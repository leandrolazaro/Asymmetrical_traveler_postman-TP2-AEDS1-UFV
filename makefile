all:
	gcc main.c -o executavel -Wall

run:
	./executavel
	
del:
	rm executavel
