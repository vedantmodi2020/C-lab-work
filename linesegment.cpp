#include <iostream>
using namespace std;
struct point {
	int x, y;
};
const int RIGHT = 1, LEFT = -1, ZERO = 0;

int directionOfPoint(point A, point B, point P)
{
	B.x -= A.x;
	B.y -= A.y;
	P.x -= A.x;
	P.y -= A.y;
	int cross_product = B.x * P.y - B.y * P.x;
	if (cross_product > 0)
		return RIGHT;

	if (cross_product < 0)
		return LEFT;

	return ZERO;
}

int main()
{
	point A, B, P;
	cout<<"\nEnter the coordinates for the line Segment\n";
	cin>>A.x;
	cin>>A.y;
	cin>>B.x;
	cin>>B.y;
	cout<<"\n\nEnter the coordinates for the point\n";
	cin>>P.x;
	cin>>P.y;


	int direction = directionOfPoint(A, B, P);
	if (direction == 1)
		cout << "Right Direction" << endl;
	else if (direction == -1)
		cout << "Left Direction" << endl;
	else
		cout << "Point is on the Line" << endl;
	return 0;
}
