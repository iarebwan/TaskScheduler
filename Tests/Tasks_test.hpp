#ifndef __TASKS_HPP__
#define __TASKS_HPP__

#include "gtest/gtest.h"

#include "../Task.hpp"
#include "../SubtaskSchedule.hpp"
#include "../SubtaskSingularTask.hpp"
#include <vector>
#include <iostream>


TEST(DisplayTest, Display){
        vector<Task*> theTasks;
        Task* Task1 = new Task();
        Task1->setTaskTitle("Task 1");
        Task1->setTaskPriority("high");
        Task1->setTaskDescription("Task 1's description is great!");
        Task1->setTaskType("work");
	theTasks.push_back(Task1);
        EXPECT_EQ(theTask.at(0)->getTaskTitle(), "Task 1");
        EXPECT_EQ(theTask.at(0)->getTaskPriority(), "high");
        EXPECT_EQ(theTask.at(0)->getTaskDescription(), "Task 1's description is great!");
	EXPECT_EQ(theTask.at(0)->getTaskType(), "work");
}


#endif
