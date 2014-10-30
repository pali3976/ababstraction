#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
//Hej
int main(int argc, char *argv[]){
  if (argc < 2){            // Om inget argument, avsluta
    puts("Usage: db [FILE]");
    return -1;
  }
  printIntro();
  char buffer[128];
  TreeNode p_tree = NULL;
  int choice = -1;

  readFile(argv[1], buffer, &p_tree);
 
  
  
  while(choice != 0){
    printOption();         //Promts options
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    switch(choice){
    case 1: query(&p_tree,buffer);break;
    case 2: update(&p_tree, buffer);break;
    case 3: insertValue(&p_tree, buffer);break;
    case 4: delete(&p_tree, buffer);break;
    case 5: printTree(p_tree); break;
    case 0: puts("Good bye!"); break;   //Exit
    default: puts("Could not parse choice! Please try again");
    }
    puts("");
    }
return 0;
}


  /*  

  Node cursor;
  Node list = NULL;

  printIntro();            //Prints starting message
  readFile(argv[1], buffer, list);       //Reads DB

  int choice = -1;
  while(choice != 0){
    printOption();         //Promts options
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    switch(choice){
    case 1: query(buffer, cursor, list); break;  //Check value
 
    case 2: update(buffer, cursor, list); break; //Update value
   
    case 3: insert(buffer,cursor, list); break; //Insert 
      
    case 4: delete(buffer, cursor, list); break; //Delete
     
    case 5: print(cursor, list); break;  //Print
     
    case 0: puts("Good bye!"); break;   //Exit
    default: puts("Could not parse choice! Please try again");
    }
    puts("");
  }
  return 0;
}
  */
