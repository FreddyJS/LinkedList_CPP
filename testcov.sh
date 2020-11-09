#!/bin/bash
g++-7 --coverage -fno-inline -fno-inline-small-functions -fno-default-inline -Wall -g -I./libs main.cpp -o main
./main
gcov -a -f -l main
