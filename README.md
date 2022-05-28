# Howe work 1

> g++ and clang++ compiler

![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-31-12.png)
 
# Home work 2

1. Препроцессинг
g++ -E main.cpp -o main.ii
Посмотрите файл main.ii: nano main.ii
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-34-26.png)
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-34-38.png)

2. Компиляция
g++ -S main.ii -o main.s
Посмотрите файл main.s: nano main.s
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-38-03.png)
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-37-25.png)

3. Ассемблирование
as main.s -o main.o
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-34-26.png)

4. Линковка
g++ main.o -o myprg
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-38-03.png)
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-38-15.png)
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-38-36.png)

5. Запуск: ./myprg
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 11-38-58.png)

# Home work 3
создать файл CMakeLists.txt с содержимым
cmake_minimum_required(VERSION 2.8)
project(MyProject1)
add_executable(main main.cpp)
выполнить команды
cmake ./
make
![Screenshot](/lesson1/screenshot/Screenshot from 2022-05-28 12-26-40.png)
