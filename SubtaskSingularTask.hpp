#ifndef __SUBTASK_SINGULAR_TASK_HPP__
#define __SUBTASK_SINGULAR_TASK_HPP__

#include "Task.hpp"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Task;

class SingularSubtask : public Task {
public:
    SingularSubtask(string taskTitle, string taskPriority, string taskDescription, string taskDueDate) {
        title = taskTitle;
        priority = taskPriority;
        description = taskDescription;
        dueDate = taskDueDate;
    }

    void displayTask() {
        cout << "TASK TITLE: " << getTaskTitle() << endl;
        cout << "TASK PRIORITY: " << getTaskPriority() << endl;
        cout << "TASK DESCRIPTION: " << getTaskDescription() << endl;
        cout << "TASK TASK DUE DATE: " << getTaskDueDate() << endl << endl;
    }

    void setTaskTitle(string taskTitle) {
        title = taskTitle;
    }

    string getTaskTitle() {
        return title;
    }

    void setTaskPriority(string taskPriority) {
        priority = taskPriority;
    }

    string getTaskPriority() {
        return priority;
    }

    void setTaskDescription(string taskDescription) {
        description = taskDescription;
    }

    string getTaskDescription() {
        return description;
    }

    void setTaskDueDate(string taskDueDate) {
        dueDate = taskDueDate;
    }

    string getTaskDueDate() {
        return dueDate;
    }

protected:
    void saveTaskInformation() {
        fstream writeToFile;
        string fileName = getTaskTitle();
        writeToFile.open(fileName, ios::out | ios::trunc);
        string theTaskDescription = getTaskDescription();
        string theTaskPriority = getTaskPriority();
        string theTaskDueDate = getTaskDueDate();
        writeToFile << "TASK DESCRIPTION: " << theTaskDescription << endl << endl;
        writeToFile << "TASK PRIORITY: " << theTaskPriority << endl << endl;
        writeToFile << "TASK DUE DATE: " << theTaskDueDate << endl << endl;
        writeToFile.close();
    }
};

#endif __SUBTASK_SINGULAR_TASK_HPP__