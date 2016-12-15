g++ exec_test_1answer.c -o exec_test_1answer.o -lfann -lm $(pkg-config opencv --cflags --libs)
./exec_test_1answer.o $1 $2
