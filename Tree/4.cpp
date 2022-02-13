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

// Is Binary search tree
int isBST(Node *root) {
    static Node *prev = NULL;
    if(root != NULL) {
        if(!isBST(root -> left)) {
            return 0;
        }
        if(prev != NULL && root -> data <= prev -> data) {
            return 0;
        }
        prev = root;
        return isBST(root -> right);
    } else {
        return 1;
    }
}

// Search in BST
Node *search(Node *root, int key) {
    if(root == NULL) return NULL;

    if(root -> data == key) return root;
    else if(root -> data > key) return search(root -> left, key);
    else return search(root -> right, key);
}

// Search Node in an iterative way
Node *searchIterative(Node *root, int key) {
    while(root != NULL) {
        if(root -> data == key) return root;
        else if(root -> data > key) root = root -> left;
        else if(root -> data < key) root = root -> right;
    }
    return NULL;
}

// Insert a node in BST  
void insert(Node *root, int key) {
    Node *prev = NULL; 
    while(root != NULL) {
        prev = root;
        if(key == root -> data) {
            cout << "Can't insert..." << endl;
            return;
        } else if(key > prev -> data) {
            root = root -> right;
        } else {
            root = root -> left;
        }
    }
    Node *newNode = new Node(key);
    if(key < prev -> data) { 
        prev -> left = newNode;
    } else {
        prev -> right = newNode;
    }
}

int main() {
    Node *root = new Node(5);
    
    Node *child1 = new Node(3);
    Node *child2 = new Node(6);

    Node *child3 = new Node(1);
    Node *child4 = new Node(4);

    root -> left = child1;
    root -> right = child2;

    child1 -> left = child3;
    child1 -> right = child4;

    insert(root, 2);
    insert(root, 7);
    inOrderTraversal(root);

    Node *found = searchIterative(root, 7);
    if(found != NULL) {
        cout << "\nNode found with key '" << found -> data << "'" << endl;
    } else {
        cout << "\nNot found" << endl;
    }

    return 0;
}  