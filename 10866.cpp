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
class Deque {
private:
    Node<T> *front, *back;
    int size;
public:
    Deque() {front = back = nullptr; size = 0;}
    ~Deque() {}

    int getSize() {return size;}
    bool isEmpty() {return size <= 0;}
    int getFront() { return front? front->data : -1; }
    int getBack() { return back? back->data : -1; }
    void push_front(T data);
    void push_back(T data);
    T pop_front();
    T pop_back();
    
};
template <typename T>
void Deque<T>::push_front(T data) {
    Node<T> *newNode = new Node<T>(data);
    if(size <= 0) {
        front = newNode;
        back = newNode;
    }
    else {
        newNode->next = front;
        front = newNode;
    }
    size++;
    return;
}
template <typename T>
void Deque<T>::push_back(T data) {
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
T Deque<T>::pop_front() {
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
        front = nullptr;
    }
    return popRTN;
}
template <typename T>
T Deque<T>::pop_back() {
    if(size <= 0) {
        return -1;
    }
    Node<T> *walker = front;
    for(int i = 0; i < size - 2; i++) {
        walker = walker->next;
    }
    T popRTN = back->data;
    delete back;
    if(size > 2) {
        back = walker;
    }
    else {
        back = front;
    }
    size--;
    if(size <= 0 && front) {
        front = nullptr;
        back = nullptr;
    }
    return popRTN;
}

int main()
{
    Deque<int> dq;
    string output = "";
    int input;
    cin >> input;
    string cmd;
    for(int i = 0; i < input; i++ ) {
        cin >> cmd;
        // cout << "now i is : " << i << "\n";
        if(cmd == "push_front") {
            int data;
            cin >> data;
            dq.push_front(data);
        }
        else if(cmd == "push_back") {
            int data;
            cin >> data;
            dq.push_back(data);
        }
        else if(cmd == "pop_front" ) {
            cout << dq.pop_front() << "\n";
            // output += to_string(dq.pop_front()) + "\n";
        }
        else if(cmd == "pop_back" ) {
            cout << dq.pop_back() << "\n";
            // output += to_string(dq.pop_back()) + "\n";
        }
        else if(cmd == "size" ) {
            cout << dq.getSize() << "\n";
            // output += to_string(dq.getSize()) + "\n";
        }
        else if(cmd == "empty" ) {
            if(dq.isEmpty()) {
                cout << "1\n";
                // output += "1\n";
            }
            else {
                cout << "0\n";
                // output += "0\n";
            }
        }
        else if(cmd == "front" ) {
            cout << dq.getFront() << "\n";
            // output += to_string(dq.getFront()) + "\n";
        }
        else if(cmd == "back" ) {
            cout << dq.getBack() << "\n";
            // output += to_string(dq.getBack()) + "\n";
        }
    }
    cout << output;
    return 0;
}