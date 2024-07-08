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
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
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
```

## paranthesis matching

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

```cpp
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    char data;
    struct Node* next;
} *top = NULL;

// Push a character onto the stack
void push(char x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("The stack is full\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Pop a character from the stack
char pop() {
    struct Node* t;
    char x = -1;
    if (top == NULL)
        printf("The stack is Empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// Display the stack (for debugging purposes)
void display() {
    struct Node* p = top;
    while (p != NULL) {
        printf("%c ", p->data); // Changed %d to %c to print characters
        p = p->next;
    }
    printf("\n");
}

// Check if the expression has balanced parentheses
int isbalanced(const char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == NULL)
                return 0; // Return 0 for unbalanced

            char topChar = pop();
            if ((exp[i] == ')' && topChar != '(') ||
                (exp[i] == '}' && topChar != '{') ||
                (exp[i] == ']' && topChar != '['))
                return 0; // Return 0 for unbalanced
        }
    }
    return top == NULL; // Return 1 for balanced, 0 for unbalanced
}

// Main function
int main() {
    const char* exp = "((a+b)*(b+c))"; // Use const char* for string literals
    printf("Is the expression balanced? %s\n", isbalanced(exp) ? "Yes" : "No");
    return 0;
}

```

### Infix, Prefix, and Postfix Notation

These notations describe different ways of writing arithmetic expressions, primarily differing in the placement of operators and operands.

#### **1. Infix Notation**

**Definition**:

- Operators are written **between** operands. This is the most familiar form of arithmetic notation.

**Example**:

- `(A + B) * (C - D)`

**Why It's Used**:

- **Human Readability**: Closely resembles the conventional arithmetic taught in schools.
- **Natural Parenthesis Handling**: Parentheses and operator precedence rules determine the order of operations.

**Precedence**:

- Parentheses dictate operations within them to be performed first.
- Operator precedence and associativity rules determine the order without parentheses.

**Manual Conversion to Prefix and Postfix**:

- Convert using structured algorithms like the Shunting Yard Algorithm for postfix and a stack-based approach for prefix.

#### **2. Prefix Notation (Polish Notation)**

**Definition**:

- Operators are written **before** their operands.

**Example**:

- `* + A B - C D` (equivalent to `(A + B) * (C - D)` in infix)

**Why It's Used**:

- **Simplifies Parsing**: No need for parentheses or precedence rules during evaluation.
- **Direct Evaluation**: Suitable for certain computational processes and applications, like function composition in Lisp.

**Precedence**:

- Not needed, as the order of operations is explicit based on the position of operators.

**Manual Conversion from Infix**:

- **Steps**:
  - Traverse the infix expression from right to left.
  - Use a stack to reverse the order of operators and operands.
  - Ensure operators precede operands by carefully placing them in the output as encountered.

#### **3. Postfix Notation (Reverse Polish Notation, RPN)**

**Definition**:

- Operators are written **after** their operands.

**Example**:

- `AB+CD-*` (equivalent to `(A + B) * (C - D)` in infix)

**Why It's Used**:

- **Simplifies Evaluation**: No need for parentheses or precedence rules.
- **Efficient Execution**: Especially useful for stack-based evaluations and computer parsing.

**Precedence**:

- Not needed, as the order of operations is explicit based on the sequence of operators and operands.

**Manual Conversion from Infix**:

- **Steps**:
  - Traverse the infix expression from left to right.
  - Use a stack to temporarily hold operators until they can be added to the output after operands.
  - Pop operators from the stack to the output based on precedence and associativity.

### **Summary**

- **Infix Notation**:
  - **Order**: `Operand Operator Operand`
  - **Usage**: Commonly used in human-readable arithmetic.
  - **Handling**: Requires parentheses and precedence rules.

- **Prefix Notation**:
  - **Order**: `Operator Operand Operand`
  - **Usage**: Simplifies parsing and function composition.
  - **Handling**: Eliminates the need for parentheses and precedence rules.

- **Postfix Notation**:
  - **Order**: `Operand Operand Operator`
  - **Usage**: Ideal for stack-based evaluation and expression parsing.
  - **Handling**: Direct evaluation without precedence or parentheses.

### **Detailed Conversion Process**

**Infix to Prefix**:

1. **Reverse** the infix expression.
2. **Change** `(` to `)` and vice versa.
3. **Apply** infix-to-postfix conversion on the modified expression.
4. **Reverse** the postfix expression to get the prefix expression.

**Infix to Postfix**:

1. **Initialize** an empty stack and output list.
2. **Scan** the infix expression from left to right.
3. **Operands**: Add directly to the output.
4. **Operators**: Push to stack. Pop from stack to output if the stack's top has higher or equal precedence.
5. **Parentheses**:
   - **Left Parenthesis**: Push to stack.
   - **Right Parenthesis**: Pop and output until a left parenthesis is encountered.

**Example Conversion**:

- **Infix**: `A + B * (C - D)`
- **Prefix**: `+ A * B - C D`
  - **Step-by-Step**:
    - Reverse infix: `) D - C ( * B + A`
    - Swap parentheses: `( D - C ) * B + A`
    - Convert to postfix: `D C - B * A +`
    - Reverse to get prefix: `+ A * B - C D`

- **Postfix**: `A B C D - * +`
  - **Step-by-Step**:
    - Read and apply operators to operands.
    - `B C -`: Subtract `C` from `B`.
    - `A + B * (result)`: Multiply the result by `B`, then add `A`.

These notations provide different ways to write expressions that can simplify parsing and evaluation for both humans and computers, each suited for specific applications and contexts.

### BODMAS Rule

**Definition**: The BODMAS rule is a mathematical principle that outlines the order of operations to evaluate an arithmetic expression correctly. The acronym stands for:

- **B**: Brackets
- **O**: Orders (i.e., powers and roots, etc.)
- **D**: Division
- **M**: Multiplication
- **A**: Addition
- **S**: Subtraction

**Alternative Acronyms**:

- **PEMDAS** (Parentheses, Exponents, Multiplication, Division, Addition, Subtraction) is commonly used in the United States.
- **BIDMAS** (Brackets, Indices, Division, Multiplication, Addition, Subtraction) is another variation.

### Details

**1. Brackets (B)**:

- Evaluate expressions within brackets first. This includes parentheses `()`, square brackets `[]`, and curly braces `{}`.
- **Example**: In the expression `3 * (2 + 4)`, the sum inside the brackets `()` is computed first to get `3 * 6`.

**2. Orders (O)**:

- Evaluate powers (exponents) and roots (square roots, cube roots, etc.) next.
- **Example**: In the expression `2^3 * 4`, compute the exponentiation `2^3 = 8` first to get `8 * 4`.

**3. Division and Multiplication (DM)**:

- Perform division and multiplication from left to right. These operations are of equal precedence.
- **Example**: In the expression `6 / 3 * 2`, perform the division first `6 / 3 = 2`, then multiply by `2` to get `4`.

**4. Addition and Subtraction (AS)**:

- Perform addition and subtraction from left to right. These operations are of equal precedence.
- **Example**: In the expression `7 - 3 + 2`, perform the subtraction first `7 - 3 = 4`, then add `2` to get `6`.

### Importance of BODMAS Rule

- **Consistent Results**: Ensures that mathematical expressions are evaluated consistently and correctly.
- **Avoids Ambiguity**: Eliminates ambiguity in arithmetic operations by providing a clear order of operations.
- **Standardized**: Provides a standardized method for solving mathematical problems, widely accepted and taught in educational systems.

### **Examples**

1. **Expression**: `2 + 3 * 4`
   - **Using BODMAS**:
     - Multiply first: `3 * 4 = 12`
     - Add: `2 + 12 = 14`
   - **Result**: `14`

2. **Expression**: `(8 - 3) + 4^2`
   - **Using BODMAS**:
     - Brackets first: `(8 - 3) = 5`
     - Exponentiation: `4^2 = 16`
     - Add: `5 + 16 = 21`
   - **Result**: `21`

3. **Expression**: `18 / (3 * 3) - 2`
   - **Using BODMAS**:
     - Brackets first: `3 * 3 = 9`
     - Division: `18 / 9 = 2`
     - Subtract: `2 - 2 = 0`
   - **Result**: `0`

4. **Expression**: `5 + 2 * (12 / 4) - 3`
   - **Using BODMAS**:
     - Brackets first: `12 / 4 = 3`
     - Multiply: `2 * 3 = 6`
     - Add: `5 + 6 = 11`
     - Subtract: `11 - 3 = 8`
   - **Result**: `8`

### **Handling Different Types of Brackets**

- **Parentheses `( )`**: Used to group parts of an expression.
  - **Example**: `(2 + 3) * 4` computes `2 + 3` first, then multiplies by `4`.

- **Square Brackets `[ ]`**: Used in nested expressions.
  - **Example**: `[3 * (4 + 5)]` computes `4 + 5` first, then multiplies by `3`.

- **Curly Braces `{ }`**: Used for further nesting.
  - **Example**: `{[2 + 3] * (4 + 1)}` computes `2 + 3` and `4 + 1` first, then multiplies the results.

### **In Summary**

- **B**: Brackets, handle expressions inside them first.
- **O**: Orders, evaluate exponents and roots next.
- **DM**: Division and Multiplication, from left to right.
- **AS**: Addition and Subtraction, from left to right.

The BODMAS rule provides a clear sequence to follow for solving mathematical expressions, ensuring accuracy and consistency in arithmetic operations.

## Infix to postfix using stack linked list

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the Node structure
struct Node {
    char data; // Data part of the node, holding a character
    struct Node* next; // Pointer to the next node in the stack
} *top = NULL; // Global pointer to the top of the stack, initialized to NULL

// Push a character onto the stack
void push(char x) {
    // Allocate memory for a new node
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL) // Check if memory allocation failed
        printf("The stack is full\n");
    else {
        // Set the data and link the new node to the current top
        t->data = x;
        t->next = top;
        // Update the top to point to the new node
        top = t;
    }
}

// Pop a character from the stack
char pop() {
    struct Node* t; // Temporary pointer to hold the node being popped
    char x = -1; // Default return value in case of an empty stack
    if (top == NULL)
        printf("The stack is empty\n");
    else {
        // Update the top to the next node
        t = top;
        top = top->next;
        // Retrieve the data from the popped node
        x = t->data;
        // Free the memory of the popped node
        free(t);
    }
    return x; // Return the popped data
}

// Check if the stack is empty
int isEmpty() {
    return top == NULL; // Returns 1 if the stack is empty, 0 otherwise
}

// Peek at the top of the stack
char peek() {
    return top ? top->data : '\0'; // Return the data of the top node, or '\0' if empty
}

// Display the stack (for debugging purposes)
void display() {
    struct Node* p = top; // Pointer to traverse the stack
    while (p != NULL) {
        // Print the data of each node
        printf("%c ", p->data); // Changed %d to %c to print characters
        p = p->next; // Move to the next node
    }
    printf("\n"); // Newline after displaying the stack
}

// Determine precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1; // Lowest precedence
        case '*':
        case '/':
            return 2; // Higher precedence
        case '^':
            return 3; // Highest precedence
    }
    return 0; // Return 0 for non-operators
}

// Check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    // Return 1 if c is an operator, 0 otherwise
}

// Convert infix to postfix
char* InToPost(const char* infix) {
    int len = strlen(infix); // Length of the infix expression
    // Allocate memory for the postfix expression
    char* postfix = (char*)malloc((len + 2) * sizeof(char));
    if (!postfix) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }

    int i = 0, j = 0; // Indices for traversing infix and building postfix
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) { // If the character is alphanumeric
            postfix[j++] = infix[i++]; // Add it to the postfix expression
        } else if (infix[i] == '(') {
            push(infix[i++]); // Push '(' onto the stack
        } else if (infix[i] == ')') {
            // Pop and add to postfix until '(' is encountered
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop(); // Remove the '(' from the stack
            }
            i++; // Move past the ')'
        } else if (isOperator(infix[i])) {
            // Pop and add to postfix based on precedence
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]); // Push the operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
    return postfix; // Return the postfix expression
}

// Main function
int main() {
    const char* exp = "a+b*c"; // Example infix expression, use const char* for string literals

    char* postfix = InToPost(exp); // Convert infix to postfix

    printf("Postfix expression: %s\n", postfix); // Print the postfix expression

    free(postfix); // Free the allocated memory for postfix

    return 0; // Return 0 to indicate successful execution
}
```

## Evaluating a postfix expression

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the Node structure for stack operations
struct Node {
    char data; // For the conversion stack
    int value; // For the evaluation stack
    struct Node* next;
} *top = NULL; // Stack pointer

// Push a character onto the stack (for infix to postfix conversion)
void push(char x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("The stack is full\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Push an integer onto the stack (for postfix evaluation)
void pushValue(int val) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("The stack is full\n");
    else {
        t->value = val;
        t->next = top;
        top = t;
    }
}

// Pop a character from the stack (for infix to postfix conversion)
char pop() {
    struct Node* t;
    char x = -1;
    if (top == NULL)
        printf("The stack is empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// Pop an integer from the stack (for postfix evaluation)
int popValue() {
    struct Node* t;
    int val = -1;
    if (top == NULL)
        printf("The stack is empty\n");
    else {
        t = top;
        top = top->next;
        val = t->value;
        free(t);
    }
    return val;
}

// Check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Peek at the top of the stack (for infix to postfix conversion)
char peek() {
    return top ? top->data : '\0';
}

// Display the stack (for debugging purposes)
void display() {
    struct Node* p = top;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Determine precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix
char* InToPost(const char* infix) {
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 2) * sizeof(char));
    if (!postfix) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop();
            }
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

// Evaluate a postfix expression
int evaluatePostfix(const char* postfix) {
    int i = 0;
    int val1, val2, result;

    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            // For simplicity, we'll assume operands are single-digit numbers
            pushValue(postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            // Pop the top two values from the stack
            val2 = popValue();
            val1 = popValue();

            // Perform the operation
            switch (postfix[i]) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < val2; j++) {
                        result *= val1;
                    }
                    break;
            }

            // Push the result back onto the stack
            pushValue(result);
        }
        i++;
    }

    // The result of the expression will be the top value of the stack
    return popValue();
}

// Main function
int main() {
    const char* exp = "3+5*2"; // Example infix expression

    char* postfix = InToPost(exp); // Convert infix to postfix

    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix); // Evaluate the postfix expression

    printf("Result of postfix evaluation: %d\n", result);

    free(postfix); // Free the allocated memory

    return 0;
}

```
