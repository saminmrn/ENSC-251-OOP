#compile and link the application
all: tutorial

#run the application
run: tutorial
	./tutorial

#link tutorial.o and helper.o to executable tutorial
tutorial: tutorial.o helper.o
	g++ -g -lm -o tutorial tutorial.o helper.o

#compile the tutorial.cpp to tutorial.o
tutorial.o: tutorial.cpp
	g++ -g -c tutorial.cpp

#compile the helper.cpp to helper.o
helper.o: helper.cpp
	g++ -g -c helper.cpp

#remove built files
clean:
	rm -rf tutorial tutorial.o helper.o *~
