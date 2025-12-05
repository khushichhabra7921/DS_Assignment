Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return NULL;
}
