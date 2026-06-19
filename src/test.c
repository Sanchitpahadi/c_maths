#include"test.h"

void test_vector()
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

void test_matrix()
{
   Mat4 mat;

    vec4 v = (vec4){1.0f, 0.0f, 0.0f, 1.0f};
    vec4 v1 = (vec4){1.0f, 1.0f, 1.0f, 1.0f};

    mat4_identity(&mat);

    mat4_display(mat);
    Mat4 mat1 = mat4_translation(5.0f, 3.0f, 2.0f);
    Mat4 mat2 = mat4_scale(2.0f, 3.0f, 4.0f);

    vec4_display(mat4_mul_vec4(mat1,v));

    vec4_display(mat4_mul_vec4(mat2,v1));

}

void test_collision_aabb()
{
    AABB A ;// min `(-1,-1,-1)` max `(1,1,1)`
    AABB B; // min `(0,0,0)` max `(2,2,2)` → overlapping
    AABB C; //min `(3,3,3)` max `(5,5,5)` → not overlapping

    A.min = (vec3){-1,-1,-1};
    A.max = (vec3){1,1,1};

    B.min = (vec3){0,0,0};
    B.max = (vec3){2,2,2};

    C.min = (vec3){3,3,3};
    C.max = (vec3){5,5,5};

    int overlapping;

    overlapping = aabb_aabb(A,B);
    if(overlapping)
    {
        str_display("Overlaping\n");
    }
    else
    {
        str_display("Not overlaping\n");
    }
    overlapping = aabb_aabb(A,C);

    if(overlapping)
    {
        str_display("Overlaping\n");
    }
    else
    {
        str_display("Not overlaping \n");
    }
}

void test_vec3_aabb()
{
    AABB A ;// min `(-1,-1,-1)` max `(1,1,1)`
    AABB B; // min `(0,0,0)` max `(2,2,2)` → overlapping
    AABB C; //min `(3,3,3)` max `(5,5,5)` → not overlapping

    A.min = (vec3){-1,-1,-1};
    A.max = (vec3){1,1,1};

    B.min = (vec3){0,0,0};
    B.max = (vec3){2,2,2};

    C.min = (vec3){3,3,3};
    C.max = (vec3){5,5,5};

    vec3 a = {0.5, 0.5, 0.5};
    vec3 b = {5.0, 0.0, 0.0};

    if(aabb_vec3(a,A))
    {
        str_display("its inside the box \n");
    }
    else
    {
        
        str_display("it is not inside the box \n");

    }
    if(aabb_vec3(b,A))
   {
        str_display("its inside the box\n");
    }
    else
    {
        
        str_display("it is not inside the box\n");

    }
}

void test_sphere()
{
   sphere s;
    s.center = (vec3){0.0 , 0.0 , 0.0};
    s.radius = 2.0;

   // vec3_display(s.center);
    
   // float_display(s.radius);

    sphere A ;  //(0,0,0)` radius `2`
    sphere B ;  //(3,0,0)` radius `2` → overlapping
    sphere C ;  //(6,0,0)` radius `1` → not overlapping

    B.center = (vec3){3.0 , 0.0 , 0.0};
    B.radius = 2.0;

    C.center = (vec3){6.0 , 0.0 , 0.0};
    C.radius = 1.0;

    sphere_vs_sphere(s,B);
    sphere_vs_sphere(s,C);

}

void test_collision_detection()
{
    vec3 va = {0.0,0.0,0.0}, vb = {3.0,4.0,0.0};

    printf(" length of the two vectors :: %f \n",vec3_distance(va,vb)); // vec3_distance calculates the distance between two object
}