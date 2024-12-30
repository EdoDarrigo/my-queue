#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

template <typename T>
class MyQueue {
public:
    MyQueue(int);
    ~MyQueue();
    void push(T);
    T pop();
    bool empty();
    int size();



private:
    T* fila;
    void incrementSize();
    unsigned int internalSize;
    unsigned int elements;
};

template<typename T>
MyQueue<T>::MyQueue(int internalSize) {
    this->internalSize = internalSize;
    elements = 0;
    fila = new T[internalSize];
}

template<typename T>
void MyQueue<T>::incrementSize() {
    T* oldFila = fila;
    internalsize += 1;
    fila = new T[internalSize];
    for (int i = 0; i < elements; i++) {
        fila[i] = oldFila[i];
    }
    delete[] oldFila;
}


template<typename T>
void MyQueue<T>::push(T element) {
    if (internalSize == elements) {
        incrementSize();
    }
    fila[elements++] = element;
}


