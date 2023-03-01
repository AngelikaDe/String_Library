#include "unit_test.h"

START_TEST(null_str) {
  char string[] = "";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(random_str) {
  char string[] =
      "21SCHOOL IS THE BEST SCHOOL IN THE WORLD YOOOOOedWDUIH@U!DBUI@!DU!HDO21";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(with_end_str) {
  char string[] =
      "21SCHOOL IS THE BEST SCHOOL\0IN THE WORLD "
      "YOOOOOedWDUIH@U!DBUI@!DU!HDO21";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(with_new_line_str) {
  char string[] =
      "21SCHOOL IS THE BEST SCHOOL\nIN THE WORLD "
      "YOOOOOedWDUIH@U!DBUI@!DU!HDO21";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(with_end_in_end_str) {
  char string[] =
      "21SCHOOL IS THE BEST SCHOOL IN THE WORLD "
      "YOOOOOedWDUIH@U!DBUI@!DU!HDO21\0";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(one_char_str) {
  char string[] = "0";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(one_new_line_str) {
  char string[] = "\n";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(one_end_str) {
  char string[] = "\0";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

START_TEST(with_tab_str) {
  char string[] =
      "21SCHOOL\tIS THE BEST SCHOOL IN THE WORLD "
      "YOOOOOedWDUIH@U!DBUI@!DU!HDO21";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}
END_TEST

Suite* s21_strlen_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strlen");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, null_str);
  tcase_add_test(tc_core, random_str);
  tcase_add_test(tc_core, with_end_str);
  tcase_add_test(tc_core, with_new_line_str);
  tcase_add_test(tc_core, with_end_in_end_str);
  tcase_add_test(tc_core, one_char_str);
  tcase_add_test(tc_core, one_new_line_str);
  tcase_add_test(tc_core, one_end_str);
  tcase_add_test(tc_core, with_tab_str);

  suite_add_tcase(s, tc_core);
  return s;
}
