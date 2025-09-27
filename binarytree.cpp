#include <iostream>
#include <stack>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    // Insert a new value into the BST
    void insert(int val) {
        root = insertRec(root, val);
    }

    // Preorder traversal method
    void preorder() {
        if (root == nullptr) return;

        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            std::cout << node->data << " ";
            nodeStack.pop();

            if (node->right) {
                nodeStack.push(node->right);
            }
            if (node->left) {
                nodeStack.push(node->left);
            }
        }
        std::cout << std::endl;
    }

private:
    TreeNode* root;

    // Recursion to insert a value
    TreeNode* insertRec(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else {
            node->right = insertRec(node->right, val);
        }
        return node;
    }
};

int main() {
    BST tree;
    int value;

    std::cout << "Enter 15 integers:" << std::endl;
    for (int i = 0; i < 15; ++i) {
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "Preorder traversal of the binary search tree:" << std::endl;
    tree.preorder();

    return 0;
}
