clean:
	rm -f run test

iplist:
	clang iplist.c -Wall -o run

test:
	clang test.c -Wall -o test
	