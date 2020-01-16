#include "Employee.hpp"


Employee::Employee(const std::string &name,
                   const std::string &lastName,
                   const std::string& PESEL,
                   const std::string& addres,
                   const std::string& sex,
                   const int &earnings)
        :Person(name, lastName, PESEL, addres, sex), earnings(earnings){}



Employee::Employee(Person &p, int &earnings)
            :Person(p)
            ,earnings(earnings){}
            
Employee::Employee()
{
        sex = generateSex();

        if(sex == "Male")
        {
                name = generateRandomMaleName();
        }
        if(sex == "Female")
        {
                name = generateRandomFemaleName();
        }

        lastName = generateRandomLastName();
        PESEL = generateRandomPesel();
        address = generateRandomStreet();
        earnings = generateRandomEarnings();
}


Employee::~Employee(){}

void Employee::setEarnings(int earnings)
{
        this->earnings = earnings;
}

int Employee::getEarnings() const
{
        return earnings;
}

int Employee::generateRandomEarnings() const 
{
        std::random_device generator;
        std::uniform_int_distribution<int> distribution(10, 100000);

        return distribution(generator);
}

void Employee::setData()
{
        std::cout << "Podaj imie: ";
        std::cin >> name;
        std::cout << "Podaj nazwisko: ";
        std::cin >> lastName;
        std::cout << "Podaj ulice: ";
        std::cin >> address;
        std::cout << "Podaj plec: ";
        std::cin >> sex;
        std::cout << "Podaj place: ";
        std::cin >> earnings;

}

std::string Employee::getData() const
{
    std::string data;
    data = "Name: " + name + "\n" + "Lastname: " + lastName
        + "\n" + "Pesel: " + PESEL + "\n" + "Address: " + address + "\n"
        + "Sex: " + sex + "\n" + "Salary: " + std::to_string(earnings) + "\n";

    return data;
}