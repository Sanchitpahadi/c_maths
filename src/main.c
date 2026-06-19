#include"test.h"
#include <math.h>

typedef struct 
{
    vec3 origin;
    vec3 direction;
}Ray;

int main()
{
    
    test_vec3_aabb();
    test_collision_aabb();
    test_collision_detection();
    test_matrix();
    test_sphere();
    test_vector();
    return 0;
}