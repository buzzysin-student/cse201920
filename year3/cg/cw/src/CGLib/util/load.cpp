#pragma once

#include "../shared.cpp"

std::vector<std::vector<float>> parseObjFile(const char *name)
{
  char *path;
  sprintf(path, "../models/%s", name);

  FILE *file = fopen(path, "r");
}