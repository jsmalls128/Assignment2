main: main.o ItemType.o CircularLinkedList.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main Main.o ItemType.o CircularLinkedList.o
main.o: Main.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Main.cpp
ItemType.o: ItemType.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ItemType.cpp
CircularLinkedList.o: CircularLinkedList.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c CircularLinkedList.cpp
clean:
	rm main Main.o ItemType.o CircularLinkedList.o