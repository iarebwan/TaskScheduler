#ifndef __SUBTASK_SCHEDULE_HPP__
#define __SUBTASK_SCHEDULE_HPP__

#include "Task.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <dir.h>
#include <fstream>

using namespace std;

class Task;

class ScheduleSubtask : public Task {
public:
    ScheduleSubtask(string taskTitle, string taskPriority, string taskDescription, string taskDueDate, vector<Task*> theListOfTasks) {
        title = taskTitle;
        priority = taskPriority;
        description = taskDescription;
        dueDate = taskDueDate;
        listOfTasks = theListOfTasks;
    }

    void displayTask() {
        cout << "TASK TITLE: " << getTaskTitle() << endl;
        cout << "TASK PRIORITY: " << getTaskPriority() << endl;
        cout << "TASK DESCRIPTION: " << getTaskDescription() << endl;
        cout << "TASK TASK DUE DATE: " << getTaskDueDate() << endl;
        //cout << "SUBTASKS: " << displaySubtasks() << endl << endl;
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

    void viewSubtaskPriorities() {
        for(int i = 0; i < tasks.size(); i++) {

        }
    }

    void displaySubtasks() {

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

    void createSchedule() {
        string theTaskTitleStr = getTaskTitle();
        const char* theTaskTitle = theTaskTitleStr.c_str();
        mkdir(theTaskTitle);
        chdir(theTaskTitle);
    }

private:
    vector<Task*> listOfTasks;
};

#endif __SUBTASK_SCHEDULE_HPP__