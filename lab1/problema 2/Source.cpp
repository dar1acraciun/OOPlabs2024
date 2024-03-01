#include <iostream>
#include <stdio.h>
using namespace std;

typedef char cuvant[200];

int main() {

	int nr=0;
	cuvant str[50];
	int cnt[50];
	int maxim = 0;
	while (scanf_s("%19s", str[nr], 19))
	{
		if (strchr(str[nr], '\n'))
			break;
		cnt[nr] = strlen(str[nr]);
		for (int i = 0; i < nr; i++)
			for (int j = i + 1; j < nr; j++)
				if (cnt[i] > cnt[j])
					swap(cnt[i], cnt[j]), swap(str[i], str[i + 1]);
	
		nr++;
    }
	for (int i = 0; i < nr; i++)
		printf(str[nr]),printf("\n\n");


}