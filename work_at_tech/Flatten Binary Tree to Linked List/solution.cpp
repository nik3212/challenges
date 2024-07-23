/*

Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list.

Flattening a binary tree means that:

- All the right pointers should point to the next node.
- All the left pointers should point to null.
- The linked list should be in the same order as the preorder traversal of the tree.

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

Node *right(Node *root) {
	while (root->right != nullptr) {
		root = root->right;
	}
	return root;
}

void flatten(Node* root) {
	Node *curr = root;
	
	while (curr != nullptr) {
		while (curr->left) {
			Node *r = right(curr->left);
			r->right = curr->right;
			curr->right = curr->left;
			curr->left = nullptr;
		}

		curr = curr->right;
	}
}