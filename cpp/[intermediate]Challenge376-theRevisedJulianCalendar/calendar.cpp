#include <iostream>

//Prototypes
long int getNumOfLeapYears(long int startYear, long int endYear);
long int getNumOfExceptionLeapYears (long int year, int remainder, int divisor);


int main () {
  using namespace std;
  long int years[] = {2016, 2017, 2019, 2020, 1900, 1901, 2000, 2001, 2800, 2801, 123456, 123456, 1234, 5678, 123456, 7891011, 123456789101112, 1314151617181920};

  for(int i = 0; i < sizeof(years)/sizeof(years[0]); i++)
    {
      cout << "leaps(" << years[i] << ", " << years[i+1] << ") => " << getNumOfLeapYears(years[i], years[i+1]-1) << endl;
      //Iterrates twice to account for two years being used in years[];
      i++;
    }
  return 0;
}

long int getNumOfLeapYears(long int startYear, long int endYear) {
  long int numOfLeapYears = 0;

  //Ends function if start year is the same or larger than end year.
  if(startYear >= endYear+1)
    {
      return 0;
    }
  else
    {
      //Adds leapyear if first year is a leap year.
      if(startYear%4==0)
	{
	  if (startYear%100 != 0)
	    {
	      numOfLeapYears++;	      
	    }
	  //If year is divisible by 4 and 100, checks to see if it's an exception of exception
	  else if(startYear%900 == 200 || startYear%900 == 600)
	    {
	      numOfLeapYears++;
	    }
	}
      //Adds every leap year after the start year.
      numOfLeapYears += (endYear/4)-(startYear/4);
      //Removes every leap year divisible by 100
      numOfLeapYears -= ((endYear/100)-(startYear/100));
      //Re-adds leap years that are divisible by 100 but has a remainder of 200 or 600 when divided by 900
      numOfLeapYears += ((getNumOfExceptionLeapYears(endYear, 200, 900)-getNumOfExceptionLeapYears(startYear,200,900)) + (getNumOfExceptionLeapYears(endYear, 600, 900) - getNumOfExceptionLeapYears(startYear, 600, 900)));
    }
  return numOfLeapYears;
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



	  


	  
