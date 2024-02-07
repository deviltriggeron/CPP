gcc = g++ -std=c++11 -Wall -Werror -Wextra
MODULES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(MODULES))

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck -lm
endif

all: clean install 

####
####
####

test:

s21_matrix_oop.a:


clang-check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h
	rm ./.clang-format

clang-formatting:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	rm ./.clang-format

clean:
	