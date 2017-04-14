#include <iostream>
#include <time.h>
#include <cmath>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"

using namespace std;

int dimension;
float weight1();
float weight23(int, vector<float>, vector<float>);

int main( int argc, char *argv[])
{
	if (argc != 5){
		printf("Incorrect number of parameters\n");
		return 0;
	}

	dimension = atoi(argv[4]);
	int numpoints = atoi(argv[2]);
	int numtrials = atoi(argv[3]);

	printf("\nINFO n = %i, dimensions = %i \n", numpoints, dimension);

	// number greater than the max possible edge length given dimension; will function as infinity
	float max_edge = ceil(sqrt(dimension)) + 1;

	srand((unsigned)time(NULL));

	vector< vector<float> > nodes;

	// create vector to store weight of each trial's MST
	vector<float> trial_weights(numtrials);

	// init MinHeap object
	MinHeap mh;

	// run Prim's numtrials times:
	for (int tr = 0; tr < numtrials; ++tr){		

		// create NxDim array, assign random vals for vertices
		if (dimension != 0) {
			nodes.clear();
			vector<float> verticeRow;

			for (int i = 0; i < numpoints; i++){
				for (int j = 0; j < dimension; j++){
					float new_coord = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					verticeRow.push_back(new_coord);
				}
				nodes.push_back(verticeRow);
				verticeRow.clear();
			}
		}

		// convert weight/coordinate arrays into a Leaf array with exception of 0th vertice, which will be root
		vector<Leaf> node_leaves;
		for (int j = 0; j < numpoints - 1; ++j){
			node_leaves.push_back(make_tuple(max_edge, j + 1));
		}

		mh.BuildHeap(node_leaves, numpoints - 1);

		// using first vertice (id: 0) as root, init prev & distance vectors
		vector<int> prev(numpoints, 0);
		prev[0] = -1;

		vector<float> dist(numpoints, -1);		
		dist[0] = 0;

		// decrease keys as necessary based on edges from root
		for (int i = 1; i < numpoints; ++i){
			if (dimension == 0) {
				float wght = weight1();
				mh.DecreaseKey(i, wght);
			} else {
				mh.DecreaseKey(i, weight23(dimension, nodes[0], nodes[i]));
			}
		}
		int counter = 0;
	
		while (!mh.IsEmpty()){
			// pop smallest edge from heap
			Leaf u = mh.ExtractMin();
			float u_wgt = get<0>(u);
			int u_id = get<1>(u);
			
			dist[u_id] = u_wgt;

			// for each node remaining in heap, update weight and prev per Prim's
			vector<int> remaining = mh.IDsRemaining();
			for (int i = 0; i < remaining.size(); i++){
				int v = remaining[i];
				bool swapped;
				if (dimension == 0) {
					float wght = weight1();
					swapped = mh.DecreaseKey(v, wght);
				} else {
					swapped = mh.DecreaseKey(v, weight23(dimension, nodes[u_id], nodes[v]));
				}
				if (swapped){
					prev[v] = u_id;
				}
			}
		}

		// add all edges to find MST weight
		float sum = accumulate(dist.begin(), dist.end(), 0.0f);
		trial_weights[tr] = sum;
		cout <<trial_weights[tr] << "\n";
	}
}


// for 0-dimension case, randomly generate weight between 0 and 1
float weight1(){
	return (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
}


// for n-dimension case, return weight given coordinates
float weight23(int dimension, vector<float> node1, vector<float> node2){
	float differences = 0;
	for (int i = 0; i < dimension; ++i){
		differences += pow((node1[i] - node2[i]), 2);
	}
	return sqrt(differences);	
}
