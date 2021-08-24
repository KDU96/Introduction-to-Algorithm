all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $<

main : bin_tree.o main.o
	g++ -g -Wall -o  $@ $^

clean :
	rm -f *.o main
