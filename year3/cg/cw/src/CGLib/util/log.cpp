#pragma once

void writeLog(char *text)
{
#ifdef LOG
  if (LOG)
    std::cout << __FILE__ << ": " << text;
#endif
}