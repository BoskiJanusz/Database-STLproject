#include "Student.hpp"

Student::Student(const std::string & name,
    const std::string & lastName,
    const std::string &PESEL,
    const std::string &address,
    const Gender &gender,
    const int &index)
    : Person(name, lastName, PESEL, address, gender), index_(index){}

Student::Student(Person &p, int& index)
            :Person(p)
            ,index_(index){}

Student::Student()
{
    gender_ = generateSex();
    if (gender_ == Gender::Female)
    {
        name_ = generateRandomFemaleName();
    }
    if (gender_ == Gender::Male)
    {
        name_ = generateRandomMaleName();
    }
    lastName_ = generateRandomLastName();
    PESEL_ = generateRandomPesel();
    address_ = generateRandomStreet();
    index_ = generateRandomIndex();
}

Student::~Student() {};

int Student::getIndex() const
{
    return index_;
}

std::string Student::getData() const
{
    std::string data = "";
    data = "Name: " + name_ + "\n" + "Lastname: " + lastName_
        + "\n" + "Pesel: " + PESEL_ + "\n" + "Address: " + address_ + "\n"
        + "Sex: " + enumGenderToString(gender_) + "\n" + "Index: " + std::to_string(index_) + "\n";

    return data;
}

void Student::setIndex(const int& index)
{
    index_ = index;
}

void Student::setData() 
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
    std::cout << "Index: ";
    std::cin >> index_;

}

int Student::generateRandomIndex() const
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(100'000, 300'000);

    return distribution(generator);
}