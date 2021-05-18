#ifndef __Task_MockTestforStrategyPattern_HPP__
#define __Task_MockTestforStrategyPattern_HPP__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
};

class Task {
private:
	string title;
	string description;
	string priority; //"high", "medium", or "low"
	Date dueDate;
	string classification; //"work", "personal", or "academic"

public:
	void setTitle(string title_) {
		this->title = title_;
	}

	string getTitle() {
		return this->title;
	}

	void setDescription(string description_) {
		this->description = description_;
	}

	string getDescription() {
		return this->description;
	}

	void setPriority(string priority_) {
		if (priority_ == "high") {
			this->priority = "high";
		}
		if (priority_ == "medium") {
			this->priority = "medium";
		}
		if (priority_ == "low") {
			this->priority = "low";
		}
	}

	string getPriority() {
		return this->priority;
	}

	void setDueDate(int day_, int month_, int year_) {
		this->dueDate.day = day_;
		this->dueDate.month = month_;
		this->dueDate.year = year_;
	}

	Date getDueDate() {
		return this->dueDate;
	}

	void displayDueDate() {
		cout << this->dueDate.day << "/" << this->dueDate.month << "/" << this->dueDate.year;
	}

	void setClassification(string taskType) {
		if (taskType == "work") {
			this->classification = "work";
		}
		if (taskType == "personal") {
			this->classification = "personal";
		}
		if (taskType == "academic") {
			this->classification = "academic";
		}
	}

	string getClassification() {
		return this->classification;
	}

};

#endif