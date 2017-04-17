#include <iostream>
#include <time.h>
#include <cmath>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include "max_heap.h"
#include <stdint.h>
#include <random>
#include <fstream>
#include <cstdlib>

using namespace std;

int main( int argc, char *argv[])
{

	int size = 5;

	if (argc != 2){
		printf("Incorrect number of parameters\n");
		return 0;
	}

	char* inpt = argv[1];
	ifstream infile(inpt);
	string str;

	vector<unsigned long long> x (size, 0);

	// add integers to vector
	for (int i = 0; i < size; i++){
		infile >> str;
		x[i] = atoi(str.c_str());
	}

	// random number generator
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned long long> dis(0, 1000000000000);

	// init MaxHeap object
	MaxHeap mh;

	mh.BuildHeap(x, size);

	mh.PrintHeap();



	for (int i = 0; i < size-1; i++){
		unsigned long long max_1 = mh.ExtractMax();
		unsigned long long max_2 = mh.ExtractMax();
		unsigned long long diff;
		if (max_1>max_2){
			diff = max_1-max_2;
		}
		else {
			diff = max_2-max_1;
		}
		mh.Insert(diff);
		mh.PrintHeap();
	}
	mh.PrintHeap();
	unsigned long long max_1 = mh.ExtractMax();
	printf("num: %llu \n", max_1);
}