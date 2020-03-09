#!/usr/bin/env python

from sys import argv
from math import inf


def weight(arr):
  s = 0
  for i in arr: # O(n) time
    s += i
  return s


def heaviest(*arrs):
  max = -inf
  heavy = None

  for a in arrs: # O(1) time
    w = weight(a) # O(n) time
    if w > max:
      max = w
      heavy = a

  return heavy


def left(arr):
  max = -inf
  n = len(arr)//2
  index = 0

  for i in range(0, n): # O(n) time
    s = weight(arr[i:]) # O(n) time
    if s > max:
      max = s
      index = i

  return index


def right(arr):
  max = -inf
  N = len(arr)
  n = N//2
  index = 0

  for i in range(0, n): # O(n) time
    s = weight(arr[n:N-i]) # O(n) time
    if s > max:
      max = s
      index = i

  return N - 1 - index


def max_sub_arr(arr):
  n = len(arr)

  if n <= 1:
    return arr # O(1) time

  s1 = max_sub_arr(arr[:n//2])
  s2 = max_sub_arr(arr[n//2:])
  i, j = left(arr), right(arr) # O(n^2) + O(n^2) time
  s3 = arr[i:j+1]

  if s3 != arr:
    s3 = max_sub_arr(s3)

  return heaviest(s1, s2, s3) # O(n) time


def main():
  arr = list(map(int, argv[1:]))
  print(max_sub_arr(arr))

if __name__ == "__main__":
  main()
