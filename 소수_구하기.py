number = 10000 # 소수 검사를 시도할 횟수
prime_nums = [] 

for a in range(number):
  count = a + 1
  n = count

  for num in prime_nums:
    while n % num == 0: # 나머지가 안 생기는 동안
      n = n / num # n을 그보다 작은 모든 소수로 나눠보기

  if n != 1: # 몫이 1이 되지 않으면
    print(count)
    prime_nums.append(count) # 소수 목록에 추가

print(prime_nums)
print('\n소수 비율 :', len(prime_nums), '/', number)