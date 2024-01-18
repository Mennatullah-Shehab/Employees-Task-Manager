#include "LinkedList.h"
#include "task.h"
#include <assert.h>
#include<iostream>
#include<string>
using namespace std;

template <class T>
Node<T>::Node()
{
    data = 0;
    next = 0;
}

template <class T>
Node<T>::Node(T val)
{
    data = val;
    next = 0;
}

template <class T>
void LinkedList<T>::Insert_sorted_descending()
{
    Node<T>* tmp;
    Node<T>* prev;
//        prev = this->head;
//        tmp = this->head->next;

    for (int i = 0; i < count; i++) {
        prev = this->head;
        tmp = this->head->next;

        while (tmp != NULL)
        {
            if (prev->data.PriorityValues < tmp->data.PriorityValues)
            {
                task tmptask = tmp->data;
                tmp->data = prev->data;
                prev->data = tmptask;

            }
            prev = tmp;
            tmp = tmp->next;
        }

    }

}

template <class T>
LinkedList<T>::LinkedList(void)
{
    head = tail = 0;
    count = 0;

}

template <class T>
int LinkedList<T>::Length()
{
    return count;
}

template <class T>
void LinkedList<T>::Append(T val)
{
    Node<T>* newNode = new Node<T>(val);
    if (head == 0)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
    Insert_sorted_descending();
    DateSorting();
}

template <class T>
string LinkedList<T>::Reminder()
{
    Node<T>* tmp = head->next;
    Node<T>* prev = head;
    string title = prev->data.TaskTitle;
    string reqdate= prev->data.RequiredEndingDate;

    while (tmp!=NULL) {

            int prevnumday = stoi(prev->data.RequiredEndingDate.substr(0, 2));
            int tmpnumday = stoi(tmp->data.RequiredEndingDate.substr(0, 2));
            int prevnummon = stoi(prev->data.RequiredEndingDate.substr(3, 2));
            int tmpnummon = stoi(tmp->data.RequiredEndingDate.substr(3, 2));
            int prevnumyear = stoi(prev->data.RequiredEndingDate.substr(6, 4));
            int tmpnumyear = stoi(tmp->data.RequiredEndingDate.substr(6, 4));

            if (prevnumyear > tmpnumyear) {

                prev = tmp;
                tmp = tmp->next;
                title = prev->data.TaskTitle;
                reqdate = prev->data.RequiredEndingDate;

            }
            else if ((prevnumyear == tmpnumyear) && (prevnummon > tmpnummon)) {

                prev = tmp;
                tmp = tmp->next;
                title = prev->data.TaskTitle;
                reqdate = prev->data.RequiredEndingDate;

            }
            else if ((prevnumyear == tmpnumyear) && (prevnummon == tmpnummon) && (prevnumday > tmpnumday)) {

                prev = tmp;
                tmp = tmp->next;
                title = prev->data.TaskTitle;
                reqdate = prev->data.RequiredEndingDate;

            }

        tmp = tmp->next;
    }
    return "Task: "+title+" Required Ending Date: "+reqdate;
 }
template<class T>
void LinkedList<T>::Update()
{
        for (int i = 0; i < Length(); i++)
        {
            cout << (i + 1) << At(i).taskTitle << endl;
        }
        int x;
        cout << "if the task is done enter the number of the task";
        cin >> x;

        DeleteAt(x - 1);

        if (Empty())
        {
            cout << "Well done ! All the tasks are done";
        }


}

template <class T>
T LinkedList<T>::At(int pos)
{
    assert(pos >= 0 && pos < count);
    Node<T>* tmp = head;
    for (int i = 0; i < pos; i++)
        tmp = tmp->next;
    return tmp->data;
}

template <class T>
void LinkedList<T>::InsertAt(int pos, T val)
{
    assert(pos >= 0 && pos < count);
    Node<T>* tmp = head;
    Node<T>* newNode = new Node<T>(val);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;

        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    count++;
}

template <class T>
void LinkedList<T>::DeleteAt(int pos)
{
    assert(pos >= 0 && pos < count);
    Node<T>* tmp = head;
    if (pos == 0)
    {
        head = head->next;
        delete tmp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;
        Node<T>* del = tmp->next;
        tmp->next = del->next;
        delete del;
        if (pos == count - 1)
            tail = tmp;
    }
    count--;
}

template<class T>
bool LinkedList<T>::Empty()
{
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
void LinkedList<T>::Display()
{
        Node<T>* ptr;
        ptr = head;
        for (int i = 0; i < count; i++) {
            cout << "task " << (i + 1) << ": " << endl;
            cout<< "taskTitle: ";
                cout << ptr->data.taskTitle << endl;
            cout << "Description: ";
                cout << ptr->data.Description << endl;
            cout << "AssignedDate: ";
                cout << ptr->data.AssignedDate << endl;
            cout << "RequiredEndingDate: ";
                cout << ptr->data.RequiredEndingDate << endl;
            cout << "EmployeeName: ";
                cout << ptr->data.EmployeeName << endl;
            cout << "PriorityValue: ";
                cout << ptr->data.PriorityValues << endl;
                cout << endl;
                cout << "---------------------------------" << endl;
            ptr = ptr->next;
        }

}

template<class T>
void LinkedList<T>::Edit()
{
    Node<T>* tmp = head;
    string title;
    int choice;
    string newstr;
    int newpriority;
    cout << "Enter task Title you want to Edit";
    cin >> title;

    for (int i = 0; i < count; i++) {
        if (tmp->data.taskTitle == title) {
            cout << "Please choose a number\n";
            cout << "1-Description\n2-Ending Date\n3-Priority";

            cin >> choice;
            if (choice != 1 && choice != 2 && choice != 3) {
                cout << "Please Enter A Valid Choice!\n";
                cout << "1-Description\n2-Ending Date\n3-Priority";
                cin >> choice;
            }

            switch (choice) {
            case 1:
            {
                cout << "Enter new Description";
                cin >> newstr;
                tmp->data.Description = newstr;
                break;
            }
            case 2:
            {
                cout << "Enter your prefered Ending Date";
                cin >> newstr;
                tmp->data.RequiredEndingDate = newstr;
                break;
            }
            case 3:
            {
                cout << "Enter Priority";
                cin >> newpriority;
                tmp->data.PriorityValues = newpriority;
                break;
            }
            }

        }
        tmp = tmp->next;
    }
}

template<class T>
void LinkedList<T>::DateSorting()
{
    Node<T>* tmp;
    Node<T>* prev;


    for (int i = 0; i < count; i++) {
        prev = this->head;
        tmp = this->head->next;

        while (tmp != NULL)
        {
            if (prev->data.PriorityValues == tmp->data.PriorityValues) {
                int prevnumday = stoi(prev->data.RequiredEndingDate.substr(0, 2));
                int tmpnumday = stoi(tmp->data.RequiredEndingDate.substr(0, 2));
                int prevnummon = stoi(prev->data.RequiredEndingDate.substr(3, 2));
                int tmpnummon = stoi(tmp->data.RequiredEndingDate.substr(3, 2));
                int prevnumyear = stoi(prev->data.RequiredEndingDate.substr(6, 4));
                int tmpnumyear = stoi(tmp->data.RequiredEndingDate.substr(6, 4));

                if (prevnumyear > tmpnumyear) {

                    task tmptask = tmp->data;
                    tmp->data = prev->data;
                    prev->data = tmptask;
                }
                else if ((prevnumyear == tmpnumyear) && (prevnummon > tmpnummon)) {

                    task tmptask = tmp->data;
                    tmp->data = prev->data;
                    prev->data = tmptask;

                }
                else if ((prevnumyear == tmpnumyear) && (prevnummon == tmpnummon) && (prevnumday > tmpnumday)) {

                    task tmptask = tmp->data;
                    tmp->data = prev->data;
                    prev->data = tmptask;

                }



            }
            prev = tmp;
            tmp = tmp->next;
        }


    }
}

template <class T>
LinkedList<T>::~LinkedList(void)
{
    while (count != 0)
        DeleteAt(0);
}
