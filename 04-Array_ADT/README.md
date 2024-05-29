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
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }

 void Append(struct Array *arr,int x)
 {
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
 }

 void Insert(struct Array *arr,int index,int x)
 {
 int i;

 if(index>=0 && index <=arr->length)
 {
    for(i=arr->length;i>index;i--)
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
- After deleting an element the space must not be empty in an
array so shift the bits accordingly
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
 for(i=index;i<arr->length-1;i++)
 arr->A[i]=arr->A[i+1];
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
must be sorted. (check out PDF)[]

## Binary Search Algorithm

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

## Recursive procedure

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
