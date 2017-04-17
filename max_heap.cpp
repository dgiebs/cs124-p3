#include <cmath>
#include <iostream>
#include "max_heap.h"
#include <vector>

using namespace std;

void MaxHeap::BuildHeap(vector<signed long long> nodes, int length){

	for (int i = 0; i < length; ++i){
		// copy nodes into heap
		_heap.push_back(nodes[i]);
	}

	Heapify();
}

void MaxHeap::Heapify(){
	int length = _heap.size();
	for (int i = length - 1; i >= 0; --i){
		HeapDown(i);
	}
}

void MaxHeap::HeapDown(int index){
	int length = _heap.size();
	int smallestChild = D * index + 1;
	int largestChild = D * index + D;

	// check if current node is a leaf
	if (largestChild > length){
		return;
	}

	// locate smallest of node and its D children
	int lowest = index;

	for (int i = smallestChild; i <= min(largestChild, length - 1); i++){
		if (_heap[lowest] < _heap[i]){
			lowest = i;
		}
	}

	// swap if necessary
	if (lowest != index){
		swap(_heap[index], _heap[lowest]);
		// perform any swaps needed further down tree
		HeapDown(lowest);
	}
}

void MaxHeap::HeapUp(int index){
	int parent = (int) floor((index - 1) / D);

	// check whether swap is necessary
	if (_heap[parent] < _heap[index]){
		// update indexmap
		swap(_heap[index], _heap[parent]);
        HeapUp(parent);

	} else {
		// once finishes one call without a swap, everything above is correct
		return;
	}
}

signed long long MaxHeap::Peek(){
	return _heap[0];
}

signed long long MaxHeap::ExtractMax(){
	int length = _heap.size();

	if (length == 0){
		return 0;
	}
	signed long long temp = _heap[0];

	_heap[0] = _heap[length-1];
	_heap.pop_back();
	HeapDown(0);
	return temp;
}

void MaxHeap::Insert(signed long long n){
    int length = _heap.size();
    _heap.push_back(n);

    HeapUp(length);
}


// useful method for debugging
void MaxHeap::PrintHeap(){
	for (int i = 0; i < _heap.size(); i++){
		cout << _heap[i] << "  ";
	}
	// cout << "\nIndexMap: ";
	// for (int j = 0; j < _indexmap.size(); ++j){
	// 	cout << j << ": " << _indexmap[j] << ", ";
	// }
	// cout << "\nRemaining: ";
	// vector<int> remaining = IDsRemaining();
	// for (int k = 0; k < remaining.size(); ++k){
	// 	cout << remaining[k] << ", ";
	// }
	cout << "\n";
}

bool MaxHeap::IsEmpty(){
	return _heap.empty();
}