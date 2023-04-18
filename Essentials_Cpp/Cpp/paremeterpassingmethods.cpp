 #include<stdio.h>
 
 void swap(int x , int y)
{
 int temp;
 temp = x;
 x = y;
 y = temp;
}

void swap1(int *x , int *y)
{
 int temp;
 temp = *x;
 *x = *y;
 *y = temp;
}

void swap2(int & x ,int & y)
{
 int temp;
 temp = x;
 x = y;
 y = temp;
}

int main()
{
 int a ,b;
 a =10;
 b=20;
 swap(a,b);
 printf("pass by value %d %d", a ,b);

 swap1(&a,&b);
 printf("\ncall by address %d %d", a ,b);

 swap2(a,b);
 printf("\nCall by reference %d %d", a ,b);
}