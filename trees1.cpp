#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void preorderTraversal(Node* node) {
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void inorderTraversal(Node* node) {
    if (node == nullptr)
        return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
    if (node == nullptr)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    
    cout << "\nInorder traversal: ";
    inorderTraversal(root);

    cout << "\nPostorder traversal: ";
    postorderTraversal(root);

    return 0;
}
