#include "Student.hpp"
#include <time.h>
#include <iostream>
#include <algorithm>
#include <random>


Student::Student(const std::string & name,
    const std::string & lastName,
    const std::string &PESEL,
    const std::string &address,
    const std::string &sex,
    int index)
    : name(name)
    , lastName(lastName)
    , PESEL(PESEL)
    , address(address)
    , sex(sex)
    , index(index)
{}

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


std::string Student::getPESEL() const
{
    return PESEL;
}

std::string Student::getLastName() const
{
    return lastName;
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

std::string  Student::generate() const
{

    auto randchar = []() -> char
    {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(10, 0);
    std::generate_n(str.begin(), 10, randchar);
    return str;
}

std::string Student::generateRandomMaleName() const
{
    std::string Names[15] = { "Michal", "Andrzej", "Pawel", "Marek", "Karol",
                            "Norbert", "Mateusz", "Krystian", "Damian", "Janusz",
                            "Szymon", "Wojtek", "Stanislaw", "Jonasz", "Jozef" };

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return Names[distribution(generator)];

}

std::string Student::generateRandomFemaleName() const
{

    std::string Names[15] = { "Oliwia", "Ania", "Patrycja", "Michalina", "Dominika",
                            "Zuzia", "Paulina", "Kasia", "Karolina", "Janina",
                            "Zosia", "Wiktoria", "Stanislawa", "Edyta", "Maria" };

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return Names[distribution(generator)];
}

std::string Student::generateRandomLastName() const
{
    std::string LastNames[15] = { "Ozga", "Barski", "Woronowicz", "Pioro", "Frac",
                            "Niestoj", "Dubinski", "Mazurkiewicz", "Winiarczyk", "Pach",
                            "Opoka", "Kaniowski", "Bieda", "Rada", "Jedruski" };

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return LastNames[distribution(generator)];
}

std::string Student::generateRandomPesel() const
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution1(10'0100, 99'1230);
    std::string pesel = (std::to_string(distribution1(generator)));

    std::uniform_int_distribution<int> distribution2(10'000, 99'999);

    pesel += (std::to_string(distribution2(generator)));
    return pesel;
}

int Student::generateRandomIndex() const
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(100'000, 300'000);
    return distribution(generator);
}

std::string Student::generateRandomStreet() const
{

    std::string Street[5] = { "Ul Barska", "Ul 3 Maja", "Ul Bernarda Belotta Canaletta", "Ul Zwyciestwa", "Ul Przegranej" };

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 4);

    return Street[distribution(generator)];

}

std::string Student::generateSex() const
{
    std::string Street[2] = { "Male", "Female" };

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 1000);

    return Street[(distribution(generator)) % 2]; // odd returns 1 even returns 0
}