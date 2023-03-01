#include "unit_test.h"

START_TEST(easy_test) {
  char string[] = "abc";
  size_t len = 3;
  char result[len + 1];
  char expected[len + 1];
  s21_memcpy(result, string, len);
  memcpy(expected, string, len);
  ck_assert_mem_eq(result, expected, len);
}

START_TEST(empty_string) {
  char string[] = "";
  size_t len = 0;
  char result[len + 1];
  char expected[len + 1];
  s21_memcpy(result, string, len);
  memcpy(expected, string, len);
  ck_assert_mem_eq(result, expected, len);
}

START_TEST(string_with_register) {
  char string[] = "Abc";
  size_t len = 3;
  char result[len + 1];
  char expected[len + 1];
  s21_memcpy(result, string, len);
  memcpy(expected, string, len);
  ck_assert_mem_eq(result, expected, len);
}

START_TEST(string_with_space) {
  char string[] = "a bc";
  size_t len = 4;
  char result[len + 1];
  char expected[len + 1];
  s21_memcpy(result, string, len);
  memcpy(expected, string, len);
  ck_assert_mem_eq(result, expected, len);
}

START_TEST(zero_len) {
  char string[] = "abc";
  size_t len = 3;
  char result[len + 1];
  char expected[len + 1];
  for (size_t i = 0; i < len; i++) {
    result[i] = 'a';
    expected[i] = 'a';
  }
  s21_memcpy(result, string, 0);
  memcpy(expected, string, 0);
  ck_assert_mem_eq(result, expected, len);
}

START_TEST(string_with_null) {
  char string[] = "a\0c";
  size_t len = 3;
  char result[len + 1];
  char expected[len + 1];
  s21_memcpy(result, string, len);
  memcpy(expected, string, len);
  ck_assert_mem_eq(result, expected, len);
}

START_TEST(long_string) {
  char string[] = "doiuwj9dh1387hdHAWHDAW wwahdA Hd87h1 7eho21e 21";
  size_t len = 10;
  char result[len + 1];
  char expected[len + 1];
  s21_memcpy(result, string, len);
  memcpy(expected, string, len);
  ck_assert_mem_eq(result, expected, len);
}

START_TEST(float_array) {
  float string[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  size_t len = 5;
  float result[len];
  float expected[len];
  s21_memcpy(result, string, len * sizeof(float));
  memcpy(expected, string, len * sizeof(float));
  ck_assert_mem_eq(result, expected, len * sizeof(float));
}

START_TEST(int_array) {
  int string[] = {1, 2, 3, 4, 5};
  size_t len = 5;
  int result[len];
  int expected[len];
  s21_memcpy(result, string, len * sizeof(int));
  memcpy(expected, string, len * sizeof(int));
  ck_assert_mem_eq(result, expected, len * sizeof(int));
}

Suite* s21_memcpy_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_memcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, easy_test);
  tcase_add_test(tc_core, empty_string);
  tcase_add_test(tc_core, string_with_register);
  tcase_add_test(tc_core, string_with_space);
  tcase_add_test(tc_core, zero_len);
  tcase_add_test(tc_core, string_with_null);
  tcase_add_test(tc_core, long_string);
  tcase_add_test(tc_core, float_array);
  tcase_add_test(tc_core, int_array);

  suite_add_tcase(s, tc_core);
  return s;
}