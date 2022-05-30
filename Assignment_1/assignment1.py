import hashlib
# import time
import timeit

# start_time = time.time()
s1 = input("Input String: ")
i = 0
while (1):
    s = s1+str(i)   #Appending i into our string
    x=hashlib.sha256(s.encode())    # Encodes the string s using the sha256 hashing function and returns its location
    x = x.hexdigest()               # Converts x into a hexadecimal string
    if(x<"00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"):
        break
    i=i+1

print(i)
print(timeit.timeit('output = 10*5'))   # prints the execution time of the code

# print("--- %s seconds ---" % (time.time() - start_time))
