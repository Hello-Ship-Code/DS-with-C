#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int a=10;
    int &r=a; /* Declaratin & initialization*/
    cout<<r<<endl;
    r=25;
    cout<<r<<endl;
    int b=20;
    r=b;
    cout<<a<<endl<<r<<endl;

    return 0;
}