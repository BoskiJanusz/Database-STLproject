#include "Database.hpp"

void Database::add_to_base(const std::shared_ptr<Person>& human) {
    people.emplace_back(std::move(human));
}

void Database::displayDatabase() const {
    std::cout << showContent();
}

std::string Database::showContent() const {
    std::string temp = "";
    int counter = 1;
    for (auto elem : people)
        temp += std::to_string(counter++) + ".\n" + elem->getData() + " \n";
    return temp;
}

void Database::sortByIndex() {
    std::sort(begin(people), end(people), [](const auto& lhs, const auto& rhs) {
        return std::dynamic_pointer_cast<Student>(lhs)->getIndex() > std::dynamic_pointer_cast<Student>(rhs)->getIndex();
    });
}

void Database::sortByPESEL() {
    std::sort(begin(people), end(people), [](const auto& lhs, const auto& rhs) {
        return lhs->getPESEL() > rhs->getPESEL();
    });
}

void Database::sortByLastName() {
    std::sort(begin(people), end(people), [](const auto& lhs, const auto& rhs) {
        return lhs->getLastName() < rhs->getLastName();
    });
}

void Database::removeStudentByIndex(const int index) {
    auto iter = std::find_if(begin(people), end(people), [&index](const auto& student) {
        return std::dynamic_pointer_cast<Student>(student)->getIndex() == index;
    });

    if (iter != end(people)) {
        people.erase(iter);
    }
}

void Database::removePersonByPESEL(const std::string pesel) {
    auto iter = std::find_if(begin(people), end(people), [&pesel](const auto& student) {
        return student->getPESEL() == pesel;
    });
    if (iter != end(people)) {
        people.erase(iter);
    }
}

std::string Database::findByLastName(const std::string lastName) const {
    std::string temp = "";
    for (auto&& elem : people) {
        if (elem->getLastName() == lastName) {
            temp += elem->getData() + "\n";
        }
    }

    return temp;
}

std::string Database::findByPESEL(const std::string pesel) const {
    std::string temp = "";
    auto iter = std::find_if(begin(people), end(people), [&pesel](const auto& student) {
        return student->getPESEL() == pesel;
    });
    if (iter != end(people)) {
        temp += (*iter)->getData() + "\n";
    }

    return temp;
}

void Database::printIfFoundByLastName(const std::string lastName) const {
    std::cout << findByLastName(lastName);
}

void Database::printIfFoundByPESEL(const std::string PESEL) const {
    std::cout << findByPESEL(PESEL);
}

void Database::generateDatabase(int numberOfElements) {
    while (numberOfElements != 0) {
        if (numberOfElements > 0) {
            people.emplace_back(new Student);
            numberOfElements--;
        }
        if (numberOfElements > 0) {
            people.emplace_back(new Employee);
            numberOfElements--;
        }
    }
}

void Database::saveDatabaseInFile() {
    std::ofstream file("data.txt");
    for (const auto& elem : people)
        file << elem->getData() << std::endl;
}

void Database::loadDataFromFile() const {
    std::ifstream file("data.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line;
    }
}

bool Database::isPESELCorrect(std::string pesel) const {
    std::vector<int> ciphers;
    for (size_t i = 0; i < pesel.size(); ++i) {
        ciphers.emplace_back(pesel[i] - '0');
    }
    if (ciphers.size() != 11) {
        throw PESELRangeError{"Wrong PESEL length"};
    }

    int cipher = 0;
    cipher += ciphers[0] * 9 + ciphers[1] * 7 +
              ciphers[2] * 3 + ciphers[3] * 1 + ciphers[4] * 9 +
              ciphers[5] * 7 + ciphers[6] * 3 + ciphers[7] * 1 +
              ciphers[8] * 9 + ciphers[9] * 7;

    if (cipher % 10 != ciphers[10]) {
        throw PESELRangeError{"Wrong PESEL"};
    } else {
        return true;
    }
}

void Database::modifyPersonByPESEL(std::string PESEL) {
    if (isPESELCorrect(PESEL) == true) {
        auto iter = std::find_if(begin(people), end(people), [&PESEL](const auto& student) {
            return student->getPESEL() == PESEL;
        });
        if (iter != std::end(people)) {
            (*iter)->setData();
        }
    }
}

void Database::modifyEarningsByPesel(std::string PESEL, int earnings) {
    if (isPESELCorrect(PESEL) == true) {
        auto iter = std::find_if(begin(people), end(people), [&PESEL](const auto& employer) {
            return employer->getPESEL() == PESEL;
        });

        if (iter != std::end(people)) {
            std::dynamic_pointer_cast<Employee>((*iter))->setSalary(earnings);
        }
    }
}

bool Database::isVectorEmpty() const {
    return people.empty();
}