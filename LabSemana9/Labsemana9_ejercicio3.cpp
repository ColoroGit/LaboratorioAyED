#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point
{
	private:
	int X;
	int Y;
	
	public:
	Point()
	{
		
	}
	
	Point(int x, int y)
	{
		X = x;
		Y = y;
	}
	
	void SetX(int x)
	{
		X = x;
	}
	
	void SetY(int y)
	{
		Y = y;
	}
	
	int GetX()
	{
		return X;
	}
	
	int GetY()
	{
		return Y;
	}
	
	void PrintPoint()
	{
		cout << X << ", " << Y << endl;
	}
};

int main()
{
	vector<Point> poligon;
	Point p;
	int aristas;
	int i;
	
	cout << "Cuantas aristas tendr\xA0 su poligono: ";
	cin >> aristas;
	
	for (i = 0; i < aristas; i++)
	{
		int input;
		
		cout << "Ingrese la coordenada x del punto " << (char)('A' + i) << " de su poligono: ";
		cin >> input;
		p.SetX(input);
		
		cout << "Ingrese la coordenada y del punto " << (char)('A' + i) << " de su poligono: ";
		cin >> input;
		p.SetY(input);
		
		poligon.push_back(p);
	}
	
	for (i = 0; i < aristas; i++)
	{
		poligon[i].PrintPoint();
	}
	
	return 0;
}
