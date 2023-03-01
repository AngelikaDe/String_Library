#include "unit_test.h"

START_TEST(all_low) {
  char s1[] = "SCHOOL21!!!";
  char s2[] = "school21!!!";
  char *res = s21_to_lower(s1);
  ck_assert_pstr_eq(res, s2);
  free(res);
}
END_TEST

START_TEST(mixed_register) {
  char s1[] = "ScHoOl21!!!";
  char s2[] = "school21!!!";
  char *res = s21_to_lower(s1);
  ck_assert_pstr_eq(res, s2);
  free(res);
}
END_TEST

START_TEST(mixed_cahr) {
  char s1[] = "Sc1234567890-+?z/cxzemr`[]{}/'\nHoOl21!!!";
  char s2[] = "sc1234567890-+?z/cxzemr`[]{}/'\nhool21!!!";
  char *res = s21_to_lower(s1);
  ck_assert_pstr_eq(res, s2);
  free(res);
}
END_TEST

START_TEST(empty_cahr) {
  char s1[] = "";
  char s2[] = "";
  char *res = s21_to_lower(s1);
  ck_assert_pstr_eq(res, s2);
  free(res);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_to_lower");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, all_low);
  tcase_add_test(tc_core, mixed_register);
  tcase_add_test(tc_core, mixed_cahr);
  tcase_add_test(tc_core, empty_cahr);

  suite_add_tcase(s, tc_core);
  return s;
}
