# Basics in C & C++

## Arrays

An array is a collection of similar data elements stored at contiguous memory locations. It is the simplest data structure where each data element can be accessed directly by only using its index number.

For instance, if we want to store the marks scored by a student in 5 subjects, then there’s no need to define individual variables for each subject. Rather, we can define an array that will store the data elements at contiguous memory locations.

Array marks[5] define the marks scored by a student in 5 different subjects where each subject’s marks are located at a particular location in the array, i.e., marks[0] denote the marks scored in the first subject, marks[1] denotes the marks scored in 2nd subject and so on.

```c++
int a[5]; /* Initializing the array*/ 
int b[5] = {2,3,4,5,6}; /*Declaration of array*/
```

When ever we initialize the array its going to store in main memory.

![memory](../Images/memory_array.png)

## Why we need to deallocate the memory?

Deallocating memory is crucial for several reasons, particularly in C++ and other languages where memory management is manual. Here's why deallocating memory is important:

### 1. Prevent Memory Leaks

**Memory Leaks**: When dynamically allocated memory is not properly deallocated, it remains allocated even when it is no longer needed. This leads to memory leaks, where the application consumes more and more memory over time, potentially exhausting system resources and causing the application to crash or slow down significantly.

### 2. Efficient Use of Resources

**Resource Management**: Efficiently managing memory resources is essential for the performance and stability of an application. Deallocating memory when it is no longer needed ensures that the memory can be reused for other parts of the application or by other applications running on the system.

### 3. Avoiding Undefined Behavior

**Memory Corruption**: Failing to deallocate memory can also lead to undefined behavior if the program inadvertently writes to memory that it thinks is still valid. This can corrupt data, cause crashes, and lead to difficult-to-debug issues.

### 4. Compliance with RAII (Resource Acquisition Is Initialization) Principle

**RAII**: This is a common idiom in C++ programming. It ensures that resources are properly released when they are no longer needed. By following RAII, you create robust and exception-safe code. Using destructors to deallocate memory is a key part of this principle.

## We need to manually deallocate the memory in C/C++. In Java, Python, Go, C# no need for manual deallocation. In Rust memory is automatically deallocated when the variable goes out of scope

## Out of scope example

```c
#include <iostream>

void exampleFunction() {
    int localVariable = 10; // localVariable is in scope
    std::cout << "Inside function: " << localVariable << std::endl;
} // localVariable goes out of scope here

int main() {
    exampleFunction();
    // localVariable is not accessible here, it's out of scope
    return 0;
}
```

### Practical Example with Destructor

To illustrate the importance of deallocating memory, consider a simple example with a class that dynamically allocates memory:

```cpp
#include <iostream>

class Rectangle {
private:
    int* length;
    int* breadth;

public:
    // Constructor
    Rectangle(int l, int b) {
        length = new int;  // Allocate memory for length
        breadth = new int; // Allocate memory for breadth
        *length = l;
        *breadth = b;
    }

    // Destructor
    ~Rectangle() {
        delete length;  // Deallocate memory for length
        delete breadth; // Deallocate memory for breadth
        std::cout << "Destructor called, memory deallocated" << std::endl;
    }

    // Function to calculate the area
    int area() const {
        return (*length) * (*breadth);
    }

    // Function to display the dimensions
    void display() const {
        std::cout << "Length: " << *length << ", Breadth: " << *breadth << std::endl;
    }
};

int main() {
    Rectangle* rect = new Rectangle(10, 5);

    rect->display();
    std::cout << "Area of the rectangle: " << rect->area() << std::endl;

    delete rect; // Manually deleting the object to invoke the destructor and deallocate memory

    return 0;
}
```

### Explanation

1. **Constructor**: Allocates memory for `length` and `breadth` dynamically.
2. **Destructor**: Deallocates the memory to prevent memory leaks.
3. **Creating and Deleting Object**: In `main`, the `Rectangle` object is created using `new`, and manually deleted using `delete`. This ensures that the destructor is called, which deallocates the memory.

### Summary

Deallocating memory in C++ is a critical part of managing resources efficiently. It prevents memory leaks, ensures that resources are available for other uses, and maintains the stability and performance of the application. The use of destructors to handle deallocation is a standard practice that aligns with the RAII principle, making your code more robust and maintainable.

## Structures

Structures (also called struct) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure.
Unlike an array, a structure can contain many different data types (int, float, char, etc.).

- Collection of data members under one name is structure
- Data members can be of similar type or non similar type
- When structures is called in the main( ) program then it will consume space accordingly to the data members types it contains in the memory.
- An example of structure is a program of a rectangle

```c++
Struct Rectangle
{
int length;
int breath;
}

int main()
{
struct Rectangle r ;            - Declaration
Struct Rectangle r = { 10, 5 }; - Declaration + Initialization
r.length = 15 ;                 - ( . operator ) Is is used to access a members to modify
r.breath = 10 ;
Printf( “ Area of rectangle is %d” , r.length * r.breath ) ; - Accessing the members
}
```

## Use of structure

 Structures is used to combine data under one name, thus some example usage of structures is:

- In Complex numbers
- In student details
- In Employee Details
- Bank Details etc
- Defining Shapes etc…

In the example, We get the size of the struct as 12 instead of 9 as integers take 4 bytes each and char takes 1 byte. But instead, the compiler takes 4 bytes as it's easy for the compiler to read but fur char it assigns only 1 byte from the four. This is called padding as it takes more bytes other than what is required.

## Pointers

- Pointer is an address variable that is meant for storing an address, not data itself.
- They are used for indirect access to data.
- For a program to use heap memory, pointers are used.
- To access heap memory and resources outside the main memory like the internet, keyboard, monitor, etc pointers is used. Pointers are also used for parameter passing.

Example :

```c++
int main( )
{
Int a = 10 ;             - data variable
Int *p ;                 - declaration
P = & a ;                - Assignment / Initialization
printf( “% d ” , a ) ;    
printf(“ %d ” , * p ) ;  - dereferencing
}
```

- Accessing Heap memory through pointer

```c++
#include<stdio.h>
int main( )
{
Int * p;
// p = (int*)malloc(5*sizeof(int)); in c
P = new int[5]; // in C++
}
```

## Memory

When a program is assigned the memory its basically divided into three parts

- code section
- stack memory
- heap memory

The program will have access to stack & code section but won't have access to the heap memory. To access the heap memory we use pointer.

### uses of pointer

- Accessing Heap memory
- Accessing resources
- parameter passing

## de·ref·er·ence

Obtain from (a pointer) the address of a data item held in another location.

```c++
#include<stdio.h>

int main()
{
    int a=10;
    int p=*a;        - Declaration
    p=&a;            - initialization
    print("%d",a);
    printf("%d",*p); - Dereference
}
```

## Accessing Heap memory

```c
#include<stdlib.h>

int main()
{
    int *p;
    p=(int *) malloc(5 * sizeof(int)); - Accessing Heap memory in C.
   //p = new int[5]; - in cpp
}
```

- Here 5 is the number of integers into the size of integers. The compiler will allocate 5 integer with each having sizeof(int).

## Reference

- A reference is a just another name for the same the variable
- Reference are only available in C++

## Example

```c++
#include<stdio.h>

int main( )
{
Int a = 10;
Int &r = a; - syntax of reference
Count << a ;
r++;
cout<< r ;
cout << a ;
int b = 30
r=b;
cout<<a<<endl<<r<<endl; // 30, 30
}
```

- This is use for parameter passing
- For writing small functions we use reference

## Pointer to a Structure

### Syntax - 1

- When variable is already existing , then we can use pointer to structure like

```c++
#include<stdio.h>

struct Rectangle
{
int length;
int breath;
};

int main( )
{

Rectangle r = { 10, 5 }; // can write without struct in cpp
struct Rectangle *p= &r;

r.length = 15 ;  
printf("%d\n",r.length);

(*p).length = 20;  /* This one way of declaring pointer to struct */
printf("%d\n",(*p).length); 

p->length = 25;  /* This another way of declaring pointer to struct */
printf("%d\n",p->length); 

}
```

### Syntax - 2

- Dynamically object created in heap and pointer pointing there

```c++
#include<stdio.h>
#include<stdlib.h>

struct Rectangle
{
int length;
int breath;
};

int main( )
{
struct Rectangle *p;
p=(struct Rectangle * )malloc(sizeof(struct Rectangle)); // in C
//p = new Rectangle in c++
p->length = 10 ;
p->breath = 5;

printf("The length %d & the breadth: %d",p->length,p->breath);
}
```

## Functions

- Function is a piece of code which performs a specific task
- Grouping instructions is called function
- They are called as modules or procedures
- The main task can be divided into several small task in the form of functions this type of programming is also called as modular or procedural programming
- It is easy for development
- A group of programmers can work on a single project using functioning
- Functions provide reusability of code
- It can be used in other software projects as well
- you can group function into library

Example :

```c++
#include<stdio.h>

int add( int a , int b ) /* Actual parameters */
{
int c;
c = a + b;
return c;
}

int main ( )
{
int x,y,z;
x =10;
y = 5;
z = add (x,y); /* Formal parameters */
printf("The sum of two number is: %d",z);
}
```

## Parameter Passing Methods

### Pass/call by value

- In pass by value actual parameters will not be modified if any changes are done to the formal parameters
Example :

```c++
#include<stdio.h>

void swap(int x , int y)
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
 printf("%d %d", a ,b);
}
```

### Call by address

- Here the address of actual parameters are passed to formal parameter and formal parameters must be pointers
- Any changes done inside function will modify the actual parameters

```c++
#include<stdio.h>

void swap(int *x , int *y)
{
 int temp;
 temp = *x;
 *x = *y;
 *y = temp;
}

int main()
{
 int a,b;
 a =10;
 b=20;
 swap(&a,&b);
 printf("%d %d", a,b);
} // 20, 10
```

- One function cannot access value of another function directly but it can access it indirectly through pointers
- Thus call by address is a suitable mechanism for modifying actual parameters

### Call by reference

- References are part of c++ programming, its one of the useful and powerful mechanism of this language
- To make a function as call by reference we just need to add & in the parameters, these are the references

```c++
#include<stdio.h>

void swap(int & x , int & y)
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
 swap(a ,b);
 printf("%d %d", a ,b);
}
```

## Arrays as Parameters

- The following function is taking parameter as an array, `int A[ ]` the declared array must be empty and its size must be provides as follows `int n`.
- The reason for array in parameter being empty is because it acts as a pointer.
- Arrays cannot be passed as values , arrays can only be passed by address.
- As its call by address its possible to change the values of the arrays.

```c++
#include<stdio.h>
void fun(int A[ ] , int n) /* int *A its a general method which is pointer to int it may array also. */
{
 int i;
 for(i=0; i<n ; i++)
 printf("%d", A[i]);
}

int main()
{
 int A[5] = {2,4,6,8,10};
 fun(A,5);
}
```

## Structure as Parameter

- If we are sending structure as a parameter to a structure it may be call by value or call by address call by value

 Example

```c++
#include<stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle r1)
{
 return r1.length*r1.breadth;
}

int main()
{
 struct Rectangle r = {10,5};
 printf("% d", area(r));
}
```

- A separate object will be created in call by value method and everything will be copied in the corresponding members this is one of the befit of structure as parameter
- If you are making changes to formal parameter it will not effect the actual parameter.

## call by reference

Example:

```c++
#include<stdio.h>
#include<iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle &r1) /* Error here check this program */
{
 return r1.length*r1.breadth;
}

int main()
{
 struct Rectangle r = {10,5};
 printf("%d", area(r));

 return 0;
}
```

- The only change we need to do for call by reference is adding `&` in the parameter.
- Here the new object is not created but the same object is called r1 also.
- Thus new changes in the values will effect the actual parameters.

## call by address

Example:

```c++
#include<stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

void changeLength(struct Rectangle *p , int l)
{
 p->length = l;
 printf("%d",p->length);
}

int main()
{
 struct Rectangle r = {10,5};
  printf("length before: %d\n",r.length);
 changeLength(&r, 20);
}
```

- If you want some function to change the actual parameter then it must be done by call by address or call by reference.
- It is possible to send array as a parameter in pass by value only if its inside the structure , if its just array passing then its not possible by pass by value.

## Structure & Functions in C

```c++
#include<stdio.h>

struct Rectangle
{
    int length;
    int breadth;
}; // Intializing the structure

void initialize(struct Rectangle *r,int l,int b)
{
    r->length = l;
    r->breadth = b;
}

int area( struct Rectangle r)
{
    return r.length*r.breadth;
}

void changelength(struct Rectangle *r, int l)
{
    r->length = l;
    printf("The length has modified to: %d",r->length);
}

int main()
{
    struct Rectangle r;
    initialize(&r,10,5);
    printf("The area of a rectangle: %d\n",area(r));
    changelength(&r,20);
}
```

## Object Oriented Programming using struct

```c++
#include<stdio.h>
#include<iostream>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;

void initialize( int l, int b)
{
    length=l;
    breadth=b;
}

int area ()
{
    return length*breadth;
}

int perimeter()
{
    int p;
    p = 2 * ( length + breadth );

    return p;
}
};
int main()
{
    Rectangle r={0,0};
    int l,b;
    printf("Enter the length & breadth\n");
    cin>>l>>b;
    /* cin>>r.length>>r.breadth; Can also initialize like this or create a function for initialization*/

    r.initialize(l,b);

    int a=r.area();
    int peri= r.perimeter();
    printf("The area of rectangle is: %d & the perimeter of the rectangle is:%d",a,peri);

    return 0;
}
```

- How to convert the above oops struct to complete oops
- We just need to add class in place of struct
- But when we do so we can't access the functions as the elements & functions declared inside class are private. To over come this we need to add public in front of the functions from where we want the functions to be public

Example:

```c++
#include<stdio.h>
#include<iostream>
using namespace std;

class Rectangle 
{
    int length;
    int breadth;
public:
void initialize( int l, int b)
{
    length=l;
    breadth=b;
}

int area ()
{
    return length*breadth;
}

int perimeter()
{
    int p;
    p = 2 * ( length + breadth );

    return p;
}
};
int main()
{
    Rectangle r;
    int l,b;
    printf("Enter the length & breadth\n");
    cin>>l>>b;
    /* cin>>r.length>>r.breadth; Can also initialize like this or create a function for initialization*/
    r.initialize(l,b);

    int a=r.area();
    int peri= r.perimeter();
    printf("The area of rectangle is: %d & the perimeter of the rectangle is:%d",a,peri);

    return 0;
}
```

## class & constructor

```c++
#include<stdio.h>
#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;
    
    public:
        Rectangle()
        {
            length=breadth=1;
        }
        Rectangle(int l,int b)
        {
            length=l;
            breadth=b;
        }
        int area()
        {
            return length*breadth;
        }
        int perimeter()
        {
            return 2 * ( length + breadth );
        }
        int setLength(int l)
        {
           return length=l;
        }
        int setBreadth(int b)
        {
            return breadth=b;
        }
        int getLength()
        {
            return length;
        }
        int getBreadth()
        {
            return breadth;
        }
        ~Rectangle()
        {
            cout<<"Destructor";
        }
};


int main()
{
    Rectangle r{10,5};

    cout<<"Area: "<<r.area()<<endl;
    cout<<"perimeter: "<<r.perimeter()<<endl;
    cout<<"Length: "<<r.getLength()<<endl;
    cout<<"breadth: "<<r.getBreadth()<<endl;
     cout<<"the length is modified: "<<r.setLength(20)<<endl;
    cout<<"The breadth is modified: "<<r.setBreadth(30)<<endl;

    return 0;
}
```

mutated function -> set length & breadth;
accessor function -> get length & breadth;

## Templates class

A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter

C++ adds two new keywords to support templates: ‘template’ and ‘type name’. The second keyword can always be replaced by the keyword ‘class’

```c++
#include <iostream>
using namespace std;
 
// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
 
int main()
{
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
    // call myMax for char
    cout << myMax<char>('g', 'e') << endl;
 
    return 0;
}
```
