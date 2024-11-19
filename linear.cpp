//Vaishnavi Borse, S.Y.A ,Batch AS1, Roll No.19.
#include <iostream>
using namespace std;
int n;
class Lsearch
{
public:
    int A[10], i, target, flag = 0, temp;

    void element(int size)
    {
        n = size;
        for (i = 0; i < n; i++)
        {
            cout << "\nEnter the array element:";
            cin >> A[i];
        }
    }

    void sorting()
    {
        for (i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i] > A[j])
                {
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }

        cout << "\nSorted array without duplicates:";
        for (i = 0; i < n; i++)
        {
            if (i == 0 || A[i] != A[i - 1])
            {
                cout << "\t" << A[i];
            }
        }
        cout << "\n";
    }

    void searching(int target)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (target == A[i])
            {
                cout << "\nTarget found at index: " << i << "\n";
                flag = 1;
                break;
            }
        }

        if (flag != 1)
        {
            cout << "\nTarget not found.\n";
        }
    }

    void countOccurrences(int target)
    {
        int count = 0;
        int firstOccurrence = -1;
        int lastOccurrence = -1;

        for (i = 0; i < n; i++)
        {
            if (A[i] == target)
            {
                count++;
                if (firstOccurrence == -1)
                {
                    firstOccurrence = i;
                }
                lastOccurrence = i;
            }
        }

        cout << "\nNumber of occurrences of target: " << count << "\n";
        if (count > 0)
        {
            cout << "First occurrence of target at index: " << firstOccurrence << "\n";
            cout << "Last occurrence of target at index: " << lastOccurrence << "\n";
        }
    }
};

int main()
{
    Lsearch l;
    int choice, Target;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Enter array elements\n";
        cout << "2. Search for a target\n";
        cout << "3. Count occurrences of target\n";
        cout << "4. sort and print without duplicate element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the size of the array:";
            cin >> n;
            l.element(n);
            break;
        case 2:
            cout << "\nEnter target:";
            cin >> Target;
            l.searching(Target);
            break;
        case 3:
            l.countOccurrences(Target);
            break;
        case 4:
            l.sorting();
        case 5:
            return 0;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
    return 0;
}
