#include <iostream>
#include <string>
#include "Header.h"
#include <time.h> 
#include <ctime>
#include <span>

using namespace std;

#pragma warning(disable : 4996)
class Worker
{
protected:
    string m_Name;
    int m_Year;
    int m_Month;
    Company m_WorkPlace;

public:

    Worker()
    {
        m_Name = "Александр";
        m_Month = 1;
        m_Year = 2000;
        m_WorkPlace = Company();
    }
    
    Worker(string Name) :Worker()
    {
        m_Name = Name;
    }

    Worker(string Name, int Month, int Year):Worker()
    {
        m_Name = Name;
        m_Month = Month;
        m_Year = Year;
    }

    Worker(string Name, int Month, int Year, string Name1) :Worker()
    {
        m_Name = Name;
        m_Month = Month;
        m_Year = Year;
        m_WorkPlace.c_Name = Name1;
    }

    Worker(string Name, int Month, int Year, string CName, string CPosition, string CSalary)
    {
        m_Name = Name;
        m_Month = Month;
        m_Year = Year;
        m_WorkPlace.c_Name = CName;
        m_WorkPlace.c_Position = CPosition;
        m_WorkPlace.c_Salary = CSalary;
    }



    Worker(const Worker& worker) : m_Name(worker.m_Name), m_Month(worker.m_Month), m_Year(worker.m_Year), m_WorkPlace(worker.m_WorkPlace)
    {

    }

    string getName() { return m_Name; } 
    void setName(string Name) {  m_Name = Name; }

    int getMonth() { return m_Month; } 
    void setMonth(int Month) { m_Month = Month; }

    int getYear() { return m_Year; } 
    void setYear(int Year) { m_Year = Year; }

    string getWorkPlaceName() { return m_WorkPlace.c_Name; } 
    void setWorkPlaceName(string CName) {  m_WorkPlace.c_Name = CName; }

    string getWorkPlacePosition() { return m_WorkPlace.c_Position; } 
    void setWorkPlacePosition(string CPosition) {  m_WorkPlace.c_Position = CPosition; }

    string getWorkPlaceSalary() { return  m_WorkPlace.c_Salary; } 
    void setWorkPlaceSalary(string CSalary) { m_WorkPlace.c_Salary = CSalary; }

    void GetWorkExperience()
    {
        int G_Month, G_Year, S_Month, S_Year, sum;
        time_t now = time(0);
        tm* ltm = localtime(&now);
        G_Month = 1 + ltm->tm_mon;
        G_Year = 1900 + ltm->tm_year;
        S_Month = m_Month;
        S_Year = m_Year;
        sum = G_Year - S_Year;
        sum=sum * 12;
        sum = sum - S_Month + G_Month;
        cout << sum<< endl;

    }

    int GetWorkExperience2()
    {
        int G_Month, G_Year, S_Month, S_Year, sum;
        time_t now = time(0);
        tm* ltm = localtime(&now);
        G_Month = 1 + ltm->tm_mon;
        G_Year = 1900 + ltm->tm_year;
        S_Month = m_Month;
        S_Year = m_Year;
        sum = G_Year - S_Year;
        sum = sum * 12;
        sum = sum - S_Month + G_Month;
        return sum;

    }
    void GetTotalMoney()
    {
        int G_Month, G_Year, S_Month, S_Year, sum, Salary;
        string S_Salary;
        time_t now = time(0);
        tm* ltm = localtime(&now);
        G_Month = 1 + ltm->tm_mon;
        G_Year = 1900 + ltm->tm_year;
        S_Month = m_Month;
        S_Year = m_Year;
        sum = G_Year - S_Year;
        sum = sum * 12;
        sum = sum - S_Month + G_Month;
        S_Salary = getWorkPlaceSalary();
        Salary = atoi(S_Salary.c_str());
        sum = sum*Salary;
        cout << sum << endl;
    
    }

    friend class Company;
    friend class Program;
};

class  Program
{
public:

    void ReadWorkersArray(Worker Lib[], int i2, int n)
    {
        int count = 1;
        for (size_t i = i2; i < i2+n; i++)
        {
            string Name, CName, CPosition, CSalary;
            int Mounth = 0;
            int Year = 0;
            
            cout << "Сотрудник номер:"<< count << endl;
            cout << "Введите имя сотрудника" << endl;
            cin >> Name;
            Lib[i].setName(Name);
            cout << "Введите месяц начала работы сотрудника " << endl;
            cin >> Mounth;
            Lib[i].setMonth(Mounth);
            cout << "Введите год начала работы сотрудника" << endl;
            cin >> Year;
            Lib[i].setYear(Year);
            cout << "Введите название компании в которой работает сотрудник" << endl;
            cin >> CName;
            Lib[i].setWorkPlaceName(CName);
            cout << "Введите должность сотрудника" << endl;
            cin >> CPosition;
            Lib[i].setWorkPlacePosition(CPosition);
            cout << "Введите зарплату сотрудника" << endl;
            cin >> CSalary;
            Lib[i].setWorkPlaceSalary(CSalary);
            count+=1;
        }
    }
    void PrintWorker(Worker Lib[], int num)
    {
        cout << Lib[num].getName() << "   " << "\t" << Lib[num].getMonth() << "   " << "\t" << Lib[num].getYear() << "   " << "\t" << Lib[num].getWorkPlaceName() << "   " << "\t" << Lib[num].getWorkPlacePosition() << "   " << "\t" << Lib[num].getWorkPlaceSalary() << endl;

    }
    void PrintWorkers(Worker Lib[],int a)
    {
        for (size_t i = 0; i < a; i++)
        {

            cout << Lib[i].getName() << "   " << "\t" << Lib[i].getMonth() << "   " << "\t" << Lib[i].getYear() << "   " << "\t" << Lib[i].getWorkPlaceName() << "   " << "\t" << Lib[i].getWorkPlacePosition() << "   " << "\t" << Lib[i].getWorkPlaceSalary() << endl;
           
        }
    }
    void GetWorkersInfo(Worker Lib[], int a)
    {
        int Salary, max, min, p1,p2=0;
        string S_Salary;
        S_Salary = Lib[0].getWorkPlaceSalary();
        Salary = atoi(S_Salary.c_str());
        max = Salary;
        min = Salary;
        for (size_t i = 1; i < a; i++)
        {
            S_Salary = Lib[i].getWorkPlaceSalary();
            Salary = atoi(S_Salary.c_str());
            if (max < Salary)
            {
                max = Salary;
                p1 = i;
            }
            if (min > Salary)
            {
                min = Salary;
                p2 = i;
            }

        }
        cout << "Самая болшая зарпалата у сотрудника" << p1+1 << "  " << max << endl;
        cout << "Самая маленькая зарпалата у сотрудника" << p2+1 << "  " << min << endl;
    }


    void SortWorkerBySalary(Worker Lib[], int a)
    {
       
        Worker Test;
        int Salary1, Salary2;
        string S_Salary1, S_Salary2;

        for (int i = 0; i < a; i++) 
        {
            for (int j = (a - 1); j >= (i + 1); j--) 
            {
                S_Salary1 = Lib[j].getWorkPlaceSalary();
                Salary1 = atoi(S_Salary1.c_str());
                S_Salary2 = Lib[j-1].getWorkPlaceSalary();
                Salary2 = atoi(S_Salary2.c_str());

                if (Salary1 > Salary2)
                {
                    Test = Lib[j];
                    Lib[j] = Lib[j-1];
                    Lib[j-1] = Test;
                }
             }
        }
        
    }

    void SortWorkerByWorkExperience(Worker Lib[], int a)
    {

        Worker Test;
        int Sum1, Sum2;
        string S_Salary1, S_Salary2;

        for (int i = 0; i < a; i++)
        {
            for (int j = (a - 1); j >= (i + 1); j--)
            {
                Sum1 = Lib[j].GetWorkExperience2();
                Sum2 = Lib[j-1].GetWorkExperience2();

                if (Sum1 < Sum2)
                {
                    Test = Lib[j];
                    Lib[j] = Lib[j - 1];
                    Lib[j - 1] = Test;
                }
            }
        }
    }
};



int main()
{
    setlocale(LC_ALL, "ru");
    const int lenght = 1000;
    Worker WorkerLib[lenght];
    Worker WorkTest;
    Program Function;
    int a, n,l = 0;
    int i = 0;
    int Choise, num, Choise2, Choise3;
    do
    {
        cout << " ---------------------------------------------------------------" << endl;
        cout << "|1 - Ввести данные о сотруднике                                 |" << endl;
        cout << "|2 - Просмотреть данные о сотруднике                            |" << endl;
        cout << "|3 - Узнать информацию про зарплату сотрудников                 |" << endl;
        cout << "|4 - Сортировать список сотрудников                             |" << endl;
        cout << "|5 - Узнать стаж работы сотрудника                              |" << endl;
        cout << "|6 - Узнать общее количетсво заработаных средств сотрудника     |" << endl;
        cout << "|0 - Выход                                                      |" << endl;
        cout << " ---------------------------------------------------------------" << endl;
        cin >> Choise;


        switch (Choise)
        {
        case 1:
        {
            cout << "Сколько сотрудников хотите ввести?" << endl;
            cin >> n;
            Function.ReadWorkersArray(WorkerLib, i, n);
            i = i + n;
            l += 1;
            break;
        }
        case 2:
        {  
            if (l == 0)
            {
                cout << "Список пуст\n";
            }
            else {

                cout << "1.Подробная информацуия о сотруднике" << endl;
                cout << "2.Вывод всего списка сотрудников" << endl;
                cin >> Choise2;
                switch (Choise2)
                {
                case 1:

                {
                    for (size_t t = 0; t < i; t++)
                    {
                        cout << t + 1 << ". " << WorkerLib[t].getName() << endl;
                    }

                    cout << "Введите номер сотрудника о котором хотите узнать подробную информацию" << endl;
                    cin >> num;
                    num = num - 1;
                    Function.PrintWorker(WorkerLib, num);

                    break;

                }
                case 2:
                {
                    Function.PrintWorkers(WorkerLib, i);
                    break;
                }

                }
            }
            break;
        }

        case 3:
        {
            if (l == 0)
            {
                cout << "Список пуст\n";
            }
            else {
                Function.GetWorkersInfo(WorkerLib, i);  
            }
            break;
        }

        case 4:
        {
            if (l == 0)
            {
                cout << "Список пуст\n";
            }
            else {
                cout << "1.Сортировать по зарплате" << endl;
                cout << "2.Сортировать по стажу" << endl;
                cin >> Choise3;
                switch (Choise3)
                {
                case 1:

                {
                    Function.SortWorkerBySalary(WorkerLib, i);
                    break;
                }
                case 2:
                {
                    Function.SortWorkerByWorkExperience(WorkerLib, i);
                }

                }
                break;

                Function.SortWorkerBySalary(WorkerLib, i);
            }
                break;
        }

        case 5:
        {   
            if (l == 0)
            {
                cout << "Список пуст\n";
            }
            else {
                for (size_t t = 0; t < i; t++)
                {
                    cout << t + 1 << ". " << WorkerLib[t].getName() << endl;
                }
                cin >> a;
                WorkerLib[a - 1].GetWorkExperience();
            }
            break;

        }
        case 6:
        {
            if (l == 0)
            {
                cout << "Список пуст\n";
            }
            else {
                for (size_t t = 0; t < i; t++)
                {
                    cout << t + 1 << ". " << WorkerLib[t].getName() << endl;
                }
                cin >> a;
                WorkerLib[a - 1].GetTotalMoney();
            }
            break;
        }

        case 0:

            return 0;
            break;

        default:
            break;
        }

    } while (true);
    
}