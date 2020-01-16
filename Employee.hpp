#pragma once
#include "Person.hpp"
#include <string>
#include <iostream>


class Employee : public   Person
{
    int earnings;

    public:
        Employee(const std::string &name,
                 const std::string &lastName,
                 const std::string& PESEL,
                 const std::string& addres,
                 const std::string& sex,
                 const int &earnings);
        Employee(Person &p, int& earnings);
        Employee();
        ~Employee();

        void setData();
        void setEarnings(int);
        std::string getData() const;

        int getEarnings() const;
        int generateRandomEarnings() const;

        virtual int getIndex() const {return 0;};
        virtual int generateRandomIndex() const {return 0;};
};