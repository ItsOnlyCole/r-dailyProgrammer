#include <iostream>

using namespace std;

//Prototypes
bool isLeapYear(long int year);
long int getNumOfLeapYears(long int startYear, long int endYear);
long int getClosestLeapYear(long int year, bool startEnd);



bool isLeapYear(long int year) {
  if (year % 4 == 0 && year % 100 != 0)
    {
      return true;
    }
  else if (year % 4 == 0 && year % 100 == 0)
    {
      if (year % 900 == 200 || year % 900 == 600)
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  else
    {
      return false;
    }
}

long int getNumOfLeapYears(long int startYear, long int endYear) {
  int numOfLeapYears = 0;
  long int startLeapYear = getClosestLeapYear(startYear, true);
  long int endLeapYear = getClosestLeapYear(endYear, false);

  //Ends loop if there are no leap years.
  if(startLeapYear > endYear || endLeapYear < startYear)
    {
      return 0;
    }
  
}




long int getClosestLeapYear (long int year, bool startEnd) {
  long int leapYear = year;

  while(leapYear % 4 != 0)
    {
      //Increments for startYear if true
      if(startEnd == true)
	{
	  leapYear++;
	}
      //Decrements for endYear if false
      else
	{
	  leapYear--;
	}
    }

  return leapYear;
}
