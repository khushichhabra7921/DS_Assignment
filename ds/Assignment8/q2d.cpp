Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = NULL;

    while (root) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}
