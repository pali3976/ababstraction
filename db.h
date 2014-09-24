typedef struct node{
  char *key;
  char *value;
  struct node *next;
} *Node;


void readline(char *dest, int n, FILE *source);
void printIntro(void);
void printOption(void);
void readFile(char *filename, char buffer[], Node list);
void query(char buffer[], Node cursor, Node list);
void update(char buffer[] ,Node cursor, Node list);
void insert(char buffer[], Node cursor, Node list);
void delete(char buffer[], Node cursor, Node list);
int print(Node cursor, Node list);
