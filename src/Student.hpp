#pragma once
#include <iostream>
#include <string>
#include "Interfaces.hpp"
#include "Person.hpp"

class Student : public Person,
                public Indexable {
private:
    int index_;

public:
    Student(const std::string& name,
            const std::string& lastName,
            const std::string& PESEL,
            const std::string& address,
            const Gender& gender,
            const int& index);
    Student(Person& p, int& index);
    Student();
    ~Student();
    void setData() override;
    void setIndex(const int&) override;
    void modifyStudentByIndex(const int);
    std::string getData() const override;
    int getIndex() const override;
    int generateRandomIndex() const;
};