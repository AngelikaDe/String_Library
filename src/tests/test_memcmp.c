#include "unit_test.h"

START_TEST(equal_lines) {
  char string1[] = "1234567890";
  char string2[] = "1234567890";
  size_t n = 10;
  ck_assert_int_eq(s21_memcmp(string1, string2, n),
                   memcmp(string1, string2, n));
}
END_TEST

START_TEST(first_char) {
  char string1[] = "1234567890";
  char string2[] = "2234567890";
  size_t n = 10;
  ck_assert_int_eq(s21_memcmp(string1, string2, n),
                   memcmp(string1, string2, n));
}

START_TEST(upper_lower_case) {
  char string1[] = "Hello";
  char string2[] = "hello";
  size_t n = 5;
  ck_assert_int_eq(s21_memcmp(string1, string2, n),
                   memcmp(string1, string2, n));
}

START_TEST(empty_string) {
  char string1[] = "";
  char string2[] = "";
  size_t n = 0;
  ck_assert_int_eq(s21_memcmp(string1, string2, n),
                   memcmp(string1, string2, n));
}

START_TEST(num_in_array) {
  float array1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  float array2[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  size_t n = 5 * sizeof(float);
  ck_assert_int_eq(s21_memcmp(array1, array2, n), memcmp(array1, array2, n));
}

START_TEST(long_strings) {
  char string1[] = "abcdefghijklmnopqrstuvwxyz";
  char string2[] = "abcdefghijklmnopqrstuvwxy!";
  size_t n = 26;
  ck_assert_int_eq(s21_memcmp(string1, string2, n),
                   memcmp(string1, string2, n));
}

START_TEST(occur_mem) {
  char string1[] = "1234567890";
  char* str1 = string1;
  char* str2 = string1 + 2;
  size_t n = 8;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}

START_TEST(zero_len) {
  char string1[] = "1234567890";
  char string2[] = "1234567890";
  size_t n = 0;
  ck_assert_int_eq(s21_memcmp(string1, string2, n),
                   memcmp(string1, string2, n));
}

Suite* s21_memcmp_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_memcmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, equal_lines);
  tcase_add_test(tc_core, first_char);
  tcase_add_test(tc_core, upper_lower_case);
  tcase_add_test(tc_core, empty_string);
  tcase_add_test(tc_core, num_in_array);
  tcase_add_test(tc_core, long_strings);
  tcase_add_test(tc_core, occur_mem);
  tcase_add_test(tc_core, zero_len);

  suite_add_tcase(s, tc_core);
  return s;
}