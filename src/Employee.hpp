#pragma once

#include "Person.hpp"
#include <string>
#include <iostream>

class Employee : public   Person
{
    int earnings_;
    void setEarnings(int);
    int getEarnings() const;
public:
    Employee(const std::string &name,
                const std::string &lastName,
                const std::string& PESEL,
                const std::string& addres,
                const Gender& sex,
                const int &earnings);
    Employee(Person &p, int& earnings);
    Employee();
    ~Employee();
    void setData() override;
    void setNumber(const int) override;
    std::string getData() const override;
    int getNumber() const override;
    int generateRandomEarnings() const;
};