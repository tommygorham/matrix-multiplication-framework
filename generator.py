# generator.py generates a random matrix 
# to run 
## generate default size: python3 generator.py      
## generate custom  size: python3 generator.py <size> 
## write matrix to  file: python3 generator.py <size> >> input.txt
#  E.g.,  
## python3 generator.py 16 >> input16a.txt 
  
from __future__ import print_function
import sys, os 
import random

DEFAULT_SIZE = 4 # if size is not passed 
MAXRNDVAL = 9       # range of values to be generated are between 0 - MAXRNDVAL 

d = DEFAULT_SIZE if len(sys.argv) <= 1 else int(sys.argv[1])

all_ = d * d
i = 0

print (d) # first line with dimension

while i < all_:
    n = str(random.randint(0,MAXRNDVAL))
    i += 1
    if i % d == 0:
       print(n)
    else:
       print(n, end=" ")
