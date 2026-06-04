#include <stdio.h>
#include "umath.h"
struct Object {
    float mass;
    float acceleration;
    float velocity;
};



int main()
{
    struct Object obj;
    float time = 2.0f;
    obj.velocity = 10.0f;
    obj.mass = 20;
    float force;

    obj.acceleration = derivative(obj.velocity , time);


    printf("accelration =  %.2f \n",obj.acceleration);

    force = obj.acceleration * obj.mass;

    printf("force  =  %.2f \n", force);


    return 0;
}