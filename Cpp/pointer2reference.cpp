#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    /*struct Rectangle r={10,5};*/ 
    Rectangle r ={15,5};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;


    Rectangle *p=&r;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;

    Rectangle *q;
    q=(struct Rectangle *)malloc(sizeof(struct Rectangle));
    q=new Rectangle;

    q->length=22;
    q->breadth=33;

    cout<<q->length<<endl;
    cout<<q->breadth<<endl;

    return 0;
}