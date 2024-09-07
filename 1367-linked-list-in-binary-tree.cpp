#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
private:
    bool dfs(ListNode* head, TreeNode* node) {
        if (!head) return true;
        if (!node) return false;
        if (head->val == node->val) {
            return dfs(head->next, node->left) || dfs(head->next, node->right);
        }
        return false;
    }
};

ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(1);
    return root;
}

int main() {
    Solution solution;
    ListNode* head = createLinkedList({4, 2, 1});
    TreeNode* root = createBinaryTree();

    bool result = solution.isSubPath(head, root);
    std::cout << "Is subpath: " << (result ? "Yes" : "No") << std::endl;

    delete head->next->next;
    delete head->next;
    delete head;

    delete root->right->left->left;
    delete root->right->left;
    delete root->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
