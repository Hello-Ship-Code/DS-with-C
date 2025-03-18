#include <stdio.h>
#include <iostream>

using namespace std;

// Rectangle structure definition
struct Rectangle {
    int length;
    int breadth;
    char x; // Extra variable to demonstrate structure padding and memory size
};

int main() {
    // Declaration and Initialization
    struct Rectangle r1 = {10, 5};

    // Displaying the size of the structure
    printf("Size of r1: %lu bytes\n", sizeof(r1));

    // Accessing structure members
    cout << "Initial Length: " << r1.length << endl;
    cout << "Initial Breadth: " << r1.breadth << endl;

    // Modifying structure members
    r1.length = 15;
    r1.breadth = 7;

    // Displaying modified values
    printf("Modified Length: %d\n", r1.length);
    printf("Modified Breadth: %d\n", r1.breadth);

    // Calculating and displaying the area
    printf("Area of rectangle: %d\n", r1.length * r1.breadth);

    return 0;
}