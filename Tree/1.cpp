#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
    
    Node(int data) {
        this -> data = data; 
        left = NULL;
        right = NULL;
    }
};

// 1) pre-order traversal <Root> <left> <right>
void preOrderTraversal(Node *head) {
    if(head == NULL) return; 
    cout << head -> data << " ";
    preOrderTraversal(head -> left);
    preOrderTraversal(head -> right);
}

// 2) post-order traversal <left> <right> <Root>
void postOrderTraversal(Node *head) {
    if(head == NULL) return; 
    postOrderTraversal(head -> left);
    postOrderTraversal(head -> right);
    cout << head -> data << " ";
}
// 3) in-order traversal <left> <Root> <right>
void inOrderTraversal(Node *head)  {
    if(head == NULL) return; 
    inOrderTraversal(head -> left);
    cout << head -> data << " ";
    inOrderTraversal(head -> right);
}

int main() {
    Node *root = new Node(4);
    
    Node *child1 = new Node(1);
    Node *child2 = new Node(6);

    Node *child3 = new Node(5);
    Node *child4 = new Node(2);

    root -> left = child1;
    root -> right = child2;

    child1 -> left = child3;
    child1 -> right = child4;

    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root); 
    cout << endl;
    inOrderTraversal(root); 

    return 0;
}