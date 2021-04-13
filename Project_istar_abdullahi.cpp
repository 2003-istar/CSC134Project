//CSC134 Project 2
// Name: Istar Abdullahi
//Date: April 8, 2021
/* Description: This program will tell a gamer what graphics
quality they will be able to run a newly developed video game
on, based on the specifications of their computer's hardware.
*/

//including the files needed
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//initialize the variables
	int choice;// users choice
	int GPUSpeed, CPUSpeed, numCores, numComp, i;// variables for the clock speed of the graphic card & processor
	double multi, perScore= 0, highScore= 0, lowScore= 0;
	//and the number of cores
	string recom = "\n\nComputer Hardware Graphics Quality Recommendation Tool\n\n"; // string holding the name
	
	do
	{
		cout << "How many computer are being processed? : ";
		cin >> numComp;
	}while (numComp < 0);// validates the inputer number and repeates the question if invalid input is entered
	
	cout << recom;
	
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
		}while ( choice < 0 || choice > 5);// validates the input and asks for input again if wrong.
		
		//Output
		cout << "\n\nGPU Clock Speed: "<< GPUSpeed << " MHz";// print out the gpu clock speed
		cout << "\nCPU Clock Speed: "<< CPUSpeed << " MHz";// print out the cpu clock speed
		cout << "\nNumber of Cores: "<< numCores;//print out the number of cores
	
		switch(choice)// prints out the resolution that was picked
		{
			case 1:// if choice is 1 print out the resolution : 1280 x 720
			{	//calculating performance score based on input
				perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * 1;
				cout << "\nMonitor Resolution: 1280 x 720";
				break;
			}
			case 2:// if choice is 2 print out the resolution : 1920 x 1080
			{	//calculating performance score based on input
				perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * .75;
				cout << "\nMonitor Resolution: 1920 x 1080";
				break;
			}
			case 3:// if choice is 3 print out the resolution : 2560 x 1440
			{	//calculating performance score based on input
				perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * .55;
				cout << "\nMonitor Resolution: 2560 x 1440";
				break;
			}
			case 4:// if choice is 4 print out the resolution : 3840 x 2160
			{	//calculating performance score based on input
				perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * .35;
				cout << "\nMonitor Resolution: 3840 x 2160";
				break;
			}
		}
		//print the performance score formatted 
		cout << "\nPerformance Score: " << fixed << setprecision(2)<<perScore;
		
		
		if(perScore > 17000)// if more than 17,00, print ultra
		{
			cout << "\nRecommended Graphics Quality: Ultra\n\n";
		}else if (perScore > 15000 )//if more than 15000, print high
		{
			cout << "\nRecommended Graphics Quality: High\n\n";
		}else if (perScore > 13000 )//if more than 13,000, print medium
		{
			cout << "\nRecommended Graphics Quality: Medium\n\n";
		}else if (perScore > 11000 )// if more than 11,000, print low
		{
			cout << "\nRecommended Graphics Quality: Low\n\n";
		}else// if less than 11000, print unable to play
		{
			cout << "\nRecommended Graphics Quality: Unable to Play\n\n\n";
		}
		
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





