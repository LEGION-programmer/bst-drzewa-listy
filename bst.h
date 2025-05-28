#pragma once
#include <iostream>

template<typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insert(Node*& node, const T& val) {
        if (!node)
            node = new Node(val);
        else if (val < node->data)
            insert(node->left, val);
        else
            insert(node->right, val);
    }

    bool search(Node* node, const T& val) const {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    Node* remove(Node* node, const T& val) {
        if (!node) return nullptr;
        if (val < node->data)
            node->left = remove(node->left, val);
        else if (val > node->data)
            node->right = remove(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = node->right;
            while (temp->left)
                temp = temp->left;
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& val) { insert(root, val); }

    bool search(const T& val) const { return search(root, val); }

    void remove(const T& val) { root = remove(root, val); }

    ~BST() { clear(root); }
};