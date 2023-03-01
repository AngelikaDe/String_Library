#include "unit_test.h"

START_TEST(simple_test) {
  char string[] = "Shelby ";
  char symbol = 'h';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(simple_test2) {
  char string[] = "Shelby ";
  char symbol = ' ';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(simple_test3) {
  char string[] = "Shelby ";
  char symbol = 'S';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(simple_test4) {
  char string[] = "Shelby ";
  char symbol = 's';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(not_find) {
  char string[] = "Shelby ";
  char symbol = 'M';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(end_of_str) {
  char string[] = "Shelby ";
  char symbol = '\0';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(empty_str) {
  char string[] = "";
  char symbol = 'l';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(char_ten) {
  char string[] = "Shelby_WALK";
  char symbol = 10;
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(end_of_str2) {
  char string[] = "Shelby_WALK\0laksdlksaldk";
  char symbol = '\0';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

START_TEST(end_of_str3) {
  char string[] = "Shelby_WALK\0laksdlksaldk2sasd";
  char symbol = '2';
  ck_assert_pstr_eq(s21_strchr(string, symbol), strchr(string, symbol));
}
END_TEST

Suite* s21_strchr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_test);
  tcase_add_test(tc_core, simple_test2);
  tcase_add_test(tc_core, simple_test3);
  tcase_add_test(tc_core, simple_test4);
  tcase_add_test(tc_core, not_find);
  tcase_add_test(tc_core, end_of_str);
  tcase_add_test(tc_core, empty_str);
  tcase_add_test(tc_core, char_ten);
  tcase_add_test(tc_core, end_of_str2);
  tcase_add_test(tc_core, end_of_str3);

  suite_add_tcase(s, tc_core);
  return s;
}