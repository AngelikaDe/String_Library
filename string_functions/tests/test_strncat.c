#include "unit_test.h"

START_TEST(simple) {
  char string1[50] = "1234567890";
  char string2[] = "qweqwrrrr";
  size_t n = 5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(zerosize) {
  char string1[50] = "1234567890";
  char string2[] = "qweqwrrrr";
  size_t n = 0;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(more_tahn_str) {
  char string1[50] = "1234567890";
  char string2[] = "qweqwrrrr";
  size_t n = 100;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(minus_size) {
  char string1[50] = "1234567890";
  char string2[] = "qweqwrrrr";
  size_t n = -5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(empty1_str) {
  char string1[50] = "";
  char string2[] = "qweqwrrrr";
  size_t n = 5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(empty2_str) {
  char string1[50] = "qweqwrrrr";
  char string2[] = "";
  size_t n = 5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(with_end_of1) {
  char string1[50] = "1234567890";
  char string2[] = "qweqw\0rrrr";
  size_t n = 5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(with_end_of2) {
  char string1[50] = "1234\0 567890";
  char string2[] = "qweqwrrrr";
  size_t n = 5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(with_end_of3) {
  char string1[50] = "\0";
  char string2[] = "qweqwrrrr";
  size_t n = 5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

START_TEST(with_end_of4) {
  char string1[50] = "qweqwrrrr";
  char string2[] = "\0";
  size_t n = 5;
  ck_assert_pstr_eq(s21_strncat(string1, string2, n),
                    strncat(string1, string2, n));
}
END_TEST

Suite* s21_strncat_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strncat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple);
  tcase_add_test(tc_core, zerosize);
  tcase_add_test(tc_core, more_tahn_str);
  tcase_add_test(tc_core, minus_size);
  tcase_add_test(tc_core, empty1_str);
  tcase_add_test(tc_core, empty2_str);
  tcase_add_test(tc_core, with_end_of1);
  tcase_add_test(tc_core, with_end_of2);
  tcase_add_test(tc_core, with_end_of3);
  tcase_add_test(tc_core, with_end_of4);

  suite_add_tcase(s, tc_core);
  return s;
}
