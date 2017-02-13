/*****************************************************************
Name: Samantha Coyle
Date: January 26, 2017
Problem Number: 1
Hours spent solving the problem: 9
Instructor: Komogortsev, TSU
******************************************************************/
//Include all of the libraries necessary for program to run
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Create prototypes
void convertTime(char initialTime[], char normalTime[]);
double convertTemp(double tempValue);

//Create file objects for input and output files
ifstream fin;
ofstream fout;

//Declare variables used in the main function
int numSamples; //Number of samples
const int arrayLength1 = 12; //Length for time stamp from input file
const int arrayLength2 = 15; //Length for time stamp for output file
const int arrayLength3 = 7; //Length for reading in temp type and value
const int arrayLength4 = 7;
char initialTime[arrayLength1]; //Char array storing input file time stamp
char normalTime[arrayLength2]; //Char array storing human readable time stamp
char temperature[arrayLength3]; //Char array storing temperature information
char tempType; //Shows temperature type in Fahrenheit or Celsius
double tempValue = 0.0; //Initialize temperature value
double averageTemp = 0.0; //Initialize average temperature to zero to avoid trash
double totalTemp = 0.0; //Get the total temperature value

int main()
{
	//Open the files
	fin.open("biodata.dat");
	fout.open("filtered_biodata.dat");

	//Set the decimal place to 2 places
	fout << fixed << showpoint << setprecision(2);

	//Check that the input file opens
	if(fin.fail())
	{
		cout << "Input file did not open. Program terminating.";
		return 1;
	}

	//Check that the output file opens
	if(fout.fail())
	{
		cout << "Output file did not open. Program terminating.";
		return 1;
	}

	fin >> numSamples; //Read in the number of samples

	fout << "Biodata Formatted Output" << endl << endl;

	//Read in the data for each sample number
	for(int index = 0; index < numSamples; index++)
	{
		fin >> initialTime; //Read in and store time stamp

        //Convert the time to human readable form
		convertTime(initialTime, normalTime);

		fin >> temperature; //Read in the temperature info

        //If temperature is not F or C, give error message
        if(temperature[0] != 'F' && temperature[0] != 'C')
            {
            cout << "Error: temperature not in F or C. Terminating program.";
            cout << endl << endl;
            return 1;
            }

        //If temperature is in F, convert to C
        if(temperature[0] == 'F')
            {
            char tempOnly[arrayLength3-1];

            //Get rid of the temperature type letter in array
            for(int i = 1; i < arrayLength3; i++)
                tempOnly[i-1] = temperature[i];

            //Convert to double
            tempValue = atof(tempOnly);

            tempValue = convertTemp(tempValue); //Convert F to C
            }

        if(temperature[0] == 'C')
            {
            char tempOnly2[arrayLength3-1];

            //Get rid of the temperature type letter in array
            for(int i = 1; i < arrayLength3; i++)
                tempOnly2[i-1] = temperature[i];

            tempValue = atof(tempOnly2); //Convert to double
            }

        if(tempValue < 0) //Check temperature values are above 0
            {
            cout << "Temperature less than 0. Terminating program.";
            cout << endl;
            return 1;
            }

        totalTemp += tempValue; //Calculate total temperature

        //Display data in output file
        fout << tempValue << " C --- recorded on ";

        for(int m = 0; m < arrayLength2-5; m++)
            fout << normalTime[m];

        fout << " at ";

        for(int n = 10; n < arrayLength2-1; n++)
            fout << normalTime[n];

        fout << endl;
        }//Close the for loop running through num samples

	//Calculate the average temperature
	averageTemp = totalTemp/numSamples;
    fout << endl << "Average Temp --- " << averageTemp << " C";

	//Close the files
	fin.close();
	fout.close();

	return 0; //Check for success
}//Close the main file

/*****************************************************************
Function One:
Convert initial time stamp to human readable time stamp
******************************************************************/
void convertTime(char initialTime[], char normalTime[])
{
    normalTime[6]  = initialTime[0]; //Part of year
	normalTime[7]  = initialTime[1]; //Part of year
	normalTime[8]  = initialTime[2]; //Part of year
	normalTime[9]  = initialTime[3]; //Part of year
	normalTime[0]  = initialTime[4]; //Part of month
	normalTime[1]  = initialTime[5]; //Part of month
	normalTime[2]  = '/'; //Separate month and date
   	normalTime[3]  = initialTime[6]; //Part of date
	normalTime[4]  = initialTime[7]; //Part of date
    normalTime[5]  = '/'; //Separate date and year
	normalTime[10] = initialTime[8]; //Hour
	normalTime[11] = initialTime[9]; //Hour
	normalTime[12] = initialTime[10]; //Minute
	normalTime[13] = initialTime[11]; //Minute

}

/*****************************************************************
Function Two:
Convert temperature in Fahrenheit to temperature in Celcius
******************************************************************/
double convertTemp(double tempValue)
{
	double tempInC = 0;
	tempInC = (tempValue-32)*(5.0/9.0);
	return (tempInC);
}




