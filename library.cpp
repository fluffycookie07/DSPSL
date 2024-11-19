// Vaishnavi Borse, S.Y.A ,Batch AS1, Roll No.19.
#include <iostream>
#include <string>
using namespace std;
int n, i, j;
class Book
{
    int cost;
    string name, author;

public:
    void accept();
    void display();
    void asc();
    void dec();
    void lessthan();
    void greaterthan();
    void deletet();
} b[100], c[100];
void Book::accept()
{
    cout << "Enter Book Name,Author and Cost:";
    cin >> name >> author >> cost;
}
void Book::display()
{

    cout << name << "\t" << author << "\t" << cost << "\n";
}
void Book::asc()
{
    Book T;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (b[i].cost > b[j].cost)
            {
                T = b[i];
                b[i] = b[j];
                b[j] = T;
            }
        }
        b[i].display();
    }
}
void Book ::dec()
{
    Book T;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (b[i].cost < b[j].cost)
            {
                T = b[i];
                b[i] = b[j];
                b[j] = T;
            }
        }
        b[i].display();
    }
}
void Book::lessthan()
{
    for (int i = 0; i < n; i++)
    {
        if (b[i].cost < 500)
        {
            b[i].display();
        }
    }
}
void Book ::greaterthan()
{
    int count;
    for (int i = 0; i < n; i++)
    {
        if (b[i].cost > 500)
        {
            b[i].display();
            count++;
        }
    }
}
void Book::deletet()
{
    j = 0;
    c[0] = b[0];
    for (i = 0; i < n; i++)
    {

        if (b[i].name != c[j].name && b[i].author != c[j].author)
        {
            j++;
            c[j] = b[i];
        }
    }
    for (i = 0; i <= j; i++)
    {
        c[i].display();
    }
}

int main()
{
    int ch;
    cout << "Enter the number of enteries:";
    cin >> n;

    while (ch != 0)
    {
        cout << "Menu\n1.Accept\n2.Display\n3.Ascending order\n4.Descending Order\n5.Books cost less than 500\n6.Books cost more than 500\n7.Delete duplicate entries\n";
        cout << "Enter Your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                b[i].accept();
            }
            break;
        case 2:
            cout << "Name\t" << "Author\t" << "Cost\n";
            for (int i = 0; i < n; i++)
            {
                b[i].display();
            }
            break;
        case 3:
            b[i].asc();
            break;
        case 4:
            b[i].dec();
            break;
        case 5:
            b[i].lessthan();
            break;
        case 6:
            b[i].greaterthan();
            break;
        case 7:
            b[i].deletet();
            break;

        default:
            cout << "press 0 to exit";
            break;
        }
    }
}
