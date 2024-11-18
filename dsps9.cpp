#include<iostream>

 using namespace std;

class donor
{
    int amt;
    string name, add;
    donor *next;

public:
    void accept();
    void display();
    void search();
    void modify();
    void remove();
} *start = NULL;

void donor::accept()
{
    donor *newnode, *temp;
    newnode = new donor;
    cout << "Enter details: ";
    cin >> newnode->amt >> newnode->name >> newnode->add;
    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void donor::display()
{
    donor *temp;
    temp = start;
    while (temp != NULL)
    {
        cout << "\n" << temp->name << "\t" << temp->amt << "\t" << temp->add;
        temp = temp->next;
    }
}

void donor::search()
{
    string search_name;
    donor *temp;
    cout << "Enter donor name to search: ";
    cin >> search_name;
    temp = start;
    while (temp != NULL)
    {
        if (temp->name == search_name)
        {
            cout << "\nFound donor: " << temp->name << "\t" << temp->amt << "\t" << temp->add;
            return;
        }
        temp = temp->next;
    }
    cout << "Donor not found!";
}

 void donor::modify()
{
    string search_name;
    donor *temp;
    cout << "Enter donor name to modify: ";
    cin >> search_name;
    temp = start;
    while (temp != NULL)
    {
        if (temp->name == search_name)
        {
            cout << "Enter new details: ";
            cin >> temp->amt >> temp->name >> temp->add;
            cout << "Details updated successfully!";
            return;
        }
        temp = temp->next;
    }
    cout << "Donor not found!";
}

void donor::remove()
{
    string search_name;
    donor *temp, *prev = NULL;
    cout << "Enter donor name to remove: ";
    cin >> search_name;
    temp = start;
    while (temp != NULL)
    {
        if (temp->name == search_name)
        {
            if (prev == NULL)
            {
                start = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Donor removed successfully!";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Donor not found!";
} 

int main()
{
    donor don;
    int choice;
    do
    {
        cout << "\n1. Add donor\n2. Display donors\n3. Search donor\n4. Modify donor\n5. Remove donor\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            don.accept();
            break;
        case 2:
            don.display();
            break;
        case 3:
            don.search();
            break;
        case 4:
            don.modify();
            break;
        case 5:
            don.remove();
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice! Please try again.";
        }
    } while (choice != 6);
    return 0;
}

