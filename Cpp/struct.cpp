#include <iostream>
using namespace std;

// Rectangle class with dynamic memory allocation for flexibility
class Rectangle {
private:
    int* length;   // Pointer for dynamic memory allocation
    int* breadth;  // Pointer for dynamic memory allocation

public:
    // Constructor to initialize length and breadth dynamically
    Rectangle(int l, int b) {
        length = new int(l);   // Memory allocated with initial value l
        breadth = new int(b);  // Memory allocated with initial value b
    }

    // Destructor to clean up dynamically allocated memory
    ~Rectangle() {
        delete length;         // Prevents memory leak
        delete breadth;        // Prevents memory leak
        cout << "Destructor called, memory deallocated" << endl;
    }

    // Function to calculate area
    int area() const {
        return (*length) * (*breadth);
    }

    // Function to calculate perimeter
    int perimeter() const {
        return 2 * ((*length) + (*breadth));
    }

    // Function to display dimensions
    void display() const {
        cout << "Length: " << *length << ", Breadth: " << *breadth << endl;
    }
};

// Structure-based implementation for simpler, non-dynamic allocation
struct RectangleStruct {
    int length;
    int breadth;
};

// Function to initialize structure values
void initialise(RectangleStruct* r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

// Function to calculate area in structure
int areaStruct(RectangleStruct r) {
    return r.length * r.breadth;
}

// Function to calculate perimeter in structure
int perimeterStruct(RectangleStruct r) {
    return 2 * (r.length + r.breadth);
}

int main() {
    int l, b;
    cout << "Enter the length & breadth: ";
    cin >> l >> b;

    // Using class-based implementation
    Rectangle* rect = new Rectangle(l, b);
    rect->display();
    cout << "Area (Class): " << rect->area() << " | Perimeter (Class): " << rect->perimeter() << endl;
    delete rect; // Ensures memory cleanup

    // Using structure-based implementation
    RectangleStruct rStruct;
    initialise(&rStruct, l, b);
    cout << "Area (Struct): " << areaStruct(rStruct) << " | Perimeter (Struct): " << perimeterStruct(rStruct) << endl;

    return 0;
}