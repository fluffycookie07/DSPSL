#include <iostream>
#include <stack>
using namespace std;

class StringOperations
{
private:
    char str1[10], str2[10];

public:
    void accept()
    {
        cout << "Enter first string: ";
        cin >> str1;
        cout << "Enter second string: ";
        cin >> str2;
    }

    int Length(char str[])
    {
        int len = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            len++;
        }
        return len;
    }

    void measureLength()
    {
        cout << "Length of first string: " << Length(str1) << endl;
        cout << "Length of second string: " << Length(str2) << endl;
    }

    void compare()
    {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0')
        {
            if (str1[i] != str2[i])
            {
                cout << "Strings are not equal." << endl;
                return;
            }
            i++;
        }
        if (str1[i] == '\0' && str2[i] == '\0')
        {
            cout << "Strings are equal." << endl;
        }
        else
        {
            cout << "Strings are not equal." << endl;
        }
    }

    void copy()
    {
        int i;
        for (i = 0; str2[i] != '\0'; i++)
        {
            str1[i] = str2[i];
        }
        str1[i] = '\0';
        cout << "Copied second string to first string: " << str1 << endl;
    }

    void reverseString(char str[], char reversed[])
    {
        int len = Length(str);
        for (int i = 0; i < len; i++)
        {
            reversed[i] = str[len - i - 1];
        }
        reversed[len] = '\0';
    }

    void reverse()
    {
        char r1[10], r2[10];
        reverseString(str1, r1);
        reverseString(str2, r2);
        cout << "Reversed first string: " << r1 << endl;
        cout << "Reversed second string: " << r2 << endl;
    }

    void concatenate()
    {
        char Str[20];
        int i = 0, j = 0;

        for (i = 0; str1[i] != '\0'; i++)
        {
            Str[i] = str1[i];
        }

        for (j = 0; str2[j] != '\0'; j++)
        {
            Str[i + j] = str2[j];
        }
        Str[i + j] = '\0';
        cout << "Concatenated string: " << Str << endl;
    }

    void checkPalindrome(char str[])
    {
        stack<char> s;
        int len = Length(str);

        for (int i = 0; i < len; i++)
        {
            s.push(str[i]);
        }

        for (int i = 0; i < len; i++)
        {
            if (s.top() != str[i])
            {
                cout << str << " is not a palindrome." << endl;
                return;
            }
            s.pop();
        }
        cout << str << " is a palindrome." << endl;
    }

    void palindrome()
    {
        char str1[10];
        cout << "Enter string:";
        cin >> str1;
        checkPalindrome(str1);
    }
};

int main()
{
    StringOperations S;
    int choice;
    S.accept();

    do
    {
        cout << "\nChoose an operation to perform:\n";
        cout << "1. Measure Length\n";
        cout << "2. Compare Strings\n";
        cout << "3. Concatenate Strings\n";
        cout << "4. Reverse Strings\n";
        cout << "5. Copy String\n";
        cout << "6. Check Palindrome\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            S.measureLength();
            break;
        case 2:
            S.compare();
            break;
        case 3:
            S.concatenate();
            break;
        case 4:
            S.reverse();
            break;
        case 5:
            S.copy();
            break;
        case 6:
            S.palindrome();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
