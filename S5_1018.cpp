#include <iostream>
#include <algorithm>
using namespace std;

//8<=N,M<=50�� 2���̹Ƿ� �ð��� �˳�
//������ �����ϴ� ���̽�1�� ������ �����ϴ� ���̽�2�� �ΰ�
//��ü ����� ���� ���� �� ���� ���� ���� ���


int S5_1018(void)
{
	//������� �����ϴ� ���
	string firstCase[8] = { "WBWBWBWB",
							"BWBWBWBW",
							"WBWBWBWB",
							"BWBWBWBW",
							"WBWBWBWB",
							"BWBWBWBW",
							"WBWBWBWB",
							"BWBWBWBW" };

	//���������� �����ϴ� ���
	string secondCase[8] = { "BWBWBWBW",
							 "WBWBWBWB",
							 "BWBWBWBW",
							 "WBWBWBWB",
							 "BWBWBWBW",
							 "WBWBWBWB",
							 "BWBWBWBW",
							 "WBWBWBWB" };


	int v, h;
	cin >> v >> h;  //vertic ����, horizon ����

	string board[50];  //������Ȳ �ʱ�ȭ, �Է�

	for (int i = 0; i < v; ++i)
	{
		string line;
		cin >> line;

		board[i] = line;
	}

	int isMin = 65;  //���� ��°�. 65=8*8+1;

	//board�� ����, ���ΰ� ������ ��ŭ 8*8 Ž�� �ݺ�
	for (int i = 0; i + 7 < v; ++i)
	{
		for (int j = 0; j + 7 < h; ++j)
		{
			int firstNum = 0;
			int secondNum = 0; //�� ���̽��� �ּڰ�

			for (int k = 0; k < 8; ++k)  //8*8��ŭ �� ���̽��� ��
			{
				for (int l = 0; l < 8; ++l)
				{
					if (board[i + k][j + l] != firstCase[k][l])
					{
						firstNum++;  //ù��° ���� �ٸ���� firstNum++
					}

					if (board[i + k][j + l] != secondCase[k][l])
					{
						secondNum++;  //�ι�° ���� �ٸ���� secondNum++;
					}
				}
			}

			isMin = min(isMin, min(firstNum, secondNum));  
			//�������� first�� second�� �� ���� ������
			//���� ���� ���� ���� ���� ������ ����

		}

		
	}


	cout << isMin;  //��� ���


	return 0;
}