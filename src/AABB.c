#include "AABB.h"

int aabb_aabb(AABB a, AABB b)
{
    int overlaps = (a.max.x >= b.min.x && a.min.x <= b.max.x && a.max.y >= b.min.y && a.min.y <= b.max.y &&  a.max.z >= b.min.z && a.min.z <= b.max.z);
   return overlaps;
}

int aabb_vec3(vec3 v , AABB b)
{
    return (v.x > b.min.x && v.x < b.max.x && v.y > b.min.y && v.y < b.max.y &&v.z > b.min.z && v.z < b.max.z );
}
