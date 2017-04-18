#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main () {

	ofstream myfile;
	myfile.open ("nums.txt");
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<signed long long> dis(0, 1000000000000);
	for (int i = 0; i < 100; i++){
		signed long long x = dis(gen);
		myfile << x << "\n";
	}
	
	myfile.close();
	return 0;
}