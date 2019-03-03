#pragma once
#include <string>

class Student
{
private:
    std::string name;
    std::string lastName;
    std::string PESEL;
    std::string address;
    std::string sex;
    int index;

public:
    Student(const std::string &name,
        const std::string &lastName,
        const std::string &PESEL,
        const std::string &address,
        const std::string &sex,
        int index);
    Student();
    ~Student();
    int getIndex() const;
    std::string getPESEL() const;
    std::string getLastName() const;
    std::string getData() const;
    std::string generate() const;
    std::string generateRandomMaleName() const;
    std::string generateRandomFemaleName() const;
    std::string generateRandomLastName() const;
    std::string generateSex() const;
    std::string generateRandomPesel() const;
    std::string generateRandomStreet() const;
    int  generateRandomIndex() const;
    void setData();

};