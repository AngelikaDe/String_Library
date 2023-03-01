#include "unit_test.h"

START_TEST(in_middle) {
  char s1[] = "school21!!!";
  char s2[] = "SCHOOL21!!!";
  char s3[] = "schooSCHOOL21!!!l21!!!";
  char *res = s21_insert(s1, s2, 5);
  ck_assert_pstr_eq(res, s3);
  free(res);
}
END_TEST

START_TEST(in_start) {
  char s1[] = "school21!!!";
  char s2[] = "SCHOOL21!!!";
  char s3[] = "SCHOOL21!!!school21!!!";
  char *res = s21_insert(s1, s2, 0);
  ck_assert_pstr_eq(res, s3);
  free(res);
}
END_TEST

START_TEST(in_end) {
  char s1[] = "school21!!!";
  char s2[] = "SCHOOL21!!!";
  char s3[] = "school21!!!SCHOOL21!!!";
  char *res = s21_insert(s1, s2, 11);
  ck_assert_pstr_eq(res, s3);
  free(res);
}
END_TEST

START_TEST(minus_size) {
  char s1[] = "school21!!!";
  char s2[] = "SCHOOL21!!!";
  char *res = s21_insert(s1, s2, -1);
  ck_assert_pstr_eq(res, NULL);
  free(res);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_insert");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, in_middle);
  tcase_add_test(tc_core, in_start);
  tcase_add_test(tc_core, in_end);
  tcase_add_test(tc_core, minus_size);

  suite_add_tcase(s, tc_core);
  return s;
}
