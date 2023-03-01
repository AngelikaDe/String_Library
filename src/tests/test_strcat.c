#include "unit_test.h"

START_TEST(simple_test) {
  char string1[] = "Shelby ";
  char result[12] = "Walk";
  char expected[12] = "Walk";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(simple_test2) {
  char string1[] = "Work";
  char result[35] = "Rabota_ne_Walk_rabota_eto ";
  char expected[35] = "Rabota_ne_Walk_rabota_eto ";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(simple_test3) {
  char string1[] = "a";
  char result[3] = "b";
  char expected[3] = "b";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(all_empty) {
  char string1[] = "";
  char result[3] = "";
  char expected[3] = "";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(first_empty) {
  char string1[] = "Another 1";
  char result[11] = "";
  char expected[11] = "";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(second_empty) {
  char string1[] = "";
  char result[13] = "Big pchela";
  char expected[13] = "Big pchela";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(one_symbol) {
  char string1[] = "n";
  char result[35] = "dfskjosdopfjpsdojfpsdojfdjpos";
  char expected[35] = "dfskjosdopfjpsdojfpsdojfdjpos";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(with_end_of1) {
  char string1[] = "Boy\0 and girl";
  char result[30] = "Paseka";
  char expected[30] = "Paseka";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(with_end_of2) {
  char string1[] = "Boy";
  char result[] = "Paseka\0 and honey";
  char expected[] = "Paseka\0 and honey";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(with_end_of3) {
  char string1[] = "\0";
  char result[25] = "Paseka\0 and honey";
  char expected[25] = "Paseka\0 and honey";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(identical) {
  char string1[] = "Look_at_me";
  char result[25] = "Look_at_me";
  char expected[25] = "Look_at_me";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

START_TEST(ultra_mega_long) {
  char string1[] =
      "aspjdassadhdsakhdsadhsahdsipasdhpsashdphsahp129383913127_12 123";
  char result[150] =
      "sadiodhsahdiosaiasodhidsihoadsihosaihodsiohsaiohisadhiosioadioasdsadsa";
  char expected[150] =
      "sadiodhsahdiosaiasodhidsihoadsihosaihodsiohsaiohisadhiosioadioasdsadsa";
  ck_assert_pstr_eq(s21_strcat(result, string1), strcat(expected, string1));
}
END_TEST

Suite* s21_strcat_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strcat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_test);
  tcase_add_test(tc_core, simple_test2);
  tcase_add_test(tc_core, simple_test3);
  tcase_add_test(tc_core, all_empty);
  tcase_add_test(tc_core, first_empty);
  tcase_add_test(tc_core, second_empty);
  tcase_add_test(tc_core, one_symbol);
  tcase_add_test(tc_core, with_end_of1);
  tcase_add_test(tc_core, with_end_of2);
  tcase_add_test(tc_core, with_end_of3);
  tcase_add_test(tc_core, identical);
  tcase_add_test(tc_core, ultra_mega_long);

  suite_add_tcase(s, tc_core);
  return s;
}