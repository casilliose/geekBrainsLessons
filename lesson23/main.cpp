#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "../lesson16/main.cpp"

using namespace std;

TEST(extractFio, extractFio) {
    tuple<string,string,string> fie("Ильин", "Петр", "Артемович");
    tuple<string,string,string> fie2("Test", "test", "test");
    ASSERT_TRUE(fie == Lesson1::extractFio("Ильин Петр Артемович +7(17)455767 57"));
    ASSERT_FALSE(fie2 == Lesson1::extractFio("Ильин Петр Артемович +7(17)455767 57"));
}

TEST(extractPhone, extractPhone) {
    tuple<uint,uint,string,uint> fie(7, 17, "455767", 57);
    tuple<uint,uint,string,uint> fie2(1, 17, "455767", 57);
    ASSERT_TRUE(fie == Lesson1::extractPhone("Ильин Петр Артемович +7(17)455767 57"));
    ASSERT_FALSE(fie2 == Lesson1::extractPhone("Ильин Петр Артемович +7(17)455767 57"));
}

int main(int argc, const char ** argv) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
   
    // auto fie = Lesson1::extractFio();
    // cout << get<0>(fie) << " " << get<1>(fie) << " " << get<2>(fie) << endl;
}