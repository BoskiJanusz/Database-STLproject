#include <gtest/gtest.h>
#include <memory>

#include "Database.hpp"
#include "Employee.hpp"

struct DataBaseTest : ::testing::Test {
    Database db;
};

TEST_F(DataBaseTest, DisplayNonEmptyDataBase) {
    const std::shared_ptr<Employee> ewa = std::make_shared<Employee>(
        "Ewa",
        "Kowalczyk",
        "12345678912",
        "ul. Nowowiejska 20, 00-100 Warszawa",
        Gender::Female,
        5);
    db.add_to_base(ewa);
    auto content = db.showContent();
    auto expected = "1.\nName: Ewa\nLastname: Kowalczyk\nPesel: 12345678912\nAddress: ul. Nowowiejska 20, 00-100 Warszawa\nSex: Female\nSalary: 5\n \n";

    EXPECT_EQ(content, expected);
}

TEST_F(DataBaseTest, RemoveStudentByIndex) {
    const std::shared_ptr<Student> ewa = std::make_shared<Student>(
        "Ewa",
        "Kowalczyk",
        "12345678912",
        "ul. Nowowiejska 20, 00-100 Warszawa",
        Gender::Female,
        123456);
    db.add_to_base(ewa);
    db.removeStudentByIndex(123456);
    bool isEmpty = db.isVectorEmpty();
    bool expected = true;

    EXPECT_EQ(isEmpty, expected);
}

TEST_F(DataBaseTest, RemovePersonByPESEL) {
    const std::shared_ptr<Student> ewa = std::make_shared<Student>(
        "Ewa",
        "Kowalczyk",
        "12345678912",
        "ul. Nowowiejska 20, 00-100 Warszawa",
        Gender::Female,
        123456);
    db.add_to_base(ewa);
    db.removePersonByPESEL("12345678912");
    bool isEmpty = db.isVectorEmpty();
    bool expected = true;

    EXPECT_EQ(isEmpty, expected);
}

TEST_F(DataBaseTest, FindPersonByLastName) {
    db.add_to_base(std::make_shared<Student>("Andzelika", "Nowak", "76120851491", "Ul. Wroclawska", Gender::Female, 2345));
    db.add_to_base(std::make_shared<Student>("Andrzej", "Reto", "47061311463", "Ul. Michalowiska", Gender::Male, 5744));
    db.add_to_base(std::make_shared<Student>("Karol", "Bordo", "64102499632", "Ul. Wiesnowa", Gender::Male, 23456));
    db.add_to_base(std::make_shared<Employee>("Michal", "Szklany", "46110839228", "Ul. Kambodza", Gender::Male, 100'000));
    db.add_to_base(std::make_shared<Employee>("Michal", "Poniedzilek", "82072728882", "Ul. Jemen", Gender::Male, 1000));
    db.add_to_base(std::make_shared<Employee>("Stanislaw", "Sobota", "72081255275", "Ul. Polska", Gender::Male, 1000));

    auto foundPerson = db.findByLastName("Bordo");
    auto expected = "Name: Karol\nLastname: Bordo\nPesel: 64102499632\nAddress: Ul. Wiesnowa\nSex: Male\nIndex: 23456\n\n";

    EXPECT_EQ(foundPerson, expected);
}

TEST_F(DataBaseTest, FindPersonByPESEL) {
    db.add_to_base(std::make_shared<Student>("Andzelika", "Nowak", "76120851491", "Ul. Wroclawska", Gender::Female, 2345));
    db.add_to_base(std::make_shared<Student>("Andrzej", "Reto", "47061311463", "Ul. Michalowiska", Gender::Male, 5744));
    db.add_to_base(std::make_shared<Student>("Karol", "Bordo", "64102499632", "Ul. Wiesnowa", Gender::Male, 23456));
    db.add_to_base(std::make_shared<Employee>("Michal", "Szklany", "46110839228", "Ul. Kambodza", Gender::Male, 100'000));
    db.add_to_base(std::make_shared<Employee>("Michal", "Poniedzilek", "82072728882", "Ul. Jemen", Gender::Male, 1000));
    db.add_to_base(std::make_shared<Employee>("Stanislaw", "Sobota", "72081255275", "Ul. Polska", Gender::Male, 1000));

    auto foundPerson = db.findByPESEL("76120851491");
    auto expected = "Name: Andzelika\nLastname: Nowak\nPesel: 76120851491\nAddress: Ul. Wroclawska\nSex: Female\nIndex: 2345\n\n";

    EXPECT_EQ(foundPerson, expected);
}

TEST_F(DataBaseTest, SortPersonByPESEL) {
    db.add_to_base(std::make_shared<Student>("Andzelika", "Nowak", "76120851491", "Ul. Wroclawska", Gender::Female, 2345));
    db.add_to_base(std::make_shared<Student>("Andrzej", "Reto", "47061311463", "Ul. Michalowiska", Gender::Male, 5744));
    db.add_to_base(std::make_shared<Student>("Karol", "Bordo", "64102499632", "Ul. Wiesnowa", Gender::Male, 23456));
    db.add_to_base(std::make_shared<Employee>("Michal", "Szklany", "46110839228", "Ul. Kambodza", Gender::Male, 100'000));
    db.add_to_base(std::make_shared<Employee>("Michal", "Poniedzilek", "82072728882", "Ul. Jemen", Gender::Male, 1000));
    db.add_to_base(std::make_shared<Employee>("Stanislaw", "Sobota", "72081255275", "Ul. Polska", Gender::Male, 1000));
    db.sortByPESEL();
    auto isSorted = std::is_sorted(std::begin(db.getPeople()), std::end(db.getPeople()), [](const auto& lhs, const auto& rhs) {
        return lhs->getPESEL() > rhs->getPESEL();
    });
    auto expected = true;
    EXPECT_EQ(isSorted, expected);
}

TEST_F(DataBaseTest, SortStudentByIndex) {
    db.add_to_base(std::make_shared<Student>("Andzelika", "Nowak", "76120851491", "Ul. Wroclawska", Gender::Female, 2345));
    db.add_to_base(std::make_shared<Student>("Andrzej", "Reto", "47061311463", "Ul. Michalowiska", Gender::Male, 5744));
    db.add_to_base(std::make_shared<Student>("Karol", "Bordo", "64102499632", "Ul. Wiesnowa", Gender::Male, 23456));
    db.add_to_base(std::make_shared<Student>("Maja", "Niedziela", "72081255275", "Ul. Polska", Gender::Female, 254894));
    db.sortByIndex();
    auto isSorted = std::is_sorted(std::begin(db.getPeople()), std::end(db.getPeople()), [](const auto& lhs, const auto& rhs) {
        return std::dynamic_pointer_cast<Student>(lhs)->getIndex() > std::dynamic_pointer_cast<Student>(rhs)->getIndex();
    });
    // db.displayDatabase();
    auto expected = true;

    EXPECT_EQ(isSorted, expected);
}

TEST_F(DataBaseTest, CorrectPESEL) {
    auto isCorrect = db.isPESELCorrect("76120851491");
    auto expected = true;
    EXPECT_EQ(isCorrect, expected);
}

TEST_F(DataBaseTest, failShortPESEL) {
    std::string shortPesel = "123456";
    ASSERT_THROW(db.isPESELCorrect(shortPesel), std::range_error);
}

TEST_F(DataBaseTest, failLongPESEL) {
    std::string longPesel = "1234567891234567";
    ASSERT_THROW(db.isPESELCorrect(longPesel), std::range_error);
}

TEST_F(DataBaseTest, failCiphersPESEL) {
    std::string wrongCiphersPESEL = "1234567891234567";
    ASSERT_THROW(db.isPESELCorrect(wrongCiphersPESEL), std::range_error);
}