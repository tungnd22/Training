practice: practice.o
	gcc practice.o -o practice			# Linking

practice.o: practice.s
	gcc -c practice.s -o practice.o		# Assembly

practice.s: practice.i
	gcc -S practice.i -o practice.s		# Compilation

practice.i: practice.c
	gcc -E practice.c -o practice.i		# Preprocessing