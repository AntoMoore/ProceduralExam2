#include <stdio.h>

//constants
#define GAMES_PLAYED 10

//declare functions
int getMaxDistance(int list[]);
float getAverage(float total);

void main()
{
	//files
	FILE* outputFile;
	outputFile = fopen("PerformanceTest.txt", "w");

	//variables
	int testDataArr1[10];
	int testDataArr2[10];
	int maxPlayer1;
	int maxPlayer2;
	int totalPlayer1 = 0;
	int totalPlayer2 = 0;
	float avgPlayer1, avgPlayer2;
	int bestPlayer;
	int i;

	//loop
	for (i = 0; i < GAMES_PLAYED; i++)
	{
		//prompt user
		printf("Please Enter the distance ran by Player 1 in Game %d\n", (i + 1));
		scanf("%d", &testDataArr1[i]);
		totalPlayer1 += testDataArr1[i];

		printf("Please Enter the distance ran by Player 2 in Game %d\n", (i + 1));
		scanf("%d", &testDataArr2[i]);
		totalPlayer2 += testDataArr2[i];
	}

	//function to find max distance
	maxPlayer1 = getMaxDistance(testDataArr1);
	maxPlayer2 = getMaxDistance(testDataArr2);

	//function to find average
	avgPlayer1 = getAverage(totalPlayer1);
	avgPlayer2 = getAverage(totalPlayer2);

	//find which player did best
	if (avgPlayer1 > avgPlayer2)
	{
		bestPlayer = 1;
	}
	else if (avgPlayer2 > avgPlayer1)
	{
		bestPlayer = 2;
	}
	else
	{
		bestPlayer = 0;
	}

	//header
	printf("Player1 Versus Player2 \n");
	printf("Game    Player 1    Player 2 \n");
	fprintf(outputFile, "Player1 Versus Player2 \n");
	fprintf(outputFile, "Game    Player 1    Player 2 \n");

	//output Arrays
	for (i = 0; i < GAMES_PLAYED; i++)
	{
		printf("%d %10d %10d \n", (i + 1), testDataArr1[i], testDataArr2[i]);
		fprintf(outputFile, "%d %10d %10d \n", (i + 1), testDataArr1[i], testDataArr2[i]);
	}

	//output results
	printf("\nThe Max distance ran by player 1 is: %d \n", maxPlayer1);
	printf("The Max distance ran by player 2 is: %d \n", maxPlayer2);
	fprintf(outputFile, "\nThe Max distance ran by player 1 is: %d \n", maxPlayer1);
	fprintf(outputFile, "The Max distance ran by player 2 is: %d \n", maxPlayer2);

	printf("\nThe Average distance ran by player 1 is %.2f and the Average distance ran by player 2 is %.2f \n", avgPlayer1, avgPlayer2);
	printf("Hence the average distance ran by player %d is better \n", bestPlayer);
	fprintf(outputFile, "\nThe Average distance ran by player 1 is %.2f and the Average distance ran by player 2 is %.2f \n", avgPlayer1, avgPlayer2);
	fprintf(outputFile, "Hence the average distance ran by player %d is better \n", bestPlayer);

	//close files
	fclose(outputFile);

}

//======== myFunctions ===============

int getMaxDistance(int list[])
{
	//variable
	int maxDistance = 0;
	int counterHigh = 0;
	int current;
	int i;

	//loop
	for (i = 0; i < GAMES_PLAYED; i++)
	{
		
		//largest distance ran
		if ((maxDistance >= 0) && (counterHigh == 0))
		{
			maxDistance = list[i]; //only runs on first pass
			counterHigh++;
		}
		else if (maxDistance < list[i])
		{
			maxDistance = list[i];
			counterHigh++;
		}	
	}//for
	return maxDistance;
}

//==================================================

float getAverage(float total)
{
	//variable
	float average;
	
	average = total / GAMES_PLAYED;
	return average;
}

