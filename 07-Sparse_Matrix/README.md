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

1. **Compressed Sparse Row (CSR) Format**:
    - **Data**: Stores the non-zero values.
    - **Indices**: Stores the column indices of the elements in the data array.
    - **Index Pointer**: Stores the index in the data array where each row starts.
  
2. **Compressed Sparse Column (CSC) Format**:
    - Similar to CSR, but it compresses columns instead of rows.

3. **Coordinate List (COO) Format**:
    - **Row Indices**: Stores the row indices of non-zero elements.
    - **Column Indices**: Stores the column indices of non-zero elements.
    - **Data**: Stores the non-zero values.

4. **Diagonal Storage**: Used for matrices with non-zero elements primarily along the diagonal lines.

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

## Coordinate List (COO) Format

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
