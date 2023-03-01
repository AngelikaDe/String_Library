#include "unit_test.h"

START_TEST(simple_str) {
  char string1[] = "abcdeaaaaqqqqqqqq";
  char string2[] = "abcde";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(no_seg_str) {
  char string1[] = "qqqqqqqqqq";
  char string2[] = "abcde";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(simple_reverse_str) {
  char string1[] = "qqqqqqqqabcdeaaaaqqqqqqqq";
  char string2[] = "abcde";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(same_patern_str) {
  char string1[] = "qqqqqqqqabcdeaaaaqqqqqqqq";
  char string2[] = "qqqqqqqqq";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(same_str) {
  char string1[] = "qqqqqqqqq";
  char string2[] = "qqqqqqqqq";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(patern_with_end_str) {
  char string1[] = "qaqaqqaae";
  char string2[] = "q\0a";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(end_srt) {
  char string1[] = "qaqaqqa\0ae";
  char string2[] = "qq";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(new_line_str) {
  char string1[] = "qaqa\nqawqaae";
  char string2[] = "q\nq";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(tab_serch_str) {
  char string1[] = "q\t\tqa\nqawqaae";
  char string2[] = "\t";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(empty_patern_str) {
  char string1[] = "q\t\tqa\nqawqaae";
  char string2[] = "";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(empty_str) {
  char string1[] = "";
  char string2[] = "q";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(bouth_empty_str) {
  char string1[] = "";
  char string2[] = "";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

START_TEST(end_str) {
  char string1[] = "\0";
  char string2[] = "\0";
  ck_assert_int_eq(s21_strspn(string1, string2), strspn(string1, string2));
}
END_TEST

Suite* s21_strspn_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_str);
  tcase_add_test(tc_core, no_seg_str);
  tcase_add_test(tc_core, simple_reverse_str);
  tcase_add_test(tc_core, same_patern_str);
  tcase_add_test(tc_core, same_str);
  tcase_add_test(tc_core, patern_with_end_str);
  tcase_add_test(tc_core, end_srt);
  tcase_add_test(tc_core, new_line_str);
  tcase_add_test(tc_core, tab_serch_str);
  tcase_add_test(tc_core, empty_patern_str);
  tcase_add_test(tc_core, empty_str);
  tcase_add_test(tc_core, bouth_empty_str);
  tcase_add_test(tc_core, end_str);

  suite_add_tcase(s, tc_core);
  return s;
}
