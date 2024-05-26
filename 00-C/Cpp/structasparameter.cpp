#include<stdio.h>
#include<iostream>
using namespace std;


struct Rectangle{
    int length;
    int breadth;
};

void fun(struct Rectangle *r)
{
    r->length=20;
    cout<<"Length "<<r->length<<endl<<"breadth "<<r->breadth<<endl;
}

struct Rectangle * func()
{
    struct Rectangle *p;
    p=new Rectangle;

    p->length=15;
    p->breadth=5;

    return p;
}
int main()
{
    struct Rectangle r={10,5};
    fun(&r);
    printf("length %d \nbreadth %d\n",r.length,r.breadth);

    struct Rectangle *ptr=func();
    cout<<"Length of struct:"<<ptr->length<<endl<<"breadth of struct"<<ptr->breadth<<endl;

    return 0;
}