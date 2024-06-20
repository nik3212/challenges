/*

Binary Tree Zigzag Level Order Traversal

There are different ways to traverse a binary tree. The zigzag level order traversal of a binary tree covers all the nodes of the tree such that each level is traversed left to right or right to left alternatively.

Given the root node of a binary tree, return an array depicting the zigzag level order traversal.

Note: The first level is traversed left to right.

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

vector<int> zigzagLevelOrderTraversal(Node* root) {
    std::queue<Node*> q;
	std::vector<int> res;

	q.push(root);
	
	bool flag = false;
	
	while (!q.empty()) {
		int level = q.size();
		
		std::vector<int> tmp;
		
		while (level--) {
			Node* u = q.front();
			q.pop();
			
			tmp.push_back(u->data);
			
			if (u->left != nullptr) {
				q.push(u->left);
			}
			
			if (u->right != nullptr) {
				q.push(u->right);
			}
		}
		
		if (flag) {
			std::reverse(tmp.begin(), tmp.end());
		}
		
		flag = !flag;
		
		res.insert(std::end(res), std::begin(tmp), std::end(tmp));
	}
	
	return res;
}