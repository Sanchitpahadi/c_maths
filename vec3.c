 #include"vec3.h"

#include <math.h>

 vec3 vec3_add( vec3 vec, vec3 vec2)
{
    return ( vec3) {vec.x + vec2.x,vec.y + vec2.y,vec.z + vec2.z};
}

 vec3 vec3_sub( vec3 vec, vec3 vec2)
{
    return ( vec3) {vec.x - vec2.x,vec.y - vec2.y,vec.z - vec2.z};
}

 vec3 vec3_scale(float a, vec3 vec)
{
    return ( vec3) {a* vec.x, a * vec.y ,a * vec.z};
}

float vec3_dot(vec3 a,  vec3 b)
{
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

 vec3 vec3_cross( vec3 vec, vec3 vec2)
{

    return ( vec3)
            {
                vec.y * vec2.z - vec.z * vec2.y,
                vec.z * vec2.x -  vec.x * vec2.z,
                vec.x * vec2.y - vec.y * vec2.x
            };
}

vec3 vec3_normalize( vec3 vec)
{
    vec3 temp = vec;
    return (vec3)
    {
        vec.x/temp.x,
        vec.y/temp.y,
        vec.z/temp.z
    };
}

float vec3_length( vec3 vec)
{
    return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}