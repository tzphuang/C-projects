#include <iostream>;
#include <string>;
using namespace std;
/*
class Name {
public:
	Name() {}
	Name(string name) {
		this->name = name;
	}
	~Name() {
		cout << this->name << ": Destructor called." << endl;
	}
	string getName() const {
		return this->name;
	}
private:
	string name{ "N/A" };
};
void passByMove(const unique_ptr<Name> uPtr_M) {
	cout << "@uPtr_M: " << uPtr_M << endl;
	cout << "getName(): " << uPtr_M->getName() << endl;
}
void passByRef(const unique_ptr<Name>& uPtr_R) {
	cout << "@uPtr_R: " << uPtr_R << endl;
	cout << "getName(): " << uPtr_R->getName() << endl;
}
void passByShare(const shared_ptr<Name> sPtr_S) {
	cout << "@sPtr_S: " << sPtr_S << endl;
	cout << "getName(): " << sPtr_S->getName() << endl;
	cout << "use_count(): " << sPtr_S.use_count() << endl;
}
Name* passByValue(const unique_ptr<Name> uPtr_V) {
	cout << "@uPtr_V: " << uPtr_V << endl;
	cout << "getName(): " << uPtr_V->getName() << endl;
	return uPtr_V.get();
}
int main() {
	cout << passByValue(make_unique<Name>("Goofy")) << endl;
	unique_ptr<Name> uPtr{ make_unique<Name>("Mickey") };
	passByRef(uPtr);
	cout << "name_uPtr: " << uPtr << endl;
	passByMove(move(uPtr));
	cout << "name_uPtr: " << uPtr << endl;
	uPtr = make_unique<Name>("Minnie");
	shared_ptr<Name> sPtr{ uPtr.release() };
	passByShare(sPtr);
	cout << "END of Program" << endl;
	return 0;
}*/int funcB(int);
int funcA(int n) {
	if (n <= 1)
		return 217;
	else
		return n + funcB(n - 2);
}
int funcB(int n) {
	if (n <= 2) {
		return 3;
	}
	else {
		if (n > 4) {
			return n * funcA(n - 5);
		}
		else {
			return n - funcB(n - 1);
		}
	}
}
int main() {
	cout << funcA(13);
	return 0;
}