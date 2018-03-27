main: main.o ItemType.o DoublyLinkedList.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main Main.o ItemType.o DoublyLinkedList.o
main.o: Main.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Main.cpp
ItemType.o: ItemType.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ItemType.cpp
DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c DoublyLinkedList.cpp
clean:
	rm main Main.o ItemType.o DoublyLinkedList.o