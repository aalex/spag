all: run

state.o: state.cpp
	g++ -Wall -fPIC -c  -o state.o state.cpp

machine.o: machine.cpp
	g++ -Wall -fPIC -c  -o machine.o machine.cpp

rule.o: rule.cpp
	g++ -Wall -fPIC -c  -o rule.o rule.cpp

spag.so: state.o machine.o rule.o
	g++ -shared -Wl,-soname,libspag.so -o libspag.so rule.o state.o machine.o

libspag.a: state.o machine.o rule.o
	ar rcs libspag.a state.o machine.o rule.o

run: spag.so main.c
	g++ -Wall -Werror -o run -L. -lspag main.c

clean:
	rm -rf *.so *.o run *.so.1.0.1
