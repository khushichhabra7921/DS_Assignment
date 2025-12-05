int sizeDLL() {
    Node* p = head;
    int count = 0;
    while (p) count++, p = p->next;
    return count;
}

int sizeCLL() {
    if (!chead) return 0;
    int count = 0;
    CNode* p = chead;

    do {
        count++;
        p = p->next;
    } while (p != chead);

    return count;
}
