#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

int * initArray(size_t n)
{
    int * newArray {nullptr};
    newArray = new  (std::nothrow) int[n];
    if (newArray == nullptr) {
        throw "Не достаточно памяти, введите поменьше размер массива !!!";
    }
    return newArray;
}

void setArrayToPowerOfTwo(int * newArray, size_t n)
{
    newArray[0] = 1;
    for (size_t i = 1; i < n; i++) {
        newArray[i] = newArray[i - 1] * 2;
    }
}

void printArray(int * arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << (n - 1 == i ? ""  : ", ");
    }
}

void freeArray(int *& arr)
{
    delete[] arr;
    arr = nullptr;
}

size_t getInputSizeArray(char s = ' ')
{
    cout << "Введите размер массива " << s << ":" << endl;
    size_t n {0};
    cin >> n;
    if (cin.fail()) {
        cout << "Ошибка. нужно вводить только целые числа!" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }
    return n;
}

void homeWorkFirst()
{
    cout << "Домашняя работа 1" << endl;
    size_t sizeAr = getInputSizeArray();
    int * linkArr = initArray(sizeAr);
    setArrayToPowerOfTwo(linkArr, sizeAr);
    printArray(linkArr, sizeAr);
    freeArray(linkArr);
    cout << endl << endl;
}

int ** initArray(size_t m, size_t n)
{
    int ** ptrArr;
    ptrArr = new int * [m];
    for (size_t i = 0; i < m; i++) {
        ptrArr[i] = new int[n];
    }
    return ptrArr;
}

void freeArray(int **& linkArr, size_t m)
{
    for (size_t i = 0; i < m; i++) {
        delete [] linkArr[i];
    }
    delete[] linkArr;
    linkArr = nullptr;
}

void setArrayRandNumber(int ** linkArr, size_t m, size_t n)
{
    srand(time(NULL));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            linkArr[i][j] = rand() % 100;
        }
    }
}

void printArray(int ** linkArr, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << linkArr[i][j] << (n - 1 == j ? ""  : ", ");
        }
        cout << endl;
    }
}

void homeWorkSecond()
{
    cout << "Домашняя работа 2" << endl;
    int ** ptrArr {nullptr};
    size_t m = getInputSizeArray('m');
    size_t n = getInputSizeArray('n');
    ptrArr = initArray(m, n);
    setArrayRandNumber(ptrArr, m, n);
    printArray(ptrArr, m, n);
    freeArray(ptrArr, m);
    cout << endl << endl;
}

string getNameFile(uint8_t n)
{
    cout << "Введите имя файла №" << n << " : " << endl;
    string fileName;
    cin >> fileName;
    return fileName;
}

ofstream createTxtFile(string fileName)
{
    ofstream fout(fileName+".txt");
    return fout;
}

string getRandomText(size_t sizeText)
{
    srand(time(NULL));
    char symbols[27]  = "abcdefghijklmnopqrstuvwxyz";
    string newLine;
    size_t random, i;
    for (i = 0; i < sizeText; i++) {
        random = rand()%(26);
        newLine.push_back(symbols[random]);
    }
    return newLine;
}

void homeWorkThree()
{
    cout << "Домашняя работа 3" << endl;
    string fileNameFirst = getNameFile(1);
    string fileNameSecond = getNameFile(2);
    ofstream ofOutFirst = createTxtFile(fileNameFirst);
    ofstream ofOutSecond = createTxtFile(fileNameSecond);
    string textFirst = getRandomText(70);
    string textSecond = getRandomText(100);
    ofOutFirst << textFirst;
    ofOutSecond << textSecond;
    ofOutSecond.close();
    ofOutSecond.close();
    cout << endl << endl;
}

void homeWorkFour()
{
    cout << "Домашняя работа 4" << endl;
    cout << "Введите имена файлов для склеивания" << endl;
    string fileNameFirst = getNameFile(1);
    string fileNameSecond = getNameFile(2);
    cout << "Введите имя файла с результатом" << endl;
    string fileNameThree = getNameFile(3);
    ofstream ofOutThree = createTxtFile(fileNameThree);
    string textCompare {""};
    ifstream fin(fileNameFirst+".txt");
    if (fin.is_open())
    {
        string buf;
        while (!fin.eof())
        {
            getline(fin, buf);
            textCompare.append(buf);
        }
        fin.close();
    }
    ifstream fin2(fileNameSecond+".txt");
    if (fin2.is_open())
    {
        string buf2;
        while (!fin2.eof())
        {
            getline(fin2, buf2);
            textCompare.append(buf2);
        }
        fin2.close();
    }
    ofOutThree << textCompare;
    ofOutThree.close();
    cout << endl << endl;
}

inline std::vector<std::string_view> SplitString( std::string_view input_string, const char separator )
{
    std::vector<std::string_view> parts;

    size_t part_length = 0;
    while( ( part_length = input_string.find( separator ) ) != input_string.npos )
    {
    parts.emplace_back( input_string.data(), part_length );
    input_string.remove_prefix( part_length + 1 );
    }

    if( !input_string.empty() )
    {
    parts.push_back( std::move( input_string ) );
    }

    return parts;
}

void homeWorkFive()
{
    cout << "Домашняя работа 5" << endl;
    cout << "Введите слова через пробел : " << endl;
    string words, filetext, findtext;
    getline(cin, words);
    cout << "Введите имя файла для поиска" << endl;
    cin >> filetext;
    ifstream fin(filetext+".txt");
    if (fin.is_open())
    {
        string buffer;
        while (!fin.eof())
        {
            getline(fin, buffer);
            findtext.append(buffer);
        }
        fin.close();
    }
    auto wordArr = SplitString(words, ' ');
    bool findFlag {true};
    for(auto iter=wordArr.begin(); iter!=wordArr.end(); iter++) {
        if (findtext.find(*iter) != -1) {
            cout << "Слово <" << *iter << "> найдено в тексте" << endl;
            findFlag = false;
        }
    }
    if (findFlag) {
        cout << "Слова в файле не найдены" << endl;
    }
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    try {
        homeWorkFirst();
        homeWorkSecond();
        homeWorkThree();
        homeWorkFour();
        homeWorkFive();
    } catch (string str) {
        cout << "\033[1m\033[31m" << str << "\033[0m" << endl;
    }
    return 0;
}
