#include<iostream>
#include<string.h>
using namespace std;
class TreeNode
{
    public:
    TreeNode()
    {
        
    }
    int val;
    TreeNode *left=NULL,*right=NULL;
    TreeNode(int val)
    {
        this->val=val;
    }
};
class BST
{
    public:
    int val;
    BST *parent,*left=NULL,*right=NULL;
    BST(int val,BST *parent=NULL)
    {
        this->val=val;
        this->parent=parent;
        
    }
    void push(int val,BST *parent=nullptr);
    void replace(BST *child);
    void in_order();
    void deleteval(int val);
    int find_min()
    {
        if(this->left){return this->left->find_min();}
        else{return this->val;}
    }
};
main()
{
    int x,n;
    cout<<"ENTER HOW MANY NODES YOU WANT IN TREE "<<endl;
    cin>>n;
    cout<<"ENTER VALUE OF NODE "<< 1 <<endl;
    cin>>x;
    BST s(x);
    for(int i=0;i<n-1;i++)
    {
        cout<<"ENTER VALUE OF NODE "<<i+2<<endl;
        cin>>x;
        s.push(x);
    }
    cout<<"IN ORDER(ROOT AT MIDDLE) TRAVERSAL OF BNARY TREE"<<endl;
    s.in_order();
    cout<<"ENTER VALUE YOU WANT TO DELETE FROM TREE"<<endl;
    cin>>x;
    s.deleteval(x);
    cout<<"AFTER DELETING "<<20<<endl;
    s.in_order();
    //  "ahsan"=="ahsan"
    char p[]= "ahsan" ,y[]="ahsan";
    cout<<strcmp(p,y);
}
void BST::in_order()
    {
    if(this->left!=NULL)
    {  this->left->in_order();}
    cout<<this->val<<endl;
    if(this->right!=NULL)
    {  this->right->in_order();}
    }


void BST::push(int val,BST *parent)
    {
        if(this->val<val)
        {
            if(this->right==NULL)
            {
                this->right=new BST(val,this);
            }
            else
            {
                this->right->push(val,this);
            }
        }

        else
        {
            if(this->left==NULL)
            {
                this->left=new BST(val,this);
            }
            else
            {
                this->left->push(val,this);
            }
        }
    }

void BST::replace(BST *child)
{
    
    if(this->parent->left==this)
    {
        cout<<"ke";
        this->parent->left=child;
    }
    else
    {
        cout<<"re"<<endl;
        this->parent->right=child;
    }
    if(child!= NULL)
    {cout<<"child"<<endl;
        child->parent=this->parent;
    }

}
void BST::deleteval(int val)
{
    if (this->val==val)
    {
        if(this->left==NULL and this->right==NULL)
        {
           this->replace(NULL);
            cout<<"replace done"<<endl;
            return;
        }
        else if(this->left==NULL || this->right==NULL)
        {
            if(this->left==NULL)
            {
                this->replace(this->right);
            }
            else
            {
                this->replace(this->left);
            }
        }
        else
        {
            int x=this->right->find_min();
            this->val=x;
            this->right->deleteval(x);
        }

    }
    else
    {
        if(val>this->val)
        {
            if(this->right!=NULL)
            {
            this->right->deleteval(val);
            }
            else
            {
                throw "VALUE NOT IN LIST \n";
            }
        }
        else
        {
            if(this->left!=NULL)
            {
            this->left->deleteval(val);
            }
            else
            {
                throw "VALUE NOT IN LIST \n";
            }
        }
    }
}