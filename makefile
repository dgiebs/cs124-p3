all: makenums kk 

kk: kk.cpp max_heap.cpp
	g++ max_heap.cpp kk.cpp -o kk -std=c++11

makenums: makenums.cpp
	g++ makenums.cpp -o makenums -std=c++11

kk_streamline: kk_streamline.cpp max_heap.cpp
	g++ max_heap.cpp kk_streamline.cpp -o kk_streamline -std=c++11