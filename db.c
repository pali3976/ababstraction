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

  
void readFile(char *filename, char buffer[], Node list){
  printf("Loading database \"%s\"...\n\n", filename);  
  FILE *database = fopen(filename, "r");
  
  while(!(feof(database))){                            // !(Kollar om den �r vid slutet av filen)
    Node newNode = malloc(sizeof(struct node));        // Allokerar minne f�r noden
    readline(buffer, 128, database);                   // L�ser n.te raden i buffern
    newNode->key = malloc(strlen(buffer) + 1);         // Allokerar plats f�r v�rdet i newNode nyckeln
    strcpy(newNode->key, buffer);                      // Kopierar buffern och l�gger in i newNodes nyckelnn
    readline(buffer, 128, database);                   // Vi l�ser nyckelv�rdet och sparar i buffern
    newNode->value = malloc(strlen(buffer) + 1);       // S�tter nya newNode v�rdet till ... en minnesplats?
    strcpy(newNode->value, buffer);                    // Kopierar in v�rdet in i buffern fr�n newNode
    newNode->next = list;                              // L�gger dem nya noderna efter varandra, s� allt slutar p� NULL
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
    if(strcmp(buffer, cursor->key) == 0){      // Matchar str�ngen med n
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
