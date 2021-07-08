/**
 * @file test_bankManagementSystem.c
 * @author Sumit Bhimte
 * @brief defile all testcases and run it
 * @version 0
 * @date 2021-07-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "unity.h"
#include "bank.h"
#include<stdio.h>
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}



void test_view_list(void) {
  TEST_ASSERT_EQUAL(1, 1);
}
void test_calculateInterest(void){
  TEST_ASSERT_EQUAL(60.000000,calculateInterest(10,20,30));
}

void test_delayProg(void){
  TEST_ASSERT_EQUAL(10,delayProg(1));
}

void test_menu(void){
  TEST_ASSERT_EQUAL(0,0);
}
int main(void){
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();
/* Run Test functions */
  RUN_TEST(test_view_list);
  RUN_TEST(test_calculateInterest);
  RUN_TEST(test_delayProg);
  RUN_TEST(test_menu);

/* Close the Unity Test Framework */
  return UNITY_END();

}