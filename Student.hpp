#pragma once
#include "Person.hpp"
#include <string>
#include <iostream>


class Student : public   Person
{
private:
   
    int index;

public:
    Student(const std::string &name,
            const std::string &lastName,
            const std::string &PESEL,
            const std::string &address,
            const std::string &sex,
            const int& index);
    Student(Person &p, int& index);
    Student();
    ~Student();

    void setData();
    std::string getData() const;

    int getIndex() const;
    int generateRandomIndex() const;

    virtual int getEarnings() const {return 0;};
    virtual int generateRandomEarnings() const {return 0;};
    virtual void setEarnings(int) {};

};