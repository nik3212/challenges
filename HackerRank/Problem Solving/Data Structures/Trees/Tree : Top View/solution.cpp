#include<bits/stdc++.h>

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

/*
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

*/

    void topView(Node * root) {
        if (root == nullptr) {
            return;
        }
        
        std::queue<std::pair<int, Node*>> q;
        std::map<int, Node*> ans;

        q.push({ 0, root });
        
        while (!q.empty()) {
            auto i = q.front();
            
            if (i.second != nullptr) {
                ans.insert(i);
                
                q.push(std::make_pair(i.first + 1, i.second->right));
                q.push(std::make_pair(i.first - 1, i.second->left));
            }
            
            q.pop();
        }
        
        for (auto i: ans) {
            std::cout << i.second->data << " ";
        }
    }

}; //End of Solution