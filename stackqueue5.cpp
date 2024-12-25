#include <bits/stdc++.h>
using namespace std;

class QNode {
public:
    int data;
    QNode* next;
    QNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
public:
    QNode *front, *rear;
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        QNode* temp = new QNode(x);

        if (rear == nullptr) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == nullptr)
            return;

        QNode* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete (temp);
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Queue Front : " << ((q.front != nullptr) ? q.front->data : -1) << endl;
    cout << "Queue Rear : " << ((q.rear != nullptr) ? q.rear->data : -1) << endl;
    return 0;
}
