#!/bin/bash

gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c test/main.c -o customPrintf
