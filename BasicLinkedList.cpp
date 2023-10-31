#include<iostream>
#include<string>
using namespace std;
typedef struct node{
    int val;
    node *next;
}node;
node* create_node(node *head,int  value);
void print_list(node *head);
main(){
    int sum=1;
    node *head=new node;
    head->val=1;
    head->next=NULL;
    node*current=NULL;
    node *temp=NULL;
    current=head;
    cout<<"BEFORE DELETING 64"<<endl;
    for(int i=2;i<11;i++){
        current =create_node(current,i*i);
        sum+=current->val;
    }
print_list(head);
cout<<"THE SUM OF LIST IS "<<sum <<endl;
current=head;
for(int i=0;i<6;i++){
    current=current->next;
}
temp=current->next;
current->next=temp->next;
delete temp;
cout<<"AFTER DELETING 64"<<endl;
print_list(head);
}
void print_list(node *head){
node *current=head;
cout<<'[';
for(;current!=NULL;){
    cout<<current->val;
    current=current->next;
    if(current!=NULL)
    cout<<" , ";
}
cout<<']';
cout<<endl;
}
node* create_node(node *head ,int  value){
    node *current =new node;
    head->next=current;
    current->next=NULL;
    current->val=value;
    return current;
    
}