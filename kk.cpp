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

using namespace std;

int main( int argc, char *argv[])
{

	int size = 100;

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

	vector<Leaf> node_leaves;
	for (int i = 0; i < size; i++){
		node_leaves.push_back(make_tuple(x[i], i + 1));
	}

	mh.BuildHeap(node_leaves, size);

	mh.PrintHeap();

	for (int i = 0; i < size; i++){
		Leaf tmp = mh.ExtractMax();
		printf("num: %llu \n", get<0>(tmp));
	}
}