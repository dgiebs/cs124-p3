#include <vector>
#include <tuple>

using namespace std;

#define D 2// number of children per node

class MaxHeap
{
private:
	vector<unsigned long long> _heap;
	void Heapify();
	void HeapUp(int index);
	void HeapDown(int index);
public:
	void BuildHeap(vector<unsigned long long> nodes, int length);

	unsigned long long Peek();
	unsigned long long ExtractMax();
	void Insert(unsigned long long n);
	void PrintHeap();
	bool IsEmpty();
	vector<int> IDsRemaining();
};