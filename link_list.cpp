#include<iostream>
using namespace std;
struct node
{
    int value;
    node *next;
};

node *head=NULL, *previousAddress =NULL;
//Start insert value
void insertValue(int newValue)
{
    node *currentAddress = new node();// create a new address
    currentAddress->value = newValue;
    if (head == NULL)
    {
        head = currentAddress;
        previousAddress = currentAddress;
    }
    else
    {
        previousAddress->next = currentAddress;
        previousAddress = currentAddress;
    }
}
//Function for Delete value
void deleteValue(int srcValue)
{
    node *currentAddress = head;
    node *previousAddress = NULL;

    while(currentAddress != NULL)
    {
        if(currentAddress->value == srcValue)
        {
            if(head->value == srcValue)
                head = head->next;
            else
                previousAddress->next = currentAddress->next;
            break;
        }
        previousAddress = currentAddress;
        currentAddress = currentAddress->next;
    }
}

void print_link_list()
{
    node *currentAddress = head;
    while(currentAddress!=NULL) //until get NULL
    {
        cout<<currentAddress->value<<" "; // print value of current address.
        currentAddress = currentAddress->next;
        /*
         currentAddress = currentAddress->next;
          Here next address replace with current address.
        */
    }
    cout<<endl;
}
int main()
{
    insertValue(2);
    insertValue(5);
    insertValue(8);
    insertValue(7);
    cout<<"Before delete link list: ";
    print_link_list();
    deleteValue(5); // delete 5 from link list
    cout<<"After delete link list: ";
    print_link_list();
}

