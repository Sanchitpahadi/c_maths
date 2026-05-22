#include<stdio.h>

int main()
{
    int i,j;
    for(int k =0; k<2;k++)
    {
        for(i=1; i<8;i++)
        {
            for(j=0;j<i;j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    for(i = 0;  i<4; i++)
    {
    printf("*\n");

    }
    printf("\n");
    return 0;
}