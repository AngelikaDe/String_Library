#include "unit_test.h"

START_TEST(equal_string) {
  char s1[] = "abc";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(from_start) {
  char s1[] = "abcde";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(in_the_middle) {
  char s1[] = "dabce";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(end_of_string) {
  char s1[] = "Hello, abc";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(in_empty_string) {
  char s1[] = "";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(search_for_empty_string) {
  char s1[] = "abc";
  char s2[] = "";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(both_empty) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(no_result) {
  char s1[] = "Hello, world";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(partially_match_start) {
  char s1[] = "ab, Hello";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(partially_match_end) {
  char s1[] = "Hello, ab";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(partially_match_middle) {
  char s1[] = "Hello, ab, hello";
  char s2[] = "abc";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

Suite* s21_strstr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, equal_string);
  tcase_add_test(tc_core, from_start);
  tcase_add_test(tc_core, in_the_middle);
  tcase_add_test(tc_core, end_of_string);
  tcase_add_test(tc_core, in_empty_string);
  tcase_add_test(tc_core, search_for_empty_string);
  tcase_add_test(tc_core, both_empty);
  tcase_add_test(tc_core, no_result);
  tcase_add_test(tc_core, partially_match_start);
  tcase_add_test(tc_core, partially_match_end);
  tcase_add_test(tc_core, partially_match_middle);

  suite_add_tcase(s, tc_core);
  return s;
}
