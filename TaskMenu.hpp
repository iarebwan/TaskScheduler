//CS100 FINAL PROJECT
#ifndef _TASKMENU_HPP_
#define _TASKMENU_HPP_

#include "SetupTaskFiles.hpp"
#include "SubtaskFiles.hpp"
#include "SubtaskSingularTask.hpp"
#include "OrderByDueDate.hpp"
#include "OrderByPriority.hpp"
#include "OrderByTaskType.hpp"
#include "OrderTasks.hpp"


#include <iostream>

using namespace std;

class Menu {
    private:
        void importTasksFromDatabase();
        bool verifyList();
        bool verifyTask;
        void importTasksFromDatabase();

    public:
        vector<Task*> tasks;

//===========================================================================

void ScheduleActions(){
            char input;
            printScheduleActions();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && 
                   input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' && 
                   input != 'f' && input != 'F' && input != 'q' && input != 'Q') {
                cout << "Error: Unknown input. Please Select a valid option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a' || input == 'A') {        //INPUT A = RENAME SCHEDULE
            cout << "What would you like to rename your schedule to?";
                string rename;
                getline(cin, rename);
                setTaskTitle(rename);
                cout << "Your Schedule has been re-named to " << rename << '!';
                printScheduleActions();
                ScheduleActions();
            }

            else if (input == 'b' || input == 'B') {        //INPUT B = SET SCHEDULE PRIORITY
            
            }

            else if (input == 'c' || input == 'C') {        //INPUT C = EDIT SCHEDULE DESCRIPTION
                string newDescription;
                getline(cin, newDescription);
                setTaskDescription(newDescription);
                printScheduleActions();
                ScheduleActions();
            }

            else if (input == 'd' || input == 'D') {        //INPUT D = SET SCHEDULE DUE DATE
                cout <<"Enter the day, month, and year of your schedule due date:" << endl;
                int day; 
                int month; 
                int year;
                cout << "Day:";
                cin >> day;

                while(isdigit(day)){
                    if(day > 32 || day < 1){
                        cout << "Error: Please enter a valid day.";
                        cin >> day;
                    }
                    else{
                        continue;
                    }
                }

                cout << "Month:";
                cin >> month;
                while(isdigit(month)){
                    if(month > 12 || month < 1){
                        cout << "Error: Please enter a valid month.";
                        cin >> day;
                    }
                    else{
                        continue;
                    }
                }
                cout << "Year";
                cin >> year;
                while(isdigit(year)){
                    if(year < 0){
                        cout << "Error: Please enter a valid year.";
                        cin >> year;
                    }
                    else{
                        continue;
                    }
                }
                setDueDate(day, month, year);
                
            }
            else if (input == 'e' || input == 'E') {        //INPUT E = DISPLAY CURRENT SCHEDULE
            
            }
            else if (input == 'f' || input == 'F') {        //INPUT F = EMBED ANOTHER SCHEDULE
            
            }
            else if (input == 'g' || input == 'G') {        //INPUT G = DELETE THIS SCHEDULE
            
            }

            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "Back to main menu!" << endl;
                printTaskMenu();
                TaskMenu();
            }
        }

        //=================================================================================

        void TaskActions(){
            char input;
            printTaskActions();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && 
                   input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' && 
                   input != 'f' && input != 'F' && input != 'q' && input != 'Q') {
                cout << "Error: Unknown input. Please Select a valid option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a' || input == 'A') {              //INPUT A = RENAME TASK
                cout << "What would you like to rename your task to?";
                string rename;
                getline(cin, rename);
                setTaskTitle(rename);
                printTaskActions();
                TaskMenu();
            }

            else if (input == 'b' || input == 'B') {        //INPUT B = SET PRIORITY
            
            }

            else if (input == 'c' || input == 'C') {        //INPUT C = EDIT TASK DESCRIPTION
                string newDescription;
                getline(cin, newDescription);
                setTaskDescription(newDescription);
                printTaskActions();
                TaskMenu();
            }

            else if (input == 'd' || input == 'D') {        //INPUT D = SET TASK DUE DATE
                cout <<"Enter the day, month, and year of your task due date:" << endl;
                int day; 
                int month; 
                int year;
                cout << "Day:";
                cin >> day;

                while(isdigit(day)){
                    if(day > 32 || day < 1){
                        cout << "Error: Please enter a valid day.";
                        cin >> day;
                    }
                    else{
                        continue;
                    }
                }

                cout << "Month:";
                cin >> month;
                while(isdigit(month)){
                    if(month > 12 || month < 1){
                        cout << "Error: Please enter a valid month.";
                        cin >> day;
                    }
                    else{
                        continue;
                    }
                }
                cout << "Year";
                cin >> year;
                while(isdigit(year)){
                    if(year < 0){
                        cout << "Error: Please enter a valid year.";
                        cin >> year;
                    }
                    else{
                        continue;
                    }
                }
                setDueDate(day, month, year);
            }

            else if (input == 'e' || input == 'E') {        //INPUT E = DISPLAY CURRENT TASK
            
            }
            else if (input == 'f' || input == 'F') {        //INPUT F = EMBED ANOTHER TASK
            
            }
            else if (input == 'g' || input == 'G') {        //INPUT G = DELETE THIS TASK
            
            }


            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "Main menu!" << endl;
                printTaskMenu();
                TaskMenu();
            }
        }

        void printTaskMenu() {
            cout << "Welcome to the Task Menu. What would you like to do?" << endl;
            cout << "-------------------------------------" << endl
                 << "a - View all schedules and tasks" << endl
                 << "b - Create a Schedule" << endl
                 << "c - Create a Task" << endl
                 << "d - Edit a Schedule" << endl
                 << "e - Edit a Task" << endl
                 << "q - Exit Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
        }

        void printScheduleActions() {                                       //Schedule is essentially a folder in this case
            cout << "What would you like to do with this schedule?" << endl
                 << "-------------------------------------" << endl
                 << "a - Rename Schedule Title" << endl
                 << "b - Set priority" << endl
                 << "c - Set Description" << endl
                 << "d - Set Due Date" << endl
                 << "e - Set Classification" << endl
                 << "f - Display Current Schedule" << endl
                 << "g - Embed another Schedule" << endl
                 << "h - Delete this Schedule" << endl
                 << "q - Return to Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
        }

        void printTaskActions() {
            cout << "What would you like to do with this Task?" << endl
                 << "-------------------------------------" << endl
                 << "a - Rename Task Title" << endl
                 << "b - Set priority" << endl
                 << "c - Set Description" << endl
                 << "d - Set Due Date" << endl
                 << "e - Set Classification" << endl
                 << "f - Display Current Task" << endl
                 << "g - Embed another Schedule" << endl
                 << "h - Delete this Task" << endl
                 << "q - Return to Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
        }
        
        
        void TaskMenu() {
            char input;
            string userInput = "";
            printTaskMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && 
                   input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' && 
                   input != 'q' && input != 'Q') {
                cout << "Error: Unknown input. Please Select a valid option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a' || input == 'A') {             //INPUT A = VIEW SCHEDULE(S) DONE
                if ( tasks.empty() == true){
                    cout << "There are no Schedules." << endl;
                }

                else{
                    for(int l = 0; l < tasks.size(); l++) {
                        cout << l + 1 << ")" << endl;
                        tasks.at(l)->displayTask();
                        numberOfIndents = 1;
                        firstLayerDirectorySubtaskDisplayFlag = 0;
                    }
                }
            }

            else if (input == 'b' || input == 'B') {             //INPUT B = CREATE A SCHEDULE
                cout << "Type in a Schedule title followed by ENTER:" << endl;
                string title;
                getline(cin, title);
                setTaskTitle(title);

                cout << "Type in the new schedules priority followed by ENTER:" << endl;
                string priority;
                getline(cin, priority);
                setTaskPriority(priority);

                cout << "Type in the new schedules description followed by ENTER:" << endl;
                string description;
                getline(cin, description);
                setTaskDescription(description);

                cout << "Type in the new schedules due date followed by ENTER:" << endl;
                string dueDate;
                getline(cin, dueDate);
                setTaskDueDate(dueDate);

                cout << "Type in the new schedules task type followed by ENTER:" << endl;
                string taskType;
                getline(cin, taskType);
                setTaskDescription(taskType);

                saveTaskInformation();      //save the information
                printScheduleActions()      //prompt whats next with the new made schedule
            }

            else if (input == 'c' || input == 'C') {        //INPUT C = CREATE A TASK
                cout << "Type in a Task title followed by ENTER:" << endl;
                string title;
                getline(cin, title);
                setTaskTitle(title);

                cout << "Type in the new schedules priority followed by ENTER:" << endl;
                string priority;
                getline(cin, priority);
                setTaskPriority(priority);

                cout << "Type in the new schedules description followed by ENTER:" << endl;
                string description;
                getline(cin, description);
                setTaskDescription(description);

                cout << "Type in the new schedules due date followed by ENTER:" << endl;
                string dueDate;
                getline(cin, dueDate);
                setTaskDueDate(dueDate);

                cout << "Type in the new schedules task type followed by ENTER:" << endl;
                string taskType;
                getline(cin, taskType);
                setTaskDescription(taskType);

                saveTaskInformation();      //save the information
                printScheduleActions();      //prompt whats next with the new made task
                ScheduleActions();
            }

            else if (input == 'd' || input == 'D') {        //INPUT D = EDIT SCHEDULE
                if(tasks.empty() = true){
                    cout << "There are no schedules to edit." << endl;
                }

                else{
                    cout << "Which schedule would you like to edit? Please enter the corresponding number next to the Schedule";
                    for(int l = 0; l < tasks.size(); l++) {
                        cout << l + 1 << ")" << endl;
                        tasks.at(l)->displayTask();
                        numberOfIndents = 1;
                        firstLayerDirectorySubtaskDisplayFlag = 0;
                    }

                    int userInput;
                    cin >> userInput;
                    while(!(cin >> userInput) || userInput > tasks.size()) {
                        cout << "ERROR: Enter a valid number:" << endl;
                    }
                    cout << endl << tasks(userInput - 1) << " - ";      //subtract 1 to get the right cell inside vector
                    printScheduleActions() 
                    ScheduleActions();
                }

            else if (input == 'e' || input == 'E') {        //INPUT E = EDIT TASK

            }

            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "See you later!" << endl;
                exit;
            }
        }

    };

        //================================================================================
#endif