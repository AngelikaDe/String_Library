#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"
#define sign_of(a) ((a) > 0 ? 1 : ((a) < 0 ? -1 : 0))
#define BUFF_SIZE 512

Suite* s21_memchr_suite(void);
Suite* s21_memcmp_suite(void);
Suite* s21_memcpy_suite(void);
Suite* s21_memmove_suite(void);
Suite* s21_memset_suite(void);
Suite* s21_strcat_suite(void);
Suite* s21_strncat_suite(void);
Suite* s21_strchr_suite(void);
Suite* s21_strcmp_suite(void);
Suite* s21_strncmp_suite(void);
Suite* s21_strcpy_suite(void);
Suite* s21_strncpy_suite(void);
Suite* s21_strcspn_suite(void);
Suite* s21_strerror_suite(void);
Suite* s21_strlen_suite(void);
Suite* s21_strpbrk_suite(void);
Suite* s21_strrchr_suite(void);
Suite* s21_strspn_suite(void);
Suite* s21_strstr_suite(void);
Suite* s21_strtok_suite(void);
Suite* s21_to_upper_suite(void);
Suite* s21_to_lower_suite(void);
Suite* s21_insert_suite(void);
Suite* s21_trim_suite(void);
Suite* s21_print_d_suite(void);
Suite* s21_print_c_suite(void);
Suite* s21_print_lc_suite(void);
Suite* s21_print_n_suite(void);
Suite* s21_print_pr_suite(void);
Suite* s21_print_s_suite(void);
Suite* s21_print_ls_suite(void);
Suite* s21_print_i_suite(void);
Suite* s21_print_p_suite(void);
Suite* s21_print_f_suite(void);
Suite* s21_print_e_suite(void);
Suite* s21_print_eb_suite(void);
Suite* s21_print_g_suite(void);
Suite* s21_print_gb_suite(void);
Suite* s21_print_x_suite(void);
Suite* s21_print_xb_suite(void);
Suite* s21_print_u_suite(void);
Suite* s21_print_o_suite(void);
Suite* s21_sscanf_d_suite(void);
Suite* s21_sscanf_i_suite(void);
Suite* s21_sscanf_c_suite(void);
Suite* s21_sscanf_s_suite(void);
Suite* s21_sscanf_n_suite(void);
Suite* s21_sscanf_u_suite(void);
Suite* s21_sscanf_xb_suite(void);
Suite* s21_sscanf_x_suite(void);
Suite* s21_sscanf_f_suite(void);
Suite* s21_sscanf_e_suite(void);
Suite* s21_sscanf_eb_suite(void);
Suite* s21_sscanf_g_suite(void);
Suite* s21_sscanf_gb_suite(void);
Suite* s21_sscanf_o_suite(void);
Suite* s21_sscanf_p_suite(void);
Suite* s21_sscanf_pr_suite(void);

#endif  // UNIT_TEST_H
