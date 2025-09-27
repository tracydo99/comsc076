#include <iostream>

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        // Recursion, multiply the base by the result of raising it to (exponent - 1)
        return base * power(base, exponent - 1);
    }
}

int main() {
    int base, exponent;

    std::cout << "Enter a number: ";
    std::cin >> base;

    std::cout << "Enter an exponent (must be a positive number): ";
    std::cin >> exponent;

    // Call the power function and store the result
    int result = power(base, exponent);

    std::cout << base << " to the power of " << exponent << " is " << result << "." << std::endl;

    return 0;
}
