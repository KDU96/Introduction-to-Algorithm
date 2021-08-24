all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : main.o open_addressing.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f *.o main
