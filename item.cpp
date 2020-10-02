#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
class Item
{
    string name;
    int cost;
public:
    Item()
    {
        this->name="NULL";
        cost=0;
    }
    Item(string name, int cost)
    {
        this->name = name;
        this->cost = cost;
    }
    void display()
    {
        cout<<"The item details are:"<<endl;
        cout<<"Item name:"<<name<<endl;
        cout<<"Item cost:"<<cost<<endl;
    }
    void * operator new(size_t size)
    {
        cout<<"Overloading new operator"<<endl;
        void * p=malloc(size);
        return p;
    }
    void operator delete(void * p)
    {
       cout<<"Overloading delete operator";
       free(p);
    }
};
int main()
{
    string name;
    int price;
    cout<<"Enter the item details:"<<endl;
    getline(cin,name);
    cin>>price;
    Item* x= new Item(name,price);
    x->display();
    delete x;
    return 0;
}


