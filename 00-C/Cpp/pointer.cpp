#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
 int a=10;
 int *p;
 p=&a;

cout<<a<<endl;
std::cout<<"Here the address of the pointer is stored:"<<p<<endl;
printf("Here the pointer values is stored: %d \n The address of a %d\n",*p,&a);

/* Array*/

int A[5] = {1,2,3,4,5};
int *q=A; // Don't use pointer cause A it self in point at the starting of the array if you want to use & p = &A[0]


for(int i=0;i<5;i++)
{
cout<<A[i];
cout<<",";
cout<<"Q "<<q[i]<<endl; /* printing using pointer*/

}

/* creating array in heap memory C*/

int *s;
s=(int *)malloc(5*sizeof(int)); /*In C*/
//s=new int[5]; in c++ this is dynamic allocation
s[0]=112;
s[1]=232;
s[2]=235;
s[3]=917;
s[4]=128;
for(int w=0;w<5;w++)
cout<<s[w]<<endl;

//delete [ ] s; Freeing in C++ ( deallocating )
free(s); // Freeing in c

return 0;

}






