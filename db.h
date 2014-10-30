typedef struct treenode {
  char *key;
  char *value;
  struct treenode *left;
  struct treenode *right;
} *TreeNode;

void readFile(char *filename, char buffer[], TreeNode *pp_tree);
void insert(TreeNode *pp_tree, char *insert_key, char *insert_value, int *p_found);
void insertValue(TreeNode *pp_tree, char buffer []);
TreeNode findNode(TreeNode p_tree, char buffer[], int *found);
void delete(TreeNode *pp_tree, char buffer[]);
void update(TreeNode *pp_tree, char buffer[]);
void query(TreeNode *pp_tree, char buffer[]);
void printIntro(void);
void printOption(void);
void printTree(TreeNode p_tree);
