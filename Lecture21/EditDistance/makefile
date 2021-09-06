all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : editdistance.o main.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f main *.o
