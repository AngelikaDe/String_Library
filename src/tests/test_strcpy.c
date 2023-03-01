#include "unit_test.h"

START_TEST(simple_test) {
  char string1[] = "Shelby ";
  char result[9] = "Walk";
  char expected[9] = "Walk";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(simple_test2) {
  char string1[] = "Walk";
  char result[20] = "Letsgooo12345zxc";
  char expected[20] = "Letsgooo12345zxc";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(all_empty) {
  char string1[] = "";
  char result[] = "";
  char expected[] = "";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(first_empty) {
  char string1[] = "";
  char result[6] = "Walk";
  char expected[6] = "Walk";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(second_empty) {
  char string1[] = "Another one";
  char result[12] = "";
  char expected[12] = "";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(with_end_of1) {
  char string1[] = "Boy\0 and girl";
  char result[15] = "Paseka";
  char expected[15] = "Paseka";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(with_end_of2) {
  char string1[] = "Boy";
  char result[] = "Paseka\0 and honey";
  char expected[] = "Paseka\0 and honey";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(with_end_of3) {
  char string1[] = "\0";
  char result[] = "Paseka\0 and honey";
  char expected[] = "Paseka\0 and honey";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(identical) {
  char string1[] = "Look_at_me";
  char result[] = "Look_at_me";
  char expected[] = "Look_at_me";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

START_TEST(ultra_long) {
  char string1[] =
      "aspjdassadhdsakhdsadhsahdsipasdhpsashdphsahp129383913127_12 123";
  char result[] =
      "sadiodhsahdiosaiasodhidsihoadsihosaihodsiohsaiohisadhiosioadioasdsadsa";
  char expected[] =
      "sadiodhsahdiosaiasodhidsihoadsihosaihodsiohsaiohisadhiosioadioasdsadsa";
  ck_assert_pstr_eq(s21_strcpy(result, string1), strcpy(expected, string1));
}
END_TEST

Suite* s21_strcpy_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_test);
  tcase_add_test(tc_core, simple_test2);
  tcase_add_test(tc_core, all_empty);
  tcase_add_test(tc_core, first_empty);
  tcase_add_test(tc_core, second_empty);
  tcase_add_test(tc_core, with_end_of1);
  tcase_add_test(tc_core, with_end_of2);
  tcase_add_test(tc_core, with_end_of3);
  tcase_add_test(tc_core, identical);
  tcase_add_test(tc_core, ultra_long);

  suite_add_tcase(s, tc_core);
  return s;
}