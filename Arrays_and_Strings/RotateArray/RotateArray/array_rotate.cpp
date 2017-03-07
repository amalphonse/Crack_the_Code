#include<iostream>

using namespace std;

#define R 4
#define C 4

void print(int m[R][C]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << m[i][j];
		}
		cout << endl;
	}
}
void rotate_array_clockwise(int a[R][C], int m, int n) {
	int row = 0, col = 0;
	int prev, curr;

	while (row < m && col < n) {

		prev = a[row + 1][col];
		//First moving the top row.
		for (int i = col; i < n; i++) {
			curr = a[row][i];
			a[row][i] = prev;
			prev = curr;
		}
		row++;
		//2. Move the last column.
		for (int i = row; i < n; i++) {
			curr = a[i][n - 1];
			a[i][n - 1] = prev;
			prev = curr;
		}
		n--;
		//3. Move bottom row
		if (row < m) {
			for (int i = n-1; i >= col; i--) {
				curr = a[m-1][i];
				a[m-1][i] = prev;
				prev = curr;
			}
		}
		m--;
		if (col < n)
		{
			for (int i = m - 1; i >= row; i--)
			{
				curr = a[i][col];
				a[i][col] = prev;
				prev = curr;
			}
		}
		col++;
	}
	cout << "The rotated array: " << "/n";
	print(a);

}



int main() {
	int m[R][C] = { { 1,  2,  3,  4 },
	{ 5,  6,  7,  8 },
	{ 9,  10, 11, 12 },
	{ 13, 14, 15, 16 } };

	// Tese Case 2
	/* int a[R][C] = {{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
	};
	*/  
	print(m);
	rotate_array_clockwise(m,R,C);
	//print(m);
	return 0;
}