bool isCircular(Node* head) {
    if (!head) return false;

    Node* p = head->next;

    while (p && p != head)
        p = p->next;

    return p == head;
}
