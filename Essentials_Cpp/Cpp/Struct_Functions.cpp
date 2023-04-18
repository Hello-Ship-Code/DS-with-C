#include<stdio.h>
#include<iostream>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

void initialise(struct Rectangle *r, int l, int b)
{
    r->length=l;
    r->breadth=b;
}

int area (struct Rectangle r)
{
    return r.length*r.breadth;
}

int perimeter(struct Rectangle r)
{
    int p;
    p = 2 * ( r.length + r.breadth );

    return p;
}

int main()
{
    Rectangle r={0,0};
    int l,b;
    printf("Enter the length & breadth\n");
    cin>>l>>b;
    /* cin>>r.length>>r.breadth; Can also initialize like this or create a function for initialization*/
    initialise(&r, l,b);

    int a=area(r);
    int peri= perimeter(r);
    printf("The area of rectangle is: %d & the perimeter of the rectangle is:%d",a,peri);

    return 0;
}