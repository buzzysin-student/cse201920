from sys import argv
from math import inf


def main():
  args = list(map(int, argv[1:]))
  print(args)
  print(msort(args))


def merge(x):
  x1 = x[:len(x)//2] + [inf]
  x2 = x[len(x)//2:] + [inf]
  i = 0
  j = 0
  for k in range(len(x)):
    if x1[i] < x2[j]:
      x[k] = x1[i]
      i += 1
    else:
      x[k] = x2[j]
      j += 1
  return x


def msort(x):
  if len(x) == 1:
    return x

  x[:len(x)//2] = msort(x[:len(x)//2])
  x[len(x)//2:] = msort(x[len(x)//2:])

  merge(x)
  return x


if __name__ == "__main__":
  main()
