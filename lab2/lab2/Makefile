#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, time.o, and date.o  Calendar.os to executable main
main: main.o time.o date.o Calendar.o
	g++ -g -o main main.o Calendar.o time.o date.o 
#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the Calendar.cpp to Calendar.o
Calendar.o: Calendar.cpp
	g++ -g -c Calendar.cpp

#compile the time.cpp to time.o
time.o: time.cpp
	g++ -g -c time.cpp

#compile the date.cpp to date.o
date.o: date.cpp
	g++ -g -c date.cpp

#remove built files
clean:
	rm -rf main main.o time.o date.o Calendar.o *~
