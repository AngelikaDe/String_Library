#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str) {
    while (str[len]) {
      len++;
    }
  }
  return len;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *pointer_char;
  pointer_char = (const unsigned char *)str;
  int flag = 1;
  void *ret = s21_NULL;
  while (n && flag) {
    if (*pointer_char == (unsigned char)c) {
      flag = 0;
      ret = (void *)pointer_char;
    } else {
      pointer_char++;
      n--;
    }
  }
  return ret;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *pointer_dest = (unsigned char *)dest;
  const unsigned char *pointer_src = (const unsigned char *)src;

  while (n) {
    *pointer_dest++ = *pointer_src++;
    n--;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_pointer = (unsigned char *)str;
  while (n) {
    *str_pointer++ = (unsigned char)c;
    n--;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  s21_size_t j;
  i = 0;
  j = s21_strlen(dest);
  while (i < n && src[i]) {
    dest[j + i] = src[i];
    i++;
  }
  dest[j + i] = '\0';
  return dest;
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && *str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return (int)*str1 - *str2;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  char *str1_pointer = (char *)str1;
  s21_size_t i = 0;
  int flag = 1;
  while (flag && str1[i]) {
    if (!s21_strspn(str1_pointer, str2)) {
      str1_pointer++;
      i++;
    } else {
      flag = 0;
    }
  }
  return i;
}

char *s21_strrchr(const char *str, int c) {
  s21_size_t str_len = s21_strlen(str);
  int flag = 1;
  char *ret = (char *)s21_NULL;
  while (*str) {
    str++;
  }
  while (str_len && flag) {
    if (*str == (char)c) {
      flag = 0;
      ret = (char *)str;
    } else {
      str--;
      str_len--;
    }
  }
  return ret;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t needle_len = s21_strlen(needle);
  int flag = 0;
  char *ret = (char *)s21_NULL;

  if (needle_len) {
    flag = 1;
    s21_size_t haystack_len = s21_strlen(haystack);
    while (haystack_len >= needle_len && flag) {
      if (!s21_memcmp(haystack, needle, needle_len)) {
        flag = 0;
      } else {
        haystack++;
      }
      haystack_len--;
    }
  }
  if (!flag) {
    ret = (char *)haystack;
  }
  return ret;
}

s21_size_t s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *str_1 = (char *)str1;
  char *str_2 = (char *)str2;
  s21_size_t int flag = 0;
  s21_size_t i = 0;
  while (i < n && flag == 0) {
    if (str_1[i] != str_2[i]) {
      flag = str_1[i] - str_2[i];
    }
    i++;
  }
  return flag;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *str_1 = (char *)dest;
  char *str_2 = (char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);
  if (tmp == s21_NULL) {
    return s21_NULL;
  }
  for (s21_size_t i = 0; i < n; i++) {
    tmp[i] = str_2[i];
  }
  for (s21_size_t i = 0; i < n; i++) {
    str_1[i] = tmp[i];
  }
  free(tmp);
  return str_1;
}

char *s21_strcat(char *dest, const char *src) {
  char *new_dest = dest + s21_strlen(dest);
  while (*src != '\0') {
    *new_dest++ = *src++;
  }
  *new_dest = '\0';
  return dest;
}

char *s21_strchr(const char *str, int sym) {
  char *ret = s21_NULL;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == sym) {
      ret = (char *)str + i;
      break;
    }
    i++;
  }
  return ret;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t count = 0;
  int flag = 0;
  while (count < n && flag == 0) {
    if (str1[count] == str2[count]) {
      count++;
    } else {
      flag = str1[count] - str2[count];
    }
  }
  if (count == n) {
    return flag;
  } else {
    return flag;
  }
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *isym = s21_NULL;
  int flag = 0;
  int str1_n = s21_strlen(str1);
  int str2_n = s21_strlen(str2);
  int i = 0;
  int j = 0;
  while (i < str1_n && flag == 0) {
    while (j < str2_n && flag == 0) {
      if (str1[i] == str2[j]) {
        flag = 1;
        isym = (char *)&str1[i];
      }
      j++;
    }
    i++;
    j = 0;
  }
  return isym;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (str1[i] && s21_strchr(str2, str1[i])) i++;
  return i;
  return i;
}

char *s21_strtok(char *str, const char *delim) {
  static char *new = s21_NULL;
  if (!str) {
    str = new;
    if (str == s21_NULL) {
      return s21_NULL;
    }
  }
  str += s21_strspn(str, delim);
  if (*str == '\0') {
    new = s21_NULL;
    return new;
  }
  new = str + s21_strcspn(str, delim);
  if (new[0] != '\0') {
    new[0] = '\0';
    new ++;
  } else {
    new = s21_NULL;
  }
  return str;
}

void *s21_to_upper(const char *str) {
  char *dst = s21_NULL;
  char *point = (char *)str;
  s21_size_t len = s21_strlen(point);
  dst = malloc(sizeof(char) * (len + 1));
  if (dst != s21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (point[i] >= 97 && point[i] < 122) {
        dst[i] = point[i] - 32;
      } else {
        dst[i] = point[i];
      }
    }
    dst[len] = '\0';
  }
  return (void *)dst;
}

void *s21_to_lower(const char *str) {
  char *dst = s21_NULL;
  char *point = (char *)str;
  s21_size_t len = s21_strlen(point);
  dst = malloc(sizeof(char) * (len + 1));
  if (dst != s21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (point[i] >= 65 && point[i] < 90) {
        dst[i] = point[i] + 32;
      } else {
        dst[i] = point[i];
      }
    }
    dst[len] = '\0';
  }
  return (void *)dst;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *dst = s21_NULL;
  s21_size_t num = start_index;
  s21_size_t s_src = s21_strlen(src);
  s21_size_t s_str = s21_strlen(str);
  s21_size_t i = 0;
  s21_size_t j = 0;
  if ((s_src != 0 || s_str != 0) && (num <= s_src)) {
    dst = malloc((s_src + s_str + 1) * sizeof(char));
    if (dst != s21_NULL) {
      for (; i < num; i++) {
        dst[i] = src[i];
      }
      for (; i < (s_str + num); i++, j++) {
        dst[i] = str[j];
      }
      s21_size_t res = s_src + s_str;
      for (; i < res + 1; i++) {
        dst[i] = src[num];
        num++;
      }
    }
    dst[s_src + s_str] = '\0';
  }
  return (void *)dst;
}

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t len = s21_strlen(src);
  s21_size_t start = 0;
  s21_size_t end = len - 1;
  while (start < len && s21_strchr(trim_chars, src[start]) != s21_NULL) {
    start++;
  }
  while (end > start && s21_strchr(trim_chars, src[end]) != s21_NULL) {
    end--;
  }
  s21_size_t new_len = end - start + 1;
  char *dst = (char *)malloc(new_len + 1);
  s21_strncpy(dst, src + start, new_len);
  dst[new_len] = '\0';
  return dst;
}

#ifdef __APPLE__
#define MAX_ERRORS 106
#define ERROR "Unknown error: "
char error[107][50] = {"Undefined error: 0",
                       "Operation not permitted",
                       "No such file or directory",
                       "No such process",
                       "Interrupted system call",
                       "Input/output error",
                       "Device not configured",
                       "Argument list too long",
                       "Exec format error",
                       "Bad file descriptor",
                       "No child processes",
                       "Resource deadlock avoided",
                       "Cannot allocate memory",
                       "Permission denied",
                       "Bad address",
                       "Block device required",
                       "Resource busy",
                       "File exists",
                       "Cross-device link",
                       "Operation not supported by device",
                       "Not a directory",
                       "Is a directory",
                       "Invalid argument",
                       "Too many open files in system",
                       "Too many open files",
                       "Inappropriate ioctl for device",
                       "Text file busy",
                       "File too large",
                       "No space left on device",
                       "Illegal seek",
                       "Read-only file system",
                       "Too many links",
                       "Broken pipe",
                       "Numerical argument out of domain",
                       "Result too large",
                       "Resource temporarily unavailable",
                       "Operation now in progress",
                       "Operation already in progress",
                       "Socket operation on non-socket",
                       "Destination address required",
                       "Message too long",
                       "Protocol wrong type for socket",
                       "Protocol not available",
                       "Protocol not supported",
                       "Socket type not supported",
                       "Operation not supported",
                       "Protocol family not supported",
                       "Address family not supported by protocol family",
                       "Address already in use",
                       "Can't assign requested address",
                       "Network is down",
                       "Network is unreachable",
                       "Network dropped connection on reset",
                       "Software caused connection abort",
                       "Connection reset by peer",
                       "No buffer space available",
                       "Socket is already connected",
                       "Socket is not connected",
                       "Can't send after socket shutdown",
                       "Too many references: can't splice",
                       "Operation timed out",
                       "Connection refused",
                       "Too many levels of symbolic links",
                       "File name too long",
                       "Host is down",
                       "No route to host",
                       "Directory not empty",
                       "Too many processes",
                       "Too many users",
                       "Disc quota exceeded",
                       "Stale NFS file handle",
                       "Too many levels of remote in path",
                       "RPC struct is bad",
                       "RPC version wrong",
                       "RPC prog. not avail",
                       "Program version wrong",
                       "Bad procedure for program",
                       "No locks available",
                       "Function not implemented",
                       "Inappropriate file type or format",
                       "Authentication error",
                       "Need authenticator",
                       "Device power is off",
                       "Device error",
                       "Value too large to be stored in data type",
                       "Bad executable (or shared library)",
                       "Bad CPU type in executable",
                       "Shared library version mismatch",
                       "Malformed Mach-o file",
                       "Operation canceled",
                       "Identifier removed",
                       "No message of desired type",
                       "Illegal byte sequence",
                       "Attribute not found",
                       "Bad message",
                       "EMULTIHOP (Reserved)",
                       "No message available on STREAM",
                       "ENOLINK (Reserved)",
                       "No STREAM resources",
                       "Not a STREAM",
                       "Protocol error",
                       "STREAM ioctl timeout",
                       "Operation not supported on socket",
                       "Policy not found",
                       "State not recoverable",
                       "Previous owner died",
                       "Interface output queue is full"};

#elif __linux__
#define MAX_ERRORS 133
#define ERROR "Unknown error "
char error[134][50] = {"Success",
                       "Operation not permitted",
                       "No such file or directory",
                       "No such process",
                       "Interrupted system call",
                       "Input/output error",
                       "No such device or address",
                       "Argument list too long",
                       "Exec format error",
                       "Bad file descriptor",
                       "No child processes",
                       "Resource temporarily unavailable",
                       "Cannot allocate memory",
                       "Permission denied",
                       "Bad address",
                       "Block device required",
                       "Device or resource busy",
                       "File exists",
                       "Invalid cross-device link",
                       "No such device",
                       "Not a directory",
                       "Is a directory",
                       "Invalid argument",
                       "Too many open files in system",
                       "Too many open files",
                       "Inappropriate ioctl for device",
                       "Text file busy",
                       "File too large",
                       "No space left on device",
                       "Illegal seek",
                       "Read-only file system",
                       "Too many links",
                       "Broken pipe",
                       "Numerical argument out of domain",
                       "Numerical result out of range",
                       "Resource deadlock avoided",
                       "File name too long",
                       "No locks available",
                       "Function not implemented",
                       "Directory not empty",
                       "Too many levels of symbolic links",
                       "Unknown error 41",
                       "No message of desired type",
                       "Identifier removed",
                       "Channel number out of range",
                       "Level 2 not synchronized",
                       "Level 3 halted",
                       "Level 3 reset",
                       "Link number out of range",
                       "Protocol driver not attached",
                       "No CSI structure available",
                       "Level 2 halted",
                       "Invalid exchange",
                       "Invalid request descriptor",
                       "Exchange full",
                       "No anode",
                       "Invalid request code",
                       "Invalid slot",
                       "Unknown error 58",
                       "Bad font file format",
                       "Device not a stream",
                       "No data available",
                       "Timer expired",
                       "Out of streams resources",
                       "Machine is not on the network",
                       "Package not installed",
                       "Object is remote",
                       "Link has been severed",
                       "Advertise error",
                       "Srmount error",
                       "Communication error on send",
                       "Protocol error",
                       "Multihop attempted",
                       "RFS specific error",
                       "Bad message",
                       "Value too large for defined data type",
                       "Name not unique on network",
                       "File descriptor in bad state",
                       "Remote address changed",
                       "Can not access a needed shared library",
                       "Accessing a corrupted shared library",
                       ".lib section in a.out corrupted",
                       "Attempting to link in too many shared libraries",
                       "Cannot exec a shared library directly",
                       "Invalid or incomplete multibyte or wide character",
                       "Interrupted system call should be restarted",
                       "Streams pipe error",
                       "Too many users",
                       "Socket operation on non-socket",
                       "Destination address required",
                       "Message too long",
                       "Protocol wrong type for socket",
                       "Protocol not available",
                       "Protocol not supported",
                       "Socket type not supported",
                       "Operation not supported",
                       "Protocol family not supported",
                       "Address family not supported by protocol",
                       "Address already in use",
                       "Cannot assign requested address",
                       "Network is down",
                       "Network is unreachable",
                       "Network dropped connection on reset",
                       "Software caused connection abort",
                       "Connection reset by peer",
                       "No buffer space available",
                       "Transport endpoint is already connected",
                       "Transport endpoint is not connected",
                       "Cannot send after transport endpoint shutdown",
                       "Too many references: cannot splice",
                       "Connection timed out",
                       "Connection refused",
                       "Host is down",
                       "No route to host",
                       "Operation already in progress",
                       "Operation now in progress",
                       "Stale file handle",
                       "Structure needs cleaning",
                       "Not a XENIX named type file",
                       "No XENIX semaphores available",
                       "Is a named type file",
                       "Remote I/O error",
                       "Disk quota exceeded",
                       "No medium found",
                       "Wrong medium type",
                       "Operation canceled",
                       "Required key not available",
                       "Key has expired",
                       "Key has been revoked",
                       "Key was rejected by service",
                       "Owner died",
                       "State not recoverable",
                       "Operation not possible due to RF-kill",
                       "Memory page has hardware error"};

#endif

char *s21_strerror(int errnum) {
  static char res[100] = {'0'};
  if (errnum <= MAX_ERRORS) {
    s21_strcpy(res, error[errnum]);
  } else {
    char *err_str = s21_NULL;
    err_str = s21_from_int_to_str(errnum);
    s21_strcpy(res, ERROR);
    s21_strcat(res, err_str);
    free(err_str);
  }
  return res;
}

char *s21_from_int_to_str(int num) {
  char tmp[10];
  char *res = s21_NULL;
  int new_num = num;
  int i = 0;
  int j = 0;
  if (new_num < 0) {
    new_num = new_num * (-1);
  }
  while (new_num) {
    tmp[i] = (new_num % 10) + '0';
    i++;
    new_num = new_num / 10;
  }
  if (num < 0) {
    tmp[i] = '-';
  }
  tmp[i + 1] = '\0';
  int len = s21_strlen(tmp);
  res = malloc(sizeof(int) * (len + 1));
  while (j < len) {
    res[j] = tmp[i - 1];
    j++;
    i--;
  }
  res[j] = '\0';
  return (char *)res;
}