#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;
void assignmentTwelve(); //get factorial number from input
void assignmentThirteen(); //provide list of temps & calculate to get average temp from user
void assignmentFourteen(); //create a random number game using a while loop

int main() {
	//assignmentTwelve();
	//assignmentThirteen();
	assignmentFourteen();
	return 0;
}

void assignmentTwelve() {
	//init vars
	int number;
	long fact = 1;

	//Get input from user
	cout << "Please input a positive number: ";
	cin >> number;
	
	//Check if this isn't a negative
	if (number < 0)
		cout << "This number is a negative." << endl;

	//Otherwise let's actually calculate the factorial number via a loop
	else {
		for (int i = 1; i <= number; ++i)
			fact *= i;
		cout << "Number inputted: " << number << "\nFactorial of number: " << fact << endl;
	}
}

void assignmentThirteen() {
	//init vars
	vector<double> temps = {};
	int n;
	double temp;
	double sum = 0.0;

	//Get input from user
	cout << "Input how much temps you want to add: ";
	cin >> n;
	
	//Loop through how many times user specified
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		cin >> temp;
		temps.push_back(temp);		
	}
	
	//Get sum
	for (double temp : temps)
		sum += temp;
	
	//calculate average and finally print the average
	double avg = sum / n;
	cout << "Average temperature: " << avg;
}

void assignmentFourteen() {
	//set random seed
	srand(time(NULL));
	//init vars
	int num = rand() % 100;
	int ans = 0;
	int hint = 0;
	int fails = 0;
	
	//Start the game
	cout << "Guess the secret number!" << endl;
	//"Game" logic
	while (ans != num) {
		//user input
		cout << "Your guess: ";
		cin >> ans;

		//end the game if the guess matches the number
		if (ans == num) {
			cout << "You won the game.\nSecret number is: " << num << "\nYou guessed: " << fails <<" times.";
			break;
		}
		//mismatch happened, game continues (also increment the guessed count)
		hint++;
		fails++;
		
		//May go overboard, punish the user anyway
		if (ans > 100)
			cout << "Input is way more than 100." << endl;

		//This shouldn't happen but it could so punish user regardless
		else if (ans < 0)
			cout << "Input is a negative." << endl;
		//In between, return default try again message.
		else
			cout << "Nope! Try again!" << endl;
		

		//Give hint to user every "ten" times
		if (hint == 10) {
			if (ans < num)
				cout << "Hint: The number is higher than your current guess." << endl;
			else
				cout << "Hint: The number is lower than your current guess." << endl;
			hint = 0;
		}
	}
}