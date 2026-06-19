#include "sphere.h"

// for now only debug it latter


int sphere_vs_sphere(sphere a, sphere b)
{
    //float d = sqrt((a.center.x-b.center.x)*(a.center.x-b.center.x) + (a.center.y-b.center.y)*(a.center.y-b.center.y));
    float d = vec3_distance(a.center,b.center); 
   
    float r = a.radius + b.radius;
    
    //float_display(d);
    //float_display(r);
    if(d<r)
    {
        return 1;
    }
    if(d==r)
    {
        return 0;
    }
    if(d>r)
    {
        return -1;
    }
}



