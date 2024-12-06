#include <iostream>
#include <string>
using namespace std;

class P {
    int quantity;
    string name, address;

public:
    void acceptOrder(string custName, string custAddress, int qty);
    void displayOrder();
    friend class PizzaSystem; // Allows access to private members from PizzaSystem
};

void P::acceptOrder(string custName, string custAddress, int qty) {
    name = custName;
    address = custAddress;
    quantity = qty;
}

void P::displayOrder() {
    cout << "Name: " << name << "\nAddress: " << address << "\nQuantity: " << quantity << endl;
}

class PizzaSystem {
    P orders[100]; // Array to hold orders
    int front, rear, maxSize;

public:
    PizzaSystem(int size) {
        front = -1;
        rear = -1;
        maxSize = size;
    }

    void acceptOrder();
    void serveOrder();
    void displayOrders();
    void displayNextOrder();
};

void PizzaSystem::acceptOrder() {
    if ((rear + 1) % maxSize == front) {
        cout << "Order queue is full! Cannot accept more orders.\n";
        return;
    }

    string name, address;
    int quantity;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your address: ";
    cin >> address;
    cout << "Enter quantity: ";
    cin >> quantity;

    if (front == -1) front = 0; // Initialize front for the first order
    rear = (rear + 1) % maxSize;
    orders[rear].acceptOrder(name, address, quantity);
    cout << "Order placed successfully!\n";
}

void PizzaSystem::serveOrder() {
    if (front == -1) {
        cout << "No orders to serve!\n";
        return;
    }

    cout << "Serving the following order:\n";
    orders[front].displayOrder();

    if (front == rear) {
        // Only one order left
        front = rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }
}

void PizzaSystem::displayOrders() {
    if (front == -1) {
        cout << "No orders to display!\n";
        return;
    }

    cout << "All pending orders:\n";
    int i = front;
    while (true) {
        orders[i].displayOrder();
        if (i == rear) break; // End of queue
        i = (i + 1) % maxSize;
    }
}

void PizzaSystem::displayNextOrder() {
    if (front == -1) {
        cout << "No orders in the queue!\n";
        return;
    }

    cout << "Next order to be served:\n";
    orders[front].displayOrder();
}

int main() {
    int choice, size;
    cout << "Enter the maximum number of orders: ";
    cin >> size;

    PizzaSystem ps(size);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display All Orders\n";
        cout << "4. Display Next Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ps.acceptOrder();
            break;
        case 2:
            ps.serveOrder();
            break;
        case 3:
            ps.displayOrders();
            break;
        case 4:
            ps.displayNextOrder();
            break;
        case 5:
            cout << "Thank you for using the Pizza Delivery System!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
