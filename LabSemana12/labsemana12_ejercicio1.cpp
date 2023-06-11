#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <string>

using namespace std;

int main() 
{
	int V = 0;
	unordered_map<int, char> vertex;
	
	vertex[0] = 'A';
	vertex[1] = 'B';
	vertex[2] = 'C';
	vertex[3] = 'D';
	vertex[4] = 'E';
	vertex[5] = 'F';
	vertex[6] = 'G';
	vertex[7] = 'H';
	vertex[8] = 'I';
	vertex[9] = 'J';
	
	V = 9;
	
	for (const auto& pair : vertex) 
	{
		const int& key = pair.first;
		char value = pair.second;
		cout << "Key: " << key << ", Value: " << value << endl;
	}
}

