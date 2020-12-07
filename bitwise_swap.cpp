#include<stdio.h>
int main()
{
    int X, Y;
    printf("Enter two value of X and Y: ");
    scanf("%d %d", &X, &Y);
    X=X^Y;
  //  printf("%d \n",X);
    Y=X^Y;
   // printf("%d \n",Y);
    X=X^Y;
    printf("X= %d\nY= %d\n",X,Y);
    return 0;

}
