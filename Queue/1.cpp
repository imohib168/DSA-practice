#include <iostream>
using namespace std;

int const size = 20;
int front = -1;
int rare = -1;
int arr[size];

void printQueue() {
    for(int i = front + 1; i < rare + 1; i++) {
        cout << arr[i] << " ";
    }
}

int isFull() {
    if(rare == size - 1) return 1;
    return 0;
}

int isEmpty() {
    if(front == rare) return 1;
    return 0;
}

void enqueue(int value) {
    if(isFull()) {
        cout << "\nQueue Overflow" << endl;
    } else {
        rare++;
        arr[rare] = value;
    }
}

int dequeue() {
    int a = -1;
    if(isEmpty()) {
        cout << "\nQueue Empty" << endl;
    } else {
        front++;
        a = arr[front];
    }
    return a;
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printQueue();
    
    dequeue();
    cout << endl;
    printQueue();

    dequeue();
    cout << endl;
    printQueue();

    dequeue();
    cout << endl;
    printQueue();

    dequeue();
    cout << endl;
    printQueue();

    return 0;
}