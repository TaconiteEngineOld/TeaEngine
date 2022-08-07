libs:
	cp -u ./CLibs/TeaFS/src/teafs.h ./CLibs/TeaFS/build/
	cc -Wall -c ./CLibs/TeaFS/src/teafs.c -o ./CLibs/TeaFS/build/teafs.o
	ar -cvq ./CLibs/TeaFS/build/libteafs.a ./CLibs/TeaFS/build/teafs.o
	@echo "libteafs.a" saved to "./build/"
