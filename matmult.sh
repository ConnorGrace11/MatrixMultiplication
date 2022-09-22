gcc mmnothreads.c -o mmnothreads
gcc -lpthread mmthreads.c -o mmthreads

./mmnothreads 5
./mmthreads 5

python mmnothreads.py 5

python mmthreads.py 5
