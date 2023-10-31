#include <iostream>
using namespace std;
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int l(int fn(int a,int b),int fn2(int a,int b),int a,int b, string cal)
{
    if(cal=="max")
    {
        return fn(a,b);
    }
    else
    {
        return fn2(a,b);
    }
}
main()
{
   cout<< l(max,min,2,3,"m")<<endl;
}