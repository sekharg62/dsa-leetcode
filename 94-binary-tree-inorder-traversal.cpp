#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
private:
    void inorder(TreeNode* node, vector<int>& result) {
        if (!node) return;
        inorder(node->left, result);   // Traverse left subtree
        result.push_back(node->val);   // Visit current node
        inorder(node->right, result);  // Traverse right subtree
    }
};

int main() {
    // Creating a binary tree manually for demonstration:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup
    delete root->left->right;  // Delete node with value 5
    delete root->left->left;   // Delete node with value 4
    delete root->left;         // Delete node with value 2
    delete root->right;        // Delete node with value 3
    delete root;               // Delete node with value 1

    return 0;
}
