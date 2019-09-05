#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

//diferença de tempo
double performancecounter_diff(LARGE_INTEGER *start,LARGE_INTEGER *end){
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	return (double)(start->QuadPart - end->QuadPart)/(double)freq.QuadPart;
}

void shellSort(int *array, int size) {
	int i , j , value;
	int gap = 1;
	//determinar o tamanho do gap
	while(gap < size) {
		gap = 3*gap+1;
	}
	while (gap > 0) {
		for(i = gap; i < size; i++) {
			value = array[i];
			j = i;
			while (j > gap-1 && value <= array[j - gap]) {
				array[j] = array [j - gap];
				j = j - gap;
			}
			array [j] = value;
		}
		gap = gap/3;
	}
}

int main(){
	//variaveis para medição do tempo
	LARGE_INTEGER t_start, t_end;
	double secs;
	//arquivo para armazenamento dos resultados
	fstream fs("result.txt", ios::out |ios::app);
	fs.seekg(0L, ios::end);
	//geração dos vetores
	vector<int> vecOfRandomNums(100000);
	generate(vecOfRandomNums.begin(), vecOfRandomNums.end(), []() {return rand() % 10000;});
	int* vetorRandom = vecOfRandomNums.data();

	int vetorOrdCresc[100000];
	for (int i=0; i<100000; ++i) vetorOrdCresc[i] = i;

	int vetorOrdDecre[100000];
	for (int i=0, j=100000; i<100000; ++i,--j) vetorOrdDecre[i] = j;

	int vetorCrescDecre[100000];
	for (int i=0; i<50000; ++i) vetorCrescDecre[i] = i;
	for (int i=50000, j=50000; i<100000; ++i,--j) vetorCrescDecre[i] = j;

	int vetorDecreCresc[100000];
	for (int i=0, j=50000; i<50000; ++i,--j) vetorDecreCresc[i] = j;
	for (int i=50000, j=0; i<100000; ++i,j++) vetorDecreCresc[i] = i;
	

	//inicio da cronometragem e execução do código
	QueryPerformanceCounter(&t_start);
	shellSort(vetorRandom,100000);
	QueryPerformanceCounter(&t_end);
	//fim
	//escrevendo os resultados
	secs = performancecounter_diff(&t_end, &t_start);
	fs << secs << ',';

	//inicio da cronometragem e execução do código
	QueryPerformanceCounter(&t_start);
	shellSort(vetorOrdCresc,100000);
	QueryPerformanceCounter(&t_end);
	//fim
	//escrevendo os resultados
	secs = performancecounter_diff(&t_end, &t_start);
	fs << secs << ',';

	//inicio da cronometragem e execução do código
	QueryPerformanceCounter(&t_start);
	shellSort(vetorOrdDecre,100000);
	QueryPerformanceCounter(&t_end);
	//fim
	//escrevendo os resultados
	secs = performancecounter_diff(&t_end, &t_start);
	fs << secs << ',';

	//inicio da cronometragem e execução do código
	QueryPerformanceCounter(&t_start);
	shellSort(vetorCrescDecre,100000);
	QueryPerformanceCounter(&t_end);
	//fim
	//escrevendo os resultados
	secs = performancecounter_diff(&t_end, &t_start);
	fs << secs << ',';

	//inicio da cronometragem e execução do código
	QueryPerformanceCounter(&t_start);
	shellSort(vetorDecreCresc,100000);
	QueryPerformanceCounter(&t_end);
	//fim
	//escrevendo os resultados
	secs = performancecounter_diff(&t_end, &t_start);
	fs << secs << endl;
	fs.close();
	return 0;
}
