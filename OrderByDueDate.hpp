#ifndef __ORDERBYDUEDATE_HPP__
#define __ORDERBYDUEDATE_HPP__

#include <vector>
#include <iostream>

#include "OrderTasks.hpp"

using namespace std;

//Reference1 for comparing dates: https://www.geeksforgeeks.org/how-to-sort-an-array-of-dates-in-cc/
//Reference2 for refreshing on insertion sort: https://www.geeksforgeeks.org/insertion-sort/

class OrderByDueDate : public OrderTasks {
private:
	//used reference1 here to learn how to compare dates
	//returns true if tasks need to be swapped which is when date1 is greater than date2
	bool compare_isTrue(const Date& date1, const Date& date2) {
		if (date1.year > date2.year) {
			return true;
		}
		if ((date1.year == date2.year) && (date1.month > date2.month)) {
			return true;
		}
		if ((date1.year == date2.year) && (date1.month == date2.month) && (date1.day > date2.day)) {
			return true;
		}

		return false;
	}

public:
	virtual void display(vector<Task*>& listOfTasks, string type = "") {
		//sort the pointers in listOfTasks by nearest to farthest due date		
		//used reference2 here for refreshing on using insertion sort
		int j;
		for (int i = 1; i < listOfTasks.size(); i++) {
			Task* currentTask = listOfTasks.at(i);
			j = i - 1;
			while (j >= 0 && compare_isTrue(listOfTasks.at(j)->getDueDate(), currentTask->getDueDate())) {
				listOfTasks.at(j + 1) = listOfTasks.at(j);
				j = j - 1;
			}
			listOfTasks.at(j + 1) = currentTask;
		}


		//display the title and due date of each task by iterating through the vector
		//number each task as you display them (1., 2., 3., ...)
		for (int i = 0; i < listOfTasks.size(); i++) {
			cout << i + 1 << ". Title: " << listOfTasks.at(i)->getTitle() << ", Due date: ";
			listOfTasks.at(i)->displayDueDate();
			cout << endl;
		}


	}

};

#endif