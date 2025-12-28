#include <iostream>
#include <string>  // 用于使用string类型存储姓名

int main() {
    // 定义变量：姓名（字符串）、年龄（整数）、体重（浮点数）
    std::string name = "李明";  // 存储个人姓名的字符串变量
    int age = 18;               // 存储个人年龄的整数变量
    double weight = 65.5;       // 存储个人体重的浮点型变量（单位：kg）

    // 按照指定格式输出个人信息
    std::cout << "姓名：" << name << "，年龄：" << age << "岁，体重：" << weight << "kg" << std::endl;

    return 0;
}