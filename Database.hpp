#pragma once
#include "Student.hpp"
#include <vector>
class Database
{

private:
    std::vector<Student> Students;
    
public:
    void addStudent(const Student &student);
    void sortByIndex();
    void sortByPESEL();
    void sortByLastName();
    void removeStudentByIndex(int index);
    void removeStudentByPESEL(std::string PESEL);
    void findByLastName(std::string lastName);
    void findByPESEL(std::string PESEL);
    void displayDatabase();
    void generateDatabase(int numberOfElements);
    void modifyStudent(std::string PESEL);
    bool isPESELCorrect(std::string PESEL);
    void saveDatabaseInFile();



};