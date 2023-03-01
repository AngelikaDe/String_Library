#include "unit_test.h"

START_TEST(all_errors) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(negative) { ck_assert_str_eq(s21_strerror(-1), strerror(-1)); }
END_TEST

Suite* s21_strerror_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, all_errors);
  tcase_add_test(tc_core, negative);

  suite_add_tcase(s, tc_core);
  return s;
}
