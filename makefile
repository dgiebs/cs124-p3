randmst: kk.cpp max_heap.cpp
	g++ max_heap.cpp kk.cpp -o kk -std=c++11

max_heap_test: max_heap_test.cpp max_heap.cpp
	g++ max_heap.cpp max_heap_test.cpp -o max_heap_test -std=c++11