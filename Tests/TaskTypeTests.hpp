#ifndef PRIORITY_TESTS_HPP
#define PRIORITY_TESTS_HPP
#include "../OrderTasks.hpp"
#include "../OrderByTaskType.hpp"
#include <vector>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification = "") {
	orderType->display(ListOfTasks, classification);
}

void test_printByClassification(vector<Task*>& ListOfTasks, string classification) {
	OrderTasks* orderTaskType = new OrderByTaskType();
	printTasks(ListOfTasks, orderTaskType, classification);
}

TEST(OrderByTaskTypeTest, OneTask){
    vector<Task*> ListOfTasks;
    
    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setClassification("work");
    ListOfTasks.push_back(task1);

    EXPECT_EQ(test_printByClassification(ListOfTasks, "work"), "1. Title: Task 1, TaskType(classification): work\n");
}

TEST(OrderByTaskTypeTest, WorkTest){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setClassification("academic");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("personal");
    ListOfTasks.push_back(task2);

    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setClassification("work");
    ListOfTasks.push_back(task3);
    
    EXPECT_EQ(test_printByClassification(ListOfTasks, "work"), "1. Title: Task 3, TaskType(classification): work\n 
                                                                2. Title: Task 1, TaskType(classification): academic\n
                                                                3. Title: Task 2, TaskType(classification): personal\n");
}

TEST(OrderByTaskTypeTest, PersonalTest){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setClassification("academic");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("personal");
    ListOfTasks.push_back(task2);

    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setClassification("work");
    ListOfTasks.push_back(task3);
    
    EXPECT_EQ(test_printByClassification(ListOfTasks, "personal"), "1. Title: Task 2, TaskType(classification): personal\n 
                                                                    2. Title: Task 1, TaskType(classification): academic\n
                                                                    3. Title: Task 3, TaskType(classification): work\n");
}

TEST(OrderByTaskTypeTest, academicTest){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setClassification("personal");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("academic");
    ListOfTasks.push_back(task2);

    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setClassification("work");
    ListOfTasks.push_back(task3);
    
    EXPECT_EQ(test_printByClassification(ListOfTasks, "personal"), "1. Title: Task 2, TaskType(classification): academic\n 
                                                                    2. Title: Task 1, TaskType(classification): personal\n
                                                                    3. Title: Task 3, TaskType(classification): work\n");
}

TEST(OrderByTaskTypeTest, OneTaskTypeEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("work");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByClassification(ListOfTasks, "work"), "1. Title: Task 2, TaskType(classification): work\n 
                                                                2. Title: Task 1\n");
}

TEST(OrderByTaskTypeTest, NoTaskTypeEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByClassification(ListOfTasks, ""), "1. Title: Task 1\n 
                                                            2. Title: Task 2\n");
}

TEST(OrderByTaskTypeTest, NoTaskTypeEntry2){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("work");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByClassification(ListOfTasks, ""), "1. Title: Task 1\n 
                                                            2. Title: Task 2, TaskType(classification): work\n");
}

TEST(OrderByTaskTypeTest, SameTaskTypeEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setClassification("personal");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("personal");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByClassification(ListOfTasks, "personal"), "1. Title: Task 1, TaskType(classification): personal\n 
                                                                    2. Title: Task 2, TaskType(classification): personal\n";
}

TEST(OrderByTaskTypeTest, SameTaskTypeEntry2){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setClassification("work");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("work");
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setClassification("work");
    ListOfTasks.push_back(task3);

    EXPECT_EQ(test_printByClassification(ListOfTasks, "work"), "1. Title: Task 1, TaskType(classification): work\n 
                                                                2. Title: Task 2, TaskType(classification): work\n
                                                                3. Title: Task 3, TaskType(classification): work\n");
}

TEST(OrderByTaskTypeTest, LotsOfPriorities){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setPriority("work");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setClassification("personal");
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setClassification("academic");
    ListOfTasks.push_back(task3);

    Task* task4 = new Task();
    task4->setTitle("Task 4");
    task4->setPriority("work");
    ListOfTasks.push_back(task4);

    Task* task5 = new Task();
    task5->setTitle("Task 5");
    task5->setPriority("personal");
    ListOfTasks.push_back(task5);

    Task* task6 = new Task();
    task6->setTitle("Task 6");
    task6->setPriority("academic");
    ListOfTasks.push_back(task6);
    
    Task* task7 = new Task();
    task7->setTitle("Task 7");
    task7->setPriority("work");
    ListOfTasks.push_back(task7);

    Task* task8 = new Task();
    task8->setTitle("Task 8");
    task8->setPriority("personal");
    ListOfTasks.push_back(task8);

    Task* task9 = new Task();
    task9->setTitle("Task 9");
    task9->setPriority("academic");
    ListOfTasks.push_back(task9);

    EXPECT_EQ(test_printByClassification(ListOfTasks, "work"), "1. Title: Task 1, TaskType(classification): work\n
                                                                2. Title: Task 4, TaskType(classification): work\n
                                                                3. Title: Task 7, TaskType(classification): work\n
                                                                4. Title: Task 2, TaskType(classification): personal\n
                                                                5. Title: Task 3, TaskType(classification): academic\n
                                                                6. Title: Task 5, TaskType(classification): personal\n
                                                                7. Title: Task 6, TaskType(classification): academic\n
                                                                8. Title: Task 8, TaskType(classification): personal\n
                                                                9. Title: Task 9, TaskType(classification): academic\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif
