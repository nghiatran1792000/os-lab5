pi_serial: pi_serial.c
	gcc -o pi_serial pi_serial.c
pi_multithread: pi_multithread.c
	gcc -pthread -o pi_multithread pi_multithread.c
code: code.c
	gcc -pthread -o code code.c