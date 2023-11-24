#pragma once

#include <iostream>
#include <string>
#include "Interfaces.hpp"
#include "Person.hpp"

class Employee : public Person,
                 public Salaryable {
private:
    int earnings_;

public:
    Employee(const std::string& name,
             const std::string& lastName,
             const std::string& PESEL,
             const std::string& addres,
             const Gender& sex,
             const int& earnings);
    Employee(Person& p, int& earnings);
    Employee();
    ~Employee();
    void setData() override;
    void setSalary(const int&) override;
    std::string getData() const override;
    int getSalary() const override;
    int generateRandomEarnings() const;
};