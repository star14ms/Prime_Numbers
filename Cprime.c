#include <stdio.h>
#include <math.h> // floor, sqrt
#include <time.h> // clock, CLOCKS_PER_SEC
#include <stdlib.h> // malloc

int main()
{
	// (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�
    int *isPrimeNumber = (int *)malloc(sizeof(int) * 100000000);
	// char *text = malloc(sizeof(char) * 6000000);

	// ǥ�� ��� ���� ũ�� ũ�� ����
	setvbuf(stdout, NULL, _IOFBF, 100000000);
	
	printf("--------------------------------------------\n");
    printf("���� ��� ã�°� �ְŵ�...���� �˾�?...�Ҽ�\n\n");
    printf("������: break\n");
	while(1) {
    int i, n, mult, MAX_TARGET;
    printf("--------------------------------------------\n");
    printf("n ���� �Ҽ�, n = ");
	fflush(stdout);

    scanf("%d", &MAX_TARGET);
    if (MAX_TARGET == 0) {
    	break;
	} else if (MAX_TARGET == 1) {
		printf("\n1�� �Ҽ��� �ƴ�\n");
	    continue;
	}
	
    int start = clock();
    
	// 1�ܿ��� ��� �Ҽ���� ����  
	isPrimeNumber[1] = 0;
	for (i = 2; i < MAX_TARGET+1; i++)
	{
		isPrimeNumber[i] = 1;
	}

	// �����佺�׳׽��� ü
	int num_primes = 0;
	for (n = 2; n <= floor(sqrt(MAX_TARGET)); n++)
	{
		// n�� �Ҽ��� �ƴ� ��� continue
		if (!isPrimeNumber[n]) 
		{
			continue;
		}
		// �Ҽ��� n�� ����� ��� ����
		for (mult = 2; n * mult <= MAX_TARGET; mult++) {
			isPrimeNumber[n*mult] = 0;
		}
	}
	
    int elapsed = clock();
    
    
	// �����佺�׳׽��� ü�� �̿��Ͽ� �Ҽ��鸸 ���� �迭 ���
	printf("\n");
	int start2 = clock();
	for (i = 1; i < MAX_TARGET+1; i++)
	{
		// �Ҽ��� ���ڵ� ��� ���
		if (isPrimeNumber[i])
		{
			++num_primes;
			printf("%d ", i); // ��¹�� 1
			// fprintf(stdout, "%d ", i); // ��¹�� 2 
			// char s[8]; // �ڸ���                     // ��¹�� 3 
			// fprintf(stdout, "%s ", itoa(i, s, 10));  // ��¹�� 3		
		}
	}
	int elapsed2 = clock();
	
    printf("\n\nã�� �ð� : %.3f sec\n", (double)(elapsed - start)/CLOCKS_PER_SEC);
    printf("��� �ð� : %.3f sec\n", (double)(elapsed2 - start2)/CLOCKS_PER_SEC);
    printf("�Ҽ� ���� : %d / %d (%.2f %%)\n", num_primes, MAX_TARGET, (float)num_primes/(float)MAX_TARGET*100);
	}
    free(isPrimeNumber);
	return 0;
}