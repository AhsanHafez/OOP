#include<iostream>
using namespace std;
int  move_disk(int n,char from_rod,char to_road,char aux_rod);
void print_move(int disk,char from_rod,char to_rod);
main(){
    int n=3;
    cout<<move_disk(n,'A','C','B');
}
int move_disk(int n,char from_rod,char to_rod,char aux_rod){
    static int counter=0;
    counter+=1;
if(n==1){
      //moving largest disk to desired point
    //here aux is extra rod
   print_move(1,from_rod,to_rod);
    return counter;}
    //moving smaller disk to auxilary or extra rod
    //here to_rod is auxilary
    move_disk(n-1,from_rod,aux_rod,to_rod);
  
    print_move(n,from_rod,to_rod); 
    //moving smaller disks over larger disk at desired point
    //here from_rod is auxilary
    move_disk(n-1,aux_rod,to_rod,from_rod);

    return counter;

}
void print_move(int disk,char from_rod,char to_road){
    cout<<"move disk"<<disk<<" from rod "<<from_rod<<" to rod "<<to_road<<endl;
}  