//
// Created by AbhishekJalkhare on 29-01-2026.
//

#ifndef CPPLEARNING_TASK2_H
#define CPPLEARNING_TASK2_H
#include <string>


class  Student{
    std::string name;
    int rollNo{};
    int marks{};
public:
    Student(const std::string& name , int rollNo , int marks);
    [[nodiscard]]const std::string& getName ()const;
    [[nodiscard]] int getRollNo() const;
    [[nodiscard]] int getMarks() const;
    void setName(const std::string& name);
    void setRollNo(int roll) ;
    void setMarks(int marks);
};


#endif //CPPLEARNING_TASK2_H