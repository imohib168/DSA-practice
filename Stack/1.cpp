#include <iostream>
using namespace std;

int const size = 20;
int top = -1;
int arr[size];

int isEmpty() {
    if(top == -1) return 1;
    return 0;
}

int isFull() {
    if(top == size - 1) return 1;
    return 0;
}

void push(int value) {
    if(isFull()) {
        cout << "\nStack Overflow" << endl;
        return;
    }

    top++;
    arr[top] = value;
}

int pop() {
    if(isEmpty()) {
        cout << "\nStack Underflow" << endl;
        return 0;
    }

    int poppedValue = arr[top];
    top--;
    return poppedValue;
}

void printStack() {
    for(int i = 0; i < top + 1; i++) {
        cout << arr[i] << " ";
    }
}

int peek() {
    return arr[top];
}

int main() {

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    cout << "Original Stack" << endl;
    printStack();

    push(6);
    cout << "\nAfter Insertion" << endl;
    printStack();

    // pop();
    // cout << "\nAfter Deletion" << endl;
    // printStack();

    cout << "\nPeek: ";
    cout << peek();

    return 0;
}