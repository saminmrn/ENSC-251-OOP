#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, and stu_sort.o to executable main
main: main.o student.o stu_sort.o Domestic.o International.o TOFEL.o
	g++ -g -o main main.o student.o stu_sort.o Domestic.o International.o TOFEL.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the stu_sort.cpp to stu_sort.o
stu_sort.o: stu_sort.cpp
	g++ -g -c stu_sort.cpp

#compile the Domestic.cpp to Domestic.o
Domestic.o: Domestic.cpp
	g++ -g -c Domestic.cpp

#compile the International.cpp to International.o
International.o: International.cpp
	g++ -g -c International.cpp

#compile the International.cpp to International.o
TOFEL.o: TOFEL.cpp
	g++ -g -c TOFEL.cpp

#remove built files
clean:
	rm -rf main main.o student.o stu_sort.o International.o Domestic.o TOFEL.o *~
