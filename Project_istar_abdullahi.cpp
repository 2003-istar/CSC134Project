//CSC134 Project 1
// Name: Istar Abdullahi
//Date: March 6, 2021
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
	double GPUSpeed, CPUSpeed, numCores, multi, perScore;// variables for the clock speed of the graphic card & processor
	//and the number of cores
	
	string recom = "\n\nComputer Hardware Graphics Quality Recommendation Tool\n\n";

	//output asking for user input & storing it in a variable
	cout << "Please enter the clock speed <in Megahertz> of your graphics card: ";
	cin >> GPUSpeed;


	if(GPUSpeed > 0)
	{
		//output asking for user input & storing it in a variable
		cout << "Please enter the clock speed <in Megahertz> of your processor: ";
		cin >> CPUSpeed;

		if(CPUSpeed > 0)
		{
			//output asking for user input & storing it in a variable
			cout << "Please enter the number of cores of your processor: ";
			cin >> numCores;
			
			if(numCores>0)
			{
				//print monitor resolution options for user to choose from.
				cout << "What is the resolution of your monitor?";
				cout << "\n\t 1. 1280 x 720";
				cout << "\n\t 2. 1920 x 1080";
				cout << "\n\t 3. 2560 x 1440";
				cout << "\n\t 4. 3840 x 2160";

				//output asking for user input & storing it in a variable
				cout << "\nPlease select from the options above: ";
				cin >> choice;
			
				if(choice ==1)//check the choice
				{
					//calculating performance score based on input
					perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * 1;
				}else if(choice ==2)
				{
					//calculating performance score based on input
					perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * .75;
				}else if(choice == 3)
				{
					//calculating performance score based on input
					perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * .55;
				}else if (choice == 4)
				{
					//calculating performance score based on input
					perScore = ((5 * GPUSpeed) + (numCores * CPUSpeed)) * .35;
				}else
				{
					//sends error message if input is invalid
					cout << "Invalid choice entered. Program will terminate.";
				}
				
				if(perScore > 17000)// if more than 17,00, print ultra
				{
					cout << "\nRecommended Graphics Quality: Ultra";
				}else if (perScore > 15000 )//if more than 15000, print high
				{
					cout << "\nRecommended Graphics Quality: High";
				}else if (perScore > 13000 )//if more than 13,000, print medium
				{
					cout << "\nRecommended Graphics Quality: Medium";
				}else if (perScore > 11000 )// if more than 11,000, print low
				{
					cout << "\nRecommended Graphics Quality: Low";
				}else// if less than 11000, print unable to play
				{
					cout << "\nRecommended Graphics Quality: Unable to Play";
				}	
				
				
			}
			else //sends error message if input is invalid
			{
				cout << "Invalid cores speed entered. Program will terminate.";
			}
		}
		else//sends error message if input is invalid
		{
			cout << "Invalid processor speed entered. Program will terminate.";
		}
	}
	else//sends error message if input is invalid
	{
		cout << "Invalid graphics card speed entered. Program will terminate.";
	}
	
	
	
	return 0;
}





