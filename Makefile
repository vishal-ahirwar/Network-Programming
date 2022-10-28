clean:
	rm -f run test run
iplist:
	clang iplist.c -Wall -o getip

test:
	clang test.c -Wall -o test
	