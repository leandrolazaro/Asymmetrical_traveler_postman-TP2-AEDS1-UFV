all:
	gcc main.c -o executavel -Wall

run:
	./executavel
	
del:
	rm executavel

cudac:
	nvcc -arch=sm_35 -rdc=true permutate.cu -o cuda -lcudadevrt
	
cudarun:
	./cuda

cudadel:
	rm cuda

test1:
	gcc testador.c -o teste -Wall
	
test2:
	./teste
