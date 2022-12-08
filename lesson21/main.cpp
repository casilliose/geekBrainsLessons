#include <iostream>
#include <thread>
#include <string>
#include <algorithm>
#include <mutex>
#include <vector>
#include <unistd.h>

using namespace std;

class pcout {
   private:
      mutex m;
   public:
      string str;
      pcout(string _str) {
         str = _str;
      }
      void printStr() {
         m.lock();
         cout << str << endl;
         m.unlock();
      }
};

class PrimeNumber {
   private:
      int number {1};
      int currentCalculation {1};
      int primeNumber {1};
      bool isStart {true};
   public:
      void readNumber() {
         cout << "Введите число" << endl;
         cin >> number;
      }
      bool isPrimeNumber(int num) {
         for (int j = 2; j < num; j++) {
            if (num % j == 0 && num != j) {
               return false;
            }
         }
         return true;
      }
      void calculation() {
         thread th([&]() {
            int currentPrimeNumber;
            for (int i = 2; i < number; i++) {
               currentCalculation = i;
               if (isPrimeNumber(i)) {
                  primeNumber = i;
               }
            }
            isStart = false;
         });
         th.detach();
      }
      void progressBar() {
         cout << "Вычисляем число " << currentCalculation << endl;
      }
      void start() {
         readNumber();
         calculation();
         while(isStart) {
            progressBar();
         }
         cout << "Простое число = " << primeNumber << endl;
      }
};

class Steel {
   private:
      vector<int> thing;
   public:
      void addThing() {
         srand(time(0));
         thread th([&]() {
            this_thread::sleep_for(1s);
            thing.push_back(rand());
         });
         th.join();
      }
      void removeThing() {
         thread th([&]() {
            sleep(500);
            sort(thing.begin(), thing.end(), greater<int>());
            thing.erase(thing.begin(), thing.begin());
         });
         th.join();
      }
      void print() {
         for (auto i: thing)
            cout << i << ' ';
      }
      void start() {
         addThing();
         addThing();
         addThing();
         addThing();
         addThing();
         while(thing.size() > 0) {
            addThing();
            removeThing();
            print();
         }
      }
};

int main() {
   // home work 1
   pcout pcout1("1");
   thread th(&pcout::printStr, &pcout1);
   th.join();
   pcout pcout2("2");
   thread th2(&pcout::printStr, &pcout2);
   th2.join();

   // hone work 2
   PrimeNumber prime;
   prime.start();

   // home work 3
   Steel st;
   st.start();
   return 0;
}