#include <vector>
#include <tuple>

using namespace std;

#define D 2// number of children per node

class MaxHeap
{
private:
	vector<signed long long> _heap;
	void Heapify();
	void HeapUp(int index);
	void HeapDown(int index);
public:
	void BuildHeap(vector<signed long long> nodes, int length);

	signed long long Peek();
	signed long long ExtractMax();
	void Insert(signed long long n);
	void PrintHeap();
	bool IsEmpty();
	vector<int> IDsRemaining();
};