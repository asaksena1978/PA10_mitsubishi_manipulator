all : kinematics

kinematics	 : 	main.o display.o mul.o transfer.o inverse_kin.o inv_mat.o input_A01.o input_A12.o input_A23.o input_A34.o input_A45.o input_A56.o
		 	gcc -lm  main.o display.o mul.o transfer.o inverse_kin.o inv_mat.o input_A01.o input_A12.o input_A23.o input_A34.o input_A45.o input_A56.o

main.o		:	main.c
			gcc -c main.c

display.o	:	display.c
			gcc -c display.c
	
mul.o		:	mul.c
			gcc -c mul.c

transfer.o	:	transfer.c
			gcc -c transfer.c

inverse_kin.o	:	inverse_kin.c
			gcc -c inverse_kin.c

inv_mat.o	:	inv_mat.c
			gcc -c inv_mat.c

input_A01.o	:	input_A01.c
			gcc -c input_A01.c

input_A12.o	:	input_A12.c
			gcc -c input_A12.c

input_A23.o	:	input_A23.c
			gcc -c input_A23.c

input_A34.o	:	input_A34.c
			gcc -c input_A34.c

input_A45.o	:	input_A34.c
			gcc -c input_A45.c

input_A56.o	:	input_A56.c
			gcc -c input_A56.c
