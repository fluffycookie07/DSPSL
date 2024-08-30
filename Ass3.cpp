//Vaishnavi Borse, S.Y.A ,Batch AS1, Roll No.19.
#include <iostream>
using namespace std;

int n, i,r;

class search
{
public:
    int rno;
    string name, address;
    int feedbackScore[5];

public:
    void accept();
    void display();
    void linear();
    void binary();
    void feedback();
    int calculateFeedbackScore();
} s[100];

void search::accept()
{
    cout << "Enter the Roll No: ";
    cin >> rno;
    cout << "Enter the Name: ";
    cin >> name;
    cout << "Enter the Address: ";
    cin >> address;
}

void search::display()
{
    cout << "\n"<< name << "\t" << rno << "\t" << address << "\n";
}

void search::linear()
{
    int flag = 0;
    cout << "Enter Roll No which you want to search: ";
    cin >> r;
    for (int i = 0; i < n; i++)
    {
        if (s[i].rno == r)
        {
            cout << "Roll no "<< r <<" was present for the training program.\n";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Roll no " << r << " was not present for the training.\n";
    }
}

void search::binary()
{
    search T;
    for (int i = 0; i < n ; i++)
    {
        for (int j = i; j < n ; j++)
        {
            if (s[i].rno > s[j].rno)
            {
                T= s[i];
                s[i] = s[j];
                s[j] = T;
            }
        }
    }

    int flag = 0;
    cout << "Enter the roll no which you want to search: ";
    cin >> r;
    int low = 0, high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].rno == r)
        {
            cout << "Roll no " << r << " was present for the program.\n";
            flag = 1;
            break;
        }
        else if (s[mid].rno > r)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (flag == 0)
    {
        cout << "Roll no " << r << " was not present for the training.\n";
    }
}
void search::feedback()
{
    cout << "Fill the feedback form for (Enter 1 for Yes, 0 for No):\n";
    cout << "1. Did you enjoy the session? ";
    cin >> feedbackScore[0];
    cout << "2. Are you satisfied with this training? ";
    cin >> feedbackScore[1];
    cout << "3. Was it helpful? ";
    cin >> feedbackScore[2];
    cout << "4. Do you want this session again? ";
    cin >> feedbackScore[3];
    cout << "5. Did the trainer explain all the points clearly? ";
    cin >> feedbackScore[4];
}

int search::calculateFeedbackScore()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += feedbackScore[i];
    }
    return sum;
}


int main()
{
    int ch, i;
    int totalFeedbackScore = 0;
    int averageFeedback = 0;


    cout << "How many records do you want to insert: ";
    cin >> n;

    do
    {
        cout << "Menu\n1.Accept\n2.Display\n3.Linear Search\n4.Binary Search\n5.Feedback\n6.End\n";
        cout << "Enter your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
                s[i].accept();
            break;
        case 2:
            cout << "\nName\tRoll No\tAddress\n";
            for (int i = 0; i < n; i++)
                s[i].display();
            break;
        case 3:
                s[i].linear();
            break;
        case 4:
                s[i].binary();
            break;
       case 5:
            totalFeedbackScore = 0;
            for (int i = 0; i < n; i++)
            {
                s[i].feedback();
                totalFeedbackScore += s[i].calculateFeedbackScore();
            }
            averageFeedback = (totalFeedbackScore * 100) / (n * 5);
            if (averageFeedback > 80)
            {
                cout << "The training was good.\n";
            }
            else
            {
                cout << "The training needs improvement.\n";
            }
            break;
        case 6:
            cout << "End\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (ch != 6);

    return 0;
}