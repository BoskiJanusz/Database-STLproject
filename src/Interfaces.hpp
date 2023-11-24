#pragma once

class Salaryable{
    public:
        virtual int getSalary() const = 0;
        virtual void setSalary(const int&) = 0;
};

class Indexable{
    public:
        virtual int getIndex() const = 0;
        virtual void setIndex(const int&) = 0;
};