#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *prev;

    Node(T data) {this->data = data; prev = nullptr;}
    ~Node() {}
};

template <typename T>
class Stack {
private:
    Node<T> *top;
    int size;
public:
    Stack() {top = nullptr; size = 0;}
    ~Stack() {}

    int getSize() {return size;}
    bool isEmpty() {return size <= 0;}
    int getTop() {
        return top? top->data : -1;
        }
    void push(T data);
    T pop();
    
};
template <typename T>
void Stack<T>::push(T data) {
    Node<T> *newNode = new Node<T>(data);
    if(top == nullptr) {
        top = newNode;
    }
    else {
        newNode->prev = top;
        top = newNode;
    }
    size++;
    return;
}
template <typename T>
T Stack<T>::pop() {
    if(top == nullptr) {
        return -1;
    }
    Node<T> *walker = top;
    T popRTN = top->data;
    top = top->prev;
    delete walker;
    size--;

    return popRTN;
}

int main()
{
    Stack<int> st;
    int input;
    cin >> input;
    string cmd;
    for(int i = 0; i < input; i++ ) {
        cin >> cmd;
        // cout << "now i is : " << i << "\n";
        if(cmd == "push") {
            int data;
            cin >> data;
            st.push(data);
        }
        else if(cmd == "pop" ) {
            cout << st.pop() << "\n";
        }
        else if(cmd == "size" ) {
            cout << st.getSize() << "\n";
        }
        else if(cmd == "empty" ) {
            if(st.isEmpty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if(cmd == "top" ) {
            cout << st.getTop() << "\n";
        }
    }
    return 0;
}