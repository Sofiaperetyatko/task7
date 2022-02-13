// task7. 18

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
char** matrix_memory_allocation(int size)// ������� ��� �������� ���������� �������, 
//���� ������ ����� ����� �������� ����� ����� ������ � ����, ����� ����� ���������� � ������ �������
{
	
	char** matrix = new char* [size];
	for (int i = 0; i < size; ++i)
		matrix[i] = new char[size];
	return matrix;
}
char* array_memory_allocation(int size)// ���������� ������ ��� ����,����� ������ ����� ������
{

	return new char[size];
}
int* array_int_memory_allocation(int size)//���������� ������ ��� ����,����� ������ ����� �����
{
	
	return new int[size];
}
void print_massive_char(const char* word, char* array, int& n)// �������,����� ������ ������
{
	
	cout << word;
	int i = 0;
	do
	{
		array[i] = getchar();
		i++;
	} while (i <= n && array[i - 1] != '\n');
	n = i;
}
void matrix_memory_liberation(char**& matrix, int size)// ������� ��� �������� ���������� �������
{
	for (int i = 0; i < size; ++i)
		delete[]matrix[i];
	delete[]matrix;
}
void array_memory_liberation(int*& array, int size)// ������� ��� �������� ����������� �������
{
	delete[]array;
}
char** allocation_word(char* dmass, int size, int* len_word, int& k)// � ���� ������� �� ������� �� ������ ����� ����������,

{
	
	int l = 0;
	k = 0;
	char s[6] = { '!', '.', '?', ',', ' ', '\n'};
	char** matrix = matrix_memory_allocation(size);
	for (int i = 0; i < size; ++i)
	{
		if (dmass[i] != s[0] && dmass[i] != s[1] && dmass[i] != s[2] && dmass[i] != s[3] && dmass[i] != s[4] && dmass[i]!=s[5])// ���� �������
	//� ��������� �������(������) �� ����� ������ �� ���� ��������,�� ���������� ��� � ���������� ������,����� ����� ������� ������ �� �����

		{
			matrix[k][l] = dmass[i];
			++l;
		}
		else
		{
			if (dmass[i - 1] != s[0] && dmass[i - 1] != s[1] && dmass[i - 1] != s[2] && dmass[i - 1] != s[3] && dmass[i - 1] != s[4])
			//�������� �� ������ ������ ����� ����������
			{
				len_word[k] = l;
				++k;
				l = 0;
			}
		}
	}
	return matrix;
}
void look_matix(char** matrix, int size, int* len_word)// ������� ��� ������ ������� ����� 
{
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < len_word[i]; ++j)
		{
			
			cout << matrix[i][j];
		}
		cout << '\n';
	}
}
double proportion(char** matrix_1, int* len_word_1, int k, char** matrix_2, int* len_word_2, int z)
//������� ��� ������ ���� ���� � ������ ������,������� ����������� � �� ������ ������
{
	
	int count = 0;
	int number = 0;
	for (int i = 0; i < z; ++i)
	{
		for (int f = 0; f < k; ++f)
		{
			if (len_word_2[i] == len_word_1[f])
			{
				count = 0;
				for (int j = 0, q = 0; j < len_word_2[i] && q < len_word_1[f]; ++j, ++q)
				{
					if (matrix_2[i][j] == matrix_1[f][q])
						count++;
				}
				if (count == len_word_2[i])
					number++;
			}
		}
	}
	double result = static_cast<double>(number) / static_cast<double>(k);// ��������������� ��� int � double, 
	//��� ����� ������� ����������
	return result;
}


int main()
{
  system("chcp 1251"); //����� ��������� ������� ����� � �������(����������� ��������� �������)
  system("cls");// ����� �� ���������� ��������� � ���������( ������� ���� �������)
 
	  int n = 256;//���������� �������� � 1 ������( � ��������� � ��������� ������� ��� 1 ������)
	  int d = 256;
	  int  k = 0;//���������� ���� � 1 ������
	  int z = 0;//���������� ���� � 2 ������

	  char* dmass_1 = array_memory_allocation(n);
	  print_massive_char("������� ������ ������:\n", dmass_1, n);
	  int* len_word_1 = array_int_memory_allocation(n);
	  char** matrix_1 = allocation_word(dmass_1, n, len_word_1, k);
	  look_matix(matrix_1, k, len_word_1);


	  char* dmass_2 = array_memory_allocation(d);
	  print_massive_char("������� ������ ������:\n", dmass_2, d);
	  int* len_word_2 = array_int_memory_allocation(d);
	  char** matrix_2 = allocation_word(dmass_2, d, len_word_2, z);
	  look_matix(matrix_2, z, len_word_2);

	  double r = proportion(matrix_1, len_word_1, k, matrix_2, len_word_2, z);
	  cout << "���� ������������� ���� �����: " << r;

	  matrix_memory_liberation(matrix_1, n);//������� ������ �� ������� �� ������ ������
	  matrix_memory_liberation(matrix_2, d);//������� ������ �� ������� �� ������ ������
	  array_memory_liberation(len_word_1, n);
	  array_memory_liberation(len_word_2, d);
  
}

