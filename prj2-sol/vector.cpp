#include "vector.h"
#include "errors.h" // Include error handling
#include <iostream> // Include for std::cin, std::cout, std::endl

// Constructor: Initializes a vector of given size
Vector::Vector(size_t size) : size_(size) {
    // Allocate memory for data on the heap
    try {
        data_ = new double[size];
    } catch (const std::bad_alloc& e) {
        // Memory allocation failed, print error and exit
        panic("Memory allocation failed: %s", e.what());
    }
}

// Destructor: Deallocates memory
Vector::~Vector() {
    delete[] data_; // Deallocate memory for data
}

// Reads vector data from standard input
void Vector::read() {
    for (size_t i = 0; i < size_; ++i) {
        if (!(std::cin >> data_[i])) {
            // Error while reading input
            panic("Error: Unable to read vector data.");
        }
    }
}

// Adds another vector to this vector
void Vector::add(const Vector& other, const Vector& sum) {
    for (size_t i = 0; i < size_; ++i) {
        sum.data_[i] = data_[i] + other.data_[i]; // Add corresponding elements and store in sum
    }
}

// Writes vector data to standard output
void Vector::write() const {
    for (size_t i = 0; i < size_; ++i) {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl << std::endl;
}
