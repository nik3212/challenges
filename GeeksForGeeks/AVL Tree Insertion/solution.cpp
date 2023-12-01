/*

AVL Tree Insertion

Given an AVL tree and N values to be inserted in the tree. Write a function to insert elements into the given AVL tree.

Note:
The tree will be checked after each insertion. 
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
If instead all insertions are successful, inorder traversal of the tree will be printed.

*/

/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
private:
    int height(Node *root) {
        return (root == nullptr) ? 0 : root->height;
    }

    int balance_factor(Node *root) {
        return height(root->right) - height(root->left);
    }

    void fix_height(Node *root) {
        int left = height(root->left);
        int right = height(root->right);

        root->height = max(left, right) + 1;
    }

    Node* rotate_right(Node *root) {
        Node *l = root->left;
        root->left = l->right;
        l->right = root;
        fix_height(root);
        fix_height(l);
        return l;
    }
    
    Node* rotate_left(Node *root) {
        Node *r = root->right;
        root->right = r->left;
        r->left = root;
        fix_height(root);
        fix_height(r);
        return r;
    }

    Node* balance(Node *root) {
        fix_height(root);
        
        if (balance_factor(root) == 2) {
            if (balance_factor(root->right) < 0) {
                root->right = rotate_right(root->right);
            }
            return rotate_left(root);
        } else if (balance_factor(root) == -2) {
            if (balance_factor(root->left) > 0) {
                root->left = rotate_left(root->left);
            }
            return rotate_right(root);
        }
        
        return root;
    }
 public:
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        } else if (node->data > data) {
            node->left = insertToAVL(node->left, data);
        } else {
            node->right = insertToAVL(node->right, data);
        }

        return balance(node);
    }
};