bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* left = head;
    Node* right = head;

    while (right->next) right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}
