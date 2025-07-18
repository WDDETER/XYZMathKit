# XYZMathKit
Fast, Lean, and fairly accurate math kit for applications in C!

No SIMD or ASM!

---

## Features

Basic Vector Math for 2D, 3D, and 4D Vectors:

- Addition, Subtraction, Multiplication by Scalar, and Multiplication by Component

- Projection, Reflection, Distance, Distance Squared, Angle Between, Dot, Cross, Magnitude, Normalization, Min and Max

Basic Matrix Math for 2D, 3D:

- Multiplication, Transposing

- Perspective and Otrhogonal Projection

- 3D Translation, Rotation, Scaling (via 4x4 matrices)
- 2D Translation, Rotation, Scaling (via 3x3 matrices)

Basic Math Operations:

- Floor, Ceil, Max, Min, Sin, Cos, Tan, Acos, Asin, Inverse Square Root, Square Root

---

## Benchmarking

Each operation and function has been iterated 1,000,000 times.
Functions at lowest is around 4 nanoseconds to the highest being 45 nanoseconds.
