#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

int main(int argc, char *argv[]){
  if (argc < 2){  
    puts("Usage: db [FILE]");
    return -1;
  }
  printIntro();
  TreeNode p_tree = NULL;
  int choice = -1;

  readFile(argv[1], &p_tree);

  while(choice != 0){
    printOption(); 
    scanf("%d", &choice);
    while(getchar() != '\n');
    switch(choice){
    case 1: hQuery(&p_tree);break;
    case 2: hUpdate(&p_tree);break;
    case 3: insertValue(&p_tree);break;
    case 4: hDelete(&p_tree);break;
    case 5: printTree(p_tree); break;
    case 0: puts("Good bye!"); break;
    default: puts("Could not parse choice! Please try again");
    }
    puts("");
    }
return 0;
}

