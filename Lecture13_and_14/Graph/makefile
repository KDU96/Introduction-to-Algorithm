all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : Adjacency_List_Graph.o main.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f main *.o
