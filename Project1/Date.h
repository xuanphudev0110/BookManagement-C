#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <ctime>

using namespace std;

class Date
{
private:
	int day;
	int mon;
	int year;
public:
	Date(void);
	~Date();
	// setters
	void setDayMonYear(int day,int mon,int year);
	// getters
	int getDay();
	int getMon();
	int getYear();
	// ham in ngay thang nam
	void print();
};

