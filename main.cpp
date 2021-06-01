#include "SetupTaskFiles.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    SetupTaskFiles setup;

    //vector<Task*> theTasks = setup.getTaskList();
    setup.importTasks();
    setup.deleteTask("Test");

    return 0;
}