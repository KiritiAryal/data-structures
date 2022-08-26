
#include <iostream>
#include <array>
#include <vector>
using namespace std;


void question1() { // function to swap and print two arrays
    array<int, 10> arr1, arr2;
    int myInt;

    for (int i = 0; i < 10; i++)
    {
        arr1[i] = i + 1;
    }

    arr2.fill(5);

    cout << "The first value of array 1: " << arr1.front() << endl;
    cout << "The last value of array 1: " << arr1.back() << endl;
    cout << "The elements of array 1 before swapping is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";

    }
    cout << endl;

    cout << "The elements of array 2 before swapping is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    arr1.swap(arr2);

    cout << "The elements of array 1 after swapping is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "The elements of array 2 after swapping is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "The size of array 1: " << arr1.size() << endl;
    cout << "The size of array 2: " << arr2.size() << endl;
    cout << endl;
}

vector<int> sortVector(vector <int> &g2) // function to sort a vector
{
    int temp;
    for (int j = 0; j < g2.size(); j++) {
        for (int k = j + 1; k < g2.size(); k++) {

            if (g2[j] > g2[k])
            {
                temp = g2[j];
                g2[j] = g2[k];
                g2[k] = temp;
            }
        }
    }
    return g2;
}

void question2a() // function to display sets of sorted and unsorted input integers
{
    vector <int> g1, g2;
    vector <int> ::iterator i;
    int myInt;
    cout << "Enter the numbers and press \"0\" when you are done: " << endl;
    cin >> myInt;
    do {
        g1.push_back(myInt);
        cin >> myInt;
    } while (myInt);
    cout << "The vector you entered: ";
    for (i = g1.begin(); i != g1.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    g2 = g1;
    cout << endl;
    cout << "The vector you entered ordered in ascending order: ";


    sortVector(g2);
    for (int j = 0; j < g2.size(); j++)
    {
        cout << g2[j] << " ";
    }
    cout << endl << endl;
}

void question2b() // function to match input elements with default ones
{
    vector <int> g1, g2;
    vector <int> :: iterator i;
    for (int i = 1; i <= 100; i++)
    {
        g1.push_back((i * 10) + 3);
    }

    cout << "Enter 10 integers: ";

    for (int i = 0; i < 10; i++)
    {
        int input;
        cin >> input;
        g2.push_back(input);
    }

    int count = 0;
    double percent_Present, percent_Absent;
    for (int j = 0; j < 100; j++) {
        for (i = g2.begin(); i != g2.end(); ++i) {
            if (g1[j] == *i)
                count++;
        }
    }
    percent_Present = (double(count) / 10) * 100;
    percent_Absent = 100 - percent_Present;
    cout << "There are " << count << " integers that you entered in the directory." << endl;
    cout << "The percent of integers in the dirctory is: " << percent_Present << endl;
    cout << "The percent of integers not in the dirctory is: " << percent_Absent << endl << endl;
    cin;
}

void question2c() // function to show if two vectors are equal
{
    vector<int> g1;
    vector<int> g2;
    vector<int> ::iterator i;
    vector<int> ::iterator j;
    int input;
    int myInt;
    
    cout << "Enter integers for the first vector and press \"0\" when you are done: " << endl;
    cin >> input;
    do {
        g1.push_back(input);
        cin >> input;
    } while (input);
    
    cout << "Enter another set of integers of same size for the second vector: " << endl;
    cin >> myInt;
    while (g2.size() != g1.size()) {
        g2.push_back(myInt);
        cin >> myInt;
    }
    if (g1 == g2)
        cout << "The vectors are equal" << endl;
    else
        cout << "The vectors are not equal" << endl;
    cout << endl;
}

void question2d() // function to count the repeated elements
{
    vector <int> g1, g2;
    //vector <int> :: iterator i, j;
    int input;
    cout << "Enter integers and enter \"0\" when you are done: " << endl;
    cin >> input;
    do {
        g1.push_back(input);
        cin >> input;
    } while (input);
    g1 = sortVector(g1);
    int counter, i;
    for (i = 0; i < number; i += counter) {
        for (counter = 1; i + counter < number && array[i + counter] == array[i]; )
            counter++;       // count consecutives dups
        if (counter > 1) {     // if more than one, process the dups.  
            cout << "dup: " << g1[i] << " " << counter << endl;
        }
    }
}

void question2e() // funciton to merge two sorted vectors
{
    vector <int> g1, g2, g3;
    vector <int> :: iterator i, j;
    cout << "Enter integers for the first vector and press \"0\" when you are done: " << endl;
    int input1, input2;
    cin >> input1;
    do {
        g1.push_back(input1);
        cin >> input1;
    } while (input1);
    cout << "Enter another set of integers for the second vector and press \"0\" when you are done: " << endl;
    cin >> input2;
    do {
        g1.push_back(input2);
        cin >> input2;
    } while (input2);
    g1 = sortVector(g1);
    g2 = sortVector(g2);
    for(i = g1.begin(); i != g1.end(); ++i)
    {
        g3.push_back(*i);
    }
    for (j = g2.begin(); j != g2.end(); ++j)
    {
        g3.push_back(*j);
    }
    
    g3 = sortVector(g3);
    cout << "The merging of these two sorted vectors is: ";
    for(i = g3.begin(); i != g3.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    question1();
    question2a();
    question2b();
    question2c();
    question2d();
    question2e();
    return 0;
}

