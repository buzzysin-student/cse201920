#pragma once

#include "text.cpp"

void writeLog(const char *file, int line, const char *text)
{
#ifdef LOG
  if (LOG)
    std::cout << file << ":" << line << ": " << text;
#endif
}

void writeLog(const char *file, int line, std::string text)
{
  writeLog(file, line, text.c_str());
}