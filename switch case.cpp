#include<iostream>
using namespace std;

void call(int num)
{
    int sum = 0;
    switch(num)
    {
    case 1:
        sum+=1;
        break;
    case 2:
        sum+=2;
        break;
    default:
        sum+=3;
        break;
    }
   cout<<sum<<endl;
}
int main()
{
    call(2);
}
