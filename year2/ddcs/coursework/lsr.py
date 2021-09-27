#!/usr/bin/env python3
import os
import re as r
from argparse import ArgumentParser
from datetime import date
from typing import Callable, Dict, List, Tuple, Type, Union

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from matplotlib import rcParams as rc
from matplotlib.axes import Axes
from matplotlib.figure import Figure

# Graph configuration
rc["legend.handleheight"] = 3.0

# Constants defined
FILE_BASIC = 5
FILE_NOISE = 3
FILE_ADV = 3

# Type Variables
TNumber = Union[np.ndarray, float, int]
TModelFn = Callable[[TNumber], TNumber]


class Util:
  def load_points_from_file(filename):
    """Loads 2d points from a csv called filename
    Args:
        filename : Path to .csv file
    Returns:
        (xs, ys) where xs and ys are a numpy array of the co-ordinates.
    """
    points = pd.read_csv(filename, header=None)
    return points[0].values, points[1].values


def view_data_segments(xs, ys):
  """Visualises the input file with each segment plotted in a different colour.
  Args:
      xs : List/array-like of x co-ordinates.
      ys : List/array-like of y co-ordinates.
  Returns:
      None
  """
  assert len(xs) == len(ys)
  assert len(xs) % 20 == 0
  len_data = len(xs)
  num_segments = len_data // 20
  colour = np.concatenate([[i] * 20 for i in range(num_segments)])
  plt.set_cmap('Dark2')
  plt.scatter(xs, ys, c=colour)
  plt.show()


class Model(object):
  """
  class Model

  This is a class that abstracts the work
  away from extending the input vector
  """

  def __init__(self, fns, type="linear"):
    self.fns = fns
    self.type = type

  def __getitem__(self, key):
    return self.fns[key]

  def __setitem__(self, key, value):
    self.fns[key] = value

  @classmethod
  def polynomial(cls, order=2, strict=True):
    """
    Creates a sequence of polynomial terms up to order `order`
    """
    assert order >= 2 or not strict

    def bind(i):
      def fn(x):
        return x ** i

      return fn

    return Model([bind(i) for i in range(order + 1)], type="polynomial")

  @classmethod
  def linear(cls):
    """
    Creates a linear and constant term (`Model.polynomial(2, False)`)
    """
    return cls.polynomial(1, strict=False)

  @classmethod
  def exponential(cls):
    return Model([lambda x: np.exp(0 * x), lambda x: np.exp(x)], type="exponential")

  @classmethod
  def sinusoid(cls, terms=1):
    """
    Produces a sequence `1, cos(x), sin(x), cos(2x), sin(2x), ...`
    up to `cos(terms*x), sin(terms*x)`
    """
    assert terms != None and terms >= 1

    def bind(i):
      if i == 0:
        def fn(x):
          return np.ones_like(x)
        return fn

      coeff = (i - 1) // 2 + 1

      def fn(x):
        return np.sin(coeff * x) if i % 2 == 0 else np.cos(coeff * x)
      return fn

    return Model([bind(i) for i in range(0, 2 * terms + 1)], type="sinusoid")

  def unpack(self, coeffs):
    def fn(x):
      return sum(map(lambda p, f: p * f(x), coeffs, self))

    return fn


class Calc:
  @classmethod
  def extend_input(cls, X_in, model):

    X = X_in.reshape(X_in.shape[0], 1)
    Xe = np.concatenate(list(map(lambda fn: fn(X), model)), axis=1)
    return Xe

  @classmethod
  def regression(cls, model, X_in, Y_out, regulariser=0.0, sigma2=1.0):
    """
    Performs the regression calculation, with the regulariser being optional
    """

    Xe = cls.extend_input(X_in, model)
    Lambda = regulariser * np.identity(Xe.shape[1])

    return np.linalg.solve(Xe.T @ Xe + (sigma2 * Lambda), Xe.T @ Y_out)

  @classmethod
  def fit(cls, model, X_in, Y_out, regulariser=0.0, sigma2=1.0, withCoeffs=False):
    """
    Returns the fitted function given the model, training data, regulariser.
    Optionally returns the coefficients the fitted function uses.
    """

    coeffs = cls.regression(model, X_in, Y_out, regulariser, sigma2)
    f = model.unpack(coeffs)

    if withCoeffs:
      return f, coeffs

    return f, np.array([])

  @classmethod
  def view_fit(cls, fn, X_in, Y_out, resolution=100):
    """
    View how well the fitted function matches a data set
    (inputs as X_in, output as Y_out)
    """

    x = np.linspace(min(X_in), max(X_in), num=resolution)

    fig, ax = plt.subplots()
    ax.scatter(X_in, Y_out, marker="x", color="black")
    ax.plot(x, fn(x), color="red")

    ax.set_xlabel("X")
    ax.set_ylabel("Y")

    ax.grid()

    return fig, ax

  @classmethod
  def superscript(cls, s: str):
    """
    Quick formatting utility
    """
    return s.translate(str.maketrans("0123456789", "⁰¹²³⁴⁵⁶⁷⁸⁹"))

  class BestFit:
    def __init__(self, **kwargs):
      self.type = ""
      self.coeffs = []
      self.cv_error = np.Inf
      self.error = np.Inf
      self.regulariser = 0.
      self.domain = dict(max=0., min=0.)
      self.function = lambda x: x

      self.xs = np.array([0.])
      self.ys = np.array([0.])

      self._regularisers = []
      self._errors = []

      for k, v in kwargs.items():
        if hasattr(self, k):
          setattr(self, k, v)


class Train(object):
  SEGMENT_SIZE: int = 20

  def __init__(
      self, data, validate=.5, max_fit=dict(polynomial=10, sinusoid=3), min_fit=dict(polynomial=2,sinusoid=1), use_regulariser=False
  ):
    self.xs, self.ys = data
    self.validate = validate
    self.max_fit = {**dict(polynomial=10, sinusoid=3), **max_fit}
    self.min_fit = {**dict(polynomial=2, sinusoid=1), **min_fit}
    self.use_regulariser = use_regulariser

    self.__prepare()
    self.__train()

  @classmethod
  def __cv_error(cls, fn, xs, true_ys):
    """
    The mean of the squared difference between the predicted
    value of the function and the true output
    """
    return np.mean(np.square(fn(xs) - true_ys))

  @classmethod
  def __sum_error(cls, fn, xs, true_ys):
    """
    The sum of the squared difference between the predicted
    value of the function and the true output
    """
    return np.sum(np.square(fn(xs) - true_ys))

  def __prepare(self):
    self.N = len(self.xs)

    self.xs = self.xs.reshape(
        self.N,
    )
    self.ys = self.ys.reshape(
        self.N,
    )

    self.bestFits = [Calc.BestFit()
                     for _ in range(0, self.N, self.SEGMENT_SIZE)]
    self.subsets = [
        dict(
            xs=self.xs[i: i + self.SEGMENT_SIZE],
            ys=self.ys[i: i + self.SEGMENT_SIZE],
        )
        for i in range(0, self.N, self.SEGMENT_SIZE)
    ]

    self.models = dict()

    self.models["linear"] = [Model.linear()]
    self.models["exponential"] = [Model.exponential()]
    self.models["polynomial"] = []
    self.models["sinusoid"] = []

    for i in range(self.min_fit["polynomial"], self.max_fit["polynomial"] + 1):
      self.models["polynomial"].append(Model.polynomial(i))
    for i in range(self.min_fit["sinusoid"], self.max_fit["sinusoid"] + 1):
      self.models["sinusoid"].append(Model.sinusoid(i))

  def __train(self):
    """
    Performs the algorithm for predicting the class/order of the segment(s)
    """

    reg_samples = 200 + 1  # for pretty numbers
    reg_x = np.power(10,
                     np.linspace(-20, 20, reg_samples).reshape(reg_samples, 1))

    for s, subset in enumerate(self.subsets):
      best_fit = self.bestFits[s]

      for m, models in self.models.items():

        for model in models:
          for cv_split in self.__cv_split(subset):
            train_xs, train_ys, valid_xs, valid_ys = cv_split

            def cross_validation(fitted):
              return self.__cv_error(fitted, valid_xs, valid_ys)

            generatedFits = list(map(
                lambda regulariser: Calc.fit(
                    model, train_xs, train_ys, regulariser, withCoeffs=True),
                reg_x if self.use_regulariser else [0.]))

            funcs, coeffs_list = tuple(zip(*generatedFits))

            cv_errors = list(map(cross_validation, funcs))
            most_accurate = np.argmin(cv_errors)

            if cv_errors[most_accurate] < best_fit.cv_error:
              best_fit.function = funcs[most_accurate]
              best_fit.type = m
              best_fit.coeffs = coeffs_list[most_accurate]

              best_fit.cv_error = cv_errors[most_accurate]
              best_fit.regulariser = reg_x[most_accurate] if self.use_regulariser else 0.

              best_fit.error = self.__sum_error(
                  funcs[most_accurate], subset["xs"], subset["ys"])

              best_fit.domain = dict(
                  min=np.min(subset["xs"]),
                  max=np.max(subset["xs"])
              )

              best_fit.xs = subset["xs"]
              best_fit.ys = subset["ys"]

              best_fit._regularisers = reg_x if self.use_regulariser else [0.]
              best_fit._errors = cv_errors if self.use_regulariser else [0.]

              # if polynomial can be approximated by linear
              if best_fit.type == "polynomial" and np.all(
                  np.abs(best_fit.coeffs[2:]) <= 5e-2
              ):
                # change back to linear model
                best_fit.type = "linear"
                best_fit.coeffs = best_fit.coeffs[:2]
                best_fit.function = Model.unpack(
                    Model.linear(), best_fit.coeffs
                )

  def __cv_split(self, subset):
    SIZE = self.SEGMENT_SIZE
    raw_xs, raw_ys = subset["xs"], subset["ys"]

    # * E.g 20 * 1/2 = 10
    sample_no = int(SIZE * self.validate)

    # Ensures that step=1 only when self.validate=1
    if sample_no == SIZE:
      sample_no = SIZE - 1
    # Prevent divide by zero
    elif sample_no == 0:
      sample_no = 1

    # * E.g. 20 // 10 = 2
    step = SIZE // sample_no

    indices = list(map(
        lambda i: np.arange(i, SIZE, step),
        (i for i in range(step))))

    training = list(map(
        lambda i: np.array([j for j in range(0, SIZE) if j not in i]), indices))

    cv_subsets = list(map(
        lambda training, validation: (
            raw_xs[training],
            raw_ys[training],
            raw_xs[validation],
            raw_ys[validation],
        ), indices, training))

    return cv_subsets

  def error(self):
    """
    Gets the value of the sum squared error
    """
    return sum(map(lambda fit: fit.error, self.bestFits))

  def function(self):
    """
    Return the piecewise function that fits the training data
    """

    def f(x):
      conds = []
      funcs = []
      prev_min = np.min(self.xs)
      for fit in self.bestFits:
        conds.insert(len(conds) - 1, (prev_min <= x)
                     & (x <= fit.domain["max"]))
        funcs.insert(len(funcs) - 1, fit.function)
        prev_min = fit.domain["max"]

      return np.piecewise(x, conds, funcs)

    return f

  @classmethod
  def describe_fit(cls, fits: Calc.BestFit):
    """
    Takes a ``Calc.BestFit`` and returns a string representation of it
    """

    def format_coeff(c, t: str):
      return f"{c:.3f}{t}"

    def tidy(terms: List[str], coeffs):
      return " + ".join(map(format_coeff, coeffs, terms)).replace("+ -", "- ")

    str_fn = ""
    terms = []

    if fits.type == "linear":
      terms = ["1", "x"]

    elif fits.type == "exponential":
      terms = ["1", "e^x"]

    elif fits.type == "polynomial":
      terms = ["1"]
      for i in range(1, len(fits.coeffs) + 1):
        terms.append("x" if i == 1 else f"x{Calc.superscript(str(i))}")

    elif fits.type == "sinusoid":
      for i in range(0, len(fits.coeffs)):
        trig = "sin" if i % 2 == 0 else "cos"
        inner = (i + 1) // 2 if (i + 1) // 2 != 1 else ""
        terms.append("1" if i == 0 else f"{trig}({inner}x)")

    str_fn = tidy(terms, fits.coeffs)
    str_reg = f", |Λ|={fits.regulariser}"

    if fits.regulariser > 0:
      return f"{str_fn}{str_reg}"
    else:
      return f"{str_fn}"


class Main:
  FETCH_TRAINING_CACHE: Dict[str, Tuple[np.ndarray, np.ndarray]] = {}

  @classmethod
  def path_training(cls: Type["Main"], kind, index):
    """
    Returns path to training data
    """
    return f"datafiles/train_data/{kind}_{index}.csv"

  @classmethod
  def fetch_training(cls: Type["Main"], kind: str, index: Union[int, str]):
    """
    Retrieves raw training data from file
    """
    key = f"{kind},{index}"

    if key in cls.FETCH_TRAINING_CACHE.keys():
      return cls.FETCH_TRAINING_CACHE[key]

    cls.FETCH_TRAINING_CACHE[key] = Util.load_points_from_file(
        cls.path_training(kind, index)
    )

    return cls.FETCH_TRAINING_CACHE[key]

  @classmethod
  def view_training(cls: Type["Main"], kind: str, index):
    """
    Displays raw training data from file

    Parameters
      kind (str): The complexity of the source file
      index (str):
    Returns:
      None
    """
    data = cls.fetch_training(kind, index)
    Util.view_data_segments(*data)

  @classmethod
  def view_error(cls: Type["Main"], train):
    """
    Plot with the cross-validation error wrt. regulariser

    Parameters:
      train (Train): The result of training with a dataset
    """
    plots: List[Tuple[Figure, Axes]] = []

    for fit in train.bestFits:
      fig, ax = plt.subplots()
      ax.set_title(f"Regularisation vs cross-validation")
      ax.set_xscale("log")
      ax.set_yscale("log")
      ax.set_xlabel("regulariser")
      ax.set_ylabel("cross_validation_error")

      ax.plot(fit._regularisers, fit._errors)
      ax.axvline(fit.regulariser, color="black")
      ax.grid()

      plots.append((fig, ax))

    return plots

  @classmethod
  def view_data(cls, train):
    """
    Plot containing training result/data set

    Parameters:
      train (Train): The result of training with a dataset

    Returns:
      plot (Figure, Axes): Plot containing the fitted function
    """
    f = train.function()
    fig, ax = Calc.view_fit(f, train.xs, train.ys)

    ax.legend(
        ["f(x) =\n| " + "\n| ".join(list(map(Train.describe_fit, train.bestFits)))],
        loc="lower center",
        bbox_to_anchor=(0.5, -0.3)
    )
    ax.grid()

    fig.subplots_adjust(bottom=0.25)

    return fig, ax

  @classmethod
  def run(cls):
    """
    Acts as the entry point for this program

    Parameters:

    Returns:
      None
    """
    parser = ArgumentParser()
    parser.add_argument("--plot", "-p", action="store_true")
    parser.add_argument("--save", "-s", action="store_true")
    parser.add_argument("--title", "-t", action="store_true")
    parser.add_argument("--legend", "-l", action="store_true")
    parser.add_argument("--reg", "-r", action="store_true")
    parser.add_argument("file", nargs="?")

    args = parser.parse_args()
    file, regulariser, plot, save, title, legend = args.file, args.reg, args.plot, args.save, args.title, args.legend
    kind, index = "", 0
    train = False

    if file:
      match = r.search(r'\b(\w+)_(\w+)\.csv', file)
      if match:
        kind, index = match[1], match[2]
      else:
        kind, index = date.isoformat(date.today()), ""

      data = Util.load_points_from_file(file)
      train = Train(data, use_regulariser=regulariser)

    else:
      kind, index = input("type <basic/noise/adv> <N>: ").split(" ")[:2]
      data = cls.fetch_training(kind, index)
      train = Train(data, use_regulariser=regulariser)

    if train:
      print(train.error())

    if plot and train:
      fig, ax = cls.view_data(train)

      if title:
        ax.set_title(file)

      if legend:
        ax.legend(["f(x) =\n| " + "\n| ".join(list(map(Train.describe_fit, train.bestFits)))],
                  loc="lower center",
                  bbox_to_anchor=(0.5, -0.3))
      else:
        ax.legend([])
      if save:
        if not os.path.exists("images"):
          os.mkdir("images")

        fig.savefig(f"images/{kind}_{index}.png")

      plt.show()


if __name__ == "__main__":
  Main.run()
