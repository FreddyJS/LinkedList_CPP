#!/bin/bash
g++-7 --coverage -fno-inline -fno-inline-small-functions -fno-default-inline -Wall -g -I./include main.cpp -o main
./main
gcov -a -f -l main
