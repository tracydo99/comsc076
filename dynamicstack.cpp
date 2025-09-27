#include <iostream>
#include <string>

using namespace std;

class StringStack {
private:
    struct StackNode {
        string value;
        StackNode *next;
    };
    StackNode *top;

public:
    StringStack() {
        top = nullptr;
    }

    ~StringStack() {
        StackNode *nodePtr, *nextNode;
        nodePtr = top;
        while (nodePtr != nullptr) {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    void push(string str) {
        StackNode *newNode = new StackNode;
        newNode->value = str;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "The stack is empty.\n";
        } else {
            StackNode *temp = top;
            top = top->next;
            delete temp;
        }
    }

    string peek() const {
        if (isEmpty()) {
            cout << "The stack is empty.\n";
            return "";
        } else {
            return top->value;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    StringStack stack;
    string input;
    char choice;

    do {
        cout << "Enter a string to push onto the stack: ";
        getline(cin, input);
        stack.push(input);

        cout << "Do you want to enter another string? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    cout << "\nTop of the stack: " << stack.peek() << endl;

    cout << "\nPopping the stack...\n";
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
    cout << "\nThe stack is now empty.\n";

    return 0;
}
