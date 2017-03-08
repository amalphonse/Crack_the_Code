#include<iostream>

using namespace std;
#define R 4
#define C 4
void print(int m[R][C], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << m[i][j]<<"\t";
		}
		cout << endl;
	}
}

void rotate_90(int m[R][C], int N) {
	int offset = 0;
	int first = 0;
	int last = 0;
	int top;
	/* We are rotating in 90 degree angle. SO dividing the N*N matrix in half, and
	moving from outer circle to inner range.
	1) Top <- left
	2) left <- bottom
	3) bottom <- right
	4) right <- top
	*/
	for (int layer = 0; layer < N / 2; layer++) {
		first = layer;
		last = N - 1 - layer;
		for (int i = first; i < last; i++) {
			offset = i - first;
			
			top = m[first][i];
			//1. Top <- left
			m[first][i] = m[last-offset][first];
			//2.left <- bottom
			m[last - offset][first] = m[last][last - offset];
			//3.  bottom <- right
			m[last][last - offset] = m[i][last];
			//4.right <- top
			m[i][last] = top;
		}
	}

}

int main() {
	int a[R][C] = { { 1,  2,  3,  4 },
	{ 5,  6,  7,  8 },
	{ 9,  10, 11, 12 },
	{ 13, 14, 15, 16 } };

	cout << "Before 90 degree rotation: " << endl;
	print(a, 4);
	rotate_90(a, 4);
	cout << "After 90 degree rotation: " << endl;
	print(a, 4);
	return 0;
}