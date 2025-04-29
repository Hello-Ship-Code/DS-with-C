# Sparse Matrix & Polynomial Representation

A **sparse matrix** is a matrix in which the majority of the elements are zero. Sparse matrices are common in scientific and engineering applications, such as in large-scale simulations, network theory, and machine learning. They arise naturally in situations where relationships or interactions between entities are infrequent, leading to mostly empty or zero entries in the matrix representation.

## Characteristics of Sparse Matrices

1. **High Proportion of Zeros**: A sparse matrix has significantly more zero elements than non-zero elements.
2. **Large Dimensions**: Sparse matrices are often very large, which makes storing and computing with them using traditional dense matrix methods inefficient.

### Examples

- **Graph Adjacency Matrix**: In a social network graph where each node represents a person and each edge represents a friendship, the adjacency matrix will be sparse if most people are not directly friends with most others.
- **Document-Term Matrix**: In text mining, a document-term matrix, where each row represents a document and each column represents a term, is usually sparse because most documents use a small subset of the total vocabulary.

### Storage Methods for Sparse Matrices

Storing sparse matrices efficiently is crucial to save space and computational resources. Common storage formats include:

## Compressed Sparse Row (CSR) Format

- **Data**: Stores the non-zero values.
- **Indices**: Stores the column indices of the elements in the data array.
- **Index Pointer**: Stores the index in the data array where each row starts.
- Here we consider three array as mentioned above,

1. To store the data.
2. To store the column number.
3. To store the number of elements in the current

| 0 0 3 0 4 |  
| 0 0 5 7 0 |  
| 0 0 0 0 0 |  
| 0 2 6 0 0 |  

### Data Array

`data = [3, 4, 5, 7, 2, 6]`  

- Row 1: Values are 3 and 4.  
- Row 2: Values are 5 and 7.  
- Row 3: No non-zero values.  
- Row 4: Values are 2 and 6.  

### Indices Array (indices)  

- here we are consider the matrix starts from `0` not `1`.  

`indices = [2, 4, 2, 3, 1, 2]`  

#### Corresponds to the data array

- 3 (row 1, column 2)  
- 4 (row 1, column 4)  
- 5 (row 2, column 2)  
- 7 (row 2, column 3)  
- 2 (row 4, column 1)  
- 6 (row 4, column 2)  

### Index Pointer Array (indptr)  

`indptr = [0, 2, 4, 4, 6]`  

- Row 1 starts at index 0 in data.  
- Row 2 starts at index 2 in data.  
- Row 3 starts at index 4 in data (but has no non-zero elements).  
- Row 4 starts at index 4 in data (ends at index 6).  
- The last entry (6) is the length of the data array, indicating the end of the last row.  
- Here we add previous elements with current element in the row

## Compressed Sparse Column (CSC) Format

- Similar to CSR, but it compresses columns instead of rows.

## Coordinate List (COO) Format

- **Row Indices**: Stores the row indices of non-zero elements.
- **Column Indices**: Stores the column indices of non-zero elements.
- **Data**: Stores the non-zero values.
- Also known as 3-column representation

| 0 0 3 0 4 |  
| 0 0 5 7 0 |  
| 0 0 0 0 0 |  
| 0 2 6 0 0 |  

R | C | E  
-> left blank intentionally ( we use to store the data of the matrix)  
4 | 5 | 6 This is th data (No rows | No of columns | No elements )  
1 | 3 | 3  
1 | 5 | 4  
2 | 3 | 5  
2 | 4 | 7  
4 | 2 | 2  
4 | 3 | 6  

## Diagonal Storage

- Used for matrices with non-zero elements primarily along the diagonal lines.

### Operations on Sparse Matrices

Operations on sparse matrices often require specialized algorithms to avoid unnecessary computations with zero values:

- **Matrix Addition and Subtraction**: Only add or subtract the non-zero elements.
- **Matrix-Vector Multiplication**: Efficiently multiply by considering only non-zero entries.
- **Matrix-Matrix Multiplication**: Techniques like sparse matrix partitioning and blocking are used to handle the sparsity.

### Applications of Sparse Matrices

1. **Scientific Computing**: Modeling physical phenomena, such as finite element analysis, where interactions are localized.
2. **Machine Learning**: Sparse data representation in high-dimensional spaces, e.g., feature vectors in natural language processing.
3. **Optimization Problems**: Solving large systems of linear equations where the coefficient matrix is sparse.
4. **Graph Algorithms**: Representing large graphs with sparse adjacency matrices.

### Example: Sparse Matrix in CSR Format

Consider a 4x5 matrix with many zeros:

| 0 0 3 0 4 |  
| 0 0 5 7 0 |  
| 0 0 0 0 0 |  
| 0 2 6 0 0 |  

In CSR format, it would be represented as:

- **Data**: `[3, 4, 5, 7, 2, 6]`
- **Indices**: `[2, 4, 2, 3, 1, 2]`
- **Index Pointer**: `[0, 2, 4, 4, 6]`

This compact representation allows efficient storage and computation, leveraging the sparsity of the matrix.

Understanding and utilizing sparse matrices effectively is important for optimizing performance in large-scale computational problems.

c for sparse matrix

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single element in the sparse matrix
struct Element {
    int i; // Row index of the non-zero element
    int j; // Column index of the non-zero element
    int x; // Value of the non-zero element
};

// Define the structure for the sparse matrix
struct sparse {
    int m; // Number of rows
    int n; // Number of columns
    int num; // Number of non-zero elements
    struct Element *ele; // Array of non-zero elements
};

// Function to create a sparse matrix
void create(struct sparse *s) {
    printf("Enter dimensions \n");
    scanf("%d%d", &s->m, &s->n); // Read matrix dimensions (rows and columns)
    printf("Enter the number of non-zero elements\n");
    scanf("%d", &s->num); // Read the number of non-zero elements

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element)); // Allocate memory for non-zero elements
    printf("Enter all the elements \n");
    for (int i = 0; i < s->num; i++) {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x); // Read the row, column, and value of each non-zero element
    }
}

// Function to display the sparse matrix
void display(struct sparse s) {
    int i, j, k = 0; // Initialize row (i), column (j), and element index (k)
    for (i = 0; i < s.m; i++) { // Iterate over each row
        for (j = 0; j < s.n; j++) { // Iterate over each column
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j) { // Check if the current position matches the position of a non-zero element
                printf("%d ", s.ele[k++].x); // Print the non-zero element and move to the next
            } else {
                printf("0 "); // Print zero for all other positions
            }
        }
        printf("\n"); // Move to the next row
    }
}

// Function to add two sparse matrices
struct sparse *add(struct sparse *s1, struct sparse *s2) {
    struct sparse *sum; // Pointer to the resulting sparse matrix
    int i = 0, j = 0, k = 0; // Initialize indices for s1, s2, and sum
    sum = (struct sparse *)malloc(sizeof(struct sparse)); // Allocate memory for the resulting sparse matrix
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element)); // Allocate memory for non-zero elements of the resulting matrix

    // Add non-zero elements from both matrices
    while (i < s1->num && j < s2->num) {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    // Copy remaining elements from s1 or s2
    for (; i < s1->num; i++) sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++) sum->ele[k++] = s2->ele[j];

    sum->m = s1->m; // Set the dimensions of the resulting matrix
    sum->n = s1->n;
    sum->num = k; // Set the number of non-zero elements in the resulting matrix

    return sum; // Return the resulting sparse matrix
}

int main() {
    struct sparse s1, s2, *s3;

    create(&s1); // Create the first sparse matrix
    create(&s2); // Create the second sparse matrix

    s3 = add(&s1, &s2); // Add the two sparse matrices

    printf("First matrix\n");
    display(s1); // Display the first sparse matrix

    printf("Second matrix\n");
    display(s2); // Display the second sparse matrix

    printf("Third matrix\n");
    display(*s3); // Display the resulting sparse matrix

    // Free allocated memory
    free(s1.ele);
    free(s2.ele);
    free(s3->ele);
    free(s3);

    return 0;
}

```

Converting the above program into c++

```c++
#include <iostream>
using namespace std;

// Define the class for a single element in the sparse matrix
class Element {
public:
    int i; // Row index of the non-zero element
    int j; // Column index of the non-zero element
    int x; // Value of the non-zero element
};

// Define the class for the sparse matrix
class Sparse {
public:
    int m; // Number of rows
    int n; // Number of columns
    int num; // Number of non-zero elements
    Element *ele; // Array of non-zero elements

    Sparse(int rows = 0, int cols = 0, int nonZero = 0)
        : m(rows), n(cols), num(nonZero) {
        ele = new Element[nonZero];
    }

    ~Sparse() {
        delete[] ele;
    }

    // Function to create the sparse matrix
    void create() {
        cout << "Enter dimensions: ";
        cin >> m >> n;
        cout << "Enter the number of non-zero elements: ";
        cin >> num;

        ele = new Element[num];
        cout << "Enter all the elements (row, column, value):\n";
        for (int i = 0; i < num; i++) {
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
        }
    }

    // Function to display the sparse matrix
    void display() const {
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (k < num && i == ele[k].i && j == ele[k].j) {
                    cout << ele[k++].x << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
    }

    // Function to add two sparse matrices
    Sparse* add(const Sparse &s2) const {
        if (m != s2.m || n != s2.n) {
            cout << "Matrices have different dimensions!";
            return nullptr;
        }

        Sparse *sum = new Sparse(m, n, num + s2.num);
        int i = 0, j = 0, k = 0;

        while (i < num && j < s2.num) {
            if (ele[i].i < s2.ele[j].i) {
                sum->ele[k++] = ele[i++];
            } else if (ele[i].i > s2.ele[j].i) {
                sum->ele[k++] = s2.ele[j++];
            } else {
                if (ele[i].j < s2.ele[j].j) {
                    sum->ele[k++] = ele[i++];
                } else if (ele[i].j > s2.ele[j].j) {
                    sum->ele[k++] = s2.ele[j++];
                } else {
                    sum->ele[k] = ele[i];
                    sum->ele[k++].x = ele[i++].x + s2.ele[j++].x;
                }
            }
        }

        for (; i < num; i++) sum->ele[k++] = ele[i];
        for (; j < s2.num; j++) sum->ele[k++] = s2.ele[j];
        sum->num = k;

        return sum;
    }
};

int main() {
    Sparse s1, s2, *s3;

    s1.create();
    s2.create();

    s3 = s1.add(s2);

    cout << "First matrix\n";
    s1.display();

    cout << "Second matrix\n";
    s2.display();

    if (s3 != nullptr) {
        cout << "Resulting matrix after addition\n";
        s3->display();
        delete s3;
    }

    return 0;
}

```

## Operator overloading

Operator overloading in C++ allows you to redefine the behavior of existing operators for user-defined types (like classes). This provides a way to make custom types more intuitive and integrated into the language, similar to built-in types. Here’s a detailed explanation of operator overloading, covering what it is, how to implement it, and key considerations.

## What is Operator Overloading?

Operator overloading is a feature in C++ that lets you define the behavior of operators (like `+`, `-`, `*`, `<<`, `>>`) for your custom data types. It allows objects of a class to be manipulated using these operators, just as primitive data types can be.

For example, if you have a `Complex` class representing complex numbers, you can overload the `+` operator to add two `Complex` objects.

## Basic Syntax of Operator Overloading

The general form for overloading an operator is:

```cpp
returnType operator op (parameterList);
```

- `returnType`: The type of value the overloaded operator will return.
- `op`: The operator you want to overload (`+`, `-`, `*`, `<<`, etc.).
- `parameterList`: The parameters required for the operation, typically including one or more objects of your custom type.

### Types of Operator Overloading

1. **Member Function Overloading**: The operator is overloaded within the class. It typically takes one parameter for binary operators.
2. **Non-Member Function Overloading**: The operator is overloaded outside the class, usually as a friend function. This form is used when the left operand is not of the type of the class (or for symmetric binary operations).

### Example of Member Function Overloading

Consider a simple `Complex` class:

```cpp
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator using member function
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

### Example of Non-Member (Friend) Function Overloading

You can overload the `<<` operator to print the `Complex` object:

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Friend function to overload << operator
    friend ostream &operator<<(ostream &os, const Complex &c);
};

// Implementation of << operator
ostream &operator<<(ostream &os, const Complex &c) {
    os << "(" << c.real << ", " << c.imag << ")";
    return os;
}
```

### Overloading `<<` and `>>` Operators

Overloading `<<` and `>>` is typically done as friend functions since the left operand (stream) is not of the class type.

#### Example: Overloading `<<` for Output

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Friend function to overload << operator
    friend ostream &operator<<(ostream &os, const Point &p);
};

// Implementation of << operator
ostream &operator<<(ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
```

#### Example: Overloading `>>` for Input

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Friend function to overload >> operator
    friend istream &operator>>(istream &is, Point &p);
};

// Implementation of >> operator
istream &operator>>(istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}
```

### Rules and Guidelines

1. **Cannot Create New Operators**: You can only overload existing operators. You cannot create new operators (like `**` or `%%`).
2. **Precedence and Associativity**: You cannot change the precedence and associativity of operators through overloading. The language’s rules for these remain the same.
3. **Non-Member vs. Member Functions**:
   - **Member Function**: If the operator is a member function, the left operand must be an object of the class type.
   - **Friend Function**: If the operator is a friend function, it can take different types for operands.
4. **Operators That Cannot Be Overloaded**: Some operators cannot be overloaded, such as `::` (scope resolution), `.` (member access), `.*` (pointer-to-member access), and `?:` (ternary conditional).

### Overloading Common Operators

#### Arithmetic Operators

- **Binary operators** (e.g., `+`, `-`, `*`, `/`):

  ```cpp
  Complex Complex::operator+(const Complex &other) const {
      return Complex(real + other.real, imag + other.imag);
  }
  ```

- **Unary operators** (e.g., `++`, `--`):

  ```cpp
  Complex Complex::operator++() {
      real++;
      imag++;
      return *this;
  }
  ```

#### Relational Operators

- **Relational operators** (e.g., `==`, `!=`, `<`, `>`):

  ```cpp
  bool Complex::operator==(const Complex &other) const {
      return real == other.real && imag == other.imag;
  }
  ```

#### Stream Operators

- **Insertion (`<<`)**:

  ```cpp
  ostream &operator<<(ostream &os, const Complex &c) {
      os << "(" << c.real << ", " << c.imag << ")";
      return os;
  }
  ```

- **Extraction (`>>`)**:

  ```cpp
  istream &operator>>(istream &is, Complex &c) {
      is >> c.real >> c.imag;
      return is;
  }
  ```

#### Assignment Operators

- **Assignment operator (`=`)**:

```cpp
  Complex& Complex::operator=(const Complex &other) {
      if (this != &other) {
          real = other.real;
          imag = other.imag;
      }
      return *this;
}
```

### Practical Example: Sparse Matrix

Here’s a complete example of a `SparseMatrix` class using operator overloading, including `<<` and `>>`.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Element {
public:
    int i, j, x;
    Element(int row = 0, int col = 0, int value = 0) : i(row), j(col), x(value) {}
};

class SparseMatrix {
private:
    int m, n, num;
    vector<Element> ele;

public:
    SparseMatrix(int rows = 0, int cols = 0) : m(rows), n(cols), num(0) {}

    friend istream &operator>>(istream &is, SparseMatrix &s);
    friend ostream &operator<<(ostream &os, const SparseMatrix &s);

    SparseMatrix operator+(const SparseMatrix &s2) const {
        if (m != s2.m || n != s2.n) {
            cout << "Matrices cannot be added. Dimensions do not match.\n";
            return SparseMatrix();
        }

        SparseMatrix sum(m, n);
        int i = 0, j = 0;

        while (i < num && j < s2.num) {
            if (ele[i].i < s2.ele[j].i || (ele[i].i == s2.ele[j].i && ele[i].j < s2.ele[j].j)) {
                sum.ele.push_back(ele[i++]);
            } else if (s2.ele[j].i < ele[i].i || (s2.ele[j].i == ele[i].i && s2.ele[j].j < ele[i].j)) {
                sum.ele.push_back(s2.ele[j++]);
            } else {
                Element e = ele[i];
                e.x = ele[i++].x + s2.ele[j++].x;
                sum.ele.push_back(e);
            }
        }
        while (i < num) sum.ele.push_back(ele[i++]);
        while (j < s2.num) sum.ele.push_back(s2.ele[j++]);

        sum.num = sum.ele.size();
        return sum;
    }
};

istream &operator>>(istream &is, SparseMatrix &s) {
    cout << "Enter dimensions (rows columns): ";
    is >> s.m >> s.n;

    cout << "Enter the number of non-zero elements: ";
    is >> s.num;

    s.ele.resize(s.num);

    cout << "Enter the row index, column index, and value of each non-zero element:\n";
    for (int i = 0; i < s.num; i++) {
        cout << "Element " << i + 1 << ": ";
        is >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return is;
}

ostream &operator<<(ostream &os, const SparseMatrix &s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j) {
                os << s.ele[k++].x << " ";
            } else {
                os << "0 ";
            }
        }
        os << "\n";
    }
    return os;
}

int main() {
    SparseMatrix s1, s2;

    cout << "Create the first matrix:\n";
    cin >> s1;

    cout << "Create the second matrix:\n";
    cin >> s2;

    SparseMatrix s3 = s1 + s2;

    cout << "First matrix:\n" << s1;
    cout << "Second matrix:\n" << s2;
    cout << "Sum matrix:\n" << s3;

    return 0;
}
```

### Summary

- **Member Function Overloading**: Defines how operators work within the class. Requires one less parameter since the object itself is used.
- **Friend Function Overloading**: Useful when the left operand is not the class type or when symmetric operations are needed.
- **Const Correctness**: Helps ensure that the functions do not modify objects, improving reliability and safety.
- **Operator Restrictions**: Only existing operators can be overloaded, and their precedence and associativity remain unchanged.

Operator overloading can greatly enhance the usability and readability of custom types in C++, allowing them to be manipulated similarly to built-in types.

## Polynomial Representation

Polynomials can be represented and manipulated in various ways. A common method is to use a linked list, where each node contains the coefficient and exponent of a term. This approach makes it easier to perform operations like addition and multiplication.

$$p(x) = 3x^5+2x^4+5x^2+2x+7$$

- 3,2,5,2,7 are coefficients
- 5,4,2,1,0 are the exponential

```c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct term{
    int exp;
    int coeff;
};

struct poly{
    int n;
    struct term *t;
};

void create(struct poly *p)
{
    printf("enter the number of elements: \n");
    scanf("%d",&p->n);
    
    p->t=(struct term *)malloc(p->n*sizeof(struct term));
    
    printf("Enter all the elements: \n");
    for(int i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}

void display(struct poly p)
{
    for(int i=0;i<p.n;i++)
        printf("%dx%d+",p.t[i].coeff,p.t[i].exp);
    printf("\n");
}

int poly_sum(struct poly p)
{
    double sum=0;
    int x;
    printf("Enter the value of x\n");
    scanf("%d",&x);
    for(int i=0;i<p.n;i++)
        sum+=p.t[i].coeff*pow(x,p.t[i].exp);
    return sum;
}

struct poly *add(struct poly *p1,struct poly *p2)
{
    int i,j,k;
    struct poly *sum;
    sum=(struct poly*)malloc(sizeof(struct poly));
    sum->t=(struct term*)malloc((p1->n+p2->n)*sizeof(struct term));
    i=j=k=0;
    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].exp > p2->t[j].exp)
        {
            sum->t[k++] = p1->t[i++];
        }
        else if(p1->t[i].exp < p2->t[j].exp)
        {
            sum->t[k++] = p2->t[j++];
        }
        else 
        {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
        
    }
    for(;i<p1->n;i++) sum->t[k++] = p1->t[i];
    for(;j<p2->n;j++) sum->t[k++] = p2->t[j];
    sum->n = k;
    return sum;

}

int main()
{
    struct poly p1,p2,*p3;
    create(&p1);
    create(&p2);
    printf("poly 1 \n");
    display(p1);
    printf("poly 2 \n");
    display(p2);
    // printf("%f",(double)poly_sum(p1));
 
    p3=add(&p1,&p2);
    display(*p3);


    free(p1.t);
    free(p2.t);
    free(p3->t);
    free(p3);


    return 0;
}



```

----END----
