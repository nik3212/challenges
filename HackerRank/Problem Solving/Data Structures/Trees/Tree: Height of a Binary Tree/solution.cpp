/*

Tree: Height of a Binary Tree

The height of a binary tree is the number of edges between the tree's root and its furthest leaf.

Function Description

Complete the getHeight or height function in the editor. It must return the height of a binary tree as an integer.
getHeight or height has the following parameter(s):
root: a reference to the root of a binary tree.
Note -The Height of binary tree with single node is taken as zero.

Input Format

The first line contains an integer n, the number of nodes in the tree. 
Next line contains n space separated integer where i-th integer denotes node[i].data.
Note: Node values are inserted into a binary search tree before a reference to the tree's root node is passed to your function. In a binary search tree, all nodes on the left branch of a node are less than the node value. All values on the right branch are greater than the node value.

*/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

    int height(Node* root) {
        if (root == nullptr) { return -1; }
        return std::max(height(root->left), height(root->right)) + 1;
    }

}; //End of Solution