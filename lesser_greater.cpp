#include <iostream>

template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {

    int intA, intB;

    std::cout << "Enter two integer values:" << std::endl;
    std::cout << "First number: ";
    std::cin >> intA;
    std::cout << "Second number: ";
    std::cin >> intB;

    std::cout << "Lesser: " << minimum(intA, intB) << std::endl;
    std::cout << "Greater: " << maximum(intA, intB) << std::endl;

    float floatA, floatB;

    std::cout << "Enter two float (decimal) values:" << std::endl;
    std::cout << "First number: ";
    std::cin >> floatA;
    std::cout << "Second number: ";
    std::cin >> floatB;

    std::cout << "Lesser: " << minimum(floatA, floatB) << std::endl;
    std::cout << "Greater: " << maximum(floatA, floatB) << std::endl;

    return 0;
}
