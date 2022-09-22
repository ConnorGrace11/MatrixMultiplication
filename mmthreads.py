import threading
import time
import sys
import numpy as np

size = int(sys.argv[1])
X = np.random.randint(15, size=(size, size))
Y = np.random.randint(15, size=(size, size))

def mult(X, Y):
   result = [[0]*size]
   for z in range(len(Y[0])):
       for k in range(len(Y)):
           result[0][z] += X[0] * Y[k][z]
   # print(f" {result}")

threads = list()
start = time.perf_counter()
for i in range(len(X[0])):
   x = threading.Thread(target = mult, args=(X[i], Y))
   threads.append(x)
   x.start()

for index, thread in enumerate(threads):
   thread.join()
end = time.perf_counter()

print(f"Time taken to complete {size}x{size}: {round(end - start, 5)} seconds")

