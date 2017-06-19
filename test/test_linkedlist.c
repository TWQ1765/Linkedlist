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

void setUp(void)
{
}

void tearDown(void)
{
}
void test_listInit_esure_initialized_to_NULL_and_0(void){
  LinkedList list = {
    (Item *)-1,
    (Item *)-1,
    10
  };
  listInit(&list);
  TEST_ASSERT_NULL(list.head);  //test head-> null
  TEST_ASSERT_NULL(list.tail);   //test tail-> null
  TEST_ASSERT_EQUAL(0,list.len);  //test len == 0
}

/*test1*
*  Initial              After adding Ali
*
*   tail----+             tail ----+
*   head----+             head ----+
*           |                      |
*         Null                    next --------+
*                                   data---+   |
*                                         |    Null 
*                                         Ali
*                                         ..
*Given an
*
*/

/*test2*
*  Initial              After adding Ali
*
*   tail----+             tail ----+
*   head----+             head ----+
*           |                      |
*         next--------+            next----------next-------+        
*          data---+   |            data---+       data--+   |  
*                 | Null                  |             |  Null
*                Ali                     Ali         Baba
*                ..                      ..          ..
*
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




void test_listAdd_an_empty_linked_list_then_baba_expect_2_list(void) {
LinkedList list;

listInit(&list);

list.head = &itemAli;
list.tail = &itemAli;
list.len = 1;
itemAli.next = NULL;
itemBaba.next = (Item *)-1;

listAdd(&list, &itemBaba);
TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
TEST_ASSERT_EQUAL_PTR(&itemBaba, list.tail);
TEST_ASSERT_EQUAL(2, list.len);
TEST_ASSERT_EQUAL_PTR(&itemBaba, itemAli.next);
TEST_ASSERT_EQUAL_PTR(&ali, itemAli.data);
TEST_ASSERT_NULL(itemBaba.next);
TEST_ASSERT_EQUAL_PTR(&ali, itemAli.data);
}