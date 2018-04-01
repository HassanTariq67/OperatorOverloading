#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int hours;
	int mins;
	int secs;
	int days;
public:
	void setHours(int);
	void setDays(int);
	void setMins(int);
	void setSecs(int);
	int getHours();
	int getMins();
	int getDays();
	int getSecs();
	void validateTime(int days, int hours, int mins, int secs);
	friend ostream &operator << (ostream&out,  Time&t);
	friend istream &operator >> (istream&, Time&);
	Time operator + (Time&);
	Time operator - (Time&);
	Time operator * ();
	bool operator < (const Time&);
	bool operator > (const Time&);
	bool operator == (const Time&);
	bool operator != (const Time&);
	Time operator ++ ();
	Time operator ++ (int);
	Time operator -- ();
	Time operator -- (int);
	Time(int, int, int, int);
	Time(int);
	Time();
	~Time();
};

