
#include<stdio.h>
#define siz 10001
int array[siz];
void bubble_sort(int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(array[i]>array[j])
            {
                int tmp = array[i];
                array[i]=array[j];
                array[j] = tmp;
            }
        }
    }
}
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&array[i]);
    bubble_sort(n);
    for(i=0; i<n; i++)
        printf("%d ",array[i]);
}


