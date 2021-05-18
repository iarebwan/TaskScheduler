#ifndef __ORDERBYPRIORITY_HPP__
#define __ORDERBYPRIORITY_HPP__

#include <vector>
#include <iostream>

#include "OrderTasks.hpp"

using namespace std;

class OrderByPriority : public OrderTasks {
private:
	//returns true if tasks need to be swapped which is when priority1 is less than priority2
	bool comparePriority_isTrue(string priority1, string priority2) {
		if (priority1 == "low" && (priority2 == "medium" || priority2 == "high")) {
			return true;
		}
		if (priority1 == "medium" && priority2 == "high") {
			return true;
		}
		return false;
	}

public:
	virtual void display(vector<Task*>& listOfTasks, string type = "") {
		//sort listOfTasks by high priority, medium priority, then low priority.
		//used reference2 here for refreshing on using insertion sort
		int j;
		for (int i = 1; i < listOfTasks.size(); i++) {
			j = i - 1;
			Task* currentTask = listOfTasks.at(i);
			while (j >= 0 && comparePriority_isTrue(listOfTasks.at(j)->getPriority(), currentTask->getPriority())) {
				listOfTasks.at(j + 1) = listOfTasks.at(j);
				j = j - 1;
			}
			listOfTasks.at(j + 1) = currentTask;
		}

		//display the title and priority of each task by iterating through the vector
		//number each task as you display them (1., 2., 3., ...)
		for (int i = 0; i < listOfTasks.size(); i++) {
			cout << i + 1 << ". Title: " << listOfTasks.at(i)->getTitle() << ", priority: " << listOfTasks.at(i)->getPriority() << endl;
		}

	}
};

#endif