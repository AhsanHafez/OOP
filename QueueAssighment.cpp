    #include <iostream>
    #include<fstream>
using namespace std;
#define SIZE 10
void pause();
template<class T>
class Queue{
    private:
    bool is_empty,is_full;
    int in,out;
    
    T q[SIZE];
    void inc(int *arrow);
    public:
    Queue();
    void enqueue(T val);
    T dequeue();
    void print_queue();

};
void read_From_file(string filename,Queue<string> *q)
{static int x=0;
cout<<x<<endl;x++;
    ifstream fin;
    fin.open(filename);
    string line;
   for(int i=0;i<SIZE;i++)
   {
    getline(fin,line);
    q->enqueue(line);
   }
   fin.close();
}
void read_queue( Queue<string> *q)
{
    for(int i=0;i<SIZE;i++)
    {
     cout<<q->dequeue()<<endl;   
    }
}

main()
{
Queue<string> s;
Queue<string> *q;
q=&s;
read_From_file("queue.txt",q);
read_queue(q );

}  
template<class T>
Queue<T>::Queue(){
    
    in=out=0;
    is_empty=true;
    is_full=false;
}
template<class T>
void Queue<T>::inc(int *arrow){
if( *arrow +1 ==SIZE){
    (*arrow)=0;
}
else{
    (*arrow)+=1   ;
}

}
template<class T>
void Queue<T>::enqueue(T val)
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
template<class T>
T Queue<T>::dequeue()
{
    T ret;
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
template<class T>
void Queue<T>::print_queue(){
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