#include<iostream>
#include<math.h>
using namespace std;
#include <time.h>
float distance(float a,float b)
{
    return sqrt(pow(a,2) + pow(b,2) );
}

float random()
{
      srand( (unsigned)time( NULL ) );
      return  (float) rand()/RAND_MAX ;

}
float r()
{
    static float x=0;
    
    x+=0.001;
    return x;
}
float estimati_pi(double darts);
int main()

{
    double darts=1e10;
    cout<<darts<<endl;
    cout<<estimati_pi(darts)<<endl;
    return 0;
}





float estimati_pi(double darts)
{
    int inside=0;
    for(int i=0;i<darts;i++)
    {
        float x=random();
        float y=random();
        
        if (distance(x,y)<1.0)
        {
            inside++;
        }

    }

    return ( (inside/darts)*4  );
}