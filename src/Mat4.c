#include"mat4.h"
#include "vec4.h"

void mat4_identity(Mat4* mat)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(i == j)
            {
                mat->mat4[i * 4 + j] = 1.0f;

            }
            else
            {
                mat->mat4[i * 4 + j] = 0.0f;

            }
        }
    }
}
Mat4 mat4_mul_mat4(Mat4 mat1, Mat4 mat2)
{
    Mat4 result;

    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 4; row++)
        {
            result.mat4[col * 4 + row] =
                mat1.mat4[0 * 4 + row] * mat2.mat4[col * 4 + 0] +
                mat1.mat4[1 * 4 + row] * mat2.mat4[col * 4 + 1] +
                mat1.mat4[2 * 4 + row] * mat2.mat4[col * 4 + 2] +
                mat1.mat4[3 * 4 + row] * mat2.mat4[col * 4 + 3];
        }
    }

    return result;
}

vec4 mat4_mul_vec4(Mat4 mat , vec4 vec)
{

    return (vec4){
        mat.mat4[0] *vec.x + mat.mat4[1] * vec.y+mat.mat4[2] *vec.z+mat.mat4[3] *vec.w,
        mat.mat4[4] *vec.x + mat.mat4[5] * vec.y+mat.mat4[6] *vec.z+mat.mat4[7] *vec.w,
        mat.mat4[8] *vec.x + mat.mat4[9] * vec.y+mat.mat4[10] *vec.z+mat.mat4[11] *vec.w,
        mat.mat4[12] *vec.x + mat.mat4[13] * vec.y+mat.mat4[14] *vec.z+mat.mat4[15] *vec.w,
    };
}

Mat4 mat4_translation(float tx, float ty, float tz)
{
    Mat4 mat;
    mat4_identity(&mat);

    mat.mat4[3]  = tx;
    mat.mat4[7]  = ty;
    mat.mat4[11] = tz;

    return mat;
}

Mat4 mat4_scale(float sx, float sy, float sz)
{
    Mat4 mat;
    mat4_identity(&mat);
    mat.mat4[0]=sx;
    mat.mat4[5]=sy;
    mat.mat4[10]=sz;

    return mat;
}