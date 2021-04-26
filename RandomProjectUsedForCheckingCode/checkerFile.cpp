#include <fstream>//file stream for reading file
#include <cstdlib>//used for checking whether a file is open or not
#include <iostream>//input/output stream
#include <string>//string library
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void messWithDictionary(unordered_multimap <string, pair<string, string> >&);

void messWithDictionary(unordered_multimap <string, pair<string, string> > &currDictionary) {
	string dictionaryWord = "arrow";
	pair<string, string> POSAndDefinition = make_pair("noun", "Here is one arrow: -=>>.");
	currDictionary.insert(make_pair(dictionaryWord, POSAndDefinition));

	/*for (auto dictIterator = currDictionary.begin(); dictIterator != currDictionary.end(); dictIterator++) {
		cout << dictIterator->first << " [" << dictIterator->second.first << "] : " << dictIterator->second.second << endl;
	}*/
}

int main()
{
	/*
	//loadData();
	//string dictionaryWord= "arrow";
	//pair<string, string> POSAndDefinition = make_pair("noun", "Here is one arrow: -=>>.");
	unordered_multimap <string, pair<string, string> > dictionary;
	//dictionary.insert(make_pair(dictionaryWord, POSAndDefinition));
	messWithDictionary(dictionary);

	for (auto dictIterator = dictionary.begin(); dictIterator != dictionary.end(); dictIterator++) {
		cout << dictIterator->first << " [" << dictIterator->second.first << "] : " << dictIterator->second.second << endl;
	}

	vector<string> stringVectors =
	{
	"Distinct[noun] : Distinct was in ASMT 01 as a parameter.",
	"Distinct[noun] : An advanced search option.",
	"Distinct[noun] : A keyword in this assignment.",
	"Distinct[noun] : A keyword in this assignment.",
	"Distinct[noun] : A keyword in this assignment.",
	"Distinct[adverb] : Uniquely.Written \"distinctly\".",
	"Distinct[adjective] : Unique.No duplicates.Clearly different or of a different kind.",
	"Distinct [adjective] : Familiar. Worked in Java."
	};

	for (int index = 0; index < stringVectors.size();index++)
	{
		cout << stringVectors[index] << endl;
	}

	sort(stringVectors.begin(), stringVectors.end());
	cout << "----------------------THIS IS NOW SORTED-------------------" << endl;

	for (int index = 0; index < stringVectors.size();index++)
	{
		cout << stringVectors[index] << endl;
	}*/
	//MultiMap of char and int
	std::multimap<char, int> mmapOfPos = {
		{'a', 1},
		{'b', 2},
		{'c', 3},
		{'a', 4},
		{'c', 5},
		{'c', 6},
		{'d', 7},
	};

	typedef std::multimap<char, int>::iterator MMAPIterator;

	// It returns a pair representing the range of elements with key equal to 'c'
	std::pair<MMAPIterator, MMAPIterator> result = mmapOfPos.equal_range('c');

	std::cout << "All values for key 'c' are," << std::endl;

	// Iterate over the range
	for (MMAPIterator it = result.first; it != result.second; it++)
		std::cout << it->second << std::endl;

	// Total Elements in the range
	int count = std::distance(result.first, result.second);
	std::cout << "Total values for key 'c' are : " << count << std::endl;

	/*for (auto dictIterator = mmapOfPos.begin(); dictIterator != mmapOfPos.end(); dictIterator++) {
		cout << dictIterator << endl;
	}*/
	//cout << mmapOfPos['c'] << endl;

	return 0;


}
