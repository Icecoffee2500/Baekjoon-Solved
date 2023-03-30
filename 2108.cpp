// 산술평균, 중앙값, 최빈값, 범위 구하기
// vector<pair<int, int>>로 저장 -> 들어올 때마다 <숫자, 1>로 저장 -> 만약에 이미 있는 숫자면 그 숫자의 count++

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// 노드 클래스
class Node
{
public:
    pair<int, int> data;
    Node* left;
    Node* right;

    Node(int num, int count)
    {
        data = make_pair(num, count);
        left = nullptr;
        right = nullptr;
    }
    ~Node() {}
};

// BST 클래스
class BST
{
private:
    Node* root;
    int bst_size;
    vector<pair<int, int>> sorted;
public:
    BST() {root = NULL; bst_size = 0;}
    ~BST() {}

    void printSortedVector();
    Node* getRoot() { return root; }
    int getSize() { return bst_size; }
    void Insert(int num);
    int getMin();
    int getMax();
    int getADV();
    int getMedian();
    int getMode();
    int getRange();
    void Inorder(Node* walker);
};
void BST::Insert(int num)
{
    Node* newNode = new Node(num, 1);
    if(root == nullptr) {
        root = newNode;
        bst_size++;
        return;
    }
    Node* walker = root;
    
    while(1){
        if(walker->data.first < num) {
            if(walker->right == nullptr) {
                walker->right = newNode;
                bst_size++;
                break;
            }
            walker = walker->right;
        }
        if(walker->data.first > num) {
            if(walker->left == nullptr) {
                walker->left = newNode;
                bst_size++;
                break;
            }
            walker = walker->left;
        }
        if(walker->data.first == num) {
            walker->data.second++;
            bst_size++;
            delete newNode;
            break;
        }
    }
    
    return;
}
void BST::Inorder(Node* walker)
{
    if(walker) {
        Inorder(walker->left);
        sorted.push_back(make_pair(walker->data.first, walker->data.second));
        Inorder(walker->right);
    }

    return;
}
void BST::printSortedVector()
{
    for(auto& ele : sorted) {
        cout << "(" << ele.first << ", " << ele.second << ") ";
    }
}
int BST::getMin()
{
    Node* walker = root;
    while(walker->left != nullptr) {
        walker = walker->left;
    }
    return walker->data.first;
}
int BST::getMax()
{
    Node* walker = root;
    while(walker->right != nullptr) {
        walker = walker->right;
    }
    return walker->data.first;
}
// 산술평균 구하기
int BST::getADV()
{
    float sum = 0;
    int total = 0;
    for(auto &ele : sorted) {
        sum += ele.first * ele.second;
        total += ele.second;
    }

    return (int)floor(sum/total + 0.5);
}
// 중간값 구하기
int BST::getMedian()
{
    int middle = (bst_size + 1) / 2 - 1;
    int temp = 0;
    int real_middle;
    
    for(int i = 0; i < sorted.size(); i++) {
        temp += sorted.at(i).second;
        if(temp > middle) {
            real_middle = i;
            break;
        }
    }
    int Median;
    try {
        Median = sorted.at(real_middle).first;
    }
    catch(std::out_of_range& e) {
        std::cout << "예외 발생 ! " << e.what() << std::endl;
    }
    return Median;
}
// 최빈값 구하기
int BST::getMode()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int Mode_count = 0;
    int Mode;
    for(auto& ele : sorted) {
        if(ele.second == Mode_count) {
            pq.push(ele.first);
        }
        else if(ele.second > Mode_count) {
            Mode_count = ele.second;
            while(!pq.empty()) {
                pq.pop();
            }
            pq.push(ele.first);
        }
    }
    pq.pop();
    Mode = pq.top();
    return Mode;
}
// 범위 구하는 함수
int BST::getRange()
{
    return getMax() - getMin();
}

int main()
{
    // 변수들 선언 및 입력받기
    int input_count;
    int input;
    cin >> input_count;

    BST* bst = new BST(); // BST 생성

    for(int i = 0; i < input_count; i++)
    {
        cin >> input;
        bst->Insert(input);
    }
    
    bst->Inorder(bst->getRoot());

    cout << bst->getADV() << "\n";
    cout << bst->getMedian() << "\n";
    cout << bst->getMode() << "\n";
    cout << bst->getRange() << "\n";

    return 0;
}