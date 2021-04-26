#include <fstream>//file stream for reading file
#include <cstdlib>//used for checking whether a file is open or not
#include <iostream>//input/output stream
#include <string>//string library
#include <map>
#include <unordered_map> //used for dictionary
#include <vector> //used to store strings
#include <locale> //used for tolower()
#include <algorithm> //used to sort the vector of strings

using namespace std;

void loadData(unordered_multimap <string, pair<string, string> > &);
void breakDownString(unordered_multimap <string, pair<string, string> > &, const string&);
void searchThruDict(unordered_multimap <string, pair<string, string> >&);
vector<string> splitThisString(string);
void printResultsOfSearch(unordered_multimap <string, pair<string, string> >&, vector<string>, bool);
bool checkIfDistinct(vector<string>);
string stringToLower(string);
bool checkPartOfSpeech(string);
void makeVectorDistinct(vector<string> &);

void loadData(unordered_multimap <string, pair<string, string> > &currDict) {
	string nextLine;
	fstream fileReader;
	fileReader.open("Data.CS.SFSU.txt"); //tries to open the file if it is in the same directory
	
	if (!fileReader.is_open()) // if the file is NOT open, the program will exit entirely
	{
		exit(EXIT_FAILURE);
	}

	cout << "Opening data file... ./Data.CS.SFSU.txt" << endl;
	cout << "! Loading data..." << endl;
	while (getline(fileReader, nextLine)) // loops through the entire file and sends each line to be processed by method "breakDownDefinition"
	{

		breakDownString(currDict,nextLine);
	}
	cout << "! Loading completed..." << endl;
	cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
	fileReader.close();
}

void breakDownString(unordered_multimap <string, pair<string, string> > &currDict, const string& currLine)  //takes an entire line from the file then breaks it down to a collection of "word" and "part of speech/definitions"
{
	int positionIndex; //used to keep position of .find
	string currDictWord; //used to store dictionary word of that line
	string dictWordDefs; //current line after the first word (first word being the dictionary word)
	string currPOS; //current part of speech
	string currDef; //current definition
	bool keepScanning = true; //set to true so you will have to enter the while loop at least once to grab a definition
	pair<string, string> POSAndDefinition; //created to store the part of speech /definition together

	positionIndex = currLine.find("|");
	currDictWord = currLine.substr(0, positionIndex); //gets only the dictionary word
	dictWordDefs = currLine.substr(positionIndex+1); //gets current line's part of speech/definitions

	//cout << currDictWord << endl;

	while (keepScanning) 
	{
		// this would be the start of finding the next part of speech in the current line
		positionIndex = dictWordDefs.find(" ");
		currPOS = dictWordDefs.substr(0, positionIndex);
		//cout << currPOS << " 1 " << endl;
		positionIndex += 6;
		dictWordDefs = dictWordDefs.substr(positionIndex);

		// this would be the start of finding the next definition that goes with the previous part of speech obtained
		if (dictWordDefs.find(".|") == -1) 
			//dictWordDefs.find(".|") when this does NOT find ".|" it returns -1
			//this means that there is no more definitions left in the string
			//and if there is no more definitions left in the string, we grab the last definition and set the while loop to false
		{
			currDef = dictWordDefs;
			//cout << currDef << " 3 " << endl;
			keepScanning = false;
		}
		else 
			//if there is still a ".|" we can be assured that there are definitions left
			//this means we must still scan through carefully through the rest of the string
		{
			positionIndex = dictWordDefs.find("|");
			currDef = dictWordDefs.substr(0, positionIndex);
			//cout << currDef << " 2 " << endl;
			dictWordDefs = dictWordDefs.substr(positionIndex + 1);
		}

		POSAndDefinition = make_pair(currPOS, currDef);
		currDict.insert(make_pair(currDictWord, POSAndDefinition));

	}

	//cout << "______________done with this word______________" << endl;

}

void searchThruDict(unordered_multimap <string, pair<string, string> >& currDict) {
	bool continueSearch = true;
	bool isItDistinct;
	string keyboardInput;
	vector<string> vecSplitString;


	cout << "\n----- DICTIONARY 340 C++ -----" << endl;

	while (continueSearch) 
	{
		cout << "Search: ";
		getline(cin, keyboardInput);
		keyboardInput = stringToLower(keyboardInput);
		if (keyboardInput.compare("!q") == 0) 
		{
			continueSearch = false;
		}
		else 
		{
			vecSplitString = splitThisString(keyboardInput);
			isItDistinct = checkIfDistinct(vecSplitString);
			printResultsOfSearch(currDict, vecSplitString, isItDistinct);
			/*if (currDict.count(vecSplitString[0]) != 0) {
				cout << "It is in the dictionary +1" << endl;
			}
			else {
				cout << "NOT in the dictionary" << endl;
			}*/
		}
		/*for (int index = 0; index < vecSplitString.size();index++) {
			cout << vecSplitString[index] << endl;
		}*/
	}
}

vector<string> splitThisString(string randomLine) //splits the string by spaces and stores each element inside the vector to be returned
{
	vector<string> returnVector;
	bool continueSplitting = true;

	while (continueSplitting) 
	{
		if (randomLine.find(" ") == -1)
		{
			continueSplitting = false;
			returnVector.push_back(randomLine);
		}
		else
		{
			returnVector.push_back(randomLine.substr(0, randomLine.find(" ")));
			randomLine = randomLine.substr(randomLine.find(" ") + 1);
		}
	}
	return returnVector;
}

string stringToLower(string inputString) //takes a string, and returns that string in lowercase form
{
	string returnString;
	locale yes;
	for (int index = 0; index < inputString.length();index++)
	{
		returnString += tolower(inputString[index], yes);
	}
	return returnString;
}

bool checkIfDistinct(vector<string> inputVec) //checks whether the string vector's elements have the word "distinct" and returns true if so
{
	bool isDistinct = false;

	for (int index = 1; index < inputVec.size(); index++) { //starts at index 1 since only the second/third element can be "distinct" 
		if (inputVec[index].compare("distinct") == 0) //this means that the current vector element is equal to "distinct"
		{
			isDistinct = true;
			return isDistinct;
		}
	}

	return isDistinct;
}


void printResultsOfSearch(unordered_multimap <string, pair<string, string> >& currDict, vector<string> inputVec, bool isItDistinct)
{
	bool POSIsOk; //this is for whether or not the part of speeches are written correctly in the second spot
	vector<string> dictionaryStorage4Printing; //this is to store any lines of definitions with respect to search parameters
	string makeShiftDefinition;

	//POSIsOk = checkPartOfSpeech();
	//if (currDict.count(inputVec[0]) != 0 && POSIsOk) {
	//
	//}

	if (inputVec.size() == 3 && currDict.count(inputVec[0]) != 0) // this is for 3 worded inputs
	{
		POSIsOk = checkPartOfSpeech(inputVec[1]); //takes the input vector and checks the 2nd word if its a part of speech
		if(POSIsOk == false)
		{
			dictionaryStorage4Printing.push_back("	<2nd argument must be a part of speech or \"distinct\">\n");
		}
		else if (POSIsOk && isItDistinct) //all conditions clear to search for word
		{
			for (auto dictIterator = currDict.begin(); dictIterator != currDict.end(); dictIterator++) 
				//loops through entire dictionary pushing onto vector "dictionaryStorage4Printing" only the definitions that have equal "words/part of speech" to our input
			{
				if ((dictIterator->first).compare(inputVec[0]) == 0 && (dictIterator->second.first).compare(inputVec[1]) == 0)
				{
					makeShiftDefinition = dictIterator->first + " [" + dictIterator->second.first + "] : " + dictIterator->second.second + "\n";
					dictionaryStorage4Printing.push_back(makeShiftDefinition);
				}
			}
		}
		else
		{
			dictionaryStorage4Printing.push_back("	<Not found>\n");
		}
	}
	else if (inputVec.size() == 2 && currDict.count(inputVec[0]) != 0) // this is for 2 worded inputs
	{
		POSIsOk = checkPartOfSpeech(inputVec[1]); //takes the input vector and checks the 2nd word if its a part of speech


		if (POSIsOk == false && isItDistinct == false) //if the second word is not a part of speech/"distinct" push this string onto vector
		{
			dictionaryStorage4Printing.push_back("	<2nd argument must be a part of speech or \"distinct\">\n");
		}
		else if(POSIsOk == true && isItDistinct == false) //second word from input must be a part of speech
		{
			for (auto dictIterator = currDict.begin(); dictIterator != currDict.end(); dictIterator++)
				//loops through entire dictionary pushing onto vector "dictionaryStorage4Printing" only the definitions that have equal "words/part of speech" to our input
			{
				if ((dictIterator->first).compare(inputVec[0]) == 0 && (dictIterator->second.first).compare(inputVec[1]) == 0)
				{
					makeShiftDefinition = dictIterator->first + " [" + dictIterator->second.first + "] : " + dictIterator->second.second + "\n";
					dictionaryStorage4Printing.push_back(makeShiftDefinition);
				}
			}
		}
		else if (POSIsOk == false && isItDistinct == true) //second word from input must be "distinct"
		{
			for (auto dictIterator = currDict.begin(); dictIterator != currDict.end(); dictIterator++)
				//loops through entire dictionary pushing onto vector "dictionaryStorage4Printing" only the definitions that have equal "words/part of speech" to our input
			{
				if ((dictIterator->first).compare(inputVec[0]) == 0)
				{
					makeShiftDefinition = dictIterator->first + " [" + dictIterator->second.first + "] : " + dictIterator->second.second + "\n";
					dictionaryStorage4Printing.push_back(makeShiftDefinition);
				}
			}
		}
		else { // there should be no way the second word in the input can be a part of speech AND "distinct" to trigger this else statement but it is here anyways
			dictionaryStorage4Printing.push_back("	<Not found>\n");
		}
	}
	else if (inputVec.size() == 1 && currDict.count(inputVec[0]) != 0) // this is for 1 worded inputs
	{
		for (auto dictIterator = currDict.begin(); dictIterator != currDict.end(); dictIterator++)
			//loops through entire dictionary pushing onto vector "dictionaryStorage4Printing" only the definitions that have equal "words/part of speech" to our input
		{
			if ((dictIterator->first).compare(inputVec[0]) == 0)
			{
				makeShiftDefinition = dictIterator->first + " [" + dictIterator->second.first + "] : " + dictIterator->second.second + "\n";
				dictionaryStorage4Printing.push_back(makeShiftDefinition);
			}
		}
	}
	else 
		// if the size of the input is not correct this is a catch all else statement to give the user a "<Not found>"
		// this also triggers if the first word in the input for any size is not found in the dictionary
	{
		dictionaryStorage4Printing.push_back("	<Not found>\n");
	}

	//this sorts the string vector so it is in alphabetical order
	sort(dictionaryStorage4Printing.begin(), dictionaryStorage4Printing.end());

	if (dictionaryStorage4Printing.empty()) {
		dictionaryStorage4Printing.push_back("	<Not found>\n");
	}

	// here I call a function to get rid of copies if boolean isItDistinct is true
	if (isItDistinct) {
		makeVectorDistinct(dictionaryStorage4Printing);
	}

	cout << "	|" << endl;

	for (int index = 0; index < dictionaryStorage4Printing.size();index++) {
		if (dictionaryStorage4Printing[index].substr(0,3).compare("csc") == 0)
		{
			cout << "CSC" << dictionaryStorage4Printing[index].substr(3);
		}
		else 
		{
			cout << dictionaryStorage4Printing[index];
		}
	}

	cout << "	|" << endl;

}

void makeVectorDistinct(vector<string> &inputVector) {
	int indexPrevious = 0;
	string previousString = "";

	for (int index = 0; index < inputVector.size();index++) 
	{
		if (inputVector[index].compare(previousString) == 0)
			//if the current string is equal to the previous string
			//erase the current string out of the vector
		{
			inputVector.erase(inputVector.begin()+index);
			index--;
		}
		else {
			previousString = inputVector[index];
		}
	}
}

bool checkPartOfSpeech(string currPOS) 
{
	bool returnCheck = false;

	if (currPOS.compare("noun") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("verb") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("adjective") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("adverb") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("pronoun") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("preposition") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("conjunction") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("interjection") == 0) {
		returnCheck = true;
	}
	else if (currPOS.compare("article") == 0) {
		returnCheck = true;
	}

	return returnCheck;
}

int main()
{
	unordered_multimap <string, pair<string, string> > dictionary;

	loadData(dictionary);
	searchThruDict(dictionary);
	cout << "\n-----THANK YOU-----" << endl;
	
	/*for (auto dictIterator = dictionary.begin(); dictIterator != dictionary.end(); dictIterator++) {
		cout << dictIterator->first << " [" << dictIterator->second.first << "] : " << dictIterator->second.second << endl;
	}*/
	return 0;
}
