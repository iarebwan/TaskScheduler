#ifndef __TASK_HPP__
#define __TASK_HPP__

#include <string>
#include <vector>

using namespace std;

class Task {
public:
    virtual void displayTask() = 0;
    virtual void setTaskTitle(string taskTitle) = 0;
    virtual string getTaskTitle() = 0;
    virtual void setTaskPriority(string taskPriority) = 0;
    virtual string getTaskPriority() = 0;
    virtual void setTaskDescription(string taskDescription) = 0;
    virtual string getTaskDescription() = 0;
    virtual void setTaskDueDate(string taskDueDate) = 0;
    virtual string getTaskDueDate() = 0;
    virtual void setTaskType(string taskType) = 0;
    virtual string getTaskType() = 0;
    virtual string checkTaskType() = 0;
    virtual vector<Task*> getEmbeddedListOfTasks() = 0;
    virtual void renameTaskFile(string oldTaskTitle) = 0;
    virtual void saveTaskInformation() = 0;
protected:
    string title;
    string priority;
    string description;
    string dueDate;
    string classification;
    vector<Task*> tasks;
    static int numberOfIndents;
    static int firstLayerDirectorySubtaskDisplayFlag;
    static int bootUpCompletedFlag;
};

int Task::numberOfIndents = 1;
int Task::firstLayerDirectorySubtaskDisplayFlag = 0;
int Task::bootUpCompletedFlag = 0;

#endif __TASK_HPP__