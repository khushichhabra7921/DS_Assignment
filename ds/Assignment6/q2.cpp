void displayCircular() {
    if (!chead) return;

    CNode* p = chead;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != chead);

    cout << chead->data;
}
