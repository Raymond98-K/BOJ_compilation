#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//이거 구조체로 되나??  -> 되네...
//멤버들의 나이, 이름, 순번을 저장하는 구조체 선언 후 벡터에 push back
//sort()의 compare 함수를 조건에 맞게 정의 후 사용


struct members  //멤버들의 나이와 이름, 순번을 가지는 구조체 선언
{
	int age;
	string name;
	int cnt;
};


bool compare(members first, members second);  //sort()를 위한 compare함수 선언

int S5_10814_1(void)
{
	vector<members> table;
	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)  //구조체에 정보 저장 후 벡터에 push back
	{
		members people;
		cin >> people.age >> people.name;
		people.cnt = i;
		
		table.push_back(people);
	}

	sort(table.begin(), table.end(), compare);  //요구 조건에 맞게 정렬

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].age << " " << table[i].name << "\n";  //출력
	}

	return 0;
}

bool compare(members first, members second)
{
	if (first.age == second.age)  //만약 두 회원의 나이가 같다면
	{
		return first.cnt < second.cnt;  //가입 순번이 더 빠른쪽이 우선됨
	}

	else
	{
		return first.age < second.age;  //나이가 다르다면 더 어린쪽이 우선됨
	}
}




bool cmp(pair<int, string> fst, pair<int, string> snd)
{
	return fst.first < snd.first;
}



//stable sort 사용하기
int S5_10814_2(void)
{
	vector<pair<int, string>> table;  //순서는 안정정렬을 사용할 것이므로 생각하지 않아도 된다.
	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		pair<int, string> members;
		cin >> members.first >> members.second;  //평범하게 pair에 값을 입력받고 벡터에 push back

		table.push_back(members);
	}

	stable_sort(table.begin(), table.end(), cmp);
	//안정 정렬
	// 5 2 1 4(1) 7 4(2) 8 일때 4가 두번이다. 순서대로 4(1) 4(2)일때 이걸 오름차순 정렬 시
	// 1 2 4(1) 4(2) 5 7 8 로 정렬 되는 것을 안정 정렬이라 한다.
	//즉 중복된 값들의 순서를 유지하면 안정 정렬, 그렇지 않으면 불안정 정렬이다.
	//이 문제에서 안정정렬시 가입한 순서대로의 조건이 만족된다.

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].first << " " << table[i].second << "\n";  //출력
	}


	return 0;
}