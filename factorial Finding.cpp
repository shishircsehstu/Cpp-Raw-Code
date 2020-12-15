#include<iostream>
using namespace std;
int get_Factorial(int N)
{
    if(N==0|| N==1)
        return 1;
    return N*get_Factorial(N-1);
}
int main()
{
    long long num,fact;
    cout<<"Enter a number: ";
    cin>>num;
    fact = get_Factorial(num);
    cout<<"Factorial is "<<num<<"! = "<<fact<<endl;
    return 0;

}
