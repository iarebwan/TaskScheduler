#include "TaskMenu.hpp"

int main() {
    SetupTaskFiles setup;
    vector<Task*> theTasks;

    theTasks = setup.importTasks();
    Menu *menu = new Menu(theTasks);
    menu->printTaskMenu();
    menu->TaskMenu();

    return 0;
}