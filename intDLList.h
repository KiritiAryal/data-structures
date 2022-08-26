#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST


class DLLNode {
public:
 DLLNode() {
 next = prev = 0;
 }
 DLLNode(int const &el, DLLNode *n = 0, DLLNode *p = 0) {
 info = el; next = n; prev = p;
 }
int info;
 DLLNode *next, *prev;
};

class DLList {
public:
 DLList() {
 head = tail = 0;
 }

 void insertHead();
 void insertTail();
 void deleteHead();
 void deleteTail();
 void searchNDelete();
 void printList() const;
 void dispMenu();

private:
 DLLNode *head, *tail;
};
#endif

