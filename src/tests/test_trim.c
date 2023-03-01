#include "unit_test.h"

START_TEST(one_char) {
  char s1[] = "!!!school21!!!!";
  char s2[] = "!";
  char s3[] = "school21";
  char *res = s21_trim(s1, s2);
  ck_assert_pstr_eq(res, s3);
  free(res);
}
END_TEST

START_TEST(several_char) {
  char s1[] = "!#!@!school21!!!@@@@!";
  char s2[] = "!@#";
  char s3[] = "school21";
  char *res = s21_trim(s1, s2);
  ck_assert_pstr_eq(res, s3);
  free(res);
}
END_TEST

START_TEST(no_char) {
  char s1[] = "!#!@!school21!!!@@@@!";
  char s2[] = "";
  char s3[] = "!#!@!school21!!!@@@@!";
  char *res = s21_trim(s1, s2);
  ck_assert_pstr_eq(res, s3);
  free(res);
}
END_TEST

START_TEST(result_empty_str) {
  char s1[] = "!!!!!!!!!!!!!!";
  char s2[] = "!";
  char s3[] = "";
  char *res = s21_trim(s1, s2);
  ck_assert_pstr_eq(res, s3);
  free(res);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_trim");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, one_char);
  tcase_add_test(tc_core, several_char);
  tcase_add_test(tc_core, no_char);
  tcase_add_test(tc_core, result_empty_str);

  suite_add_tcase(s, tc_core);
  return s;
}
