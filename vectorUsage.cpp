#include<iostream>
#include<vector>
using namespace std;
void output_vector_values(vector<int>v);
void reverse_output_vector_values(vector<int>v);
main(){
vector<int> marks;
for(int i=1;i<=5;i++)
marks.push_back(i*10);
cout<<"SIZE "<<marks.size()<<endl;
//alternate syntax
//vector<int> marks{10,20,30,40,50 };
int val=marks[2];
cout<<val<<endl;
output_vector_values(marks);
reverse_output_vector_values(marks);
auto i=marks.begin();
marks.erase(i+2);
cout<<"AFTER DELETING 30"<<endl;
output_vector_values(marks);
} 

void output_vector_values(vector<int>v){
    /*cout<<"[";
    for(auto i=v.begin();i!=v.end();i++)
    cout<<*i<<"\t";
    cout<<"]"<<endl;*/
    cout<<"[";
    for(int x:v)  //equivalent to for x in v
    cout<<x<<"\t";
    cout<<"]"<<endl;
}
void reverse_output_vector_values(vector<int>v){
   cout<<"[";
    for(auto i=v.rbegin();i!=v.rend();i++)
    cout<<*i<<"\t";
    cout<<"]";
    cout<<endl;
} 
