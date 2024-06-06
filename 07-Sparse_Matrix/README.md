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
