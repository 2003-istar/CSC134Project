//CSC134 Project 3
// Name: Istar Abdullahi
//Date: May 1, 2021
/* Description: This program will tell a gamer what graphics
quality they will be able to run a newly developed video game
on, based on the specifications of their computer's hardware.
*/

//including the files needed
#include <iostream>
#include <iomanip>
#include <string>

//prototypes 
void displayTitle ();
std::string getResolutionString(int);
double getMultiplierValue(int);
double calculatePerformanceScore (int, int, int, double);
std :: string getRecommendedQuality (int);
void displayInformation (int, int, int, double, std::string, std ::string);

using namespace std;

int main()
{
	//initialize the variables
	int choice;// users choice
	int GPUSpeed, CPUSpeed, numCores, numComp, i;// variables for the clock speed of the graphic card & processor
	double multi, perScore= 0, highScore= 0, lowScore= 0;
	string resolution;
	string quality;
	//and the number of cores
	
	do
	{
		cout << "How many computer are being processed? : ";
		cin >> numComp;
	}while (numComp < 0);// validates the inputer number and repeates the question if invalid input is entered
	
	displayTitle();
	
	for (i=0; i < numComp; i++)// loop through the program to calculate the amount of computers entered
	{
		do
		{
			//output asking for user input & storing it in a variable
			cout << "Please enter the clock speed <in Megahertz> of your graphics card: ";
			cin >> GPUSpeed;
		}while(GPUSpeed < 800 or GPUSpeed > 2000 );// validates the input and asks for input again if wrong.
		
		
		do
		{
			//output asking for user input & storing it in a variable
			cout << "Please enter the clock speed <in Megahertz> of your processor: ";
			cin >> CPUSpeed;
		}while(CPUSpeed < 1000 or CPUSpeed > 5500);// validates the input and asks for input again if wrong.
		
		
		do
		{
			cout << "Please enter the number of cores of your processor: ";
			cin >> numCores;
		}	while(numCores < 1 or numCores > 16);// validates the input and asks for input again if wrong.
		
	
		//print monitor resolution options for user to choose from.
		cout << "What is the resolution of your monitor?";
		cout << "\n\t 1. 1280 x 720";
		cout << "\n\t 2. 1920 x 1080";
		cout << "\n\t 3. 2560 x 1440";
		cout << "\n\t 4. 3840 x 2160";
		
		do
		{
			//output asking for user input & storing it in a variable
			cout << "\nPlease select from the options above: ";
			cin >> choice;
		}while ( choice < 0 || choice > 4);// validates the input and asks for input again if wrong.
		
		resolution = getResolutionString (choice); // stores the resolution based on the choice
		multi = getMultiplierValue(choice); // stores the multiplier value based on the choice
		
		perScore = calculatePerformanceScore(GPUSpeed, CPUSpeed, numCores, multi);// calculates the performance score
		quality = getRecommendedQuality(perScore); // holds the quality 
		
		displayInformation (GPUSpeed, CPUSpeed, numCores, perScore, resolution, quality);
		
		if( i == 0)
		{
			highScore =perScore;// set the first highscore
			lowScore =perScore;// set the first lowscore
		}
		if(perScore > highScore)// checks the highest score
		{
			highScore = perScore;// sets the high score
		}
		
		if(perScore < lowScore)// checks the lowest score
		{
			lowScore = perScore;// sets the lowest score	
		}
	}
	
	cout << "The highest performance score was: " << highScore << endl;//prints high score
	cout << "The lowest performance score was:  " << lowScore << endl;// prints low score
	
	
	return 0;
}

/*display title: 
prints the title out whenever called. doesn't return anything. 
*/
void displayTitle ()
{
	string recom = "\n\nComputer Hardware Graphics Quality Recommendation Tool\n\n"; // string holding the name
	cout << recom; // prints out the string variable 
}

/* getResolutionString
A function that accepts an integer value (1, 2, 3, or 4). 
The function should return the appropriate String representation 
of the monitor resolution. 
*/
std::string getResolutionString(int choice)
{
	string resolution;
	if (choice == 1)
		resolution = "1280 x 720"; // sets the string with the resolution
	else if(choice == 2)
		resolution = "1920 x 1080";// sets the string with the resolution
	else if (choice == 3)
		resolution = "2560 x 1440";// sets the string with the resolution
	else if (choice == 4)
		resolution = "3840 x 2160";// sets the string with the resolution
		
	return resolution; // returns the type of resollution
}

/* getMultiplierValue
A Function that accepts an integer value (1, 2, 3, or 4) that 
denotes the monitor resolution and returns the appropriate 
ìmultiplierî value.
*/
double getMultiplierValue (int choice)
{
	double multiValue;
	if (choice == 1)
		multiValue = 1.00; // sets the double with the multiplier value
	else if(choice == 2)
		multiValue = .75;// sets the double with the multiplier value
	else if (choice == 3)
		multiValue = .55;// sets the double with the multiplier value
	else if (choice == 4)
		multiValue = .35;// sets the double with the multiplier value
		
	return multiValue; // returns the mulitplier value
}

double calculatePerformanceScore (int GPUSpeed, int CPUSpeed, int cores, double multiValue)
{
	double perfScore;
	perfScore = ((5 * GPUSpeed) + (cores * CPUSpeed)) * multiValue;
	return perfScore;
	
}

/*getRecommendedQuality
A function that accepts a performance score as an argument and returns 
the recommended graphics quality. 
*/
std :: string getRecommendedQuality (int perfScore)
{
	string quality; // the string variable that holds the recommended quality
	
	if(perfScore > 17000)// if more than 17,00, print ultra
	{
		quality = "Ultra";
	}else if (perfScore > 15000 )//if more than 15000, print high
	{
		quality = "High";
	}else if (perfScore > 13000 )//if more than 13,000, print medium
	{
		quality = "Medium";
	}else if (perfScore > 11000 )// if more than 11,000, print low
	{
		quality = "Low";
	}else// if less than 11000, print unable to play
	{
		quality = "Unable to Play";
	}
	
	return quality; 
}

void displayInformation (int GPUSpeed, int CPUSpeed, int cores, double perScore, string resolution, string quality )
{
	//Output
	cout << "\n\nGPU Clock Speed: "<< GPUSpeed << " MHz";// print out the gpu clock speed
	cout << "\nCPU Clock Speed: "<< CPUSpeed << " MHz";// print out the cpu clock speed
	cout << "\nNumber of Cores: "<< cores;//print out the number of cores
	cout << "\nMonitor Resolution: " << resolution; // prints out the type of resolution

	//print the performance score formatted 
	cout << "\nPerformance Score: " << fixed << setprecision(2)<<perScore;
	cout << "\nRecommended Graphics Quality: " << quality << "\n";
	
	
}





