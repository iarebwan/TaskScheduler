#ifndef __ORDERBYDUEDATE_HPP__
#define __ORDERBYDUEDATE_HPP__

#include <vector>
#include <iostream>
#include <string>

#include "OrderTasks.hpp"
#include "Task.hpp"

using namespace std;

//Reference1 for comparing dates: https://www.geeksforgeeks.org/how-to-sort-an-array-of-dates-in-cc/
//Reference2 for refreshing on insertion sort: https://www.geeksforgeeks.org/insertion-sort/

class OrderByDueDate : public OrderTasks {
private:
	//used reference1 here to learn how to compare dates
	//returns true if tasks need to be swapped which is when date1 is greater than date2
	/*bool compare_isTrue(const Date& date1, const Date& date2) {
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
	}*/

	//used reference1 here to learn how to compare dates
	//returns true if tasks need to be swapped which is when date1 is greater than date2
	bool compare_isTrue(const string& date1, const string& date2) {
		
		string month1_str;
		string day1_str;
		string year1_str;
		int dateCount1 = 1;

		//parse date1 string and put month, day, and year part of it into their respective strings
		for (int i = 0; i < date1.length(); i++) {
			if (date1.at(i) != '/' && dateCount1 == 1 /*looks at month part of string*/) {
				month1_str.push_back(date1.at(i));
			}
			else if (dateCount1 == 1) {
				dateCount1++;
				i++;
			}

			if (date1.at(i) != '/' && dateCount1 == 2 /*looks at day part of string*/) {
				day1_str.push_back(date1.at(i));
			}
			else if (dateCount1 == 2) {
				dateCount1++;
				i++;
			}

			if (dateCount1 == 3 /*looks at year part of string*/) {
				year1_str.push_back(date1.at(i));
			}

		}

		//cout << "Debug statement: string (month1_str, day1_str, year1_str) = " << month1_str << ", " << day1_str << ", " << year1_str << endl;

		//convert the month1, day1, and year1 strings into integers.
		int date1_month = stoi(month1_str);
		int date1_day = stoi(day1_str);
		int date1_year = stoi(year1_str);

		//cout << "Debug statement: int (date1_month, date1_day, date1_year) = " << date1_month << ", " << date1_day << ", " << date1_year << endl;

		//---------------------------------------------
		string month2_str;
		string day2_str;
		string year2_str;
		int dateCount2 = 1;

		//parse date2 string and put month, day, and year part of it into their respective strings
		for (int i = 0; i < date2.length(); i++) {
			if (date2.at(i) != '/' && dateCount2 == 1 /*looks at month part of string*/) {
				month2_str.push_back(date2.at(i));
			}
			else if (dateCount2 == 1) {
				dateCount2++;
				i++;
			}

			if (date2.at(i) != '/' && dateCount2 == 2 /*looks at day part of string*/) {
				day2_str.push_back(date2.at(i));
			}
			else if (dateCount2 == 2) {
				dateCount2++;
				i++;
			}

			if (dateCount2 == 3 /*looks at year part of string*/) {
				year2_str.push_back(date2.at(i));
			}

		}

		//cout << "Debug statement: string (month2_str, day2_str, year2_str) = " << month2_str << ", " << day2_str << ", " << year2_str << endl;

		//convert the month1, day1, and year1 strings into integers.
		int date2_month = stoi(month2_str);
		int date2_day = stoi(day2_str);
		int date2_year = stoi(year2_str);

		//cout << "Debug statement: int (date2_month, date2_day, date2_year) = " << date2_month << ", " << date2_day << ", " << date2_year << endl;

		
		if (date1_year > date2_year) {
			return true;
		}
		if ((date1_year == date2_year) && (date1_month > date2_month)) {
			return true;
		}
		if ((date1_year == date2_year) && (date1_month == date2_month) && (date1_day > date2_day)) {
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
			while (j >= 0 && compare_isTrue(listOfTasks.at(j)->getTaskDueDate(), currentTask->getTaskDueDate())) {
				listOfTasks.at(j + 1) = listOfTasks.at(j);
				j = j - 1;
			}
			listOfTasks.at(j + 1) = currentTask;
		}


		//display the title and due date of each task by iterating through the vector
		//number each task as you display them (1., 2., 3., ...)
		for (int i = 0; i < listOfTasks.size(); i++) {
			cout << i + 1 << ". Title: " << listOfTasks.at(i)->getTaskTitle() << ", Due date: ";
			listOfTasks.at(i)->getTaskDueDate();
			cout << endl;
		}


	}

};

#endif