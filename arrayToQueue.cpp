#include <iostream>
using namespace std;

class Queue {
public:
    int n;
    int start = -1;
    int end = -1;
    int* qu; 
    int currSize = 0;

    Queue(int size) {
        this->n = size;
        qu = new int[n];  
    }

    bool push(int a) {
        if (currSize == n) return false;  
        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % n;
        }
        qu[end] = a;
        currSize++;
        return true;
    }

    void pop() {
        if (currSize == 0) return;  
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % n;
        }
        currSize--;
    }

    int peek() {
        if (currSize == 0) return -1;
        return qu[start];
    }

    int size() {
        return currSize;
    }

    ~Queue() {
        delete[] qu;
    }
};

int main() {
    Queue q(5);

    q.push(10);
    q.push(20);
    cout << "Front element: " << q.peek() << endl;
    q.pop();
    cout << "Front after pop: " << q.peek() << endl;
    cout << "Current size: " << q.size() << endl;

    return 0;
}
