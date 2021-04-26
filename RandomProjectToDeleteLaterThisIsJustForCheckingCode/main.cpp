#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>

using namespace std;

int x = 1, y = -1;
void swapplus1(int n1, int n2) {
	int temp = n1 + 1;
	n1 = n2 - 1;
	n2 = temp;
	x = x + n1;
}
void swapplus2(int& n1, int& n2) {
	int temp = n1 + 1;
	n1 = n2 - 1;
	n2 = temp;
}
void swapplus3(const int& n1, const int& n2) {
	int n1val, n2val, temp = n1 + 1;
	n1val = n2 - 1;
	n2val = temp;
	y -= n2;
}
void swapplus4(int* p1, int* p2) {
	int temp = *p1 + 1;
	*p1 = *p2 + 1;
	*p2 = temp;
	x = *p1 + y;
}
void swapplus5(int*& p1, int*& p2) {
	int* temp = p1 + 1;
	p1 = p2 - 1;
	p2 = temp;
}
void print(const int& x, const int& y) {
	cout << "\n x: " << x << " |y: " << y;
}
int main() {
	int arr[]{ 2, 4, 6, 8, 10, 12, 14 };
	y = arr[3] / size(arr);
	cout << y << endl;
	swapplus1(x, y); print(x, y);
	swapplus2(x, y); print(x, y);
	swapplus3(x, y); print(x, y);
	swapplus4(&x, &y); print(x, y);
	int* px = &x, * py = &y;
	(*px)--;
	(*py) -= -7;
	swapplus5(px, py); print(x, y);

	int year = 2019;
	int yearNext = 2020;
	int& ref = year;
	ref = yearNext; 


	return 0;
}