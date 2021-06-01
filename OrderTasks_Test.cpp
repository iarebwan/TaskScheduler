#include <iostream>
#include <vector>

#include "OrderTasks.hpp"
#include "OrderByDueDate.hpp"
#include "OrderByPriority.hpp"
#include "OrderByTaskType.hpp"

using namespace std;

void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification);
void test_printByDueDate(vector<Task*>& ListOfTasks);
void test_printByPriority(vector<Task*>& ListOfTasks);
void test_printByClassification(vector<Task*>& ListOfTasks, string classification);

int main() {

	vector<Task*> ListOfTasks;

	Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
	task1->setTaskDescription("This is the description of task 1");
	task1->setTaskPriority("high");
	task1->setTaskDueDate("5/18/2021");
	//task1->setDueDateStruct(5, 18, 2021);
	task1->setTaskType("academic");

	Task* task2 = new Task();
	task2->setTaskTitle("Task 2");
	task2->setTaskDescription("This is the description of task 2");
	task2->setTaskPriority("low");
	task2->setTaskDueDate("4/18/2021");
	//task2->setDueDateStruct(4, 18, 2021);
	task2->setTaskType("personal");

	Task* task3 = new Task();
	task3->setTaskTitle("Task 3");
	task3->setTaskDescription("This is the description of task 3");
	task3->setTaskPriority("medium");
	task3->setTaskDueDate("3/10/2022");
	//task3->setDueDateStruct(3, 10, 2022);
	task3->setTaskType("work");

	Task* task4 = new Task();
	task4->setTaskTitle("Task 4");
	task4->setTaskDescription("This is the description of task 4");
	task4->setTaskPriority("high");
	task4->setTaskDueDate("1/12/2023");
	//task4->setDueDateStruct(1, 12, 2023);
	task4->setTaskType("work");

	ListOfTasks.push_back(task1);
	ListOfTasks.push_back(task2);
	ListOfTasks.push_back(task3);
	ListOfTasks.push_back(task4);

	cout << "Order by Priority:" << endl;
	test_printByPriority(ListOfTasks);
	cout << endl;

	cout << "Order by due date:" << endl;
	test_printByDueDate(ListOfTasks);
	cout << endl;

	cout << "Order by Classification - work" << endl;
	test_printByClassification(ListOfTasks, "work");
	cout << endl;
}

void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification = "") {
	orderType->display(ListOfTasks, classification);
}

void test_printByDueDate(vector<Task*>& ListOfTasks) {
	OrderTasks* orderDueDate = new OrderByDueDate();
	printTasks(ListOfTasks, orderDueDate);
}

void test_printByPriority(vector<Task*>& ListOfTasks) {
	OrderTasks* orderPriority = new OrderByPriority();
	printTasks(ListOfTasks, orderPriority);
}

void test_printByClassification(vector<Task*>& ListOfTasks, string classification) {
	OrderTasks* orderTaskType = new OrderByTaskType();
	printTasks(ListOfTasks, orderTaskType, classification);
}