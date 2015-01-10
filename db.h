/** @file db.h */

typedef struct treenode *TreeNode;

/** @brief reads a file and inserts the data into a binary tree.
 * @details the binary tree will not be sorted after all elements
 * are inserted.
 *
 * @param filename is the path to the file.
 * @param buffer temp stores the data.
 * @param pp_tree a binary tree.
 */
void readFile(char *filename, TreeNode *pp_tree);

/** @brief inserts a node into the binry tree.
 * @details uses recursion to find the right empty node.
 *
 * @param pp_tree a binary tree.
 * @param insert_key the key for the new node which will be inserted.
 * @param insert_value the value fo the new node which will be inserted.
 * @param p_found determine is the node already exists (0 for true).
 */
void insert(TreeNode *pp_tree, char *insert_key, char *insert_value, int *p_found);

/** @brief replaces the value of a node.
 * @details promts a message if succeeded or not.
 *
 * @param pp_tree a binary tree.
 */
void insertValue(TreeNode *pp_tree);

/** @brief finds the node with a key in a binary tree.
 *
 * @param pp_tree a binary tree.
 * @param nodeKey stores the key to search for.
 * @param found determine is the node is found.
 * @return the memory adress of the node in the binary tree.
 * if not found will return null.
 */

TreeNode findNode(TreeNode p_tree, char nodeKey[], int *found);

/** @brief finds the parent of the node with a key in a binary tree.
 * 
 * @param pp_tree a binary tree.
 * @param nodeKey stores the key to search for.
 * @return the memory adress of the parent of the node in the binary tree,
 * if not found will return null.
 */
TreeNode returnPre(TreeNode p_tree, char nodeKey[]);

/** @brief deletes a node from a binary tree. 
 * @details promts if succeeded or not.
 *
 * @param pp_tree a binary tree.
 */

void hDelete(TreeNode *pp_tree);

/** @brief deletes a node from a binary tree. 
 * @details promts if succeeded or not.
 *
 * @param pp_tree a binary tree.
 * @param key stores the key name to the node, which will be deleted.
 * @return Returns key name if succeeded otherwise "NULL" in a string.
 */
char *delete(TreeNode *pp_tree, char key[]);

/** @brief changes the nodes value.
 *
 * @param p_tree a binary tree.
 * @param key is the key to the node.
 * @param newValue is the new value.
 * @return the new value, otherwise "NULL" as a string.
 */
char *update(TreeNode p_tree, char key[], char newValue[]);

/** @brief updates a nodes value in a binary tree. 
 * @details promts if succeeded or not.
 *
 * @param p_tree a binary tree.
 */
void hUpdate(TreeNode *pp_tree);

/** @brief checks if a key exist in the binary tree or not. 
 * @details promts if succeeded or not.
 *
 * @param pp_tree a binary tree.
 * @param nodeKey the value to be searched for.
 * @return Returns the value if found, otherwise "NULL" as a string.
 */
char *query(TreeNode *pp_tree, char *nodeKey);

/** @brief checks if a key exist in the binary tree or not. 
 * @details promts if succeeded or not.
 *
 * @param pp_tree a binary tree.
 * @param buffer the value to be searched for.
 */
void hQuery(TreeNode *pp_tree);

/** @brief prints a welcome message of the program.
 */
void printIntro(void);
/** @brief prints the avalible options. 
 */
void printOption(void);

/** @brief checks if a key exist in the binary tree or not. 
 * @details promts every node, and if tree is empty or not.
 *
 * @param pp_tree a binary tree..
 */
void printTree(TreeNode p_tree);


