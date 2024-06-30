/*

Maximum Path Sum of Binary Tree

A path between two nodes p and q is defined as a sequence of nodes encountered while travelling from node p to node q (or vice-versa) via parent-child connections. The path does not need to pass through the root node. The sum of the values of all these nodes in the path is considered as the path sum.

A binary tree can have multiple paths depending on the number of nodes. Thus, the path with the maximum sum is considered the maximum path sum for the tree. Note that the path can be empty, i.e. contain no nodes.

Given the reference to the root node of a binary tree, return its maximum path sum.

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

int res = INT_MIN;

int sum(Node *root) {
	if (root == nullptr) { return 0; }
	
	int l = std::max(sum(root->left), 0);
	int r = std::max(sum(root->right), 0);
	
	int v = root->data + std::max(l, r);
	
	res = std::max(res, root->data + l + r);
		
	return v;
}

int maxPathSum(Node *root) {
	res = INT_MIN;
    sum(root);
	return res;
}