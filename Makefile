# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
INC_DIR = libs
CC = g++
CFLAGS =-Wall -g -I./$(INC_DIR)
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o 
	$(CC) $(CFLAGS) main.o -o main 
 
# The main.o target can be written more simply
 
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
 
#LinkedList.o: LinkedList.cpp LinkedList.h
#	$(CC) $(CFLAGS) -c LinkedList.cpp
