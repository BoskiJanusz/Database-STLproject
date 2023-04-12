#include "Employee.hpp"

Employee::Employee(const std::string &name,
                   const std::string &lastName,
                   const std::string& PESEL,
                   const std::string& addres,
                   const Gender& gender,
                   const int &earnings)
        :Person(name, lastName, PESEL, addres, gender), earnings_(earnings){}

Employee::Employee(Person &p, int &earnings)
            :Person(p)
            ,earnings_(earnings){}
 
Employee::Employee()
{
        gender_ = generateSex();
        if(gender_ == Gender::Male)
        {
                name_ = generateRandomMaleName();
        }
        if(gender_ == Gender::Female)
        {
                name_ = generateRandomFemaleName();
        }

        lastName_ = generateRandomLastName();
        PESEL_ = generateRandomPesel();
        address_ = generateRandomStreet();
        earnings_ = generateRandomEarnings();
}

Employee::~Employee(){}

void Employee::setEarnings(int earnings)
{
        this->earnings_ = earnings;
}

int Employee::getEarnings() const
{
        return earnings_;
}

int Employee::getNumber() const
{
        return Employee::getEarnings();
}

int Employee::generateRandomEarnings() const 
{
        std::random_device generator;
        std::uniform_int_distribution<int> distribution(10, 100000);

        return distribution(generator);
}

void Employee::setData()
{
        std::cout << "Name: ";
        std::cin >> name_;
        std::cout << "Last name: ";
        std::cin >> lastName_;
        std::cout << "Street: ";
        std::cin >> address_;
        int sex;
        std::cin >> sex;
        gender_ = static_cast<Gender>(sex);
        std::cout << "Salary: ";
        std::cin >> earnings_;
}

void Employee::setNumber(int number)
{
        Employee::setEarnings(number);
}

std::string Employee::getData() const
{
    std::string data;
    data = "Name: " + name_ + "\n" + "Lastname: " + lastName_
        + "\n" + "Pesel: " + PESEL_ + "\n" + "Address: " + address_ + "\n"
        + "Sex: " + enumGenderToString(gender_) + "\n" + "Salary: " + std::to_string(earnings_) + "\n";

    return data;
}