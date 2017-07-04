#include "unity.h"
#include "student.h"
#include "linkedlist.h"

Student ali = {
  "Ali",     //name
  23,        //age
  72.35,     //weight
  1.78       //height
};
Item itemAli = {
  (Item *)-2343456,   //next
  (void *)&ali        //data
};

Student baba = {
  "Baba",     //name
  15,        //age
  42.35,     //weight
  1.60       //height
};
Item itemBaba = {
  (Item *)-44444456,   //next
  (void *)&baba       //data
};
Student abu = {
  "Abu",     //name
  25,        //age
  80.35,     //weight
  1.80       //height
};
Item itemAbu = {
  (Item *)-66666666,   //next
  (void *)&abu       //data
};
void setUp(void)
{
}

void tearDown(void)
{
}

/*test 1  

*/
void test_listInit_esure_initialized_to_NULL_and_0(void){
  LinkedList list = {
    (Item *)-1,       // head  
    (Item *)-1,       // tail 
    10                // len = 0 
  };
  listInit(&list);    // call void listInit(linkedList *list)
  // test the initialisation success or not.
  TEST_ASSERT_NULL(list.head);  //test head-> null
  TEST_ASSERT_NULL(list.tail);   //test tail-> null
  TEST_ASSERT_EQUAL(0,list.len);  //test len == 0
}

/*test2*
*  Initial              After adding Ali
*
*   tail----+             tail ----+
*   head----+             head ----+
*           |                      |
*         Null                    next --------+
*                                 data---+     |
*                                        |    Null 
*                                       Ali
*                                       ..
*
*/
void test_listAdd_an_empty_linked_list_then_ali_expect_1_list(void) {
  LinkedList list;
//printf("address of item: %p\n", &item);
  listInit(&list);
  listAdd(&list, &itemAli);
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.tail);
  TEST_ASSERT_EQUAL(1, list.len);
  TEST_ASSERT_NULL(itemAli.next);
  TEST_ASSERT_EQUAL_PTR(&ali, itemAli.data);
}
/*test3*
*  Initial              After adding Ali
*
*   tail----+             tail ----+
*   head----+             head ----+
*           |                      |
*         next--------+            next----------next-------+        
*         data---+    |            data---+      data--+    |  
*                |  Null                  |            |  Null
*               Ali                     Ali          Baba
*               ..                      ..            ..
*
*/
void test_listAdd_an_empty_linked_list_then_baba_expect_2_list(void) {
  LinkedList list;

  listInit(&list);
  //start initialisation
  list.head = &itemAli;
  list.tail = &itemAli;
  list.len = 1;
  itemAli.next = NULL;
  itemBaba.next = (Item *)-1;

  listAdd(&list, &itemBaba);
  //test start here
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, list.tail);
  TEST_ASSERT_EQUAL(2, list.len);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, itemAli.next);
  TEST_ASSERT_EQUAL_PTR(&ali, itemAli.data);
  TEST_ASSERT_NULL(itemBaba.next);
  TEST_ASSERT_EQUAL_PTR(&ali, itemAli.data);
}

/*test4*
*  before adding Ali 
*
*  tail ----+                       tail----+
*  head ----+                       head----+
*           |                               |
*         next-------next----------+       next-------next------next------+
*         data---+    data--+      |      data---+   data---+   data--+   |
*                |          |    Null            |          |         |  Null
*               Ali        Baba                Ali        Baba      Abu
*               ..         ..                  ..           ..      ..
*
*/
void test_listAdd_an_empty_linked_list_then_abu_expect_3_list(void) {
  LinkedList list;

  listInit(&list);
  //start initialisation
  list.head = &itemBaba;
  list.tail = &itemBaba;
  list.len = 2;
  itemBaba.next = NULL;
  itemAbu.next = (Item *)-2;

  listAdd(&list, &itemAbu);
  //test start here 
  TEST_ASSERT_EQUAL_PTR(&itemBaba, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemAbu, list.tail);
  TEST_ASSERT_EQUAL(3, list.len);
  TEST_ASSERT_EQUAL_PTR(&itemAbu, itemBaba.next);
  TEST_ASSERT_EQUAL_PTR(&baba, itemBaba.data);
  TEST_ASSERT_NULL(itemAbu.next);
  TEST_ASSERT_EQUAL_PTR(&baba, itemBaba.data);
}

void test_listRemove_Ali_linked_list_expect_4_list(void) {
  LinkedList list;
  
  listInit(&list);
  list.head = &itemBaba;
  list.tail = &itemBaba;
  list.len = 2;
  itemBaba.next = NULL;
  itemAbu.next = (Item *)-2;
  
  
}
  
  
  
  