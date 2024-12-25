#include <iostream>
#define MAX 1000

class Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;

public:
    Queue(unsigned capacity) {
        this->capacity = capacity;
        front = this->size = 0;
        rear = capacity - 1;
        array = new int[(capacity * sizeof(int))];
    }

    bool isFull() {
        return (this->size == this->capacity);
    }

    bool isEmpty() {
        return (this->size == 0);
    }

    void enqueue(int item) {
        if (isFull())
            return;
        this->rear = (this->rear + 1) % this->capacity;
        this->array[this->rear] = item;
        this->size = this->size + 1;
        std::cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty())
            return -1;
        int item = this->array[this->front];
        this->front = (this->front + 1) % this->capacity;
        this->size = this->size - 1;
        return item;
    }

    int front() {
        if (isEmpty())
            return -1;
        return this->array[this->front];
    }

    int rear() {
        if (isFull())
            return -1;
        return this->array[this->rear];
    }
};

int main() {
    Queue queue(1000);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    std::cout << queue.dequeue() << " dequeued from queue\n";
    std::cout << "Front item is " << queue.front() << std::endl;
    std::cout << "Rear item is " << queue.rear() << std::endl;

    return 0;
}
