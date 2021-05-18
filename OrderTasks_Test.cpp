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
	task1->setTitle("Task 1");
	task1->setDescription("This is the description of task 1");
	task1->setPriority("high");
	task1->setDueDate(18, 5, 2021);
	task1->setClassification("academic");

	Task* task2 = new Task();
	task2->setTitle("Task 2");
	task2->setDescription("This is the description of task 2");
	task2->setPriority("low");
	task2->setDueDate(18, 4, 2021);
	task2->setClassification("personal");

	Task* task3 = new Task();
	task3->setTitle("Task 3");
	task3->setDescription("This is the description of task 3");
	task3->setPriority("medium");
	task3->setDueDate(10, 3, 2022);
	task3->setClassification("work");

	Task* task4 = new Task();
	task4->setTitle("Task 4");
	task4->setDescription("This is the description of task 4");
	task4->setPriority("high");
	task4->setDueDate(12, 1, 2023);
	task4->setClassification("work");

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
	OrderByDueDate* orderDueDate = new OrderByDueDate();
	printTasks(ListOfTasks, orderDueDate);
}

void test_printByPriority(vector<Task*>& ListOfTasks) {
	OrderByPriority* orderPriority = new OrderByPriority();
	printTasks(ListOfTasks, orderPriority);
}

void test_printByClassification(vector<Task*>& ListOfTasks, string classification) {
	OrderTasks* orderTaskType = new OrderByTaskType();
	printTasks(ListOfTasks, orderTaskType, classification);
}