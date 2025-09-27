#include <iostream>
#include <fstream>   // For file input and output
#include <set>       // For storing unique words
#include <string>

int main() {
    std::string filename;

    std::cout << "Enter the file name: ";
    std::cin >> filename;

    std::ifstream file(filename);

    if (!file) {
        return 1;
    }

    std::set<std::string> uniqueWords; // Store unique words
    std::string word; // Hold each word in the file

    // Read each word from the file
    while (file >> word) {
        uniqueWords.insert(word); // Insert the word into the set, ignore duplicates
    }

    file.close();

    std::cout << "Unique words:" << std::endl;
    for (const auto& w : uniqueWords) {
        std::cout << w << std::endl;
    }

    return 0;
}
