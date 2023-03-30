#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T data) {this->data = data; next = nullptr;}
    ~Node() {}
};

template <typename T>
class Queue {
private:
    Node<T> *front, *back;
    int size;
public:
    Queue() {front = back = nullptr; size = 0;}
    ~Queue() {}

    int getSize() {return size;}
    bool isEmpty() {return size <= 0;}
    int getFront() { return front? front->data : -1; }
    int getBack() { return back? back->data : -1; }
    void push(T data);
    T pop();
    
};
template <typename T>
void Queue<T>::push(T data) {
    Node<T> *newNode = new Node<T>(data);
    if(size <= 0) {
        front = newNode;
        back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }
    size++;
    return;
}
template <typename T>
T Queue<T>::pop() {
    if(size <= 0) {
        return -1;
    }
    Node<T> *walker = front;
    T popRTN = walker->data;
    front = front->next;
    delete walker;
    size--;
    if(size <= 0 && back) {
        back = nullptr;
    }

    return popRTN;
}

int main()
{
    Queue<int> q;
    int input;
    cin >> input;
    string cmd;
    for(int i = 0; i < input; i++ ) {
        cin >> cmd;
        // cout << "now i is : " << i << "\n";
        if(cmd == "push") {
            int data;
            cin >> data;
            q.push(data);
        }
        else if(cmd == "pop" ) {
            cout << q.pop() << "\n";
        }
        else if(cmd == "size" ) {
            cout << q.getSize() << "\n";
        }
        else if(cmd == "empty" ) {
            if(q.isEmpty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if(cmd == "front" ) {
            cout << q.getFront() << "\n";
        }
        else if(cmd == "back" ) {
            cout << q.getBack() << "\n";
        }
    }
    return 0;
}