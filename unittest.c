#include "CUnit/Basic.h"
#include "db.h"


int init_suite_1(void){
  return 0;
}

int clean_suite_1(void){
  return 0;
}

int init_suite_2(void){
  return 0;
}

int clean_suite_2(void){
  return 0;
}

void TEST_insert(void){
  int number = -1;
  int *num = &number;

  TreeNode testTree1 = NULL;
    
  char *testKey1 = "Berit";
  char *testValue1 = "01";

  char *testKey2 = "Anna";
  char *testValue2 = "02";

  char *testKey3 = "Carl";
  char *testValue3 = "03";

  insert(&testTree1, testKey1, testValue1, num);
  insert(&testTree1, testKey2, testValue2, num);
  insert(&testTree1, testKey3, testValue3, num);

  TreeNode testTree2 = testTree1->left;
  TreeNode testTree3 = testTree1->right;


  CU_ASSERT(strcmp(testKey1, testTree1->key) == 0);
  CU_ASSERT(strcmp(testValue1,testTree1->value) == 0);

  CU_ASSERT(strcmp(testKey2, testTree2->key) == 0);
  CU_ASSERT(strcmp(testValue2, testTree2->value) == 0);

  CU_ASSERT(strcmp(testKey3, testTree3->key) == 0);
  CU_ASSERT(strcmp(testValue3, testTree3->value) == 0);
}

void TEST_query(void){
  TreeNode testTree = NULL;
  int number = -1;
  int *num = &number;
    
  char *testKey = "Berit";
  char *testValue = "01";

  insert(&testTree, testKey, testValue, num);

  char *resultValue = query(&testTree,testKey);
  
  CU_ASSERT(strcmp(testValue,resultValue) == 0);
}

void TEST_update(void){
  TreeNode testTree = NULL;
  int number = -1;
  int *num = &number;
    
  char *testKey1 = "Berit";
  char *testValue1 = "01";
  char *newValue = "02";

  insert(&testTree, testKey1, testValue1, num);
 
  char *resultValue = update(testTree,testKey1,newValue);
  
  CU_ASSERT(strcmp(newValue,resultValue) == 0);
}

void TEST_delete(void){
  int number = -1;
  int *num = &number;

  TreeNode testTree1 = NULL;
  TreeNode testTree2 = NULL;
  TreeNode testTree3 = NULL;
  TreeNode testTree4 = NULL;
  TreeNode testTree5 = NULL;

  char *testKey1 = "Ha";
  char *testValue1 = "01";

  char *testKey2 = "De";
  char *testValue2 = "02";

  char *testKey3 = "Be";
  char *testValue3 = "03";
  
  char *testKey4 = "Fe";
  char *testValue4 = "04";

  char *testKey5 = "Le";
  char *testValue5 = "05";


  // testTree1 == NULL
  insert(&testTree1, testKey1, testValue1, num);
  delete(&testTree1, testKey1);
 
  // testTree2 == De
  insert(&testTree2, testKey1, testValue1, num);
  insert(&testTree2, testKey2, testValue2, num);
  delete(&testTree2, testKey1);

  // testTree3->right == NULL
  insert(&testTree3, testKey1, testValue1, num);
  insert(&testTree3, testKey5, testValue5, num);
  delete(&testTree3, testKey1);

  // testTree3->left == NULL
  insert(&testTree4, testKey1, testValue1, num);
  insert(&testTree4, testKey2, testValue2, num);
  delete(&testTree4, testKey2);

  // (-De) tree->left->value == BE
  insert(&testTree5, testKey1, testValue1, num);
  insert(&testTree5, testKey2, testValue2, num);
  insert(&testTree5, testKey3, testValue3, num);
  insert(&testTree5, testKey4, testValue4, num);
  delete(&testTree5, testKey2);

  TreeNode fifthTree = testTree5->left;

  CU_ASSERT(testTree1 == NULL);
  CU_ASSERT(strcmp(testKey2,testTree2->key) == 0);
  CU_ASSERT(testTree3->right == NULL);
  CU_ASSERT(testTree4->left == NULL);
  CU_ASSERT(strcmp(testKey3,fifthTree->key) == 0); 
  CU_ASSERT(fifthTree->left == NULL); 
}

int main(){

  CU_pSuite pSuite1 = NULL;
  if (CUE_SUCCESS != CU_initialize_registry()){
    return CU_get_error();
  }

  pSuite1 = CU_add_suite("db.c tests",init_suite_1, clean_suite_1);

  if (NULL == pSuite1)
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  if ((NULL == CU_add_test(pSuite1, "Test insert", TEST_insert))||
      (NULL == CU_add_test(pSuite1, "Test query", TEST_query)) ||
      (NULL == CU_add_test(pSuite1, "Test update", TEST_update)) ||
      (NULL == CU_add_test(pSuite1, "Test delete", TEST_delete)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();  
  return CU_get_error();
}
