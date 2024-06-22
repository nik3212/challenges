/*

Populating Next Right Pointers in Each Node

A perfect binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.

Given a perfect binary tree which contains an extra next pointer in all the node, populate the next pointers of each node to its next right node.

In nodes with no right nodes, set next to null.

*/

/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    Node* next;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
        this->data = data;
    }
};
*/

void connect(Node* root) {
	std::queue<Node*> q;
	q.push(root);
	
	while (!q.empty()) {
		int level = q.size();
		
		std::vector<Node*> nodes;

		while (level--) {
			Node *u = q.front();
			q.pop();
			
			if (u->left) {
				q.push(u->left);
				nodes.push_back(u->left);
			}
			
			if (u->right) {
				q.push(u->right);
				nodes.push_back(u->right);
			}
		}
		
		if (nodes.size() > 1) {
			for (int i = 0; i < nodes.size() - 1; ++i) {
				nodes[i]->next = nodes[i + 1];
			}
		}
	}
}