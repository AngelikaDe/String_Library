#include "unit_test.h"

START_TEST(eq_strs) {
  char string1[] = "1234567890";
  char string2[] = "1234567890";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(random_str) {
  char string1[] = "qweerttyyuiurytytrr";
  char string2[] = "sdfdsfdsfwsdfdsfdsfdsf";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(no_eq_str) {
  char string1[] = "1234567890";
  char string2[] = "qweerrtyyyu";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(empty1_str) {
  char string1[] = "";
  char string2[] = "qwqw";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(empty2_str) {
  char string1[] = "qwe";
  char string2[] = "";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(empty3_str) {
  char string1[] = "";
  char string2[] = "";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(end_in_midle1_str) {
  char string1[] = "qwer\0qwert";
  char string2[] = "t";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(end_in_midle2_str) {
  char string1[] = "t";
  char string2[] = "qwer\0qwert";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(new_line_str) {
  char string1[] = "\n";
  char string2[] = "qw\ner\0qwert";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

START_TEST(empty_find_str) {
  char string1[] = "\0";
  char string2[] = "qw\ner\0qwert";
  ck_assert_ptr_eq(s21_strpbrk(string1, string2), strpbrk(string1, string2));
}
END_TEST

Suite* s21_strpbrk_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strpbrk");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, eq_strs);
  tcase_add_test(tc_core, random_str);
  tcase_add_test(tc_core, no_eq_str);
  tcase_add_test(tc_core, empty1_str);
  tcase_add_test(tc_core, empty2_str);
  tcase_add_test(tc_core, empty3_str);
  tcase_add_test(tc_core, end_in_midle1_str);
  tcase_add_test(tc_core, end_in_midle2_str);
  tcase_add_test(tc_core, new_line_str);
  tcase_add_test(tc_core, empty_find_str);

  suite_add_tcase(s, tc_core);
  return s;
}
