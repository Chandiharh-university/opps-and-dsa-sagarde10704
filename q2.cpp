#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findPaths(TreeNode* root, string path, vector<string>& paths) {
    if (!root) return;
    path += to_string(root->val);
    if (!root->left && !root->right)
        paths.push_back(path);
    else {
        path += "->";
        findPaths(root->left, path, paths);
        findPaths(root->right, path, paths);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    findPaths(root, "", paths);
    return paths;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> result = binaryTreePaths(root);
    for (string path : result)
        cout << path << endl;

    return 0;
}
