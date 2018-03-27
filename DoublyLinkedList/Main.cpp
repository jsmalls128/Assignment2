#include "DoublyLinkedList.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main(int argc, char * argv[]){
  // Command prompt
  cout << "insert (i), delete (d), length (l), print (p), additivepair(a) quit (q)" << endl << endl;
    char input;
    int numbers;
    bool cont = true;
    ifstream inFile;
    inFile.open(argv[1]);       // attempt to open file
    if(!inFile){
      cout << "Unable to open file";
      return EXIT_FAILURE;
    }
    DoublyLinkedList startList = DoublyLinkedList();
    while(inFile >> numbers){                    // Insert all numbers in file into a DoublyLinkedList
      ItemType data;
      data.initialize(numbers);
      startList.insertItem(data); 
    }
    do {
      cout << "Enter a command: ";
      std::cin >> input;
      if(input == 'i'){                                   // Insert value
        cout << "Number to insert: ";
        std::cin >> numbers ;
        ItemType data;
        data.initialize(numbers);
        startList.insertItem(data);
        startList.print();
      }
      else if(input == 'd'){                              // Delete value
        startList.print();
        cout << "Number to delete: ";
        std::cin >> numbers ;
        ItemType data;
        data.initialize(numbers);
        startList.deleteItem(data);
        startList.print();
      }
      else if(input  == 'p'){                             // Print list
        startList.print();
      }
      else if(input  == 'l'){                             // Print length
        cout << "List length is " << startList.lengthIs() << endl;
      }
      else if(input == 'a'){                              // Additive pairs
        cout << "Get the additive sum of: ";
        std::cin >> numbers;
        ItemType data;
        data.initialize(numbers);
        startList.additivePairs(data);
      }
      else if(input == 'q'){                              // Quit program
        cout << "Quitting program..." << endl;
        return EXIT_SUCCESS;
      }
      else if(input != 'q'){                              // Other input
        cout << "Command not recognized. Try again" << endl;
      }
    }
    while(cont);                                     
  
  return EXIT_SUCCESS;    
} // main