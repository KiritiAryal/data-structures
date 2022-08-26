#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct queue
{
    int info;
    queue* next;
};
queue* front[10], *rear[10];

int dispMenu();
void getInput(vector<int>& arr);
void dispArray(vector<int>& arr);
void swap(int* x, int* y);
void bubbleSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);
void addQueue(int i, int value);
int deleteQueue(int i);
void radixSort(vector<int>& arr);

int main()
{
    vector<int> arr;
    int userInput;

    while (1)
    {
        userInput = dispMenu();
        switch (userInput)
        {
        case 0:
            arr.clear();
            getInput(arr);
            dispArray(arr);
            break;
        case 1:
            insertionSort(arr);
            dispArray(arr);
            break;
        case 2:
            selectionSort(arr);
            dispArray(arr);
            break;
        case 3:
            bubbleSort(arr);
            dispArray(arr);
            break;
        case 4:
            quickSort(arr, 0, arr.size() - 1);
            dispArray(arr);
            break;
        case 5:
            radixSort(arr);
            dispArray(arr);
            break;
        case 6:
            return 0;
        default:
            cout << "Not a valid input\n";
        }
    }
    return 0;
}

int dispMenu()
{
    int choice;
    cout << setw(25) << "MENU" << endl << endl;
    cout << "Input Data (0), Insertion Sort (1), Selection Sort (2),\n";
    cout << "Bubble Sort (3), Quick Sort (4), Radix Sort (5)\n";
    cout << "Exit Program (6)\n\n";
    cout << setw(28) << "Choose?" << endl;
    cin >> choice;
    return choice;
}

void getInput(vector<int>& arr)
{
    int input;
    char ch;
    while (1)
    {
        scanf_s("%d%c", &input, &ch);
        arr.push_back(input);
        if (ch == '\n')
            break;
    }
}

void dispArray(vector<int>& arr)
{
    cout << endl;
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr.at(j) > arr.at(j + 1))
                swap(&arr.at(j), &arr.at(j + 1));
}

void insertionSort(vector<int>& arr)
{
    int temp, j;
    for (int i = 1; i < arr.size(); i++)
    {
        temp = arr.at(i);
        j = i - 1;
        while (j >= 0 && arr.at(j) > temp)
        {
            arr.at(j + 1) = arr.at(j);
            j = j - 1;
        }
        arr.at(j + 1) = temp;
    }
}

void selectionSort(vector<int>& arr)
{
    int min, temp, n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
            min = arr.at(min) > arr.at(j) ? j : min;
        temp = arr.at(i);
        arr.at(i) = arr.at(min);
        arr.at(min) = temp;
    }
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr.at(high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr.at(j) <= pivot)
        {
            i++;
            swap(&arr.at(i), &arr.at(j));
        }
    }
    swap(&arr.at(i + 1), &arr.at(high));
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

void addQueue(int i, int value)
{
    queue* temp = new queue();
    temp->next = NULL;
    temp->info = value;
    if (front[i])
        rear[i]->next = temp;
    else
        front[i] = temp;
    rear[i] = temp;
}

int deleteQueue(int i)
{
    int value;
    queue* temp;
    temp = front[i];
    if (!temp)
        return -1;
    value = temp->info;
    front[i] = temp->next;
    delete temp;
    return value;
}

void radixSort(vector<int>& arr)
{
    int i, j, k, radix, data, temp;
    int MAX = arr[0];
    if (arr.size() < 1)
        return;

    for (int x : arr)
        MAX = MAX < x ? x : MAX;
    for (radix = 1, data = 0; MAX >= radix; data++, radix *= 10);

    for (i = 0, radix = 1; i < data; i++, radix *= 10)
    {
        for (j = 0; j < arr.size(); j++)
            addQueue((arr[j] / radix) % 10, arr[j]);
        for (j = 0, k = 0; j < 10; j++)
            for (temp = deleteQueue(j); temp != -1; temp = deleteQueue(j), k++)
                arr[k] = temp;
    }
}

