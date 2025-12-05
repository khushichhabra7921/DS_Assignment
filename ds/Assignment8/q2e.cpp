Node* inorderPredecessor(Node* root, Node* target) {
    Node* pre = NULL;

    while (root) {
        if (target->data > root->data) {
            pre = root;
            root = root->right;
        } else root = root->left;
    }
    return pre;
}
