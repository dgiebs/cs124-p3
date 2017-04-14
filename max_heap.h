#include <vector>
#include <tuple>

// Leaf stores <weight, ID_node>
typedef std::tuple<float, int> Leaf;

#define D 2// number of children per node

class MinHeap
{
private:
	std::vector<Leaf> _heap;
	// mapping to make DecreaseKey more efficient
	std::vector<int> _indexmap;
	void Heapify();
	void HeapUp(int index);
	void HeapDown(int index);
public:
	void BuildHeap(std::vector<Leaf> nodes, int length);

	Leaf Peek();
	Leaf ExtractMax();
	bool DecreaseKey(int ID, float newWeight);
	void PrintHeap();
	bool IsEmpty();
	std::vector<int> IDsRemaining();
};