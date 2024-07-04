/*

Lowest Common Ancestor in Binary Tree

The lowest common ancestor of two nodes p and q is the lowest node in the binary tree that has p and q as its descendants.
Note: A node is also considered a descendant of itself.

Given the reference to the root node and two nodes p and q in a binary tree, return the reference to the lowest common ancestor of p and q.

Note: You can assume that p and q will be present in the tree.

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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	if (root == nullptr || root == p || root == q) {
		return root;
	}
	
    Node* l = lowestCommonAncestor(root->left, p, q);
	Node* r = lowestCommonAncestor(root->right, p, q);
	
	if (l == nullptr) {
		return r;
	} else if (r == nullptr) {
		return l;
	} else {
		return root;
	}
}