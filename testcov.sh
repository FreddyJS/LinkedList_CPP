#!/bin/bash
g++-7 -coverage -Wall -g -I./libs main.cpp -o main
./main
