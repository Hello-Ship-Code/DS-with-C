# Stack

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. In a stack, the most recently added element is the first one to be removed. It supports two primary operations:

- **Push:** Adds an element to the top of the stack.
- **Pop:** Removes the topmost element from the stack.

## **Applications:**

1. **Function Call Management:**
   - Manages function calls and local variables during recursive function execution.
   - Example: Call stack in programming languages.

2. **Expression Evaluation:**
   - Evaluates and converts expressions like infix to postfix or prefix.
   - Example: Expression parsers in compilers.

3. **Backtracking Algorithms:**
   - Supports algorithms that require exploring all possible options (e.g., depth-first search).
   - Example: Solving mazes, searching tree structures.

4. **Undo Mechanisms:**
   - Manages undo actions in text editors and software.
   - Example: Undo feature in text processing applications.

5. **Parenthesis Matching:**
   - Validates balanced parentheses in mathematical and programming expressions.
   - Example: Syntax checking in compilers and interpreters.

6. **Browser History Management:**
   - Maintains navigation history in web browsers, allowing the back and forward navigation.
   - Example: Back button functionality in web browsers.

7. **Memory Management:**
   - Manages memory allocation and de-allocation in runtime environments.
   - Example: Stack memory in process execution.

8. **Syntax Parsing:**
   - Assists in parsing and interpreting structured data or code.
   - Example: Parsing HTML or XML documents.

### Stack Abstract Data Type (ADT)

The **Stack Abstract Data Type (ADT)** is a conceptual framework that defines a stack's operations and expected behavior, without specifying how these operations are implemented. It focuses on a collection of elements managed through the **Last In, First Out (LIFO)** principle.

#### **Core Operations of Stack ADT**

1. **Push (add an element to the top):**
   - **Description:** Inserts an element at the top of the stack.
   - **Example:** `Push(5)` results in the stack `[5]` if it was initially empty.

2. **Pop (remove the top element):**
   - **Description:** Removes and returns the topmost element from the stack.
   - **Example:** `Pop()` on the stack `[5, 10]` results in `[5]` and returns `10`.

3. **Peek/Top (retrieve the top element):**
   - **Description:** Returns the top element without removing it from the stack.
   - **Example:** `Peek()` on the stack `[5, 10]` returns `10`.

4. **IsEmpty (check if the stack is empty):**
   - **Description:** Checks if the stack contains no elements.
   - **Example:** `IsEmpty()` on the stack `[]` returns `True`.

5. **Size (return the number of elements):**
   - **Description:** Returns the count of elements in the stack.
   - **Example:** `Size()` on the stack `[5, 10]` returns `2`.

The Stack ADT defines these operations to ensure a consistent and predictable interface for using stacks, regardless of their underlying implementation (e.g., arrays or linked lists).

## Implementing the Stacks using arrays

```cpp
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *S;
};

void create(struct stack *st)
{
    printf("Enter the size: ");
    scanf("%d",&st->size);

    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
}

void display(struct stack st)
{
   for(int i=st.top;i>=0;i--)
      printf("%d ",st.S[i]);
   printf("\n");
}

void push(struct stack *st, int x)
{
   if(st->top == st->size-1)
      printf("Stack Overflow\n");
   else
   {
      st->top++;
      st->S[st->top]=x;
   }
}

int pop(struct stack *st)
{
   int x=-1;
   if(st->top == -1)
      printf("Stack underflow\n");
   else
   {
      x = st->S[st->top--];
   }
   return x;
}

int peek(struct stack st, int index)
{
    int x=-1;
    if(st.top-index+1<0)
        printf("Invalid Index");
    x = st.S[st.top-index+1];
    
    return x;
    
}

int isEmpty(struct stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct stack st)
{
    return st.top == st.size-1;
}

int stacktop(struct stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
   struct stack st;
   create(&st);

   push(&st,10);
   push(&st,20);
   push(&st,30);
   push(&st,40);
   push(&st,50);
   
   printf("The stack is: %d \n",isEmpty(st));
   printf("Is the stack Full: %d \n",isFull(st));
   printf("top element of the stack: %d \n",stacktop(st));
   printf("the element at index is : %d \n",peek(st, 1));
   printf("The element deleted is : %d \n",pop(&st));

   display(st);

   return 0;
}
```

## Stack using Linked List

```cpp

#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*top = NULL;

void push(int x)
{
   struct Node *t;
   t=(struct Node*)malloc(sizeof(struct Node));
   
   if(t == NULL)
      printf("The stack is full\n");
   else{
      t->data = x;
      t->next = top;
      top = t;
   }
}

int pop()
{
   struct Node *t;
   int x=-1;

   if(top == NULL)
      printf("The stack is Empty\n");
   else{
      t = top;
      top = top->next;
      x = t->data;
      free(t);
   }
   return x;
}

void display()
{
   struct Node *p;
   p = top;
   while( p != NULL )
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("\n");
}

int main()
{
   push(10);
   push(20);
   push(30);
   push(40);

   display();
   
   printf("%d ",pop());
   
   return 0;
}
```

## stack using Linked list with C++

```cpp
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Node{
   public:
      int data;
      Node *next;
};

class stack{
   private:
      Node *top;
   public:
      stack(){top=NULL;}     
      // Stack() : top(nullptr) {} can also implement like this

   // free stack if its empty
    ~stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

      void push(int x);
      int pop();
      void display();
};

void stack::push(int x)
{
   Node * t = new Node(x);

   if( t == NULL)
      std::cout << "The stack is full \n";
   else
   {
      t->next = top;
      top = t;
   }
}

int stack::pop()
{
   int x=-1;
   if(top == NULL)
      std::cout<<"stack is empty"<<endl;
   else{
      Node *t = top;
      top = top->next;
      x = t->data;
      delete(t);
   }
   return x;
}

void stack::display()
{
   Node *p = top;
   while(p != NULL )
   {
      std::cout<<p->data<<" ";
      p=p->next;
   }
   cout<<endl;
}

int main()
{
   stack s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);

   s.display();

   std::cout << s.pop() << std::endl;

   return 0;
}

## paranthesis matching

### Definition of Parenthesis Matching Using Stack

**Parenthesis matching** (or **parentheses balancing**) is a problem of checking if the parentheses (and other types of brackets) in a given expression are correctly balanced and nested. A stack is a common data structure used to solve this problem efficiently. 

**Definition:**

**Parenthesis Matching Using Stack** is a method for verifying if every opening parenthesis (or other bracket) in an expression has a corresponding closing parenthesis in the correct order and properly nested. The algorithm involves pushing each opening parenthesis onto a stack and popping from the stack when a closing parenthesis is encountered. If at the end of the expression the stack is empty and no unmatched parenthesis is found, the expression is considered balanced.

### Algorithm

1. **Initialize an empty stack**.
2. **Traverse the expression** from left to right.
3. **For each character** in the expression:
   - **If the character is an opening parenthesis** (e.g., `(`, `{`, or `[`):
     - **Push it onto the stack**.
   - **If the character is a closing parenthesis** (e.g., `)`, `}`, or `]`):
     - **Check if the stack is empty**:
       - **If it is empty**, the expression is unbalanced (return false).
       - **Otherwise**, pop the top of the stack and check if the popped parenthesis matches the closing parenthesis.
       - If they do not match, the expression is unbalanced (return false).
4. **After processing all characters**, check if the stack is empty:
   - If it is not empty, the expression is unbalanced (return false).
   - If it is empty, the expression is balanced (return true).

### Example

Given the expression `"(a + b) * [c / d]"`:

1. Traverse the expression.
2. When encountering `(` and `[`, push them onto the stack.
3. When encountering `)` and `]`, pop from the stack and check for matching opening parentheses.

Here a step-by-step representation:

- Expression: `"(a + b) * [c / d]"`
- Stack after encountering `(`: `[(]`
- Stack after encountering `[`: `[(, []`
- Encounter `)` and pop `(` from the stack: `[]`
- Encounter `]` and pop `[` from the stack: `[]`
- Stack is empty after traversal: expression is balanced.
