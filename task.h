#ifndef TASK_H
#define TASK_H
#include<string>
using namespace std;

class task
{
public:
    task();
    string TaskTitle;
    string Description;
    string AssignedDate;
    string RequiredEndingDate;
    string EmployeeName;
    int PriorityValues;
    int Importance();
};

#endif // TASK_H
