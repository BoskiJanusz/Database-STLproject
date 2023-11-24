#include "Person.hpp"

Person::Person(const std::string& name,
               const std::string& lastName,
               const std::string& PESEL,
               const std::string& address,
               const Gender& gender)
    : name_(name), lastName_(lastName), PESEL_(PESEL), address_(address), gender_(gender) {}

Person::~Person(){};

Person::Person() {
    gender_ = generateSex();
    if (gender_ == Gender::Male) {
        name_ = generateRandomMaleName();
    }
    if (gender_ == Gender::Female) {
        name_ = generateRandomMaleName();
    }

    lastName_ = generateRandomLastName();
    PESEL_ = generateRandomPesel();
    address_ = generateRandomStreet();
}

std::string Person::enumGenderToString(const Gender& sex) const {
    std::string temp = "";
    switch (sex) {
    case Gender::Male: {
        temp = "Male";
        break;
    }
    case Gender::Female: {
        temp = "Female";
        break;
    }
    default:
        break;
    }

    return temp;
}

std::string Person::getPESEL() const {
    return PESEL_;
}

std::string Person::getLastName() const {
    return lastName_;
}

std::string Person::generateRandomMaleName() const {
    std::string Names[15] = {"Michal", "Andrzej", "Pawel", "Marek", "Karol",
                             "Norbert", "Mateusz", "Krystian", "Damian", "Janusz",
                             "Szymon", "Wojtek", "Stanislaw", "Jonasz", "Jozef"};
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return Names[distribution(generator)];
}

std::string Person::generateRandomFemaleName() const {
    std::string Names[15] = {"Oliwia", "Ania", "Patrycja", "Michalina", "Dominika",
                             "Zuzia", "Paulina", "Kasia", "Karolina", "Janina",
                             "Zosia", "Wiktoria", "Stanislawa", "Edyta", "Maria"};
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return Names[distribution(generator)];
}

std::string Person::generateRandomLastName() const {
    std::string LastNames[15] = {"Ozga", "Barski", "Woronowicz", "Pioro", "Frac",
                                 "Niestoj", "Dubinski", "Mazurkiewicz", "Winiarczyk", "Pach",
                                 "Opoka", "Kaniowski", "Bieda", "Rada", "Jedruski"};
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 14);

    return LastNames[distribution(generator)];
}

std::string Person::generateRandomPesel() const {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution1(10'0100, 99'1230);
    std::string pesel = (std::to_string(distribution1(generator)));
    std::uniform_int_distribution<int> distribution2(10'000, 99'999);
    pesel += (std::to_string(distribution2(generator)));

    return pesel;
}

std::string Person::generateRandomStreet() const {
    std::string Street[5] = {"Ul Barska", "Ul 3 Maja", "Ul Bernarda Belotta Canaletta", "Ul Zwyciestwa", "Ul Przegranej"};
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 4);

    return Street[distribution(generator)];
}

Gender Person::generateSex() const {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 1000);
    return static_cast<Gender>((distribution(generator)) % static_cast<int>(Gender::Count));
}