#include <iostream>
#include <string>

void printReverse(const std::string &str, int index) {
    if (index < 0) {
        return;
    }
    std::cout << str[index];
    printReverse(str, index - 1);
}

int main() {
    std::string input;
    std::cout << "Enter a sentence or string: ";
    std::getline(std::cin, input);

    std::cout << "The string in reverse: ";
    printReverse(input, input.length() - 1);
    std::cout << std::endl;

    return 0;
}
