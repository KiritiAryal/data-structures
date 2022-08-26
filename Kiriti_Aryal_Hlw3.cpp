#ifndef LL_STACK
#define LL_STACK

#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

template<class T>
class LLStack {
public:
	LLStack() {
	}
	void clear() {
		lst.clear();
	}
	bool isEmpty() {
		return lst.empty();
	}
	T pop() {
		T el = lst.back();
		lst.pop_back();
		return el;
	}
	void push(int el) {
		lst.push_back(el);
	}
private:
	list<T> lst;
};
#endif


LLStack <int> task;
void decToBinary(int num)
{
	int rem = -1, quotient = num;
	cout << "The number in binary is: ";

	do{
		rem = quotient % 2;
		task.push(rem);
		quotient = quotient / 2;
	} while (!(quotient == 0) && !(task.isEmpty() == 1));
	while(!(task.isEmpty() == 1))
		cout << task.pop();
	cout << endl;
}
void decToOctal(int num)
{
	cout << "The octal number is: ";
	int rem, quotient = num;
	do
	{
		rem = quotient % 8;
		task.push(rem);
		quotient = quotient / 8;
	} while (!(quotient == 0) && !(task.isEmpty() == 1));
	while (!(task.isEmpty() == 1))
		cout << task.pop();
	cout << endl;
}
void decToHex(int num)
{
	int rem, quotient = num, hexNumber;
	cout << "The number in hexadecimal is: ";
	do
	{
		rem = quotient % 16;
		quotient = quotient / 16;
		task.push(rem);
	} while (!quotient == 0 && !task.isEmpty() == 1);
	while (!(task.isEmpty()))
	{
		hexNumber = task.pop();
		char ch;
		if (hexNumber <= 15 && hexNumber >= 10)
		{
			switch (hexNumber)
			{
			case 10:
				ch = 'A';
				break;
			case 11:
				ch = 'B';
				break;
			case 12:
				ch = 'C';
				break;
			case 13:
				ch = 'D';
				break;
			case 14:
				ch = 'E';
				break;
			case 15:
				ch = 'F';
				break;
			}
			cout << ch;
		}
		else
		{
			cout << hexNumber;
		}
	}
		
	cout << endl;
}
void dispMenu()
{
	cout << setw(25) << "MENU" << endl << endl;
	cout << "Binary (0), Octal (1), Hexadecimal (2)" << endl;
	cout << "Exit Program(3)" << endl << endl;
	cout << setw(28) << "Choose?" << endl;
}
int main()
{
	int menuInput;
	int input;
	dispMenu();
	cin >> menuInput;
	switch (menuInput)
	{
	case 0:
		cout << "Enter the decimal number: " << endl;
		cin >> input;
		decToBinary(input);
		break;
	case 1:
		cout << "Enter the decimal number: " << endl;
		cin >> input;
		decToOctal(input);
		break;
	case 2:
		cout << "Enter the decimal number: " << endl;
		cin >> input;
		decToHex(input);
		break;
	case 3:
		break;
	default:
		cout << "\nIncorrect selection. Try again!" << endl << endl;
		dispMenu();
	}
	return 0;
}
