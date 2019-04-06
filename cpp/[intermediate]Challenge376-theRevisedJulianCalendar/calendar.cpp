#include <iostream>

using namespace std;

//Prototypes
bool isLeapYear(long int year);
long int getNumOfLeapYears(long int startYear, long int endYear);
long int getClosestLeapYear(long int year, bool startEnd);
long int getNumOfExceptionLeapYears (long int year, int remainder, int divisor);


int main () {
  cout << getNumOfLeapYears(123456, 7891011) << endl;

  return 0;
}






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
  long int numOfLeapYears = 0;
  long int startLeapYear = getClosestLeapYear(startYear, true);
  long int endLeapYear = getClosestLeapYear(endYear, false);

  //Ends loop if there are no leap years.
  if(startLeapYear > endYear || endLeapYear < startYear)
    {
      return 0;
    }
  else
    {
      //Gets total number of years disvisible by 4 (How often a leap year occurs) between start and end year
      numOfLeapYears = (endLeapYear/4)-(startLeapYear/4);

      //Removes every leap year divisible by 100
      numOfLeapYears = numOfLeapYears - ((endLeapYear/100)-(startLeapYear/100));

      //Re-adds leap years that are divisible by 100 but has a remainder of 200 or 600 when divided by 900
      numOfLeapYears = numOfLeapYears + ((getNumOfExceptionLeapYears(endLeapYear, 200, 900)-getNumOfExceptionLeapYears(startLeapYear,200,900)) + (getNumOfExceptionLeapYears(endLeapYear, 600, 900) - getNumOfExceptionLeapYears(startLeapYear, 600, 900)));
    }
  
  return numOfLeapYears;
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

long int getNumOfExceptionLeapYears (long int year, int remainder, int divisor) {
  long int numOfExceptionLeapYears = 0;

  //(year-remainder)/divisor = multiple of divisor or number of times x%divisor=remainder happen in year
  numOfExceptionLeapYears = (year-remainder)/divisor;
  //Adds 1 if year >= remainder because if year is the same as remainder it will give a remainder of 1 but a multiple of zero.
  if(year >= remainder)
    {
      numOfExceptionLeapYears++;
    }

  return numOfExceptionLeapYears;
}
