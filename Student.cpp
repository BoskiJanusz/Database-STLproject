#include "Student.hpp"



Student::Student(const std::string & name,
    const std::string & lastName,
    const std::string &PESEL,
    const std::string &address,
    const std::string &sex,
    const int &index)
    : Person(name, lastName, PESEL, address, sex), index(index){}



Student::Student(Person &p, int& index)
            :Person(p)
            ,index(index){}


Student::Student()
{
    sex = generateSex();
    
    if (sex == "Female")
    {
        name = generateRandomFemaleName();
    }
    if (sex == "Male")
    {
        name = generateRandomMaleName();
    }

    lastName = generateRandomLastName();
    PESEL = generateRandomPesel();
    address = generateRandomStreet();
    index = generateRandomIndex();
}


Student::~Student() {};

int Student::getIndex() const
{
    return index;
}


std::string Student::getData() const
{
    std::string data;
    data = "Name: " + name + "\n" + "Lastname: " + lastName
        + "\n" + "Pesel: " + PESEL + "\n" + "Address: " + address + "\n"
        + "Sex: " + sex + "\n" + "Index: " + std::to_string(index) + "\n";

    return data;
}

void Student::setData() 
{
    std::cout << "Podaj imie: ";
    std::cin >> name;
    std::cout << "Podaj nazwisko: ";
    std::cin >> lastName;
    std::cout << "Podaj ulice: ";
    std::cin >> address;
    std::cout << "Podaj plec: ";
    std::cin >> sex;
    std::cout << "Podaj index: ";
    std::cin >> index;

}


int Student::generateRandomIndex() const
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(100'000, 300'000);
    
    return distribution(generator);
}

