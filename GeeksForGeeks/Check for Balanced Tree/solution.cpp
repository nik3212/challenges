/*

Check for Balanced Tree

Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

*/

/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    private:
        int height(Node *root) {
            if (root == nullptr) { return 0; }
            
            int l = height(root->left);
            int r = height(root->right);
            
            return 1 + max(l, r);
        }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        if (root == nullptr) { return true; }
        
        bool l = isBalanced(root->left);
        
        if (l == false) {
            return false;
        }
    
        bool r = isBalanced(root->right);

        if (r == false) {
            return false;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if (abs(lh - rh) > 1) {
            return false;
        } else {
            return true;
        }
    }
};