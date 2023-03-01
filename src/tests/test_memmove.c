#include "unit_test.h"

START_TEST(easy_test) {
  char string[] = "abc";
  size_t len = 3;
  char result[len + 1];
  char expected[len + 1];
  s21_memmove(result, string, len);
  memmove(expected, string, len);
  ck_assert_mem_eq(result, expected, len * sizeof(char));
}

START_TEST(empty_string) {
  char string[] = "";
  size_t len = 0;
  char result[len + 1];
  char expected[len + 1];
  s21_memmove(result, string, len);
  memmove(expected, string, len);
  ck_assert_mem_eq(result, expected, len * sizeof(char));
}

START_TEST(string_with_register) {
  char string[] = "Abc";
  size_t len = 3;
  char result[len + 1];
  char expected[len + 1];
  s21_memmove(result, string, len);
  memmove(expected, string, len);
  ck_assert_mem_eq(result, expected, len * sizeof(char));
}

START_TEST(occur_mem) {
  char string1[] = "1234567890";
  char* str1 = string1;
  char* str2 = string1 + 2;
  size_t len = 8;
  s21_memmove(str2, str1, len * sizeof(char));

  char string2[] = "1234567890";
  char* str3 = string2;
  char* str4 = string2 + 2;
  memmove(str4, str3, len);
  ck_assert_mem_eq(str2, str4, len * sizeof(char));
}

START_TEST(long_string) {
  char string[] = "doiuwj9dh1387hdHAWHDAW wwahdA Hd87h1 7eho21e 21";
  size_t len = 10;
  char result[len + 1];
  char expected[len + 1];
  s21_memmove(result, string, len);
  memmove(expected, string, len);
  ck_assert_mem_eq(result, expected, len * sizeof(char));
}

START_TEST(float_array) {
  float string[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  size_t len = 5;
  float result[len];
  float expected[len];
  s21_memmove(result, string, len * sizeof(float));
  memmove(expected, string, len * sizeof(float));
  ck_assert_mem_eq(result, expected, len * sizeof(float));
}

START_TEST(string_with_space) {
  char string[] = "a bc";
  size_t len = 4;
  char result[len + 1];
  char expected[len + 1];
  s21_memmove(result, string, len);
  memmove(expected, string, len);
  ck_assert_mem_eq(result, expected, len * sizeof(char));
}

START_TEST(zero_move) {
  char string[] = "abc";
  size_t len = 3;
  char result[len + 1];
  char expected[len + 1];
  for (size_t i = 0; i < len; i++) {
    result[i] = '0';
    expected[i] = '0';
  }
  s21_memmove(result, string, 0);
  memmove(expected, string, 0);
  ck_assert_mem_eq(result, expected, len * sizeof(char));
}

Suite* s21_memmove_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_memmove");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, easy_test);
  tcase_add_test(tc_core, empty_string);
  tcase_add_test(tc_core, string_with_register);
  tcase_add_test(tc_core, occur_mem);
  tcase_add_test(tc_core, long_string);
  tcase_add_test(tc_core, float_array);
  tcase_add_test(tc_core, string_with_space);
  tcase_add_test(tc_core, zero_move);

  suite_add_tcase(s, tc_core);
  return s;
}
