    #include <iostream>
using namespace std;
#define SIZE 5
void pause();
class Queue{
    private:
    bool is_empty,is_full;
    int in,out;
    int q[SIZE];
    void inc(int *arrow);
    public:
    Queue();
    void enqueue(int val);
    int dequeue();
    void print_queue();

};
main()
{ try{
   Queue  que;
   que.print_queue();

    que.enqueue(5);
    que.print_queue();

    que.enqueue(11);
    que.print_queue();

    que.enqueue(22);
    que.print_queue();

    que.enqueue(33);
    que.print_queue();

    que.enqueue(44);
    que.print_queue();

  //  que.enqueue(55);
  //  que.print_queue();

cout<<"AFTER DEQUE"<<endl;
int got_value =que.dequeue();
que.print_queue();
 
got_value =que.dequeue();
que.print_queue();

got_value =que.dequeue();
que.print_queue();

got_value =que.dequeue();
que.print_queue();

got_value =que.dequeue();
que.print_queue();}
catch(const char *msg){
    cout<<msg<<endl;
}


}  
Queue::Queue(){
    for(int i=0;i<SIZE;i++){
        q[i]=0;
    }
    in=out=0;
    is_empty=true;
    is_full=false;
}
void Queue::inc(int *arrow){
if( *arrow +1 ==SIZE){
    (*arrow)=0;
}
else{
    (*arrow)+=1   ;
}

}
void Queue::enqueue(int val)
{

if(is_full){
    throw "QUEUE IS ALREADY FILLED CANNOT ENQUEUE MORE.....";
}
else{
    q[in]=val;
    inc(&in);
    if(in==out){
        is_full=true;
    }
    is_empty=false;
}
}

int Queue::dequeue()
{
    int ret=0;
    if(is_empty)
    {
        throw "QUEUE IS ALREADY EMPTY CANNOT DEQUEUE MORE...";
    }
    else
    {
        ret=q[out];
        inc(&out);
    }
    if(in==out){
        is_empty=true;
    }
    is_full=false;
    return ret;
}
void Queue::print_queue(){
    cout<<"[\t";
    for(int i=0;i<SIZE;i++)
    cout<<q[i]<<"\t";
    cout<<"]"<<endl;

    cout<<' ';
    cout<<"\t";
    for(int i=0;i<SIZE;i++)
    cout<<i<<"\t";
    cout<<endl;

    cout<<" ";
    cout<<"\t";
    for(int i=0;i<in;i++)
    cout<<"\t";
    cout<<"^in"<<endl;

    cout<<" ";
    cout<<"\t";
    for(int i=0;i<out;i++)
    cout<<"\t";
    cout<<"^out"<<endl;

    pause();
}
void pause(){
    getchar();
}