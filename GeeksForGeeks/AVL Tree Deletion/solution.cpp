/*

AVL Tree Deletion

Given an AVL tree and N values to be deleted from the tree. 
Write a function to delete a given value from the tree. 
All the N values which needs to be deleted are passed one 
by one as input data by driver code itself, you are asked 
to return the root of modified tree after deleting the 
value.

*/

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

Node* min_node(Node* node) {
    return (node->left == nullptr) ? node : min_node(node->left);
}

Node* remove_min(Node* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = remove_min(node->left);
    return balance(node);
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->data < data) {
        root->right = deleteNode(root->right, data);
    } else if (root->data > data) {
        root->left = deleteNode(root->left, data);
    } else {
        Node *l = root->left;
        Node *r = root->right;
        
        delete root;
        
        if (r == nullptr) {
            return l;
        }
        
        Node *min = min_node(r);
        min->right = remove_min(r);
        min->left = l;
        
        return balance(min);
    }
    
    return balance(root);
}