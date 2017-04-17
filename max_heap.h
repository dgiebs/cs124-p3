#include <vector>
#include <tuple>

using namespace std;

// Leaf stores <weight, ID_node>
typedef tuple<unsigned long long, int> Leaf;

#define D 2// number of children per node

class MaxHeap
{
private:
	vector<Leaf> _heap;
	// mapping to make DecreaseKey more efficient
	vector<int> _indexmap;
	void Heapify();
	void HeapUp(int index);
	void HeapDown(int index);
public:
	void BuildHeap(vector<Leaf> nodes, int length);

	Leaf Peek();
	Leaf ExtractMax();
	bool DecreaseKey(int ID, float newWeight);
	void PrintHeap();
	bool IsEmpty();
	vector<int> IDsRemaining();
};