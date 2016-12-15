>data.net
gcc parallel_train.c -o parallel_train.o -lfann -lm
echo "compiled.. running"
./parallel_train.o $1
