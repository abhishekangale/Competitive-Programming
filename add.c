#include<stdio.h>
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int i=1; i<=testcase; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int sum;
        sum = a + b;
        printf("%d\n",sum);
    }
    return 0;
}