#include <iostream>
#include <cmath>

using namespace std;

long long calHash(int table[], int size, int mod);

int main()
{
    // 길이, 문자를 숫자로 담을 table, hash, modular수 초기화
    int length;
    cin >> length;
    int word[length];
    int hash;
    int mod = 1234567891;

    // 문자 입력 받으면서 숫자로 변환해서 table에 집어넣기
    for(int i = 0; i < length; i++) {
        char input;
        cin >> input;
        word[i] = (int)(input - 'a') + 1;
    }

    //calHash함수 이용해서 hash변수에 값 저장
    hash = calHash(word, length, mod);

    // hash값 출력
    cout << hash << "\n";
    
    return 0;
}

/**  Hash값 계산 함수  **/
long long calHash(int table[], int size, int mod)
{
    long long hash = 0;
    long double r = 31;
    
    for(int i = 0; i < size; i++) {
        long long element;
        long long Pow = 1; // 거듭제곱수 초기화
        int pow_n = 31; // 지수

        // i가 1일 때부터 지수 곱해줌
        if(i > 0){
            for(int j = 1; j <= i; j++) {
                Pow *= pow_n;
                // 거듭제곱수가 mod보다 커질 때마다 계속 모듈러연산. 모듈러연산의 분배법칙 덕분에 이렇게 해도 괜찮음.
                if(Pow > mod) {
                    Pow %= mod;
                }
            }
        }
        // hash에 더할 각각의 원소
        element = (long long)(table[i] * Pow) % mod;
        
        // 각각의 원소 hash에 더하기
        hash += element;
    }
    // 모듈러연산의 분배법칙 이용, 마지막으로 모듈러 연산 한번 더.
    hash %= mod;

    return hash;
}