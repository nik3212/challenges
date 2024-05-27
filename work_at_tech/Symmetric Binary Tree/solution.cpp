/*

Symmetric Binary Tree

A binary tree is considered symmetric if it is a mirror image of itself, i.e, it is symmetric around its root node.

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

bool isSymmetric(Node* root1, Node* root2) {
	if (root1 == nullptr && root2 == nullptr) {
		return true;
	}

	if (root1 == nullptr || root2 == nullptr) {
		return false;
	}
	
	if (root1->data != root2->data) {
		return false;
	}

	return isSymmetric(root1->left, root2->right) 
		&& isSymmetric(root1->right, root2->left);
}

bool isSymmetric(Node* root) {
    if (root == nullptr) { return true; }
	return isSymmetric(root->left, root->right);
}