# *****************************************************
# Variables to control Makefile operation
 
INC_DIR = libs
CC = g++
CFLAGS =-Wall -g -I./$(INC_DIR)
 

main: main.cpp 
	$(CC) $(CFLAGS) main.cpp -o main 
 
