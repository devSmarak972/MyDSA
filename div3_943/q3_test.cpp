#include <iostream>
#include <vector>
#include <random>

// Function to generate a random integer between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Function to generate a test case
void generateTestCase() {
    int n = generateRandomNumber(2, 500); // Number of elements in a
    std::cout << n << std::endl; // Output number of elements
    
    // Output n-1 elements
    for (int i = 0; i < n - 1; ++i) {
        std::cout << generateRandomNumber(1, 500) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int t = 10000; // Number of test cases
    std::cout << t << std::endl; // Output number of test cases
    
    for (int i = 0; i < t; ++i) {
        generateTestCase(); // Generate each test case
    }
    
    return 0;
}
