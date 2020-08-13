import time

n = 10000000
len_primes = []

def primes_in(n):
  a = [False,False] + [True]*(n-1)
  primes=[]

  for i in range(2,n+1):
    if a[i]:
      primes.append(i)
      for j in range(2*i, n+1, i):
          a[j] = False

  # with open('소수목록.txt', 'w') as f:
  #   for prime in primes:
  #     f.write('{},'.format(prime))
  len_primes.append(len(primes))
  return(primes)

# 104729
# 0, 4, 25, 168, 1229, 9592, 78498, 664579, 5761455

start = time.time()
print(primes_in(n))
elapsed = time.time() - start

print('\n' + str(elapsed) + 's')
print('\n소수 비율:', len_primes[0], '/', n)
