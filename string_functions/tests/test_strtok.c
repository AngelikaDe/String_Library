#include "unit_test.h"

START_TEST(simpe_strtock) {
  char str[30] = "test1/test2/test3/test4";
  ck_assert_str_eq(s21_strtok(str, "/"), strtok(str, "/"));
  ck_assert_ptr_eq(s21_strtok(str, "test"), strtok(str, "test"));
  ck_assert_ptr_eq(s21_strtok(str, "st"), strtok(str, "st"));
}
END_TEST

START_TEST(strtok_multy) {
  struct input_data {
    char str[2024];
    const char* delim;
  };
  struct input_data testcases[] = {{"This.is.the.string", "."},
                                   {"This.is.the.string", "."},
                                   {"this,.is,.the,.,.,.string,.", ",."},
                                   {"this,.is,.the,.,.,.string,.", ",."},
                                   {",.!,.!,.!,.!,.,.,.,!.", ",.!"},
                                   {",.!,.!,.!,.!,.,.,.,!.", ",.!"},
                                   {"This is the string", ",.!"},
                                   {"This is the string", ",.!"},
                                   {"", ",."},
                                   {"", ",."},
                                   {"This is the stirng", ""},
                                   {"This is the stirng", ""},
                                   {",.,.,.,,.,.The.,.,.,,.,.", ",."},
                                   {",.,.,.,,.,.The.,.,.,,.,.", ",."}};
  s21_size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (s21_size_t i = 0; i < n; i += 2) {
    char* result = s21_strtok(testcases[i].str, testcases[i].delim);
    char* expected_result =
        strtok(testcases[i + 1].str, testcases[i + 1].delim);
    while (result && expected_result) {
      ck_assert_pstr_eq(result, expected_result);
      result = s21_strtok(s21_NULL, testcases[i].delim);
      expected_result = strtok(s21_NULL, testcases[i + 1].delim);
    }
    ck_assert_ptr_null(result);
    ck_assert_ptr_null(expected_result);
  }
}
END_TEST

Suite* s21_strtok_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_strtok");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simpe_strtock);
  tcase_add_test(tc_core, strtok_multy);

  suite_add_tcase(s, tc_core);
  return s;
}
