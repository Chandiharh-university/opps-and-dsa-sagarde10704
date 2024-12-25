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

Node* lca(Node* root, int n1, int n2) {
    if (root == nullptr)
        return nullptr;
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);

    int n1 = 10, n2 = 14;
    Node* t = lca(root, n1, n2);
    if (t != nullptr)
        cout << "LCA of " << n1 << " and " << n2 << " is " << t->data;
    else
        cout << "LCA does not exist";
    
    return 0;
}
