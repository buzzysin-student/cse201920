#define LOG false

#include "CGLib/all.cpp"
#include "prefabs/all.cpp"

// int main(int argc, char *argv[])
// {
// // TODO:  Q1)
// int r = 107,
//     g = 110,
//     b = 84,
//     a = 255;
// uint32_t packed = (g << 24) +
//                   (r << 16) +
//                   (a << 8) +
//                   (b << 0);

// // std::cout << packed << "\n";
// // * A) 1852571476

// // TODO: Q2
// // * Sorted by y-value
// vf pa = {220, 100};
// vf pb = {100, 500};
// vf pc = {500, 500};

// // ? .a)
// Interpolate::Vector left{pa, pb, 100, 500};
// //? Interpolate by y value (100 to 500) from a to b
// //  std::cout << "left: " << left(390) << "\n"; // returns vector point at y=390

// // ? .b)
// Interpolate::Vector right{pa, pc, 100, 500};
// //? Interpolate by y value (100 to 500) from a to c
// // std::cout << "right: " << right(390) << "\n"; // returns vector point at y=390

// // TODO:  Q3)
// vf v0 = {302, 56};
// vf v1 = {505, 582};
// vf v2 = {57, 387};

// // ? .a)
// Interpolate::Vector extra{v0, v1, v0[1], v1[1]};
// //? Explanation - interpolating line v0-v1 using v2's y value as the index to interpolate
// // std::cout << "extra: " << extra(v2[1]) << "\n";

// // ? .b)
// vf tv0 = {316, 66};
// vf tv1 = {517, 612};
// vf tv2 = {60, 402};

// // ! Using v0 as an anchor point
// mf v = transpose({v1 - v0, v2 - v0});
// mf t = transpose({tv1 - tv0, tv2 - tv0});

// // triangle -> basis -> texture
// vf p = {288, 341};
// vf tp = tv0 + t * inverse(v) * (p - v0);
// // std::cout << tp << "\n";

// // !
// // TODO: Q4
// // !

// m4 transform;
// vf cameraP = {42, 29, 21};
// p = {-9, 40, 98};
// vf vertical = {0, 1, 0};
// vf cf = normal(p - cameraP);
// vf cr = normal(cross(vertical, cf));
// vf cu = normal(cross(cf, cr));

// //std::cout << transpose(mf({cr, cu, cf})) << "\n";

// // TODO: Q5
// mf triangle = {{-451, -205, -108},
//                {445, 158, -129},
//                {-28, 391, -87}};
// v0 = triangle[0];
// v1 = triangle[1];
// v2 = triangle[2];

// vf n = normal(cross(triangle[0] - triangle[1], triangle[0] - triangle[2]));

// int width = 280, height = 200;

// cameraP = {0, 0, -500};
// float focalLength = 491;

// vf iP = {168, 132, cameraP[2] + focalLength};

// iP = {(iP[0] - width / 2) * iP[2] / focalLength,
//       (iP[0] + width / 2) * iP[2] / focalLength,
//       iP[2]};

// // n . d = 0
// // or
// // (1)
// // nx dx + ny dy + nz dz = 0
// float dx = iP[0] - cameraP[0];
// float dy = iP[1] - cameraP[1];
// float dz = (-n[0] * dx - n[1] * dy) / n[2];

// vf d = {dx, dy, dz};

// std::cout << d << "\n";

// // Cp + d t satisfies (1)
// // cx + t dx + cy + t dy + cz + t dz = 0
// // t = -(cz + cy + cz)/(dx + dy + dz)
// float k = -(cameraP[0] + cameraP[1] + cameraP[2]) / (d[0] + d[1] + d[2]);

// vf pIntersect = cameraP + d * k;

// float distance = magnitude(pIntersect - cameraP);

// std::cout << distance << "\n";

// ? Q6)

// vf v0 = {-456, -208, -109};
// vf v1 = {442, -159, -128};
// vf v2 = {-29, 392, -86};

// vf d1 = v0 - v1;
// vf d2 = v0 - v2;

// vf n = normal(cross(d1, d2));
// vf light = {-15, -9, 0};
// vf point = {-266, -110, -108};
// vf a_i = normal(point - light);
// vf a_r = normal(a_i - 2 * n * dot(a_i, n));

// std::cout << a_r << "\n";
// }

int main(int argc, char *argv[])
{
  try
  {

    fflush(NULL);

    // EnvTriangleCobble environment;
    EnvCornell environment;
    Engine engine(environment);

    engine.run();
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << "\n";
  }
  return 0;
}