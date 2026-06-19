#pragma once

#include "vec4.h"

typedef struct 
{
    float mat4[16];
}Mat4;

void mat4_identity(Mat4* mat);
Mat4 mat4_mul_mat4(Mat4 mat1, Mat4 mat2);
vec4 mat4_mul_vec4(Mat4 mat , vec4 vec);
Mat4 mat4_translation(float tx, float ty, float tz);
Mat4 mat4_scale(float sx, float sy, float sz);