#ifndef DUE_DATE_TESTS_HPP
#define DUE_DATE_TESTS_HPP
#include "OrderTasks.hpp"
#include "OrderByDueDate.hpp"
#include <vector>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification);

void test_printByDueDate(vector<Task*>& ListOfTasks) {  //copied from OrderTasks_Test.cpp
	OrderByDueDate* orderDueDate = new OrderByDueDate();
	printTasks(ListOfTasks, orderDueDate);
}

TEST(OrderByDueDateTest, NormalEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setDueDate(4, 18, 2021);
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 2 Due date: 4/18/2021\n 
                                                 2. Title: Task 1 Due date: 5/18/2021\n");
}

TEST(OrderByDueDateTest, NoDateEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setDueDate(4, 18, 2021);
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 2 Due date: 4/18/2021\n 
                                                 2. Title: Task 1\n");
}

TEST(OrderByDueDateTest, NoDateEntry2){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 1\n 
                                                 2. Title: Task 2\n");
}