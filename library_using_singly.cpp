#include <iostream>
using namespace std;

class LMS
{
    string tt, aut, pub;
    int prize;
    LMS *next;

public:
    void accept();
    void display();
    void displaycnt();
    void search();
    void modify();
    void deleteFirst();
    void deleteLast();
    void deleteany();
} *start = NULL, s;

void LMS::accept()
{
    LMS *newNode = new LMS;
    cout << "\nEnter Title, Author, Publisher, and Prize: ";
    cin >> newNode->tt >> newNode->aut >> newNode->pub >> newNode->prize;

    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        LMS *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LMS::display()
{
    LMS *temp = start;
    if (temp == NULL)
    {
        cout << "\nNo books in the LMS.\n";
        return;
    }
    while (temp != NULL)
    {
        cout << "\n"
             << temp->tt << "\t" << temp->aut << "\t" << temp->pub << "\t" << temp->prize;
        temp = temp->next;
    }
}

void LMS::displaycnt()
{
    int cnt = 0;
    LMS *temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    cout << "\nBooks in LMS are: " << cnt;
}

void LMS::search()
{
    string tt1;
    int f = 0;
    cout << "Enter Book name: ";
    cin >> tt1;
    LMS *temp = start;
    while (temp != NULL)
    {
        if (temp->tt == tt1)
        {
            f = 1;
            cout << "Book found: " << temp->tt << "\t" << temp->aut << "\t" << temp->pub << "\t" << temp->prize;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "Book Not Found";
    }
}

void LMS::modify()
{
    string tt1;
    int f = 0;
    cout << "Enter Book name to modify: ";
    cin >> tt1;
    LMS *temp = start;
    while (temp != NULL)
    {
        if (temp->tt == tt1)
        {
            f = 1;
            cout << "Book found. Enter New Book details (Title, Author, Publisher, Prize): ";
            cin >> temp->tt >> temp->aut >> temp->pub >> temp->prize;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "\nBook Not Found";
    }
}

void LMS::deleteFirst()
{
    if (start == NULL)
    {
        cout << "\nList is empty.\n";
        return;
    }
    LMS *temp = start;
    start = start->next;
    delete temp;
    cout << "\nFirst book deleted.";
}

void LMS::deleteLast()
{
    if (start == NULL)
    {
        cout << "\nList is empty.\n";
        return;
    }
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        cout << "\nLast book deleted.";
        return;
    }
    LMS *temp = start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "\nLast book deleted.";
}

void LMS::deleteany()
{
    string t;
    cout << "\nEnter Book name to delete: ";
    cin >> t;
    if (start == NULL)
    {
        cout << "\nList is empty.\n";
        return;
    }
    if (start->tt == t)
    {
        deleteFirst();
        return;
    }
    LMS *temp = start;
    LMS *prev = NULL;
    while (temp != NULL && temp->tt != t)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Book Not Found.\n";
    }
    else
    {
        prev->next = temp->next;
        delete temp;
        cout << "\nBook deleted.";
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\nMenu\n1. Accept\n2. Display\n3. Display Count\n4. Search\n5. Modify\n6. Delete First\n7. Delete Last\n8. Delete Any\n9. Exit\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            s.accept();
            break;
        case 2:
            s.display();
            break;
        case 3:
            s.displaycnt();
            break;
        case 4:
            s.search();
            break;
        case 5:
            s.modify();
            break;
        case 6:
            s.deleteFirst();
            break;
        case 7:
            s.deleteLast();
            break;
        case 8:
            s.deleteany();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (ch != 9);
    return 0;
}
