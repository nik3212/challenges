/*

Inorder Successor of Node in BST

The inorder successor of a node p is the node q that comes just after p in the binary tree's inorder traversal.

Given the root node of a binary search tree and the node p, find the inorder successor of node p. If it does not exist, return null.

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

Node *min(Node* root) {
	if (root->left == nullptr) {
		return root;
	}
	return min(root->left);
}

Node* findSuccessor(Node* root, Node* p) {
    if (p->right != nullptr) {
		return min(p->right);
	}
	
	Node *curr = root;
	Node *prev = nullptr;

	while (curr) {
		if (curr->data > p->data) {
			prev = curr;
			curr = curr->left;
		} else if (curr->data < p->data) {
			curr = curr->right;
		} else {
			break;
		}
	}
	
	return prev;
}