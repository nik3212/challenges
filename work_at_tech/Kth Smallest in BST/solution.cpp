/*

Kth Smallest in BST

Given the root node of a binary search tree and a number k, find out the kth smallest element (1-indexed) in the BST.

Note: You can assume that k <= number of nodes.

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

int c = 0;

Node *find(Node *root, int k) {
	if (root == nullptr) { return nullptr; }
	
	Node* n = find(root->left, k);
	
	if (n != nullptr) {
		return n;
	}
	
	c++;
	
	if (k == c) {
		return root;
	}
	
	return find(root->right, k);
}

int findKthSmallest(Node* root, int k) {
	c = 0;
	Node *n = find(root, k);
	return n->data;
}