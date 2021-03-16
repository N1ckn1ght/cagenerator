#include <iostream>
#include <vector>
#include <string>

using namespace std;

void next_g1(vector <int>& g1)
{
	int temp = (g1[2] + g1[9]) % 2;
	for (int i = 9; i > 0; i--)
	{
		g1[i] = g1[i - 1];
	}
	g1[0] = temp;
}

void next_g2(vector <int>& g2)
{
	int temp = (g2[1] + g2[2] + g2[5] + g2[7] + g2[8] + g2[9]) % 2;
	for (int i = 9; i > 0; i--)
	{
		g2[i] = g2[i - 1];
	}
	g2[0] = temp;
}

int main()
{

	vector <int> g1(10, 1);
	vector <int> g2(10, 1);
	string code = "";
	string number;
	int satellite = 0;
	int cycle = 1023;

	vector <pair <int, int>> input({
		{2, 6}, {3, 7}, {4, 8}, {5, 9}, {1, 9}, {2, 10}, {1, 8}, {2, 9},
		{3, 10}, {2, 3}, {3, 4}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10},
		{1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}, {6, 9}, {1, 3}, {4, 6},
		{5, 7}, {6, 8}, {7, 9}, {8, 10}, {1, 6}, {2, 7}, {3, 8}, {4, 9}
	});

	cout << "Input satellite id: ";
	cin >> number;
	
	try
	{
		satellite = stoi(number);
	}
	catch (invalid_argument)
	{
		cout << "Error: satellite id should be a numeric value.";
		return 0;
	}

	if (satellite < 0 || satellite > input.size())
	{
		cout << "Error: sattelite id is not found in database.";
		return 0;
	}

	for (int i = 0; i < cycle; i++)
	{
		next_g1(g1);
		next_g2(g2);
		int temp_g1 = g1[9];
		int temp_g2 = g2[input[satellite - 1].first - 1] ^ g2[input[satellite - 1].second - 1];
		int temp = temp_g1 ^ temp_g2;
		code += to_string(temp);
	}

	cout << code;
}
