#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstddef> // Needed for size_t

class Vector {
public:
    // Constructor to create a Vector object with a specified size
    Vector(size_t size);

    // Destructor to clean up resources when the Vector object is destroyed
    ~Vector();

    // Reads input values from standard input into the vector
    void read();

    // Adds elements of another Vector to this Vector element-wise
    void add(const Vector& other);

    // Writes the elements of the vector to standard output
    void write() const;

private:
    size_t size_;    
    double* data_;   
};

#endif // VECTOR_H_
