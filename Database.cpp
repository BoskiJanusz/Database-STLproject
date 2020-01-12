#include "Database.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <boost/algorithm/string/split.hpp>

void Database::addStudent(const Student &student)
{
    Students.emplace_back(student);
}

void Database::sortByIndex()
{
    std::sort(begin(Students), end(Students), [](const auto &lhs, const auto &rhs) {
        return lhs.getIndex() < rhs.getIndex();
    });
}

void Database::sortByPESEL()
{
    std::sort(begin(Students), end(Students), [](const auto &lhs, const auto &rhs) {
        return lhs.getPESEL() < rhs.getPESEL();
    });
}

void Database::sortByLastName()
{
    std::sort(begin(Students), end(Students), [](const auto &lhs, const auto &rhs) {
        return lhs.getLastName() < rhs.getLastName();
    });
}

void Database::removeStudentByIndex(int index)
{
    auto iter = std::find_if(begin(Students), end(Students), [&index](const auto &student) {
        return student.getIndex() == index;
    });
    if (iter != end(Students))
    {
        Students.erase(iter);
    }
}

void Database::removeStudentByPESEL(std::string pesel)
{
    auto iter = std::find_if(begin(Students), end(Students), [&pesel](const auto &student) {
        return student.getPESEL() == pesel;
    });
    if (iter != end(Students))
    {
        Students.erase(iter);
    }
}

void Database::displayDatabase()
{
    int counter = 1;
    for (auto elem : Students)
        std::cout << counter++ << ".\n"
                  << elem.getData() << std::endl;
}

void Database::findByPESEL(std::string pesel)
{
    auto iter = std::find_if(begin(Students), end(Students), [&pesel](const auto &student) {
        return student.getPESEL() == pesel;
    });

    if (iter != end(Students))
    {
        std::cout << iter->getData();
    }
}

void Database::findByLastName(std::string lastName)
{
    for (auto elem : Students)
    {
        if (elem.getLastName() == lastName)
        {
            std::cout << elem.getData();
        }
        std::cout << "\n";
    }
}

void Database::generateDatabase(int numberOfElements)
{

    while (numberOfElements != 0)
    {
        Student st;
        Students.emplace_back(st);
        numberOfElements--;
    }
}

void Database::saveDatabaseInFile()
{
    std::ofstream file("data.txt");
    for (const auto &elem : Students)
        file << elem.getData() << "\n";
}

bool Database::isPESELCorrect(std::string pesel)
{

    std::vector<int> ciphers;
    for (size_t i = 0; i < pesel.size(); ++i)
        ciphers.emplace_back(pesel[i] - '0');

    if (ciphers.size() != 11)
    {
        std::cout << "Zla dlugosc peselu!" << std::endl;
        return false;
    }

    int cipher = 0;
    cipher += ciphers[0] * 9 + ciphers[1] * 7 + ciphers[2] * 3 + ciphers[3] * 1 + ciphers[4] * 9 + ciphers[5] * 7 + ciphers[6] * 3 + ciphers[7] * 1 + ciphers[8] * 9 + ciphers[9] * 7;

    if (cipher % 10 != ciphers[10])
    {
        std::cout << "Bledny pesel!" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Pesel poprawny" << std::endl;
        return true;
    }
}
void Database::modifyStudent(std::string PESEL)
{

    if (isPESELCorrect(PESEL) == true)
    {
        auto iter = std::find_if(begin(Students), end(Students), [&PESEL](const auto &student) {
            return student.getPESEL() == PESEL;
        });
        
        if (iter != std::end(Students))
        {
            iter->setData();
        }
    }

    else
    {
        std::cout << "Bledny pesel!";
    }
}