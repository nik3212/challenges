/*

Balanced Binary Tree

A binary tree is considered balanced if the difference between the heights of the left and the right subtree is not more than 1 for any given node.

Given the root node of a binary tree, determine whether it's height balanced.

*/

/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

bool check_balance(Node *root, int& height) {
	if (root == nullptr) { 
		height = 0;
		return true;
	}
	
	int lh = 0;
	int rh = 0;
	
	bool lv = check_balance(root->left, lh);
	bool rv = check_balance(root->right, rh);
	
	height = 1 + std::max(lh, rh);
	
	if (abs(lh - rh) > 1) {
		return false;
	}
	
	return lv && rv;
}

bool isBinaryTreeBalanced(Node* root) {
	int height = 0;
	return check_balance(root, height);
}