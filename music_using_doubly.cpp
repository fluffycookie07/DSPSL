#include <iostream>
using namespace std;

class music {
    int year;
    float duration;
    string name,album,artist;
    music *next,*prev;
    public:
    void accept();
    void display();
    void search();
    void modify();
    void count();
    void delete_position();
}*start=NULL,*End=NULL;
//accept record

void music::accept() {
    music *newnode = new music;
    cout << "Enter music name,album,artist,year,duration: ";
   cin >> newnode->name >> newnode->album >> newnode->artist >> newnode->year >> newnode->duration;
      newnode->next = nullptr;
      newnode->prev = nullptr;

    if (start == nullptr) {
        start = newnode;
    } else {
        music *temp = start;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        End=temp;
    }
}
//display record
void music::display() {
    music *temp = start;
    while (temp != nullptr) {
        cout << "\n" << temp->name << "\t" << temp->album << "\t" << temp->artist<<"\t"<< temp->year <<"\t"<< temp->duration;
        temp = temp->next;
    }
}
//search a record
void music::search() {
    string title;
    int f = 0;
    cout << "\nEnter a Music name you want to search: ";
    cin >> title;
  music *temp = start;

    while (temp != nullptr) {
        if (title == temp->name) {
            cout << "\n" << temp->name << "\t" << temp->album << "\t" << temp->artist <<"\t"<<temp->year <<"\t"<<temp->duration;
            f = 1;
            break; // Exit loop if music is found
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
void music::modify() {
    string title;
    int f = 0;
    cout << "\nEnter Music name you want to modify: ";
    cin >> title;
    
    music *temp = start;

    while (temp != nullptr) {
        if (title == temp->name) {
            cout << "Enter new name of music,album,artist,released year,and duration: ";
            cin >> temp->name >> temp->album >> temp->artist >>temp->year>>temp->duration;
            f = 1;
            break; // Exit loop if modification is done
        }
        temp = temp->next;
    }

    if (f == 1) {
        cout << "\nModification successful";
    } else {
        cout << "\nMusic not found";
    }
}


//delete position
void music::delete_position() {
    string title;
    cout << "\nEnter music name to remove: ";
    cin >> title;

    if (start == nullptr) {
        cout << "\nList is empty";
        return;
    }

    if (start->name == title) {
        music *temp=start;
        start=start->next;
        delete temp;
        return;
    }

    music *temp = start;
    while (temp->next != NULL && temp->next->name != title) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "\nMusic not found";
        return;
    }

    music *pos = temp->next;
    temp->next = pos->next;
    cout << "\nDeleted: " << pos->name << "\t" << pos->album << "\t" << pos->artist <<"\t"<< pos->year <<"\t"<< pos->duration;
    delete pos;
}
//music count function
void music::count()
{  int c;
    music *temp = start;
    while (temp != nullptr) {
        c++;
        temp = temp->next;
    }
    cout<<"\ntotal music="<<c;
}


int main() {
    int ch;
    music s;
    do {
        cout << "\n1. Accept Music Information\n2. Display Music Information\n3. Search Music Information\n4. Modify Music Information\n5. Delete Music Information\n6. total Musics";
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
            s.delete_position();
            break;
            
            case 6:
            s.count();
            break;
        }
    } while (ch != 0);
    
  return 0;
}