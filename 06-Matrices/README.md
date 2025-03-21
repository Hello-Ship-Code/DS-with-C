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

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Class to represent a diagonal matrix
class Diagonal {
    private:
        int n;      // Size of the matrix (n x n)
        int *A;     // Pointer to dynamically allocated array to store diagonal elements

    public:
        // Default constructor initializing a 2x2 matrix
        Diagonal() {
            n = 2;
            A = new int[2];
        }

        // Parameterized constructor to initialize an n x n matrix
        Diagonal(int n) {
            this->n = n;
            A = new int[n];
        }

        // Member function to set an element at position (i, j)
        void set(int i, int j, int x);

        // Member function to get an element at position (i, j)
        int get(int i, int j);

        // Member function to display the matrix
        void Display();

        // Destructor to free dynamically allocated memory
        ~Diagonal() {
            delete [] A;
        }
};

// Destructor definition outside the class
// Diagonal::~Diagonal() {
//     delete[] A;
// }


// Function to set an element at position (i, j) if it's on the diagonal
void Diagonal::set(int i, int j, int x) {
    if (i == j) {
        A[i - 1] = x; // Adjust for 0-based indexing
    }
}

// Function to get an element at position (i, j)
int Diagonal::get(int i, int j) {
    if (i == j) {
        return A[i - 1]; // Return the diagonal element
    }
    return 0; // Return 0 for non-diagonal elements
}

// Function to display the matrix
void Diagonal::Display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << A[i] << " "; // Print diagonal element
            } else {
                cout << "0 "; // Print 0 for non-diagonal elements
            }
        }
        cout << endl; // New line after each row
    }
}

// Main function to demonstrate the usage of the Diagonal class
int main() {
    Diagonal d(4); // Create a 4x4 diagonal matrix

    // Set diagonal elements
    d.set(1, 1, 1);
    d.set(2, 2, 2);
    d.set(3, 3, 3);
    d.set(4, 4, 4);

    // Get and print the value at position (1, 1)
    printf("%d \n", d.get(1, 1));

    // Display the entire matrix
    d.Display();

    return 0;
}

```

## Lower Triangular Matrix

- A Matrix `m` `n x n` = `5 x 5` is said to be Lower Triangular Matrix. All lower triangle are non-zero and upper are zero
$$m[i,j]=0  if(i<=j) $$
$$m[i,j]=non-zero  if(i>j) $$
- non-zero = 1 + 2 + 3 + 4 + 5
- non-zero = $$n^2$$ - n(n+1)/2

m =  
| 1 0 0 0 |  
| 5 2 0 0 |  
| 6 7 3 0 |  
| 8 9 1 4 |  

### how to insert

- we use row-Major
A = 1 | 5 2 | 6 7 3 | 8 9 1 4
A[i,j] = [ i * ( i - 1 ) / 2 + (j - 1)]

```C
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a lower triangular matrix
struct Matrix {
    int *A;  // Pointer to store non-zero elements of the lower triangular matrix
    int n;   // Dimension of the matrix (n x n)
};

// Function to set an element in the lower triangular matrix
void set(struct Matrix *m, int i, int j, int x) {
    if (i >= j) {
        m->A[i * (i - 1) / 2 + j - 1] = x;
    }
}

// Function to get an element from the lower triangular matrix
int get(struct Matrix m, int i, int j) {
    if (i >= j) {
        return m.A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

// Function to display the lower triangular matrix
void Display(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            if (i >= j) {
                printf("%d ", m.A[i * (i - 1) / 2 + j - 1]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int i, j, x;

    // Prompt the user to enter the dimension of the matrix
    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    // Allocate memory to store the non-zero elements of the lower triangular matrix
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    // Prompt the user to enter all the elements of the matrix
    printf("Enter all the elements:\n");
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    // Display the value at the first position (1,1) and the whole matrix
    printf("\n\n");
    printf("%d\n", get(m, 1, 1));
    Display(m);

    // Free the allocated memory
    free(m.A);

    return 0;
}

```

- we use Column-Major
A = 1 5 6 8 | 2 7 9 | 3 1 | 4
A[i,j] = [  ( j - 1 ) * n - (( j - 2) * ( j - 1 )) / 2  +  i - j ]

```C
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a lower triangular matrix
struct Matrix {
    int *A;  // Pointer to store non-zero elements of the lower triangular matrix
    int n;   // Dimension of the matrix (n x n)
};

// Function to set an element in the lower triangular matrix
void set(struct Matrix *m, int i, int j, int x) {
    if (i >= j) {
        m->A[ m.n*( j - 1 ) + ( j - 2) + ( j - 1 ) / 2  + i - j ] = x;
    }
}

// Function to get an element from the lower triangular matrix
int get(struct Matrix m, int i, int j) {
    if (i >= j) {
        return m.A[ m->n*( j - 1 ) + ( j - 2) + ( j - 1 ) / 2  + i - j ];
    }
    return 0;
}

// Function to display the lower triangular matrix
void Display(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            if (i >= j) {
                printf("%d ", m.A[ m.n*( j - 1 ) + ( j - 2) + ( j - 1 ) / 2  + i - j ]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int i, j, x;

    // Prompt the user to enter the dimension of the matrix
    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    // Allocate memory to store the non-zero elements of the lower triangular matrix
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    // Prompt the user to enter all the elements of the matrix
    printf("Enter all the elements:\n");
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    // Display the value at the first position (1,1) and the whole matrix
    printf("\n\n");
    printf("%d\n", get(m, 1, 1));
    Display(m);

    // Free the allocated memory
    free(m.A);

    return 0;
}

```

### using C++

```C
#include <iostream>
#include <cstdlib>

using namespace std;

// Class to represent a lower triangular matrix
class Matrix {
private:
    int *A;  // Pointer to store non-zero elements of the lower triangular matrix
    int n;   // Dimension of the matrix (n x n)

public:
    // Constructor to initialize the matrix with a given dimension
    Matrix(int size) {
        n = size;
        A = new int[n * (n + 1) / 2];
    }

    // Destructor to free the allocated memory
    ~Matrix() {
        delete[] A;
    }

    // Function to set an element in the lower triangular matrix
    void set(int i, int j, int x) {
        if (i >= j) {
            A[i * (i - 1) / 2 + j - 1] = x;
        }
    }

    // Function to get an element from the lower triangular matrix
    int get(int i, int j) const {
        if (i >= j) {
            return A[i * (i - 1) / 2 + j - 1];
        }
        return 0;
    }

    // Function to display the lower triangular matrix
    void display() const {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    cout << A[i * (i - 1) / 2 + j - 1] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n, i, j, x;

    // Prompt the user to enter the dimension of the matrix
    cout << "Enter Dimension: ";
    cin >> n;

    // Create a Matrix object
    Matrix m(n);

    // Prompt the user to enter all the elements of the matrix
    cout << "Enter all the elements:" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> x;
            m.set(i, j, x);
        }
    }

    // Display the value at the first position (1,1) and the whole matrix
    cout << "\n" << m.get(1, 1) << endl;
    m.display();

    return 0;
}

```

## Upper Triangular Matrix

- A Matrix `m` `n x n` = `5 x 5` is said to be upper Triangular Matrix. All lower triangle are non-zero and upper are zero
$$m[i,j]=0  if(i>j) $$
$$m[i,j]=non-zero  if(i<=j) $$
- non-zero = 5 + 4 + 3 + 2 + 1
- non-zero = $$n^2 - n * ( n + 1 ) / 2$$
- zero = n * ( n - 1 ) / 2

m =  
| 1 5 6 7 |  
| 0 2 8 9 |  
| 0 0 3 1 |  
| 0 0 0 4 |  

- how to insert
- we use row-Major
A = 1 5 6 7 | 2 8 9 | 3 1 | 4
A[i,j] = [ (i-1) * n - (( i - 2) * ( i - 1 )) / 2  + j - i ]

- we use Column-Major
A = 1 | 5 2 | 6 8 3 | 7 9 1 4
A[i,j] = [ j * ( j - 1 ) / 2  +  i - 1 ]

## Symmetric Matrix

- A Matrix `m` `n x n` = `5 x 5` is said to be Symmetric Matrix. All symmetric are non-zero and upper are zero
- if we know i,j == j,i. So, we can just store any one and reduce the value.
$$m[i,j]=0  if(i>j) $$
$$m[i,j]=non-zero  if(i<=j) $$
- non-zero = 5 + 4 + 3 + 2 + 1
- non-zero = $$n^2$$ - n * ( n + 1 ) / 2$$
- zero = n * ( n - 1 ) / 2

m =  
| 1 1 1 1 |  
| 1 2 2 2 |  
| 1 2 3 3 |  
| 1 2 3 4 |  

- how to insert
- we use row-Major
A = 1 5 6 7 | 2 8 9 | 3 1 | 4
A[i,j] = [ (i-1) * n - ( i - 2) * ( i - 1 ) / 2 ] + (j - i )

- we use Column-Major
A = 1 | 5 2 | 6 8 3 | 7 9 1 4
A[i,j] = [ j * ( j - 1 ) / 2  +  i - 1 ]

## Tri diagonal Matrix

m =  
| 1 1 0 0 |  
| 1 2 2 0 |  
| 0 2 3 3 |  
| 0 0 3 4 |  

main = i - j = 0 index = i-1  
lower = i - j = 1 index = n-1+i-1  
upper = i - j = -1 index 2*n-1+i-1  
m[i,j] = non-zero if | i - j | <= 1  
m[i,j] = 0 if | i - j |  1  
size = 3* n - 2 for size
we can't use row & column major as they are not uniform
we use diagonals

## Square band diagnol

- there are more than and equal number of bands known as square band matrix

## Toeplitz Matrix

- ALl the element in diagonal are same and there are no non-zero elements

m[i,j] = m[i-1,j-1]
elements to store n + n-1
A = 2 3 4 | 1 4
index A[i] [j]
case 1: if i<=j index = j-i
case 2: if i>j index = n + i - j - 1

m =  
| 2 3 4 |  
| 1 2 3 |  
| 4 1 2 |  

## Sparse Matrix

## formulas and explanation

### diagonal Matrix

A diagonal matrix is a matrix in which the entries outside the main diagonal are all zero.

Conditions:

- Only diagonal elements are non-zero.
- Non-zero elements are stored in a 1D array of size \( n \).

Formulas:

- Row-major: \( A[i \cdot (i-1)/2 + (j-1)] \)
- Column-major: \( A[(j-1) \cdot (j-1)/2 + (i-1)] \)

### lower Triangular Matrix

A lower triangular matrix is a matrix in which all the entries above the main diagonal are zero.

Conditions:

- Non-zero elements satisfy \( i \geq j \).
- Non-zero elements are stored in a 1D array of size \( n(n+1)/2 \).

Formulas:

- Row-major: \( A[i \cdot (i-1)/2 + (j-1)] \)
- Column-major: \( A[(j-1) \cdot (2n-j+2)/2 + (i-j)] \)

### upper Triangular Matrix

An upper triangular matrix is a matrix in which all the entries below the main diagonal are zero.

Conditions:

- Non-zero elements satisfy \( i \leq j \).
- Non-zero elements are stored in a 1D array of size \( n(n+1)/2 \).

Formulas:

- Row-major: \( A[i \cdot (2n-i+1)/2 + (j-i)] \)
- Column-major: \( A[(j \cdot (j-1)/2) + (i-1)] \)

### symmetric Matrix

A symmetric matrix is a square matrix that is equal to its transpose.

Conditions:

- Non-zero elements satisfy \$$(A[i] [j] = A[j] [i])$$
- Non-zero elements are stored in a 1D array of size \( n(n+1)/2 \).

Formulas:

- Row-major: If \( i \geq j \): \( A[i \cdot (i-1)/2 + (j-1)] \), else: \( A[j \cdot (j-1)/2 + (i-1)] \)
- Column-major: If \( i \geq j \): \( A[(j-1) \cdot (2n-j+2)/2 + (i-j)] \), else: \( A[(i-1) \cdot (2n-i+2)/2 + (j-i)] \)

### Tri Diagonal Matrix

A tri-diagonal matrix has non-zero elements only on the main diagonal and the diagonals directly above and below it.

Conditions:

- Non-zero elements satisfy \( |i - j| \leq 1 \).
- Non-zero elements are stored in a 1D array of size \( 3n - 2 \).

Formulas:

- Row-major:  
  - Main diagonal: \( A[i-1] \)
  - Lower diagonal: \( A[n-1 + (i-1)] \)
  - Upper diagonal: \( A[2n-1 + (i-2)] \)

- Column-major:  
  - Main diagonal: \( A[i-1] \)
  - Lower diagonal: \( A[n-1 + (j-1)] \)
  - Upper diagonal: \( A[2n-1 + (j-2)] \)

### Band Matrix

A band matrix has non-zero elements around the main diagonal within a certain bandwidth.

Conditions:

- Non-zero elements are within bandwidth \( k \).
- Non-zero elements are stored in a 1D array.

Formulas:

- Row-major:  
  - \( A[i \cdot (2k+1) + (j-i+k)] \)
- Column-major:  
  - \( A[j \cdot (2k+1) + (i-j+k)] \)

### toeplitz Matrix

A Toeplitz matrix has constant diagonals, i.e., each descending diagonal from left to right is constant.

Conditions:

- Non-zero elements satisfy \( A[i] [j] = A[i-1] [j-1] \).
- Non-zero elements are stored in a 1D array of size \( 2n - 1 \).

Formulas:

- Row-major:  
  - If \( i \leq j \): \( A[j-i] \)
  - If \( i > j \): \( A[n + i-j-1] \)
- Column-major:  
  - If \( j \leq i \): \( A[i-j] \)
  - If \( j > i \): \( A[n + j-i-1] \)

### sparse Matrix

A sparse matrix is a matrix in which most of the elements are zero.

Conditions:

- Sparse matrices can be stored efficiently using various techniques such as compressed row storage, compressed column storage, or a list of tuples.

Formulas:

- **Compressed Row Storage**:
  - Row-major:  
    - Values array: \( A[\text{value\_index}] \)
    - Column indices array: \( A[\text{column\_index}] \)
    - Row pointers array: \( A[\text{row\_pointer}] \)
- **Compressed Column Storage**:
  - Column-major:  
    - Values array: \( A[\text{value\_index}] \)
    - Row indices array: \( A[\text{row\_index}] \)
    - Column pointers array: \( A[\text{column\_pointer}] \)

These formulas and conditions provide a guide for storing and accessing elements in various types of matrices efficiently using both row-major and column-major orders.
