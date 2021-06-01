#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "Task.hpp"

TEST(DisplayTest, Display){
	vector<Task*> theTasks
	Task* Task1 = new Task();
	theTasks.at(0)->setTaskTitle("Task 1");
	theTasks.at(0)->setTaskPriority("high");
	theTasks.at(0)->setTaskDescription("Task 1's description is great!");
	theTasks.at(0)->setTaskType("work");
	EXPECT_EQ(theTask.at(0)->getTaskTitle, "Task 1");
}

TEST(taskTest, nameTest){ 
  Task* task1 = new Task();
  task1->setTaskName("Go to grocery store");
  
  EXPECT_EQ(task1->getTaskName(), "Go to grocery store");
}

TEST(taskTest, duedateTest){ 
  Task* task1 = new Task();
  task1->setDueDate("5/22/2021");
  
  EXPECT_EQ(task1->getDueDate(), "5/22/2021");
}

TEST(taskTest, PriorityTest){ 
  Task* task1 = new Task();
  task1->setTaskPriority("high");
  
  EXPECT_EQ(task1->getTaskPriority(), "high");
}

TEST(taskTest, descriptionTest){ 
  Task* task1 = new Task();
  task1->setTaskDescription("Task 1 is great!");
  
  EXPECT_EQ(task1->getTaskDueDate(), "Tasl 1 os great!");
}

TEST(taskTest, duedateTest){ 
  Task* task1 = new Task();
  task1->setTaskType("work");
  
  EXPECT_EQ(task1->getTaskType(), "work");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};
