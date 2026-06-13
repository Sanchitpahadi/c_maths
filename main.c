#include"main.h"
#include "sphere.h"
#include <math.h>
#include "AABB.h"
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
Mat4 mat4_mul(Mat4 mat1, Mat4 mat2)
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

void matrix()
{
   Mat4 mat;

    vec4 v = (vec4){1.0f, 0.0f, 0.0f, 1.0f};
    vec4 v1 = (vec4){1.0f, 1.0f, 1.0f, 1.0f};

    mat4_identity(&mat);

    mat4_display(mat);
    Mat4 mat1 = mat4_translation(5.0f, 3.0f, 2.0f);
    Mat4 mat2 = mat4_scale(2.0f, 3.0f, 4.0f);

    vec4_display(mat4_mul_vec4(mat1,v));

    vec4_display(mat4_mul_vec4(mat2,v1));

}

float vec3_distance(vec3 A, vec3 B)
{
    vec3 temp;
    temp = (vec3) { A.x-B.x,A.y -B.y, A.z- B.z };
    
    return vec3_length(temp);
}
void collision_detection()
{
        // Collison ditection

    vec3 va = {0.0,0.0,0.0}, vb = {3.0,4.0,0.0};

    printf(" length of the two vectors :: %f \n",vec3_distance(va,vb)); // vec3_distance calculates the distance between two object
}
void sphere_sphere(sphere a, sphere b)
{
    //float d = sqrt((a.center.x-b.center.x)*(a.center.x-b.center.x) + (a.center.y-b.center.y)*(a.center.y-b.center.y));
    float d = vec3_distance(a.center,b.center); 
   
    float r = a.radius + b.radius;
    
    float_display(d);
    float_display(r);
    if(d<r)
    {
        str_display("collides \n");
    }
    if(d==r)
    {
        str_display("touch on edges \n");
    }
    if(d>r)
    {
        str_display("not colliding \n");
    }
}

void data_sphere()
{
   sphere s;
    s.center = (vec3){0.0 , 0.0 , 0.0};
    s.radius = 2.0;

   // vec3_display(s.center);
    
   // float_display(s.radius);

    sphere A ;  //(0,0,0)` radius `2`
    sphere B ;  //(3,0,0)` radius `2` → overlapping
    sphere C ;  //(6,0,0)` radius `1` → not overlapping

    B.center = (vec3){3.0 , 0.0 , 0.0};
    B.radius = 2.0;

    C.center = (vec3){6.0 , 0.0 , 0.0};
    C.radius = 1.0;

    sphere_sphere(s,B);
    sphere_sphere(s,C);


}
int aabb_aabb(AABB a, AABB b)
{
    int overlaps = (a.max.x >= b.min.x && a.min.x <= b.max.x && a.max.y >= b.min.y && a.min.y <= b.max.y &&  a.max.z >= b.min.z && a.min.z <= b.max.z);
   return overlaps;
}

int vec3_aabb(vec3 v , AABB b)
{
    return (v.x > b.min.x && v.x < b.max.x && v.y > b.min.y && v.y < b.max.y &&v.z > b.min.z && v.z < b.max.z );
}


void data_collision_aabb()
{
       AABB A ;// min `(-1,-1,-1)` max `(1,1,1)`
    AABB B; // min `(0,0,0)` max `(2,2,2)` → overlapping
    AABB C; //min `(3,3,3)` max `(5,5,5)` → not overlapping

    A.min = (vec3){-1,-1,-1};
    A.max = (vec3){1,1,1};

    B.min = (vec3){0,0,0};
    B.max = (vec3){2,2,2};

    C.min = (vec3){3,3,3};
    C.max = (vec3){5,5,5};

    int overlapping;

    overlapping = aabb_aabb(A,B);
    if(overlapping)
    {
        str_display("Overlaping\n");
    }
    else
    {
        str_display("Not overlaping\n");
    }
    overlapping = aabb_aabb(A,C);

    if(overlapping)
    {
        str_display("Overlaping\n");
    }
    else
    {
        str_display("Not overlaping \n");
    }
}

void data_vec3_aabb()
{
       AABB A ;// min `(-1,-1,-1)` max `(1,1,1)`
    AABB B; // min `(0,0,0)` max `(2,2,2)` → overlapping
    AABB C; //min `(3,3,3)` max `(5,5,5)` → not overlapping

    A.min = (vec3){-1,-1,-1};
    A.max = (vec3){1,1,1};

    B.min = (vec3){0,0,0};
    B.max = (vec3){2,2,2};

    C.min = (vec3){3,3,3};
    C.max = (vec3){5,5,5};

    vec3 a = {0.5, 0.5, 0.5};
    vec3 b = {5.0, 0.0, 0.0};

    if(vec3_aabb(a,A))
    {
        str_display("its inside the box \n");
    }
    else
    {
        
        str_display("it is not inside the box \n");

    }
    if(vec3_aabb(b,A))
   {
        str_display("its inside the box\n");
    }
    else
    {
        
        str_display("it is not inside the box\n");

    }
}
int main()
{
    
 
    return 0;
}