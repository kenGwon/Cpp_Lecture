
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // C++용으로 변환: iostream
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_PEOPLE 10
#define MAX_DATA 100

int main(int argc, char* argv[]) {

	char str_tmp[MAX_DATA], name[MAX_PEOPLE + 1][20], num[MAX_PEOPLE + 1], * p;
	int kor[MAX_PEOPLE + 1], eng[MAX_PEOPLE + 1], math[MAX_PEOPLE + 1], sci[MAX_PEOPLE + 1], role[MAX_PEOPLE + 1], acc[MAX_PEOPLE + 1];
	int i = 0, sum[MAX_PEOPLE + 1], avg[MAX_PEOPLE + 1], rank[MAX_PEOPLE + 1], var[MAX_PEOPLE + 1], s, j = 0, k = 0;
	double std[MAX_PEOPLE + 1];
	FILE* pFile, * outFile; // C++용으로 변환
	char* temp;
	char t1[10], t2[10], t3[10], t4[10], t5[10], t6[10], t7[10], t8[10], t9[10], t10[10], t11[10], t12[10]; // 콤마로 쪼개진 파일들을 임시로 넣어두기 위해서???

	pFile = fopen("sungjuk.csv", "r"); // C++용으로 변환
	outFile = fopen("Trans.csv", "w"); // C++용으로 변환

	if (pFile != NULL)
	{
		i = 0, sum[0] = sum[1] = 0; // 초깃값 셋팅

		while (!feof(pFile))
		{
			fgets(str_tmp, MAX_DATA, pFile); // 한줄을 읽어옴
			printf(" %d data : %s ", i, str_tmp);
			//printf("===============================================\n");
			if (i >= 1)
			{
				s = 0; j = 0; sum[i] = 0;
				p = strtok(str_tmp, ",");   // ,기준으로  끊어서 구분

				// printf("%s, ", p);  // number
				num[i] = atoi(p);

				p = strtok(NULL, ",");
				// printf("%s, ", p); // name
				sprintf(name[i], "%s", p);

				p = strtok(NULL, ",");
				//  printf("%s, ", p); // kor
				kor[i] = atoi(p);
				sum[i] += atoi(p);

				p = strtok(NULL, ",");
				// printf("%s, ", p); // ENG
				eng[i] = atoi(p);
				sum[i] += atoi(p);

				p = strtok(NULL, ",");
				//   printf("%s, ", p); // MATH
				math[i] = atoi(p);
				sum[i] += atoi(p);


				p = strtok(NULL, ",");
				//   printf("%s, ", p); // scienc
				sci[i] = atoi(p);
				sum[i] += atoi(p);


				p = strtok(NULL, ",");
				//  printf("%s, ", p); // role
				role[i] = atoi(p);
				sum[i] += atoi(p);

				p = strtok(NULL, ",");
				//   printf("%s, ", p); // acc
				acc[i] = atoi(p);
				sum[i] += atoi(p);

				avg[i] = (int)(sum[i] / 6);
				// 표준편차, 분산 알고리즘 추가 
				var[i] = (pow(kor[i] - avg[i], 2) + pow(eng[i] - avg[i], 2) + pow(math[i] - avg[i], 2) + pow(sci[i] - avg[i], 2) + pow(role[i] - avg[i], 2) + pow(acc[i] - avg[i], 2)) / 6;
				std[i] = sqrt(var[i]);

				p = strtok(NULL, ",");
				//   printf("sum= %d ave=%d var=%d std=%.2lf", sum[i], avg[i], var[i], std[i]);
				//   printf("\n====================================================================\n");

			}
			// printf("sum[%d] =%d \n", i, sum[i]);
			i++;

			if (i > MAX_PEOPLE) break;
		}
		/*
			  for(i=1;i<=MAX_PEOPLE;i++)
	   {
	   if(i==1) sum[1]=k;
	   printf("sum[%d] =%d \n", i, sum[i]);
	   }
	   */        // 석차메기기 개선  (오류있음) 

	   /*
	   for (i = 1; i <= MAX_PEOPLE; i++)
		 {
			 s = 1;
			 for (int j = 1; j <= 10; j++)
			 {
				 if (sum[i] < sum[j]) s++;
			 }
			 rank[i] = s;
			 printf("%2d %s = rank %2d\n", i, name[i], rank[i]);
		 }
		 */

		// 공동 2등이 있으면, 1 2 2 4 5 ... 이렇게 가면 좋은데, 
		// 아래 알고리즘은 공동 2등이 있어도 앞에 있는 사람이 순위가 높게 책정된다.(1 2 3 4 5 ...)
		for (i = 1; i <= MAX_PEOPLE; i++) {
			rank[i] = 1;

			for (int j = 1; j <= MAX_PEOPLE; j++) {
				if (sum[i] < sum[j]) {
					rank[i]++;
				}
			}

			//printf("%2d %s = rank %2d\n", i, name[i], rank[i]);
		}

		////////////////////////
		/*   for(i=1;i<=MAX_PEOPLE;i++)
		{
		printf("%d =%d \n", i, sum[i]);
		}
		*/ ////////////////////////////////
		//csv 저장용 파일생성   
		printf("\n=============================================================================\n");
		printf("Num| name | kor| eng | math| sci | role| acc | sum | avg | rank| var | std  |\n");

		sprintf(str_tmp, "학번,성명,국어,영어,수학,과학,윤리,회계,총점,평균,석차,분산,표준편차\n");
		fputs(str_tmp, outFile);

		for (i = 1; i <= MAX_PEOPLE; i++)
		{
			printf("%2d |%s| %3d| %3d | %3d | %3d | %3d | %3d | %3d | %3d | %3d | %3d | %.2lf|\n",
				i, name[i], kor[i], eng[i], math[i], sci[i], role[i], acc[i], sum[i], avg[i], rank[i], var[i], std[i]);
			// to csv format
			_itoa_s(i, t1, 10);
			//    printf("%s", &t1); // 이름은 그냥 그 자체로 문자열이기 때문에 _itoa_s()변환이 필요 없었음
			_itoa_s(kor[i], t2, 10); 
			_itoa_s(eng[i], t3, 10); // 엑셀은 csv를 취급할 때 숫자든 문자든 전부 문자로 관리하기 때문에 _itoa_s()
			_itoa_s(math[i], t4, 10); // 원래 그냥 _itoa() 써도 됐겠지만, 비쥬얼 스튜디오에서 쓸라고 하다보니까
			_itoa_s(sci[i], t5, 10); // _itoa_s()함수의 세번째 파라미터에다가 몇개를 바꿀 것인지 그 최대치를 넣도록 함수가 바뀌었다.
			_itoa_s(role[i], t6, 10); // 첫날에 scanf()함수를 scanf_s()로 바꿔서 썼던게 바로 그 예시이다.
			_itoa_s(acc[i], t7, 10);
			_itoa_s(sum[i], t8, 10);
			_itoa_s(avg[i], t9, 10);
			_itoa_s(rank[i], t10, 10);
			_itoa_s(var[i], t11, 10);
			_itoa_s(std[i], t12, 10);
			sprintf(str_tmp, "%s,%s, %s,%s,%s,%s,%s,%s, %s,%s,%s,%s, %.2lf\n",
				t1, name[i], t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12);
			fputs(str_tmp, outFile);

		}
	}
	fclose(pFile);
	fclose(outFile);
	return 0;
}





#if 0 // 교재 예제

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char name[10], dept[20];
	int sid;

	ifstream fin("student.txt");

	if (!fin)
	{
		cout << "stdent.txt 파일을 열수 없습니다.";
		return 0;
	}

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();

}

#endif

#if 0 // 교재 예제

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char name[10], dept[20];
	int sid;

	// 키보드로부터 읽기
	cout << "이름 >> ";
	cin >> name;
	cout << "학번(숫자로) >> ";
	cin >> sid;
	cout << "학과 >> ";
	cin >> dept;

	ofstream fout("student.txt");

	if (!fout)
	{
		cout << "stdent.txt 파일을 열수 없습니다.";
		return 0;
	}

	// 파일 쓰기
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();

}

#endif