// circular linked list로 풀자
#include <iostream>

using namespace std;

template <typename T>
struct node
{
public:
    T data;
    node *next;

    node<T>(T data) {this->data = data; next = nullptr;}
    ~node<T>() {}
};

template <typename T>
class CLL
{
private:
    node<T> *head;
    int length = 0;
public:
    CLL() { head = nullptr; }
    ~CLL() {
        while(!isEmpty()) {
            Delete(1);
        }
    }
    void Insert(T data);
    void Delete(int order);
    bool isEmpty();
};
template <typename T>
void CLL<T>::Insert(T data)
{
    node<T> *newNode = new node<T>(data);
    if(head == nullptr) {
        head = newNode;
        head->next = head;
        length++;
        return;
    }
    node<T> *walker = head;
    while(walker->next != head) {
        walker = walker->next;
    }
    
    walker->next = newNode;
    
    newNode->next = head;
    length++;

    return;
}
template <typename T>
void CLL<T>::Delete(int order)
{
    //cout << "this is DELETE : " << order << "\n";
    int delete_num;
    if(length <= 0) {
        return;
    }
    node<T> *walker = head;
    node<T> *prev = nullptr;
    if(order == 1) {
        order += length;
    }

    for(int i = 1; i < order; i++) {
        prev = walker;
        walker = walker->next;
    }
    delete_num = walker->data;
    if(length > 1) {
        prev->next = walker->next;
    }
    walker->next = nullptr;
    delete walker;
    length--;
    head = prev->next;
    cout << delete_num;

    return;
}
template <typename T>
bool CLL<T>::isEmpty()
{
    return (length == 0);
}

int main()
{
    int N, K;
    cin >> N >> K;
    CLL<int> cll;
    
    for(int i = 1; i < N + 1; i++) {
        cll.Insert(i);
    }
    cout << "<";
    for(int i = 1; i < N; i ++) {
        cll.Delete(K);
        cout  << ", ";
    }
    cll.Delete(K);
    cout << ">\n";

    return 0;
}