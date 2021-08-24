all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : TextJustification.o main.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f *.o main
