#include<iostream>
using namespace std;
void heapify(int arr[],int n,int root);
void build_heap(int arr[],int n);
void heap_sort(int arr[],int n);
void print(int arr[],int n)
{
    cout<<"[";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        if(i+1!=n)
        {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}
main()
{
    int arr[20];
    for(int i=0;i<20;i++)
    {
        arr[i]=i;
    }
    print(arr,20);
    heap_sort(arr,20);
    cout<<"AFTER BUILDING HEAP "<<endl;
    build_heap(arr,20);
    print(arr,20);
    cout<<"AFTER HEAP SORT"<<endl;
    heap_sort(arr,20);
    print(arr,20);
}


void heapify(int arr[],int n,int root)
{
    int largest=root,left=2*root+1,right=2*root+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
     if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }

    if(largest!=root)
    {
        int x=arr[largest];
        arr[largest]=arr[root];
        arr[root]=x;
        heapify(arr,n,largest);
    }
   
}

void build_heap(int arr[],int n)
{
    for(int i=n;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}

void heap_sort(int arr[],int n)
{
    build_heap(arr,n);
 for(int i=n;i>=0;i--)
 {
    int temp=arr[i];
    arr[i]=arr[0];
    arr[0]=temp;
    heapify(arr,i,0);
 }   
}