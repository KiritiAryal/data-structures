#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
class IntSLLNode {
public:
 IntSLLNode() {
 next = 0;
 }
 IntSLLNode(int el, IntSLLNode *ptr = 0) {
 info = el; next = ptr;
 }
 int info;
 IntSLLNode *next;
};
class IntSLList {
public:
 IntSLList() {
 head = tail = 0;
 }
 ~IntSLList();
 int isEmpty() {
 return head == 0;
 }
 void insertHead();
 void insertTail();
 void deleteHead();
 void deleteTail(); 
 void searchNDelete();
 void printList() const;
 void dispMenu();
 bool isInList(int) const;
 private:
 IntSLLNode *head, *tail;
};
#endif
