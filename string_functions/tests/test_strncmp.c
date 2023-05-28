#include "unit_test.h"

START_TEST(equal_string) {
  char s1[] = "abc";
  char s2[] = "abc";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 3)),
                   sign_of(strncmp(s1, s2, 3)));
}
END_TEST

START_TEST(first_empty) {
  char s1[] = "";
  char s2[] = "abc";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 3)),
                   sign_of(strncmp(s1, s2, 3)));
}
END_TEST

START_TEST(second_empty) {
  char s1[] = "abc";
  char s2[] = "";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 4)),
                   sign_of(strncmp(s1, s2, 4)));
}
END_TEST

START_TEST(both_empty) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 2)),
                   sign_of(strncmp(s1, s2, 2)));
}
END_TEST

START_TEST(all_different_equal_size) {
  char s1[] = "abc";
  char s2[] = "def";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 3)),
                   sign_of(strncmp(s1, s2, 3)));
}
END_TEST

START_TEST(last_different_equal_size) {
  char s1[] = "abc";
  char s2[] = "abd";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 3)),
                   sign_of(strncmp(s1, s2, 3)));
}
END_TEST

START_TEST(all_different_first_bigger) {
  char s1[] = "Hello, World";
  char s2[] = "abc";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 12)),
                   sign_of(strncmp(s1, s2, 12)));
}
END_TEST

START_TEST(all_different_second_bigger) {
  char s1[] = "abc";
  char s2[] = "Hello, World";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 12)),
                   sign_of(strncmp(s1, s2, 12)));
}
END_TEST

START_TEST(zero_n_parameter) {
  char s1[] = "dqwdq qfwe fwq";
  char s2[] = "Hello, World";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 0)),
                   sign_of(strncmp(s1, s2, 0)));
}
END_TEST

START_TEST(equal_by_n_parameter) {
  char s1[] = "abwdq qfwe fwq";
  char s2[] = "abllo, World";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 2)),
                   sign_of(strncmp(s1, s2, 2)));
}
END_TEST

START_TEST(not_equal_by_n_parameter) {
  char s1[] = "afwdq qfwe fwq";
  char s2[] = "abllo, World";
  ck_assert_int_eq(sign_of(s21_strncmp(s1, s2, 2)),
                   sign_of(strncmp(s1, s2, 2)));
}
END_TEST

Suite* s21_strncmp_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strncmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, equal_string);
  tcase_add_test(tc_core, first_empty);
  tcase_add_test(tc_core, second_empty);
  tcase_add_test(tc_core, both_empty);
  tcase_add_test(tc_core, all_different_equal_size);
  tcase_add_test(tc_core, last_different_equal_size);
  tcase_add_test(tc_core, all_different_first_bigger);
  tcase_add_test(tc_core, all_different_second_bigger);
  tcase_add_test(tc_core, zero_n_parameter);
  tcase_add_test(tc_core, equal_by_n_parameter);
  tcase_add_test(tc_core, not_equal_by_n_parameter);

  suite_add_tcase(s, tc_core);
  return s;
}
