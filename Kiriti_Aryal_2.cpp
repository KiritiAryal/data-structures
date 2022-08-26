#include <iostream>
#include <intSLList.h>
#include <intDLList.h>
#include<iomanip>
//using namespace std;

IntSLList :: ~IntSLList() {
	for (IntSLLNode* p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}
void IntSLList::insertHead() {
	std::cout << "Insert an integer: " << std::endl;
	int el;
	std::cin >> el;
	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}
void IntSLList::insertTail() {
	std::cout << "Insert an integer: " << std::endl;
	int el;
	std::cin >> el;
	if (tail != 0) { // if list not empty;
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el);
}
void IntSLList::deleteHead() {
	int el = head->info;
	IntSLLNode* tmp = head;
	if (head == tail) // if only one node in the list;
		head = tail = 0;
	else head = head->next;
	delete tmp;
}
void IntSLList::deleteTail() {
	int el = tail->info;
	if (head == tail) { // if only one node in the list;
		delete head;
		head = tail = 0;
	}
	else { // if more than one node in the list,
		IntSLLNode* tmp; // find the predecessor of tail;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp; // the predecessor of tail becomes tail;
		tail->next = 0;
	}
}
void IntSLList::searchNDelete() {
	std::cout << "Insert an integer: " << std::endl;
	int el;
	std::cin >> el;
	if (head != 0) // if nonempty list;
		if (head == tail && el == head->info) { // if only one
			delete head; // node in the list;
			head = tail = 0;
		}
		else if (el == head->info) {// if more than one node in the list
			IntSLLNode* tmp = head;
			head = head->next;
			delete tmp; // and old head is deleted;
		}
		else { // if more than one node in the list
			IntSLLNode* pred, * tmp;
			for (pred = head, tmp = head->next; // and a nonhead node
				tmp != 0 && !(tmp->info == el);// is deleted;
				pred = pred->next, tmp = tmp->next);
			if (tmp != 0) {
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
}
bool IntSLList::isInList(int el) const {
	IntSLLNode* tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}

void IntSLList::printList() const
{
	IntSLLNode* temp;

	temp = head;
	std::cout << std::endl;
	std::cout << "The list is: ";
	while (temp != 0)
	{
		std::cout << temp->info << " ";
		temp = temp->next;
	}

}

void DLList::insertHead()
{
	int el;
	std::cout << "Insert an integer: " << std::endl;
	std::cin >> el;
	if (head == 0)
	{
		head = tail = new DLLNode(el, head, 0);
	}
	else
	{
		DLLNode* temp = head;
		head = new DLLNode(el, temp, 0);
	}
}
void DLList::insertTail()
{
	int el;
	std::cout << "Insert an integer: " << std::endl;
	std::cin >> el;
	if (head == 0)
	{
		head = tail = new DLLNode(el, 0, tail);
	}
	else {
		tail = new DLLNode(el, 0, tail);
		tail->prev->next = tail;
	}
}
void DLList::deleteHead() {
	if (head != tail) {
		DLLNode* temp = head;
		head = head->next;
		delete temp;
		head->prev = 0;
	}
	else {

		delete head;
		head = tail = 0;
	}
}
void DLList::deleteTail()
{
	if (head != tail)
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	else {
		delete head;
		tail = head = 0;
	}
}
void DLList::searchNDelete() {
	std::cout << "Insert an integer: " << std::endl;
	int el;
	std::cin >> el;
	if (head != 0) // if nonempty list;
		if (head == tail && el == head->info) { // if only one
			delete head; // node in the list;
			head = tail = 0;
		}
		else if (el == head->info) {// if more than one node in the list
			DLLNode* tmp = head;
			head = head->next;
			delete tmp; // and old head is deleted;
		}
		else { // if more than one node in the list
			DLLNode* pred, * tmp;
			for (pred = head, tmp = head->next; // and a nonhead node
				tmp != 0 && !(tmp->info == el);// is deleted;
				pred = pred->next, tmp = tmp->next);
			if (tmp != 0) {
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
}
void IntSLList::dispMenu()
{
	int num;
	std::cout << std::setw(25) << "MENU" << std::endl << std::endl;
	std::cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << std::endl;
	std::cout << "DLL: IH(6), IT(7), DH(8), DT(9). SD(10), PD(11)" << std::endl;
	std::cout << "Exit Program(12)" << std::endl << std::endl;
	std::cout << std::setw(28) << "Choose?" << std::endl;
	std::cin >> num;
	switch (num)
	{
	case 0:
		insertHead();
		dispMenu();
		break;
	case 1:
		insertTail();
		dispMenu();
		break;
	case 2:
		deleteHead();
		dispMenu();
		break;
	case 3:
		deleteTail();
		dispMenu();
		break;
	case 4:
		searchNDelete();
		dispMenu();
		break;
	case 5:
		printList();
		dispMenu();
		break;
	}
}
void DLList::printList()const
{
	DLLNode* temp = head;
	temp = head;
	std::cout << std::endl;
	std::cout << "The list is: ";
	while (temp != 0)
	{
		std::cout << temp->info << " ";
		temp = temp->next;
	}
}

void DLList::dispMenu()
{
	int num;
	std::cout << std::setw(25) << "MENU" << std::endl << std::endl;
	std::cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << std::endl;
	std::cout << "DLL: IH(6), IT(7), DH(8), DT(9). SD(10), PD(11)" << std::endl;
	std::cout << "Exit Program(12)" << std::endl << std::endl;
	std::cout << std::setw(28) << "Choose?" << std::endl;
	std::cin >> num;
	IntSLList task;
	switch (num)
	{
		
	case 0:
		task.dispMenu();
		break;
	case 1:
		task.dispMenu();
		break;
	case 2:
		
		task.dispMenu();
		break;
	case 3:
		task.dispMenu();
		break;
	case 4:
		task.dispMenu();
		break;
	case 5:
		task.dispMenu();
		break;
	case 6:
		insertHead();
		dispMenu();
		break;
	case 7:
		insertTail();
		dispMenu();
		break;
	case 8:
		deleteHead();
		dispMenu();
		break;
	case 9:
		deleteTail();
		dispMenu();
		break;
	case 10:
		searchNDelete();
		dispMenu();
		break;
	case 11:
		printList();
		dispMenu();
		break;
	case 12:
		break;
	default:
		std::cout << "\nIncorrect selection. Try again!" << std::endl << std::endl;
		dispMenu();
	}

}


int main()
{
	IntSLList task;
	DLList task1;
	
	task.dispMenu();
	task1.dispMenu();
return 0;
}

