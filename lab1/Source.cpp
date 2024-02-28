#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long convert(char stringg[201])
{
	long long  x=0;
	for (int i = 0; stringg[i]!='\0'; i++)
		if (stringg[i] >= '0'&& stringg[i] <= '9')
			x = x * 10 + (stringg[i] - '0');
	return x;
}

int main() {
	FILE *fp;
	long long s=0;
	if (fopen_s(&fp, "in.txt", "r") != 0)
		printf("EROARE\n");
	else {
		char stringg[201];
		while (fgets(stringg, 201, fp))
		{
			stringg[strlen(stringg) - 1] = '\0';
			long long  x = convert(stringg);
			s += x;
		}
		printf("%lld",s);
	}


}