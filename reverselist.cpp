#include <iostream>
#ifndef Numberlist_H
#define Numberlist_H

class LinkedList
{
private:
    struct ListNode
    {
        double value;
        struct ListNode *next;
    };
    ListNode *head;

public:
    LinkedList() { head = nullptr; }
    ~LinkedList() {
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
    void reverse();
};

#endif

void LinkedList::appendNode(double num) {
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

void LinkedList::insertNode(double num) {
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

void LinkedList::deleteNode(double num) {
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

void LinkedList::displayList() const {
    ListNode* nodePtr = head;
    while (nodePtr) {
        std::cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}

void LinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    LinkedList list;

    list.appendNode(1.1);
    list.appendNode(3.3);
    list.appendNode(5.5);
    list.appendNode(7.7);
    list.appendNode(9.9);

    std::cout << "Original list: ";
    list.displayList();

    list.reverse();

    std::cout << "Reversed list: ";
    list.displayList();

    return 0;
}
