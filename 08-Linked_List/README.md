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

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
}*first=0;

void create(int a[], int n)
{   
    int i;
    struct Node *first,*t, *last;

    first=(struct Node *)malloc(sizeof(struct Node));

    first->data=a[0];
    first->next=0;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=0;
        last->next=t;
        last=t;
    }
    return first;
}

void display(struct Node *p){
     // while(p!=0)
    // {
    //     printf("%d -> ",p->data);
    //     p=p->next;
    // }
    if(p!=0)
    {
        printf("%d ",p->data);
        display(p->next);
    }

    // printing reverse
    // if(p!=0)
    // {
    //     printf("%d -> ",p->data);
    //     display(p->next);
    // }
}

int getlength(struct Node *p)
{
    // int count = 0;
    // while(p!=0)
    // {
    //     count++;
    //     p=p->next;
    // }
    // return count;
    
     if(p == 0)
        return 0;
    else
        return getlength(p->next)+1;
}

int sum(struct Node *p){
      if(p==0)
        return 0;
    else
        return sum(p->next)+p->data;
}

int max_num(struct Node *p){
    int max = INT_MIN;
    // while(p!=0)
    // {
    //     if(p->data>max)
    //     {
    //         max = p->data;
    //         p=p->next;
    //     }
    // }
    // return max;
    
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
    int x=0;
   
    if(p==0)
        return max;
    x = max_num(p->next);
    return x>p->data? x : p->data;
    
}

struct Node * lsearch(struct Node *p, int key)
{   
    // Move to head
    struct Node *q = NULL;
    while(p!=0)
    {
        if( key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    //iterative
    // while(p!=0)
    // {
    //     if(key == p->data)
    //         return p;
    //     p=p->next;
    //     else
    //         return 0;
    // }

    //recursive

//     if( p==0)
//         return 0;
//     return lsearch(p->next,key);
}

void insert(struct Node *p,int data, int pos){

     struct Node *t;

     if(pos < 0 || pos > getlength(p))
        return ;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(pos == 0)
    {
        t->next=first;
        first = t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
void sorted_insert(struct Node *p,int x)
{
    struct Node *t,*q=0;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=0;

    if(first == 0)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}

int delete(struct Node *p,int index)
{
    struct Node *q;
    int x=-1,i;

    if(index <1 && index > getlength(p))
        return -1;

    q=(struct Node *)malloc(sizeof(struct Node));
    if(index == 1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next
        x=p->data;
        free(p);
        return x;

    }

}

int  is_sorted(struct Node *p){
    int x=MIN_INT;

    while(p!=0)
    {
        if(x>p->data)
            return false;
        else
            x=p->data;
            p=p->next;
    }
    return true;
}

void rmv_dup(struct Node *p)
{
    struct Node *q=p->next;

    while(q != 0)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

// array
void reverse1(struct Node *p)
{ 
    int *A,i=0;

    struct Node *q;
    A=(int *)malloc(sizeof(int));

    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void reverse3(struct Node *p,struct Node *q)
{
    
    if(p!=0)
    {
        reverse(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void concat(struct Node *p,struct Node *q){
    p=first;
    q=first;
    while(p->next!=0)
    {
        p=p->next;
    }
    p->next=q;

}



int main ()
{
    int a[] = {3,4,5,6,7,8};
    
    create(a,6);
    
    printf("\nThe length of linked list is: %d\n",getlength(first));
    printf("The sum of linked list is: %d\n",sum(first));
    printf("The max of linked list is: %d\n",max_num(first));
     
    s

    temp = lsearch(first,8);
    if(temp)
        printf("The key found on the linked list is: %d\n",temp->data);
    else
        printf("key not found");
    
    display(first);

    return 0;
}
```
