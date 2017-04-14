randmst: randmst.cpp min_heap.cpp
	g++ min_heap.cpp randmst.cpp -o randmst -std=c++11

min_heap_test: min_heap_test.cpp min_heap.cpp
	g++ min_heap.cpp min_heap_test.cpp -o min_heap_test -std=c++11