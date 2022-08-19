#!usr/bin/env python3 
import time        # monotonic() 
import numpy as np # np.random.randn()

N = 2048 # square dims

if __name__ == "__main__":
  A = np.random.randn(N,N).astype(np.float32) 
  B = np.random.randn(N,N).astype(np.float32)
  # number of ops in matrix multiplication 
  flop = N*N*2*N # output is N^2, 2N compute each (multiply and add) 
  
  # print continuously to simultaneously check core usage  
  for i in range(20):
   start = time.monotonic()
   C = A @ B 
   end = time.monotonic()
   t = end - start  
   print(f"\n{flop/t * 1e-9:.2f} GFLOP/S") 
  
  print(f"\ntime monotonic: {t}") 
  
  if(N<25): 
   print(f"\nMatrix A\n {A}\nMatrixB\n{B}\nResult\n{C}") 
