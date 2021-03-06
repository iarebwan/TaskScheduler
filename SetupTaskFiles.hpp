#ifndef __SETUP_TASK_FILES_HPP__
#define __SETUP_TASK_FILES_HPP__

#include "SubtaskSingularTask.hpp"
#include "SubtaskSchedule.hpp"

#include <iostream>
#include <filesystem>
#include <dir.h>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;
namespace fs = std::filesystem;

class SingularSubtask;
class ScheduleSubtask;

//Reminder: deallocate memory

class SetupTaskFiles : public Task {
public:
    vector<Task*> importTasks() {
        tasks.clear();
        int numOfDirectories = 0;
        bool directoryStillExists = true;
        if(bootUpCompletedFlag == 0) {
            int checkIfTaskDirectoryExists = chdir("Tasks");
            if (checkIfTaskDirectoryExists != 0) {
                mkdir("Tasks");
                chdir("Tasks");
            }
            bootUpCompletedFlag = 1;
        }
        const fs::path pathToShow(fs::current_path());
        for(const auto& content : fs::directory_iterator(pathToShow)) {
            const auto contentName = content.path().filename().string();
            const auto contentNameWithoutFileExtension = contentName.substr(0, contentName.length() - 4);
            if(content.is_directory()) {
                const char* directoryName = contentName.c_str();
                string innerDirectory = "";
                while(directoryStillExists) {
                    if(numOfDirectories == 0) {
                        chdir(directoryName);
                    }
                    else {
                        const char* innerDirectoryName = innerDirectory.c_str();
                        chdir(innerDirectoryName);
                    }
                    numOfDirectories++;
                    int directoryChangeFlag = false;
                    for(const auto& innerContent : fs::directory_iterator(fs::current_path())) {
                        const auto innerContentName = innerContent.path().filename().string();
                        if(innerContentName != "." && innerContentName != ".." && innerContent.is_directory()) {
                            innerDirectory = innerContent.path().filename().string();
                            directoryChangeFlag = true;
                            break;
                        }
                    }
                    if(!directoryChangeFlag) {
                        break;
                    }
                }
                directoryWithNumOfSubDirectories[contentName] = numOfDirectories;
                firstLayerDirectories.push_back(contentName);
                directories.push_back(directoryWithNumOfSubDirectories);
                for(int i = 0; i < numOfDirectories; i++) {
                    chdir("..");
                }
                numOfDirectories = 0;
            }
            else if(content.is_regular_file()) {
                string theDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                string thePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                string theDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                string theTaskType = openAndReadTaskInformation("TASK CLASSIFICATION: ", contentName);
                SingularSubtask *singleSubtask = new SingularSubtask(contentNameWithoutFileExtension, thePriority, theDescription, theDueDate, theTaskType);
                tasks.push_back(singleSubtask);
            }
        }

        for(int i = 0; i < directories.size(); i++) {
            int numOfSubDirectories = directories.at(i)[firstLayerDirectories.at(i)];
            int j = 1;
            const char* firstLayerDirectory = firstLayerDirectories.at(i).c_str();
            chdir(firstLayerDirectory);
            for(const auto& content : fs::directory_iterator(fs::current_path())) {
                const auto contentName = content.path().filename().string();
                if(content.is_directory()) {
                    const char* directoryName = contentName.c_str();
                    chdir(directoryName);
                    j++;
                    if(j == numOfSubDirectories) {
                        break;
                    }
                }
            }
            for(int k = 0; k < numOfSubDirectories; k++) {
                string scheduleTitle;
                string scheduleDescription;
                string schedulePriority;
                string scheduleDueDate;
                string scheduleTaskType;
                if(k == 0) {
                    for(const auto& content : fs::directory_iterator(fs::current_path())) {
                        const auto contentName = content.path().filename().string();
                        const auto contentNameWithoutFileExtension = contentName.substr(0, contentName.length() - 4);
                        const auto directoryFile = fs::current_path().filename().string();
                        if(contentNameWithoutFileExtension == directoryFile) {
                            scheduleTitle = contentNameWithoutFileExtension;
                            scheduleDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            schedulePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            scheduleDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                            scheduleTaskType = openAndReadTaskInformation("TASK CLASSIFICATION: ", contentName);
                        }
                        else {
                            string theDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            string thePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            string theDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                            string theTaskType = openAndReadTaskInformation("TASK CLASSIFICATION: ", contentName);
                            SingularSubtask *singleSubtask = new SingularSubtask(contentNameWithoutFileExtension, thePriority, theDescription, theDueDate, theTaskType);
                            listOfTasksFromSubDirectory.push_back(singleSubtask);
                        }
                    }
                    ScheduleSubtask *scheduleSubtask = new ScheduleSubtask(scheduleTitle, schedulePriority, scheduleDescription, scheduleDueDate, scheduleTaskType, listOfTasksFromSubDirectory);
                    listOfTasksFromSubDirectory.clear();
                    listOfTasksFromSubDirectory.push_back(scheduleSubtask);
                }
                else {
                    chdir("..");
                    for(const auto& content : fs::directory_iterator(fs::current_path())) {
                        const auto contentName = content.path().filename().string();
                        const auto contentNameWithoutFileExtension = contentName.substr(0, contentName.length() - 4);
                        const auto directoryFile = fs::current_path().filename().string();
                        if(content.is_directory()) {
                            continue;
                        }
                        else if(content.is_regular_file() && contentNameWithoutFileExtension == directoryFile) {
                            scheduleTitle = contentNameWithoutFileExtension;
                            scheduleDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            schedulePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            scheduleDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                            scheduleTaskType = openAndReadTaskInformation("TASK CLASSIFICATION: ", contentName);
                        }
                        else if(content.is_regular_file() && contentNameWithoutFileExtension != directoryFile) {
                            string theDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            string thePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            string theDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                            string theTaskType = openAndReadTaskInformation("TASK CLASSIFICATION: ", contentName);
                            SingularSubtask *singleSubtask = new SingularSubtask(contentNameWithoutFileExtension, thePriority, theDescription, theDueDate, theTaskType);
                            listOfTasksFromSubDirectory.push_back(singleSubtask);
                        }
                    }
                    Task* temp = listOfTasksFromSubDirectory.at(0);
                    listOfTasksFromSubDirectory.at(0) = listOfTasksFromSubDirectory.at(listOfTasksFromSubDirectory.size() - 1);
                    listOfTasksFromSubDirectory.at(listOfTasksFromSubDirectory.size() - 1) = temp;
                    ScheduleSubtask *scheduleSubtask = new ScheduleSubtask(scheduleTitle, schedulePriority, scheduleDescription, scheduleDueDate, scheduleTaskType, listOfTasksFromSubDirectory);
                    listOfTasksFromSubDirectory.clear();
                    listOfTasksFromSubDirectory.push_back(scheduleSubtask);
                }
            }
            chdir("..");
            Task* schedule = listOfTasksFromSubDirectory.at(0);
            tasks.push_back(schedule);
            listOfTasksFromSubDirectory.clear();
        }

        //Testing Purposes
        /*for(int l = 0; l < tasks.size(); l++) {
            cout << l + 1 << ")" << endl;
            tasks.at(l)->displayTask();
            numberOfIndents = 1;
            firstLayerDirectorySubtaskDisplayFlag = 0;
        }*/

        string originalDirectory = fs::current_path().stem().string();
        if(originalDirectory != "Tasks") {
            bool inOriginalDirectory = false;
            while(!inOriginalDirectory) {
                chdir("..");
                originalDirectory = fs::current_path().stem().string();
                if(originalDirectory == "Tasks") {
                    inOriginalDirectory = true;
                    break;
                }
            }
        }
        return tasks;
    }

    string openAndReadTaskInformation(string taskInformation, string fileName) {
        fstream readFile;
        string line;
        string theTaskInformation;
        readFile.open(fileName, ios::in);
        while(getline(readFile, line)) {
            if(line.find(taskInformation, 0) != string::npos) {
                if(taskInformation == "TASK DESCRIPTION: ") {
                    theTaskInformation = line.substr(18, line.length());
                }
                else if(taskInformation == "TASK PRIORITY: " || taskInformation == "TASK DUE DATE: ") {
                    theTaskInformation = line.substr(15, line.length());
                }
                else if(taskInformation == "TASK CLASSIFICATION: ") {
                    theTaskInformation = line.substr(21, line.length());
                }
                break;
            }
        }
        return theTaskInformation;
    }

    void deleteTask(string taskTitle) {
        for(const auto& content : fs::directory_iterator(fs::current_path())) {
            const auto contentName = content.path().filename().string();
            const auto contentNameWithoutFileExtension = contentName.substr(0, contentName.length() - 4);
            if(content.is_directory() && taskTitle == contentName) {
                const char* fileToBeDeleted = taskTitle.c_str();
                fs::remove_all(fileToBeDeleted);
                break;
            }
            else if(content.is_regular_file() && contentNameWithoutFileExtension == taskTitle) {
                taskTitle += ".txt";
                const char* fileToBeDeleted = taskTitle.c_str();
                remove(fileToBeDeleted);
                break;
            }
        }
    }

    void switchIntoDesiredDirectory(string desiredDirectoryFirstLayerDirectory) {
        int i;
        for(i = 0; i < firstLayerDirectories.size(); i++) {
            if(desiredDirectoryFirstLayerDirectory == firstLayerDirectories.at(i)) {
                break;
            }
        }
        int numOfDirectoriesToSwitch = directories.at(i)[desiredDirectoryFirstLayerDirectory];
        for(int j = 0; j < numOfDirectoriesToSwitch; j++) {
            if(j == 0) {
                const char* firstLayerDirectory = desiredDirectoryFirstLayerDirectory.c_str();
                chdir(firstLayerDirectory);
            }
            else {
                for(const auto& content : fs::directory_iterator(fs::current_path())) {
                    if(content.is_directory()) {
                        const auto contentName = content.path().filename().string();
                        const char* directoryToChangeInto = contentName.c_str();
                        chdir(directoryToChangeInto);
                    }
                }
            }
        }
    }

    void displayTask() {}
    void setTaskTitle(string taskTitle) {}
    string getTaskTitle() {}
    void setTaskPriority(string taskPriority) {}
    string getTaskPriority() {}
    void setTaskDescription(string taskDescription) {}
    string getTaskDescription() {}
    void setTaskDueDate(string taskDueDate) {}
    string getTaskDueDate() {}
    void setTaskType(string taskType) {}
    string getTaskType() {}
    string checkTaskType() {}
    void createSchedule(string theTaskTitleStr) {
        const char* theTaskTitle = theTaskTitleStr.c_str();
        mkdir(theTaskTitle);
        chdir(theTaskTitle);
    }
    vector<Task*> getEmbeddedListOfTasks() {}
    void renameTaskFile(string oldTaskTitle) {}
    void saveTaskInformation() {}
private:
    map<string, int> directoryWithNumOfSubDirectories;
    vector<map<string, int>> directories;
    vector<string> firstLayerDirectories;
    vector<Task*> listOfTasksFromSubDirectory;
};

#endif //__SETUP_TASK_FILES_HPP__