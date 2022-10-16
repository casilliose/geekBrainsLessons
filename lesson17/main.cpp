#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "timer.h"

using namespace std;

template <typename T>
void swap(T* const t1, T* const t2) {
    T temp = t1;
    t1 = t2;
    t2 = temp;
    return;
}

template <typename T> 
void SortPointers(vector<T*>&vec) {
   sort(vec.begin(), vec.end(), [&](T* first, T* second){
         return *first > *second;
   });
}

int main () {
    cout << "Home work 1" << endl;
    int a = 8, b = 3;
    cout << "a address = " << &a << " a result = " << a << endl;
    cout << "b address = " << &b << " b result = " << b << endl;
    swap <int> (a,b);
    cout << "a address = " << &a << " a result = " << a << endl;
    cout << "b address = " << &b << " b result = " << b << endl;
    cout << endl;
    
    cout << "Home work 2" << endl;
    int c = 1, d = 2, g = 3, r = 5;
    vector<int*> vec;
    vec.push_back(&c);
    vec.push_back(&d);
    vec.push_back(&g);
    vec.push_back(&r);
    SortPointers<int>(vec);
    for (int* i: vec)
        std::cout << *i << ' ';
    cout << endl << endl;   

    cout << "Home work 3" << endl;
    string line;
    ifstream file("war_and_world.txt");
    getline(file, line);
    // my variant release
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    int countVowels {0};
    Timer timer("for and count");
    for (char symbol : vowels) {
        countVowels += count(line.begin(), line.end(), symbol);
    }
    cout << "count = " << countVowels << endl;
    timer.print();
    cout << endl;
   
    timer.start("count_if и find");
    countVowels = 0;
    countVowels = count_if(
        line.begin(),
        line.end(),
        [vowels](char symbol) -> bool {
            return find(vowels.begin(), vowels.end(), symbol) != vowels.end();
        });
    cout << "count_if и find = " << countVowels << endl;
    timer.print();
    cout << endl;

    timer.start("count_if и цикл for");
    countVowels = 0;
    countVowels = count_if(
        line.begin(),
        line.end(),
        [vowels](char symbol) -> bool {
            for (char nextSymbol : vowels) {
                if (nextSymbol == symbol) {
                    return true;
                }
            }
            return false;
        });
    cout << "count_if и цикл for = " << countVowels << endl;
    timer.print();
    cout << endl;

    timer.start("цикл for и find");
    countVowels = 0;
    for (char currentSymbol : line) {
        if (find(vowels.begin(), vowels.end(), currentSymbol) != vowels.end()) {
            countVowels++;
        }
    }
    cout << "цикл for и find = " << countVowels << endl;
    timer.print();
    cout << endl;

    timer.start("2 цикла for");
    countVowels = 0;
    for (char currentSymbol : line) {
        for (char findSymbol : vowels) {
            if (currentSymbol == findSymbol) {
                countVowels++;
            }
        }
    }
    cout << "2 цикла for = " << countVowels << endl;
    timer.print();
    cout << endl;

    cout << endl;
    return 0;
}