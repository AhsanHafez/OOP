#include<iostream>
using namespace std;
template <class T>
class LinkedList{
    protected:
    struct node
    {
        T val;
        node *next;
    };
    node *head;
    node *last;
    public:
    LinkedList();
    void push(T value);
    T pop();
    void print_list();
    void insert(int index,T value);
    void remove(T value);
    };
int main()
{
   LinkedList<string> l;
    l.push("AHSAN");
    l.push("SAQIB");
    l.push("ZOAHIB");
    l.insert(0,"ZAID");
    l.insert(33,"BILAL");
    l.print_list();
    l.remove("ZOHAIB");
    l.print_list();
    return 0;
}
template <class T>
LinkedList<T>::LinkedList()
{
this->head=NULL;
this->last=NULL;
}
template <class T>
void LinkedList<T>::push(T value)
{
    node *n=new node;
    n->val=value;
    n->next=NULL;
    if(head==NULL)
    {
       head=n;
       last=head;
        return;
    }
    last=head;
    for(;last->next!=NULL;)
    {
        last=last->next;
    }
    last->next=n;

}
template <class T>
void LinkedList<T>::print_list()
{
last=head;
cout<<"[";
for(;last!=NULL;)
{
    cout<<last->val;
    last=last->next;
    if(last!=NULL){
        cout<<",";
    }
}
cout<<"]"<<endl;
}

template <class T>
T LinkedList<T>::pop()
{
if(head==NULL)
{
    throw "WARNING TRYING TO POP FROM EMPTY LIST \n";
}
last=head;
node *temp=last;
for(;last->next!=NULL;)
{
    temp=last;
    last=last->next;
}
T val=last->val;
last=temp;
temp->next=NULL;
delete last;
return val;
}

template <class T>
void LinkedList<T>::insert(int index,T value){
    node *ne=new node;
    ne->val=value;
    ne->next=NULL;
    int i;
    if(head==NULL)
    {
        head=ne;
        last=head;
        return ;
    }
    if(index==0)
    {
        ne->next=head;
        head=ne;
        return;
    }
    last=head;
    node *prev=last;
    for(i=1;i<=index&&last!=NULL;i++)
    {
        prev=last;
        last=last->next;
    }
    if(i==index)
    {
        prev->next=ne;
        ne->next=last;
        return;
    }
    else
    {
        prev->next=ne;
    }
}

template <class T>
void LinkedList<T>::remove(T value)
{
if(head==NULL)
{
    throw "CANNOT REMOVE FROM EMPTY LIST\n";
}
node *temp;
last=head;
for(;last!=NULL&&last->val!=value;)
{
temp=last;
last=last->next;
}
if(last==head)
{
    head=head->next;
    delete last;
    return;
}
if(last==NULL)
{
cout<<"VALUE NOT FOUND"<<endl;
return;
}
if(last->val==value)
{
if(last->next==NULL)
{
temp->next=NULL;
delete last;
return;
}

else
{
temp->next=temp->next->next;
delete last;
}

}

}