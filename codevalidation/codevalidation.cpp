using namespace std;
#include <string> //needed for string manipulation/methods
#include <vector> //needed to access the card numbers
#include <iostream> // needed for output
#include <iomanip> //needed for setw for formatting

bool isvalidcc(const string&);
int wantToDouble(int);

bool isvalidcc(const string& cardNum) 
{
	int rightSideStartIndex = cardNum.length(); //this is the index of the right most character
	int currentIndex = rightSideStartIndex;
	int sumOfEvens = 0;
	int sumOfOdds = 0;
	int randomStorage;

	for (int count = 1; currentIndex > 0; count++) 
	{
		currentIndex = rightSideStartIndex - count; //this sets the current index to the rightest index
		//cout << "current number being evaluated: "<< cardNum[currentIndex] << "\n";

		if ((count % 2) == 0) //this means the index is even
		{
			randomStorage = cardNum[currentIndex] - '0';
			sumOfEvens += (wantToDouble(randomStorage));
		}
		else //this means the index is odd
		{
			sumOfOdds += cardNum[currentIndex] - '0';
		}

	}
	//cout << (sumOfEvens + sumOfOdds);
	return ((sumOfEvens + sumOfOdds) % 10) == 0;
}

int wantToDouble(int checkThisInt) //checks whether or not the parameter is greater than 9 and then throws back the
{
	//cout << checkThisInt << "\n";
	checkThisInt = checkThisInt * 2;
	if (checkThisInt > 9) //if the doubled value of the even indexed number is greater than 9 take its indivual elements and add them
	{
		//cout << "This is when the int is greater than 9: "<< (checkThisInt % 10) + (checkThisInt / 10) << "\n";
		return (checkThisInt%10) + (checkThisInt/10);
	}
	return checkThisInt;
}

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};
	/*vector<string> cardnumbers = {
		 "4388576018402626"
	};*/

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}