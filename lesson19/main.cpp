#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

template<typename T>
void insert_sorted(T item, vector<T> &arr) {
    arr.push_back(item);
    sort(arr.begin(), arr.end());
}

template<typename TT>
void print(vector<TT> const &arr) {
    for_each(arr.begin(), arr.end(), [](TT i) { cout << i << endl; });
}

int main() {
    // home work 1
    vector<int> arr {1,2,3,4,5,6,7,8,9};
    insert_sorted<int>(2, arr);
    print<int>(arr);
    cout << endl;

    // home work 2
    vector<float> a;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(1, 10);
    for (int i = 0; i < 100; i++) {
        a.push_back(dist(gen));
    }
    print<float>(a);
    vector<int> b;
    for (int i = 0; i < 100; i++) {
        b.push_back(static_cast<int>(a[i]));
    }
    print<int>(b);
    int inc = 0;
    cout << "different analog and cifra = " << accumulate(begin(a),end(a),0.0, [&inc, b](float x, float y){
        x = powf(y - b[inc], 2);
        inc++;
        return x;
    });
    return 0;
}