#include <iostream>

int main () {
  using namespace std;

  
  for(int i = 0; i < 2019; i++)
    {
      
      if (i % 100 == 0)
	{
	  if(i % 900 == 200)
	    {
	      cout << i << " % 900 = " << i%900 << endl;
	      //cout << (i-200)/900 << "\n" << endl;
	    }
	  else if (i % 900 == 600)
	    {
	      cout << i << " % 900 = " << i%900 << endl;
	      //cout << (i-600)/900 << "\n" << endl;
	    }
	  }
      

      /*
      if (i % 100 == 0 && ((i-200)%900==0 || (i-600)%900==0))
	{
	  cout << i << " % 900 = " << i%900 << endl;

	  if((i-200)%900 == 0)
	    {
	      cout << (i-200)/900 << "\n" << endl;
	    }
	  else if ((i-600)%900 == 0)
	    {
	      cout << (i-600)/900 << "\n" << endl;
	    }
	    } */
    }

  int numOfLeapYearExceptions;
  numOfLeapYearExceptions = ((2000-200)/900)+((2000-600)/900)+2;

  cout << "Number of leap years that are divisible by 100 and have a remainder of 200 or 600 when divided by 900\n" << numOfLeapYearExceptions << endl;

  return 0;
}
