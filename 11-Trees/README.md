# Tree's

In data structures, trees are a hierarchical model used to represent and organize data in a way that allows efficient insertion, deletion, and search operations. Below are key terminologies and their definitions related to trees in data structures:

## **Basic Terminologies**

Here's a comprehensive list of basic tree terminologies, incorporating the provided terms:

1. **Tree**: A data structure consisting of nodes, with a single root node and potentially many levels of additional nodes forming a hierarchical structure. Each node may have zero or more child nodes.

2. **Node**: A fundamental part of a tree structure that stores data and has references to child nodes. Each node contains a value and possibly pointers to child nodes.

3. **Root**: The top node of a tree, from which all nodes branch out. There is only one root in a tree.

4. **Edge**: A connection between two nodes in a tree, representing the parent-child relationship.

5. **Child**: A node that is a direct descendant of another node (its parent).

6. **Parent**: A node that has one or more children.

7. **Leaf**: A node with no children, often found at the bottom of a tree.

8. **Subtree**: A portion of a tree that includes a node and all its descendants.

9. **Height**: The length of the longest path from the root to a leaf. The height of a tree is the height of its root node.

10. **Depth**: The length of the path from the root to a particular node. The depth of the root is zero.

11. **Level**: The depth of a node; nodes at the same depth form a level.

12. **Degree of Node**: The number of children a node has. The degree of a tree is the maximum degree of any node in the tree.

13. **Internal Node**: A node with at least one child; not a leaf. Internal nodes are also called non-leaf nodes.

14. **External Node**: A node with no children; also known as a leaf node.

15. **Forest**: A collection of disjoint trees, meaning multiple trees that are not connected to each other.

16. **Sibling**: Nodes that share the same parent are siblings.

17. **Path**: A sequence of nodes and edges connecting a node with a descendant.

18. **Ancestor**: Any node along the path from the root to a particular node.

19. **Descendant**: Any node that is reachable from a particular node through a sequence of edges.

20. **Binary Tree**: A tree where each node has at most two children, often referred to as the left and right child.

21. **Balanced Tree**: A tree in which the height of the left and right subtrees of every node differs by no more than one.

22. **Complete Tree**: A binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

23. **Full Tree**: A binary tree in which every node other than the leaves has two children.

24. **Perfect Tree**: A binary tree in which all interior nodes have two children and all leaves have the same depth.

### **Specialized Trees**

1. **Binary Search Tree (BST)**: A binary tree in which each node has a value, and every node's left child has a value less than its parent, while the right child's value is greater.

2. **Balanced Tree**: A tree where the height of the two subtrees of any node differ by no more than one.

3. **AVL Tree**: A self-balancing binary search tree where the difference in heights of the left and right subtrees is at most one for all nodes.

4. **Red-Black Tree**: A binary search tree with an extra bit of data per node (its color), which ensures the tree remains balanced during insertions and deletions.

5. **B-Tree**: A self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. Used extensively in databases and file systems.

6. **Heap**: A specialized tree-based data structure that satisfies the heap property; in a max heap, for any given node, the value of the node is greater than or equal to the values of its children.

7. **Trie**: A tree-like data structure used for storing a dynamic set of strings, where the keys are usually strings.

8. **Suffix Tree**: A compressed trie of all the suffixes of a given text, useful for various string operations.

### **Traversal Methods**

1. **In-order Traversal**: Visit the left subtree, the root, and the right subtree. (Used in binary search trees to get sorted order.)

2. **Pre-order Traversal**: Visit the root, the left subtree, and the right subtree.

3. **Post-order Traversal**: Visit the left subtree, the right subtree, and then the root.

4. **Level-order Traversal**: Visit nodes level by level from the root downwards, also known as breadth-first traversal.

These terminologies and concepts are fundamental for understanding and working with trees in data structures.

### **Tree Representation and Explanation**

A **tree** is a hierarchical data structure consisting of nodes connected by edges. It starts with a root node and branches out to additional nodes, forming a parent-child relationship. Here's a representation of a simple binary tree and its explanation:

#### **Graphical Representation**

```cpp
        A
       / \
      B   C
     / \   \
    D   E   F
```

### **Explanation**

1. **Nodes**:
   - Each item in the tree is called a node.
   - In this tree, **A**, **B**, **C**, **D**, **E**, and **F** are nodes.

2. **Root**:
   - The root is the topmost node in the tree.
   - **A** is the root node here.

3. **Edges**:
   - An edge connects a parent node to a child node.
   - For example, edges connect **A** to **B**, **A** to **C**, etc.

4. **Parent and Child**:
   - A parent node has one or more child nodes directly connected to it.
   - **A** is the parent of **B** and **C**.
   - **B** is the parent of **D** and **E**.

5. **Leaf**:
   - A leaf node is a node with no children.
   - **D**, **E**, and **F** are leaf nodes.

6. **Subtree**:
   - A subtree is a portion of the tree consisting of a node and all its descendants.
   - For instance, **B** and all its children (**D**, **E**) form a subtree.

7. **Levels**:
   - The level of a node is the number of edges from the root to the node.
   - **A** is at level 0, **B** and **C** are at level 1, and **D**, **E**, and **F** are at level 2.

8. **Depth**:
   - The depth of a node is the distance from the root to that node.
   - **B** has a depth of 1, **D** has a depth of 2.

9. **Height**:
   - The height of a tree is the number of edges on the longest downward path from the root to a leaf.
   - This tree's height is 2.

### **Summary**

In this simple binary tree:

- **A** is the root.
- **B** and **C** are children of **A**.
- **D** and **E** are children of **B**.
- **F** is a child of **C**.
- **D**, **E**, and **F** are leaves.
- The height of the tree is 2.

Each node except the root has exactly one parent, and each node may have zero or more children.

### Definitions and Representations for Number of Binary Trees and Catalan Numbers

#### Number of Binary Trees

**Definition**: The number of distinct binary trees that can be formed with `n` nodes is given by the Catalan number. For `n` nodes, the count is represented by the `n`-th Catalan number \( C_n \).

Here are the corrected formulas for markdown format:

Sure, here is the markdown with the formulas formatted using `$$` for display mode:

### Catalan Number

**Definition**: The Catalan number is a sequence of natural numbers that appears in various counting problems, often involving recursively defined structures. It represents the number of ways to correctly match parentheses, the number of rooted binary trees, the number of paths along the edges of a grid that do not pass above the diagonal, etc.

**Formula**:
$C_n = \frac{1}{n+1} \binom{2n}{n} = \frac{(2n)!}{(n+1)!n!}$
Where $\binom{2n}{n}$ is a binomial coefficient.

**Recursive Formula**:
$C_0 = 1$
$C_{n+1} = \sum_{i=0}^{n} C_i C_{n-i}$

**Representation**:

- **Catalan Numbers**:

  $C_0 = 1, \; C_1 = 1, \; C_2 = 2, \; C_3 = 5, \; C_4 = 14, \; C_5 = 42, \; C_6 = 132, \; \ldots$
  
- **Visual Representation**:
  - **Parentheses Matching**: For $n = 3$, the 5 valid combinations are:

    ```text
    ((())), (()()), (())(), ()(()), ()()()
    ```

  - **Binary Trees**: For $n = 3$ nodes, the 5 binary trees can be visualized as:

    ```text
      Tree 1         Tree 2       Tree 3        Tree 4         Tree 5
         1             1            1             2              3
          \             \            \           / \            /
           2             3            2         1   3          1
            \           /              \                     / \
             3         2                3                   2   3
    ```

  - **Grid Paths**: For $n = 2$, the number of paths from the bottom-left to the top-right of a 2x2 grid without crossing above the diagonal is 2:

    ```text
     .__.
    |  /|
    |/ _|
    ```

### Applications of Catalan Numbers

1. **Binary Trees**: Counting the number of distinct binary trees with $n$ nodes.
2. **Parentheses Combinations**: Number of ways to correctly match $n$ pairs of parentheses.
3. **Grid Paths**: Number of paths along the edges of a grid that do not pass above the diagonal.
4. **Polygon Triangulation**: Number of ways to triangulate a convex polygon with $n+2$ sides.

### Examples and Calculation

**Example Calculation for $C_3$**:

- Using the formula:
  $C_3 = \frac{1}{3+1} \binom{6}{3} = \frac{1}{4} \times 20 = 5$

- Using the recursive definition:
  $C_0 = 1$
  $C_1 = C_0 \cdot C_0 = 1$
  $C_2 = C_0 \cdot C_1 + C_1 \cdot C_0 = 1 + 1 = 2$
  $C_3 = C_0 \cdot C_2 + C_1 \cdot C_1 + C_2 \cdot C_0 = 1 \cdot 2 + 1 \cdot 1 + 2 \cdot 1 = 2 + 1 + 2 = 5$

### Summary

- The number of binary trees for $n$ nodes corresponds to the $n$-th Catalan number.
- Catalan numbers have a wide range of applications in combinatorial mathematics and computer science.

## Steps to Calculate the Number of Labeled Binary Trees

To determine the number of distinct binary trees that can be generated using labeled nodes, we need to consider both the number of binary tree structures possible with $( n )$ unlabeled nodes and the permutations of the labeled nodes.

1. **Count the Number of Unlabeled Binary Trees**: The number of unlabeled binary trees with $( n )$ nodes is given by the $( n )-th$ Catalan number, $( C_n )$. The formula for the \( n \)-th Catalan number is: $C_n = \frac{1}{n+1} \binom{2n}{n} = \frac{(2n)!}{(n+1)!n!}$

2. **Count the Number of Permutations of Labeled Nodes**:
   For $( n )$ labeled nodes, the number of permutations is \( n! \).

3. **Combine Both Counts**:
   The total number of distinct labeled binary trees is the product of the number of unlabeled binary trees and the number of permutations of the labeled nodes:

Number of labeled binary trees = $C_n \times n!$

### Example for $( n = 3)$

1. **Number of Unlabeled Binary Trees**:

$C_3 = \frac{1}{3+1} \binom{6}{3} = \frac{1}{4} \cdot 20 = 5$

1. **Number of Permutations of 3 Labeled Nodes**:

$3! = 6$

1. **Total Number of Labeled Binary Trees**

Number of labeled binary trees = $C_3 \times 3! = 5 \times 6 = 30$

### General Formula

For $( n )$ labeled nodes, the number of distinct labeled binary trees is:

Number of labeled binary trees = $\frac{2nC_n}{n+1} \times n!$

Simplifying, we get:

Number of labeled binary trees = $\frac{(2n)!}{(n+1)!}$

This formula allows you to calculate the number of distinct labeled binary trees for any given $\( n \)$ labeled nodes.

---

## Height of binary tree

- if we are given Nodes of binary tree. We can determine minimum and maximum  height. We can generate a formulae.

$\log_2 (n+1) - 1 \leq height \leq n -1$

## Number of nodes in a binary tree

- if we are given height of binary tree. We can determine minimum and maximum  nodes. We can generate a formulae.

$h + 1 \leq n \leq 2^{h+1} - 1$
