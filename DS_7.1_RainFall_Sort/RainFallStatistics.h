//THIS IS RAINFALLSTATISTICS.H
#pragma once
#include "LinkedSortedList.h"
#include "RainFallMonth.h"
#include <vector>

template<class ItemType>
class RainFallStatistics: public LinkedSortedList<RainFallMonth>
{
private:
	LinkedSortedList<RainFallMonth> RainFallYear;
public:
	RainFallStatistics();
	RainFallStatistics(const LinkedSortedList<RainFallMonth> RainFallYear);
	~RainFallStatistics() override;
	void addRainFallMonth(RainFallMonth rainFallMonth);
	void displayRainFallYear();
	void displayRainFallMonth(string monthName);
	void displayRainFallMonth(RainFallMonth rainFallMonth);
	void displayRainFallMonth(int monthNumber);
	void displayRainFallMonth();
	void displayRainFallMonthAverage();
	void displayRainFallMonthTotal();
	friend ostream& operator<<(ostream& os, const RainFallStatistics& rainFallStatistics)
	{
		os << rainFallStatistics.RainFallYear;
		return os;
	}
};
