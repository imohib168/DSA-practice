#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

    public:
        Node(int data) {
            this -> data = data;
        }
};

class CustomStack {
    int size = 0;

    public:
        int isEmpty(Node *top) {
            if(top == NULL) return 1;
            return 0;
        }
    
    public:
        int isFull() {
            // Assuming size for the insertion
            if(size == 20) return 1;
            return 0;
        }

    public:
        void traverseStack(Node *top) {
            if(top == NULL) return;

            while(top != NULL) {  
                cout << top->data << " ";  
                top = top->next;  
            } 
            cout << endl;
        }

    public:
        Node *push(Node **top, int value) {
            int isStackFull = isFull();
            if(isStackFull == 1) {
                cout << "\nStack Overflow" << endl;
                return NULL;
            }

            Node *newNode = new Node(value);
            
            if(top == NULL) {
                *top = newNode;
                size++;
                return *top;
            } else {
                newNode -> next = *top;
                *top = newNode;
                size++;
                return *top;
            }
        }

    public:
        Node *pop(Node **top) {
            int isStackEmpty = isEmpty(*top);
            if(isStackEmpty == 1) {
                cout << "\nStack Underflow" << endl;
                return NULL;
            }

            *top = (*top)->next;
            delete(top);
            return *top;
        }
};

int main() {
    CustomStack *CS = new CustomStack();

    Node *top =  NULL;

    CS->push(&top, 10);
    CS->push(&top, 5);
    CS->push(&top, 4);
    CS->push(&top, 50);
    CS->push(&top, 51);
    CS->push(&top, 98);

    CS->traverseStack(top);

    CS->pop(&top);
    CS->traverseStack(top);
    
    return 0;
}