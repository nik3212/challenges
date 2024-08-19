/*

Serialize and Deserialize Binary Search Tree (BST)

Serialization is the process of translating a data structure or object state into a format that can be stored (for example, in a file or memory data buffer) or transmitted (for example, over a computer network) and reconstructed later (possibly in a different computer environment).

The opposite operation, extracting a data structure from a series of bytes, is deserialization.

Design an algorithm to serialize and deserialize a BST.

The serialize method should return a string. The format of the string does not matter. Try to keep it as compact as possible to avoid getting TLE/MLE.
The deserialize method when provided the serialized string should return the original BST.

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

std::string serialize(Node* root) {
    if (root == nullptr) { return ""; }
    
    std::string s;
    std::queue<Node*> q;
    
    q.push(root);
    
    while (!q.empty()) {
        Node *n = q.front();
        q.pop();
        
        if (n == nullptr) {
            s += "#,";
        } else {
            s += std::to_string(n->data) + ",";
            
            q.push(n->left);
            q.push(n->right);
        }
    }
    
    // Optionally remove the trailing comma
    if (!s.empty()) s.pop_back();
    
    return s;
}

Node* deserialize(std::string serializedTree) {
    if (serializedTree.empty()) { return nullptr; }
    
    std::stringstream ss(serializedTree);
    std::string s;
    
    getline(ss, s, ',');
    
    Node *root = new Node(stoi(s));
    
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node *n = q.front();
        q.pop();
        
        // Left child
        if (getline(ss, s, ',')) {
            if (s != "#") {
                Node *left = new Node(stoi(s));
                n->left = left;
                q.push(left);
            }
        }
        
        // Right child
        if (getline(ss, s, ',')) {
            if (s != "#") {
                Node *right = new Node(stoi(s));
                n->right = right;
                q.push(right);
            }
        }
    }
    
    return root;
}