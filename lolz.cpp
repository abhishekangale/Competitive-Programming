#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dotprod(int *v1, int *v2)
{
    int dotprod;
    dotprod= v1[0]*v2[0] + v1[1]*v2[1];
    return dotprod;
}

float vecprod(float *v1, float *v2)
{
    int vecprod;
    int i1, i2, j1, j2;
    
    i1=v1[0]; j1= v1[1]; i2= v2[0]; j2= v2[1];
    vecprod= (j1*i2-i1*j2);
    return vecprod;
}

int main()
{
    float v1[2]={0}, v2[2]={0};

    printf("Enter vectors in the format 'i, j':");
    printf("Enter v1: ");
    scanf("%f, %f", &v1[0], &v1[1]);
    printf("Enter v2: ");
    scanf("%f, %f", &v2[0], &v2[1]);

    printf("Vector Product: %f", vecprod(v1, v2));
    exit(0);
}