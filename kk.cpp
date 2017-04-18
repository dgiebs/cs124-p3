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
#include <limits>
#include <math.h>

using namespace std;

// random numbers are generated throughout the program and its helper functions
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> s_rand(0, 1);
uniform_int_distribution<signed long long> dis(0, 1000000000000);

int method_a_1(vector<signed long long>, int);
int method_a_2(vector<signed long long>, int);
int method_a_3(vector<signed long long>, int);
signed long long kk(vector<signed long long>);

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

	vector<signed long long> x (size, 0);

	// add integers to vector
	for (int i = 0; i < size; i++){
		infile >> str;
		x[i] = atoi(str.c_str());
	}

	int a_1 = method_a_1(x, 25000);
	int a_2 = method_a_2(x, 25000);
	int a_3 = method_a_3(x, 25000);
	signed long long pure_kk = kk(x);
	printf("a_1 : %i \na_2 : %i \na_3: %i \npure kk: %lli \n", a_1, a_2, a_3, pure_kk);
}

int method_a_1(vector<signed long long> x, int iterations){

	vector<int> s (x.size(), 0);
	int residue = numeric_limits<int>::max();
	for (int i = 0; i < iterations; ++i){
		
		for (int j = 0; j < s.size(); ++j){
			s[j] = s_rand(gen);
			if (s[j] == 0){
				s[j] = -1;
			}
		}
		int tmp_residue = 0;
		for (int j = 0; j < x.size(); ++j){
			tmp_residue += s[j]*x[j];
		}
		tmp_residue = abs(tmp_residue);
		if (tmp_residue < residue){
			residue = tmp_residue;
		}
	}
	return residue;
}

int method_a_2(vector<signed long long> x, int iterations){

    uniform_int_distribution<> rand_idx(0, x.size()-1);
	vector<int> s (x.size(), 0);
	for (int j = 0; j < s.size(); ++j){
		s[j] = s_rand(gen);
		if (s[j] == 0){
			s[j] = -1;
		}
	}
	int residue = 0;
	for (int j = 0; j < x.size(); ++j){
		residue += s[j]*x[j];
	}

	for (int i = 0; i < iterations; ++i){

		int s_i = rand_idx(gen);
		int s_j;
		//make sure j != i
		do {
			s_j = rand_idx(gen);
		} while (s_i == s_j);

		// following the algorithm-flip 1 or two elements of S
		int choosing = s_rand(gen);
		int temp_residue = residue - 2*s[s_i]*x[s_i];
		if (choosing == 0){
			temp_residue -= 2*s[s_j]*x[s_j];
		}
		// if its a smaller residue, change s
		if (abs(temp_residue)<abs(residue)){
			s[s_i] = -s[s_i];
			if (choosing == 0){
				s[s_j] = -s[s_j];
			}
			residue = temp_residue;
		}
	}
	return abs(residue);
}

int method_a_3(vector<signed long long> x, int iterations){

    uniform_int_distribution<> rand_idx(0, x.size()-1);

	vector<int> s (x.size(), 0);
	for (int j = 0; j < s.size(); ++j){
		s[j] = s_rand(gen);
		if (s[j] == 0){
			s[j] = -1;
		}
	}

	int residue = 0;
	for (int j = 0; j < x.size(); ++j){
		residue += s[j]*x[j];
	}

	int residue_orig = residue;

	for (int i = 0; i < iterations; ++i){
		// for (int j = 0; j < x.size(); ++j){
		// 	printf("%i ", s[j]);
		// }
		// printf("\n");
		int s_i = rand_idx(gen);
		int s_j;
		//make sure j != i
		do {
			s_j = rand_idx(gen);
		} while (s_i == s_j);

		// following the algorithm-flip 1 or two elements of S
		int choosing = s_rand(gen);
		int temp_residue = residue - 2*s[s_i]*x[s_i];
		// 1/2 chance you change 2
		if (choosing == 0){
			temp_residue -= 2*s[s_j]*x[s_j];
		}
		// if its a smaller residue, change s
		if (abs(temp_residue)<abs(residue)){
			s[s_i] = -s[s_i];
			if (choosing == 0){
				s[s_j] = -s[s_j];
			}
			residue = temp_residue;
		}
		else{
			// "temperature" function
			float t_iter = 10000000000*pow(0.8, floor(i/300));
			float p = exp (-(abs(temp_residue)-abs(residue))/t_iter);
			bernoulli_distribution bern(p);
			bool anneal = bern(gen);
			if (anneal) {
				// printf("chosen \n");
				s[s_i] = -s[s_i];
				if (choosing == 0){
					s[s_j] = -s[s_j];
				}
				residue = temp_residue;
			}
		}

		if (abs(residue)<abs(residue_orig)){
			residue_orig = residue;
		}
	}
	return abs(residue_orig);
}

signed long long kk(vector<signed long long> x){
	// init MaxHeap object
	MaxHeap mh;

	mh.BuildHeap(x, x.size());

	for (int i = 0; i < x.size()-1; i++){
		signed long long max_1 = mh.ExtractMax();
		signed long long max_2 = mh.ExtractMax();
		signed long long diff;
		if (max_1>max_2){
			diff = max_1-max_2;
		}
		else {
			diff = max_2-max_1;
		}
		mh.Insert(diff);
	}
	signed long long final = mh.ExtractMax();
	return final;
}

int vec_prime(vector<signed long long> x, vector<signed long long> p)
{
	vector<int> x_prime (size, 0);
	int residue = numeric_limits<int>::max();
	for (int i = 0; i < size; ++i){
		x_prime[i] = 

		for (int j = 0; j < s.size(); ++j){
			s[j] = s_rand(gen);
			if (s[j] == 0){
				s[j] = -1;
			}
		}
		int tmp_residue = 0;
		for (int j = 0; j < x.size(); ++j){
			tmp_residue += s[j]*x[j];
		}
		tmp_residue = abs(tmp_residue);
		if (tmp_residue < residue){
			residue = tmp_residue;
		}
	}
	return residue;
}

int method_b_2(vector<signed long long>, int)
{

}

int method_b_3(vector<signed long long>, int)
{

}