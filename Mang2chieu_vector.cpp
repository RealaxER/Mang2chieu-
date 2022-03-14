#include <iostream>
#define MAX 50  
using namespace std;
void xuat(int a[][MAX], int dong , int cot) // bắt buộc ghi cột 
{
	cout << "\t\t\t====XUAT===="<< endl;
	for (int i = 0; i < dong;i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}
void nhap(int a[][MAX], int dong, int cot)
{
	cout << "\t\t====NHAP GIA TRI ====" << endl;
	for (int i = 0; i < dong; i++)
	{
		cout << "\nNhap dong thu " << i << " : ";
		for (int j = 0; j < cot; j++)
		{
			cout << " \nNhap gia tri thu " << j << " cua dong " << i << " : ";
			cin >> a[i][j];
		}
	}
}
void duong_cheo_chinh(int a[][MAX], int dong)
{
	int S = 0;
	for (int i = 0; i < dong; i++)
	{
		if (a[i][i] % 2 !=0)
		{
			S = S + a[i][i];
		}
	}
	cout << S << endl;
}
void duong_cheo_phu(int a[][MAX], int dong)
{
	int temp = dong - 1;
	int S = 0;
	for (int i = 0; i < dong; i++)
	{
		if (a[i][temp] % 2 != 0)
		{
			S = S +  a[i][temp];
			temp--;
		}
	}
	cout << S << endl;
}
void Bai1(int a[][MAX], int dong, int cot)
{
	bool check = false;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (i == j)
			{
				a[i][j] = 0;
				check = true;
				continue;
			}
			if (check == false)
			{
				a[i][j] = -1;
			}
			else {
				a[i][j] = 1;
			}
		}
		check = false;
	}
}
void Bai2(int a[][MAX], int n ) {
	for (int i = 0; i < n; i++) // chạy dòng 
	{
		for (int j = 0; j <= i; j++) // chạy cột theo điều kiện dòng , dòng 1 thì chjay 1 cột 2 thì 2
		{
			if (j == 0) // nếu j = 0 tương ứng với vị trị đầu tiên luôn luôn bằng 0 bắt đk bằng = 1
			{
				a[i][0] = 1;
				continue;
			}
			else if (j == i) // vị trí cuối cùng luôn bằng 1
			{
				a[i][j] = 1;
			}
			else //nếu không phải đầu cuối thì áp công thức sau a[3] [2] sẽ bằng a[2] của dòng 2 + a[2-1] của dòng 2
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1]; // công thức a[i][j]  = a[i-1] [j] + a[i-1] [j-1];
			}
	
		}
	}
	// Xuất tam giác ra 
	for (int i = 0; i < n; i++) // chạy dòng 
	{
		for (int j = 0; j <=i ; j++) // chạy số hàng tương đương với dòng dòng 1 chạy  1 cột 2 chạy 2 
		{
			cout << a[i][j] << "  "; // cout ra giá trị 
		}
		cout << endl; // hét một dòng thì xuống dòng 
	}
}
int main()
{
	int dong;
	do
	{
		cout << "Nhap dong : " << endl; cin >> dong;
	} while (dong <= 0 || dong > MAX);
	int cot;
	do
	{
		cout << "Nhap cot : " << endl; cin >> cot;
	} while (cot <= 0 || cot > MAX);
	int a[MAX][MAX];
	//	nhap(a, dong, cot);
	//	xuat(a, dong,cot);

		//cout << "Duongcheochinh" << endl; 
		//duong_cheo_chinh(a, dong);

		//cout << "Duongcheophu" << endl;
		//duong_cheo_phu(a, dong);
	cout << "===NANG CAO===" << endl;
	//Bai1(a, dong, cot);
	//xuat(a, dong, cot);
	Bai2(a, dong);
	system("pause");
	return 0;

}