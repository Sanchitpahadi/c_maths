#include "vec3.h"

typedef struct 
{
    vec3 min;
    vec3 max;
}AABB;


int aabb_aabb(AABB a, AABB b);

int aabb_vec3(vec3 v , AABB b);

