#include<iostream>
using namespace std;
#define SIZE 5
class Queue{
    private:
    int q[SIZE];
    int in,out;
    bool is_empty,is_full;
    public:
    void inc(int *arrow);
    void print_queue();
    Queue();
    void enqueue(int val);
    int deque();

};
main(){
    try
    {
     Queue l;

     l.enqueue(5);
     l.print_queue();   

     l.enqueue(10);
     l.print_queue();  

     l.enqueue(15);
     l.print_queue(); 

     l.enqueue(20);
     l.print_queue();   

     l.enqueue(25);
     l.print_queue();  

     //l.enqueue(25);
     //l.print_queue();   

    int get;
cout<<"AFTER DEQUE"<<endl;
    get=l.deque();
    l.print_queue();
    cout<<"THE ELEMENT DEQUEUE IS "<<get<<endl;

    get=l.deque();
    l.print_queue();
    cout<<"THE ELEMENT DEQUEUE IS "<<get<<endl;

    get=l.deque();
    l.print_queue();
    cout<<"THE ELEMENT DEQUEUE IS "<<get<<endl;

    get=l.deque();
    l.print_queue();
    cout<<"THE ELEMENT DEQUEUE IS "<<get<<endl;

    get=l.deque();
    l.print_queue();
    cout<<"THE ELEMENT DEQUEUE IS "<<get<<endl;

    //get=l.deque();
   // l.print_queue();
    }
    catch(const char *msg)
    {
        cout<<"WARNING!!"<<endl;
     cout<<msg<<endl;   
    }
    
}
Queue::Queue(){
    for(int i=0;i<SIZE;i++)
    q[i]=0;
    in=out=0;
    is_full=false;
    is_empty=true;
}
void Queue::enqueue(int val)
{
if(is_full)
{
throw "QUEUE ALREADY FULL CANNOT ENQUEUE ANYMORE.....\n";
}
else
{
    q[in]=val;
    inc(&in);
    is_empty=false;
}
if(in==out)
{

    is_full=true;
}

}
void Queue::inc(int *arrow)
{
    if((*arrow)+1==SIZE )
    {
        *arrow=0;
    }
    else
    {
        (*arrow)++;
    }
}
int Queue::deque()
{
    int temp;
    if(is_empty)
    {
        throw "QUEUE IS ALREADY EMPTY CANNOT DEQUEUE ANYMORE...\n";
    }
    else
    {
        temp=q[out];
        inc(&out);
        is_full=false;
    }
    if(in==out)
    {
        is_empty=true;
    }
    return temp;
}
void Queue::print_queue(){
    cout<<"[\t";
    for(int i=0;i<SIZE;i++)
    cout<<q[i]<<"\t";
    cout<<"]"<<endl;
}