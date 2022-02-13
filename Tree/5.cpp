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

// Level of a Node
int getLevelOfNode(Node *root, int key, int level) {
    if(root == NULL) return 0;
    if(root -> data == key) return level;

    int nextLevel = getLevelOfNode(root -> left, key, level + 1);
    if(nextLevel != 0) {
        return nextLevel;
    }

    nextLevel = getLevelOfNode(root -> right, key, level + 1);
    return nextLevel;
}

int getLevel(Node *root, int key) {
    int level = 1;
    return getLevelOfNode(root, key, level);
}

// Height of tree
int Height(Node *root) {
    if(root == NULL) return 0;

    int rightHeight = Height(root -> right);
    int leftHeight = Height(root -> left);

       if (leftHeight > rightHeight) {
           return(leftHeight+1);
       } else {
            return(rightHeight+1);
       }
}

// Delete Node in BST
Node *inOrderPrecessor(Node *root) {
    // inOrderPrecessor = Right most child of left subtree
    root = root -> left;
    while(root -> right != NULL) {
        root = root -> right;
    }
    return root;
}

Node *deleteNode(Node *root, int value) {
    Node *iPre = NULL;
    if(root == NULL) {
        return NULL;
    }

    // Incase if root node is leaf node
    if(root -> left == NULL && root -> right == NULL) {
        free(root);
        return NULL;
    }

    // Breaking the tree
    if(value < root -> data) {
        root -> left = deleteNode(root -> left, value);
    } else if(value > root -> data) {
        root -> right = deleteNode(root -> right, value);
    } else {
        // Incase if the root of subtree is supposed to be deleted
        iPre = inOrderPrecessor(root);
        root ->data = iPre -> data;
        root -> left = deleteNode(root -> left, iPre -> data);
    }

    return root;
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

    // Node *found = searchIterative(root, 7);
    // if(found != NULL) {
    //     cout << "\nNode found with key '" << found -> data << "'" << endl;
    // } else {
    //     cout << "\nNot found" << endl;
    // }

    // int level = getLevel(root, 7);
    // if (level) {
    //     cout << "Level of "<< 7 << " is " << getLevel(root, 7) << endl;
    // } else {
    //     cout << 7 << "is not present in tree" << endl;
    // }

    // cout << Height(root);

    Node *deletedNode = deleteNode(root, root -> data);
    if(deletedNode != NULL) {
        cout << "\nNode sucessfully deleted" << endl;
    } else {
        cout << "\nNode not found" << endl;
    }

    inOrderTraversal(root);

    return 0;
}  