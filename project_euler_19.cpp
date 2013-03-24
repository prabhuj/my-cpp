#include <iostream>

int getDayOfWeek(int month, int day, int year, int CalendarSystem)
{
	// CalendarSystem = 1 for Gregorian Calendar
	if (month < 3)
	{
		month = month + 12;
		year = year - 1;
	}
	return (day + (2*month) + int(6*(month+1)/10) + year + int(year/4) - int(year/100) + int(year/400) + CalendarSystem) % 7;
}

int main()
{
	char week[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday",};

	//cout << week[getDayOfWeek(1,1,1900,1)] << endl;

	int result = 0;
	for(int year=1901;year<=2000;year++)
	{
		for(int month=1;month<=12;month++)
		{
			if(getDayOfWeek(month,1,year,1) == 0)
			{
				result++;
			}
		}
	}
	cout << result << endl;

	return 0;
}

// http://everything2.com/title/How+to+calculate+the+day+of+the+week+for+a+given+date
