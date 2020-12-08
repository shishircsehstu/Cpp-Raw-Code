
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)


typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction


string keyword[32]= {"auto","break","case","char","const",
                     "continue","default", "do","double","else","enum","extern",
                     "float","for","goto", "if","int","long","register","return",
                     "short","signed", "sizeof","static","struct","switch",
                     "typedef","union", "unsigned","void","volatile","while"
                    };

string str;
int pos;
string getrelop()
{
    int state=0;
    while(1)
    {
        switch(state)
        {
        case 0:
            if(str[pos]=='<')state=1;
            else if(str[pos]=='=')state=5;
            else if(str[pos]=='>')state=6;
            else return "fail";
            pos++;
            break;
        case 1:
            if(str[pos]=='=')state=2;
            else if(str[pos]=='>')state=3;
            else state=4;
            pos++;
            break;
        case 2:
            pos++;
            return "LE";
        case 3:
            pos++;
            return "NE";
        case 4:
            return "LT";
        case 5:
            pos++;
            return "EQ";
        case 6:
            if(str[pos]=='=')state=7;
            else state=8;
            pos++;
            break;
        case 7:
            pos++;
            return "GE";
        case 8:
            return "GT";
        }
    }
}
string getid()
{
    int state=9;
    string temp="";
    while(1)
    {
        switch(state)
        {
        case 9:
            if(isalpha(str[pos])||str[pos]=='_')
            {
                state=10;
                temp+=str[pos];
            }
            else return "8fail";
            pos++;
            break;
        case 10:
            if(isalnum(str[pos]))
            {
                state=10;
                temp+=str[pos];
            }
            else return temp;
            pos++;
            break;
        }
    }
}
string getnum()
{
    int  state=12;
    string temp="";
    while(1)
    {
        switch(state)
        {
        case 12:
            if(isdigit(str[pos]))state=13;
            else return "fail";
            temp+=str[pos];
            pos++;
            break;
        case 13:
            if(isdigit(str[pos]))state=13;
            else if(str[pos]=='.')state=14;
            else if(str[pos]=='E')state=16;
            else return temp;
            temp+=str[pos];
            pos++;
            break;
        case 14:
            if(isdigit(str[pos]))state=15;
            else return "fail";
            temp+=str[pos];
            pos++;
            break;
        case 15:
            if(isdigit(str[pos]))state=15;
            else if(str[pos]=='E')state=16;
            else return temp;
            temp+=str[pos];
            pos++;
            break;
        case 16:
            if(isdigit(str[pos]))state=18;
            else if(str[pos]=='+'||str[pos]=='-')
                state=17;
            temp+=str[pos];
            pos++;
            break;
        case 17:
            if(isdigit(str[pos]))state=18;
            temp+=str[pos];
            pos++;
            break;
        case 18:
            if(isdigit(str[pos]))state=18;
            else return temp;
            temp+=str[pos];
            pos++;
            break;
        }
    }
}
string getws()
{
    int state =22;
    while(1)
    {
        switch(state)
        {
        case 22:
            if(str[pos]>=0&&str[pos]<=32)state=23;
            else return "fail";
            pos++;
            break;
        case 23:
            if(str[pos]>=0&&str[pos]<=32)state=23;
            else return "Whitespace";
            pos++;
            break;
        }
    }
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    while(getline(cin,str))
    {
        pos=0;
        while(pos<str.length())
        {
            string relop=getrelop();
            if(relop!="fail")//Relational Operator Check
            {
                pos--;
                cout<<"Relop "<<relop<<"\n";
                continue;
            }
            string id =getid();//Identifier Check
            if(id!="8fail")
            {
                bool ans=true;
                FOR(i,0,31)
                if(id==keyword[i])//Keyword Check
                {
                    ans=false;
                    break;
                }
                if(ans)
                    cout<<"Id "<<id<<"\n";
                else
                    cout<<"Key "<<id<<"\n";
                continue;
            }
            string num=getnum();//Number Check
            if(num!="fail")
            {
                cout<<"Num "<<num<<"\n";
                continue;
            }
            string whites=getws();//Whitespace Check
            if(whites!="fail")
            {
                cout<<"WS "<<"\n";
                continue;
            }
            //Unary Operator Check
            if(str[pos]=='+'||str[pos]=='-'||
                    str[pos]=='*'||str[pos]=='/'||str[pos]=='%')
            {
                cout<<"Unary "<<str[pos]<<"\n";
                pos++;
                continue;
            }
            pos++;
        }
    }
    return 0;
}
