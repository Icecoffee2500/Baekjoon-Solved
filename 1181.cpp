// <단어 정렬>
// 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
//  길이가 짧은 것부터
//  길이가 같으면 사전 순으로
//단, 중복된 단어는 하나만 남기고 제거해야 한다.

// 입력 : 첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.
// 출력 : 조건에 따라 정렬하여 단어들을 출력한다.

// <알고리즘>
// BST를 이용하자
// Insertion() <- 조건 다 들어가기
// InOrder_traversal로 순서대로 출력

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    Node(string word) {
        this->word = word;
        this->word_size = this->word.size();
        this->left = NULL;
        this->right = NULL;
        }
    ~Node() {}

    string word;
    int word_size;
    Node* left;
    Node* right;
};

class BST
{
private:
    Node* root;

public:
    BST() {root = NULL;}
    ~BST() {}
    void Insert(string word);
    void InOrder_traversal(Node* current);
    Node* getRoot() { return root; }
};

void BST::Insert(string word)
{
    int size = word.size();

    // 입력된 단어를 가지는 새로운 노드와 테스트노드 생성
    Node* newNode = new Node(word);

    // 만약 BST가 비어있으면 새 노드를 Root로
    if(root == NULL)
    {
        root = newNode;
        return;
    }
    /***** BST가 1개 이상의 노드를 갖고 있는 경우 *****/
    Node* walker = root;
    // 규칙에 따라 walker가 BST를 탐색
    while(walker != NULL)
    {
        // 이미 있는 단어면 삭제
        if(walker->word == word)
        {
            //cout << "this word is already Exist. DELETE {" << word << "}" << endl;
            delete newNode;
            return;
        }
        // 입력된 단어의 길이가 현재위치의 노드의 단어길이보다 크면 walker가 오른쪽 노드로 이동
        if(walker->word_size < size)
        {
            if(walker->right == NULL)
            {
                walker->right = newNode;
                return;
            }
            else
            {
                walker = walker->right;
            }
        }
        // 입력된 단어의 길이가 현재위치의 노드의 단어길이보다 작으면 walker가 왼쪽 노드로 이동
        else if(walker->word_size > size)
        {
            if(walker->left == NULL)
            {
                walker->left = newNode;
                return;
            }
            else
            {
                walker = walker->left;
            }
        }
        // 입력된 단어의 길이와 현재위치의 노드의 단어길이가 같으면 사전순으로 단어비교
        else if (walker->word_size == size)
        {
            // 입력된 단어가 현재위치의 노드의 단어보다 사전순으로 뒤에 있으면 오른쪽 노드로 이동
            if(walker->word < word)
            {
                if(walker->right == NULL)
                {
                    walker->right = newNode;
                    return;
                }
                else
                {
                    walker = walker->right;
                }
            }
            // 입력된 단어가 현재위치의 노드의 단어보다 사전순으로 앞에 있으면 왼쪽 노드로 이동
            else if(walker->word > word)
            {
                if(walker->left == NULL)
                {
                    walker->left = newNode;
                    return;
                }
                else
                {
                    walker = walker->left;
                }
            }
            // 입력된 단어와 현재위치의 노드의 단어가 같으면 새로운 노드 삭제
            else
            {
                // 단어 삭제
                cout << "What's the problem with " << newNode->word << "?" << endl;
                //delete newNode;
                return;
            }
        }
    }

    
}
void BST::InOrder_traversal(Node* current)
{
    if(current != NULL)
    {
        InOrder_traversal(current->left);
        cout << current->word << endl;
        InOrder_traversal(current->right);
    }
}

int main()
{
    // 단어의 개수 N 입력받기
    int N;
    //cout << "단어의 개수를 입력하세요 : ";
    cin >> N;
    cin.ignore();

    // BST 객체 선언 및 단어 입력
    string word;
    BST* tree = new BST();

    // 단어를 BST에 저장
    for(int i = 0; i < N; i++)
    {
        getline(cin, word);
        tree->Insert(word);
    }
    
    // 단어를 순서대로 출력
    tree->InOrder_traversal(tree->getRoot());

    return 0;
}