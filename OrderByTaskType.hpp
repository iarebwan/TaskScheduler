#ifndef __ORDERBYTASKTYPE_HPP__
#define __ORDERBYTASKTYPE_HPP__

#include <vector>
#include <iostream>
#include <string>

#include "OrderTasks.hpp"

using namespace std;

class OrderByTaskType : public OrderTasks {
private:
	//returns true if tasks need to be swapped which is when classification2 is of the specified taskType and classification1 is not.
	bool compareTaskType_isTrue(string classification1, string classification2, string taskType) {
		if ((classification2 == taskType) && (classification1 != taskType)) {
			return true;
		}
		return false;
	}

public:

	virtual void display(vector<Task*>& listOfTasks, string taskType = "") {
		//sort the pointers in listOfTasks by having the specified taskType on the top
		//used reference2 here for refreshing on using insertion sort
		int j;
		for (int i = 1; i < listOfTasks.size(); i++) {
			j = i - 1;
			Task* currentTask = listOfTasks.at(i);
			while (j >= 0 && compareTaskType_isTrue(listOfTasks.at(j)->getTaskType(), currentTask->getTaskType(), taskType)) {
				listOfTasks.at(j + 1) = listOfTasks.at(j);
				j = j - 1;
			}
			listOfTasks.at(j + 1) = currentTask;
		}

		//display the title and priority of each task by iterating through the vector
		//number each task as you display them (1., 2., 3., ...)
		for (int i = 0; i < listOfTasks.size(); i++) {
			cout << i + 1 << ". Title: " << listOfTasks.at(i)->getTaskTitle() << ", TaskType(classification): " << listOfTasks.at(i)->getTaskType() << endl;
		}
        cout << endl;
	}
};

#endif