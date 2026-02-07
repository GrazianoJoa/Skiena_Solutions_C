CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

# ==============================
# Core library (data structures)
# ==============================

DS_SRC := $(wildcard src/data_structures/*.c)
DS_OBJ := $(DS_SRC:.c=.o)

# ==============================
# Exercises
# ==============================

EX_SRC := $(wildcard exercises/chp3/*.c)
EX_OBJ := $(EX_SRC:.c=.o)

# ==============================
# Test framework (shared)
# ==============================

TEST_COMMON_SRC := tests/test_ctx.c
TEST_COMMON_OBJ := $(TEST_COMMON_SRC:.c=.o)

# ==============================
# Test programs
# ==============================

TEST_SRC_MAIN := tests/test_src.c
TEST_EX_MAIN  := tests/test_ex.c

TARGET_TEST_SRC := run_tests_src
TARGET_TEST_EX  := run_tests_ex

# ==============================
# Phony targets
# ==============================

.PHONY: all clean tests ds exercises

# ==============================
# Default target
# ==============================

all: tests

# ==============================
# Test targets
# ==============================

tests: $(TARGET_TEST_SRC) $(TARGET_TEST_EX)

$(TARGET_TEST_SRC): $(DS_OBJ) $(TEST_COMMON_OBJ) $(TEST_SRC_MAIN)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_TEST_EX): $(DS_OBJ) $(EX_OBJ) $(TEST_COMMON_OBJ) $(TEST_EX_MAIN)
	$(CC) $(CFLAGS) $^ -o $@

# ==============================
# Object compilation
# ==============================

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ==============================
# Cleaning
# ==============================

clean:
	rm -f \
		$(DS_OBJ) \
		$(EX_OBJ) \
		$(TEST_COMMON_OBJ) \
		$(TARGET_TEST_SRC) \
		$(TARGET_TEST_EX)

