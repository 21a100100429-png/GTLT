#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Stack {
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* top;
    int count;

    Stack() : top(nullptr), count(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack rong!");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            temp->data.xuat();
            temp = temp->next;
        }
    }

    T* toArray(int& n) const {
        n = count;
        if (n == 0) return nullptr;

        T* arr = new T[n];
        Node* temp = top;
        for (int i = 0; i < n; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }
        return arr;
    }

    void fromArray(T* arr, int n) {
        while (!isEmpty()) pop();
        for (int i = n - 1; i >= 0; i--) {
            push(arr[i]);
        }
    }
};

#endif