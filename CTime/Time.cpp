#include "Time.h"



Time::Time(int days, int hours, int mins, int secs)
{
	validateTime(days, hours, mins, secs);
}

Time::Time(int secs)
{
	setDays(0);
	setHours(0);
	setMins(0);
	setSecs(0);
	if (secs>0)
	{
		if (secs > 86400)
		{
			secs -= ((this->days = secs / 86400) * 86400);
			if (secs > 3600)
			{
				secs -= ((this->hours = secs / 3600) * 3600);
				if (secs>60)
				{
					secs -= ((this->mins = secs / 60) * 60);
					this->secs = secs;
				}
				else
				{
					this->secs = secs;
				}
			}
			else if (secs>60)
			{
				secs -= ((this->mins = secs / 60) * 60);
				this->secs = secs;
			}
			else
			{
				this->secs = secs;
			}
		}
		else if (secs > 3600)
		{
			secs -= ((this->hours = secs / 3600) * 3600);
			if (secs>60)
			{
				secs -= ((this->mins = secs / 60) * 60);
				this->secs = secs;
			}
			else
			{
				this->secs = secs;
			}
		}
		else if (secs>60)
		{
			secs -= ((this->mins = secs / 60) * 60);
			this->secs = secs;
		}
		else
		{
			this->secs = secs;
		}
	}
}

Time::Time()
{
	this->hours = 0;
	this->mins = 0;
	this->secs = 0;
	this->days = 0;
}


Time::~Time()
{
}

void Time::setHours(int hours)
{
	if (hours < 0)
		this->hours = 0;
	else
		this->hours = hours;
}

void Time::setDays(int days)
{
	if (days < 0)
		this->days = 0;
	else
		this->days = days;
}

void Time::setMins(int mins)
{
	if (mins < 0)
		this->mins = 0;
	else
		this->mins = mins;
}

void Time::setSecs(int secs)
{
	if (secs < 0)
		this->secs = 0;
	else
		this->secs = secs;
}

int Time::getHours()
{
	return this->hours;
}

int Time::getMins()
{
	return this->mins;
}

int Time::getDays()
{
	return this->days;
}

int Time::getSecs()
{
	return this->secs;
}

void Time::validateTime(int days, int hours, int mins, int secs)
{
	if (days>0 && hours>0 && mins>0 && secs>0)
	{
		setDays(days);
		setHours(hours);
		setMins(mins);
		setSecs(secs);
		if (secs > 60)
		{
			this->mins += secs / 60;
			this->secs -= (secs / 60) * 60;
		}
		if (this->mins > 60)
		{
			this->hours += this->mins / 60;
			this->mins -= (mins / 60) * 60;
		}
		if (this->hours > 24)
		{
			this->days += this->hours / 24;
			this->hours -= (hours / 24) * 24;
		}
	}
	else
	{
		setDays(0);
		setHours(0);
		setMins(0);
		setSecs(0);
	}
}

ostream &operator<<(ostream& out,Time &t)
{
	out << t.getDays() << "~" << t.getHours() << ":" << t.getMins() << ":" << t.getSecs();
	return out;
}

istream &operator>>(istream&is,Time &t)
{
	int day, hr, min, sec;
	cout << "Enter the days:";   is >> day ;
	cout << "Enter the hours:";  is>> hr;
	cout << "Enter the mins:";  is>> min;
	cout << "ENter the secs";    is>> sec;
	t.validateTime(day,hr,min,sec);
	return is;
}

Time Time::operator+(Time &t)
{
	t.validateTime((this->days + t.days),(this->hours+t.hours),(this->mins+t.mins),(this->secs+t.secs));
	return t;
}

Time Time::operator-(Time &t)
{
	int secs1, secs2;
	secs1 = (this->days * 86400) + (this->hours * 3600) + (this->mins * 60) + (this->secs);
	secs2 = (t.days * 86400) + (t.hours * 3600) + (t.mins * 60) + (t.secs);
	Time t1(secs1 - secs2);
	return t1;
}

Time Time::operator*(int number)
{
	this->validateTime((this->days * number), (this->hours * number), (this->mins * number), (this->secs * number));
	return *this;
}

bool Time::operator<(const Time & t)
{
	int secs1, secs2;
	secs1 = (this->days * 86400) + (this->hours * 3600) + (this->mins * 60) + (this->secs);
	secs2 = (t.days * 86400) + (t.hours * 3600) + (t.mins * 60) + (t.secs);

	if (secs1 > secs2)
		return false;
	else
		return true;
}

bool Time::operator>(const Time &t)
{
	int secs1, secs2;
	secs1 = (this->days * 86400) + (this->hours * 3600) + (this->mins * 60) + (this->secs);
	secs2 = (t.days * 86400) + (t.hours * 3600) + (t.mins * 60) + (t.secs);

	if (secs1 > secs2)
		return true;
	else
		return false;
}

bool Time::operator==(const Time &t)
{
	int secs1, secs2;
	secs1 = (this->days * 86400) + (this->hours * 3600) + (this->mins * 60) + (this->secs);
	secs2 = (t.days * 86400) + (t.hours * 3600) + (t.mins * 60) + (t.secs);

	if (secs1 == secs2)
		return true;
	else
		return false;
}

bool Time::operator!=(const Time &t)
{
	int secs1, secs2;
	secs1 = (this->days * 86400) + (this->hours * 3600) + (this->mins * 60) + (this->secs);
	secs2 = (t.days * 86400) + (t.hours * 3600) + (t.mins * 60) + (t.secs);

	if (secs1 != secs2)
		return true;
	else
		return false;
}

Time Time::operator++()
{
	this->validateTime(this->days+=1, this->hours += 1, this->mins += 1, this->secs += 1);
	return *this;
}

Time Time::operator++(int) //postfix
{
	Time t(this->days,this->hours,this->mins,this->secs);
	this->validateTime(this->days += 1, this->hours += 1, this->mins += 1, this->secs += 1);
	return t;
}

Time Time::operator--()
{
	this->validateTime(this->days -= 1, this->hours -= 1, this->mins -= 1, this->secs -= 1);
	return *this;
}

Time Time::operator--(int)
{
	Time t(this->days, this->hours, this->mins, this->secs);
	this->validateTime(this->days -= 1, this->hours -= 1, this->mins -= 1, this->secs -= 1);
	return t;
}
