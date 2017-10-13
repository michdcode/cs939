#include <iostream>
using namespace std;

// List function prototypes
void getJudgeData(double &score);
double calcScore(double, double, double, double, double);
int findLowest(double, double, double, double, double);
int findHighest(double, double, double, double, double);


int main()
{
	// Initalize variables
	double score1, score2, score3, score4, score5, finalScore; 

	// Explain purpose of program
	cout << "This program will collect scores from five judges for\n"
		 << "a talent competition. Scores must be between 0 and 10.\n"
		 << "The program will drop the lowest and the highest scores.\n"
		 << "Then, it will average the three remaining scores to create\n"
		 << "a final score.\n\n";

	// Obtain judges scores by calling getJudgeData five times
	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	// Obtain the final score
	finalScore = calcScore(score1, score2, score3, score4, score5);

	// Display the final score
	cout << "\n Congratulations! The final score is " << finalScore << endl; 

	return 0;
}

// Obtains the score for a judge & validates it.
void getJudgeData(double &score)
{	
	// Obtain user input for score
	cout << "Please enter the score of the judge: ";
	cin >> score;

	// Validation of score 
	while (score < 0 || score > 10)
	{
		cout << "\n The score must be between 0 and 10.\n"
		  	 << "Please enter a score between 0 and 10: ";
		cin >> score;
	}
}

// Finds the lowest score. 
int findLowest(double one, double two, double three, double four, double five)
{	
	//Initialize a variable to hold the lowest number
	double low;
	
	//Compare scores to each other, starting with the first, to find lowest one
	low = one;
	if (two < low)
		low = two;
	if (three < low)
		low = three;
	if (four < low)
		low = four;
	if (five < low)
		low = five; 
	// cout << "\nthe lowest is " << low << endl;
	return low;
}

// Finds the highest score. 
int findHighest(double one, double two, double three, double four, double five)
{	
	//Initialize a variable to hold the highest number
	double high;

	//Compare scores to each other, starting with the first, to find the highest one
	high = one;
	if (two > high)
		high = two;
	if (three > high)
		high = three;
	if (four > high)
		high = four;
	if (five > high)
		high = five;
	// cout << "the highest is " << high << endl;
	return high; 
}

// Gets the lowest & highest scores and tosses them out, averages remaining three scores.
double calcScore(double one, double two, double three, double four, double five)
{
	//Initalize variables
	double lowest, highest, total, average;

	//Get the lowest and highest scores
	lowest = findLowest(one, two, three, four, five);
	// cout << "the low is " << lowest << endl;
	highest = findHighest(one, two, three, four, five);
	// cout << "the high is " << highest << endl;

	//Sum all five scores and toss out the lowest & highest
	total = (one + two + three + four + five);
	total = total - lowest;
	total = total - highest;
	// cout << "the total is " << total << endl; 

	//Calculate the average
	average = (total / 3);
	// cout << "the average is" << average << endl; 

	return average; 
}
