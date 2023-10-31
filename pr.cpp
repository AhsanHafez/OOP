#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v);
void rprint(vector<int> v);
main()
{
vector<int> v;
for(int i=1;i<6;i++)
{
    v.push_back(i*10);
}
auto x=v.begin();

print(v);
v.erase(x+2);
print(v);
}

void print(vector<int> v)
{cout<<"[";
for(auto x:v)
    cout<<x<<",";
    //for(auto i=v.begin();i!=v.end();i++)
      //  cout<<*i<<",";
    cout<<"]"<<endl;
}

void rprint(vector<int> v)
{
    cout<<"[";
    for(auto i=v.rbegin();i!=v.rend();i++)
    cout<<*i<<",";
    cout<<"]"<<endl;
}