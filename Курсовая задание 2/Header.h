#pragma once
#include <string>
using namespace std;

class Company
{
protected:
    string c_Name;
    string c_Position;
    string c_Salary;


public:
    
    Company()
    {
        c_Name = "NikStudio";
        c_Position = "Работник";
        c_Salary = "6000";
    }

    Company(string Name1):Company()
    {
        c_Name = Name1;
    
    }
    Company(string Name1, string Position1, string Salary1) 
    {
        c_Name = Name1;
        c_Position = Position1;
        c_Salary = Salary1;

    }
    Company(const Company& company) : c_Name(company.c_Name), c_Position(company.c_Position), c_Salary(company.c_Salary)
    {


    }


    friend class Worker;
    friend class Program;
};
