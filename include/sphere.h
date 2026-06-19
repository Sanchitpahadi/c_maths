#pragma once
#include "vec3.h"

typedef struct 
{
    vec3 center;
    float radius;
}sphere;

int sphere_vs_sphere(sphere a, sphere b);