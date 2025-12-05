int maxBST(Node* root) {
    while (root->right) root = root->right;
    return root->data;
}
