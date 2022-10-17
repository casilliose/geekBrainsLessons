#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <memory>
#include <iterator>

using namespace std;

void addAverageListInBackList(list<float> &ls) {
    float summ {0};
    for (float i : ls) {
        summ += i;
    }
    ls.push_back(summ/ls.size());
}

class Matrix {
    uint8_t n {0};
    public:
    vector<vector<double>> matrix;
        Matrix(uint8_t n) {
            this->n = n;
            srand(time(0));
            vector<vector<double>> matrixMap(n,vector<double>(n));
            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++)
                {
                    matrixMap[i][j] = rand() % 10;
                }
            }
            this->matrix = matrixMap;
        }

        friend ostream& operator<< (ostream &out, const Matrix &mat);

        int matrixDet() {
            const double EPS = 1E-9;
            auto a = matrix;
            double det = 1;

            for (int i=0; i<n; ++i) {
                int k = i;
                for (int j=i+1; j<n; ++j)
                    if (abs (a[j][i]) > abs (a[k][i]))
                        k = j;
                if (abs (a[k][i]) < EPS) {
                    det = 0;
                    break;
                }
                swap (a[i], a[k]);
                if (i != k)
                    det = -det;
                det *= a[i][i];
                for (int j=i+1; j<n; ++j)
                    a[i][j] /= a[i][i];
                for (int j=0; j<n; ++j)
                    if (j != i && abs (a[j][i]) > EPS)
                        for (int k=i+1; k<n; ++k)
                            a[j][k] -= a[i][k] * a[j][i];
            }
            return det;
        }
};

ostream& operator<< (ostream &out, const Matrix &mat) {
    for (auto i : mat.matrix) {
        for (auto l : i) {
            out << l << " ";
        }
        out << endl;
    }
    return out;
}

template< typename Type>
class SomeSortedContainer{
    std::vector<Type> m_data;
public:
    typedef typename std::vector<Type>::iterator iterator;
    typedef typename std::vector<Type>::const_iterator const_iterator;

    iterator begin() {return m_data.begin();}
    const_iterator begin() const {return m_data.begin();}
    const_iterator cbegin() const {return m_data.cbegin();}
    iterator end() {return m_data.end();}
    const_iterator end() const {return m_data.end();}
    const_iterator cend() const {return m_data.cend();}
    void add(int item) {
        m_data.push_back(item);
    }
};

int main() {
    // home work 1
    cout << "Home work 1" << endl;
    list<float> ls {1.1, 2.1, 3};
    addAverageListInBackList(ls);
    for(float i : ls) {
        cout << i << endl;
    }
    cout << endl;

    // home work 2
    cout << "Home work 2" << endl;
    Matrix matrix(3);
    cout << matrix << endl;
    cout << "Det matrix = " << matrix.matrixDet() << endl;
    cout << endl;

    // home work 3
    cout << "Home work 3" << endl;
    SomeSortedContainer<int> sm;
    sm.add(1);
    sm.add(2);
    sm.add(3);
    for (auto item : sm) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}