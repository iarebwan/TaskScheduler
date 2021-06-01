#ifndef __PRIORITY_TESTS_HPP__
#define __PRIORITY_TESTS_HPP__
#include "../OrderTasks.hpp"
#include "../OrderByPriority.hpp"
#include <vector>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification = "") {
	orderType->display(ListOfTasks, classification);
}

void test_printByPriority(vector<Task*>& ListOfTasks) {
	OrderByPriority* orderPriority = new OrderByPriority();
	printTasks(ListOfTasks, orderPriority);
}

TEST(OrderByPriorityTest, OneTask){
    vector<Task*> ListOfTasks;
    
    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
	task1->setTaskPriority("high");
    ListOfTasks.push_back(task1);

    EXPECT_EQ(test_printByPriority(ListOfTasks), "1. Title: Task 1, priority: high\n");
}

TEST(OrderByPriorityTest, NormalEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
	task1->setTaskPriority("medium");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTaskTitle("Task 2");
    task2->setTaskPriority("low");
    ListOfTasks.push_back(task2);

    Task* task3 = new Task();
    task3->setTaskTitle("Task 3");
    task3->setTaskPriority("high");
    ListOfTasks.push_back(task3);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 3, priority: high\n2. Title: Task 1, priority: medium\n3. Title: Task 2, priority: low\n");
}

TEST(OrderByPriorityTest, OnePriorityEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTaskTitle("Task 2");
    task2->setTaskPriority("high");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 2, priority: high\n2. Title: Task 1\n");
}

TEST(OrderByPriorityTest, NoPriorityEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTaskTitle("Task 2");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 1\n2. Title: Task 2\n");
}

TEST(OrderByPriorityTest, SamePriorityEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
	task1->setTaskPriority("high");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTaskTitle("Task 2");
    task2->setTaskPriority("high");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 1, priority: high\n2. Title: Task 2, priority: high\n";
}

TEST(OrderByPriorityTest, SamePriorityEntry2){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
	task1->setTaskPriority("low");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTaskTitle("Task 2");
    task2->setTaskPriority("low");
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTaskTitle("Task 3");
    task3->setTaskPriority("low");
    ListOfTasks.push_back(task3);

    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 1, priority: low\n2. Title: Task 2, priority: low\n3. Title: Task 3, priority: low\n");
}

TEST(OrderByPriorityTest, LotsOfPriorities){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
	task1->setTaskPriority("low");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTaskTitle("Task 2");
    task2->setTaskPriority("medium");
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTaskTitle("Task 3");
    task3->setTaskPriority("high");
    ListOfTasks.push_back(task3);

    Task* task4 = new Task();
    task4->setTaskTitle("Task 4");
    task4->setTaskPriority("low");
    ListOfTasks.push_back(task4);

    Task* task5 = new Task();
    task5->setTaskTitle("Task 5");
    task5->setTaskPriority("medium");
    ListOfTasks.push_back(task5);

    Task* task6 = new Task();
    task6->setTaskTitle("Task 6");
    task6->setTaskPriority("high");
    ListOfTasks.push_back(task6);
    
    Task* task7 = new Task();
    task7->setTaskTitle("Task 7");
    task7->setTaskPriority("low");
    ListOfTasks.push_back(task7);

    Task* task8 = new Task();
    task8->setTaskTitle("Task 8");
    task8->setTaskPriority("medium");
    ListOfTasks.push_back(task8);

    Task* task9 = new Task();
    task9->setTaskTitle("Task 9");
    task9->setTaskPriority("medium");
    ListOfTasks.push_back(task9);

    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 3, priority: high\n2. Title: Task 6, priority: high\n3. Title: Task 9, priority: high\n4. Title: Task 2, priority: medium\n5. Title: Task 5, priority: medium\n6. Title: Task 8, priority: medium\n7. Title: Task 1, priority: low\n8. Title: Task 4, priority: low\n9. Title: Task 7, priority: low\n");
}

//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}

#endif