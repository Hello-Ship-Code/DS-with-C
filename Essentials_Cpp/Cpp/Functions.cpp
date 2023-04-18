#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int add( int a , int b )
{
int c;
c = a + b;
return c;
}

int main ( )
{
int x,y,z;
x = 10;
y = 5;
z = add (x, y);
printf("sum is %d\n",z);
cout<<"Sum is "<< z;

return 0;
}