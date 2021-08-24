all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : main.o GraphForDijkstra.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f main *.o
