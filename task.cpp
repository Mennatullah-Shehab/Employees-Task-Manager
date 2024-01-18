#include "task.h"
#include <string>
#include<iostream>
using namespace std;
task::task()
{

}

int task::Importance() {

    cout << "Plese enter the number of importance from 1 to 10 " << endl;
    cout << "If the task is very important write 10 " << endl;
    cin>> PriorityValues;
    try {
        if ((PriorityValues < 1) || (PriorityValues > 10)) {
            throw exception();
        }
    }
    catch (exception e) {
        cout << "Please enter number from 1 to 10" << endl;
        cin >> PriorityValues;

    }

    return PriorityValues;

}

