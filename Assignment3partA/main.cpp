#include <iostream>
#include <string>
using namespace std;

/*
	"if a is a pointer that points to some value, *a is how you access that value
	kind of like
	a pointer is like a mailbox and *is the key that lets you open the mailbox and get the mail out
	or rather a storage container"
*/

class Chair {
public: 
	Chair(); // default constructor
	Chair(const string &, const int &); //implicit constructor
	
	~Chair(); //destructor? i think?

	string getType() const;
	int getNumberLegs() const;
	void setTypeandLegs(const string&, const int&);

private:
	string typeChair{ "N/A" };
	int numberLegs{ 4 };
};

Chair::Chair() {}
Chair::Chair(const string & typeChair, const int & numberLegs)
	: typeChair(typeChair), numberLegs(numberLegs) {

}

Chair::~Chair() { //default destructor method trying to use "big 5" implementation with destructor with a unique destructor
	cout << "This is the Chair Destructor. Address being deleted: " << this << ", " << "object type being deleted: "<< this->getType() << endl;
}

string Chair::getType() const {
	return this->typeChair;
}

int Chair::getNumberLegs() const {
	return this->numberLegs;
}

void Chair::setTypeandLegs(const string& typeChair, const int& numberLegs) {
	this->typeChair = typeChair;
	this->numberLegs = numberLegs;
}

class Leg {
public:
	Leg(); //default constructor

	~Leg(); //destructor

private:
	unique_ptr<Chair> chair1{ make_unique<Chair>("Wooden", 4) };
	string typeLeg{"I'm a Leg!"}; //the string constructor {"insert quote here"}

};
Leg::Leg() {}

Leg::~Leg() { //default destructor method trying to use "big 5" implementation with destructor with a unique destructor
	cout << "This is the Leg Destructor. Address being deleted: " << this << endl;
}




void partA2() 
{
	unique_ptr<int> uniquePTR1 = make_unique<int>(5);
	cout << uniquePTR1.get() << endl;
}

int main()
{
	/*
	string objectGetsDeletedx2 = "this will be deleted twice";

	string* stringPTR1 = new string;
	stringPTR1 = &objectGetsDeletedx2;

	string* stringPTR2 = new string;
	stringPTR2 = &objectGetsDeletedx2;

	string* stringPTR3 = new string;
	*stringPTR3 = objectGetsDeletedx2;
	// this dereferences the pointer so it would "store" the information
	// for the objectGetsDeletedx2; in this case 
	// it would store the address holding "this will be deleted twice"

	cout << &objectGetsDeletedx2 << endl;
	cout << stringPTR1 << endl;
	cout << stringPTR2 << endl;
	cout << *stringPTR2 << endl;
	// all the above have the same address meaning
	// this was set up correctly 
	// where we have one object and two pointers pointing at that object
	cout << stringPTR3 << endl;
	//ptr3 has a different address than ptr1/ptr2
	//but it still references the "objectGetsDeletedx2" addresss
	cout << *stringPTR3 << endl;

	delete stringPTR1; //causes problem fix later
	stringPTR1 = nullptr;
	cout << stringPTR1 << endl;

	unique_ptr<int[]> intArray1(new int[3]);
	intArray1[0] = 1;
	intArray1[1] = 2;
	intArray1[2] = 3;
	//cout << sizeof(intArray1)/sizeof(intArray1[0]) << endl;
	for (int count = 0; count < 3; count++)
	{
		cout << intArray1[count] << endl;
	}

	*/


	// Part A - 1
	cout << "This is part A - 1 \n" << endl;
	int* intPTR1 = new int(25);
	int* intPTR2 = intPTR1;

	cout << "The address inside intPTR1 is: " << intPTR1 << endl;
	cout << "The address inside intPTR2 is: " << intPTR2 << endl;
	//the above pointers point to the same address which should be the address of int(25)

	cout << "Inside the intptr1 address is: " << *intPTR1 << endl;
	cout << "Inside the intptr2 address is: " << *intPTR2 << endl;
	// this is just to clarify that they actually hold the same object

	delete intPTR1;
	cout << "the thing intPTR1 has been pointing to has now been deleted" << endl;
	intPTR1 = nullptr;
	cout << "intPTR1 has been set to nullptr" << endl;
	cout << "intPTR1 is pointing to: " << intPTR1 << endl;
	cout << "intPTR2 is pointing to: " << intPTR2 << endl;
	cout << "Inside the intptr2 address is: " << *intPTR2 << endl;
	//delete intPTR2; //this crashes the program
	cout << "the thing intPTR2 has been pointing to has now been deleted" << endl;
	intPTR2 = nullptr;
	cout << "intPTR2 has been set to nullptr" << endl;
	cout << "intPTR2 is pointing to: " << intPTR2 << endl;

	cout << "This is the end of part A - 1\n" << endl;

	/*
	
	1. is straight forward.
	2. use this https://www.internalpointers.com/post/beginner-s-look-smart-pointers-modern-c as a reference.
	3. use the above to make an example where data members of classes have smart pointers.
	4. straight forward.
	5. https://stackoverflow.com/questions/12030650/when-is-stdweak-ptr-useful
	
	*/


	// Part A - 2
	cout << "This is part A - 2 \n" << endl;
	{
		unique_ptr<Chair> chair1{ make_unique<Chair>("Wooden", 4) };
		cout << "chair1, unique_ptr address: " << &chair1 << endl;
		cout << "chair1, unique_ptr value (essentially what's inside the address the pointer holds): " << chair1 << endl;
		cout << "chair1, unique_ptr, currently owned object's address: " << chair1.get() << endl;
	}
	cout << "This is the end of part A - 2\n" << endl;
	//cout << "chair1, unique_ptr address: " << &chair1 << endl;
	//since chair1 was inside the block above, it is now deleted since
	//the block has ended, this meaning the deconstructor was called
	//and the unqiue pointer/address of object is both gone

	// Part A - 3
	cout << "This is part A - 3 \n" << endl;
	{
		unique_ptr<Leg> leg1{ make_unique<Leg>() };
	}
	cout << "This is the end of part A - 3\n" << endl;
	//here we have the leg class being called that has a unique pointer
	//that points to a chair class object
	//once the destructor is called at the end of this block
	//the leg destruct is first called
	//then the chair constructor is called since it has a unique pointer
	//pointing to it

	// Part A - 4
	cout << "This is part A - 4 \n" << endl;
	{
		unique_ptr<Chair> chair1{ make_unique<Chair>("Wooden", 4) };
		shared_ptr<Chair> chair1_shared{ move(chair1) };
		if (chair1_shared.unique())
		{
			cout << "chair1_shared is the only shared pointer for its object." << endl;
		}
		else
		{
			cout << "chair1_shared is not the only shared pointer for its object, as it is shared with another shared pointer." << endl;
		}
	}
	cout << "This is the end of part A - 4\n" << endl;

	// Part A - 5
	cout << "This is part A - 5 \n" << endl;
	{
		shared_ptr<Chair> shared_chair2{ make_unique<Chair>("Office", 5) };
		weak_ptr<Chair> weak_chair2{ shared_chair2 };
		cout << (weak_chair2.expired() ? "Weak pointer object has expired." : "Weak pointer object has not expired.") << endl;
		shared_chair2.reset();
		cout << (weak_chair2.expired() ? "Weak pointer object has expired." : "Weak pointer object has not expired.") << endl;
	}
	cout << "This is the end of part A - 5\n" << endl;

	return 0;
}