#include <iostream>
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
    struct ListNode
    {
        double value;
        struct ListNode *next;
    };
    ListNode *head;

public:
    NumberList() { head = nullptr; }
    ~NumberList() {
        ListNode* nodePtr = head;
        while (nodePtr != nullptr) {
            ListNode* garbage = nodePtr;
            nodePtr = nodePtr->next;
            delete garbage;
        }
    }
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList() const;
    void mergeArray(double[], int);
};

#endif

void NumberList::appendNode(double num) {
    ListNode* newNode = new ListNode;
    ListNode* nodePtr;
    newNode->value = num;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void NumberList::insertNode(double num) {
    ListNode* newNode;
    ListNode* nodePtr;
    ListNode* previousNode = nullptr;
    newNode = new ListNode;
    newNode->value = num;

    if (!head) {
        head = newNode;
        newNode->next = nullptr;
    } else {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->value < num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == nullptr) {
            head = newNode;
            newNode->next = nodePtr;
        } else {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void NumberList::deleteNode(double num) {
    ListNode* nodePtr;
    ListNode* previousNode;

    if (!head) return;

    if (head->value == num) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->value != num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void NumberList::displayList() const {
    ListNode* nodePtr = head;
    while (nodePtr) {
        std::cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}

void NumberList::mergeArray(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        insertNode(arr[i]);
    }
}

int main() {
    NumberList list;
    double arr[] = {7.5, 3.2, 9.8, 1.1, 5.4};
    int size = sizeof(arr) / sizeof(arr[0]);

    list.mergeArray(arr, size);
    std::cout << "Merged list: ";
    list.displayList();

    return 0;
}
