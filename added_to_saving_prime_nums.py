number = 1000 # 소수 검사를 시도할 횟수

with open('소수목록.txt', 'r') as f:
  list = f.read().split(',')

if list[0] == '': # txt 파일이 비어있으면
  count = 0 # 1부터 검사
else:
  count = int(list[-1]) # '마지막 검사 수' 다음부터 이어서 검사
prime_nums = list[:-1] # '마지막 검사 수' 없애기

for n in range(len(prime_nums)):
  prime_nums[n] = int(prime_nums[n])

with open('소수목록.txt', 'a') as f:
  for a in range(number):
    count += 1 
    n = count
  
    for num in prime_nums: 
      while n % num == 0: # 나머지가 안 생기는 동안
        n = n / num # n을 그보다 작은 모든 소수로 나눠보기
  
    if n != 1: # 몫이 1이 되지 않으면
      print(count)
      prime_nums.append(count) # 소수 목록에 추가
      f.write('{},'.format(count)) # 기록
    
    if a == number - 1:
      f.write('{}'.format(count)) # '마지막 검사 수' 기록

print('\n'+str(len(prime_nums)))
