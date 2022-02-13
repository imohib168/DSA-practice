#include <iostream>
using namespace std;

int const size = 5;
int front = 0;
int rare = 0;
int arr[size];

int isFull() {
    if((rare + 1) % size == front) return 1;
    return 0;
}

int isEmpty() {
    if(front == rare) return 1;
    return 0;
}

void circularEnqueue(int value) {
    if(isFull()) {
        cout << "\nQueue Overflow" << endl;
    } else {
        rare = (rare+1) % size;
        arr[rare] = value;
        cout << "Element enqueued: " << value << endl;
    }
}

int circularDequeue() {
    int a = -1;
    if(isEmpty()) {
        cout << "\nQueue Empty" << endl;
    } else {
        front = (front+1) % size;
        a = arr[front];
    }
    return a;
}

int main() {

    circularEnqueue(10);
    circularEnqueue(20);
    circularEnqueue(20);
    circularEnqueue(20);

    circularDequeue();
    circularDequeue();
    circularDequeue();
    circularDequeue();

    circularEnqueue(40);
    circularEnqueue(70);
    circularEnqueue(70);
    circularEnqueue(70);


    return 0;
}