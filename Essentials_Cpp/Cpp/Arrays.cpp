#include<iostream>
using namespace std;

int main()
{
    int a[5]={1,2,3,4,5};
    cout<<sizeof(a)<<endl;
    printf("%d\n",a[2]);
    printf("%d\n",a[7]);

    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<endl;
    }

    for(int x:a)//for each loop
    { 
        cout<<x<<endl;
    }

    return 0;
}

