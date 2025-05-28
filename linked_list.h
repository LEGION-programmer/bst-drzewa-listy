#pragma once
#include <iostream>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(const T& val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    bool search(const T& val) {
        Node* current = head;
        while (current) {
            if (current->data == val) return true;
            current = current->next;
        }
        return false;
    }

    void remove(const T& val) {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            if (current->data == val) {
                if (prev)
                    prev->next = current->next;
                else
                    head = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    ~LinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};