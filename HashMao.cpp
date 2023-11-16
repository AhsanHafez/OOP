#include<iostream>
using namespace std;
#include<vector>
template <class T>
struct maps
{
    int key;
    T value;
};
class HashMaps{
    public:
    int size=10;
    vector<maps<string>> arr[10];
    HashMaps()
    {
       
    }
    int hash(int key)
    {
        return key%size;
    }
    void add(int key,string value)
    {
        int idx=this->hash(key);
        maps<string> temp;
        temp.key=key;
        temp.value=value;
        arr[idx].push_back(temp);
    }
    string search(int key)
    {
        int idx=this->hash(key);
        auto v=arr[idx];
        for(auto x=v.begin();x!=v.end();x++)
        {
            if(x->key==key)
            {
                return x->value;
            }
        }
        throw "Key Not found";
    }
void remove(int key)
{
    int idx=this->hash(key);
    auto v=arr[idx];
    int z=0;

        auto x=v.begin();
        v.erase(x+2);
    //throw "...";

    
}
void print()
{
    for(int i=0;i<size;i++)
    {
        auto v=arr[i];
        for(auto x=v.begin();x!=v.end();x++)
        {
            cout<<x->key<<" = "<<x->value<<endl;
        }

    }
}

};
main()
{
    HashMaps h;
    maps<string> k;
    int n;
    cout<<"ENTER HO MANY VALUES YOU WANT TO ENTER"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER KEY"<<endl;
        cin>>k.key;

        cout<<"ENTER VALUE"<<endl;
        cin>>k.value;
        h.add(k.key,k.value);
        cout<<"YOU HAVE ENTERED "<<i+1 << " VALUE" <<endl;
    }
    h.print();
    cout<<"ENTER KEY YOU WANT TO SEARCH "<<endl;
    cin>>n;
    cout<<"VALUE OF KEY IS " <<h.search(n)<<endl;
    cout<<"ENTER VALUE YOU WANT TO DELETE"<<endl;
    cin>>n;
    h.remove(n);
    h.print();
}
