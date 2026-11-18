
#include <iostream>
using namespace std;

const int MAX = 5;   
int stackArr[MAX];   
int top = 0;       

bool isEmpty(){
    return top == 0;
 }
bool isFull(){
     return top == MAX ;
     }


void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot insert " << value << ".\n";
        return;
    }
    stackArr[top] = value;
    top++;
    
    
    cout << value << " inserted successfully.\n";
    cout << endl;
}


int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack is empty.\n";
        return -1;
    }

    int value = stackArr[top];
    top--;
    return value;
    
}


void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Top element: " << stackArr[top] << "\n";
    cout << endl;
}


void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack : ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << "\n";
    cout << endl;
}

int main() {
    int choice = 0;
    int value;

    while (choice != 5) {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push  2. Pop  3. Peek\n";
        cout << "4. Display  5. Exit\n\n";
        cout << "Choose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            peek();
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