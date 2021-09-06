all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : main.o knapsack.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f *.o main
