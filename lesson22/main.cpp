#include <iostream>
#include <fstream>
#include ".pb.h"

using namespace std;

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл  
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
    virtual double GetAverageScore(const MyNameSpace::FullName& name) = 0;
    virtual string GetAllInfo(const MyNameSpace::FullName& name) = 0;
    virtual string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, public IMethods {
    private:
        MyNameSpace::Student studentMap[3];
    public:
        void StudentsGroup(MyNameSpace::Student st) {
            studentMap = st;
        }
        void Open() {
            ifstream in("~/.conan/data/protobuf/3.17.1/_/_/package/3c46b99f1f6ceb18db163abcd9d9d56913b97edc/bin/protoc-3.17.1.0", ios_base::binary);
            for (auto item : studentMap) {
                if (item.ParseFromIstream(&in)){
                    cout << item.nameStudent.Name << " " << item.nameStudent.MiddleName << " " << item.nameStudent.LastName << " " << item.gpa << endl;
                } else{
                    cout << "Error!" << endl;
                }
            }
        }
        void Save() {
            ofstream out("~/.conan/data/protobuf/3.17.1/_/_/package/3c46b99f1f6ceb18db163abcd9d9d56913b97edc/bin/protoc-3.17.1.0", ios_base::binary);
            for (auto item : studentMap) {
                cout << item.nameStudent.Name << " " << item.nameStudent.MiddleName << " " << item.nameStudent.LastName << " " << item.gpa << endl;
            }
            studentMap.SerializeToOstream(&out);
        }
        double GetAverageScore(const MyNameSpace::FullName& name) {
            for (auto item : studentMap) {
                if (item.nameStudent.Name == name.nameStudent.Name && item.nameStudent.LastName == name.nameStudent.LastName) {
                    return item.gpa;
                }
            }
            return 0.0;
        }
        string GetAllInfo(const MyNameSpace::FullName& name) {
            for (auto item : studentMap) {
                if (item.nameStudent.Name == name.nameStudent.Name && item.nameStudent.LastName == name.nameStudent.LastName) {
                    return item.nameStudent.LastName + " " +  item.nameStudent.MiddleName + " " + item.nameStudent.LastName;
                }
            }
            return "";
        }
}

int main() {
    MyNameSpace::FullName st1Name;
    st1Name.set_Name("name_Test1");
    st1Name.set_LastName("last_name_test1");
    MyNameSpace::Student st1;
    st1.set_nameStudent(st1Name);
    st1.set_ratingsMap([1,2,3,4,5]);
    st1.set_gpa(3.0);
    StudentsGroup sg(st1);
    sg.Save();
    sg.Open();
    sg.GetAllInfo();
    sg.GetAverageScore();
    return 0;
}