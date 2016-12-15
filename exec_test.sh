g++ exec_test.c -o exec_test.o -lfann -lm $(pkg-config opencv --cflags --libs)
./exec_test.o $1 $2
