#include <iostream>
using namespace std;

class Stack {
public:
    int n;
    int top;
    int* st;  

    Stack(int size) {
        this->n = size;
        this->top = -1;
        st = new int[n];  
    }

    bool push(int a) {
        if (top >= n - 1) return false;  
        top++;
        st[top] = a;
        return true;
    }

    void pop() {
        if (top >= 0) top--;  
    }

    int peek() {
        if (top < 0) return -1;  
        return st[top];
    }

    int size() {
        return top + 1;
    }

    ~Stack() {
        delete[] st;  
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;
    cout << "Current size: " << s.size() << endl;

    return 0;
}
