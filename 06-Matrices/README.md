# Matrices

- Diagonal Matrix
- Lower Triangular Matrix
- Upper Triangular Matrix
- Symmetric Matrix
- Tri diagonal Matrix
- Band Matrix
- Toeplitz Matrix
- Sparse Matrix

## Diagonal Matrix

A Matrix `m` `n x n` = `5 x 5` is said to be Diagonal Matrix. if all the values of the matrix are `0` except the diagonal elements.
$$m[i,j]=0  if(i!=j) $$
m =  
| 1 0 0 0 |  
| 0 2 0 0 |  
| 0 0 3 0 |  
| 0 0 0 4 |  

- If we tried to store all the elements of 5 x 5 = 25 values. Let's assume int take 2 bytes. So, we need 50 bytes of data to store this 5 x 5 diagnol matrix.
- Its also time and space consuming while multiply `0` with `0`.
- Instead we need to store all the non `0` values in a single dimensional array. Which saves time and space.

syntax:

```C
A = 1,2,3,4
m[i,j]
if(i==j)
printf(A[i-1])
```

## code

```C
#include<stdio.h>

struct Matrix{
int A[10];
int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if(i==j)
        m->A[i-1]=x;
}

int get(struct Matrix m,int i, int j)
{
    if(i==j)
        return m.A[i-1];
    else 
        return 0;
}

void Display(struct Matrix m)
{
    for(int i=0;i<m.n;i++)
    {
        for(int j=0;j<m.n;j++)
        {
            if(i==j)
                printf("%d ",m.A[i]);
            else
            printf("0 ");
        }
    printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n=4;

    set(&m,1,1,1);set(&m,2,2,2);set(&m,3,3,3);set(&m,4,4,4);

    printf("%d ",get(m,1,1));
    Display(m);
    return 0;
}
```

- Now we do the same for C++

```c
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Diagonal{
    private:
        int n;
        int *A;
    
    public:
        Diagonal(){
            n=2;
            A = new int[2];
        }
        Diagonal(int n){
            this->n=n;
            A = new int[n];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        ~Diagonal(){delete []A;}
}
void Diagonal::set(int i, int j, int x)
{
    if(i==j)
    {
        A[i-1]=x;
    }
}

int Diagonal::get(int i, int j){
    if(i==j)
        return A[i-1];
    return 0;
}

void Diagonal::Display(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<A[i]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal d(4);

    d.set(1,1,1);d.set(2,2,2);d.set(3,3,3);d.set(4,4,4);

    printf("%d \n",d.get(1,1));

    d.Display();
    return 0;
}

```
