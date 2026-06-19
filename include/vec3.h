#pragma once

typedef struct {
    float x;
    float y;
    float z;

}vec3;

//basic 
 vec3 vec3_add( vec3 vec, vec3 vec2);
 vec3 vec3_sub( vec3 vec, vec3 vec2);
 vec3 vec3_scale(float a, vec3 vec);

// products
float vec3_dot( vec3 a,  vec3 b);
vec3 vec3_cross( vec3 vec, vec3 vec2);

//utilities
vec3 vec3_normalize( vec3 vec);
float vec3_length( vec3 vec);

float vec3_distance(vec3 A, vec3 B);


