#include<stdio.h>
#include<iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
} // r1,r1,r3;
/* r2 Can also declare while initializing the struct*/;
  /*struct Rectangle r1;  Can also declare the structure here also. which is available globally*/

int main()
{
    
  struct Rectangle r1={10,5};

  printf("%lu\n", sizeof(r1)); 
  cout<<r1.length<<endl;
  cout<<r1.breadth<<endl;

  r1.length=15;
  r1.breadth=7;
  printf("%d \n%d", r1.length,r1.breadth);

  return 0;

}