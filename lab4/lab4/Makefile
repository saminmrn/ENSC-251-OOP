#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and stack.o to executable main
main: main.o stack.hpp
	g++ -g -o main main.o 

#compile the main.cpp to main.o
main.o: main.cpp stack.hpp
	g++ -g -c main.cpp

#compile the stack.cpp to stack.o
binaries= main.o 
clean: 
	rm main $(binaries)
#remove built files
clean_win:
	del main.exe $(binaries)
