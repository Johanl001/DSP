#include <iostream>
using namespace std;

class Queue 
{
    int f, r;
    int arr[10];

public:
    Queue() 
    {
        f = -1;
        r = -1;
    }

    void empty();
    void full();
    void enQueue();
    void deQueue();
    void display();
};

void Queue::empty() 
{
    if (f == -1) 
    {
        cout << "\nQueue is Empty";
    } 
    else 
    {
        cout << "\nQueue is not empty.";
    }
}

void Queue::full() 
{
    if ((f == 0 && r == 9) || (r + 1) % 10 == f) 
    {
        cout << "\nQueue is Full";
    } 
    else 
    {
        cout << "\nQueue is not full.";
    }
}

void Queue::enQueue() 
{
    if ((f == 0 && r == 9) || (r + 1) % 10 == f) 
    {
        cout << "\nQueue is Full.\nYou cannot insert the data.";
        return;
    }

    int b;
    cout << "\nEnter the data you want to insert in Queue: ";
    cin >> b;

    if (f == -1) 
    { // Insert First Element
        f = r = 0;
    } 
    else 
    {
        r = (r + 1) % 10; // Move to the next position circularly
    }
    arr[r] = b;
}

void Queue::deQueue() 
{
    if (f == -1) 
    {
        cout << "\nQueue is Empty";
        return;
    }

    cout << "\nDequeued: " << arr[f];
    arr[f] = -1; // Optionally clear the dequeued position

    if (f == r) 
    { // Queue becomes empty after this dequeue
        f = -1;
        r = -1;
    }
    else 
    {
        f = (f + 1) % 10; // Move to the next position circularly
    }
}

void Queue::display() 
{
    if (f == -1) 
    {
        cout << "\nQueue is Empty";
        return;
    }

    cout << "\nElements in Circular Queue are: ";
    int i = f;
    while (true) 
    {
        cout << arr[i] << " ";
        if (i == r) break;
        i = (i + 1) % 10; // Move circularly
    }
    cout << endl;
}

int main() 
{
    Queue a;
    int ch;

    while (true) 
    {
        cout << "\n\nMenu.\n1.Check empty\n2.Check Full\n3.EnQueue\n4.DeQueue\n5.Display\n6.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                a.empty();
                break;

            case 2:
                a.full();
                break;

            case 3:
                a.enQueue();
                break;

            case 4:
                a.deQueue();
                break;

            case 5:
                a.display();
                break;

            case 6:
                return 0;

            default:
                cout << "\nInvalid choice.";
                break;
        }
    }

    return 0;
}
