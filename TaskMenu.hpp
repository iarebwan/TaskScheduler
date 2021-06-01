//CS100 FINAL PROJECT
#ifndef _TASKMENU_HPP_
#define _TASKMENU_HPP_

#include "SetupTaskFiles.hpp"
#include "SubtaskSchedule.hpp"
#include "SubtaskSingularTask.hpp"
#include "OrderByDueDate.hpp"
#include "OrderByPriority.hpp"
#include "OrderByTaskType.hpp"
#include "OrderTasks.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class SingularSubtask;
class ScheduleSubtask;

class Menu : public SetupTaskFiles {
private:

    void printTasks(vector<Task *> &ListOfTasks, OrderTasks *orderType, string classification = "") {
        orderType->display(ListOfTasks, classification);
    }

    void printByDueDate(vector<Task *> &ListOfTasks) {
        OrderTasks *orderDueDate = new OrderByDueDate();
        printTasks(ListOfTasks, orderDueDate);
    }

    void printByPriority(vector<Task *> &ListOfTasks) {
        OrderTasks *orderPriority = new OrderByPriority();
        printTasks(ListOfTasks, orderPriority);
    }

    void printByClassification(vector<Task *> &ListOfTasks, string classification) {
        OrderTasks *orderTaskType = new OrderByTaskType();
        printTasks(ListOfTasks, orderTaskType, classification);
    }

    int userNumber;
    vector<Task*> theTasks;
public:

    Menu(vector<Task*> taskList) {
        theTasks = taskList;
    }

    int getUserNumber() {
        return userNumber;
    }

    void printTaskMenu() {
        cout << "Welcome to the Task Menu. What would you like to do?" << endl;
        cout << "-------------------------------------" << endl
             << "a - View all schedules and tasks" << endl
             << "b - Create a Schedule" << endl
             << "c - Create a Task" << endl
             << "d - Edit a Schedule" << endl
             << "e - Edit a Task" << endl
             << "f - Display by due date" << endl
             << "g - Display by priority" << endl
             << "h - Display by Classification" << endl
             << "i - Delete all Schedules and Tasks" << endl
             << "q - Exit Task Scheduler" << endl
             << "-------------------------------------" << endl << endl
             << "Choose an option: ";
        //TaskMenu();
    }

    void printScheduleActions() {                                       //Schedule is essentially a folder in this case
        cout << "What would you like to do with this schedule?" << endl
             << "-------------------------------------" << endl
             << "a - Rename Schedule Title" << endl
             << "b - Set priority" << endl
             << "c - Set Description" << endl
             << "d - Set Due Date" << endl
             << "e - Set Classification" << endl
             << "f - Embed Another Schedule" << endl
             << "g - Delete this Schedule" << endl
             << "q - Return to Task Scheduler" << endl
             << "-------------------------------------" << endl << endl
             << "Choose an option: ";
        ScheduleActions();
    }

    void printTaskActions() {
        cout << "What would you like to do with this Task?" << endl
             << "-------------------------------------" << endl
             << "a - Rename Task Title" << endl
             << "b - Set priority" << endl
             << "c - Set Description" << endl
             << "d - Set Due Date" << endl
             << "e - Set Classification" << endl
             << "f - Delete this Task" << endl
             << "q - Return to Task Scheduler" << endl
             << "-------------------------------------" << endl << endl
             << "Choose an option: ";
        TaskActions();
    }

    void TaskMenu() {
        char input;
        string userInput = "";
        cin >> input;
        cout << endl;

        while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&
               input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
               input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'h' &&
               input != 'H' && input != 'i' && input != 'I' && input != 'q' && input != 'Q') {
            cout << "Error: Unknown input. Please Select a valid option: ";
            cin >> input;
            cout << endl;
        }

        if (input == 'a' || input == 'A') {             //INPUT A = VIEW SCHEDULE(S) DONE
            if (theTasks.empty() == true) {
                cout << "There are no Schedules." << endl;
            } else {
                for (int l = 0; l < theTasks.size(); l++) {
                    cout << l + 1 << ")" << endl;
                    theTasks.at(l)->displayTask();
                    numberOfIndents = 1;
                    firstLayerDirectorySubtaskDisplayFlag = 0;
                }
            }
            cout << endl;
            printTaskMenu();
            TaskMenu();
        } else if (input == 'b' || input == 'B') {             //INPUT B = CREATE A SCHEDULE
            vector<Task *> listOfTasks;
            ScheduleSubtask *schedule = new ScheduleSubtask("", "", "", "", "", listOfTasks);
            theTasks.push_back(schedule);

            cout << "Type in a Schedule title followed by ENTER:" << endl;
            string title;
            getline(cin.ignore(), title);
            //setTaskTitle(title);
            theTasks.at(theTasks.size() - 1)->setTaskTitle(title);

            createSchedule(title);

            cout << "Type in the new schedules priority (high, medium, or low) followed by ENTER:" << endl;
            string priority;
            getline(cin.ignore(), priority);
            theTasks.at(theTasks.size() - 1)->setTaskPriority(priority);

            cout << "Type in the new schedules description followed by ENTER:" << endl;
            string description;
            getline(cin.ignore(), description);
            theTasks.at(theTasks.size() - 1)->setTaskDescription(description);

            cout << "Type in the new schedules due date (mm/dd/year) followed by ENTER:" << endl;
            string dueDate;
            getline(cin.ignore(), dueDate);
            theTasks.at(theTasks.size() - 1)->setTaskDueDate(dueDate);

            cout << "Type in the new schedules task type followed by ENTER:" << endl;
            string taskType;
            getline(cin.ignore(), taskType);
            theTasks.at(theTasks.size() - 1)->setTaskType(taskType);

            theTasks.at(theTasks.size() - 1)->saveTaskInformation();      //save the information
            importTasks();
            cout << endl;
            printTaskMenu();               //return to main menu
            TaskMenu();
        } else if (input == 'c' || input == 'C') {        //INPUT C = CREATE A TASK
            SingularSubtask *singularTask = new SingularSubtask("", "", "", "", "");
            theTasks.push_back(singularTask);

            cout << "Type in a task title followed by ENTER:" << endl;
            string title;
            getline(cin, title);
            //setTaskTitle(title);
            theTasks.at(theTasks.size() - 1)->setTaskTitle(title);

            createSchedule(title);

            cout << "Type in the new task priority (high, medium, or low) followed by ENTER:" << endl;
            string priority;
            getline(cin, priority);
            theTasks.at(theTasks.size() - 1)->setTaskPriority(priority);

            cout << "Type in the new task description followed by ENTER:" << endl;
            string description;
            getline(cin, description);
            theTasks.at(theTasks.size() - 1)->setTaskDescription(description);

            cout << "Type in the new task due date (mm/dd/year) followed by ENTER:" << endl;
            string dueDate;
            getline(cin, dueDate);
            theTasks.at(theTasks.size() - 1)->setTaskDueDate(dueDate);

            cout << "Type in the new task task type followed by ENTER:" << endl;
            string taskType;
            getline(cin, taskType);
            theTasks.at(theTasks.size() - 1)->setTaskType(taskType);

            theTasks.at(theTasks.size() - 1)->saveTaskInformation();      //save the information
            importTasks();
            cout << endl;
            printTaskMenu();               //return to main menu
            TaskMenu();
        } else if (input == 'd' || input == 'D') {        //INPUT D = EDIT SCHEDULE
            if (theTasks.empty() == true) {
                cout << "There are no schedules to edit." << endl;
            } else {
                cout << "Which schedule would you like to edit? Please enter the corresponding number next to the Schedule" << endl;
                for (int l = 0; l < theTasks.size(); l++) {
                    cout << l + 1 << ")" << endl;
                    theTasks.at(l)->displayTask();
                    numberOfIndents = 1;
                    firstLayerDirectorySubtaskDisplayFlag = 0;
                }

                cin >> userNumber;
                while (userNumber > theTasks.size() || userNumber <= 0) {
                    cout << "ERROR: Enter a valid number:" << endl;
                    cin >> userNumber;
                    cout << endl;
                }
                if (theTasks.at(userNumber - 1)->checkTaskType() == "Schedule Task") {
                    printScheduleActions();
                    ScheduleActions();
                } else {
                    cout << "ERROR: Entered Invalid Schedule. Returning to main menu." << endl;
                    printTaskMenu();
                }
            }
        } else if (input == 'e' || input == 'E') {        //INPUT E = EDIT TASK NEEDS HELP
            if (theTasks.empty() == true) {
                cout << "There are no tasks to edit." << endl;
            } else {
                cout << "Which task would you like to edit? Please enter the corresponding number next to the task";
                for (int l = 0; l < theTasks.size(); l++) {
                    cout << l + 1 << ")" << endl;
                    theTasks.at(l)->displayTask();
                    numberOfIndents = 1;
                    firstLayerDirectorySubtaskDisplayFlag = 0;
                }

                cin >> userNumber;
                while (!(cin >> userNumber) || userNumber > theTasks.size() || userNumber <= 0) {
                    cout << "ERROR: Enter a valid number:" << endl;
                    cin >> userNumber;
                    cout << endl;
                }

                if (theTasks.at(userNumber - 1)->checkTaskType() == "Singular Task") {
                    cout << endl << theTasks.at(userNumber - 1)
                         << " - ";      //subtract 1 to get the right cell inside vector
                } else {
                    cout << "ERROR: Entered Invalid Task. Returning to main menu." << endl;
                    printTaskMenu();
                }

            }
            printTaskActions();
            TaskActions();
        } else if (input == 'f' || input == 'F') {        //INPUT F = DUE DATE DISPLAY
            printByDueDate(theTasks);
            printTaskMenu();
            TaskMenu();
        } else if (input == 'g' || input == 'G') {        //INPUT G = PRIORITY DISPLAY
            printByPriority(theTasks);
            printTaskMenu();
            TaskMenu();
        } else if (input == 'h' || input == 'H') {        //INPUT H = CLASSIFICATION DISPLAY
            string classificationType;
            cout << "Enter the classification (work, personal, or academic) you want displayed on top" << endl;
            cin >> classificationType;
            while (!(classificationType == "work" || classificationType == "personal" ||
                    classificationType == "academic" || classificationType == "Work" || classificationType == "Personal" ||
                                                            classificationType == "Academic")) {
                cout << "Enter a valid classification (work, personal, or academic): " << endl;
                cin >> classificationType;
            }
            printByClassification(theTasks, classificationType);
            printTaskMenu();
            TaskMenu();
        } else if (input == 'i' || input == 'I') {        //INPUT I = DELETE ALL SCHEDULES/TASKS
            theTasks.clear();
            printTaskMenu();
            TaskMenu();
            //TODO: clear database as well
        } else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
            cout << "See you later!" << endl;
            exit;
        }
    }


    void ScheduleActions() {
        char input;
        string userInput = "";
        cin >> input;
        cout << endl;

        while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&
               input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
               input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'q' &&
               input != 'Q') {
            cout << "Error: Unknown input. Please Select a valid option: ";
            cin >> input;
            cout << endl;
        }

        if (input == 'a' || input == 'A') {        //INPUT A = RENAME SCHEDULE
            cout << "What would you like to rename your schedule to?" << endl;
            string rename;
            getline(cin.ignore(), rename);
            string oldTaskTitle = theTasks.at(getUserNumber() - 1)->getTaskTitle();
            theTasks.at(getUserNumber() - 1)->setTaskTitle(rename);
            cout << "Your Schedule has been re-named to " << rename << '!' << endl;
            switchIntoDesiredDirectory(oldTaskTitle);
            renameTaskFile(oldTaskTitle);
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printScheduleActions();
            ScheduleActions();
        } else if (input == 'b' || input == 'B') {        //INPUT B = SET SCHEDULE PRIORITY
            string setPriority;
            getline(cin.ignore(), setPriority);
            theTasks.at(getUserNumber() - 1)->setTaskPriority(setPriority);
            cout << "Your Schedule has been re-prioritized to " << setPriority << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printScheduleActions();
            ScheduleActions();
        } else if (input == 'c' || input == 'C') {        //INPUT C = SET SCHEDULE DESCRIPTION
            string newDescription;
            getline(cin.ignore(), newDescription);
            setTaskDescription(newDescription);
            theTasks.at(getUserNumber() - 1)->setTaskDescription(newDescription);
            cout << "Your Schedule has been re-described to " << newDescription << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printScheduleActions();
            ScheduleActions();
        } else if (input == 'd' || input == 'D') {        //INPUT D = SET SCHEDULE DUE DATE
            string dueDate;
            getline(cin.ignore(), dueDate);
            theTasks.at(getUserNumber() - 1)->setTaskDueDate(dueDate);
            cout << "Your Schedule date has been changed to " << dueDate << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printScheduleActions();
            ScheduleActions();
        } else if (input == 'e' || input == 'E') {        //INPUT E = SET SCHEDULE CLASSIFICATION
            string setClassification;
            getline(cin.ignore(), setClassification);
            theTasks.at(getUserNumber() - 1)->setTaskType(setClassification);
            cout << "Your Schedule date has been changed to " << setClassification << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printScheduleActions();
            ScheduleActions();
        } else if (input == 'f' || input == 'f') {        //INPUT F = EMBED ANOTHER SCHEDULE
            vector<Task *> listOfTasks;
            ScheduleSubtask *schedule = new ScheduleSubtask("", "", "", "", "", listOfTasks);
            vector<Task*> embeddedListOfTasks = theTasks.at(userNumber - 1)->getEmbeddedListOfTasks();
            embeddedListOfTasks.push_back(schedule);

            cout << "Type in a Schedule title followed by ENTER:" << endl;
            string title;
            getline(cin, title);
            embeddedListOfTasks.at(embeddedListOfTasks.size() - 1)->setTaskTitle(title);
            switchIntoDesiredDirectory(theTasks.at(getUserNumber() - 1)->getTaskTitle());
            createSchedule(title);

            cout << "Type in the new schedules priority (high, medium, or low) followed by ENTER:" << endl;
            string priority;
            getline(cin, priority);
            embeddedListOfTasks.at(embeddedListOfTasks.size() - 1)->setTaskPriority(priority);

            cout << "Type in the new schedules description followed by ENTER:" << endl;
            string description;
            getline(cin, description);
            embeddedListOfTasks.at(embeddedListOfTasks.size() - 1)->setTaskDescription(description);

            cout << "Type in the new schedules due date (mm/dd/year) followed by ENTER:" << endl;
            string dueDate;
            getline(cin, dueDate);
            embeddedListOfTasks.at(embeddedListOfTasks.size() - 1)->setTaskDueDate(dueDate);

            cout << "Type in the new schedules task type followed by ENTER:" << endl;
            string taskType;
            getline(cin, taskType);
            embeddedListOfTasks.at(embeddedListOfTasks.size() - 1)->setTaskType(taskType);

            embeddedListOfTasks.at(embeddedListOfTasks.size() - 1)->saveTaskInformation();      //save the information
            importTasks();
            cout << endl;
            printTaskMenu();               //return to main menu
            TaskMenu();
        } else if (input == 'g' || input == 'G') {        //INPUT G = DELETE THIS SCHEDULE
            deleteTask(theTasks.at(getUserNumber() - 1)->getTaskTitle());
            vector<Task*>::iterator itr = theTasks.begin();
            advance(itr, getUserNumber() - 1);
            theTasks.erase(itr);
            cout << "Your Schedule has successfully been deleted!\n Returning to main menu..." << endl;
            importTasks();
            printTaskMenu();
            TaskMenu();
        } else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
            cout << "Back to main menu!" << endl;
            printTaskMenu();
            TaskMenu();
        }
    }

    void TaskActions() {
        char input;
        cin >> input;
        cout << endl;

        while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&
               input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
               input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'q' &&
               input != 'Q') {
            cout << "Error: Unknown input. Please Select a valid option: ";
            cin >> input;
            cout << endl;
        }

        if (input == 'a' || input == 'A') {        //INPUT A = RENAME TASK
            cout << "What would you like to rename your task to?";
            string rename;
            getline(cin, rename);
            theTasks.at(getUserNumber() - 1)->setTaskTitle(rename);
            cout << "Your task has been re-named to " << rename << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printTaskActions();
            TaskActions();
        } else if (input == 'b' || input == 'B') {        //INPUT B = SET TASK PRIORITY
            string setPriority;
            getline(cin, setPriority);
            theTasks.at(getUserNumber() - 1)->setTaskPriority(setPriority);
            cout << "Your task has been re-prioritized to " << setPriority << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printTaskActions();
            TaskActions();
        } else if (input == 'c' || input == 'C') {        //INPUT C = SET TASK DESCRIPTION
            string newDescription;
            getline(cin, newDescription);
            setTaskDescription(newDescription);
            theTasks.at(getUserNumber() - 1)->setTaskDescription(newDescription);
            cout << "Your task has been re-described to " << newDescription << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printTaskActions();
            TaskActions();
        } else if (input == 'd' || input == 'D') {        //INPUT D = SET TASK DUE DATE
            string dueDate;
            getline(cin, dueDate);
            theTasks.at(getUserNumber() - 1)->setTaskDueDate(dueDate);
            cout << "Your Task date has been changed to " << dueDate << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printTaskActions();
            TaskActions();
        } else if (input == 'e' || input == 'E') {        //INPUT E = SET TASK CLASSIFICATION
            string setClassification;
            getline(cin, setClassification);
            theTasks.at(getUserNumber() - 1)->setTaskType(setClassification);
            cout << "Your Task date has been changed to " << setClassification << '!' << endl;
            theTasks.at(getUserNumber() - 1)->saveTaskInformation();
            importTasks();
            printTaskActions();
            TaskActions();
        } else if (input == 'f' || input == 'F') {        //INPUT F = EMBED ANOTHER TASK
            // cout << "Type in a Task title followed by ENTER:" << endl;
            // string title;
            // getline(cin, title);
            // tasks.at(getUserNumber() - 1)->setTaskTitle(title);                                          //WE WANT TO FORMAT EVERYTHING LIKE THIS

            // cout << "Type in the new schedules priority followed by ENTER:" << endl;
            // string priority;
            // getline(cin, priority);
            // setTaskPriority(priority);

            // cout << "Type in the new schedules description followed by ENTER:" << endl;
            // string description;
            // getline(cin, description);
            // setTaskDescription(description);

            // cout << "Type in the new schedules due date followed by ENTER:" << endl;
            // string dueDate;
            // getline(cin, dueDate);
            // setTaskDueDate(dueDate);

            // cout << "Type in the new schedules task type followed by ENTER:" << endl;
            // string taskType;
            // getline(cin, taskType);
            // setTaskDescription(taskType);

            // saveTaskInformation();      //save the information

            // cout << endl;
            // printTaskMenu();            //return to main menu
        } else if (input == 'g' || input == 'G') {        //INPUT G = DELETE THIS TASK NEEDS HELP
            deleteTask(tasks.at(getUserNumber() - 1)->getTaskTitle());
            vector<Task*>::iterator itr = tasks.begin();
            advance(itr, getUserNumber() - 1);
            theTasks.erase(itr);
            cout << "Your Schedule has successfully been deleted!\n Returning to main menu..." << endl;
            importTasks();
            printTaskMenu();
            TaskMenu();
        } else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
            cout << "Main menu!" << endl;
            printTaskMenu();
            TaskMenu();
        }
    }
};
#endif