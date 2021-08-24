all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : basic_chained_hash.o main.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f *.o main