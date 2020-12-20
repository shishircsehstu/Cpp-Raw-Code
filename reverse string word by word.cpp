#include<bits/stdc++.h>
#define siz 10001
using namespace std;
vector<string>words;
char input[siz];

string get_reverse_str(char input_str[])
{
    string str_tmp;
    int len = strlen(input_str);
    for(int i = 0; i<len ; i++)
    {
        if(input_str[i]==' ')
        {
            words.push_back(str_tmp);
            str_tmp.clear();
        }
        else
            str_tmp+=input_str[i];
    }

    words.push_back(str_tmp);
    str_tmp.clear();

    for(int i=words.size()-1; i>=0; i--)
    {
        str_tmp+=words[i];
        if(i>0) str_tmp+=' ';
    }
    return str_tmp;

}
int main()
{
    string reverse_str;
    cout<<"Enter a string\n";
    gets(input);
    reverse_str = get_reverse_str(input);
    cout<<reverse_str<<endl;

    return 0;

}
