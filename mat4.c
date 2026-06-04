#include"mat4.h"

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