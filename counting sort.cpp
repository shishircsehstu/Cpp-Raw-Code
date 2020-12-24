#include<stdio.h>
#define siz 10001
int array[siz],count_array[siz];
int main()
{
    int n,i,j,max_value=0;
    for(i=0; i<=siz; i++)
        count_array[i]=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter the %d elements: ",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
        count_array[array[i]]++;

        if(max_value<array[i])
            max_value = array[i];
    }
    printf("Sorted array: ");
    for(i=0; i<=max_value; i++)
    {
        for(j=0; j<count_array[i]; j++)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
}
