#pragma once

#include "../shared.cpp"

using vf = std::vector<float>;
using mf = std::vector<vf>;

// + -> recieves reference, returns reference (vector addition)
vf &operator+=(vf &u, const vf &v)
{
  if (u.size() != v.size())
    throw -1;

  for (size_t i = 0; i < u.size(); i++)
  {
    u[i] += v[i];
  }

  return u;
}

// + -> recieves reference, returns reference (scalar addition)
// NOTE - reversed parameters not supported.
vf &operator+=(vf &u, const float &f)
{
  for (size_t i = 0; i < u.size(); i++)
  {
    u[i] += f;
  }

  return u;
}

// + -> recieves value, returns value (vector addition)
vf operator+(vf u, const vf &v)
{
  u += v;
  return u;
}

// + -> recieves value, returns value (scalar addition)
vf operator+(vf u, const float &f)
{
  u += f;
  return u;
}
vf operator+(const float &f, vf u)
{
  u += f;
  return u;
}

// * -> recieves reference, returns reference (scalar multiplication)
// NOTE - reversed parameters not supported.
vf &operator*=(vf &u, const float &f)
{
  for (size_t i = 0; i < u.size(); i++)
  {
    u[i] *= f;
  }

  return u;
}

// * -> recieves value, returns value (scalar multiplication)
// NOTE - reversed parameters not supported.
vf operator*(vf u, const float &f)
{
  u *= f;
  return u;
}
vf operator*(const float &f, vf u)
{
  u *= f;
  return u;
}

// - -> recieves reference, returns reference (scalar multiplication)
vf &operator-=(vf &u, const vf &v)
{
  u += v * -1;
  return u;
}

// - -> recieves reference, returns reference (scalar multiplication)
// NOTE - reversed parameters not supported.
vf &operator-=(vf &u, const float &f)
{
  u += -f;
  return u;
}

// - -> recieves value, returns value (vector subtraction)
vf operator-(vf u, const vf &v)
{
  u -= v;
  return u;
}

// - -> recieves value, returns value (scalar subtraction)
vf operator-(vf u, const float &f)
{
  u -= f;
  return u;
}
vf operator-(const float &f, vf u)
{
  u -= f;
  return u;
}

// / -> recieves reference, returns reference (scalar division)
vf &operator/=(vf &u, const float &f)
{
  u *= 1 / f;
  return u;
}

// / -> recieves value, returns value (scalar division)
vf operator/(vf u, const float &f)
{
  u *= 1 / f;
  return u;
}
vf operator/(const float &f, vf u)
{
  u *= 1 / f;
  return u;
}

// + -> recieves value, returns value (scalar arithmetic negation)
vf operator-(vf u)
{
  u *= -1;
  return u;
}

// << -> out stream
std::ostream &operator<<(std::ostream &os, const vf &u)
{
  for (size_t i = 0; i < u.size(); i++)
  {
    os << u[i];

    if (i != u.size() - 1)
    {
      os << ", ";
    }
  }

  return os;
}

// Vector multiplication-to-assignment is not type-safe and
// since C++ cannot define new operators, the methods
// available on std::vector<float> must be extended(?)

// . -> receives value, returns value (vector dot product)
// NOTE - since the dot product has a different return type
// than its parameters, the dot-equals (.=) operator is not
// well-defined in a type-safe system
float dot(vf u, const vf &v)
{
  if (u.size() != v.size())
    throw -1;

  float result = 0.0f;

  for (size_t i = 0; i < u.size(); i++)
  {
    result += u[i] * v[i];
  }

  return result;
}

// The cross product only exists in 3 and 7 dimensions,
// and I'm NOT writing the 7 dimensional case.
vf cross(vf u, const vf &v)
{
  if (u.size() != v.size())
    throw -1;

  if (u.size() != 3)
    throw -1;

  float wx = u[1] * v[2] - u[2] * v[1];
  float wy = u[2] * v[0] - u[0] * v[2];
  float wz = u[0] * v[1] - u[1] * v[0];

  return vf({wx, wy, wz});
}

float vMax(vf v)
{
  float max = 0.0f;
  for (size_t i = 0; i < v.size(); i++)
  {
    max = std::max(max, v[i]);
  }

  return max;
}

float vMin(vf v)
{
  float min = 0.0f;
  for (size_t i = 0; i < v.size(); i++)
  {
    min = std::min(min, v[i]);
  }

  return min;
}

glm::vec3 toGlm(const vf &u)
{
  if (u.size() < 3)
    throw -1;

  glm::vec3 result;

  result.x = u[0];
  result.y = u[1];
  result.z = u[2];

  return result;
}

// ! Matrices

mf &operator+=(mf &m, const mf &n)
{
  if (m.size() != n.size())
    throw -1;

  for (size_t i = 0; i < m.size(); i++)
  {
    m[i] += n[i];
  }

  return m;
}

mf &operator+=(mf &m, const vf &v)
{
  for (size_t i = 0; i < m.size(); i++)
  {
    m[i] += v;
  }

  return m;
}

mf &operator+=(mf &m, const float &f)
{
  for (size_t i = 0; i < m.size(); i++)
  {
    m[i] += f;
  }

  return m;
}

mf operator+(mf m, const mf &n)
{
  m += n;
  return m;
}

mf operator+(mf m, const vf &v)
{
  m += v;
  return m;
}

mf operator+(mf m, const float &f)
{
  m += f;
  return m;
}

std::ostream &operator<<(std::ostream &os, const mf &u)
{
  for (size_t i = 0; i < u.size(); i++)
  {
    os << u[i];

    if (i != u.size() - 1)
    {
      os << "\n";
    }
  }

  return os;
}

mf transpose(mf m)
{
  mf n(m.size(), vf(m[0].size(), 0.0f));

  for (size_t r = 0; r < m.size(); r++)
  {
    for (size_t c = 0; c < m[0].size(); c++)
    {
      n[c][r] = m[r][c];
    }
  }

  return n;
}

vf row(mf m, int i)
{
  return m[i];
}

vf col(mf m, int i)
{
  vf col(m.size(), 0.0f);

  for (size_t r = 0; r < m.size(); r++)
  {
    col[r] = m[r][i];
  }

  return col;
}

mf &operator*=(mf &m, const mf &n)
{
  size_t m_rows = m.size();
  size_t n_rows = n.size();
  if (m_rows == 0 || n_rows == 0)
    throw -1;

  size_t m_cols = m[0].size();
  size_t n_cols = n[0].size();
  if (m_cols == 0 || n_cols == 0)
    throw -1;

  if (m_cols != n_rows)
    throw -1;

  mf result(m_rows, vf(n_cols, 0.0f));

  for (size_t y = 0; y < m_rows; y++)
  {
    vf r = row(m, y);
    for (size_t x = 0; x < n_cols; x++)
    {
      vf c = col(m, x);

      result[y][x] = dot(r, c);
    }
  }

  m = result;
  return m;
}