#include<stdio.h>
#include<iostream>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;

void initialise( int l, int b)
{
    length=l;
    breadth=b;
}

int area ()
{
    return length*breadth;
}

int perimeter()
{
    int p;
    p = 2 * ( length + breadth );

    return p;
}
};
int main()
{
    Rectangle r={0,0};
    int l,b;
    printf("Enter the length & breadth\n");
    cin>>l>>b;
    /* cin>>r.length>>r.breadth; Can also initialize like this or create a function for initialization*/
    r.initialise(l,b);

    int a=r.area();
    int peri= r.perimeter();
    printf("The area of rectangle is: %d & the perimeter of the rectangle is:%d",a,peri);

    return 0;
}