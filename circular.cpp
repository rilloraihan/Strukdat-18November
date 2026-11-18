// Q4_CircularQueue.cpp - Circular Queue berbasis array (kapasitas 5), tanpa STL
#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int front = 0;    // indeks elemen terdepan
int rear = -1;    // indeks elemen terakhir
int total = 0;    // jumlah elemen -> pembeda Full vs Empty

bool isEmpty() { return total == 0; }
bool isFull()  { return total == MAX; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << value << ".\n";
        return;
    }
    rear = (rear +1) % MAX;
    queueArr[rear] = value;
    total++;
    cout << value << " inserted successfully.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }
    cout << queueArr[front] << " removed successfully.\n";
    front = (front + 1) % MAX;
    total--;
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
    for (int i = 0; i < total; i++) {
        cout << queueArr[(front + i) % MAX] << " ";
    }
    cout << "\n";
}

// Tes wajib 10 langkah
void mandatoryTest() {
    front = 0;
    rear = -1;
    total = 0;
    cout << "--- Mandatory Test ---\n";
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();      // hapus 10
    dequeue();      // hapus 20
    enqueue(60);    // wrap-around
    enqueue(70);
    display();      // Queue: 30 40 50 60 70
}

int main() {
    int choice = 0;
    int value;

    while (choice != 6) {
        cout << "\n===== CIRCULAR QUEUE MENU =====\n";
        cout << "1. Enqueue  2. Dequeue  3. Front\n";
        cout << "4. Display  5. Run Mandatory Test  6. Exit\n\n";
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
            mandatoryTest();
        } else if (choice == 6) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}