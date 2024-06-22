/*

Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its elements.

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

void inorder(Node *root, std::vector<int> &v) {
	if (root) {
		inorder(root->left, v);
		v.push_back(root->data);
		inorder(root->right, v);
	}
}

vector<int> getInorderTraversal(Node* root) {
    std::vector<int> v;
	inorder(root, v);
	return v;
}