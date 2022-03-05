#include <iostream>
#include <vector>
using namespace std;

//sudoku(n)�� ȣ���ؼ� 1~81���� �˻縦 �ϰ� n == 82�� �Ǹ� cout << sudoku
//�Լ� ���ο��� [i][j] == 0 �̸� k�� 1~9���� �����ٿ� �ִ���, �����ٿ� �ִ���, ���� �簢��(3*3)�� �ִ��� �˻�
//�˻� ����� [i][j] = k �ϰ� sudoku(n+1) ȣ��
//�˻纤�� checkRow[i][j] == true ��� i��° �࿡ j���ڰ� �̹� �ִٴ� ������ false��� �� ���ڰ� ���� ���ٴ� ��


void MakeSudoku(int tile);

vector<vector<int>> sudoku(10, vector<int>(10));  //������ ����� ����(pushback����� ���� ù��° ĭ�� �ϳ��� �־��ش�.)
vector<vector<bool>> in_row(10, vector<bool>(10, false));  //���ο��� ���� �Ǵܿ� ����
vector<vector<bool>> in_col(10, vector<bool>(10, false));  //���ο��� ���� �Ǵܿ� ����
vector<vector<bool>> in_box(10, vector<bool>(10, false));  //���� �簢���� ���� �Ǵܿ� ����

int G4_2580(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 9; ++i)
	{
		vector<int> line(10);

		for (int j = 0; j < 9; ++j)
		{
			int num;
			cin >> num;

			line[j] = num;  //���پ� �Է� �ޱ�

			if (num != 0)
			{
				in_row[i][num] = true;  //�ش� ���� num�� �ش��ϴ� ���� ���� ����
				in_col[j][num] = true;  //�ش� ���� num�� �ش��ϴ� ���� ���� ����
				in_box[((i / 3) * 3) + (j / 3)][num] = true;
				//�ش� �ڽ��� num�� �ش��ϴ� ���� ���� ����
				//(���ȣ/3)*3 + (����ȣ/3) �ϸ� ���������� 0�� �ڽ�, ������ �� �Ʒ��� 8�� �ڽ��� �ȴ�.
			}
		}

		sudoku[i] = line;

	}


	MakeSudoku(0);  // ù��° ĭ���� ��ġ ����

	return 0;
}



void MakeSudoku(int tile)
{
	if (tile == 81)  //tile == 81 �̶�� ��� Ÿ���� �� ä���ٴ� ���̹Ƿ�
	{
		for (int i = 0; i < 9; ++i)  //�䱸���ǿ� �°� ����Ѵ�.
		{
			for (int j = 0; j < 9; ++j)
			{
				cout << sudoku[i][j] << " ";
			}

			cout << "\n";
		}

		exit(0);  //���� ��������(ex ���� ��ĭ) �ٷ� ������ �ϹǷ� �ٷ� �������ش�.
	}


	//tile�� 81�� �ƴ϶��
	//���� �ݺ����� ���� ���� ������ �߻��Ͽ� tile�� ���� ���� ��� ���� ����Ѵ�.
	//���� tile�� 9�� ���� �� ���� 9�� ���� ������ ���̴�.
	int row = tile / 9;
	int col = tile % 9;

	if (sudoku[row][col] != 0)  //���� �ش�ĭ�� ��ĭ�� �ƴ϶��
	{
		MakeSudoku(tile + 1);  //����ĭ���� �Ѿ��.
	}

	else  //�ش� ĭ�� ��ĭ�̶��
	{
		for (int k = 1; k <= 9; ++k)  //���� �� �ִ� �� 1~9������ �˻��Ѵ�.
		{
			if (!in_row[row][k] && !in_col[col][k] && !in_box[((row / 3) * 3) + (col / 3)][k])
				//��,��,�ڽ� �˻翡�� ��� false�� ���;� ���� �� �ִ� ���̴�.
			{
				in_row[row][k] = true;
				in_col[col][k] = true;
				in_box[((row / 3) * 3) + (col / 3)][k] = true;  //�ش� ��,��,�ڽ��� ���� ������ ���� ���θ� true�� ����
				sudoku[row][col] = k;  //������ �Է��Ѵ�.

				MakeSudoku(tile + 1);  //���� ĭ���� �����Ѵ�.

				//�� �Ʒ��� ����ȴٴ� ���� k�� �ְ� ���� ��ĭ�� 1~9������ ���� ���� �� �ִ� ���� ���ٴ� ���̴�.
				//�� ����ĭ ȣ�� ���������� ���� k�� �߸��Ǿ��ٴ� ���̹Ƿ� �ش� ���� �ٽ� �����Ѵ�.

				in_row[row][k] = false;
				in_col[col][k] = false;
				in_box[((row / 3) * 3) + (col / 3)][k] = false;  //��, ��, �ڽ��� ���� ������ ���� ���θ� false�� ����
				sudoku[row][col] = 0;  //�ٽ� ��ĭ���� ����� �������� ������ k�� ã�´�.

			}
		}
	}




}