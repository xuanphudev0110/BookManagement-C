#include "Date.h"


Date::Date(void)
{
}
Date::~Date()
{

}
// setters
void Date::setDayMonYear(int day,int mon,int year)
{
	this->day = day;
	this->mon = mon;
	this->year = year;
}
// getters
int Date::getDay()
{
	return day;
}
int Date::getMon()
{
	return mon;
}
int Date::getYear()
{
	return year;
}
// ham in ngay thang nam
void Date::print()
{
	cout << this->day << "/" << this->mon<<"/" << this->year << endl;
}