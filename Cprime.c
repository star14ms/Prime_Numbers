#include <stdio.h>
#include <math.h> // floor, sqrt
#include <time.h> // clock, CLOCKS_PER_SEC
#include <stdlib.h> // malloc

int main()
{
	// (int 크기 * 입력받은 크기)만큼 동적 메모리 할당
    int *isPrimeNumber = (int *)malloc(sizeof(int) * 100000000);
	// char *text = malloc(sizeof(char) * 6000000);

	// 표준 출력 버퍼 크기 크게 설정
	setvbuf(stdout, NULL, _IOFBF, 100000000);
	
	printf("--------------------------------------------\n");
    printf("내가 계속 찾는게 있거든...뭔지 알아?...소수\n\n");
    printf("나가기: break\n");
	while(1) {
    int i, n, mult, MAX_TARGET;
    printf("--------------------------------------------\n");
    printf("n 안의 소수, n = ");
	fflush(stdout);

    scanf("%d", &MAX_TARGET);
    if (MAX_TARGET == 0) {
    	break;
	} else if (MAX_TARGET == 1) {
		printf("\n1은 소수가 아님\n");
	    continue;
	}
	
    int start = clock();
    
	// 1외에는 모두 소수라고 가정  
	isPrimeNumber[1] = 0;
	for (i = 2; i < MAX_TARGET+1; i++)
	{
		isPrimeNumber[i] = 1;
	}

	// 에라토스테네스의 체
	int num_primes = 0;
	for (n = 2; n <= floor(sqrt(MAX_TARGET)); n++)
	{
		// n이 소수가 아닌 경우 continue
		if (!isPrimeNumber[n]) 
		{
			continue;
		}
		// 소수인 n의 배수들 모두 제거
		for (mult = 2; n * mult <= MAX_TARGET; mult++) {
			isPrimeNumber[n*mult] = 0;
		}
	}
	
    int elapsed = clock();
    
    
	// 에라토스테네스의 체를 이용하여 소수들만 남은 배열 출력
	printf("\n");
	int start2 = clock();
	for (i = 1; i < MAX_TARGET+1; i++)
	{
		// 소수인 숫자들 모두 출력
		if (isPrimeNumber[i])
		{
			++num_primes;
			printf("%d ", i); // 출력방법 1
			// fprintf(stdout, "%d ", i); // 출력방법 2 
			// char s[8]; // 자릿수                     // 출력방법 3 
			// fprintf(stdout, "%s ", itoa(i, s, 10));  // 출력방법 3		
		}
	}
	int elapsed2 = clock();
	
    printf("\n\n찾는 시간 : %.3f sec\n", (double)(elapsed - start)/CLOCKS_PER_SEC);
    printf("출력 시간 : %.3f sec\n", (double)(elapsed2 - start2)/CLOCKS_PER_SEC);
    printf("소수 비율 : %d / %d (%.2f %%)\n", num_primes, MAX_TARGET, (float)num_primes/(float)MAX_TARGET*100);
	}
    free(isPrimeNumber);
	return 0;
}