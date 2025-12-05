struct CNode {
    int data;
    CNode* next;
};

CNode* chead = NULL;

CNode* createCNode(int x) {
    CNode* temp = new CNode();
    temp->data = x;
    temp->next = temp;
    return temp;
}

// Insert at end
void insertC(int x) {
    CNode* temp = createCNode(x);

    if (!chead) {
        chead = temp;
        return;
    }
    CNode* p = chead;
    while (p->next != chead) p = p->next;

    p->next = temp;
    temp->next = chead;
}

// Delete a value
void deleteC(int val) {
    if (!chead) return;

    CNode *p = chead, *prev = NULL;

    // delete head
    if (chead->data == val) {
        if (chead->next == chead) {
            delete chead;
            chead = NULL;
            return;
        }
        CNode* last = chead;
        while (last->next != chead) last = last->next;

        last->next = chead->next;
        CNode* temp = chead;
        chead = chead->next;
        delete temp;
        return;
    }

    // delete middle node
    while (p->next != chead && p->data != val) {
        prev = p;
        p = p->next;
    }

    if (p->data == val) {
        prev->next = p->next;
        delete p;
    }
}

// Search in CLL
void searchC(int val) {
    if (!chead) return;
    CNode* p = chead;
    int pos = 1;

    do {
        if (p->data == val) {
            cout << "Found at pos " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    } while (p != chead);

    cout << "Not found\n";
}
