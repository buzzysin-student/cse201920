#pragma once

#include "../shared.cpp"

// ? Max string length for allocation
const int STRLN = 100;

// ? True if a character is a whitespace character
bool isWhitespace(char c)
{
  return c == ' ' || c == '\n' || c == '\t';
}

// ? True if the character is the terminating character
bool isEnd(char c)
{
  return c == '\0';
}

// ? Receives tokens vector which will store the result and
// ? a function that determines the delimiter, and finally
// ? the text to delimit
void getDelimitedTokens(std::vector<char *> &tokens, bool (*isDelimiter)(char c), char *text)
{
  char *cursor = text;

  while (!isEnd(*cursor))
  {
    // ? Count characters until delimiter
    int t = 0;
    while (!isDelimiter(*cursor) && !isEnd(*cursor))
    {
      cursor++;
      t++;
    }

    // ? Copy characters into memory
    char *token = (char *)malloc((t + 1) * sizeof(char));
    token[t] = '\0';
    strncpy(token, (cursor - t), t);

    // ? Add to token stack
    tokens.push_back(token);

    // ? Increment cursor if we are not finished yet
    if (!isEnd(*cursor))
      cursor++;
  }
}

// ? Store whitespace-delimited tokens in the vector provided
void getWhitespaceDelimitedTokens(std::vector<char *> &tokens, char *text)
{
  getDelimitedTokens(tokens, isWhitespace, text);
}

// ? `get[...]DelimitedTokens` makes use of malloc. Use this to release
// ? used up memory
void destroyDelimitedTokens(std::vector<char *> &v)
{
  for (size_t i = 0; i <  v.size(); i++)
  {
    auto s = v[i];
    free(s);
  }
}

std::vector<std::string> getTokens(const std::string &line, char delimiter)
{
  std::vector<std::string> tokens;

  size_t prev = 0, next = 0;

  while ((next = line.find(delimiter, next), next != std::string::npos))
  {
    std::string token(line.substr(prev, next - prev));
    tokens.push_back(token);
    prev = ++next;
  }

  tokens.push_back(line.substr(prev, next - prev));

  return tokens;
}