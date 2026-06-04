#include<stdio.h>

#include"vec3.h"
#include"vec4.h"

#include"mat4.h"
#include "help.h"

void vector()
{
    vec3 v,v2,v3,v4,v5;
    v3 =  ( vec3) {3.4,5.6,7.6};
    v4 =  ( vec3) {4.5,6.6,7.6};
    v5 = ( vec3) {1.0,1.0,1.0};

    vec3 added = vec3_add(v3 , v4);
    vec3 scaled = vec3_scale(2.5,v5);
    float dot = vec3_dot(v3,v4);

    vec3 result = vec3_cross(v3,v4);

    float check = vec3_dot(result,v4);

    str_display("display added \n");
    vec3_display(added);

    str_display("display scaled \n");

    vec3_display(scaled);

    str_display("display dot \n");


    float_display(dot);

    str_display("length \n");

    float_display(vec3_length(v5));
    float_display(vec3_length(v3));

    str_display("display result \n");
    vec3_display(result);

    str_display("display check \n");
    float_display(check);
}