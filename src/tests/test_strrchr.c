#include "unit_test.h"

START_TEST(simple_str) {
  char string[] = "abcde";
  char c = 'e';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(empty1_str) {
  char string[] = "";
  char c = 'e';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(empty2_str) {
  char string[] = "";
  char c = 'e';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(empty3_str) {
  char string[] = "eeeeeeee";
  char c = '\0';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(empty4_str) {
  char string[] = "";
  char c = '\0';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(two_way_str) {
  char string[] = "qeqqqqqeq";
  char c = 'e';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(no_char_str) {
  char string[] = "qqqqqqqqqqq";
  char c = 'e';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(one_way_str) {
  char string[] = "qqqqqqqqqqe";
  char c = 'e';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(endof_str) {
  char string[] = "qqqqqqqqqqe";
  char c = '\0';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(new_line_str) {
  char string[] = "qqqqqqq\nqqqe\n";
  char c = '\n';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

START_TEST(tab_str) {
  char string[] = "qqqqqqq\tqqqe\n";
  char c = '\t';
  ck_assert_ptr_eq(s21_strrchr(string, c), strrchr(string, c));
}
END_TEST

Suite* s21_strrchr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strrchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_str);
  tcase_add_test(tc_core, empty1_str);
  tcase_add_test(tc_core, empty2_str);
  tcase_add_test(tc_core, empty3_str);
  tcase_add_test(tc_core, empty4_str);
  tcase_add_test(tc_core, two_way_str);
  tcase_add_test(tc_core, no_char_str);
  tcase_add_test(tc_core, one_way_str);
  tcase_add_test(tc_core, endof_str);
  tcase_add_test(tc_core, new_line_str);
  tcase_add_test(tc_core, tab_str);

  suite_add_tcase(s, tc_core);
  return s;
}
