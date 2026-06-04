#include"main.h"
vec4 mat4_mul_vec4(Mat4 mat , vec4 vec)
{

    return (vec4){
        mat.mat4[0] *vec.x + mat.mat4[1] * vec.y+mat.mat4[2] *vec.z+mat.mat4[3] *vec.w,
        mat.mat4[4] *vec.x + mat.mat4[5] * vec.y+mat.mat4[6] *vec.z+mat.mat4[7] *vec.w,
        mat.mat4[8] *vec.x + mat.mat4[9] * vec.y+mat.mat4[10] *vec.z+mat.mat4[11] *vec.w,
        mat.mat4[12] *vec.x + mat.mat4[13] * vec.y+mat.mat4[14] *vec.z+mat.mat4[15] *vec.w,
    };
}
int main()
{
    Mat4 mat;
    vec4 v;
    v = (vec4) {1.0,1.0,1.0,1.0};

    mat4_identity(&mat);

    mat.mat4[3] = 5.0f;   // x translation
    mat.mat4[7] = 2.0f;   // y translation
    mat.mat4[11] = -1.0f; // z translation
    
    mat4_display(mat);
    vec4_display(mat4_mul_vec4(mat,v));
    

    return 0;
}