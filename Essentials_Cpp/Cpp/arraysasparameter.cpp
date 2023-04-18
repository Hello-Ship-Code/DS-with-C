#include<stdio.h>
#include<iostream>
using namespace std;

void fun(int *A,int n) /* array are always passed by address*/
{
 A[0]=50;
 cout<<sizeof(A)<<endl;
 cout<<sizeof(int)<<endl;
 cout<<sizeof(A)/sizeof(int)<<endl;
 for(int i=0;i<n;i++) /*We can't use for each loop on pointers*/
 cout<<"Array elements "<<A[i]<<endl;
}

/*Creating an array in a function returning its address*/
int * func(int size)
{
    int *p;
    p=new int[size];
    for( int i=0;i<size;i++)
    p[i]=i+1;

    return p;
}

int main()
{
 int A[ ] = {2,4,6,8,10};
 int n=5;
 fun(A,n);
 cout<<"size of array is:"<<sizeof(A)/sizeof(int)<<endl;

 for(int x:A)
 cout<<"Array"<<x<<" "<<endl;

int *ptr,sz=5;
ptr=func(sz);
for(int i=0;i<sz;i++)
cout<<"test "<<ptr[i]<<endl;

 return 0;
}