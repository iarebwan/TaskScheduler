#ifndef __Task_MockTestforStrategyPattern_HPP__
#define __Task_MockTestforStrategyPattern_HPP__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//struct Date {
//	int day = 0;
//	int month = 0;
//	int year = 0;
//};

class Task {
private:
	string title;
	string priority; //"high", "medium", or "low"
	string description;
	//Date dueDateStruct;
	string dueDate;
	string classification; //"work", "personal", or "academic"

public:
	void setTaskTitle(string title_) {
		/*this->*/title = title_;
	}

	string getTaskTitle() {
		return /*this->*/title;
	}

	void setTaskDescription(string description_) {
		/*this->*/description = description_;
	}

	string getTaskDescription() {
		return /*this->*/description;
	}

	void setTaskPriority(string priority_) {
		if (priority_ == "high") {
			/*this->*/priority = "high";
		}
		if (priority_ == "medium") {
			/*this->*/priority = "medium";
		}
		if (priority_ == "low") {
			/*this->*/priority = "low";
		}
	}

	string getTaskPriority() {
		return /*this->*/priority;
	}

	/*void setDueDateStruct(int month_, int day_, int year_) {
		this->dueDateStruct.month = month_;
		this->dueDateStruct.day = day_;
		this->dueDateStruct.year = year_;
	}

	Date getDueDateStruct() {
		return this->dueDateStruct;
	}*/

	void setTaskDueDate(string date) {
		/*this->*/dueDate = date;
	}

	string getTaskDueDate() {
		return /*this->*/dueDate;
	}

	void displayDueDate() {
		//cout << this->dueDateStruct.month << "/" << this->dueDateStruct.day  << "/" << this->dueDateStruct.year;
		cout << /*this->*/dueDate;
	}

	void setTaskType(string taskType) {
		if (taskType == "work") {
			/*this->*/classification = "work";
		}
		if (taskType == "personal") {
			/*this->*/classification = "personal";
		}
		if (taskType == "academic") {
			/*this->*/classification = "academic";
		}
	}

	string getTaskType() {
		return /*this->*/classification;
	}

};

#endif