#ifndef __SETUP_TASK_FILES_HPP__
#define __SETUP_TASK_FILES_HPP__

//#include "Task.hpp"
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

class SetupTaskFiles : public Task {
public:
    void importTasks() {
        int numOfDirectories;
        bool directoryStillExists = true;
        const fs::path pathToShow{ _argc >= 2 ? _argv[1] : fs::current_path() };
        for(const auto& content : fs::directory_iterator(pathToShow)) {
            const auto contentName = content.path().filename().string();
            if(content.is_directory()) {
                const char* directoryName = contentName.c_str();
                while(directoryStillExists) {
                    chdir(directoryName);
                    numOfDirectories++;
                    string previousDirectoryName = directoryName;
                    for(const auto& innerContent : fs::directory_iterator(directoryName)) {
                        if(innerContent.is_directory()) {
                            directoryName = innerContent.path().fileName.string();
                            break;
                        }
                    }
                    if(previousDirectoryName == directoryName) {
                        break;
                    }
                }
                directoryWithNumOfSubDirectories[contentName] = numOfDirectories;
                firstLayerDirectories.push_back(contentName);
                directories.push_back(directoryWithNumOfSubDirectories);
            }
            else if(content.is_regular_file()) {
                numOfDirectories = 0;
                string theDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                string thePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                string theDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                SingularSubtask *singleSubtask = new SingularSubtask(contentName, thePriority, theDescription, theDueDate);
                tasks.push_back(singleSubtask);
            }
        }

        for(int i = 0; i < directories.size(); i++) {
            int numOfSubDirectories = directories.at(i)[firstLayerDirectories.at(i)];
            int j = 1;
            const char* firstLayerDirectory = firstLayerDirectories.at(i).c_str();
            chdir(firstLayerDirectory);
            string currentDirectory = firstLayerDirectories.at(i);
            for(const auto& content : fs::directory_iterator(currentDirectory)) {
                const auto contentName = content.path().filename().string();
                if(content.is_directory()) {
                    chdir(contentName);
                    currentDirectory = contentName;
                    j++;
                    if(j == numOfSubDirectories) {
                        currentDirectory = contentName;
                        break;
                    }
                }
            }
            for(int k = 0; k < numOfSubDirectories; k++) {
                string scheduleTitle;
                string scheduleDescription;
                string schedulePriority;
                string scheduleDueDate;
                if(k == 0) {
                    for(const auto& content : fs::directory_iterator(currentDirectory)) {
                        const auto contentName = content.path().filename().string();
                        if(contentName == currentDirectory) {
                            scheduleTitle = contentName;
                            scheduleDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            schedulePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            scheduleDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                        }
                        else {
                            string theDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            string thePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            string theDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                            SingularSubtask *singleSubtask = new SingularSubtask(contentName, thePriority, theDescription, theDueDate);
                            listOfTasksFromSubDirectory.push_back(singleSubtask);
                        }
                    }
                    ScheduleSubtask *scheduleSubtask = new ScheduleSubtask(scheduleTitle, schedulePriority, scheduleDescription, scheduleDueDate, listOfTasksFromSubDirectory);
                    listOfTasksFromSubDirectory.clear();
                    listOfTasksFromSubDirectory.push_back(scheduleSubtask);
                }
                else {
                    chdir("..");
                    currentDirectory = fs::current_path().filename().string();
                    for(const auto& content : fs::directory_iterator(currentDirectory)) {
                        const auto contentName = content.path().filename().string();
                        if(content.is_directory()) {
                            continue;
                        }
                        else if(content.is_regular_file() && contentName == currentDirectory) {
                            scheduleTitle = contentName;
                            scheduleDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            schedulePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            scheduleDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                        }
                        else if(content.is_regular_file() && contentName != currentDirectory) {
                            string theDescription = openAndReadTaskInformation("TASK DESCRIPTION: ", contentName);
                            string thePriority = openAndReadTaskInformation("TASK PRIORITY: ", contentName);
                            string theDueDate = openAndReadTaskInformation("TASK DUE DATE: ", contentName);
                            SingularSubtask *singleSubtask = new SingularSubtask(contentName, thePriority, theDescription, theDueDate);
                            listOfTasksFromSubDirectory.push_back(singleSubtask);
                        }
                    }
                    ScheduleSubtask *scheduleSubtask = new ScheduleSubtask(scheduleTitle, schedulePriority, scheduleDescription, scheduleDueDate, listOfTasksFromSubDirectory);
                    listOfTasksFromSubDirectory.clear();
                    listOfTasksFromSubDirectory.push_back(scheduleSubtask);
                }
            }
            Task* schedule = listOfTasksFromSubDirectory.at(0);
            tasks.push_back(schedule);
        }
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
                break;
            }
        }
        return theTaskInformation;
    }

private:
    map<string, int> directoryWithNumOfSubDirectories;
    vector<map<string, int>> directories;
    vector<string> firstLayerDirectories;
    vector<Task*> listOfTasksFromSubDirectory;
};

#endif __SETUP_TASK_FILES_HPP__