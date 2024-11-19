#include <iostream>
#include <string>
using namespace std;
const int MAX = 5;
const int PIZZA_COST = 100;
class PizzaParlour
{
    int front, rear;
    int orders[MAX];

public:
    PizzaParlour()
    {
        front = rear = -1;
    }
    bool addOrder(int data);
    void serveOrder();
    void display();
};

bool PizzaParlour::addOrder(int id)
{
    if (rear == -1)
    {
        front = rear = 0;
        orders[rear] = id;
        return true;
    }
    else
    {
        int pos = (rear + 1) % MAX;
        if (pos == front)
        {
            cout << "Full.\n";
            return false;
        }
        else
        {
            rear = pos;
            orders[rear] = id;
            return true;
        }
    }
}

void PizzaParlour::serveOrder()
{
    if (front == -1)
    {
        cout << "Empty\n";
        return;
    }
    else
    {
        cout << "\nOrder No. " << orders[front] << " is processed.\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void PizzaParlour::display()
{
    int i = 0;
    if (front == -1)
    {
        cout << "Empty.\n";
        return;
    }
    else
    {
        cout << "Order IDs: \n";
        for (i = front; i != rear; i = ((i + 1) % MAX))
        {
            cout << orders[i] << "  ";
        }
        cout << orders[rear];
    }
}

double getDiscount(int id)
{

    if (id == 1)
    {
        return 0.50;
    }
    else if (id == 2)
    {
        return 0.30;
    }
    else if (id == 3)
    {
        return 0.20;
    }
    else
    {
        return 0.10;
    }
}

int main()
{
    int ch, id = 0;
    string customerName, customerAddress;
    int quantity;
    double totalBill, discount, finalBill;

    PizzaParlour q;

    do
    {

        cout << "-----------------";
        cout << "\n****Menu*****\n";
        cout << "1. Accept order\n";
        cout << "2. Serve order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit";

        cout << "\nChoice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            id++;
            cout << "Enter your name: ";
            cin>>customerName;
            cout << "Enter your address: ";
            cin>> customerAddress;
            cout << "Enter quantity: ";
            cin >> quantity;

            totalBill = quantity * PIZZA_COST;

            discount = getDiscount(id);
            finalBill = totalBill * (1 - discount);

            if (q.addOrder(id))
            {
                cout << "Thank you for the order, " << customerName << ".\n";
                cout << "Order ID is: " << id << "\n";
                cout << "Address: " << customerAddress << "\n";
                cout << "Quantity: " << quantity << "\n";
                cout << "Total Bill: Rs. " << totalBill << "\n";
                cout << "Discount: " << (discount * 100) << "%\n";
                cout << "Final Bill after discount: Rs. " << finalBill << "\n"; 
            }
            else
            {
                id--;
            }
            break;

        case 2:
            q.serveOrder();
            break;

        case 3:
            q.display();
            break;
        }
    } while (ch != 4);
    cout << "\nThank You. Keep Visiting.";
}
