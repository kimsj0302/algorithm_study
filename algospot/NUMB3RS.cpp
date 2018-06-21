#include <iostream>

#include <vector>

#include <cstring> //memset

using namespace std;



int villageNum, day, jail, searchNum; //������ ��, Ż�� �� �� ��, ������ �ִ� ��ȣ, ã�� ���� ������ ��

int village[50][50]; //�ִ� 50�� ����

int adjacent[50]; //adjacent[i]�� ���� i�� ������ ������ ��

double cache[50][100]; //�ִ� 50�� ����, �ִ� 100��


double search(int here, int days) //here �ش� ����, days: ���� �� ��

{

	//���� ���

	if (days == 0)

		return (here == jail ? 1.0 : 0.0); //������ ����

										   //�޸������̼�

	double &result = cache[here][days];

	if (result != -1.0)

		return result;

	result = 0.0;

	//�Ųٷ� Ȯ���� ����Ѵ�. �� �ش� �������� ����(�������̶�� �������� ����)

	for (int there = 0; there < villageNum; there++)

		if (village[here][there]) //there�� �������ִٸ�

			result += search(there, days - 1) / adjacent[there]; //��(1/adjacent(there) * search(there, days-1));

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

				adjacent[j] += village[j][k]; //������ ���� ���� �ʱ�ȭ



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