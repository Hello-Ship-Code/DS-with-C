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
