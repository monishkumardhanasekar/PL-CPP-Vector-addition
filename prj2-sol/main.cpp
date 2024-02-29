#include "vector.h"
#include "errors.h" // Include error handling
#include <string>    // Include for std::stoi
#include <stdexcept> // Include for std::invalid_argument and std::out_of_range


int main(int argc, const char* argv[]) {
    if (argc != 3) {
        panic("Usage: %s N_OPS N_ENTRIES", argv[0]);
    }

    int N_OPS;
    int N_ENTRIES;
    try {
        N_OPS = std::stoi(argv[1]); // Convert the first argument to an integer
        N_ENTRIES = std::stoi(argv[2]); // Convert the second argument to an integer
    } catch (const std::invalid_argument& e) {
        panic("Invalid argument provided: %s", e.what());
    } catch (const std::out_of_range& e) {
        panic("Argument out of range: %s", e.what());
    }

    for (int op = 0; op < N_OPS; ++op) {
        Vector* vector1;
        Vector* vector2;
        Vector* sum_vector; // New vector to hold the sum

        try {
            vector1 = new Vector(N_ENTRIES); // Create a new Vector object
            vector2 = new Vector(N_ENTRIES); // Create another new Vector object
            sum_vector = new Vector(N_ENTRIES); // Create a new Vector object for the sum

            vector1->read();    // Read input values into the first vector
            vector2->read();    // Read input values into the second vector

            vector1->add(*vector2, *sum_vector); // Add the vectors and store the result in the sum vector

            sum_vector->write(); // Write the sum vector to standard output
        } catch (const std::bad_alloc& e) {
            panic("Memory allocation failed: %s", e.what());
        } catch (const std::exception& e) {
            panic("Error during vector operation: %s", e.what());
        }

        delete vector1; // Deallocate memory for the first vector
        delete vector2; // Deallocate memory for the second vector
        delete sum_vector; // Deallocate memory for the sum vector
    }

    return 0;
}
