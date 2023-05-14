#include <iostream>
#include <string>

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
	Point p1;
	Point p2(3, 7);
	
	cout << p1.GetX() << ", " << p1.GetY() << endl;
	
	p1.SetX(4);
	p1.SetY(1);
	
	cout << p1.GetX() << ", " << p1.GetY() << endl;
	
	p2.PrintPoint();
	
	return 0;
}
