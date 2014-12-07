#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

typedef struct treenode {
  char *key;
  char *value;
  struct treenode *left;
  struct treenode *right;
} *TreeNode;


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
 
void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);                             
  int len = strlen(dest);                             
  if(dest[len-1] == '\n')                            
    dest[len-1] = '\0';
}

void readFile(char *filename, char buffer[], TreeNode *pp_tree){
  printf("Loading database \"%s\"...\n\n", filename);
  FILE *database = fopen(filename, "r");
  char buffer2[128];
  int found = -1;

  while(!feof(database)){
    readline(buffer, 128, database);
    readline(buffer2, 128, database);
    insert(pp_tree, buffer, buffer2, &found);
  }

	fclose(database);
}

void insertValue(TreeNode *pp_tree,char buffer[]){
  char buffer2[128];
  int found = -1;
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  printf("Enter value: ");
  readline(buffer2, 128, stdin);
  puts("Searching database for duplicate keys...");
  insert(pp_tree, buffer, buffer2,&found);

  if(found != 0){
    puts("Entry inserted successfully:");
    printf("key: %s\nvalue: %s\n", buffer, buffer2);
  }

  else {
    printf("key \"%s\" already exists!\n", buffer);
  }
}

TreeNode returnPre(TreeNode p_tree, char buffer[]){
  TreeNode temp = NULL;
  if(p_tree == NULL){ 
    return NULL;
  }
  if(strcmp((p_tree)->key, buffer) == 0){
    return p_tree;
  }
  if(strcmp(buffer,(p_tree)->key) < 0 && p_tree->left != NULL){ //left
    temp = (p_tree)->left;
    if(strcmp((temp)->key, buffer) == 0){;
      return p_tree;
    } 
    
    else 
      return returnPre(temp, buffer);
  }
  if(strcmp(buffer,(p_tree)->key) > 0 && p_tree->right != NULL){ //right
    temp = (p_tree)->right;
    if(strcmp((temp)->key, buffer) == 0){
      return p_tree;
    } 
    
    else return  returnPre(temp, buffer);
  }
  
  else return NULL;
}

TreeNode findRightNode(TreeNode p_tree){
  while(p_tree->right != NULL){
    p_tree = p_tree->right;
  }
  return p_tree;
}

TreeNode findNode(TreeNode p_tree, char buffer[],int *found){
  while(strcmp(buffer, p_tree->key) != 0){
    if (strcmp(buffer, (p_tree)->key) < 0 && p_tree->left != NULL){ //left
      p_tree = p_tree->left;
    }
    else if (strcmp(buffer, (p_tree)->key) > 0 && p_tree->right != NULL){ //right
      p_tree = p_tree->right;	
    }
    else{
      *found = 0;
      return NULL;
    }
  }
  return p_tree;
}


void insert(TreeNode *pp_tree, char *insert_key, char *insert_value, int *p_found){
  if (*pp_tree == NULL){

    TreeNode p_temp = NULL;
    p_temp = malloc(sizeof(struct treenode));

    p_temp->key = malloc(strlen(insert_key)+1);
    strcpy(p_temp->key, insert_key);

    p_temp->value = malloc(strlen(insert_value)+1);
    strcpy(p_temp->value, insert_value);

    p_temp->left = NULL;
    p_temp->right = NULL;
    *pp_tree = p_temp;
    
    return;
  }
  else if(strcmp(insert_key,(*pp_tree)->key) > 0){   // Right
    insert(&(*pp_tree)->right, insert_key, insert_value,p_found);
  } 
  else if(strcmp(insert_key,(*pp_tree)->key) < 0) {   // Left
    insert(&(*pp_tree)->left, insert_key, insert_value,p_found);
  } 
   
  else if(strcmp(insert_key,(*pp_tree)->key) == 0) {
    *p_found = 0;
  }    
}

void query(TreeNode *pp_tree, char buffer[]){
  int found = -1;
  printf("Enter key: ");
  readline(buffer, 128,stdin);

  TreeNode temp = findNode(*pp_tree, buffer, &found);

  if(found != 0){
    puts("Matching entry found:");
    printf("key: %s\nvalue: %s\n\n", temp->key, temp->value);

  }
  else printf("Sorry, could not find a matching key\n\n");
}

void update(TreeNode *pp_tree, char buffer[]){
  int found = -1;
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  printf("Searching for node...\n\n");
  TreeNode temp = findNode(*pp_tree, buffer, &found);

  if(found != 0){
    printf("Found matching key\nEnter new value: ");
    readline(buffer,128,stdin);
    strcpy(temp->value,buffer);
    printf("key: %s\nvalue: %s\n", temp->key, temp->value);
  }

  else  printf("Sorry, could not find a matching key\n\n");
}

void printTree(TreeNode p_tree){
  if(p_tree == NULL){
    puts("\nThe tree is empty\n");
    return;
  }
  printf("%s\n%s\n", p_tree->key, p_tree->value);
  if(p_tree->left != NULL) { printTree(p_tree->left);}
  if(p_tree->right != NULL) { printTree(p_tree->right);}
  return;
}




void delete(TreeNode *pp_tree, char buffer[]){
  int found = -1;
  printf("Please enter key: ");
  readline(buffer,128,stdin);
  printf("\nSearching for node...\n\n");
  TreeNode deletedNode = findNode(*pp_tree, buffer, &found);
 
  if(deletedNode == NULL){
    puts("Sorry, could not find a matching key\n\n");
    return;
  }
  
  //Om rootnoden ska deletas
  if(strcmp(deletedNode->key,(*pp_tree)->key) == 0){
    //Om det endast finns en nod i trädet
    if(deletedNode->left == NULL && deletedNode->right == NULL){
      *pp_tree = NULL;
      printf("Successfully deleted key: %s\n", deletedNode->key);
      free(deletedNode);
      return;
    }
    if(deletedNode->left != NULL && deletedNode->right != NULL){
      TreeNode rNode = deletedNode->right;
      TreeNode lNode = deletedNode->left;
      TreeNode temp = findRightNode(lNode);
	  
      temp->right = rNode; 
      *pp_tree = lNode;
      
      printf("Successfully deleted key: %s\n", deletedNode->key);
      free(deletedNode);
      return;
	  
    }
    //Om det endast finns en vänsternod till roten
    if(deletedNode->left != NULL){
      *pp_tree = deletedNode->left;
      printf("Successfully deleted key: %s\n", deletedNode->key);
      free(deletedNode);
      return;
    }
    //Om det endast finns en högernod till roten
    if(deletedNode->right != NULL){
      *pp_tree = deletedNode->right;
      printf("Successfully deleted key: %s\n", deletedNode->key);
      free(deletedNode);
      return;
    }
    //Om det finns 2 noder till roten
  }
  //ej rotnod
  else {
    //Om noden som ska deletas inte har några barn
    if(deletedNode->left == NULL && deletedNode->right == NULL){
      TreeNode preNode = returnPre(*pp_tree,buffer);
      if(strcmp(buffer,preNode->key) < 0){ //left
	preNode->left = NULL;
	printf("Successfully deleted key: %s\n", deletedNode->key);
	free(deletedNode);
	return;
      }

      else{// right
	preNode->right = NULL;
	printf("Successfully deleted key: %s\n", deletedNode->key);
	free(deletedNode);
	return;
      }
    }
    //Om noden som ska deletas har två barn
    if(deletedNode->left != NULL && deletedNode->right !=NULL){
      TreeNode rNode = deletedNode->right;
      TreeNode lNode = deletedNode->left;
      TreeNode preNode = returnPre(*pp_tree,buffer);
      TreeNode temp = findRightNode(lNode);
      if(strcmp(lNode->key,preNode->key) < 0){ //Left side
	temp->right = rNode;
        preNode->left = lNode;
      }
      else{ //Right side
	temp->right = rNode;
	preNode->right = lNode;
      }
      printf("Successfully deleted key: %s\n", deletedNode->key);
      free(deletedNode);
      return;
    }
    //Om noden som ska deletas bara har ett vänsterbarn
    if(deletedNode->left != NULL){

      TreeNode lNode = deletedNode->left;
      TreeNode preNode = returnPre(*pp_tree,buffer);
    

      preNode->left = lNode;
      printf("Successfully deleted key: %s\n", deletedNode->key);
      free(deletedNode);
      return;

    }
    //Om noden som ska deletas bara har ett högerbarn
    else if(deletedNode->right != NULL){
      TreeNode rNode = deletedNode->right;
      TreeNode preNode = returnPre(*pp_tree,buffer);
    
      preNode->right = rNode;
      printf("Successfully deleted key: %s\n", deletedNode->key);
      free(deletedNode);
      return;
    }   
  }
}
 



