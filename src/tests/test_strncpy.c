#include "unit_test.h"

START_TEST(without_zero) {
  char str[] = "abc";
  size_t len = sizeof(str) / sizeof(str[0]);
  char result[len + 1];
  char expected[len + 1];
  s21_strncpy(result, str, len - 1);
  strncpy(expected, str, len - 1);
  ck_assert_mem_eq(result, expected, (len - 1) * sizeof(char));
}
END_TEST

START_TEST(full_string) {
  char str[] = "abc";
  size_t len = sizeof(str) / sizeof(str[0]);
  char result[len + 2];
  char expected[len + 2];
  s21_strncpy(result, str, len);
  strncpy(expected, str, len);
  ck_assert_mem_eq(result, expected, len * sizeof(char));
}
END_TEST

START_TEST(part_of_string) {
  char str[] = "abc";
  size_t len = sizeof(str) / sizeof(str[0]);
  char result[len + 1];
  char expected[len + 1];
  s21_strncpy(result, str, len);
  strncpy(expected, str, len);
  ck_assert_mem_eq(result, expected, 2 * sizeof(char));
}
END_TEST

START_TEST(big_string) {
  char str[] = "doiuwj9dh1387hdHAWHDAW wwahdA Hd87h1 7eho21e 21";
  size_t len = sizeof(str) / sizeof(str[0]);
  char result[len + 1];
  char expected[len + 1];
  s21_strncpy(result, str, len);
  strncpy(expected, str, len);
  ck_assert_mem_eq(result, expected, len);
}
END_TEST

START_TEST(bigger_than_string) {
  char str[] = "abc";
  char result[6];
  char expected[6];
  s21_strncpy(result, str, 5);
  strncpy(expected, str, 5);
  ck_assert_mem_eq(result, expected, 4 * sizeof(char));
}
END_TEST

START_TEST(empty_string) {
  char str[] = "";
  char result[6];
  char expected[6];
  s21_strncpy(result, str, 5);
  strncpy(expected, str, 5);
  ck_assert_mem_eq(result, expected, 1 * sizeof(char));
}
END_TEST

Suite* s21_strncpy_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strncpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, without_zero);
  tcase_add_test(tc_core, full_string);
  tcase_add_test(tc_core, part_of_string);
  tcase_add_test(tc_core, big_string);
  tcase_add_test(tc_core, bigger_than_string);
  tcase_add_test(tc_core, empty_string);

  suite_add_tcase(s, tc_core);
  return s;
}
