//CS100 FINAL PROJECT
#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>

using namespace std;

class Menu {
    private:
        Schedule* currSched;
        Task* currTask;
        bool verifyList();
        bool verifyTask;
        void importTasksFromDatabase();

    public:
        Menu(Schedule* currSched) {
            this->currSched = currSched;
        }

        Menu(Schedule* currTask) {
            this->currTask = currTask;
        }

            void runTaskScheduler() {
            while (currSched->getTypeAction() == "Tasks") {
                TaskMenu();
            }

            while (currTask->getTypeAction() == "Task actions") {
                TaskActions();
            }

            while (currSched->getTypeAction() == "Schedule actions"){
                ScheduleActions();
            }
        }

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
                printScheduleActions();
                ScheduleActions();
            }

            else if (input == 'b' || input == 'B') {        //INPUT B = SET SCHEDULE PRIORITY
            
            }

            else if (input == 'c' || input == 'C') {        //INPUT A = EDIT SCHEDULE DESCRIPTION
                string newDescription;
                getline(cin, newDescription);
                setTaskDescription(newDescription);
                printScheduleActions();
                ScheduleActions();
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

            if (input == 'a' || input == 'A') {        //INPUT A = RENAME TASK
                cout << "What would you like to rename your task to?";
                string rename;
                getline(cin, rename);
                setTaskTitle(rename);
                printTaskActions();
                TaskMenu();
            }

            else if (input == 'b' || input == 'B') {        //INPUT B = SET PRIORITY
            
            }

            else if (input == 'c' || input == 'C') {        //INPUT A = EDIT TASK DESCRIPTION
                string newDescription;
                getline(cin, newDescription);
                setTaskDescription(newDescription);
                printTaskActions();
                TaskMenu();
            }


            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "Main menu!" << endl;
                printTaskMenu();
                TaskMenu();
            }
        }

        void printTaskMenu() {
            cout << currSched->getName() << endl;
            cout << "-------------------------------------" << endl
                 << "a - View Schedules" << endl
                 << "b - View Tasks" << endl
                 << "c - Create a Schedule" << endl
                 << "d - Create a Task" << endl
                 << "e - Delete a Schedule" << endl
                 << "f - Delete a Task" << endl
                 << "g - Edit a Schedule" << endl
                 << "h - Edit a Task" << endl
                 << "q - Exit Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
        }

        void printScheduleActions() {                                       //Schedule is essentially a folder in this case
            cout << endl << currSched->getName() << " - ";
            cout << "What would you like to do with this schedule?" << endl
                 << "-------------------------------------" << endl
                 << "a - Rename Schedule Title" << endl
                 << "b - Set priority" << endl
                 << "c - Set Description" << endl
                 << "d - Set Due Date" << endl
                 << "e - Display Current Schedule" << endl
                 << "f - Embed another Schedule" << endl
                 << "g - Delete this Schedule" << endl
                 << "q - Return to Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
        }

        void printTaskActions() {
            cout << endl << currSched->getName() << " - ";
            cout << "What would you like to do with this Task?" << endl
                 << "-------------------------------------" << endl
                 << "a - Rename Task Title" << endl
                 << "b - Set priority" << endl
                 << "c - Set Description" << endl
                 << "d - Set Due Date" << endl
                 << "e - Display Current Task" << endl
                 << "f - Embed another Schedule" << endl
                 << "g - Delete this Task" << endl
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
                   input != 'f' && input != 'F' && input != 'q' && input != 'Q') {
                cout << "Error: Unknown input. Please Select a valid option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a' || input == 'A') {             //INPUT A = VIEW SCHEDULE(S) DONE
                if (currSched->getSize() == 0){
                    cout << "There are no Schedules." << endl;
                }

                else{
                    cout << "Schedule list:" << endl;
                    currSched->print();                     //CREATE PRINT FUNCTION
                }
            }

            else if (input == 'b' || input == 'B') {             //INPUT B = VIEW TASK(S) DONE
                if (currTask->getSize() == 0){
                    cout << "There are no Task." << endl;
                }

                else{
                    cout << "Task list:" << endl;
                    currTask->print();                     //CREATE PRINT FUNCTION
                }
            }

            else if (input == 'c' || input == 'C') {        //INPUT C = CREATE A SCHEDULE
                string ScheduleName;
                cout << "Enter your new Schedule: ";
                getline(cin, ScheduleName);
                cout << endl;
                //IMPLEMENT POINTER TO CHILD HERE (we need a function)
                printScheduleActions();
                ScheduleActions();
            }

            else if (input == 'd' || input == 'D') {        //INPUT C = CREATE A TASK
                string TaskName;
                cout << "Enter your new Task: ";
                getline(cin, TaskName);
                cout << endl;
                //IMPLEMENT POINTER TO CHILD HERE (we need a function)
                printTaskActions();
                TaskActions();
            }

            else if (input == 'e' || input == 'E') {        //INPUT D = DELETE A SCHEDULE
                if (currSched->getSize() == 0) {
                    cout << "There are no schedules." << endl;
                }
                else{
                    cout << "Here is your schedule(s) list: " << endl;
                    currSched->print();
                    cout << endl << "Enter which schedule(s) you want to remove: ";
                    cin >> //SOMETHING, CHECK IT, AND DELETE IT;
                    cout << endl;
                    printScheduleActions();
                    ScheduleActions();
                }
            }
            
            else if (input == 'f' || input == 'F') {        //INPUT E = DELETE A TASK
                if (currTask->getSize() == 0) {
                    cout << "There are no task(s)." << endl;
                }
                else{
                    cout << "Here is your task(s) list: " << endl;
                    currTask->print();
                    cout << endl << "Enter which task(s) you want to remove: ";
                    cin >> //SOMETHING, CHECK IT, AND DELETE IT;
                    cout << endl;
                    printTaskActions();
                    TaskActions();
                }

            }

            else if (input == 'g' || input == 'G') {        //INPUT F = EDIT A SCHEDULE
                if(currSched->getSize() = 0){
                    cout << "There are no schedules to edit." << endl;
                }
                else{
                    cout << "Which schedule would you like to edit?";
                    cin >> userInput;
                    if(currSched->getTaskName == userInput){
                        printScheduleActions();
                        ScheduleActions();
                    }
                }
            }

            else if (input == 'g' || input == 'G') {        //INPUT F = EDIT A TASK
                if(currTask->getSize() = 0){
                    cout << "There are no tasks to edit." << endl;
                }
                else{
                    cout << "Which task would you like to edit?";
                    cin >> userInput;
                    if(currTask->getTaskName == userInput){
                        printTaskActions();
                        TaskActions();
                    }
                }
            }

            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "See you later!" << endl;
                exit;
            }
        }

    };

        //================================================================================
