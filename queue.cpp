
#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int front = 0;    // indeks elemen paling depan
int rear = -1;    // indeks elemen paling belakang (-1 = kosong)

bool isEmpty() { return rear < front; }
bool isFull()  { return rear == MAX - 1; }

// Masuk lewat belakang
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << value << ".\n";
        return;
    }
    rear++;
    queueArr[rear] = value;

   
    cout << value << " inserted successfully.\n";
}

// Keluar lewat depan
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }
    cout << queueArr[front] << " removed successfully.\n";
    front++;
    if (front > rear){
        front = 0;
        rear = -1;
    }
}

void showFront() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element: " << queueArr[front] << "\n";
}

void display() {
    if (isEmpty()) {
        cout << "Queue: (empty)\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice = 0;
    int value;

    while (choice != 5) {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue  2. Dequeue\n";
        cout << "3. Front  4. Display  5. Exit\n\n";
        cout << "Choose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            showFront();
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}