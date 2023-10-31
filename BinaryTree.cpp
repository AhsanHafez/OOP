#include <iostream>
using namespace std;
class TreeNode
{
    public:
    int value;
    TreeNode *right,*left,*root=NULL;
    TreeNode(int val);
    void in_order();
    void push(int val);
    bool search(int val);
    void deleteval(int val);
    void replace(TreeNode *t);
    
};

main()
{
    TreeNode t(1);
    t.left=new TreeNode(3);
    t.right= new TreeNode(2);
    t.right->right=new TreeNode(55);
    t.right->right->right=new TreeNode(101);
    t.right->right->right->right=new TreeNode(1019);
    t.right->right->right->left=new TreeNode(200);
    t.right->right->left=new TreeNode(87);
    t.left->left=new TreeNode(5);
    t.left->right=new TreeNode(15);
    //t.in_order(&t);
    TreeNode t2(5);
    t2.push(1);
    t2.push(20);
    t2.push(10);
    t2.push(50);
    t2.push(30);
    t2.push(40);
    t2.push(60);
    t2.in_order();
    int arr[]={5,1,20,10,50,30,40,60,33,44,56,78};
    for(int x:arr)
    {
        //cout<<t2.search(x )<<endl;
    }
}
 void TreeNode::in_order()
    {
    if(this->left!=NULL)
    {  this->left->in_order();}
    cout<<this->value<<endl;
    if(this->right!=NULL)
    {  this->right->in_order();}
    }
 void TreeNode::push(int val)
    {
        if(this->value<val)
        {
            if(this->right==NULL)
            {
                this->right=new TreeNode(val);
            }
            else
            {
                this->right->push(val);
            }
        }

        else
        {
            if(this->left==NULL)
            {
                this->left=new TreeNode(val);
            }
            else
            {
                this->left->push(val);
            }
        }
    }
TreeNode::TreeNode(int val)
    {
        this->value=val;
        this->right=NULL;
        this->left=NULL;
        root=this;
    }
bool TreeNode::search(int val)
    {
        if(this->value==val)
        {
            return 1;
        }
        if(val>this->value)
        {
            if(this->right!=NULL)
            {
                return this->right->search(val);
            }
            else
            {
                return 0;
            }
        }

        else
        {
            if(this->left!=NULL)
            {
                return this->left->search(val);
            }
            else
            {
                return 0;
            }
        }
    }
void TreeNode::deleteval(int val)
{
    if (this->value==val)
    {
        if(this->left==NULL and this->right==NULL)
        {
            replace(NULL);
        }

    }
    else
    {
        if(val>this->value)
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