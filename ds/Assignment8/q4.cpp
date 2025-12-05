bool isBST(Node* root, long minV = LONG_MIN, long maxV = LONG_MAX) {
    if (!root) return true;

    if (root->data <= minV || root->data >= maxV) return false;

    return isBST(root->left, minV, root->data) &&
           isBST(root->right, root->data, maxV);
}
