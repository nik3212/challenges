/*

Inorder Successor in BST

Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

*/

class Solution {
private:
    Node* tree_min(Node* root) {
        Node* x = root;
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x) {
        if (x->right != nullptr) {
            return tree_min(x->right);
        }

        Node* y = nullptr;

        while (root != nullptr) {
            if (root->data > x->data) {
                y = root;
                root = root->left;
            } else if (root->data < x->data) {
                root = root->right;
            } else {
                break;
            }
        }

        return y;
    }
};