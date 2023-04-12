#pragma once
#include "Person.hpp"
#include <string>
#include <iostream>

class Student : public Person
{
private:
    int index_;
    void setIndex(const int);
    int getIndex() const;
public:
    Student(const std::string &name,
            const std::string &lastName,
            const std::string &PESEL,
            const std::string &address,
            const Gender &gender,
            const int& index);
    Student(Person &p, int& index);
    Student();
    ~Student();
    void setData() override;
    void setNumber(const int) override;
    void modifyStudentByIndex(const int);
    std::string getData() const override;
    int getNumber() const override;
    int generateRandomIndex() const;
};