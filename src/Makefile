GCC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
LDFLAGS = -O2 -Wall -Werror -Wextra -std=c11
SOURCE = $(wildcard s21_*.c)
HEADER = $(wildcard s21_*.h)
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
TESTS_SOURCE = tests.c
TESTS_OBJECTS = $(patsubst %.c,%.o, ${TESTS_SOURCE})
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    FLAGS += 
else
	FLAGS += -lpthread -pthread -lrt -lm -lsubunit
endif

# ifeq ($(OS), Darwin)
#     FLAGS += -D OS_MAC
# else
#     FLAGS += -D OS_LINUX
# 	TEST_FLAGS += -lpthread -pthread -lrt -lm -lsubunit
# endif

PATH := $(BREW)/bin:$(PATH)

all: clean s21_string.a test

s21_string.a: ${SOURCE}
	$(CC) $(CFLAGS) $(FLAGS) $(SOURCE)
	ar rc $@ $(OBJECTS)
	ranlib $@
	# cp $@ lib$@ # закомментил и второй либы нет теперь
	-rm -rf *.o

test: ${TESTS_SOURCE} s21_string.a
	${CC} $(LDFLAGS) -o test $^ -lcheck $(FLAGS)
	./test

gcov_report: clean lcov ${SOURCE}
	gcc --coverage ${SOURCE} tests.c -o s21_test -lcheck
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif

check:
	cppcheck *.h *.c
	CK_FORK=no leaks --atExit -- ./test

valgrind: clean
	make s21_string.a
	gcc -g ${TESTS_SOURCE} s21_string.a -o test -lcheck -lcheck -lpthread -lm -D_GNU_SOURCE -lrt -lsubunit
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT_VALGRIND.txt ./test

style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n *.c *.h
	rm .clang-format

clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
	-rm -rf s21_test
