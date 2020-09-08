import time as t
import math as m


# def primes_in(n):
#   primes=[]
#   for i in range(1, m.floor(m.sqrt(n+1))):
#     if a[i]:
#       primes.append(i)
#       for j in range(2*i, n+1, i):
#           a[j] = False
#   return primes


def is_primes_in(n):
  for i in range(1, m.floor(m.sqrt(n+1))): # m.floor(m.sqrt(n+1))
    if a[i]:
      for j in range(2*i, n+1, i):
          a[j] = False
  return None


# 진행 시작
print("-" * 44)
print("내가 계속 찾는게 있거든...뭔지 알아?...소수\n");
print("나가기: break")
# 반복
while True:
  print("-" * 44)

  # n 입력 받기
  n = input("n 안의 소수, n = ")
  if n == 'break':
      break

  # 자연수 확인
  try:
    n = int(n)
    if n < 1:
      raise
  except:
    print("자연수를 써라")
    continue
  
  
  # 소수 찾기
  start = t.time()
  a = [False,False] + [True]*(n-1)
  is_primes_in(n)          ## is_primes_in 함수 전용
  # primes = primes_in(n)  ## primes_in 함수 전용
  elapsed = t.time() - start


  # 소수 출력하기
  print()
  num_primes = 0
  # f = open('소수목록.txt', 'w') ## 기록 전용

  start2 = t.time()
  for i in range(1,n+1):   ## is_primes_in 전용
    if a[i]:               ## is_primes_in 전용
      num_primes += 1      ## is_primes_in 전용
      print(i, end=' ')    ## is_primes_in 전용
      # f.write(f"{i},")   ## 기록 전용
  # f.close()              ## 기록 전용
  # print(primes)          ## primes_in 전용
  elapsed2 = t.time() - start2
  

  # 정보 출력하기
  print('\n\n찾는 시간 : %.3f sec' % elapsed)
  print('출력 시간 : %.3f sec' % elapsed2)
  print('소수 비율 :', num_primes, '/', n, "(%.2f %%)" % (num_primes/n*100))