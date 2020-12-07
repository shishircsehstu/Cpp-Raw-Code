#include<iostream>
using namespace std;
class parentClass
{
protected:    //This is protected access midifier
    int x,y; // this is protected member data

};
class childClass:public parentClass
{
public:
    void setValue(int value1,int value2)
    {
        x=value1,y=value2;
    }
    void dis()
    {
        cout<<"Summation = "<<x+y<<endl;
    }

};

int main()
{
    childClass ob;
    ob.setValue(3,2);
    ob.dis();

}
