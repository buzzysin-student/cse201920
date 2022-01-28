#pragma once

#include "../shared.cpp"

using vf = std::vector<float>;
template <typename T>
using matrix = std::vector<std::vector<T>>;
using mf = std::vector<vf>;

template <typename T>
void vectorAdditionCheck(std::vector<T> u, std::vector<T> v)
{
  if (u.size() != v.size())
  {
    std::cerr << "Vectors do not match sizes: " << u.size() << ", " << v.size() << "\n";
    throw std::invalid_argument("Invalid argument");
  }
}

void matrixProductCheck(mf m, mf n)
{
  size_t m_rows = m.size();
  size_t n_rows = n.size();
  if (m_rows == 0 || n_rows == 0)
  {
    std::cerr << "One or both matrices have y dimension\n";
    throw std::invalid_argument("Invalid argument");
  }

  size_t m_cols = m[0].size();
  size_t n_cols = n[0].size();
  if (m_cols == 0 || n_cols == 0)
  {
    std::cerr << "One or both matrices have x dimension\n";
    throw std::invalid_argument("Invalid argument");
  }

  if (m_cols != n_rows)
  {
    std::cerr << "Matrices cannot be multiplied: "
              << "(" << m_rows << "x" << m_cols << ")"
              << " and "
              << "(" << n_rows << "x" << n_cols << ")"
              << "\n";
    throw std::invalid_argument("Invalid argument");
  }
}

// + -> recieves reference, returns reference (vector addition)
vf &operator+=(vf &u, const vf &v)
{
  vectorAdditionCheck(u, v);

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
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &u)
{
  os << "[";
  for (size_t i = 0; i < u.size(); i++)
  {
    auto next = i < u.size() - 1 ? ", " : "";
    os << u[i] << next;
  }
  os << "]";

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
  {
    std::cerr << "Vectors do not match sizes: " << u.size() << ", " << v.size() << "\n";
    throw std::invalid_argument("Invalid argument");
  }

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
  {
    std::cerr << "Vectors do not match sizes: " << u.size() << ", " << v.size() << "\n";
    throw std::invalid_argument("Invalid argument");
  }

  if (u.size() != 3)
  {
    std::cerr << "Cross product only avaiable for 3-vectors\n";
    throw std::invalid_argument("Invalid argument");
  }

  float wx = u[1] * v[2] - u[2] * v[1];
  float wy = u[2] * v[0] - u[0] * v[2];
  float wz = u[0] * v[1] - u[1] * v[0];

  return vf({wx, wy, wz});
}

float vMax(vf v)
{
  float max = -MAXFLOAT + 1;
  for (size_t i = 0; i < v.size(); i++)
  {
    max = std::max(max, v[i]);
  }

  return max;
}

float vMin(vf v)
{
  float min = MAXFLOAT;
  for (size_t i = 0; i < v.size(); i++)
  {
    min = std::min(min, v[i]);
  }

  return min;
}

glm::vec3 toGlm(const vf &u)
{
  glm::vec3 result;

  for (size_t i = 0; i < u.size(); i++)
  {
    switch (i)
    {
    case 0:
      result.x = u[i];
      break;
    case 1:
      result.y = u[i];
      break;
    case 2:
      result.z = u[i];
      break;
    }
  }

  return result;
}

float magnitude(vf v)
{
  float sum = 0;
  for (size_t i = 0; i < v.size(); i++)
    sum += std::pow(v[i], 2);

  return std::sqrt(sum);
}

vf normal(vf v)
{
  return v / magnitude(v);
}

vf extend(vf v, size_t i, float value)
{
  if (v.size() < i)
    for (size_t j = 0; j < v.size() - i; j++)
      v.push_back(value);

  return v;
}

vf truncate(vf v, size_t i)
{
  if (v.size() > i)
  {
    vf newV(v.begin(), v.begin() + i);
    return newV;
  }

  return v;
}

// ! Matrices

mf &operator+=(mf &m, const mf &n)
{
  vectorAdditionCheck(m, n);

  for (size_t i = 0; i < m.size(); i++)
    m[i] += n[i];

  return m;
}
mf &operator+=(mf &m, const vf &v)
{
  for (size_t i = 0; i < m.size(); i++)
    m[i] += v;

  return m;
}
mf &operator+=(mf &m, const float &f)
{
  for (size_t i = 0; i < m.size(); i++)
    m[i] += f;

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

mf &operator-=(mf &m, const mf &n)
{
  for (size_t i = 0; i < m.size(); i++)
    m[i] += -n[i];

  return m;
}
mf &operator-=(mf &m, const vf &v)
{
  for (size_t i = 0; i < m.size(); i++)
    m[i] += -v;

  return m;
}
mf &operator-=(mf &m, const float &f)
{
  for (size_t i = 0; i < m.size(); i++)
    m[i] += -f;

  return m;
}

mf operator-(mf m, const mf &n)
{
  m -= n;
  return m;
}
mf operator-(mf m, const vf &v)
{
  m -= v;
  return m;
}
mf operator-(mf m, const float &f)
{
  m -= f;
  return m;
}

mf operator-(mf m)
{
  for (size_t i = 0; i < m.size(); i++)
    m[i] = -m[i];

  return m;
}

mf transpose(mf m)
{
  size_t rs = m.size();
  size_t cs = m[0].size();

  mf n(cs, vf(rs));

  for (size_t r = 0; r < rs; r++)
    for (size_t c = 0; c < cs; c++)
      n[c][r] = m[r][c];

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
  matrixProductCheck(m, n);

  size_t m_rows = m.size();
  size_t n_cols = n.size();

  mf result(m_rows, vf(n_cols, 0.0f));

  for (size_t y = 0; y < m_rows; y++)
  {
    vf r = row(m, y);
    for (size_t x = 0; x < n_cols; x++)
    {
      vf c = col(n, x);
      result[y][x] = dot(r, c);
    }
  }

  m = result;
  return m;
}
mf &operator*=(mf &m, const float &f)
{
  for (size_t i = 0; i < m.size(); i++)
    m[i] *= f;

  return m;
}

mf operator*(mf m, const mf &n)
{
  m *= n;
  return m;
}
mf operator*(mf m, const float &f)
{
  m *= f;
  return m;
}
mf operator*(float f, const mf &m)
{
  return m * f;
}
vf operator*(mf m, const vf &v)
{
  vf u = transpose(m * transpose({v}))[0];
  return u;
}

mf subMatrix(mf m, size_t r, size_t c)
{
  if (m.size() < 2 && m[0].size() < 2)
  {
    std::cerr << "The submatrix of a one-by-x or x-by-one matrix is undefined.\n";
    throw std::invalid_argument("Invalid argument");
  }

  size_t rs = m.size(), cs = m[0].size();

  mf n(rs - 1, vf(cs - 1, 0.0f));

  for (size_t nr = 0; nr < rs - 1; nr++)
  {
    for (size_t nc = 0; nc < cs - 1; nc++)
    {
      size_t mr = nr < r ? nr : nr + 1;
      size_t mc = nc < c ? nc : nc + 1;
      n[nr][nc] = m[mr][mc];
    }
  }

  return n;
}

float det(mf m);

float minor(mf m, size_t r, size_t c)
{
  return det(subMatrix(m, r, c));
}

float det(mf m)
{
  if (m.size() == 1)
    return m[0][0];

  float d = 0;
  for (size_t i = 0; i < m.size(); i++)
    d += std::pow(-1, i) * m[0][i] * minor(m, 0, i);

  return d;
}

float cofactor(mf m, size_t r, size_t c)
{
  return std::pow(-1, r + c) * minor(m, r, c);
}

mf cofactors(mf m)
{
  mf C(m.size(), vf(m[0].size(), 0.0f));

  for (size_t r = 0; r < m.size(); r++)
    for (size_t c = 0; c < m[0].size(); c++)
      C[r][c] = cofactor(m, r, c);

  return C;
}

mf adjugate(mf m)
{
  return transpose(cofactors(m));
}

mf inverse(mf m)
{
  if (det(m) == 0)
  {
    std::cerr << "Matrix is singular.\n";
    throw std::invalid_argument("Invalid argument");
  }

  return ((float)1 / (float)det(m)) * adjugate(m);
}

class m4
{
  mf m;

public:
  m4() : m({{1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}})
  {
  }

  m4(mf matrix) : m({{1, 0, 0, 0},
                     {0, 1, 0, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 1}})
  {
    size_t rows = m.size();
    for (size_t i = 0; i < rows; i++)
    {
      size_t cols = m[i].size();
      for (size_t j = 0; j < cols; j++)
      {
        m[i][j] = matrix[i][j];
      }
    }
  }

  m4 identity()
  {
    return m4();
  }

  m4 scale(vf v)
  {
    mf s({{v[0], 0, 0, 0},
          {0, v[1], 0, 0},
          {0, 0, v[2], 0},
          {0, 0, 0, 1}});

    mf n = s * m;

    return m4(n);
  }

  m4 scale(float s)
  {
    return scale({s, s, s});
  }
  m4 scaleX(float x)
  {
    return scale({x, 1, 1});
  }
  m4 scaleY(float y)
  {
    return scale({1, y, 1});
  }
  m4 scaleZ(float z)
  {
    return scale({1, 1, z});
  }

  m4 translate(vf v)
  {
    mf t({{1, 0, 0, v[0]},
          {0, 1, 0, v[1]},
          {0, 0, 1, v[2]},
          {0, 0, 0, 1}});

    mf n = t * m;
    return m4(n);
  }

  m4 translateX(float x)
  {
    return translate({x, 0, 0});
  }
  m4 translateY(float y)
  {
    return translate({0, y, 0});
  }
  m4 translateZ(float z)
  {
    return translate({0, 0, z});
  }

  m4 rotate(vf v)
  {
    using namespace std;
    auto x = v[0],
         y = v[1],
         z = v[2];
    float cosx = cos(x), sinx = sin(x),
          cosy = cos(y), siny = sin(y),
          cosz = cos(z), sinz = sin(z),
          ___0 = 0.000f, ___1 = 1.000f;

    mf rx = {{___1, ___0, ___0, ___0},
             {___0, cosx, -sinx, ___0},
             {___0, sinx, cosx, ___0},
             {___0, ___0, ___0, ___1}};

    mf ry = {{cosy, ___0, siny, ___0},
             {___0, ___1, ___0, ___0},
             {-siny, ___0, cosy, ___0},
             {___0, ___0, ___0, ___1}};

    mf rz = {{cosz, -sinz, ___0, ___0},
             {sinz, cosz, ___0, ___0},
             {___0, ___0, ___1, ___0},
             {___0, ___0, ___0, ___1}};

    mf r = rz * ry * rx;

    mf n = r * m;
    return m4(n);
  }

  m4 rotateX(float x)
  {
    return rotate({x, 0, 0});
  }
  m4 rotateY(float y)
  {
    return rotate({0, y, 0});
  }
  m4 rotateZ(float z)
  {
    return rotate({0, 0, z});
  }

  m4 project(float fov, float aspect, float zNear, float zFar)
  {
    auto arg = std::atan(fov);
    auto zp = zFar + zNear;
    auto zm = zFar - zNear;

    mf p({{arg / aspect, 0, 0, 0},
          {0, arg, 0, 0},
          {0, 0, -zp / zm, -2 * (zFar * zNear) / zm},
          {0, 0, -1, 0}});

    mf n = p * m;
    return m4(n);
  }

  // Be cautious with this - this struct doesn't keep a queue
  // of transform requests, so don't reverse unless you know the
  // implications of non-commutativity/left-associativity
  m4 reverse()
  {
    mf n = inverse(m);
    return m4(n);
  }

  vf apply(vf v)
  {
    vf w;
    if (v.size() < 4)
    {
      w = extend(v, 4, 0);
      w[3] = 1;
    }
    else if (v.size() > 4)
    {
      w = truncate(v, 4);
    }
    else
    {
      w = vf(v);
    }

    w = m * w;
    w /= w[3]; // (convert from [X, Y, Z, W] to [x, y, z])

    return truncate(w, 3);
  }

  // ? Checks are skipped because I'm lazy.
  mf apply(mf n)
  {
    mf p(n);
    for (size_t i = 0; i < n.size(); i++)
    {
      p[i] = apply(n[i]);
    }

    return p;
  }

  mf get()
  {
    return m;
  }

  // ? Returns the result of this transformed by n
  m4 transformBy(m4 n)
  {
    m = n.m * m;
    return m4(m);
  }

  friend std::ostream &operator<<(std::ostream &os, const m4 &m)
  {
    return os << m.m;
  }

  friend m4 &operator*=(m4 &m, const m4 &n)
  {
    mf _m = m.m * n.m;
    m.m = _m;
    return m;
  }

  friend m4 operator*(m4 m, m4 n)
  {
    m *= n;
    return m;
  }
};
