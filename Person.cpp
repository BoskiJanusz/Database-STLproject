#include "Person.hpp"

Person::Person(const std::string &name,
               const std::string &lastName,
               const std::string &PESEL,
               const std::string &address,
               const std::string &sex)
    : name(name), lastName(lastName), PESEL(PESEL), address(address), sex(sex)
{
}

Person::~Person(){};

Person::Person()
{
    sex = generateSex();
    if (sex == "Male")
    {
        name = generateRandomMaleName();
    }
    if (sex == "Female")
    {
        name = generateRandomMaleName();
    }

    lastName = generateRandomLastName();
    PESEL = generateRandomPesel();
    address = generateRandomStreet();
}

std::string Person::getPESEL() const
{
    return PESEL;
}

std::string Person::getLastName() const
{
    return lastName;
}

std::string Person::getData() const
{
    std::string data;
    data = "Name: " + name + "\n" + "Lastname: " +
    lastName + "\n" + "Pesel: " + PESEL + "\n" + "Address: " +
    address + "\n" + "Sex: " + sex + "\n";

    return data;
}

void Person::setData()
{
    std::cout << "Podaj imie: ";
    std::cin >> name;
    std::cout << "Podaj nazwisko: ";
    std::cin >> lastName;
    std::cout << "Podaj ulice: ";
    std::cin >> address;
    std::cout << "Podaj plec: ";
    std::cin >> sex;
}

std::string Person::generateRandomMaleName() const
{
    std::string Names[15] = {"Michal", "Andrzej", "Pawel", "Marek", "Karol",
                             "Norbert", "Mateusz", "Krystian", "Damian", "Janusz",
                             "Szymon", "Wojtek", "Stanislaw", "Jonasz", "Jozef"};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return Names[distribution(generator)];
}

std::string Person::generateRandomFemaleName() const
{

    std::string Names[15] = {"Oliwia", "Ania", "Patrycja", "Michalina", "Dominika",
                             "Zuzia", "Paulina", "Kasia", "Karolina", "Janina",
                             "Zosia", "Wiktoria", "Stanislawa", "Edyta", "Maria"};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return Names[distribution(generator)];
}

std::string Person::generateRandomLastName() const
{
    std::string LastNames[15] = {"Ozga", "Barski", "Woronowicz", "Pioro", "Frac",
                                 "Niestoj", "Dubinski", "Mazurkiewicz", "Winiarczyk", "Pach",
                                 "Opoka", "Kaniowski", "Bieda", "Rada", "Jedruski"};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return LastNames[distribution(generator)];
}

std::string Person::generateRandomPesel() const
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution1(10'0100, 99'1230);
    std::string pesel = (std::to_string(distribution1(generator)));

    std::uniform_int_distribution<int> distribution2(10'000, 99'999);

    pesel += (std::to_string(distribution2(generator)));
    return pesel;
}

std::string Person::generateRandomStreet() const
{

    std::string Street[5] = {"Ul Barska", "Ul 3 Maja", "Ul Bernarda Belotta Canaletta", "Ul Zwyciestwa", "Ul Przegranej"};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 4);

    return Street[distribution(generator)];
}

std::string Person::generateSex() const
{
    std::string Street[2] = {"Male", "Female"};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 1000);

    return Street[(distribution(generator)) % 2]; // odd returns 1 even returns 0
}