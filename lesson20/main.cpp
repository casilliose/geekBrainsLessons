#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_set>
#include <iterator>
#include <ostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

template<typename T>
void print(_List_iterator<T> begin, _List_iterator<T> end) {
    unordered_set<T> map;
    copy(begin, end, inserter(map, map.end()));
    for_each(map.begin(), map.end(), [](T word) { cout << word << endl; });
}

void homeWork2() {
    unordered_multiset<string> suggestions;
    int i {1};
    string text;
    while (i <= 5) {
        cout << "Write suggestion №" << i << endl;
        i++;
        getline(cin, text);
        suggestions.insert(text);
    }
    map<string, int> mapWordsAndCountInSuggestion;
    string word;
    const char delim {' '};
    for_each(suggestions.begin(), suggestions.end(), [&mapWordsAndCountInSuggestion, &word, delim](string const &suggestion) {
        stringstream steamSuggestion(suggestion);
        int countWord {0};
        while (getline(steamSuggestion, word, delim)) {
            countWord++;
        }
        mapWordsAndCountInSuggestion[suggestion] = countWord;
    });
    vector<pair<string, int>> words(mapWordsAndCountInSuggestion.begin(), mapWordsAndCountInSuggestion.end());
    sort(words.begin(), words.end(), [](const auto& l, const auto& r) {
        return l.second > r.second;
    });
    for_each(words.begin(), words.end(), [](pair<string, int> word) { cout << word.first << " = " << word.second << endl; });
}

int main() {
    // home work 1
    list<string> words {"aaa", "bbb", "aaa"};
    print<string>(words.begin(), words.end());
    list<int> number {1,1,2,2,3,4,5,6,6};
    print<int>(number.begin(), number.end());

    // home work 2
    cout << endl;
    homeWork2();
    return 0;
}