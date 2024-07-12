/*

Left View of Binary Tree

There are different ways to look at a binary tree. The left view of a binary tree contains the set of nodes that will be visible if you look at the binary tree from the left side.

Given the root node of a binary tree, return an array containing the node elements in the left view, from top to bottom.

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

void left(Node* root, int level, int &max_level, std::vector<int> &v) {
	if (root == nullptr) {
		return;
	}

	if (level > max_level) {
		v.push_back(root->data);
		max_level = level;
	}
	
	left(root->left, level + 1, max_level, v);
	left(root->right, level + 1, max_level, v);
}

vector<int> leftView(Node* root) {
    std::vector<int> v;
	int max_level = 0;

	left(root, 1, max_level, v);

	return v;
}