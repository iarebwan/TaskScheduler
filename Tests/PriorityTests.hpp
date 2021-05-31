#ifndef PRIORITY_TESTS_HPP
#define PRIORITY_TESTS_HPP
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
	task1->setTitle("Task 1");
	task1->setPriority("high");
    ListOfTasks.push_back(task1);

    EXPECT_EQ(test_printByPriority(ListOfTasks), "1. Title: Task 1, priority: high\n");
}

TEST(OrderByPriorityTest, NormalEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setPriority("medium");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setPriority("low");
    ListOfTasks.push_back(task2);

    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setPriority("high");
    ListOfTasks.push_back(task3);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 3, priority: high\n 
                                                 2. Title: Task 1, priority: medium\n
                                                 3. Title: Task 2, priority: low\n");
}

TEST(OrderByPriorityTest, OnePriorityEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setPriority("high");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 2, priority: high\n 
                                                 2. Title: Task 1\n");
}

TEST(OrderByPriorityTest, NoPriorityEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 1\n 
                                                 2. Title: Task 2\n");
}

TEST(OrderByPriorityTest, SamePriorityEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setPriority("high");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setPriority("high");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 1, priority: high\n 
                                                 2. Title: Task 2, priority: high\n";
}

TEST(OrderByPriorityTest, SamePriorityEntry2){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setPriority("low");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setPriority("low");
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setPriority("low");
    ListOfTasks.push_back(task3);

    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 1, priority: low\n 
                                                 2. Title: Task 2, priority: low\n
                                                 3. Title: Task 3, priority: low\n");
}

TEST(OrderByPriorityTest, LotsOfPriorities){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setPriority("low");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setPriority("medium");
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setPriority("high");
    ListOfTasks.push_back(task3);

    Task* task4 = new Task();
    task4->setTitle("Task 4");
    task4->setPriority("low");
    ListOfTasks.push_back(task4);

    Task* task5 = new Task();
    task5->setTitle("Task 5");
    task5->setPriority("medium");
    ListOfTasks.push_back(task5);

    Task* task6 = new Task();
    task6->setTitle("Task 6");
    task6->setPriority("high");
    ListOfTasks.push_back(task6);
    
    Task* task7 = new Task();
    task7->setTitle("Task 7");
    task7->setPriority("low");
    ListOfTasks.push_back(task7);

    Task* task8 = new Task();
    task8->setTitle("Task 8");
    task8->setPriority("medium");
    ListOfTasks.push_back(task8);

    Task* task9 = new Task();
    task9->setTitle("Task 9");
    task9->setPriority("medium");
    ListOfTasks.push_back(task9);

    EXPECT_EQ(test_printByPriority(ListOfTasks),"1. Title: Task 3, priority: high\n
                                                 2. Title: Task 6, priority: high\n
                                                 3. Title: Task 9, priority: high\n
                                                 4. Title: Task 2, priority: medium\n
                                                 5. Title: Task 5, priority: medium\n
                                                 6. Title: Task 8, priority: medium\n
                                                 7. Title: Task 1, priority: low\n
                                                 8. Title: Task 4, priority: low\n
                                                 9. Title: Task 7, priority: low\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif
