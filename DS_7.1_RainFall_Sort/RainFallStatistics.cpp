//THIS IS RAINFALLSTATISTICS.cpp
#include "RainFallStatistics.h"
#include <iostream>
#include <string>

template<class ItemType>
RainFallStatistics<ItemType>::RainFallStatistics()
{
	 //RainFallYear = LinkedSortedList();
}

template<class ItemType>
RainFallStatistics<ItemType>::RainFallStatistics(const LinkedSortedList<RainFallMonth> RainFallYear)
{
	this->RainFallYear = RainFallYear;
}

template<class ItemType>
RainFallStatistics<ItemType>::~RainFallStatistics()
{
}

template<class ItemType>
void RainFallStatistics<ItemType>::addRainFallMonth(RainFallMonth rainFallMonth)
{
	RainFallYear.insertSorted(rainFallMonth);
}

template<class ItemType>
void RainFallStatistics<ItemType>::displayRainFallYear()
{
	cout << "Rainfall for the year:" << endl;
	cout << RainFallYear << endl;
}

template<class ItemType>
void RainFallStatistics<ItemType>::displayRainFallMonth(string monthName)
{
	RainFallMonth rainFallMonth(monthName, 0.0);
	if (RainFallYear.getEntry(rainFallMonth, rainFallMonth))
	{
		cout << "Rainfall for " << monthName << ": " << rainFallMonth.getRainfall() << endl;
	}
	else
	{
		cout << "Rainfall for " << monthName << ": Not found" << endl;
	}
}

template<class ItemType>
void RainFallStatistics<ItemType>::displayRainFallMonth(RainFallMonth rainFallMonth)
{
	if (RainFallYear.getEntry(rainFallMonth, rainFallMonth))
	{
		cout << "Rainfall for " << rainFallMonth.getMonthName() << ": " << rainFallMonth.getRainfall() << endl;
	}
	else
	{
		cout << "Rainfall for " << rainFallMonth.getMonthName() << ": Not found" << endl;
	}
}

template<class ItemType>
void RainFallStatistics<ItemType>::displayRainFallMonth(int monthNumber)
{
	RainFallMonth rainFallMonth("", 0.0);
	if (RainFallYear.getEntry(monthNumber, rainFallMonth))
	{
		cout << "Rainfall for " << rainFallMonth.getMonthName() << ": " << rainFallMonth.getRainfall() << endl;
	}
	else
	{
		cout << "Rainfall for " << rainFallMonth.getMonthName() << ": Not found" << endl;
	}
}

template<class ItemType>
void RainFallStatistics<ItemType>::displayRainFallMonth()
{
	RainFallMonth rainFallMonth("", 0.0);
	if (RainFallYear.getEntry(1, rainFallMonth))
	{
		cout << "Rainfall for " << rainFallMonth.getMonthName() << ": " << rainFallMonth.getRainfall() << endl;
	}
	else
	{
		cout << "Rainfall for " << rainFallMonth.getMonthName() << ": Not found" << endl;
	}
}

template<class ItemType>
void RainFallStatistics<ItemType>::displayRainFallMonthAverage()
{
	RainFallMonth rainFallMonth("", 0.0);
	float total = 0.0;
	int count = 0;
	for (int i = 1; i <= RainFallYear.getLength(); i++)
	{
		if (RainFallYear.getEntry(i, rainFallMonth))
		{
			total += rainFallMonth.getRainfall();
			count++;
		}
	}
	cout << "Average rainfall for the year: " << total / count << endl;
}

template<class ItemType>
void RainFallStatistics<ItemType>::displayRainFallMonthTotal()
{
	RainFallMonth rainFallMonth("", 0.0);
	float total = 0.0;
	for (int i = 1; i <= RainFallYear.getLength(); i++)
	{
		if (RainFallYear.getEntry(i, rainFallMonth))
		{
			total += rainFallMonth.getRainfall();
		}
	}
	cout << "Total rainfall for the year: " << total << endl;
}