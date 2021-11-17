#pragma once

#include "../shared.cpp"

// Sorts a vector of floats (not in place, likely unstable, returns a copy)
template <typename T>
std::vector<T> sortVector(std::vector<T> v, int (*comparison)(T, T))
{
  if (v.size() == 0 || v.size() == 1)
    return std::vector<T>(v);

  size_t size = v.size();
  size_t p = round(size / 2);

  T pivot = v[p];
  std::vector<T> ult, pvt, ugt, rslt(size, T());

  for (size_t i = 0; i < size; i++)
  {
    T value = v[i];
    int cmp = comparison(value, pivot);

    if (cmp < 0)
      ult.push_back(value);
    else if (cmp == 0)
      pvt.push_back(value);
    else
      ugt.push_back(value);
  }

  size_t ltSize = ult.size(),
         pvtSize = pvt.size();

  std::vector<T> lt = sortVector(ult, comparison);
  std::vector<T> gt = sortVector(ugt, comparison);

  for (size_t i = 0; i < size; i++)
  {
    size_t j = i - ltSize;
    size_t k = i - ltSize - pvtSize;
    if (i < ltSize)
    {
      rslt[i] = lt[i];
    }
    else if (ltSize <= i && i < ltSize + pvtSize)
    {
      rslt[i] = pvt[j];
    }
    else
    {
      rslt[i] = gt[k];
    }
  }

  return rslt;
}