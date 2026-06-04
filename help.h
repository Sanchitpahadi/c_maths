#include"stdio.h"
#include "vec3.h"
#include "mat4.h"

void vec3_Data(vec3* vec)
{
    printf("Enter for x  = ");
    scanf("%f",&vec->x);
    printf("\n");
    printf("Enter for y  = ");
    scanf("%f",&vec->y);
    printf("\n");
    printf("Enter for z  = ");
    scanf("%f",&vec->z);
    printf("\n");
}

void vec3_display( vec3 vec)
{
    printf("%.2f \n", vec.x);
    printf("%.2f \n", vec.y);
    printf("%.2f \n", vec.z);
    printf("\n");
}

void vec4_data(vec4* vec)
{
    printf("Enter for x  = ");
    scanf("%f",&vec->x);
    printf("\n");
    printf("Enter for y  = ");
    scanf("%f",&vec->y);
    printf("\n");
    printf("Enter for z  = ");
    scanf("%f",&vec->z);
    printf("\n");
    printf("Enter for w  = ");
    scanf("%f",&vec->w);
    printf("\n");
}
void vec4_display( vec4 vec)
{
    printf("%.2f \n", vec.x);
    printf("%.2f \n", vec.y);
    printf("%.2f \n", vec.z);
    printf("%.2f \n", vec.w);
    printf("\n");
}


void float_display(float f)
{
    printf("%.2f \n",f);
}

void str_display(const char * ch)
{
    printf("%s",ch);
}
 
void mat4_display(Mat4 mat)
{
    for(int i =0; i < 4; i++)
    {
        for(int j =0; j< 4;j++)
        {
            printf("%.2f \t",mat.mat4[i * 4 + j]);
        }
        printf("\n");
    }
} 