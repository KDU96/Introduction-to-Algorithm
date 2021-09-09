all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : Matrix.o main.o
	g++ -g -Wall -o $@ $^ -lpthread

clean :
	rm -f main *.o
