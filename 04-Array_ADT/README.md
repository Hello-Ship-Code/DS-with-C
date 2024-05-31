# Array ADT

- Array ADT (Array as Abstract Data Type)
- The representation of data is define by the compiler itself, However the operations on the data must be given by the programmer. The combination of theses 2 on an array is called Array ADT.

## Some possible operations on array are

- Display( )
- Add( x ) / Append( x )
- Insert( index , x )
- Delete( index )
- Search( x )
- Get( index )
- Set( index , x )
- Max( ) / Min( )
- sum ()
- Avg ()
- Reverse( )
- Shift( ) / Rotate( )

## The representation of array data require 3 thing

1. Array Space
2. Size
3. Length( no.of element )

## Demo Array_ADT

```c++
#include<iostream>
using namespace std;
 
class Array{
 
private:
    int *A;
    int size;
    int length;
 
public:
    Array(int size){
        this->size = size;
        A = new int [size];
    }
 
    void create(){
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++){
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }
 
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }
 
    ~Array(){
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main() 
{
    Array arr(10);
    arr.create();
    arr.display();

    return 0;
}
```

## Inserting and Appending in a Array

```c++
#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

 void Display(struct Array arr)
 {
    printf("\nElements are\n");
    for(int i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
 }

 void Append(struct Array *arr,int x)
 {
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
 }

 void Insert(struct Array *arr,int index,int x)
 {
    if(index>=0 && index <=arr->length)
    {
        for(int i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
        }
 }

int main()
{
    struct Array arr1={{2,3,4,5,6},10,5};
    Append(&arr1,10);
    Insert(&arr1,0,12);
    Display(arr1);
    return 0;
}
```

## Deleting from Array

- Removing an element from an array is called deleting
- After deleting an element the space must not be empty in an array so shift the bits accordingly
- The index should not be beyond the array

Syntax : Delete( 3 )

```c++
x = A[ index ]
for( i = index ; i < length - 1 ; i++ )
{
A[ i ] = A[ i+1] ;
}  
```

Size = 10
Length = 8

```c++
#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

 void Display(struct Array arr)
 {
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
 }

int Delete(struct Array *arr,int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];}
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    struct Array arr1={{2,3,4,5,6},10,5};
    printf("%d",Delete(&arr1,0));
    Display(arr1);
    return 0;
}
```

## Linear Search

- They are 2 search method in an array
I. Linear search
II. Binary search
- Linear search :
Size = 10
Length = 10
Key = 5 (successful search)
Key = 12 (unsuccessful search)
- All the elements must be unique here
- The value you are searching is called key, In linear search we search
the key element one by one linearly
- We search the element by comparing it with the key value

A
0 1 2 3 4 5 6 7 8 9 </br>
8 3 7 12 6 3 10 5 14 2

- The result of the search is the location of the element where its present (index number) , it is very useful in accessing the element in the list
- If the element is not found throughout the list that means it is not present in the list therefore search is unsuccessful

Syntax :

```c
for( i = 0; i < length ; i++ )
{
    if( key == A[ i ] )
    return i; //if search is successful it ends here
}
return -1; // if search unsuccessful returns -1
```

## Improving Linear Search

- When you are searching for a key element there is a possibility that you are searching the same element again
- To improve the speed of comparison , you can move a key
element repeatedly search one step forward this method is called
transposition

Syntax :

```c++
for( i = 0; i < length ; i++ )
{
if( key == A[ i ] )
{
    swap( A[i], A[i-1]);
    return i-1;
 }
}
```

- The second method is you can directly swap the key element to
the first element this process is called move to head . The next
search for the same element becomes faster.

```c++
for( i = 0; i < length ; i++ )
{
    if( key == A[ i ] )
    {
        swap( A[i], A[0]);
        return 0;
    }
}
```

## Linear Search Code

```c
#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

 void Display(struct Array arr)
 {
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
 }

void swap(int *x,int *y)
 {
    int temp=*x;
    *x=*y;
    *y=temp;
 }

int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr1={{2,23,14,5,6,9,8,12},10,8};
    printf("%d",LinearSearch(&arr1,14));
    Display(arr1);
    return 0;
}
```

## Binary Search

- The condition for binary search is that the list of elements
must be sorted.
- The algorithm for binary search is as follows iterative procedure

```c
Algorithm BinSearch(l,h,key)
{
    while(l<=h)
    {
        mid = [(l+h)/2];
        if(key==A[mid])
            return mid;
        else if (key<A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return-1;
}
```

## Recursive procedure ( tail recursion )

```c
Algorithm RBinSearch(l,h,key)
{
    if(l<=h)
    {
        mid = [(l+h)/2];
        if(key==A[mid])
            return mid;
        else if (key<A[mid])
            return RBinSearch(l, mid-1, key);
        else
            return RBinSearch(mid+1, h, key);
    }
    return-1;
}
```

- Tail and loop recursive are similar
- If given option for both always go for loop recursive
as its better than it because it uses stack.

## Binary Search in Array

```c
#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

 void Display(struct Array arr)
 {
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
 }

 /*Swapping */
void swap(int *x,int *y)
 {
    int temp=*x;
    *x=*y;
    *y=temp;
 }

int BinarySearch(struct Array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

/* Recursion version */
int RBinSearch(int a[],int l,int h,int key)
{
 
    int mid=0;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
        return mid;
        else if(key<a[mid])
        return RBinSearch(a,l,mid-1,key);
    }
    else
        return RBinSearch(a,mid+1,h,key);

    return -1;
}

int main()
{
    struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
    printf("%d",BinarySearch(arr1,16));
    Display(arr1);
    return 0;
}
```

## Array Methods

### get()

```c
get(index)
if(index >=0 && index<Length)
    return A[index]
```

### set()

```c
set(index, x)
if(index >=0 && index<Length)
    A[index] = x
```

### max()

```c
// unsorted
max = a[o];
for( i=0;i<n;i++)
{
    if a[i] > max
    max=A[i]
}
```

### min()

```c
// unsorted
min = a[o];
for( i=0;i<n;i++)
{
    if a[i] < max
    min=A[i]
}
```

### sum()

```c
total = 0;
for(i=0;i<n;i++)
total = total + a[i];

//recursive

sum(a,n)
{
    if n < 0
    return 0;
    else
    return sum(a,n-1)+a[n]
}
sum(A,length-1) // calling
```

### AVG()

```c
total = 0;
for(i=0;i<n;i++)
    total = total + a[i];
    return total/n
```

### Reverse

```c
// 0(n)
a = [1,2,3]
b [3]
for i=len-1,j=0;i>=0;i--,j++
    b[j]=a[i]
for i=0;i<len;i++
    a[i]=b[j]

a = [1,2,3]
temp= 0
for j=len-1,i=0;i<j;j--,ii++
    temp=a[i]
    a[i]=a[j]
    a[j]=temp
```

### Left & Right shift & rotate

- use in advertizement in LED boards scrolling and rotating the data.

### Reversing an Array

```c
#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
    arr->A[i]=B[i];
}

void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int main(){

    struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
    Reverse(&arr1);
    Display(arr1);
    return 0;
}
```

### Checking if Array is Sorted

```c
#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements are\n");
    for(int i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
}

int isSorted(struct Array arr)
{
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}

int main() {
    struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
    printf("%d",isSorted(arr1));
    Display(arr1);
    return 0;
}
```

### -ve on left side

```c
int i=0,j=len-1
while(i<j)

while(A[i]<0){i++}
while(A[j]>=0){j++}
if(i<j)
swap(A[i],A[j])
```

## Merge

- Merge only can be used on sorted array and we need a third array to merge.
- some merge operations ( append, Concat, Compare, Copy)

### All up

```c
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr1){
    for(int i=0;i<arr1.length;i++){
        printf("%d \n",arr1.A[i]);
    }
}

void append(struct Array *arr1,int x){
    if(arr1->length<arr1->size){
        arr1->A[arr1->length++] = x;
    }
    
}

void insert(struct Array *arr1, int index, int x)
{
    if(index>=0 && index<arr1->length){
        for(int i=arr1->length;i>index;i--)
        {
            arr1->A[i]=arr1->A[i-1];
        }
        arr1->A[index] = x;
        arr1->length++;
    }
}

void Delete(struct Array *arr1, int index){
    int temp;
    temp = arr1->A[index];
    if(index>=0 && index<arr1->length){
    for(int i=index;i<arr1->length-1;i++)
    {
        arr1->A[i]=arr1->A[i+1];
    }
    arr1->length--;
    }    
}

int LinearSearch(struct Array arr1, int key)
{
    for(int i=0;i<arr1.length;i++)
    {
        if(arr1.A[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int Bsearch(struct Array arr1, int key)
{
    int l,h,mid;
    l=0;
    h=arr1.length;
    while(l<h)
    {
        mid = l+h/2;
        if(arr1.A[mid]==key) 
        return mid;
        else if(arr1.A[mid]>key)
        h=mid-1;
        else
        l=mid+1;
    }
    return -1;
}

int get(struct Array arr1, int index)
{
    return arr1.A[index];
    
}

void set(struct Array *arr1, int index, int x)
{
    if(index>=0 && index<arr1->length)
    {
        arr1->A[index]=x;
    }
}

int max(struct Array arr1){
    int max = arr1.A[0];
    for(int i=0;i<arr1.length;i++)
    {
        if(arr1.A[i]>max) 
        {
            max = arr1.A[i];
        }
    }
    return max;
}

int min(struct Array arr1){
    int max = arr1.A[0];
    for(int i=0;i<arr1.length;i++)
    {
        if(arr1.A[i]<max) 
        {
            max = arr1.A[i];
        }
    }
    return max;
}

int sum(struct Array arr1){
    int sum = 0;
    for(int i=0;i<arr1.length;i++)
    {
        sum = arr1.A[i] + sum;
    }
    return sum;
}

int avg(struct Array arr1){
    int avg = 0;
    avg = sum(arr1)/arr1.length;
    return avg;
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void reverse(struct Array *arr1){
    int *arr2;
    int i,j;
    
    arr2 = (int *)malloc(arr1->length * sizeof(int));
    
    for(i=arr1->length-1,j=0;i>=0;j++,i--)
    {
        arr2[j]=arr1->A[i];
    }
    for(i=0;i<arr1->length;i++)
    {
        arr1->A[i]=arr2[i];
    }
}

void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int isSorted(struct Array arr)
{
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}

struct Array* Merge(struct Array *arr1,struct Array *arr2)
{

    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct
    Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
    }
    else
        arr3->A[k++]=arr2->A[j++];

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}

// Union

struct Array* Union(struct Array *arr1,struct Array *arr2)
{

    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct
    Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=k;
    arr3->size=10;
    
    return arr3;
}

// Intersection

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct
    Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr1->A[i]>arr2->A[j])
            j++;
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

// Diff

struct Array* Diff(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct
    Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

int main()
{
    struct Array arr1={{2,9,21,28,35},10,5};
    // append(&arr1,36);
    // insert(&arr1, 0, 1);
    // Delete(&arr1,0);
    // printf("Index found at position: %d \n",LinearSearch(arr1,21));
    // printf("%d \n",Bsearch(arr1,1));
    // printf("%d \n",get(arr1,1));
    // set(&arr1,0,1);
    // printf("%d \n",max(arr1));
    // printf("%d \n",min(arr1));
    // printf("%d\n",sum(arr1));
    // printf("%d\n",avg(arr1));
    // struct Array arr2;
    reverse(&arr1);
    Display(arr1);
    
    return 0;
}
```

## Array C++ class

```c
#include <iostream>
using namespace std;

template<class T>
class Array
{
    private:
        T *A;
        int size;
        int length;
    public:
        Array()
        {
            size=10;
            A=new T[10];
            length=0;
        }
        Array(int sz)
        {
            size=sz;
            length=0;
            A = new T[size]
        }
        ~Array()
        {
            delete []A; 
        }
        void Display();
        void Insert(int index,T x);
        T Delete(int index);
};

template<class T>
void Array<T>::Display (){
    t i;
    printf("\nElements are\n");
    for(i=0;i<length;i++)
    printf("%d ",arr.A[i]);
}

template<class T>
T Array<T>::Delete(int index)
{
    T x=0;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(int i=index;i<length-1;i++){
        A[i]=[i+1];}
        length--;
    }
    return x;
}

template<class T>
 void Array<T>::Insert(int index,T x)
 {
    if(index>=0 && index <=length)
    {
        for(int i=length;i>index;i--)
            A[i]=A[i-1];
        A[index]=x;
        length++;
        }
 }


int main()
{

    Array<char> arr(10);
    arr.Insert(0,'a');
    arr.Insert(1,'c');
    arr.Insert(2,'d');
    arr.Display();
    cout<<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}

```
