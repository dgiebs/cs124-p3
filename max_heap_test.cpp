#include <iostream>
#include "min_heap.h"

using namespace std;

void buildHeapTest(void);

int main(void){
	MinHeap mh;
	Leaf leaves[6];
	leaves[0] = make_tuple(50, 1);
	leaves[1] = make_tuple(30, 2);
	leaves[2] = make_tuple(10, 3);
	leaves[3] = make_tuple(30, 4);
	leaves[4] = make_tuple(20, 5);
	leaves[5] = make_tuple(60, 6);
	
	cout << "Testing BuildHeap (also tests Heapify)...\n";
	mh.BuildHeap(leaves, 6);
	cout << "Built Heap:";
	mh.PrintHeap();
	cout << "\n";
	//buildHeapTest();

	cout << "Testing Peek...\n";
	Leaf min = mh.Peek();
	cout << "Peeked and saw: (" << get<0>(min) << ", " << get<1>(min) << ")\n";
	cout << "\n";

	cout << "Testing ExtractMin (also tests Peek)...\n";
	cout << "Heap pre-extraction: ";
	mh.PrintHeap();
	cout << "\n";
	Leaf min2 = mh.ExtractMin();
	cout << "Extracted Min: (" << get<0>(min2) << ", " << get<1>(min2) << ")\n";
	cout << "Heap post-extraction: ";
	mh.PrintHeap();
	cout << "\n";

	cout << "Testing DecreaseKey...\n";
	cout << "Heap pre-decrease: ";
	mh.PrintHeap();
	cout << "\n";
	bool swapped = mh.DecreaseKey(6, 5.2);
	cout << "Heap post-decrease: ";
	mh.PrintHeap();
	cout << "\n";
	cout << "Swapped: " << swapped << "\n";

	cout << "Testing IsEmpty...\n";
	bool empty;
	mh.ExtractMin();
	mh.PrintHeap();
	empty = mh.IsEmpty();
	cout << empty << "\n";
	cout << "\n";
	mh.ExtractMin();
	mh.PrintHeap();
	empty = mh.IsEmpty();
	cout << empty << "\n";
	cout << "\n";
	mh.ExtractMin();
	mh.PrintHeap();
	empty = mh.IsEmpty();
	cout << empty << "\n";
	cout << "\n";
	mh.ExtractMin();
	mh.PrintHeap();
	empty = mh.IsEmpty();
	cout << empty << "\n";
	cout << "\n";
	mh.ExtractMin();
	mh.PrintHeap();
	empty = mh.IsEmpty();
	cout << empty << "\n";


	/* cout << "Testing Insert...\n";
	cout << "Heap pre-insert: ";
	mh.PrintHeap();
	cout << "\n";
	Leaf newVal = make_tuple(25, 6);
	mh.Insert(newVal);
	cout << "Heap post-insert: ";
	mh.PrintHeap();
	cout << "\n"; */

	return 0;

}

void buildHeapTest(void){
	MinHeap mh;
	Leaf leaves[6];
	leaves[0] = make_tuple(50, 1);
	leaves[1] = make_tuple(30, 2);
	leaves[2] = make_tuple(10, 3);
	leaves[3] = make_tuple(30, 4);
	leaves[4] = make_tuple(20, 5);
	leaves[5] = make_tuple(60, 6);

	mh.BuildHeap(leaves, 6);
	cout << "Built Heap:";
	mh.PrintHeap();
	cout << "\n\n";
}