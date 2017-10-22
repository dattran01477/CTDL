// DoAnCTDLC1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<time.h>
using namespace std;

//string x;
//#pragma cin>>"nhap kieu du lieu ban muon:">>x;
#define ElementType int

struct Xe
{
	double gia;
	char ten[30];
	double trongLuong;
};
int Compare(int a, int b)
{
	if (a > b)
		return 1;
	/*if (a >= b)
		return 2;
	if (a <= b)
		return 3;*/
	return 0;
}
int Compare(double a, double b)
{
	if (a > b)
		return 1;
	
	
		return 0;
	
}
int Compare(Xe xe1, Xe xe2)
{
	if (xe1.gia > xe2.gia)
		return 1;
	if (xe1.gia >= xe2.gia)
		return 2;
	if (xe1.gia <= xe2.gia)
		return 3;
	return 0;
}
void Mang(Xe xe[], int &n)
{
	cout << "Nhap so chiec xe n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Xe thu " << i << ":" << endl;
		cout << "Ten Xe: ";
		cin >> xe[i].ten;
		cout << "Gia xe ";
		cin >> xe[i].gia;
		cout << "Trong luong xe (kg): ";
		cin >> xe[i].trongLuong;
	}
}
void XuatMang(Xe xe[], int n)
{
	cout << "Danh sach thong tin xe:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "xe thu " << i << ":" << endl;
		cout << "Ten Xe: " << xe[i].ten << "\t";
		cout << "Gia Xe: " << xe[i].gia << endl;
		cout << "Trong Luong: " << xe[i].trongLuong << endl << endl;
	}
}

void XuatMang(int a[], int&n)
{
	cout << "\n";
	for (int i = 0;i < n;i++)
		cout << a[i]<<" ";
	
}

void Mang(int a[], int &n)
{
	srand(time(NULL));
	int x;

	cout << "nhap so phan tu ban muon tao:";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		x = rand() % 100 + 1;
		a[i] = x;
	}
	XuatMang(a,n);
		

}
//Hàm Đổi vị trí
void Swap(ElementType &a, ElementType &b)
{
	ElementType temp;
	temp = a;
	a = b;
	b = temp;
}

void SelectionSort(ElementType a[], int n)
{
	int min;
	for (int i = 0;i < n - 1;i++)
	{
		min = i;
		for (int j = i + 1;j < n;j++)
		{
			if (Compare(a[j],a[min]))
			{
				min = j;
			}
			if (min != i)
				Swap(a[min], a[i]);
		}
	}
}
void InsertSort(ElementType a[], int n)
{
	ElementType temp;
	int j;
	for (int i = 1;i < n;i++)
	{
		temp = a[i];
		j = i - 1;
		while (Compare(temp , a[j]) && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}
void BubbleSort(ElementType a[], int n)
{
	for (int i = 1;i < n ;i++)
		for (int j = 0;j < n - i;j++)
			if (Compare(a[j] , a[j + 1]))
				Swap(a[j], a[j + 1]);
}
void SnakeSort(ElementType a[], int n)
{
	for (int i = 1;i < n / 2;i++)
	{
		for (int j = 0;j < n - i;j++)
		{
			if (Compare(a[j] , a[j + 1]))
				Swap(a[j], a[j + 1]);

		}
		for (int t = n-i;t >= i;t--)
		{
			if (Compare(a[t] , a[t - 1])==0)
				Swap(a[t], a[t - 1]);

		}

	}
}
void QuickSort(ElementType a[], int left, int right)
{
	ElementType pivot = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (Compare(a[i],pivot))
			i++;
		while (Compare(pivot, a[j]))
			j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;

		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (right > i)
		QuickSort(a, i, right);
}
int BinarySearch(ElementType a[], int n, ElementType x)
{
	int dau = 0;
	int cuoi = n - 1;
	int mid;
	while (dau<=cuoi)
	{
		mid = (cuoi+dau) / 2;
		if (Compare(a[mid],x)==2&&Compare(a[mid-1],x)==3)
		{
			return mid;
		}
		if(Compare(a[mid],x)==1)
		cuoi = mid - 1;
		if (Compare(a[mid] , x)==0)
		dau = mid + 1;
		
	}
	return n;
	
	
	
}
void SelectionSortBinary(ElementType a[], int n)
{
	ElementType temp;
	int j,vt;
	for (int i = 1;i < n;i++)
	{
		temp = a[i];
		j = i - 1;
		vt = BinarySearch(a, j+1, temp);
		while (j>=vt&&j>=0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	
}
void QuickSortFirstPivot(ElementType a[], int left, int right)
{
	ElementType pivot = a[left] ;
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (Compare(a[i] , pivot))
			i++;
		while (Compare(pivot,a[j]))
			j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;

		}
	};
	if (left < j)
		QuickSortFirstPivot(a, left, j);
	if (right > i)
		QuickSortFirstPivot(a, i, right);
}
void Menu()
{
	ElementType a[100];
	int n;
	int x;
	Mang(a, n);
	cout << "\n--------------------------------------------------";
	cout << "\nchon kieu sap xep:" << endl;
	cout << "1.InsertionSort1" << endl;
	cout << "2.SelectionSort" << endl;
	cout << "3.BubbleSort" << endl;
	cout << "4.QickSort1" << endl;
	cout << "5.shakerSort" << endl;
	cout << "6.QickSort2" << endl;
	cout << "7.InsertionSort2" << endl;
	cout << "xin moi chon";

	a:cin >> x;
	cout << "\n--------------------------------------------------"<<endl;
	switch (x)
	{
		case 1:
		{
			cout << "Ban da chon InsertSort";
			InsertSort(a, n);
			XuatMang(a, n);
		}
		break;
		case 2:
		{
			cout << "Ban da chon SelectionSort";
			SelectionSort(a, n);
			XuatMang(a, n);
		}
		break;
		case 3:
		{
			cout << "Ban da chon BubbleSort";
			BubbleSort(a, n);
			XuatMang(a, n);
		}
		break;
		case 4:
		{
			cout << "Ban da chon QuickSort1";
			QuickSort(a, 0, n - 1);
			XuatMang(a, n);
		}
		break;
		case 5:
		{
			cout << "SnakeSort";
			SnakeSort(a, n);
			XuatMang(a, n);
		}
		break;
		case 6:
		{
			cout << "Ban da chon QuickSort 2";
			QuickSortFirstPivot(a, 0, n - 1);
			XuatMang(a, n);
		}
		break;
		case 7:
		{
			cout << "Ban da chon SelectionSortBinary";
			SelectionSortBinary(a, n);
			XuatMang(a, n);
		}
		break;
	default:
	{
		cout << "moi nhap lai";
		goto a;
	}
	
		break;
	}
	cout << "\n--------------------------------------------------";
	int i;
	cout << "\n nhan (1) de thoat \n nhan (2) de tiep tuc";
	cin >> i;
	switch (i)
	{
	case 1:
		system("cls");
		break;
	case 2:
		goto a;
		break;
	default:
		break;
	}
	

}




int main()
{
	Menu();

    return 0;
}

