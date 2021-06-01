#ifndef __SUBTASK_SCHEDULE_HPP__
#define __SUBTASK_SCHEDULE_HPP__

#include "Task.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <dir.h>
#include <fstream>
#include <stdio.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Task;

class ScheduleSubtask : public Task {
public:
    ScheduleSubtask(string taskTitle, string taskPriority, string taskDescription, string taskDueDate, string taskType, vector<Task*> theListOfTasks) {
        title = taskTitle;
        priority = taskPriority;
        description = taskDescription;
        dueDate = taskDueDate;
        classification = taskType;
        listOfTasks = theListOfTasks;
    }

    void displayTask() {
        if(firstLayerDirectorySubtaskDisplayFlag == 0) {
            firstLayerDirectorySubtaskDisplayFlag = 1;
            cout << "TASK TITLE: " << getTaskTitle() << endl;
            cout << "TASK PRIORITY: " << getTaskPriority() << endl;
            cout << "TASK DESCRIPTION: " << getTaskDescription() << endl;
            cout << "TASK DUE DATE: " << getTaskDueDate() << endl;
            cout << "TASK TYPE: " << getTaskType() << endl;
            displaySubtasks();
        }
        else if(firstLayerDirectorySubtaskDisplayFlag == 1) {
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
            displaySubtasks();
            cout << endl;
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
        return "Schedule Task";
    }

    vector<Task*> getEmbeddedListOfTasks() {
        return listOfTasks;
    }

    void displaySubtasks() {
        for(int i = 0; i < listOfTasks.size(); i++) {
            if(listOfTasks.at(i)->checkTaskType() == "Schedule Task") {
                numberOfIndents++;
                listOfTasks.at(i)->displayTask();
            }
            else if(listOfTasks.at(i)->checkTaskType() == "Singular Task") {
                listOfTasks.at(i)->displayTask();
            }
        }
    }

    void renameTaskFile(string oldTaskTitleStr) {
        oldTaskTitleStr += ".txt";
        const char* oldTaskTitle = oldTaskTitleStr.c_str();
        string newTaskTitleStr = getTaskTitle() + ".txt";
        const char* newTaskTitle = newTaskTitleStr.c_str();
        rename(oldTaskTitle, newTaskTitle);
        chdir("..");
        for(const auto& content : fs::directory_iterator(fs::current_path())) {
            if(content.is_directory()) {
                fs::rename(oldTaskTitleStr, getTaskTitle());
                const char* newTaskTitle2 = newTaskTitleStr.substr(0, newTaskTitleStr.length() - 4).c_str();
                chdir(newTaskTitle2);
                break;
            }
        }
    }

    void saveTaskInformation() {
        fstream writeToFile;
        string fileName = getTaskTitle() + ".txt";
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

    // void createSchedule() {
    //     string theTaskTitleStr = getTaskTitle();
    //     const char* theTaskTitle = theTaskTitleStr.c_str();
    //     mkdir(theTaskTitle);
    //     chdir(theTaskTitle);
    // }

private:
    vector<Task*> listOfTasks;
};

#endif //__SUBTASK_SCHEDULE_HPP__