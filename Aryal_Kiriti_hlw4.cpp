#include <iostream>
#include <string>
using namespace std;

void compareStr() //function to compare given and inverted strings
{
    string str1, str2;
    string::reverse_iterator ir;
    std::cout << "Enter a string: " << endl;
    getline(cin, str1);
    cin;

    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] == ' ')
        {
            for (int j = i; j < str1.size(); j++)
                str1[j] = str1[j + 1];
        }

    }
    std::cout << endl;
    std::cout << str1;
    std::cout << endl;
    for (ir = str1.rbegin(); ir != str1.rend(); ++ir)
    {
        str2.push_back(*ir);
    }
    std::cout << str2 << endl;
    if(str1.compare(str2) == 0)
    {
        std::cout << "Strings are palindrome.";
    }
}
void tokenizeIP(){ // function to display IP address with curly brackets and comma
    string str1;
    std::cout << "Enter an IP address to tokenize it: " << endl;
    getline(cin, str1);
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] == '.')
        {
            str1[i] = ',';
        }

    }
    str1.insert(0, "{");
    str1.insert(str1.size(), "}");
    std::cout << str1;    
}

int main()
{
    compareStr();
    tokenizeIP();
    return 0;
}
