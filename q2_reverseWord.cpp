// Q2_ReverseWord.cpp - Membalik kata menggunakan stack (LIFO) dari array char
#include <iostream>
using namespace std;

const int MAX = 100;
char stackArr[MAX];  // stack karakter
int top = 0;

bool isEmpty() { return top == 0; }
bool isFull()  { return top == MAX; }

void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow!\n";
        return;
    }
    stackArr[top] = c;
    top++;
    
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
        return '\0';
    }
    top--;
    char c = stackArr[top];
    
    return c;
}

int main() {
    char word[MAX];
    cout << "Enter a word: ";
    cin >> word;

    // Hitung panjang kata manual
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }

    // PUSH: karakter dari kiri ke kanan
    for (int i = 0; i < length; i++) {
        push(word[i]);
    }

    // POP: semua karakter keluar dalam urutan terbalik
    char reversed[MAX];
    int index = 0;
    while (!isEmpty()) {
        reversed[index] = pop();
        index++;
    }
    reversed[index] = '\0';

    cout << "\nOriginal word: " << word << "\n";
    cout << "Reversed word: " << reversed << "\n";
    return 0;
}