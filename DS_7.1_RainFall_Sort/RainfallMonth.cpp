//THIS IS RAINFALLMONTH.CPP
#include "RainfallMonth.h"


RainFallMonth::RainFallMonth(): monthName(""), rainfall(0.0)
{
}

RainFallMonth::RainFallMonth(string monthName, float rainfall)
{
	this->monthName = monthName;
	this->rainfall = rainfall;
}

RainFallMonth::~RainFallMonth()
{
}

string RainFallMonth::getMonthName()
{
	return monthName;
}

float RainFallMonth::getRainfall()
{
	return rainfall;
}

void RainFallMonth::setMonthName(string monthName)
{
	this->monthName = monthName;
}

void RainFallMonth::setRainfall(float rainfall)
{
	this->rainfall = rainfall;
}

bool RainFallMonth::operator==(const RainFallMonth& other) const
{
	return (this->monthName == other.monthName);
}

bool RainFallMonth::operator<(const RainFallMonth& other) const
{
	return (this->monthName < other.monthName);
}

bool RainFallMonth::operator>(const RainFallMonth& other) const
{
	return (this->monthName > other.monthName);
}