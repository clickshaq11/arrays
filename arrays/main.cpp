#include <fstream>
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <sstream>

const int SIZE = 5;
int getArraySize();
void countEqualElements(int* array, int size);

int main() {
	setlocale(LC_ALL, "Rus");
	//
	int array1[SIZE] = { 1, 1, 1, 1, 1 };
	countEqualElements(array1, SIZE);
	//
	int N;
	N = getArraySize();
	int* array2 = new int[N];
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < N; i++) {
		array2[i] = rand() % 2;
		std::cout << array2[i] << " ";
	}
	countEqualElements(array2, N);
	delete[] array2;
	//
	std::ifstream inFile;
	std::string path = "test.txt";
	inFile.open(path);
	if (inFile.is_open()) {
		std::cout << "success" << "\n";
	}
	else {
		std::cout << "failure" << "\n";
	}
	std::string curStr;
	std::string curStr2;
	
	while (!(inFile.eof())) {
		std::getline(inFile, curStr);
		int a = atoi(curStr.c_str());
		int* array3 = new int[a];
		std::getline(inFile, curStr2);
		std::istringstream iss(curStr2);
		for (int i = 0; i < a; i++) {
			iss >> array3[i];
			std::cout << array3[i] << " ";
		}
		countEqualElements(array3, a);
		delete[] array3;
	}
	inFile.close();
}

int getArraySize() {
	int s;
	while (!(std::cin >> s)) {
		std::cin.clear();
		std::cin.get();
		std::cout << "������� �������� �������� ������� �������." << std::endl;
	}
	return s;
}

void countEqualElements(int* array, int size) {
	int count = 1;
	int countBuffer = 1;
	for (int i = 1; i < size; i++) {
		if (array[i-1] == array[i]) {
			countBuffer += 1;
		}
		else {
			if (countBuffer > count) {
				count = countBuffer;
			}
			countBuffer = 1;
		}
	}
	if (countBuffer > count) {
		count = countBuffer;
	}
	std::cout << "\n������������ ���������� ������ ������ ��������� �����: " << count << std::endl;
}