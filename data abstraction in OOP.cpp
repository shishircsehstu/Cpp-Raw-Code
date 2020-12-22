#include<iostream>
using namespace std;
class parent
{
public:
    virtual void send_message()=0;
    /*
    pure virtual function. Have only declaration
    but no details what is happening here
    */

};
class bob:public parent
{
public:
    void call()
    {
        cout<<"Hi! This is Bob\n";
    }
};
class david:public parent
{
public:

    void call()
    {
        cout<<"Hi! This is David\n";
    }
};
int main()
{

    parent *ob_parent;
    bob ob_bob;
    david ob_david;

    ob_parent = &ob_bob;

    ob_parent->call();
    ob_parent = &ob_child2;
    ob_parent->call();
}

