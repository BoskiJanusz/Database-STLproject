#pragma once
#include "Student.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
class Database
{

private:
    std::vector<std::shared_ptr<Person>> people;
    
public:

    void add_to_base(const std::shared_ptr<Person>& human);
    void displayDatabase();
    void sortByIndex();
    void sortByPESEL();
    void sortByLastName();
    void removeStudentByIndex(int index);
    void removePersonByPESEL(std::string PESEL);
    void findByLastName(std::string lastName);
    void findByPESEL(std::string PESEL);
    void generateDatabase(int numberOfElements);
    void modifyPersonByPESEL(std::string PESEL);
    void modifyEarningsByPesel(std::string PESEL, int earnings);
    bool isPESELCorrect(std::string PESEL);
    void saveDatabaseInFile();
    void loadDataFromFile();



};