#include "unit_test.h"

START_TEST(two_empty_string) {
  char string[] = "";
  char string2[] = "";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(first_empty_string) {
  char string[] = "";
  char string2[] = "abc";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(second_empty_string) {
  char string[] = "abc";
  char string2[] = "";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(identical_strings) {
  char string[] = "abcde.zxc";
  char string2[] = "abcde.zxc";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(identical_nonasci_strings) {
  char string[] = "Пасека";
  char string2[] = "Пасека";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(sad_fun) {
  char string[] = "Sad story";
  char string2[] = "Fun story";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(another_one_two) {
  char string[] = "Another one";
  char string2[] = "Another two";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(lower_and_upper) {
  char string[] = "letsgo";
  char string2[] = "LETSGO";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(upper_and_lower) {
  char string[] = "BIG";
  char string2[] = "big";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(strings_with_slash) {
  char string[] = "zxc\ngood night";
  char string2[] = "zxc\tgood night";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(numbers_and_signs) {
  char string[] = "15+12321-1231312";
  char string2[] = "15+12321321";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(first_string_shorter) {
  char string[] = "Awesome review";
  char string2[] = "Awesome review, sir";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

START_TEST(second_string_shorter) {
  char string[] = "Awesome review, sir! Good night!";
  char string2[] = "Awesome review, sir";
  ck_assert_int_eq(sign_of(s21_strcmp(string, string2)),
                   sign_of(strcmp(string, string2)));
}
END_TEST

Suite* s21_strcmp_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strcmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, two_empty_string);
  tcase_add_test(tc_core, first_empty_string);
  tcase_add_test(tc_core, second_empty_string);
  tcase_add_test(tc_core, identical_strings);
  tcase_add_test(tc_core, identical_nonasci_strings);
  tcase_add_test(tc_core, sad_fun);
  tcase_add_test(tc_core, another_one_two);
  tcase_add_test(tc_core, lower_and_upper);
  tcase_add_test(tc_core, upper_and_lower);
  tcase_add_test(tc_core, strings_with_slash);
  tcase_add_test(tc_core, numbers_and_signs);
  tcase_add_test(tc_core, first_string_shorter);
  tcase_add_test(tc_core, second_string_shorter);

  suite_add_tcase(s, tc_core);
  return s;
}
