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
