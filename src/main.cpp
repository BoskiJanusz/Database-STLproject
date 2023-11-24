#include "Database.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
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
    db.add_to_base(std::make_shared<Student>("Dominik", "Nowak", "75051898423", "Ul. Olesnicka", Gender::Male, 237812));
    db.add_to_base(std::make_shared<Student>("Andzelika", "Nowak", "76120851491", "Ul. Wroclawska", Gender::Female, 2345));
    db.add_to_base(std::make_shared<Student>("Andrzej", "Reto", "47061311463", "Ul. Michalowiska", Gender::Male, 5744));
    db.add_to_base(std::make_shared<Student>("Karol", "Bordo", "64102499632", "Ul. Wiesnowa", Gender::Male, 23456));
    db.add_to_base(std::make_shared<Employee>("Michal", "Szklany", "46110839228", "Ul. Kambodza", Gender::Male, 100'000));
    db.add_to_base(std::make_shared<Employee>("Michal", "Poniedzilek", "82072728882", "Ul. Jemen", Gender::Male, 1000));
    db.add_to_base(std::make_shared<Employee>("Stanislaw", "Sobota", "72081255275", "Ul. Polska", Gender::Male, 1000));
    db.add_to_base(std::make_shared<Employee>("Robert", "Nowak", "81120695565", "Ul. Nowojorska", Gender::Male, 1000));

    // db.displayDatabase();
    // db.sortByIndex();
    // db.sortByPESEL();
    // db.sortByLastName();
    // db.removeStudentByIndex(23456);
    // db.removeStudentByPESEL("46110839228");
    // db.findByLastName("Nowak");
    // db.findByPESEL("76120851491");
    // db.generateDatabase(5);
    // db.saveDatabaseInFile();
    // db.isPESELCorrect("46110839228");
    // db.modifyPersonByPESEL("75051898423");
    // db.modifyEarningsByPesel("81120695565", 99);

    return 0;
}
