#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <random>


class Person
{
    protected:
         std::string name;
         std::string lastName;
         std::string PESEL;
         std::string address;
         std::string sex;
    public:
    Person();
    Person(const std::string &name,
        const std::string &lastName,
        const std::string &PESEL,
        const std::string &address,
        const std::string &sex);

        virtual void setData();
        virtual std::string getData() const;

        virtual int getIndex() const  = 0;
        virtual int generateRandomIndex() const = 0;

        virtual int getEarnings() const = 0;
        virtual int generateRandomEarnings() const = 0;
        virtual void setEarnings(int) = 0;

        std::string getPESEL() const;
        std::string getLastName() const;
        std::string generate() const;
        std::string generateRandomMaleName() const;
        std::string generateRandomFemaleName() const;
        std::string generateRandomLastName() const;
        std::string generateSex() const;
        std::string generateRandomPesel() const;
        std::string generateRandomStreet() const;

    ~Person();


};