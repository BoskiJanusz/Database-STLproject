#include "Database.hpp"



void Database::add_to_base(const std::shared_ptr<Person>&  human)
{
    people.emplace_back(std::move(human));
}

void Database::displayDatabase()
{
    int counter = 1;
    for (auto elem : people)
        std::cout << counter++ << ".\n"
                  << elem->getData() << std::endl;
}


void Database::sortByIndex()
{
    std::sort(begin(people), end(people), [](const auto &lhs, const auto &rhs) {
        return lhs->getIndex() > rhs->getIndex();
    });
}



void Database::sortByPESEL()
{
    std::sort(begin(people), end(people), [](const auto &lhs, const auto &rhs) {
        return lhs->getPESEL() > rhs->getPESEL();
    });
}

void Database::sortByLastName()
{
    std::sort(begin(people), end(people), [](const auto &lhs, const auto &rhs) {
        return lhs->getLastName() < rhs->getLastName();
    });
}

void Database::removeStudentByIndex(int index)
{
    auto iter = std::find_if(begin(people), end(people), [&index](const auto &student) {
        return student->getIndex() == index;
    });

    if (iter != end(people))
    {
        people.erase(iter);
    }
}

void Database::removePersonByPESEL(std::string pesel)
{
    auto iter = std::find_if(begin(people), end(people), [&pesel](const auto &student) {
        return student->getPESEL() == pesel;
    });
    if (iter != end(people))
    {
        people.erase(iter);
    }
}


void Database::findByLastName(std::string lastName)
{
    for (auto elem : people)
    {
        if (elem->getLastName() == lastName)
        {
            std::cout << elem->getData();
            std::cout << "\n";
        }
    }
}

void Database::findByPESEL(std::string pesel)
{
    auto iter = std::find_if(begin(people), end(people), [&pesel](const auto &student) {
        return student->getPESEL() == pesel;
    });

    if (iter != end(people))
    {        
        std::cout << (*iter) ->getData();
    }
}
void Database::generateDatabase(int numberOfElements)
{

    while (numberOfElements != 0)
    {
        if(numberOfElements > 0)
        {
            people.emplace_back(new Student);
            numberOfElements--;
        }
        
        if(numberOfElements > 0)
        {
            people.emplace_back(new Employee);
            numberOfElements--;
        }
        
    }
}


void Database::saveDatabaseInFile()
{
    std::ofstream file("data.txt");
    for (const auto &elem : people)
        file << elem->getData() << "\n";
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
    cipher += ciphers[0] * 9 + ciphers[1] * 7 + 
    ciphers[2] * 3 + ciphers[3] * 1 + ciphers[4] * 9 + 
    ciphers[5] * 7 + ciphers[6] * 3 + ciphers[7] * 1 + 
    ciphers[8] * 9 + ciphers[9] * 7;

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


void Database::modifyPersonByPESEL(std::string PESEL)
{

    if (isPESELCorrect(PESEL) == true)
    {
        auto iter = std::find_if(begin(people), end(people), [&PESEL](const auto &student) {
            return student->getPESEL() == PESEL;
        });
        
        if (iter != std::end(people))
        {
            (*iter)->setData();
        }
    }

    else
    {
        std::cout << "Bledny pesel!";
    }
}

void Database::modifyEarningsByPesel(std::string PESEL, int earnings)
{
  if (isPESELCorrect(PESEL) == true)
    {
        auto iter = std::find_if(begin(people), end(people), [&PESEL](const auto &student) {
            return student->getPESEL() == PESEL;
        });
        
        if (iter != std::end(people))
        {
            (*iter)->setEarnings(earnings);
        }
    }

    else
    {
        std::cout << "Bledny pesel!";
    }   
}