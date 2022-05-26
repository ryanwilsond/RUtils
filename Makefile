CC=g++

.PHONY: tests

tests:
	$(CC) tests/* -o test.exe -Icpp
