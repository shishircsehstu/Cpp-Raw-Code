#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
bool search(Node* root,int data)
{
    if(root==NULL)
        return false;
    else if(root->data==data)
        return true;
    else if(data<=root->data) return search(root->left,data);
    else return search(root->right,data);
}
Node* newNode(int data)
{
    Node *newnode=new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    printf("before return %d\n",newnode);
    return newnode;
}
Node* insert(Node *root,int data)
{
    if(root==NULL)
    {
        root=newNode(data);
        printf(" after return %d\n",root);
    }
    else if(data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
int main()
{
    Node *root =NULL;
    int i,j,n,k,x,t;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&k);
        root=insert(root,k);
        printf("return root %d\n",root);
    }
    scanf("%d",&x);
    if(search(root,x)==true)
        printf("Yes! %d has found\n",x);
    else
        printf("No! %d has not found\n",x);
}
