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
    SingularSubtask(string taskTitle, string taskPriority, string taskDescription, string taskDueDate, string taskType) {
        title = taskTitle;
        priority = taskPriority;
        description = taskDescription;
        dueDate = taskDueDate;
        classification = taskType;
    }

    void displayTask() {
        if(firstLayerDirectorySubtaskDisplayFlag == 0) {
            cout << "TASK TITLE: " << getTaskTitle() << endl;
            cout << "TASK PRIORITY: " << getTaskPriority() << endl;
            cout << "TASK DESCRIPTION: " << getTaskDescription() << endl;
            cout << "TASK DUE DATE: " << getTaskDueDate() << endl;
            cout << "TASK TYPE: " << getTaskType() << endl << endl;
        }
        else {
            for (int i = 0; i < numberOfIndents; i++) {
                cout << "\t";
            }
            cout << "TASK TITLE: " << getTaskTitle() << endl;
            for (int i = 0; i < numberOfIndents; i++) {
                cout << "\t";
            }
            cout << "TASK PRIORITY: " << getTaskPriority() << endl;
            for (int i = 0; i < numberOfIndents; i++) {
                cout << "\t";
            }
            cout << "TASK DESCRIPTION: " << getTaskDescription() << endl;
            for (int i = 0; i < numberOfIndents; i++) {
                cout << "\t";
            }
            cout << "TASK DUE DATE: " << getTaskDueDate() << endl;
            for(int i = 0; i < numberOfIndents; i++) {
                cout << "\t";
            }
            cout << "TASK TYPE: " << getTaskType() << endl;
        }
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

    void setTaskType(string taskType) {
        classification = taskType;
    }

    string getTaskType() {
        return classification;
    }

    string checkTaskType() {
        return "Singular Task";
    }

protected:
    void saveTaskInformation() {
        fstream writeToFile;
        string fileName = getTaskTitle();
        writeToFile.open(fileName, ios::out | ios::trunc);
        string theTaskDescription = getTaskDescription();
        string theTaskPriority = getTaskPriority();
        string theTaskDueDate = getTaskDueDate();
        string theTaskType = getTaskType();
        writeToFile << "TASK DESCRIPTION: " << theTaskDescription << endl << endl;
        writeToFile << "TASK PRIORITY: " << theTaskPriority << endl << endl;
        writeToFile << "TASK DUE DATE: " << theTaskDueDate << endl << endl;
        writeToFile << "TASK CLASSIFICATION: " << theTaskType << endl << endl;
        writeToFile.close();
    }
};

#endif __SUBTASK_SINGULAR_TASK_HPP__