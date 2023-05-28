#include "unit_test.h"

START_TEST(find_3_in_1_9) {
  char string[] = "1234567890";
  char c = '3';
  size_t n = 10;
  ck_assert_ptr_eq(s21_memchr(string, c, n), memchr(string, c, n));
}
END_TEST

START_TEST(end_of_string) {
  char string[] = "1234567890";
  char c = '\0';
  size_t n = 11;
  ck_assert_ptr_eq(s21_memchr(string, c, n), memchr(string, c, n));
}
END_TEST

START_TEST(empty_string) {
  char string[] = "";
  char c = '3';
  size_t n = 0;
  ck_assert_ptr_eq(s21_memchr(string, c, n), memchr(string, c, n));
}

START_TEST(num_in_array) {
  float array[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  float num = 3.0;
  size_t n = 5 * sizeof(float);
  ck_assert_ptr_eq(s21_memchr(array, num, n), memchr(array, num, n));
}

START_TEST(num_not_in_array) {
  float array[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  float num = 6.0;
  size_t n = 5 * sizeof(float);
  ck_assert_ptr_eq(s21_memchr(array, num, n), memchr(array, num, n));
}

START_TEST(long_string) {
  char string[] =
      "21SCHOOL IS THE BEST SCHOOL IN THE WORLD YOOOOOedWDUIH@U!DBUI@!DU!HDO21";
  char c = '!';
  size_t n = s21_strlen(string);
  ck_assert_ptr_eq(s21_memchr(string, c, n), memchr(string, c, n));
}

START_TEST(no_char) {
  char string[] = "ABC";
  char c = '!';
  size_t n = 3;
  ck_assert_ptr_eq(s21_memchr(string, c, n), memchr(string, c, n));
}

Suite* s21_memchr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_memchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, find_3_in_1_9);
  tcase_add_test(tc_core, end_of_string);
  tcase_add_test(tc_core, empty_string);
  tcase_add_test(tc_core, num_in_array);
  tcase_add_test(tc_core, num_not_in_array);
  tcase_add_test(tc_core, long_string);
  tcase_add_test(tc_core, no_char);

  suite_add_tcase(s, tc_core);
  return s;
}