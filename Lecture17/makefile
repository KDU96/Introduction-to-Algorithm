all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : main.o BellmanFord.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f main *.o