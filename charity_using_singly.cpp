#include <iostream>
using namespace std;

class CMS {
    int amount;
    string name, add;
    CMS *next;
    public:
    void accept();
    void display();
    void search();
    void modify();
    void delete_position();
    void delete_first();
    void delete_last();
}*start=NULL;
//accept record
void CMS::accept() {
    CMS *newnode = new CMS;
    cout << "Enter Donor name, address, amount: ";
    cin >> newnode->name >> newnode->add>> newnode->amount;

    if (start == nullptr) {
        start = newnode;
    } else {
        CMS *temp = start;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
//display record
void CMS::display() {
    CMS *temp = start;
    while (temp != nullptr) {
        cout << "\n" << temp->name << "\t" << temp->add << "\t" << temp->amount;
        temp = temp->next;
    }
}
//search a record
void CMS::search() {
    string title;
    int f = 0;
    cout << "\nEnter a Donar name you want to search: ";
    cin >> title;
  CMS *temp = start;

    while (temp != nullptr) {
        if (title == temp->name) {
            cout << "\n" << temp->name << "\t" << temp->add << "\t" << temp->amount;
            f = 1;
            break; // Exit loop if donor is found
        }
        temp = temp->next;
    }

    if (f == 1) {
        cout << "\nFound";
    } else {
        cout << "\nNot found";
    }
}
//modify record
void CMS::modify() {
    string title;
    int f = 0;
    cout << "\nEnter Donor name you want to modify: ";
    cin >> title;
    
    CMS *temp = start;

    while (temp != nullptr) {
        if (title == temp->name) {
            cout << "Enter new name, address, and amount: ";
            cin >> temp->name >> temp->add >> temp->amount;
            f = 1;
            break; // Exit loop if modification is done
        }
        temp = temp->next;
    }

    if (f == 1) {
        cout << "\nModification successful";
    } else {
        cout << "\nDonor not found";
    }
}
//delete first record
void CMS::delete_first() {
    if (start == nullptr) {
        cout << "\nList is empty";
        return;
    }

    CMS *temp = start;
    start = start->next;
    cout << "\nDeleted: " << temp->name << "\t" << temp->add << "\t" << temp->amount;
    delete temp;
}
//delete last record
void CMS::delete_last() {
    if (start == nullptr) {
        cout << "\nList is empty";
        return;
    }

    if (start->next == nullptr) {
        cout << "\nDeleted: " << start->name << "\t" << start->add << "\t" << start->amount;
        delete start;
        start = nullptr;
        return;
    }

    CMS *temp = start;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    cout << "\nDeleted: " << temp->next->name << "\t" << temp->next->add << "\t" << temp->next->amount;
    delete temp->next;
    temp->next = nullptr;
}
//delete position
void CMS::delete_position() {
    string title;
    cout << "\nEnter Donor name to delete: ";
    cin >> title;

    if (start == nullptr) {
        cout << "\nList is empty";
        return;
    }

    if (start->name == title) {
        delete_first();
        return;
    }

    CMS *temp = start;
    while (temp->next != NULL && temp->next->name != title) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "\nDonor not found";
        return;
    }

    CMS *pos = temp->next;
    temp->next = pos->next;
    cout << "\nDeleted: " << pos->name << "\t" << pos->add << "\t" << pos->amount;
    delete pos;
}

int main() {
    int ch;
    CMS s;
    do {
        cout << "\n1. Accept Donor Information\n2. Display Donor Information\n3. Search Donor Information\n4. Modify Donor Information\n5. Delete first Donor Information\n6. Delete last Donor Information\n7. Delete Donor Information\n";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
            s.accept(); 
            break;
            
            case 2: 
            s.display(); 
            break;
            
            case 3:
            s.search(); 
            break;
            
            case 4: 
            s.modify(); 
            break;
            
            case 5:
            s.delete_first();
            break;
            
            case 6:
            s.delete_last();
            break;
            
            case 7:
            s.delete_position();
            break;
            
        }
    } while (ch != 0);
    
  return 0;
}