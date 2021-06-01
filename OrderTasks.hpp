#ifndef __ORDERTASKS_HPP__
#define __ORDERTASKS_HPP__

#include <string>
#include <iostream>
//#include "Task_MockTestforStrategyPattern.hpp"

using namespace std;

class OrderTasks {
private:
	//string type;

public:
	virtual void display(vector<Task*>& listOfTasks, string type = "") = 0;
};


#endif