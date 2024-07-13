/*

Lowest Common Ancestor in BST

The lowest common ancestor of two nodes p and q is the lowest node in the binary search tree that has both p and q as its descendants. A node is also considered a descendant of itself.

Given the root node and two nodes p and q in a binary search tree, return their lowest common ancestor.

Note: You can assume that p and q will be present in t

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
    if (root == nullptr || root == p || root == q) { return root; }
	
	Node *l = lowestCommonAncestor(root->left, p, q);
	Node *r = lowestCommonAncestor(root->right, p, q);
	
	if (l == nullptr) {
		return r;
	} else if (r == nullptr) {
		return l;
	} else {
		return root;
	}
}