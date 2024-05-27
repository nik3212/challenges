/*

Maximum Depth of Binary Tree

Given a binary tree, return its maximum depth.

The depth of a binary tree is the number of nodes from the root node to any of the leaf nodes. The maximum depth is the maximum of the depths across all the paths.

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

int getMaxDepth(Node* root) {
    if (root == nullptr) { return 0; }
	
	int l = 1 + getMaxDepth(root->left);
	int r = 1 + getMaxDepth(root->right);
	
	return std::max(l, r);
}