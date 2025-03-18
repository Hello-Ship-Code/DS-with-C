#include <stdio.h>

int main() {
    int a = 10;      // Declare and initialize an integer variable
    int *p;          // Declare a pointer to an integer

    p = &a;          // Initialize the pointer to the address of 'a'
    
    printf("%d\n", a);  // Print the value of 'a'
    printf("%d\n", *p); // Dereference the pointer to print the value at the address stored in 'p'
    
    return 0;        // Return 0 to indicate successful execution
}