#include "unit_test.h"

START_TEST(easy_test) {
  char string1[] = "abc";
  char string2[] = "abc";
  size_t len = 3;
  s21_memset(string1, 'a', len);
  memset(string2, 'a', len);
  ck_assert_mem_eq(string1, string2, len * sizeof(char));
}

START_TEST(empty_string) {
  char string1[] = "";
  char string2[] = "";
  size_t len = 0;
  s21_memset(string1, 'a', len);
  memset(string2, 'a', len);
  ck_assert_mem_eq(string1, string2, len * sizeof(char));
}

START_TEST(string_with_register) {
  char string1[] = "Abc";
  char string2[] = "Abc";
  size_t len = 3;
  s21_memset(string1, 'a', len - 1);
  memset(string2, 'a', len - 1);
  ck_assert_mem_eq(string1, string2, len * sizeof(char));
}

START_TEST(part_of_string) {
  char string1[] = "abcdefgijklmnopqrstuvwxyz";
  char string2[] = "abcdefgijklmnopqrstuvwxyz";
  size_t len = 26;
  s21_memset(string1 + 1, 'a', 3);
  memset(string2 + 1, 'a', 3);
  ck_assert_mem_eq(string1, string2, len * sizeof(char));
}

START_TEST(float_array) {
  float string1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  float string2[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  size_t len = 5;
  s21_memset(string1, 1.0, 3);
  memset(string2, 1.0, 3);
  ck_assert_mem_eq(string1, string2, len * sizeof(float));
}

START_TEST(long_string) {
  char string1[] = "doiuwj9dh1387hdHAWHDAW wwahdA Hd87h1 7eho21e 21";
  char string2[] = "doiuwj9dh1387hdHAWHDAW wwahdA Hd87h1 7eho21e 21";
  size_t len = s21_strlen(string1);
  s21_memset(string1, 'a', 10);
  memset(string2, 'a', 10);
  ck_assert_mem_eq(string1, string2, len * sizeof(char));
}

START_TEST(occur_mem) {
  char string1[] = "1234567890";
  char* str2 = string1 + 2;
  size_t len = 5;
  s21_memset(str2, 'a', len);

  char string2[] = "1234567890";
  char* str4 = string2 + 2;
  memset(str4, 'a', len);
  ck_assert_mem_eq(str2, str4, len * sizeof(char));
}
/*
START_TEST(zero_len) {
    char string1[] = "abc";
    char string2[] = "abc";
    size_t len = 3;
    s21_memset(string1, 'a', 0);
    memset(string2, 'a', 0);
    ck_assert_mem_eq(string1, string2, len * sizeof(char));
}
*/
START_TEST(replace_with_num) {
  char string1[] = "abc";
  char string2[] = "abc";
  size_t len = 3;
  s21_memset(string1, '1', len);
  memset(string2, '1', len);
  ck_assert_mem_eq(string1, string2, len * sizeof(char));
}

Suite* s21_memset_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_memset");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, easy_test);
  tcase_add_test(tc_core, empty_string);
  tcase_add_test(tc_core, string_with_register);
  tcase_add_test(tc_core, part_of_string);
  tcase_add_test(tc_core, float_array);
  tcase_add_test(tc_core, long_string);
  tcase_add_test(tc_core, occur_mem);
  //    tcase_add_test(tc_core, zero_len);
  tcase_add_test(tc_core, replace_with_num);

  suite_add_tcase(s, tc_core);
  return s;
}