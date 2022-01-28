from xml.dom.minidom import parseString
import numpy as np


def ii_naive(i: "np.ndarray", x: "int", y: "int"):
  """Naive implementation of ii(x, y)"""
  ii = 0
  for sy in range(y+1):
    for sx in range(x+1):
      ii += i[sy][sx]

  return ii


def integral_image_matrix_naive(i: "np.ndarray") -> "np.ndarray":
  """Naive matrix where I_{x,y} = ii_naive(x, y)"""
  ii = np.zeros(i.shape)
  for y in range(i.shape[0]):
    for x in range(i.shape[1]):
      ii[y][x] = ii_naive(i, x, y)

  return ii


def s(i: "np.ndarray", x: "int", y: "int"):
  """Cumulative row sum of i. Recursive."""
  if y == -1:
    return 0
  return s(i, x, y - 1) + i[y][x]


def ii(i, x, y):
  """Single-pass calculation of integral image value"""
  if x == -1:
    return 0
  return ii(i, x - 1, y) + s(i, x, y)


def integral_image_matrix(i: "np.ndarray") -> "np.ndarray":
  """Single-pass calculation of matrix I_{x,y}=ii(x, y)"""
  _ii = np.zeros(i.shape)
  for y in range(i.shape[0]):
    for x in range(i.shape[1]):
      _ii[y][x] = ii(i, x, y)

  return _ii


def image_pixel_sum(i: "np.ndarray", x1: "int", y1: "int", x2: "int", y2: "int"):
  return ii(i, x2, y2) + ii(i, x1, y1) - ii(i, x2, y1) - ii(i, x1, y2)


def image_pixel_avg(i: "np.ndarray", x1: "int", y1: "int", x2: "int", y2: "int"):
  return image_pixel_sum(i, x1, y1, x2, y2)/np.abs((x2-x1+1)*(y2-y1+1))


def convolve(image: "np.ndarray", mask: "np.ndarray"):
  my, mx = mask.shape
  iy, ix = image.shape
  py, px = (my - 1)//2, (mx - 1)//2
  fy, fx = iy + 2*py, ix + 2*px

  x_padding = np.zeros((iy, px))
  y_padding = np.zeros((py, fx))

  f = np.concatenate((
      y_padding,
      np.concatenate((x_padding, image, x_padding), axis=1),
      y_padding,
  ), axis=0)

  g = np.zeros((iy, ix))

  # * Iterate over image...
  for y in range(iy):
    for x in range(ix):
      # * Iterate over mask...
      for m in range(-py, py+1):
        for n in range(-px, px+1):
          g[y][x] += f[y+py-m][x+px-n] * mask[m+py][n+px]

  return g


def correlate(image: "np.ndarray", mask: "np.ndarray"):
  my, mx = mask.shape
  iy, ix = image.shape
  py, px = (my - 1)//2, (mx - 1)//2
  fy, fx = iy + 2*py, ix + 2*px

  x_padding = np.zeros((iy, px))
  y_padding = np.zeros((py, fx))

  f = np.concatenate((
      y_padding,
      np.concatenate((x_padding, image, x_padding), axis=1),
      y_padding,
  ), axis=0)

  g = np.zeros((iy, ix))

  # * Iterate over image...
  for y in range(iy):
    for x in range(ix):
      # * Iterate over mask...
      for m in range(-py, py+1):
        for n in range(-px, px+1):
          g[y][x] += f[y+py+m][x+px+n] * mask[m+py][n+px]

  return g


def superimpose_add(what: "np.ndarray", on: "np.ndarray", x: "int", y: "int"):
  imposed = np.array(on)
  for i in range(what.shape[0]):
    for j in range(what.shape[1]):
      imposed[y+i][x+j] += what[i][j]

  return imposed


def superimpose_mult(what: "np.ndarray", on: "np.ndarray", x: "int", y: "int"):
  imposed = np.array(on)
  for i in range(what.shape[0]):
    for j in range(what.shape[1]):
      imposed[y+i][x+j] *= what[i][j]

  return imposed


def ddx(f: "np.ndarray"):
  return convolve(f, np.array([[-1, 0, 1]]))


def ddy(f: "np.ndarray"):
  return convolve(f, np.array([[-1],
                               [0],
                               [1]]))


def d2dydx(f: "np.ndarray"):
  return ddy(ddx(f))


def main():
  pass


if __name__ == "__main__":
  main()
