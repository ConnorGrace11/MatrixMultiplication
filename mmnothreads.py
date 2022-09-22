import sys
import time
import numpy as np
size = int(sys.argv[1])
matrix1 = np.random.randint(15, size=(size, size))
matrix2 = np.random.randint(15, size=(size, size))

res = [[0 for x in range(size)] for y in range(size)]
start = time.time()

for i in range(len(matrix1)):
    for j in range(len(matrix2[0])):
        for k in range(len(matrix2)):
            res[i][j] += matrix1[i][k] * matrix2[k][j]


for i in range(len(res)):
    print (res[i])
end = time.time()
print("The time of execution is :", end-start)
