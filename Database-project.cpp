#include "pch.h"
#include "Database.hpp"
#include "Student.hpp"


int main()
{

    /*PESEL:
        75051898423
        76120851491
        47061311463
        64102499632
        46110839228
        82072728882
        72081255275
        81120695565
        53120296831
        89090868938
        */

    Database db;
    Student jan("Jan", "Kowalski", "75051898423", "Ul. Komandorska", "Male", 8999);
    db.addStudent(jan);
    Student adam("Adam", "Adamski", "47061311463", "Ul. 3 Maja", "Male", 666);
    db.addStudent(adam);
    db.saveDatabaseInFile();
    //db.generateDatabase(10);
    //db.sortByIndex();
    db.displayDatabase();
    // db.isPESELCorrect("97011907");
   // db.modifyStudent("47061311463");
       db.displayDatabase();
    //db.findByPESEL("970229103");
   // db.removeStudentByPESEL("1222213");
   // db.displayDatabase();
   // db.removeStudentByIndex(1222213);
    system("pause");
}

