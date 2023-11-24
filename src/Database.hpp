#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

struct PESELRangeError : public std::range_error {
    PESELRangeError(std::string const& msg)
        : std::range_error(msg) {}
};

class Database {
private:
    std::vector<std::shared_ptr<Person>> people;

public:
    const std::vector<std::shared_ptr<Person>>& getPeople() const { return people; }
    std::string showContent() const;
    std::string findByLastName(const std::string lastName) const;
    std::string findByPESEL(const std::string PESEL) const;
    void displayDatabase() const;
    void printIfFoundByLastName(const std::string lastName) const;
    void printIfFoundByPESEL(const std::string PESEL) const;
    void add_to_base(const std::shared_ptr<Person>& human);
    void sortByIndex();
    void sortByPESEL();
    void sortByLastName();
    void removeStudentByIndex(const int index);
    void removePersonByPESEL(const std::string PESEL);
    void generateDatabase(int numberOfElements);
    void modifyPersonByPESEL(std::string PESEL);
    void modifyEarningsByPesel(std::string PESEL, int earnings);
    bool isPESELCorrect(std::string PESEL) const;
    void saveDatabaseInFile();
    void loadDataFromFile() const;
    bool isVectorEmpty() const;
};