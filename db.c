#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"


void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);                             
  int len = strlen(dest);                             
  if(dest[len-1] == '\n')                            
    dest[len-1] = '\0';
}

void readFile(char *filename, char buffer[], TreeNode tree){
  printf("Loading database \"%s\"...\n\n", filename);
  FILE *database = fopen(filename, "r");
  char buffer2[128];

  while(!feof(database)){
  readline(buffer, 128, database);
  readline(buffer2, 128, database);
  insert(tree, buffer, buffer2);
    }   
}

void insert(TreeNode tree, char *insert_key, char *insert_value){
  printf("Test\n");
  if (tree == NULL){
    tree = malloc(sizeof(struct treenode));

    tree->key = malloc(strlen(insert_key)+1);
    strcpy(tree->key, insert_key);

    tree->value = malloc(strlen(insert_value)+1);
    strcpy(tree->value, insert_value);

    tree->left = NULL;
    tree->right = NULL;
    return;
  }

  else if(strcmp(insert_key,tree->key) > 0){   // Right
    insert(tree->right, insert_key, insert_value);
  } 
  else if(strcmp(insert_key,tree->key) < 0) {   // Left
    insert(tree->left, insert_key, insert_value);
  } 
   
  else if(strcmp(insert_key,tree->key) == 0) {
    printf("key \"%s\" already exists!\n", insert_key);
  }
    
}



/*

  
void readFile(char *filename, char buffer[], Node list){
  printf("Loading database \"%s\"...\n\n", filename);  
  FILE *database = fopen(filename, "r");
  
  while(!(feof(database))){                          
    Node newNode = malloc(sizeof(struct node));
    readline(buffer, 128, database); 
    newNode->key = malloc(strlen(buffer) + 1); 
    strcpy(newNode->key, buffer); 
    readline(buffer, 128, database); 
    newNode->value = malloc(strlen(buffer) + 1); 
    strcpy(newNode->value, buffer);   
    newNode->next = list; 
    list = newNode; 
  }
}

void printIntro(void){
  puts("Welcome to");
  puts(" ____    ____       ");
  puts("/\\  _`\\ /\\  _`\\     ");
  puts("\\ \\ \\/\\ \\ \\ \\L\\ \\   ");
  puts(" \\ \\ \\ \\ \\ \\  _ <\\ ");
  puts("  \\ \\ \\_\\ \\ \\ \\L\\ \\ ");
  puts("   \\ \\____/\\ \\____/ ");
  puts("    \\/___/  \\/___/  ");
  puts(""); 
}

void printOption(void){
    puts("PLEASE CHOOSE AN OPERATION");
    puts("1. QUERY A KEY");
    puts("2. UPDATE AN ENTRY");
    puts("3. NEW ENTRY");
    puts("4. Remove entry");
    puts("5. Print database");
    puts("0. Exit database");
    printf("? "); 
}
 

void query(char buffer[],Node cursor, Node list){
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  puts("Searching database...\n");
  int found = 0;
  cursor = list;
  while(!found && cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){      // Matchar strängen med n
      puts("Found entry:");
      printf("key: %s\nvalue: %s\n", cursor->key, cursor->value);
      found = 1;
    }else{
      cursor = cursor->next;
    }
      }
  if(!found){
    printf("Could not find an entry matching key \"%s\"!\n", buffer);
      }
  }

void update(char buffer[], Node cursor, Node list){
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  puts("Searching database...\n");
  int found = 0;
  cursor = list;
  while(!found && cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){
          puts("Matching entry found:");
          printf("key: %s\nvalue: %s\n\n", cursor->key, cursor->value);
          found = 1;
    }
    else{
      cursor = cursor->next;
    }
  }
  if(!found){
    printf("Could not find an entry matching key \"%s\"!\n", buffer);
  }else{
        printf("Enter new value: ");
        readline(buffer, 128, stdin);
        free(cursor->value);
        cursor->value = malloc(strlen(buffer) + 1);
        strcpy(cursor->value, buffer);
        puts("Value inserted successfully!");
  }
}


void insert(char buffer[], Node cursor,  Node list){
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  puts("Searching database for duplicate keys...");
  int found = 0;
  cursor = list;
  while(!found && cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){
      printf("key \"%s\" already exists!\n", cursor->key);
      found = 1;
        }else{
      cursor = cursor->next;
    }
  }
  if(!found){ // Insert new node to the front of the list
    puts("Key is unique!\n");
    Node newNode = malloc(sizeof(struct node));
    newNode->key = malloc(strlen(buffer) + 1);
    strcpy(newNode->key, buffer);
    printf("Enter value: ");
    readline(buffer, 128, stdin);
    newNode->value = malloc(strlen(buffer) + 1);
    strcpy(newNode->value, buffer);
    newNode->next = list;
    list = newNode;
    puts("");
    puts("Entry inserted successfully:");
    printf("key: %s\nvalue: %s\n", list->key, list->value);
  }
}

void delete(char buffer[], Node cursor, Node list){
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  puts("Searching database...\n");
  int found = 0;
  cursor = list;
  Node prev = NULL;
  while(!found && cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){
      if(prev == NULL){ // Delete first node
	list = cursor->next;
      }else{
	prev->next = cursor->next;
      }
      found = 1;
      printf("Deleted the following entry:\nkey: %s\nvalue: %s\n", cursor->key, cursor->value);
    }else{
      prev = cursor;
      cursor = cursor->next;
    }
  }
  if(!found){
    printf("Could not find an entry matching key \"%s\"!\n", buffer);
  }
}


int print(Node list, Node cursor){
  cursor = list;
  while(cursor != NULL){
    puts(cursor->key);
    puts(cursor->value);
    cursor = cursor->next;
  }
  return -1;
}
*/
