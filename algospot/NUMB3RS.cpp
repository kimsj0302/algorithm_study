#include <iostream>

#include <vector>

#include <cstring> //memset

using namespace std;



int villageNum, day, jail, searchNum; //마을의 수, 탈출 후 일 수, 교도소 있는 번호, 찾고 싶은 마을의 수

int village[50][50]; //최대 50개 마을

int adjacent[50]; //adjacent[i]는 마을 i와 인접한 마을의 수

double cache[50][100]; //최대 50개 마을, 최대 100일


double search(int here, int days) //here 해당 마을, days: 지난 일 수

{

	//기저 사례

	if (days == 0)

		return (here == jail ? 1.0 : 0.0); //시작은 감옥

										   //메모이제이션

	double &result = cache[here][days];

	if (result != -1.0)

		return result;

	result = 0.0;

	//거꾸로 확률을 계산한다. 즉 해당 마을부터 시작(정방향이라면 감옥부터 시작)

	for (int there = 0; there < villageNum; there++)

		if (village[here][there]) //there와 인접해있다면

			result += search(there, days - 1) / adjacent[there]; //∑(1/adjacent(there) * search(there, days-1));

	return result;

}



int main(void)

{

	int test_case;

	cin >> test_case;

	if (test_case < 1 || test_case>50)

		exit(-1);



	for (int i = 0; i < test_case; i++)

	{

		cin >> villageNum >> day >> jail;

		if (villageNum < 2 || villageNum>50 || day < 1 || day>100 || jail < 0 || jail >= villageNum)

			exit(-1);

		for (int j = 0; j < villageNum; j++)

			for (int k = 0; k < villageNum; k++)

				cin >> village[j][k];

		for (int j = 0; j < 50; j++)

			for (int k = 0; k < 100; k++)

				cache[j][k] = -1;

		memset(adjacent, 0, sizeof(adjacent));

		for (int j = 0; j < villageNum; j++)

			for (int k = 0; k < villageNum; k++)

				adjacent[j] += village[j][k]; //인접한 마을 갯수 초기화



		cin >> searchNum;

		if (searchNum > villageNum || searchNum < 1)

			exit(-1);

		vector<int> v;

		for (int j = 0; j < searchNum; j++)

		{

			int there;

			cin >> there;

			if (there<0 || there>villageNum - 1)

				exit(-1);

			v.push_back(there);

		}

		for (int j = 0; j < searchNum; j++)

		{

			cout.precision(8);

			cout << search(v[j], day) << " ";

		}

		cout << endl << endl;

	}

	return 0;

}