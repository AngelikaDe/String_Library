#include <check.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_memcmp_test) {
  int res = 0;
  int res_orig = 0;

  char first[] = "12345678901234567890";
  char second[] = "12345678901234567891";
  res = s21_memcmp(first, second, 19);
  res_orig = memcmp(first, second, 19);
  ck_assert_int_eq(res, res_orig);

  char first_1[] = "90123467890";
  char second_1[] = "901234567891";
  res = s21_memcmp(first_1, second_1, 10);
  res_orig = memcmp(first_1, second_1, 10);
  ck_assert_int_eq(res, res_orig);

  char first_2[] = "9012367890";
  char second_2[] = "90127891";
  res = s21_memcmp(first_2, second_2, 6);
  res_orig = memcmp(first_2, second_2, 6);
  ck_assert_int_le(res, res_orig);

  char first_3[] = "abcdef";
  char second_3[] = "ABCDEF";
  res = s21_memcmp(first_3, second_3, 5);
  res_orig = memcmp(first_3, second_3, 5);
  ck_assert_int_ge(res, res_orig);

  char first_4[] = "DWgaOtP12df0";
  char second_4[] = "DWGAOTP12DF0";
  res = s21_memcmp(first_4, second_4, 7);
  res_orig = memcmp(first_4, second_4, 7);
  ck_assert_int_ge(res, res_orig);
}
END_TEST

START_TEST(s21_memmove_test) {
  char first[] = "1234567890";
  char second[] = "1234567890";
  s21_memmove(&first[4], &first[3], 3);
  memmove(&second[4], &second[3], 3);
  ck_assert_str_eq(first, second);

  char str1_1[] = "Geeks";
  char str2_1[] = "Quiz";
  s21_memmove(str1_1, str2_1, 5);
  char str1_2[] = "Geeks";
  memmove(str1_2, str2_1, 5);
  ck_assert_str_eq(str1_1, str1_2);

  char str1_3[] = "Geeks";
  char str2_3[] = "Quiz";
  s21_memmove(str1_3, str2_3, 5);
  char str1_4[] = "Geeks";
  char str2_4[] = "Quiz";
  memmove(str1_4, str2_4, 5);
  ck_assert_str_eq(str1_4, str2_4);
}
END_TEST

START_TEST(s21_strcat_test) {
  char first[20] = {0};
  char second[20] = {0};

  s21_strcat(first, "LALALA");
  strcat(second, "LALALA");
  ck_assert_str_eq(first, second);

  s21_strcat(first, "Henlooo");
  strcat(second, "Henlooo");
  ck_assert_str_eq(first, second);

  char first_1[20] = {0};
  char second_1[20] = {0};

  s21_strcat(first_1, "");
  strcat(second_1, "");
  ck_assert_str_eq(first_1, second_1);
}
END_TEST

START_TEST(s21_strncmp_test) {
  int res = 0;
  int res_orig = 0;
  char first[] = "123456";
  char second[] = "123456789";
  res = s21_strncmp(first, second, 5);
  res_orig = strncmp(first, second, 5);
  ck_assert_int_eq(res, res_orig);

  char first_1[] = "123456909808";
  char second_1[] = "12345";
  res = strncmp(first_1, second_1, 100);
  res_orig = strncmp(first_1, second_1, 100);
  ck_assert_int_eq(res, res_orig);

  char first_2[] = "";
  char second_2[] = "123456789";
  res = s21_strncmp(first_2, second_2, 5);
  res_orig = strncmp(first_2, second_2, 5);
  ck_assert_int_eq(res, res_orig);

  char first_3[] = "12346909808";
  char second_3[] = "62345";
  res = strncmp(first_3, second_3, 10);
  res_orig = strncmp(first_3, second_3, 10);
  ck_assert_int_eq(res, res_orig);
}
END_TEST

START_TEST(s21_strchr_test) {
  char *res = s21_NULL;
  char *res_orig = s21_NULL;
  char str[] = "123456";
  res = s21_strchr(str, '4');
  res_orig = strchr(str, '4');
  ck_assert_str_eq((char *)res, (char *)res_orig);

  char str_2[] = "HeelloWOrld";
  res = s21_strchr(str_2, 'l');
  res_orig = strchr(str_2, 'l');
  ck_assert_str_eq((char *)res, (char *)res_orig);

  char str_3[] = "HeelloWOrld";
  res = s21_strchr(str_3, 'H');
  res_orig = strchr(str_3, 'H');
  ck_assert_str_eq((char *)res, (char *)res_orig);
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str[] = "HeelloWOrld";
  char str_1[100] = {0};
  char str_2[100] = {0};
  s21_strncpy(str_1, str, 12);
  strncpy(str_2, str, 12);
  ck_assert_str_eq(str_1, str_2);

  char str_3[] = "Heell";
  char str_4[100] = {0};
  char str_5[100] = {0};
  s21_strncpy(str_4, str_3, 12);
  strncpy(str_5, str_3, 12);
  ck_assert_str_eq(str_4, str_5);
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char *res = s21_NULL;
  char *res_orig = s21_NULL;
  char str[] = "123456";
  res = s21_strchr(str, '4');
  res_orig = strchr(str, '4');
  ck_assert_str_eq((char *)res, (char *)res_orig);

  char str_2[] = "HeelloWOrld";
  res = s21_strchr(str_2, 'l');
  res_orig = strchr(str_2, 'l');
  ck_assert_str_eq((char *)res, (char *)res_orig);

  char str_3[] = "HeelloWOrld";
  res = s21_strchr(str_3, 'H');
  res_orig = strchr(str_3, 'H');
  ck_assert_str_eq((char *)res, (char *)res_orig);
}
END_TEST

START_TEST(s21_strspn_test) {
  int res = 0;
  int res_orig = 0;

  char str[11] = "0123456789";
  char str_2[10] = "210";
  res = strspn(str, str_2);
  res_orig = strspn(str, str_2);
  ck_assert_int_eq(res, res_orig);

  char str_3[11] = "123456789";
  char str_4[10] = "210";
  res = strspn(str_3, str_4);
  res_orig = strspn(str_3, str_4);
  ck_assert_int_eq(res, res_orig);

  char str_5[11] = "HelloWorld";
  char str_6[10] = "Hey";
  res = strspn(str_5, str_6);
  res_orig = strspn(str_5, str_6);
  ck_assert_int_eq(res, res_orig);

  char str_7[11] = "";
  char str_8[10] = "Hey";
  res = strspn(str_7, str_8);
  res_orig = strspn(str_7, str_8);
  ck_assert_int_eq(res, res_orig);

  char str_9[11] = "HelloWorld";
  char str_10[10] = "";
  res = strspn(str_9, str_10);
  res_orig = strspn(str_9, str_10);
  ck_assert_int_eq(res, res_orig);

  char str_11[] = "";
  char str_12[] = "";
  ck_assert_int_eq(s21_strcspn(str_11, str_12), strcspn(str_11, str_12));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str1[] = "LALALAL +_ 084t _ LALALA";
  char str2[] = "LALALAL +_ 084t _ LALALA";
  const char delims[] = "++_)(** ";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    }
  }

  char str3[] = "LALALAL +_ 084t _ LALALA";
  char str4[] = "LALALAL +_ 084t _ LALALA";
  const char delims1[] = "";

  char *got1 = s21_strtok(str3, delims1);
  char *expected1 = strtok(str4, delims1);

  ck_assert_uint_eq(s21_strlen(got1), s21_strlen(expected1));
  ck_assert_str_eq(got1, expected1);

  while (got1 && expected1) {
    got1 = s21_strtok(NULL, delims1);
    expected1 = strtok(NULL, delims1);

    if (got1 || expected1) {
      ck_assert_str_eq(got1, expected1);
    }
  }

  char str5[] = "LALALAL084tLALALA";
  char str6[] = "LALALAL084tLALALA";
  const char delims2[] = "+_))(_)";

  char *got2 = s21_strtok(str5, delims2);
  char *expected2 = strtok(str6, delims2);

  ck_assert_uint_eq(s21_strlen(got2), s21_strlen(expected2));
  ck_assert_str_eq(got2, expected2);

  while (got2 && expected2) {
    got2 = s21_strtok(NULL, delims2);
    expected2 = strtok(NULL, delims2);

    if (got2 || expected2) {
      ck_assert_str_eq(got2, expected2);
    }
  }
}
END_TEST

START_TEST(s21_strerror_test) {
  char *str = s21_strerror(10);
  char *str1 = strerror(10);
  ck_assert_str_eq(str, str1);

  char *str2 = s21_strerror(20);
  char *str3 = strerror(20);
  ck_assert_str_eq(str2, str3);

  char *str4 = s21_strerror(100);
  char *str5 = strerror(100);
  ck_assert_str_eq(str4, str5);

  char *str6 = s21_strerror(130);
  char *str7 = strerror(130);
  ck_assert_str_eq(str6, str7);

  char *str8 = s21_strerror(0);
  char *str9 = strerror(0);
  ck_assert_str_eq(str8, str9);

  char *str10 = s21_strerror(99);
  char *str11 = strerror(99);
  ck_assert_str_eq(str10, str11);

  char *str12 = s21_strerror(135);
  char *str13 = strerror(135);
  ck_assert_str_eq(str12, str13);
}
END_TEST

// START_TEST(s21_strlen_test) {
//   const char str[] = "Hello world";
//   const char str_1[] = "HelloHelloHelloHello";
//   const char str_2[] = "";
//   ck_assert_int_eq(strlen(str), s21_strlen(str));
//   ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
//   ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
// }
// END_TEST

// START_TEST(s21_memchr_test) {
//   const char str[] = "Hello world";
//   const char str_1[] = "HelloHelloHelloHello";
//   const char str_2[] = "2345678965432";
//   ck_assert_ptr_eq(memchr(str, 'e', 6), s21_memchr(str, 'e', 6));
//   ck_assert_ptr_eq(memchr(str_1, 'H', 10), s21_memchr(str_1, 'H', 10));
//   ck_assert_ptr_eq(memchr(str_2, 'e', 12), s21_memchr(str_2, 'e', 12));
// }
// END_TEST

// START_TEST(s21_memcpy_test) {
//   const char str[] = "Hello world";
//   const char str_1[] = "HelloHelloHelloHello";
//   const char str_2[] = "2345678965432";
//   char dest_1[100] = {0};
//   char dest_2[100] = {0};
//   char dest_3[100] = {0};
//   char dest_4[100] = {0};
//   char dest_5[100] = {0};
//   char dest_6[100] = {0};
//   s21_memcpy(dest_1, str, 12);
//   memcpy(dest_2, str, 12);
//   ck_assert_str_eq(dest_1, dest_2);

//   s21_memcpy(dest_3, str_1, 10);
//   memcpy(dest_4, str_1, 10);
//   ck_assert_str_eq(dest_3, dest_4);

//   s21_memcpy(dest_5, str_2, 1);
//   memcpy(dest_6, str_2, 1);
//   ck_assert_str_eq(dest_5, dest_6);
// }
// END_TEST

// START_TEST(s21_memset_test) {
//   char str[5] = "";
//   char str_1[5] = "";
//   ck_assert_str_eq(memset(str, '=', 4), s21_memset(str_1, '=', 4));

//   char str_2[100] = "";
//   char str_3[100] = "";
//   ck_assert_str_eq(memset(str_2, '0', 50), s21_memset(str_3, '0', 50));

//   char str_4[20] = "";
//   char str_5[20] = "";
//   ck_assert_str_eq(memset(str_4, ' ', 10), s21_memset(str_5, ' ', 10));
// }
// END_TEST

// START_TEST(s21_strncat_test) {
//   char str[10] = "";
//   char str_1[10] = "";
//   ck_assert_str_eq(strncat(str, "NONONO", 7), s21_strncat(str_1, "NONONO",
//   7));

//   char str_2[40] = "";
//   char str_3[40] = "";
//   ck_assert_str_eq(strncat(str_2, "YYEEEEEAHhhh", 13),
//                    s21_strncat(str_3, "YYEEEEEAHhhh", 13));

//   // char str_4[10] = "";
//   // char str_5[10] = "";
//   // ck_assert_str_eq(strncat(str_4, "YYEEEEEA", 13),
//   //                  s21_strncat(str_5, "YYEEEEEA", 13));
// }
// END_TEST

// START_TEST(s21_strcspn_test) {
//   char str[] = "Hello world";
//   char str_1[] = "HelloHELLOworld";
//   char str_2[] = "2345678965432";
//   ck_assert_int_eq(strcspn(str, "H"), s21_strcspn(str, "H"));
//   ck_assert_int_eq(strcspn(str_1, "lo"), s21_strcspn(str_1, "lo"));
//   ck_assert_int_eq(strcspn(str_2, "432"), s21_strcspn(str_2, "432"));
// }
// END_TEST

// START_TEST(s21_strrchrn_test) {
//   char str[] = "HelloHelloHelloHello";
//   char str_1[] = "2345678965432";
//   ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
//   ck_assert_str_eq(strrchr(str, 'H'), s21_strrchr(str, 'H'));
//   ck_assert_str_eq(strrchr(str_1, '3'), s21_strrchr(str_1, '3'));
// }
// END_TEST

// START_TEST(s21_strstr_test) {
//   char str[] = "HelloH  elloHelloHe  llo";
//   ck_assert_str_eq(strstr(str, "llo"), s21_strstr(str, "llo"));
//   ck_assert_str_eq(strstr(str, " "), s21_strstr(str, " "));
// }
// END_TEST

// START_TEST(s21_strcmp_test) {
//   char str[] = "HelloHelloHelloHello";
//   char str_1[] = "HelloHelloHelloHello";
//   ck_assert_int_eq(s21_strcmp(str,str_1),strcmp(str,str_1));

//   char str_2[] = "HelloHel";
//   char str_3[] = "HelloHelloHelloHello";
//   ck_assert_int_eq(s21_strcmp(str_2,str_3),strcmp(str_2,str_3));

//   char str_4[] = "";
//   char str_5[] = "HelloHelloHel";
//   ck_assert_int_eq(s21_strcmp(str_4,str_5),strcmp(str_4,str_5));

// }END_TEST

// START_TEST(s21_strcpy_test) {
//   const char str[] = "Hello world";
//   const char str_1[] = "HelloHelloHelloHello";
//   const char str_2[] = "2345678965432";
//   char dest_1[100] = {0};
//   char dest_2[100] = {0};
//   char dest_3[100] = {0};
//   char dest_4[100] = {0};
//   char dest_5[100] = {0};
//   char dest_6[100] = {0};
//   s21_strcpy(dest_1, str);
//   strcpy(dest_2, str);
//   ck_assert_str_eq(dest_1, dest_2);

//   s21_strcpy(dest_3, str_1);
//   strcpy(dest_4, str_1);
//   ck_assert_str_eq(dest_3, dest_4);

//   s21_strcpy(dest_5, str_2);
//   strcpy(dest_6, str_2);
//   ck_assert_str_eq(dest_5, dest_6);

// }END_TEST

START_TEST(s21_to_upper_test) {
  const char str[] = "Hello world";
  const char str_1[] = "hello World";
  const char str_2[] = "HELLO WORLD";
  const char res[] = "HELLO WORLD";
  char *res_1 = s21_to_upper(str);
  char *res_2 = s21_to_upper(str_1);
  char *res_3 = s21_to_upper(str_2);
  ck_assert_str_eq(res_1, res);
  ck_assert_str_eq(res_2, res);
  ck_assert_str_eq(res_3, res);
  free(res_1);
  free(res_2);
  free(res_3);
}
END_TEST

START_TEST(s21_to_lower_test) {
  const char str[] = "Hello world";
  const char str_1[] = "hello World";
  const char str_2[] = "HELLO WORLD";
  const char res[] = "hello world";
  char *res_1 = s21_to_lower(str);
  char *res_2 = s21_to_lower(str_1);
  char *res_3 = s21_to_lower(str_2);
  ck_assert_str_eq(res_1, res);
  ck_assert_str_eq(res_2, res);
  ck_assert_str_eq(res_3, res);
  free(res_1);
  free(res_2);
  free(res_3);
}
END_TEST

// START_TEST(s21_insert_test) {
//   char src[] = "HELLO world";
//   char str[] = "";
//   s21_size_t index = 7;
//   char expected[] = "HELLO world";
//   char *res = (char *)s21_insert(src, str, index);
//   ck_assert_str_eq(res, expected);
//   if (res) free(res);

//   char src_2[] = "";
//   char str_2[] = "";
//   s21_size_t index_2 = 100;
//   char *expected_2 = NULL;
//   char *res_2 = (char *)s21_insert(src_2, str_2, index_2);
//   ck_assert_ptr_eq(res_2, expected_2);
//   if (res_2) free(res_2);

//   char *src_3 = NULL;
//   char *str_3 = NULL;
//   s21_size_t index_3 = 100;
//   char *expected_3 = NULL;
//   char *res_3 = (char *)s21_insert(src_3, str_3, index_3);
//   ck_assert_ptr_eq(res_3, expected_3);
//   if (res_3) free(res_3);

//   char src_4[] = "HELLO  world";
//   char str_4[] = "now";
//   char expected_4[] = "HnowELLO  world";
//   char *res_4 = (char *)s21_insert(src_4, str_4, 1);
//   ck_assert_str_eq(res_4, expected_4);
//   if (res_4) free(res_4);
// }
// END_TEST

// START_TEST(s21_trim_test) {
//   char str[] = "";
//   char trim_ch[] = "";
//   char expected[] = "";
//   char *res = s21_trim(str, trim_ch);
//   ck_assert_str_eq(res, expected);
//   if (res) free(res);

//   char str_1[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
//   char trim_ch_1[] = "";
//   char expected_1[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
//   char *res_1 = s21_trim(str_1, trim_ch_1);
//   ck_assert_str_eq(res_1, expected_1);
//   if (res_1) free(res_1);

//   char str_2[] = "HELLOworldHELLO";
//   char trim_ch_2[] = "HELLO";
//   char expected_2[] = "world";
//   char *res_2 = (char *)s21_trim(str_2, trim_ch_2);
//   ck_assert_str_eq(res_2, expected_2);
//   if (res_2) free(res_2);

//   char str_3[] = "heresadhere";
//   char trim_ch_3[] = {'s', 'a', 'd'};
//   char expected_3[] = "heresadhere";
//   char *res_3 = s21_trim(str_3, trim_ch_3);
//   ck_assert_str_eq(res_3, expected_3);
//   if (res_3) free(res_3);
// }
// END_TEST

int main(void) {
  Suite *s = suite_create("s21_string");
  TCase *tc = tcase_create("s21_string");
  SRunner *sr = srunner_create(s);
  int nf;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_memcmp_test);
  tcase_add_test(tc, s21_memmove_test);
  tcase_add_test(tc, s21_strcat_test);
  tcase_add_test(tc, s21_strncmp_test);
  tcase_add_test(tc, s21_strchr_test);
  tcase_add_test(tc, s21_strncpy_test);
  tcase_add_test(tc, s21_strpbrk_test);
  tcase_add_test(tc, s21_strspn_test);
  tcase_add_test(tc, s21_strtok_test);
  tcase_add_test(tc, s21_strerror_test);
  // tcase_add_test(tc, s21_strlen_test);
  // tcase_add_test(tc, s21_memchr_test);
  // tcase_add_test(tc, s21_memcpy_test);
  // tcase_add_test(tc, s21_memset_test);
  // tcase_add_test(tc, s21_strncat_test);
  // tcase_add_test(tc, s21_strcspn_test);
  // tcase_add_test(tc, s21_strrchrn_test);
  // tcase_add_test(tc, s21_strstr_test);
  // tcase_add_test(tc,s21_strcmp_test);
  // tcase_add_test(tc,s21_strcpy_test);
  tcase_add_test(tc, s21_to_upper_test);
  tcase_add_test(tc, s21_to_lower_test);
  // tcase_add_test(tc, s21_insert_test);
  // tcase_add_test(tc, s21_trim_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
