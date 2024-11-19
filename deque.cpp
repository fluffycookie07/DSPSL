#include <iostream>
using namespace std;

class deque
{
public:
    int x, f, r, n;
    int q[10];
    deque(int size) {
        n = size;
        f = r = -1;
    }
    void insert_rear();
    void insert_front();
    void deque_rear();
    void deque_front();
};

void deque::insert_rear()
{
    cout << "\nEnter element:";
    cin >> x;
    if (r == n - 1)
    {
        cout << "\nQueue is full";
    }
    else if (f == -1 && r == -1)
    {
        r = 0;
        f = 0;
        q[r] = x;
        cout << "\nElement inserted at position " << r;
    }
    else
    {
        r++;
        q[r] = x;
        cout << "\nElement inserted at position " << r;
    }
}

void deque::insert_front()
{
    cout << "\nEnter element:";
    cin >> x;
    if (f == 0)
    {
        cout << "\nQueue is full at the front";
    }
    else if (f == -1 && r == -1)
    {
        f = r = n - 1;
        q[f] = x;
        cout << "\nElement inserted at position " << f;
    }
    else
    {
        f--;
        q[f] = x;
        cout << "\nElement inserted at position " << f;
    }
}

void deque::deque_front()
{
    if (f == -1)
    {
        cout << "\nQueue is empty";
    }
    else if (f == r)
    {
        cout << "Deleted Element: " << q[f];
        f = r = -1;
    }
    else
    {
        cout << "Deleted Element: " << q[f];
        f++;
    }
}

void deque::deque_rear()
{
    if (f == -1)
    {
        cout << "\nQueue is empty";
    }
    else if (f == r)
    {
        cout << "Deleted Element: " << q[r];
        f = r = -1;
    }
    else
    {
        cout << "Deleted Element: " << q[r];
        r--;
    }
}

int main()
{
    int ch, size;
    cout << "Enter size of the deque: ";
    cin >> size;
    
    deque d(size); 

    do
    {
        cout << "\nMenu\n1. Insert from rear\n2. Insert from front\n3. Delete from rear\n4. Delete from front\n5. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.insert_rear();
            break;
        case 2:
            d.insert_front();
            break;
        case 3:
            d.deque_rear();
            break;
        case 4:
            d.deque_front();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 5);

    return 0;
}
