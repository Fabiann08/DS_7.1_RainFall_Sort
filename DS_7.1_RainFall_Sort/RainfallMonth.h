//THIS IS RAINFALLMONTH.H
#pragma once
#include "LinkedSortedList.h"
#include <string>
using namespace std;

class RainFallMonth: public LinkedSortedList<RainFallMonth>
{
private:
	string monthName;
	float rainfall;
public:
	RainFallMonth();
	RainFallMonth(string monthName, float rainfall);
	~RainFallMonth() override;
	string getMonthName();
	float getRainfall();
	void setMonthName(string monthName);
	void setRainfall(float rainfall);
	bool operator==(const RainFallMonth& other) const;
	bool operator<(const RainFallMonth& other) const;
	bool operator>(const RainFallMonth& other) const;
};