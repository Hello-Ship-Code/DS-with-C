# Linked List

A **linked list** is a linear data structure in which elements, called nodes, are stored in a sequence. Each node contains two parts:

1. **Data**: The value or information of the node.
2. **Pointer**: A reference or link to the next node in the sequence.

The last node's pointer is typically `NULL`, indicating the end of the list. Linked lists come in various types:

- **Singly Linked List**: Each node points to the next node.
- **Doubly Linked List**: Each node points to both the next and the previous node.
- **Circular Linked List**: The last node points back to the first node, forming a circle.

## Structure of a Node in C

```c
struct Node {
    int data;
    struct Node* next; // this is known as self-referential structure
};
```

### Basic Operations

1. **Insertion**: Adding a node at the beginning, end, or middle of the list.
2. **Deletion**: Removing a node from the list.
3. **Traversal**: Accessing each node in the list sequentially.

### Problems with Arrays

1. **Fixed Size**: Arrays have a fixed size, defined at creation time, which limits their flexibility. You cannot resize an array without creating a new one and copying elements.
2. **Memory Waste**: If the array is not fully utilized, there can be wasted memory.
3. **Costly Insertion and Deletion**: Inserting or deleting elements in an array involves shifting elements, which is costly in terms of time complexity (`O(n)` for worst-case scenarios).
4. **Contiguous Memory**: Arrays require a contiguous block of

### Simple Statements

- **Linear Search (ls)** works on linked lists because it processes elements sequentially, matching the structure of linked lists which allows traversal from one node to the next.

- **Binary Search (bs)** doesn’t work on linked lists because it relies on quick random access to the middle elements, which linked lists cannot provide efficiently due to their sequential access nature.

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
}*first=NULL;

// Global pointer to the first node
// struct Node *first = NULL;

// Function to create and insert a new node at the end of the list
void create(int data) {
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if (first == NULL) {
        first = t;
    } else {
        last = first;
        while (last->next) {
            last = last->next;
        }
        last->next = t;
    }
}

// Function to display the linked list
void display() {
    struct Node *p = first;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Recursive function to display the linked list
void display_recursive(struct Node *p) {
    if (p != NULL) {
        printf("%d -> ", p->data);
        display_recursive(p->next); // Recursive call to the next node
    } else {
        printf("NULL\n");
    }
    // printing reverse
    // if(p!=0)
    // {
    //     printf("%d -> ",p->data);
    //     display(p->next);
    // }
}

// Function to get the length of the linked list recursively
int getlength(struct Node *p) {
    if (p == NULL)
        return 0;
    else
        return getlength(p->next) + 1;
}

// Alternative function to get the length of the linked list iteratively
int getlength_iterative(struct Node *p) {
    int length = 0;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

// Function to calculate the sum of the linked list recursively
int sum(struct Node *p) {
    if (p == NULL)
        return 0;
    else
        return sum(p->next) + p->data;
}

// Alternative function to calculate the sum of the linked list iteratively
int sum_iterative(struct Node *p) {
    int total = 0;
    while (p != NULL) {
        total += p->data;
        p = p->next;
    }
    return total;
}

// Function to find the maximum value in the linked list recursively
int max_num(struct Node *p) {
    if (p == NULL)
        return INT_MIN;
    int x = max_num(p->next); // Recursive call to the next node
    return x > p->data ? x : p->data; // Return the maximum of current node and recursion result

        //recursive
    // int x;
    // if(p!=0){
    //     x = max_num(p->next);
    //     if (x > 0)
    //         return x;
    //     else
    //         return (p->data) ;
    // } else{
    //     return INT_MIN;
    // }
}

// Alternative function to find the maximum value in the linked list iteratively
int max_num_iterative(struct Node *p) {
    int max = INT_MIN;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// Function to search for a value and move it to the head of the linked list
struct Node* lsearch(int key) {
    struct Node *p = first, *q = NULL; // Pointer to keep track of the previous node
    while (p != NULL) {
        if (key == p->data) {
            if (q != NULL) q->next = p->next; // Remove p from its current position
            p->next = first; // Move p to the head
            first = p; // Update the head
            return p;
        }
        q = p; // Update q to current node
        p = p->next; // Move to next node
    }
    return NULL; // Key not found
}

// Alternative recursive function to search for a value (without moving to head)
struct Node* lsearch_recursive(struct Node *p, int key) {
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return lsearch_recursive(p->next, key);
}

// Function to insert a node at a given position
void insert_at_position(int x, int pos) {
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(pos < 0 || pos > getlength(p))
        return ;

    if (pos == 0) {
        t->next = first;
        first = t;
    } else {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++) p = p->next;
        if (p) {
            t->next = p->next;
            p->next = t;
        }
    }
}

// Function to insert a node in a sorted linked list
void sorted_insert(int x) {
    struct Node *t, *p = first, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL || first->data >= x) {
        t->next = first;
        first = t;
    } else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        t->next = q->next;
        q->next = t;
    }
}

// Function to delete a node at a given position
int delete(int index) {
    struct Node *p = first, *q = NULL;
    int x = -1;

    if (index < 1 || index > getlength(first)) return -1;

    if (index == 1) {
        first = first->next;
        x = p->data;
        free(p);
    } else {
        for (int i = 0; i < index - 1 && p; i++) {
            q = p;
            p = p->next;
        }
        if (p) {
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}

// Function to check if the linked list is sorted
int is_sorted(struct Node *p) {
    int x = INT_MIN;

    while (p != NULL) {
        if (x > p->data)
            return 0; // List is not sorted
        x = p->data;
        p = p->next;
    }
    return 1; // List is sorted
}

// Function to remove duplicate values from a sorted linked list
void rmv_dup(struct Node *p) {
    struct Node *q = p->next;

    while (q != NULL) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            free(q); // Remove duplicate node
            q = p->next;
        }
    }
}

// Function to reverse the linked list using an array
void reverse1(struct Node *p) {
    int *A, i = 0;
    int length = getlength(p);

    A = (int *)malloc(sizeof(int) * length);

    // Copy the data into the array
    while (p != NULL) {
        A[i++] = p->data;
        p = p->next;
    }

    // Reassign p to point to the head again
    p = first;
    i--; // Adjust index to the last element in the array

    // Assign the data in reverse order
    while (p != NULL) {
        p->data = A[i--];
        p = p->next;
    }

    free(A); // Free the allocated memory
}

// Alternative function to reverse the linked list by reversing the links
void reverse2(struct Node *p) {
    struct Node *q = NULL, *r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r; // Reverse the link
    }
    first = q; // Update the head to the new first node
}

// Alternative function to reverse the linked list recursively
void reverse3(struct Node *p, struct Node *q) {
    if (p != NULL) {
        reverse3(p->next, p); // Recursive call
        p->next = q;
    } else {
        first = q; // Update the head to the new first node
    }
}

// Function to concatenate two linked lists
void concat(struct Node *second) {
    struct Node *p = first;
    while (p->next != NULL) p = p->next; // Move to the end of the first list
    p->next = second; // Link the end of the first list to the start of the second list
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node *first1, struct Node *first2) {
    struct Node *third, *last;

    // Initialize third (result list) and last
    if (first1->data < first2->data) {
        third = last = first1;
        first1 = first1->next;
        last->next = NULL;
    } else {
        third = last = first2;
        first2 = first2->next;
        last->next = NULL;
    }

    // Merge the two lists
    while (first1 != NULL && first2 != NULL) {
        if (first1->data < first2->data) {
            last->next = first1;
            last = first1;
            first1 = first1->next;
            last->next = NULL;
        } else {
            last->next = first2;
            last = first2;
            first2 = first2->next;
            last->next = NULL;
        }
    }

    // Attach remaining nodes of first1 if any
    if (first1 != NULL) {
        last->next = first1;
    }
    // Attach remaining nodes of first2 if any
    if (first2 != NULL) {
        last->next = first2;
    }

    return third;
}



// Main function with switch-case menu
int main() {
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create/Insert\n");
        printf("2. Display\n");
        printf("3. Display Recursively\n");
        printf("4. Get Length (Recursive)\n");
        printf("5. Get Length (Iterative)\n");
        printf("6. Sum (Recursive)\n");
        printf("7. Sum (Iterative)\n");
        printf("8. Max (Recursive)\n");
        printf("9. Max (Iterative)\n");
        printf("10. Search and Move to Head\n");
        printf("11. Search (Recursive)\n");
        printf("12. Insert at Position\n");
        printf("13. Sorted Insert\n");
        printf("14. Delete\n");
        printf("15. Check if Sorted\n");
        printf("16. Remove Duplicates\n");
        printf("17. Reverse List (Using Array)\n");
        printf("18. Reverse List (Reverse Links)\n");
        printf("19. Reverse List (Recursively)\n");
        printf("20. Concatenate Another List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                display();
                break;
            case 3:
                display_recursive(first);
                break;
            case 4:
                printf("Length (Recursive): %d\n", getlength(first));
                break;
            case 5:
                printf("Length (Iterative): %d\n", getlength_iterative(first));
                break;
            case 6:
                printf("Sum (Recursive): %d\n", sum(first));
                break;
            case 7:
                printf("Sum (Iterative): %d\n", sum_iterative(first));
                break;
            case 8:
                printf("Max (Recursive): %d\n", max_num(first));
                break;
            case 9:
                printf("Max (Iterative): %d\n", max_num_iterative(first));
                break;
            case 10:
                printf("Enter key to search: ");
                scanf("%d", &data);
                if (lsearch(data))
                    printf("Key %d found and moved to head\n", data);
                else
                    printf("Key not found\n");
                break;
            case 11:
                printf("Enter key to search (Recursive): ");
                scanf("%d", &data);
                if (lsearch_recursive(first, data))
                    printf("Key %d found\n", data);
                else
                    printf("Key not found\n");
                break;
            case 12:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_at_position(data, pos);
                break;
            case 13:
                printf("Enter data to insert in sorted list: ");
                scanf("%d", &data);
                sorted_insert(data);
                break;
            case 14:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                data = delete(pos);
                if (data != -1)
                    printf("Deleted value: %d\n", data);
                else
                    printf("Invalid position\n");
                break;
            case 15:
                if (is_sorted(first)) 
                    printf("The list is sorted\n");
                else 
                    printf("The list is not sorted\n");
                break;
            case 16:
                rmv_dup(first);
                printf("Duplicates removed\n");
                break;
            case 17:
                reverse1(first);
                printf("List reversed using array\n");
                break;
            case 18:
                reverse2(first);
                printf("List reversed by reversing links\n");
                break;
            case 19:
                reverse3(first, NULL);
                printf("List reversed recursively\n");
                break;
            case 20:
                printf("Enter elements for the second list (end with -1): ");
                struct Node *second = NULL;
                while (1) {
                    scanf("%d", &data);
                    if (data == -1) break;
                    create(data);
                }
                concat(second);
                printf("Lists concatenated\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

```

## Loops in linked list

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Global pointer to the first node
struct Node *first = NULL;

// Function to create and insert a new node at the end of the list
void create(int data) {
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if (first == NULL) {
        first = t;
    } else {
        last = first;
        while (last->next) {
            last = last->next;
        }
        last->next = t;
    }
}

// Function to display the linked list
void display() {
    struct Node *p = first;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to create a loop in the linked list
void create_loop(int pos) {
    if (pos < 0) return;

    struct Node *p = first, *loop_node = NULL;
    int count = 0;

    // Traverse to the node at the given position
    while (p != NULL && count < pos) {
        loop_node = p;
        p = p->next;
        count++;
    }

    // If the loop_node is found and p is not NULL, create a loop
    if (loop_node && p) {
        while (p->next) {
            p = p->next;
        }
        p->next = loop_node; // Create a loop by pointing the last node to the loop_node
    }
}

// Function to detect if there is a loop in the linked list
int detect_loop() {
    struct Node *slow = first, *fast = first;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet at some point, then there is a loop
        if (slow == fast) {
            return 1; // Loop detected
        }
    }

    return 0; // No loop detected
}

// Function to remove the loop from the linked list
void remove_loop() {
    struct Node *slow = first, *fast = first;

    // Detect loop using Floyd’s Cycle-Finding Algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;// we can use as many next's as possible

        if (slow == fast) { // Loop detected
            // Find the starting point of the loop
            slow = first;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            // Break the loop
            fast->next = NULL;
            return;
        }
    }
}

int main() {
    int data, choice, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create/Insert\n");
        printf("2. Display\n");
        printf("3. Create Loop\n");
        printf("4. Detect Loop\n");
        printf("5. Remove Loop\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter position to create loop: ");
                scanf("%d", &pos);
                create_loop(pos);
                break;
            case 4:
                if (detect_loop())
                    printf("Loop detected in the linked list.\n");
                else
                    printf("No loop detected in the linked list.\n");
                break;
            case 5:
                remove_loop();
                printf("Loop removed from the linked list.\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

```

## Circular Linked List

A circular linked list is a variation of a linked list where the last node of the list points back to the first node, forming a loop. In other words, the "next" pointer of the last node points to the first node instead of being NULL as in a traditional linked list.

Here are some key characteristics of a circular linked list:

1. **Circular Structure**: The last node in the list points to the first node, forming a circular structure. This means that traversal can start from any node and continue until the traversal reaches the starting node again.

2. **No NULL Pointers**: Unlike traditional linked lists where the "next" pointer of the last node is NULL, in a circular linked list, there are no NULL pointers among the nodes.

3. **Traversal**: Traversal of a circular linked list can start from any node and continue until the starting node is reached again. This means that there's no need to keep track of the end of the list separately.

4. **Applications**:
   - Circular linked lists are often used in applications where data needs to be accessed in a continuous loop, such as in round-robin scheduling algorithms.
   - They can also be useful in implementing data structures like circular buffers or queues.

5. **Insertion and Deletion**: Insertion and deletion operations in a circular linked list are similar to those in traditional linked lists. However, care must be taken to properly update the pointers to maintain the circular structure.

6. **Termination**: Although the list forms a loop, there still needs to be a way to determine when to terminate operations such as traversal. This can be achieved by setting a condition or flag to indicate the end of traversal.

Overall, circular linked lists offer advantages in scenarios where continuous looping and efficient traversal are required. However, they also require careful handling to avoid infinite loops and ensure proper maintenance of the circular structure.

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node *next;
};

// Global pointer to the last node in the circular linked list
struct Node *last = NULL;

// Function to create a circular linked list and insert a new node at the end
void create(int data) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;

    if (last == NULL) {
        // If the list is empty, initialize the first node
        last = t;
        last->next = last;
    } else {
        // Insert the new node at the end and update the last pointer
        t->next = last->next; // The new node points to the first node
        last->next = t; // The last node points to the new node
        last = t; // Update the last pointer to the new node
    }
}

// Function to display the circular linked list
void display() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *p = last->next;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("(circular)\n");
}

// Function to insert a node at a given position in the circular linked list
void insert(int data, int pos) {
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;

    if (last == NULL) {
        // If the list is empty, initialize the first node
        last = t;
        last->next = last;
    } else if (pos == 0) {
        // Insert at the beginning
        t->next = last->next;
        last->next = t;
    } else {
        // Insert at the given position
        p = last->next;
        for (int i = 0; i < pos - 1 && p != last; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
        if (p == last)
            last = t; // Update last if inserted at the end
    }
}

// Function to delete a node at a given position in the circular linked list
int delete(int pos) {
    if (last == NULL) {
        printf("The list is empty.\n");
        return -1;
    }

    struct Node *p = last->next, *q = NULL;
    int x;

    if (pos == 0) {
        // Delete the first node
        if (last == last->next) {
            x = last->data;
            free(last);
            last = NULL;
        } else {
            q = last->next;
            x = q->data;
            last->next = q->next;
            free(q);
        }
    } else {
        // Delete the node at the given position
        for (int i = 0; i < pos && p->next != last->next; i++) {
            q = p;
            p = p->next;
        }
        if (p == last->next) {
            printf("Invalid position.\n");
            return -1;
        }
        q->next = p->next;
        x = p->data;
        if (p == last) last = q; // Update last if deleting the last node
        free(p);
    }
    return x;
}

int main() {
    int data, choice, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create/Insert at End\n");
        printf("2. Display\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Position\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert(data, pos);
                break;
            case 4:
                printf("Enter position to delete from: ");
                scanf("%d", &pos);
                data = delete(pos);
                if (data != -1)
                    printf("Deleted value: %d\n", data);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

```

## Method 2

```cpp
#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the circular linked list
struct Node{
    int data;         // Data part of the node
    struct Node *next; // Pointer to the next node
};

struct Node *Head; // Global pointer to the head of the circular linked list

// Function to create a circular linked list from an array
void create(int a[], int n) {
    struct Node *t, *last;
    Head = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the first node
    Head->data = a[0];  // Set the data of the first node
    Head->next = Head;  // Point the first node to itself, making it circular

    last = Head; // Initialize last as Head
    
    for(int i = 1; i < n; i++) { 
        t = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
        t->data = a[i];   // Set the data of the new node
        t->next = last->next; // Point the new node to the first node
        last->next = t;    // Update the last node to point to the new node
        last = t;          // Move the last pointer to the new node
    }
}

// Function to display the circular linked list recursively
void recursive_display(struct Node *h) {
    static int flag = 0; // Static flag to control recursion depth

    if(h != Head || flag == 0) {   
        flag = 1;               // Set the flag when starting the display
        printf("%d ", h->data); // Print the data of the current node
        recursive_display(h->next); // Recursive call to the next node
    }
    flag = 0; // Reset the flag to 0 when recursion ends
}

// Function to get the length of the circular linked list
int getlength(struct Node *p) {
    int len = 0; // Initialize length counter
    
    do {
        len++;    // Increment length for each node
        p = p->next; // Move to the next node
    } while(p != Head); // Continue until the circular linked list loops back to the head

    return len; // Return the length of the list
}

// Function to insert a new node at a given index in the circular linked list
void insert(struct Node *p, int data, int index) {
    struct Node *t;
    
    if(index < 0 || index > getlength(p)) // Check if the index is valid
        return;

    if(index == 0) { // Insert at the beginning
        t = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
        t->data = data; // Set the data of the new node
        if(Head == NULL) { // If the list is empty, initialize the first node
            Head = t;
            Head->next = Head; // Point the new node to itself
        } else {
            while(p->next != Head) // Traverse to the last node
                p = p->next;
            p->next = t; // Point the last node to the new node
            t->next = Head; // Point the new node to the old head
            Head = t; // Update head to the new node
        }
    } else {
        for(int i = 0; i < index - 1; i++)
            p = p->next; // Traverse to the node before the insertion point
        t = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
        t->data = data; // Set the data of the new node
        t->next = p->next; // Link the new node to the next node
        p->next = t; // Link the previous node to the new node
    }
}

// Function to display the circular linked list iteratively
void display(struct Node *h) {
    do {
        printf("%d ", h->data); // Print the data of the current node
        h = h->next; // Move to the next node
    } while(h != Head); // Continue until the circular linked list loops back to the head
    
    printf("\n"); // Print newline at the end of the display
}

// Function to delete a node at a given index in the circular linked list
int delete(struct Node *p, int index) {   
    struct Node *q;
    int x;
    if(index < 0 || index > getlength(p)) // Check if the index is valid
         return -1;

    if(index == 1) { // Delete the first node
        while(p->next != Head) // Traverse to the last node
            p = p->next;
        x = Head->data; // Store data of the node to be deleted
        if(Head->next == p) { // If the list has only one node
            free(Head); // Free the memory of the head
            Head = NULL; // Set head to NULL
        } else {
            p->next = Head->next; // Point the last node to the second node
            free(Head); // Free the memory of the head
            Head = p->next; // Update head to the second node
        }
    } else {
        for(int i = 0; i < index - 2; i++) p = p->next; // Traverse to the node before the deletion point
        q = p->next; // Node to be deleted
        p->next = q->next; // Link the previous node to the next node
        x = q->data; // Store data of the node to be deleted
        free(q); // Free the memory of the node to be deleted
    }
    return x; // Return the data of the deleted node
}

int main() {
    int A[] = {1, 2, 3, 4, 5}; // Array to create the circular linked list

    create(A, 5); // Create the circular linked list
    insert(Head, 10, 5); // Insert 10 at index 5
    
    delete(Head, 9); // Delete the node at index 9 (invalid in this case, should handle error)
    recursive_display(Head); // Display the list recursively

    return 0;
}

```

## Doubly Linked List

Certainly! A doubly linked list is a data structure consisting of a sequence of elements called nodes. Each node contains two pointers or references: one to the previous node and one to the next node in the sequence. This bidirectional linking allows traversal of the list in both forward and backward directions.

Here are some key points about doubly linked lists:

1. **Bidirectional traversal**: Unlike singly linked lists, where traversal is only possible in one direction (forward), doubly linked lists allow traversal in both forward and backward directions.

2. **Dynamic size**: Doubly linked lists can dynamically grow and shrink in size. Nodes can be efficiently added or removed from the beginning, end, or middle of the list.

3. **Memory overhead**: Doubly linked lists require more memory compared to singly linked lists due to the additional pointer in each node that points to the previous node.

4. **Operations**:
   - **Insertion**: Insertion of a new node can be done efficiently at the beginning, end, or middle of the list.
   - **Deletion**: Deletion of a node can also be done efficiently from any position in the list.
   - **Traversal**: Traversing the list can be done in both forward and backward directions.

5. **Applications**:
   - Doubly linked lists are commonly used in implementations of other data structures like stacks, queues, and associative arrays (like hash tables).
   - They are suitable for scenarios where efficient insertion and deletion operations are required, and when there's a need for traversal in both forward and backward directions.

6. **Drawbacks**:
   - Increased memory usage due to the extra pointer in each node.
   - Slightly more complex to implement and maintain compared to singly linked lists.

Overall, doubly linked lists offer flexibility and efficiency in certain scenarios where bidirectional traversal and dynamic manipulation of elements are required.

```cpp
#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t,*last;

    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev = NULL;
    first->next = NULL;
    
    last=first;

    for(int i=1;i<n;i++) // i = 1 cause we have already declared the first element
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = last->next; 
        t->prev = last;
        last->next=t;
        last=t; 
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int getlength(struct Node *p) {
    int len = 0; 
    
    while(p!=NULL) {
        len++;    
        p = p->next; 
    }

    return len; // Return the length of the list
}


void insert(struct Node *p,int data, int index)
{
    struct Node *t;
    if(index <0 || index >getlength(p)) return;

    t=(struct Node*)malloc(sizeof(struct Node));

    if(index == 0){ 
        t = (struct Node *)malloc(sizeof(struct Node)); 
        t->data = data; 
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t; 
    } else {
        for(int i = 0; i < index - 1; i++)
            p = p->next; 
        t = (struct Node *)malloc(sizeof(struct Node));  
        t->data = data; 

        t->prev = p;
        t->next = p->next; 
        if(p->next != NULL)
            p->next->prev = t; 
        p->next = t;
    }
}

void delete(struct Node *p, int index)
{
    if(index < 0 || index > getlength(p))
        return ;
    
    int x;

    if(index == 0 )
    {
        first = first->next;
        if(first) first->prev = NULL;
        x=p->data;
        free(p);
        
    }
    else
    {
        for(int i=0;i<index-1;i++) p = p->next;

        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
}


void reverse1(struct Node *p)
{
    struct Node  * temp;
    while(p!=NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if(p!=NULL && p->next == NULL)
            first = p;
    }

}


int main()
{
    int A[]={1,2,3,4,5};

    create(A,5);
    
    insert(first,10,0);
    delete(first,0);
    // display(first);
    
    reverse1(first);
    
    display(first);
    
    return 0;
}

```

## Circular Doubly Linked list

A circular doubly linked list combines the features of a circular linked list and a doubly linked list. Like a circular linked list, the last node points back to the first node, forming a loop. Additionally, each node in the list maintains references to both the next and previous nodes, enabling bidirectional traversal.

Here are some key characteristics of a circular doubly linked list:

1. **Circular Structure**: Similar to a circular linked list, the last node in the list points back to the first node, forming a loop. This allows for continuous traversal from any node in the list.

2. **Bidirectional Traversal**: Each node maintains pointers or references to both the next and previous nodes, enabling traversal in both forward and backward directions. This bidirectional traversal is a characteristic inherited from doubly linked lists.

3. **No NULL Pointers**: As with circular linked lists, there are no NULL pointers among the nodes. Instead, the pointers of the first and last nodes in the list are adjusted to maintain the circular structure.

4. **Insertion and Deletion**: Insertion and deletion operations in a circular doubly linked list are similar to those in traditional doubly linked lists. Care must be taken to properly update the pointers to maintain the circular structure and bidirectional links.

5. **Applications**: Circular doubly linked lists find applications in scenarios where continuous looping and bidirectional traversal are required, along with efficient insertion and deletion operations. Examples include implementations of certain types of caches, game loops, and music playlists.

6. **Termination**: Similar to circular linked lists, a termination condition or flag is necessary to determine when to terminate operations such as traversal.

Circular doubly linked lists offer advantages in scenarios requiring bidirectional traversal and continuous looping, while also providing efficient insertion and deletion operations. However, they require careful handling to maintain the integrity of the circular structure and bidirectional links.

```cpp

```

middle node of linked list using 2 nodes and p=p->next (1 time ) q=q->next ( 2 times) if q reaches null stop p and its the middle node

using stack insert data in stack and divide the stack length /2 and pop that many number of elements from stack and the remaining last one is middle

intersection of 2 linked list using 2 stack insert data in stack  pop that many equal elements by maintaining a copy of previous if different we found the intersection
