#!usr/bin/env python3 
# this program measures execution time with perfcounter as opposed to monotonic() in pygemm.py
from time import perf_counter # this seems to be the most similar to c++ chrono high_resolution_clock()  
import numpy as np # np.random.randn()

N = 2048 # square dims

if __name__ == "__main__":
  A = np.random.randn(N,N).astype(np.float32) 
  B = np.random.randn(N,N).astype(np.float32)
  # number of ops in matrix multiplication 
  flop = N*N*2*N # output is N^2, 2N compute each (multiply and add) 
  
  # print continuously to simultaneously check core usage  
  for i in range(20):
   start = perf_counter()
   C = A @ B 
   end = perf_counter()
   t = end - start  
   print(f"\n{flop/t * 1e-9:.2f} GFLOP/S") 
  
  print(f"\ntime in ms using perfcounter: {t}") 
  
  if(N<25): 
   print(f"\nMatrix A\n {A}\nMatrixB\n{B}\nResult\n{C}") 
