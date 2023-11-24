#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <string>

enum class Gender
{
    Male,
    Female,
    Count
};

class Person
{
protected:
    std::string name_;
    std::string lastName_;
    std::string PESEL_;
    std::string address_;
    Gender gender_;         
public:
    Person();
    Person(const std::string &name,
        const std::string &lastName,
        const std::string &PESEL,
        const std::string &address,
        const Gender &gender);
    virtual ~Person();
    virtual void setData() = 0;
    virtual std::string getData() const = 0;
    std::string getPESEL() const;
    std::string getLastName() const;
    std::string generateRandomMaleName() const;
    std::string generateRandomFemaleName() const;
    std::string generateRandomLastName() const;
    std::string generateRandomPesel() const;
    std::string generateRandomStreet() const;
    std::string enumGenderToString(const Gender&) const;
    Gender generateSex() const;
};