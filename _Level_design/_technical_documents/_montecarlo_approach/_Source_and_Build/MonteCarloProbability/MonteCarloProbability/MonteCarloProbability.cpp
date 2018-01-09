// MonteCarloProbability.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h> 
#include <time.h>


int main()
{
	srand(time(NULL));

	int currentAttempts[1000];
	int averageAttempts[1000];
	int i = 0;
	int j = 0;

	int baseN = 18; //number of options
	int basen = 3; //number of correct options

	int foundCorrect = 0; //how many correct answers has been found
	int attempts = 0; //how many attempted have been made

	int N = baseN; //current number of options left
	int n = basen; //current number of total options

	bool repeat = true;

	while (repeat)
	{
		bool extraction = false;
		int random = rand() % N + 1; //extraction
		//printf("%d   ", random);
		
		if (random <= n)
		{
			extraction = true;
			//printf("found");
		}

		attempts++;
		N -= 1;
		if (extraction)
		{
			n -= 1;
			if (n <= 0) //found all three correct answers
			{
				currentAttempts[i] = attempts;
				i++;
				if (i >= 1000) //more than 1000 tests
				{
					i = 0;
					double totalAmount = 0;
					for (int z = 0; z < 1000; z++) //average calculation
					{
						totalAmount += currentAttempts[z];
					}
					totalAmount /= 1000;
					averageAttempts[j] = totalAmount;
					j++;
					/*printf("\nPartial repetition:");
					printf("%f", totalAmount);*/
				}
				attempts = 0; //reset
				N = baseN;
				n = basen;
			}
		}

		if (j >= 1000)//all tests over
		{
			repeat = false;
		}
		/*printf("  %d - N %d - n  ", N, n);
		system("pause");*/
	}

	double totalAmount = 0;
	for (int z = 0; z < 1000; z++) //final average
	{
		totalAmount += averageAttempts[z];
	}
	totalAmount /= 1000;
	printf("\nAverage repetition: ");
	printf("%f", totalAmount);
	system("pause");
    return 0;
}

