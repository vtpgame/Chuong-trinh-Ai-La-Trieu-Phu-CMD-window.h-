/*
BAI TIEU LUAN MON GIAI THUAT VA CSDL
NHOM 4 
VO TUAN PHUONG - 17030061
BUI DUC THIEN - 17041331
HA THANH PHI - 17037141
MAI THI KIM QUE - 17025241 
------------------------------------------------------------------*/

#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include<windows.h>
#include<iostream>
#include <cwchar>
#include<fstream>

#define maxpt 10000 
#define maxpt_d 10000 

using namespace std;
int fflush(FILE *stream);

enum // Khai vao kieu liet ke cac hang so khong thay doi trong bai
{
	KEY_ESC = 27,
	ARROW_UP = 256 + 72,
	ARROW_DOWN = 256 + 80,
	ARROW_LEFT = 256 + 75,
	ARROW_RIGHT = 256 + 77
};
HANDLE hConsoleColor;
char op1[maxpt_d] = "BAT DAU CHOI";
char op2[maxpt_d] = "HUONG DAN";
char op3[maxpt_d] = "THONG TIN NHOM";
char op4[maxpt_d] = "THOAT";

char md1[maxpt_d] = "200.000 VND";
char md2[maxpt_d] = "400.000 VND";
char md3[maxpt_d] = "600.000 VND";
char md4[maxpt_d] = "1.000.000 VND";
char md5[maxpt_d] = "2.000.000 VND";
char md6[maxpt_d] = "3.000.000 VND";
char md7[maxpt_d] = "6.000.000 VND";
char md8[maxpt_d] = "10.000.000 VND";
char md9[maxpt_d] = "14.000.000 VND";
char md10[maxpt_d] = "22.000.000 VND";
char md11[maxpt_d] = "30.000.000 VND";
char md12[maxpt_d] = "40.000.000 VND";
char md13[maxpt_d] = "60.000.000 VND";
char md14[maxpt_d] = "85.000.000 VND";
char md15[maxpt_d] = "150.000.000 VND";

char huongDan[100000];
char chuoiRong[10000];
int tg1, tg2, tg3, tg4, a = 0, b = 0, c = 0, d = 0, cauHoi = 0, md = 1, pt, moc2 = 0, moc3 = 0;;


// Su dung thu vien Window.h de goi duoc toa do cua x , y tren console . Giup di chuyen chuyen den vi tri bat
//ki tren console
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
int get_code(void)
{
	int ch = getch();

	if (ch == 0 || ch == 224)
		ch = 256 + getch();

	return ch;
}
void phimBatKi ()
{
    int x = get_code();
		if (x == '\r' || x == ARROW_UP || x == ARROW_DOWN || x == ARROW_RIGHT || x == ARROW_LEFT)
		{
			system("cls");
		}
		else system("cls");
}

/*-------------------------------------------------------------------------------------------
* To chuc du lieu
- Su dung mang cau truc
- Nhap va ghi file tu txt
- Tim kim theo thu tu ghi file vao txt
*/
struct data {
	char cauHoi[maxpt];
	char a[maxpt];
	char b[maxpt];
	char c[maxpt];
	char d[maxpt];
	char dapAn[maxpt];
}; data dt[maxpt];

void inputData(int x) // Nhap file tu txt  - ( x - file muon nhap theo do kho ) 
{
	fstream f;
	int i = 0;

	switch (x) {
	case 1:
		f.open("QuestA.txt", ios::in);
		break;
	case 2:
		f.open("QuestB.txt", ios::in);
		break;
	case 3:
		f.open("QuestC.txt", ios::in);
		break;
	}
	while (!f.eof()) 
	{
		f.getline(dt[i].cauHoi, maxpt, '/');
		f.getline(dt[i].a, maxpt, '/');
		f.getline(dt[i].b, maxpt, '/');
		f.getline(dt[i].c, maxpt, '/');
		f.getline(dt[i].d, maxpt, '/');
		f.getline(dt[i].dapAn, maxpt, '/');
		f.getline(chuoiRong, maxpt, '/');
		i++;
	}
	pt = i;
	f.close();
}
void xoaPT(int &n, data a[], int vt)
{
	for (int i = vt; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void menu()
{
	gotoxy(26, 0);
	for (int i = 0; i < 25; i++)
	{
		printf("%c", 186);
		gotoxy(26, i);
	}
	gotoxy(0, 0);
	cout << "MENU" << endl;
	cout << "-------------------------" << endl;
	cout << "1. Them cau hoi moi" << endl;
	cout << "2. Tim kiem cau hoi" << endl;
	cout << "3. Tro ve menu" << endl;
	cout << "-------------------------" << endl;
	cout << "> Chon chuc nang : ";
}
int themCauHoiMoi()
{
	int c;
	std::ofstream f;
	char Q[maxpt], A[maxpt], B[maxpt], C[maxpt], D[maxpt], DA[maxpt];

	do {
		system("cls");
		menu();
		gotoxy(28, 1);
		cout << "Chon muc do cau hoi ban muon them : ";
		gotoxy(28, 2);
		cout << "1 . De ( cau 1 - 5 )";
		gotoxy(28, 3);
		cout << "2 . Trung binh ( cau 6 - 10 )";
		gotoxy(28, 4);
		cout << "3 . Kho ( cau 11 - 15 )";
		if (c > 3)
		{
			gotoxy(28, 5);
			cout << "> Muc do ban chon khong co trong Menu ! Moi nhap lai : ";
			cin >> c;
		}
		else {
			gotoxy(28, 5);
			cout << "> Chon : ";
			cin >> c;
		}
	} while (c > 3);

	gotoxy(28, 6);
	cout << "---------------------------------------------------------";
	switch (c) {
	case 1:
		f.open("QuestA.txt", std::ios::app);
		break;
	case 2:
		f.open("QuestB.txt", std::ios::app);
		break;
	case 3:
		f.open("QuestC.txt", std::ios::app);
		break;
	}
	gotoxy(28, 7);
	cout << "> Nhap cau hoi : ";
	fflush(stdin);
	gets(Q);
	gotoxy(28, 8);
	cout << "> Nhap dap an A : ";
	fflush(stdin);
	gets(A);
	gotoxy(28, 9);
	cout << "> Nhap dap an B : ";
	fflush(stdin);
	gets(B);
	gotoxy(28, 10);
	cout << "> Nhap dap an C : ";
	fflush(stdin);
	gets(C);
	gotoxy(28, 11);
	cout << "> Nhap dap an D : ";
	fflush(stdin);
	gets(D);
	gotoxy(28, 12);
	cout << "> Nhap dap an dung : ";
	fflush(stdin);
	gets(DA);
	f << "/" << Q << "/" << A << "/" << B << "/" << C << "/" << D << "/" << DA << "/" << "\n";
	f.close();
	gotoxy(28, 13);
	cout << "> Nhap thanh cong ! Nhan phim bat ki de tiep tuc .";
}
void timCauHoi()
{
	fstream f1, f2, f3;
	int c = 0;
	f1.open("QuestA.txt", ios::in);
	f2.open("QuestB.txt", ios::in);
	f3.open("QuestC.txt", ios::in);
	while (!f1.eof())
	{
		f1.getline(dt[c].cauHoi, maxpt, '/');
		f1.getline(dt[c].a, maxpt, '/');
		f1.getline(dt[c].b, maxpt, '/');
		f1.getline(dt[c].c, maxpt, '/');
		f1.getline(dt[c].d, maxpt, '/');
		f1.getline(dt[c].dapAn, maxpt, '/');
		f1.getline(chuoiRong, maxpt, '/');
		c++;
	}
	while (!f2.eof())
	{
		f2.getline(dt[c].cauHoi, maxpt, '/');
		f2.getline(dt[c].a, maxpt, '/');
		f2.getline(dt[c].b, maxpt, '/');
		f2.getline(dt[c].c, maxpt, '/');
		f2.getline(dt[c].d, maxpt, '/');
		f2.getline(dt[c].dapAn, maxpt, '/');
		f2.getline(chuoiRong, maxpt, '/');
		c++;
	}
	while (!f3.eof())
	{
		f3.getline(dt[c].cauHoi, maxpt, '/');
		f3.getline(dt[c].a, maxpt, '/');
		f3.getline(dt[c].b, maxpt, '/');
		f3.getline(dt[c].c, maxpt, '/');
		f3.getline(dt[c].d, maxpt, '/');
		f3.getline(dt[c].dapAn, maxpt, '/');
		f3.getline(chuoiRong, maxpt, '/');
		c++;
	}
	int tim;
	gotoxy(28, 1);
	cout << "- Nhap du lieu thanh cong !";
	gotoxy(28, 2);
	cout << "- Co tong cong " << c << " cau hoi duoc nhap .";
	gotoxy(28, 3);
	cout << "> Chon cau hoi ban muon tim ( nhap so bat dau tu 0 ) : ";
	cin >> tim;
	gotoxy(28, 4);
	cout << "-------------------------------------------------------";
	if (tim < c) {
		gotoxy(28, 5);
		cout << "Cau hoi : " << dt[tim].cauHoi;
		gotoxy(28, 6);
		cout << "A. " << dt[tim].a;
		gotoxy(28, 7);
		cout << "B. " << dt[tim].b;
		gotoxy(28, 8);
		cout << "C. " << dt[tim].c;
		gotoxy(28, 9);
		cout << "D. " << dt[tim].d;
		gotoxy(28, 10);
		cout << "> Tim thanh cong ! Nhan phim bat ki de tiep tuc .";
	}
	else {
		gotoxy(28, 5);
		cout << "> Khong tim thay";
	}
}
int toChucDL()
{
	int c;
	while (c != 3)
	{
		menu();
		cin >> c;
		switch (c) {
		case 1:
			themCauHoiMoi();
			break;
		case 2:
			timCauHoi();
			break;
		case 3:
			return 1;
			break;
		default:
			gotoxy(28, 1);
			cout << "> Nhap khong hop le ! Nhan phim bat ki de tiep tuc !";
			break;
		}
		int x = getch();
		if (x == 0 || x == 224)
			x = 256 + getch();
		if (x == '\r' || x == ARROW_UP || x == ARROW_DOWN || x == ARROW_RIGHT || x == ARROW_LEFT) {
			system("cls");
		}
		else system("cls");
	}
}

/*---------------------------------------------------------------------------------
* Tao khung
- Su dung gotoxy de den toa do can tao
- Su dung ki tu dat biet trong bang ma ascii : 205 , 186 de tao khung
*/
void taoKhung(int nx, int ny1, int ny2, int dx1, int dx2, int dy, int n, int d)
{
	gotoxy(nx, ny1);
	for (int i = 0; i < n; i++)
	{
		printf("%c", 205);
	}
	gotoxy(nx, ny2);
	for (int i = 0; i < n; i++)
	{
		printf("%c", 205);
	}
	gotoxy(dx1, dy);
	for (int i = dy + 1; i < (dy + 1) + d; i++)
	{
		printf("%c", 186);
		gotoxy(dx1, i);
	}
	gotoxy(dx2, dy);
	for (int i = dy + 1; i < (dy + 1) + d; i++)
	{
		printf("%c", 186);
		gotoxy(dx2, i);
	}
	gotoxy(dx1, ny1); printf("%c", 201); // cai moc cau ben trai tren
	gotoxy(dx1, ny2); printf("%c", 200); //Ben trai duoi
	gotoxy(dx2, ny1); printf("%c", 187); // cai moc cau ben phai ben tre^n
	gotoxy(dx2, ny2); printf("%c", 188); // cai moc cau ben phai ben duoi
}
// Mot so khung tao rieng vi co xu li nhan ki tu tu ban phim
void taoKhungDungSai(int x, int arr)
{
	switch (x)
	{
	case 1:
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 7);
		taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
		gotoxy(16, 20);
		cout << "Day la phuong an cuoi cung cua ban ? ";
		if (arr == 1) {
			SetConsoleTextAttribute(hConsoleColor, 143);
			gotoxy(23, 24);
			cout << "DUNG";
		}
		else {
			SetConsoleTextAttribute(hConsoleColor, 7);
			gotoxy(23, 24);
			cout << "DUNG";
		}
		if (arr == 2) {
			SetConsoleTextAttribute(hConsoleColor, 143);
			gotoxy(40, 24);
			cout << "KHONG";
		}
		else {
			SetConsoleTextAttribute(hConsoleColor, 7);
			gotoxy(40, 24);
			cout << "KHONG";
		}
		SetConsoleTextAttribute(hConsoleColor, 7);
		break;
	case 2:
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 10);
		taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
		gotoxy(29, 21);
		cout << "DAP AN DUNG";
		SetConsoleTextAttribute(hConsoleColor, 39);
		gotoxy(26, 24);
		cout << "CAU HOI TIEP THEO";
		SetConsoleTextAttribute(hConsoleColor, 7);
		break;
	case 3:
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 4);
		taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
		gotoxy(19, 20);
		cout << "DAP AN SAI ! BAN DA DUNG CUOC CHOI";
		gotoxy(22, 21);
		cout << "BAN NHAN DUOC SO TIEN LA : ";
		gotoxy(30, 22);
		if (md <= 5) cout << "0 VND";
		else if (md > 5 && md <= 10) cout << md5;
		else if (md > 10) cout << md10;
		if (arr == 1) {
			SetConsoleTextAttribute(hConsoleColor, 196);
			gotoxy(23, 24);
			cout << "CHOI LAI";
		}
		else {
			SetConsoleTextAttribute(hConsoleColor, 4);
			gotoxy(23, 24);
			cout << "CHOI LAI ";
		}
		if (arr == 2) {
			SetConsoleTextAttribute(hConsoleColor, 196);
			gotoxy(40, 24);
			cout << "THOAT";
		}
		else {
			SetConsoleTextAttribute(hConsoleColor, 4);
			gotoxy(40, 24);
			cout << "THOAT";

		}
		SetConsoleTextAttribute(hConsoleColor, 7);
		break;
	}
}
void taoKhungTg2(int arr)
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 7);
	taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
	gotoxy(17, 19);
	cout << "Ban muon noi day ket noi den ai ? ";
	if (arr == 1) {
		SetConsoleTextAttribute(hConsoleColor, 143);
		gotoxy(18, 20);
		cout << "Ba , me";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 7);
		gotoxy(18, 20);
		cout << "Ba , me";
	}
	if (arr == 2) {
		SetConsoleTextAttribute(hConsoleColor, 143);
		gotoxy(18, 21);
		cout << "Vo/Chong";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 7);
		gotoxy(18, 21);
		cout << "Vo/Chong";
	}
	if (arr == 3) {
		SetConsoleTextAttribute(hConsoleColor, 143);
		gotoxy(18, 22);
		cout << "Ban gai/Ban trai";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 7);
		gotoxy(18, 22);
		cout << "Ban gai/Ban trai";
	}
	if (arr == 4) {
		SetConsoleTextAttribute(hConsoleColor, 143);
		gotoxy(18, 23);
		cout << "Ban than ";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 7);
		gotoxy(18, 23);
		cout << "Ban than";
	}
	SetConsoleTextAttribute(hConsoleColor, 7);
}
void taoKhungTg3(char dapan[], int x)
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 10);
	taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
	gotoxy(18, 19);
	cout << "Dap an khan gia dua ra la : ";
	gotoxy(18, 20);
	cout << "1 ." << dapan;
	gotoxy(18, 21);
	cout << "2 ." << dapan;
	gotoxy(18, 22);
	printf("3 .%c", x - 32);
	gotoxy(18, 23);
	cout << "4 ." << dapan << endl;
	SetConsoleTextAttribute(hConsoleColor, 39);
	gotoxy(28, 24);
	cout << "CHAP NHAN";
	SetConsoleTextAttribute(hConsoleColor, 7);
	phimBatKi() ;
}
void taoKhungTg4(int a, int b, int c, int d, char x[])
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 10);
	taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
	gotoxy(18, 19);
	cout << "Dap an to tu van dua ra la : ";

	if (strcmpi(x, "A") == 0)
	{
		gotoxy(18, 20);
		cout << "A ." << a << "%";
		gotoxy(18, 21);
		cout << "B ." << b << "%";
		gotoxy(18, 22);
		cout << "C ." << c << "%";
		gotoxy(18, 23);
		cout << "D ." << d << "%";
		SetConsoleTextAttribute(hConsoleColor, 39);
		gotoxy(28, 24);
		cout << "CHAP NHAN";
		SetConsoleTextAttribute(hConsoleColor, 7);
		phimBatKi() ;
	}
	else if (strcmpi(x, "B") == 0)
	{
		gotoxy(18, 20);
		cout << "A ." << b << "%";
		gotoxy(18, 21);
		cout << "B ." << a << "%";
		gotoxy(18, 22);
		cout << "C ." << c << "%";
		gotoxy(18, 23);
		cout << "D ." << d << "%";
		SetConsoleTextAttribute(hConsoleColor, 39);
		gotoxy(28, 24);
		cout << "CHAP NHAN";
		SetConsoleTextAttribute(hConsoleColor, 7);
		phimBatKi() ;
	}
	else if (strcmpi(x, "C") == 0)
	{
		gotoxy(18, 20);
		cout << "A ." << c << "%";
		gotoxy(18, 21);
		cout << "B ." << b << "%";
		gotoxy(18, 22);
		cout << "C ." << a << "%";
		gotoxy(18, 23);
		cout << "D ." << d << "%";
		SetConsoleTextAttribute(hConsoleColor, 39);
		gotoxy(28, 24);
		cout << "CHAP NHAN";
		SetConsoleTextAttribute(hConsoleColor, 7);
		phimBatKi() ;
	}
	else if (strcmpi(x, "D") == 0)
	{
		gotoxy(18, 20);
		cout << "A ." << d << "%";
		gotoxy(18, 21);
		cout << "B ." << b << "%";
		gotoxy(18, 22);
		cout << "C ." << c << "%";
		gotoxy(18, 23);
		cout << "D ." << a << "%";
		SetConsoleTextAttribute(hConsoleColor, 39);
		gotoxy(28, 24);
		cout << "CHAP NHAN";
		SetConsoleTextAttribute(hConsoleColor, 7);
		phimBatKi() ;
	}
}
void taoKhungDungCuocChoi(int arr)
{
	if (md > 5)
	{
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 4);
		taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
		gotoxy(19, 19);
		cout << "BAN MUON DUNG CUOC CHOI ?";
		gotoxy(19, 20);
		cout << "BAN DA VUOT QUA MOC CAU HOI SO " << md - 1;
		gotoxy(19, 21);
		cout << "BAN SE NHAN DUOC SO TIEN LA : ";
		gotoxy(27, 22);
		switch (md)
		{
		case 6: cout << md5; break;
		case 7: cout << md6; break;
		case 8: cout << md7; break;
		case 9: cout << md8; break;
		case 10: cout << md9; break;
		case 11: cout << md10; break;
		case 12: cout << md11; break;
		case 13: cout << md12; break;
		case 14: cout << md13; break;
		case 15: cout << md14; break;
		default: break;

		}
		if (arr == 1) {
			SetConsoleTextAttribute(hConsoleColor, 196);
			gotoxy(23, 24);
			cout << "CHOI TIEP";
		}
		else {
			SetConsoleTextAttribute(hConsoleColor, 4);
			gotoxy(23, 24);
			cout << "CHOI TIEP ";
		}
		if (arr == 2) {
			SetConsoleTextAttribute(hConsoleColor, 196);
			gotoxy(40, 24);
			cout << "DUNG";
		}
		else {
			SetConsoleTextAttribute(hConsoleColor, 4);
			gotoxy(40, 24);
			cout << "DUNG";

		}
	}
	else {
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 4);
		taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
		gotoxy(19, 20);
		cout << "BAN CAN VUOT QUA MOC CAU HOI SO 5";
		gotoxy(19, 21);
		cout << "DE CO THEM QUYEN DUNG CUOC CHOI !!";
		SetConsoleTextAttribute(hConsoleColor, 196);
		gotoxy(29, 24);
		cout << "CHOI TIEP";

	}
	SetConsoleTextAttribute(hConsoleColor, 7);
}
void taoKhungChienThang(int arr)
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 10);
	taoKhung(35, 6, 19, 34, 80, 6, 45, 13);
	gotoxy(51, 7); cout << "CHIEN THANG";
	gotoxy(36, 8); cout << "------------------------------------------";
	gotoxy(36, 9); cout << "CHUC MUNG BAN DA TRO THANH TRIEU PHU !!";
	gotoxy(36, 11); cout << "BAN DA HOAN THANH 15 MOC CAU HOI";
	gotoxy(36, 13); cout << "BAN SE NHAN MUC THUONG CAO NHAT LA : ";
	gotoxy(47, 15); cout << "==150.000.000 VND==";
	if (arr == 1)
	{
		SetConsoleTextAttribute(hConsoleColor, 47);
		gotoxy(40, 19); cout << "TRO CHOI MOI";
		SetConsoleTextAttribute(hConsoleColor, 10);
		gotoxy(60, 19); cout << "TRO LAI MENU";
		SetConsoleTextAttribute(hConsoleColor, 7);
	}
	else if (arr == 2)
	{
		SetConsoleTextAttribute(hConsoleColor, 10);
		gotoxy(40, 19); cout << "TRO CHOI MOI";
		SetConsoleTextAttribute(hConsoleColor, 47);
		gotoxy(60, 19); cout << "TRO LAI MENU";
		SetConsoleTextAttribute(hConsoleColor, 7);
	}

}
/*-----------------------------------------------------------------
- Xu li bat ki tu tu ban phim de doi mau chu
*/
void menuColor(int arrow)
{
	SetConsoleTextAttribute(hConsoleColor, 15);
	gotoxy(34, 3); cout << "BAI TAP LON MON CAU TRUC DU LIEU VA GIAI THUAT";
	gotoxy(43, 5); cout << "DE TAI 2 : AI LA TRIEU PHU";
	gotoxy(44, 7); cout << "GIAO VIEN : DANG THI PHUC";
	gotoxy(53, 9); cout << "NHOM 4";
	gotoxy(34, 11); cout << "----------------------------------------------";
	taoKhung(48, 13, 25, 47, 66, 14, 18, 11);

	if (arrow == 1) {
		SetConsoleTextAttribute(hConsoleColor, 112);
		gotoxy(50, 15); cout << op1 << endl;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(50, 15); cout << op1 << endl;
	}
	if (arrow == 2) {
		SetConsoleTextAttribute(hConsoleColor, 112);
		gotoxy(50, 17); cout << op2 << endl;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(50, 17); cout << op2 << endl;
	}
	if (arrow == 3) {
		SetConsoleTextAttribute(hConsoleColor, 112);
		gotoxy(50, 19); cout << op3 << endl;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(50, 19); cout << op3 << endl;
	}
	if (arrow == 4) {
		SetConsoleTextAttribute(hConsoleColor, 112);
		gotoxy(50, 21); cout << "TO CHUC DU LIEU" << endl;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(50, 21); cout << "TO CHUC DU LIEU" << endl;
	}
	if (arrow == 5) {
		SetConsoleTextAttribute(hConsoleColor, 112);
		gotoxy(50, 23); cout << op4 << endl;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(50, 23); cout << op4 << endl;
	}
	SetConsoleTextAttribute(hConsoleColor, 7);
}
void thongTinNhom()
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsoleColor, 12);
	taoKhung(35, 5, 19, 34, 80, 6, 45, 13);
	SetConsoleTextAttribute(hConsoleColor, 7);
	gotoxy(38, 7); cout << "THANH VIEN : ";
	SetConsoleTextAttribute(hConsoleColor, 1);
	gotoxy(38, 9); cout << "HA THANH PHI - 17037141";
	SetConsoleTextAttribute(hConsoleColor, 2);
	gotoxy(38, 11); cout << "VO TUAN PHUONG - 17030061";
	SetConsoleTextAttribute(hConsoleColor, 5);
	gotoxy(38, 13); cout << "MAI THI KIM QUE - 17025241";
	SetConsoleTextAttribute(hConsoleColor, 14);
	gotoxy(38, 15); cout << "BUI DUC THIEN - 17041331";
	SetConsoleTextAttribute(hConsoleColor, 207);
	gotoxy(55, 19); cout << "TRO LAI";
	SetConsoleTextAttribute(hConsoleColor, 7);
}
void huongDanH()
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);
	gotoxy(0, 6);
	for (int i = 0; i < 120; i++)
	{
		printf("%c", 205);
	}
	gotoxy(0, 17);
	for (int i = 0; i < 120; i++)
	{
		printf("%c", 205);
	}
	SetConsoleTextAttribute(hConsoleColor, 232);
	gotoxy(55, 17); cout << "TRO LAI";
}
int xuliKhungDungSai(int x)
{
	int action, arrow = 1;
	taoKhungDungSai(x, arrow);
	while ((action = get_code()) != KEY_ESC && arrow != -1)
	{
		switch (action)
		{
		case ARROW_RIGHT:
			if (arrow == 1)
				arrow = 2;
			else if (arrow == 2)
				arrow = 1;
			taoKhungDungSai(x, arrow);
			break;
		case ARROW_LEFT:
			if (arrow == 1)
				arrow = 2;
			else if (arrow == 2)
				arrow = 1;
			taoKhungDungSai(x, arrow);
			break;
		case '\r':
			if (arrow == 1)
			{
				return 1;
			}
			else if (arrow == 2)
			{
				return -1;
			}
			get_code();
			break;
		default:
			break;
		}
	}
}
void xuLiGameplay(int arr, int x)
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);
	taoKhung(1, 0, 6, 0, 71, 1, 70, 5);
	SetConsoleTextAttribute(hConsoleColor, 6);
	taoKhung(1, 7, 15, 0, 71, 8, 70, 7);
	SetConsoleTextAttribute(hConsoleColor, 3);
	taoKhung(76, 0, 5, 75, 104, 1, 28, 5);
	SetConsoleTextAttribute(hConsoleColor, 3);
	taoKhung(76, 6, 22, 75, 104, 7, 28, 16);
	SetConsoleTextAttribute(hConsoleColor, 14);
	gotoxy(3, 1); cout << dt[x].cauHoi;


	if (arr == 1) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(2, 8); cout << "A . " << dt[x].a;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 6);
		gotoxy(2, 8); cout << "A . " << dt[x].a;
	}
	if (arr == 2) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(2, 10); cout << "B . " << dt[x].b;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 6);
		gotoxy(2, 10); cout << "B . " << dt[x].b;
	}
	if (arr == 3) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(2, 12); cout << "C . " << dt[x].c;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 6);
		gotoxy(2, 12); cout << "C . " << dt[x].c;
	}
	if (arr == 4) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(2, 14); cout << "D . " << dt[x].d;
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 6);
		gotoxy(2, 14); cout << "D . " << dt[x].d;
	}
	if (arr == 5) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(77, 1); cout << "1 . 50/50";
	}
	else if (tg1 == -1) {
		SetConsoleTextAttribute(hConsoleColor, 8);
		gotoxy(77, 1); cout << "1 . 50/50";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(77, 1); cout << "1 . 50/50";
	}

	if (arr == 6) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(77, 2); cout << "2 . Goi dien cho nguoi than";
	}
	else if (tg2 == -1) {
		SetConsoleTextAttribute(hConsoleColor, 8);
		gotoxy(77, 2); cout << "2 . Goi dien cho nguoi than";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(77, 2); cout << "2 . Goi dien cho nguoi than";
	}

	if (arr == 7) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(77, 3); cout << "3 . Hoi to tu van";
	}
	else if (tg3 == -1) {
		SetConsoleTextAttribute(hConsoleColor, 8);
		gotoxy(77, 3); cout << "3 . Hoi to tu van";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(77, 3); cout << "3 . Hoi to tu van";
	}

	if (arr == 8) {
		SetConsoleTextAttribute(hConsoleColor, 181);
		gotoxy(77, 4); cout << "4 . Xin y kien khan gia";
	}
	else if (tg4 == -1) {
		SetConsoleTextAttribute(hConsoleColor, 8);
		gotoxy(77, 4); cout << "4 . Xin y kien khan gia";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoxy(77, 4); cout << "4 . Xin y kien khan gia";
	}
	if (arr == 9) {
		SetConsoleTextAttribute(hConsoleColor, 71);
		gotoxy(2, 17); cout << "- > DUNG CUOC CHOI !";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 4);
		gotoxy(2, 17); cout << "- > DUNG CUOC CHOI !";
	}
}
void xuLiMucDiem(int md)
{
	if (md == 1) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 7); cout << "1 / 200.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 7); cout << "1 / 200.000";
	}
	if (md == 2) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 8); cout << "2 / 400.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 8); cout << "2 / 400.000";
	}
	if (md == 3) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 9); cout << "3 / 600.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 9); cout << "3 / 600.000";
	}
	if (md == 4) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 10); cout << "4 / 1.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 10); cout << "4 / 1.000.000";
	}
	if (md == 5) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 11); cout << "5 / 2.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 1);
		gotoxy(77, 11); cout << "5 / 2.000.000";
	}
	if (md == 6) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 12); cout << "6 / 3.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 12); cout << "6 / 3.000.000";
	}
	if (md == 7) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 13); cout << "7 / 6.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 13); cout << "7 / 6.000.000";
	}
	if (md == 8) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 14); cout << "8 / 10.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 14); cout << "8 / 10.000.000";
	}
	if (md == 9) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 15); cout << "9 / 14.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 15); cout << "9 / 14.000.000";
	}
	if (md == 10) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 16); cout << "10 / 22.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 1);
		gotoxy(77, 16); cout << "10 / 22.000.000";
	}
	if (md == 11) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 17); cout << "11 / 30.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 17); cout << "11 / 30.000.000";
	}
	if (md == 12) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 18); cout << "12 / 40.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 18); cout << "12 / 40.000.000";
	}
	if (md == 13) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 19); cout << "13 / 60.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 19); cout << "13 / 60.000.000";
	}
	if (md == 14) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 20); cout << "14 / 85.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 3);
		gotoxy(77, 20); cout << "14 / 85.000.000";
	}
	if (md == 15) {
		SetConsoleTextAttribute(hConsoleColor, 25);
		gotoxy(77, 21); cout << "15 / 150.000.000";
	}
	else {
		SetConsoleTextAttribute(hConsoleColor, 1);
		gotoxy(77, 21); cout << "15 / 150.000.000";
	}
}
int xuliKhungTg2()
{
	int action, arrow = 1;
	taoKhungTg2(arrow);
	while ((action = get_code()) != KEY_ESC && arrow != -1)
	{
		switch (action)
		{
		case ARROW_DOWN:
			if (arrow == 4)
				arrow = 1;
			else arrow++;
			taoKhungTg2(arrow);
			break;
		case ARROW_UP:
			if (arrow == 1)
				arrow = 4;
			else arrow--;
			taoKhungTg2(arrow);
			break;
		case '\r':
			if (arrow != -1)
			{
				system("cls");
				xuLiGameplay(arrow, cauHoi);
				xuLiMucDiem(md);
				hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsoleColor, 10);
				taoKhung(15, 18, 24, 14, 55, 19, 40, 5);
				if (arrow == 1) {
					gotoxy(24, 21);
					cout << "DAP AN CUA BA ME LA : " << dt[cauHoi].dapAn;
				}
				else if (arrow == 2) {
					gotoxy(24, 21);
					cout << "DAP AN CUA EM LA : " << dt[cauHoi].dapAn;
				}
				if (arrow == 3) {
					gotoxy(24, 21);
					cout << "DAP AN CUA EM LA : " << dt[cauHoi].dapAn;
				}
				if (arrow == 4) {
					gotoxy(24, 21);
					cout << "DAP AN CUA TO LA : " << dt[cauHoi].dapAn;
				}
				SetConsoleTextAttribute(hConsoleColor, 39);
				gotoxy(30, 24);
				cout << "CHAP NHAN";
				SetConsoleTextAttribute(hConsoleColor, 7);
				arrow = 5;
			}
			phimBatKi() ;
			return 1 ;
			break;
		default:
			break;
		}
	}
}
int xuliDungCuocChoi()
{
	if (md > 5)
	{
		int action, arrow = 1;
		taoKhungDungCuocChoi(arrow);
		while ((action = get_code()) != KEY_ESC && arrow != -1)
		{
			switch (action)
			{
			case ARROW_RIGHT:
				if (arrow == 1)
					arrow = 2;
				else if (arrow == 2)
					arrow = 1;
				taoKhungDungCuocChoi(arrow);
				break;
			case ARROW_LEFT:
				if (arrow == 1)
					arrow = 2;
				else if (arrow == 2)
					arrow = 1;
				taoKhungDungCuocChoi(arrow);
				break;
			case '\r':
				if (arrow == 1)
				{
					return 1;
				}
				else if (arrow == 2)
				{
					return -1;
				}
				get_code();
				break;
			default:
				break;
			}
		}
	}
	else {
		taoKhungDungCuocChoi(1);
		phimBatKi();
		return 1 ;
	}
}
int xuliKhungChienThang()
{

	int action, arrow = 1;
	taoKhungChienThang(arrow);
	while ((action = get_code()) != KEY_ESC && arrow != -1)
	{
		switch (action)
		{
		case ARROW_RIGHT:
			if (arrow == 1)
				arrow = 2;
			else if (arrow == 2)
				arrow = 1;
			taoKhungChienThang(arrow);
			break;
		case ARROW_LEFT:
			if (arrow == 1)
				arrow = 2;
			else if (arrow == 2)
				arrow = 1;
			taoKhungChienThang(arrow);
			break;
		case '\r':
			if (arrow == 1)
			{
				return 1;
			}
			else if (arrow == 2)
			{
				return -1;
			}
			get_code();
			break;
		default:
			break;
		}
	}
}

// Xu li gameplay trong tro choi 
void ranDom(int &cauHoi, int x, int y)
{
	srand(time(NULL));
	cauHoi = rand() % x + y;
}
void reset()
{
	md = 1;
	tg1 = tg2 = tg3 = tg4 = 1;
	moc2 = moc3 = 0;
}
void update(int arrow)
{
	system("cls");
	xuLiGameplay(arrow, cauHoi);
	xuLiMucDiem(md);
	xuliKhungDungSai(2);
	md++;
	xoaPT(pt, dt, cauHoi);
	cauHoi = rand() % pt + 0;
	system("cls");
}
int dapAnSai(int arrow)
{
	system("cls");
	xuLiGameplay(arrow, cauHoi);
	xuLiMucDiem(md);
	int kq = xuliKhungDungSai(3);
	if (kq == 1) {
		reset();
		inputData(1);
		cauHoi = rand() % pt + 0;
		system("cls");
		return 1;
	}
	else {
		reset();
		return -1;
	}
}
int gamePlay()
{
	int action, arrow = 1;
	inputData(1);
	ranDom(cauHoi, pt, 0);
	xuLiGameplay(arrow, cauHoi);
	xuLiMucDiem(md);
	while ((action = get_code()) != KEY_ESC && arrow != -1)
	{
		switch (action)
		{
		case ARROW_UP:
			if (arrow == 1)
				arrow = 9;
			else if (arrow == 9)
				arrow = 4;
			else if (arrow == 5)
				arrow = 8;
			else arrow -= 1;
			xuLiGameplay(arrow, cauHoi);
			break;
		case ARROW_DOWN:
			if (arrow == 4)
				arrow = 9;
			else if (arrow == 9)
				arrow = 1;
			else if (arrow == 8)
				arrow = 5;
			else arrow += 1;
			xuLiGameplay(arrow, cauHoi);
			break;
		case ARROW_RIGHT:
			if (arrow == 1 || arrow == 2 || arrow == 3 || arrow == 4)
				arrow = 5;
			else if (arrow == 5 || arrow == 6 || arrow == 7 || arrow == 8) arrow = 1;
			xuLiGameplay(arrow, cauHoi);
			break;
		case ARROW_LEFT:
			if (arrow == 1 || arrow == 2 || arrow == 3 || arrow == 4)
				arrow = 5;
			else if (arrow == 5 || arrow == 6 || arrow == 7 || arrow == 8); arrow = 1;
			xuLiGameplay(arrow, cauHoi);
			break;
		case '\r':
			srand(time(NULL));
			if (arrow == 1 && strcmpi(dt[cauHoi].a, "[X]") != 0)
			{
				int kq1 = xuliKhungDungSai(1);
				if (kq1 == 1)
				{
					if (strcmpi(dt[cauHoi].dapAn, "A") == 0) {
						update(arrow);
						break;
					}
					else {
						int kq2 = dapAnSai(arrow);
						if (kq2 != -1) break;
						else return -1;
					}
				}
				else {
					system("cls");
					break;
				}
			}
			else if (arrow == 2 && strcmpi(dt[cauHoi].b, "[X]") != 0)
			{
				int kq1 = xuliKhungDungSai(1);
				if (kq1 == 1)
				{
					if (strcmpi(dt[cauHoi].dapAn, "B") == 0) {
						update(arrow);
						break;
					}
					else {
						int kq2 = dapAnSai(arrow);
						if (kq2 != -1) break;
						else return -1;
					}
				}
				else {
					system("cls");
					break;
				}
			}
			else if (arrow == 3 && strcmpi(dt[cauHoi].c, "[X]") != 0)
			{
				int kq1 = xuliKhungDungSai(1);
				if (kq1 == 1)
				{
					if (strcmpi(dt[cauHoi].dapAn, "C") == 0) {
						update(arrow);
						break;
					}
					else {
						int kq2 = dapAnSai(arrow);
						if (kq2 != -1) break;
						else return -1;
					}
				}
				else {
					system("cls");
					break;
				}
			}
			else if (arrow == 4 && strcmpi(dt[cauHoi].d, "[X]") != 0) {
				int kq1 = xuliKhungDungSai(1);
				if (kq1 == 1)
				{
					if (strcmpi(dt[cauHoi].dapAn, "D") == 0) {
						update(arrow);
						break;
					}
					else {
						int kq2 = dapAnSai(arrow);
						if (kq2 != -1) break;
						else return -1;
					}
				}
				else {
					system("cls");
					break;
				}
			}
			else if (arrow == 5) {
				if (tg1 != -1)
				{
					if (strcmpi(dt[cauHoi].dapAn, "A") == 0)
					{
						srand(time(NULL));
						char x = 98 + rand() % 3;
						if (x == 'b') {
							strcpy(dt[cauHoi].c, "[X]");
							strcpy(dt[cauHoi].d, "[X]");
						}
						else if (x == 'c') {
							strcpy(dt[cauHoi].b, "[X]");
							strcpy(dt[cauHoi].d, "[X]");
						}
						else if (x == 'd') {
							strcpy(dt[cauHoi].b, "[X]");
							strcpy(dt[cauHoi].c, "[X]");
						}
						system("cls");
						xuLiGameplay(arrow, cauHoi);
						xuLiMucDiem(md);
						tg1 = -1;
						break;
					}
					else if (strcmpi(dt[cauHoi].dapAn, "B") == 0)
					{
						srand(time(NULL));
						char x = 99 + rand() % 2;
						if (x == 'c') {
							strcpy(dt[cauHoi].a, "[X]");
							strcpy(dt[cauHoi].d, "[X]");
						}
						else if (x == 'd') {
							strcpy(dt[cauHoi].a, "[X]");
							strcpy(dt[cauHoi].c, "[X]");
						}
						system("cls");
						xuLiGameplay(arrow, cauHoi);
						xuLiMucDiem(md);
						tg1 = -1;
						break;
					}
					else if (strcmpi(dt[cauHoi].dapAn, "C") == 0)
					{
						srand(time(NULL));
						char x = 97 + rand() % 2;
						if (x == 'a') {
							strcpy(dt[cauHoi].b, "[X]");
							strcpy(dt[cauHoi].d, "[X]");
						}
						else if (x == 'b') {
							strcpy(dt[cauHoi].a, "[X]");
							strcpy(dt[cauHoi].d, "[X]");
						}
						system("cls");
						xuLiGameplay(arrow, cauHoi);
						xuLiMucDiem(md);
						tg1 = -1;
						break;
					}
					if (strcmpi(dt[cauHoi].dapAn, "D") == 0)
					{
						srand(time(NULL));
						char x = 97 + rand() % 3;
						if (x == 'a') {
							strcpy(dt[cauHoi].b, "[X]");
							strcpy(dt[cauHoi].c, "[X]");
						}
						else if (x == 'b') {
							strcpy(dt[cauHoi].a, "[X]");
							strcpy(dt[cauHoi].c, "[X]");
						}
						else if (x == 'c') {
							strcpy(dt[cauHoi].a, "[X]");
							strcpy(dt[cauHoi].b, "[X]");
						}
						system("cls");
						xuLiGameplay(arrow, cauHoi);
						xuLiMucDiem(md);
						tg1 = -1;
						break;
					}
				}
				break;
			}
			else if (arrow == 6)
			{
				if (tg2 != -1)
					xuliKhungTg2();
				tg2 = -1;
				break;
			}
			else if (arrow == 7)
			{
				if (tg3 != -1)
				{
					if (strcmpi(dt[cauHoi].dapAn, "A") == 0)
					{
						srand(time(NULL));
						int x = 98 + rand() % 3;
						taoKhungTg3("A", x);
						tg3 = -1;
						break;
					}
					else if (strcmpi(dt[cauHoi].dapAn, "B") == 0)
					{
						srand(time(NULL));
						char x = 99 + rand() % 2;
						taoKhungTg3("B", x);
						tg3 = -1;
						break;
					}
					else if (strcmpi(dt[cauHoi].dapAn, "C") == 0)
					{
						srand(time(NULL));
						char x = 97 + rand() % 2;
						taoKhungTg3("C", x);
						tg3 = -1;
						break;
					}
					if (strcmpi(dt[cauHoi].dapAn, "D") == 0)
					{
						srand(time(NULL));
						char x = 97 + rand() % 3;
						taoKhungTg3("D", x);
						tg3 = -1;
						break;
					}
				}
				break;
			}
			else if (arrow == 8)
			{
				if (tg4 != -1)
				{
					if (strcmpi(dt[cauHoi].dapAn, "A") == 0)
					{
						srand(time(NULL));
						int a = 50 + rand() % 21; //(x + y +1) = 21 50 - 70 
						int b = 5 + rand() % 6;
						int c = 10 + rand() % 11;
						int d = 100 - (a + b + c);
						taoKhungTg4(a, b, c, d, "A");
						tg4 = -1;
						break;
					}
					else if (strcmpi(dt[cauHoi].dapAn, "B") == 0)
					{
						srand(time(NULL));
						int a = 50 + rand() % 21;
						int b = 5 + rand() % 6;
						int c = 10 + rand() % 11;
						int d = 100 - (a + b + c);
						taoKhungTg4(a, b, c, d, "B");
						tg4 = -1;
						break;
					}
					else if (strcmpi(dt[cauHoi].dapAn, "C") == 0)
					{
						srand(time(NULL));
						int a = 50 + rand() % 21;
						int b = 5 + rand() % 6;
						int c = 10 + rand() % 11;
						int d = 100 - (a + b + c);
						taoKhungTg4(a, b, c, d, "C");
						tg4 = -1;
						break;
					}
					if (strcmpi(dt[cauHoi].dapAn, "D") == 0)
					{
						srand(time(NULL));
						int a = 50 + rand() % 21;
						int b = 5 + rand() % 6;
						int c = 10 + rand() % 11;
						int d = 100 - (a + b + c);
						taoKhungTg4(a, b, c, d, "D");
						tg4 = -1;
						break;
					}
				}
				break;
			}
			if (arrow == 9)
			{
				int kq = xuliDungCuocChoi();
				if (kq == 1) {
					system("cls");
					break;
				}
				else {
					reset() ;
					return -1;
					break;
				}
			}
			break;
		default:
			break;
		}
		if (md > 5 && md <= 10 && moc2 != -1) {
			inputData(2);
			moc2 = -1;
		}
		if (md > 10 && moc3 != -1) {
			inputData(3);
			moc3 = -1;
		}
		if (md > 15) {
			system("cls");
			int kq = xuliKhungChienThang();
			reset();
			if (kq == -1)
			{
				return -1;
			}
			else {
				inputData(1);
				system("cls");
				xuLiGameplay(arrow, cauHoi);
				xuLiMucDiem(md);
			}
		}
		if (arrow != -1)
		{
			xuLiGameplay(arrow, cauHoi);
			xuLiMucDiem(md);
		}
		else md = 0;
	}
}
int gamePlayGuide()
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 1);
	taoKhung(35, 5, 19, 34, 80, 6, 45, 13);
	SetConsoleTextAttribute(hConsoleColor, 1);
	gotoxy(40, 7); cout << "CHAO MUNG BAN DEN VOI AI LA TRIEU PHU";
	gotoxy(36, 8); cout << "-------------------------------------------";
	SetConsoleTextAttribute(hConsoleColor, 7);
	gotoxy(36, 9); cout << "CACH CHOI :";
	gotoxy(36, 11); cout << "SU DUNG CAC PHIM LEN,XUONG,TRAI,PHAI,ENTER";
	gotoxy(36, 13); cout << "DE DIEU KHIEN CHON DAP AN";
	SetConsoleTextAttribute(hConsoleColor, 12);
	gotoxy(36, 15); cout << "BAN DA SAN SANG DE BUOC VAO CHUONG TRINH ?";
	int action, arr = 1;
	SetConsoleTextAttribute(hConsoleColor, 207);
	gotoxy(45, 19); cout << "SAN SANG";
	SetConsoleTextAttribute(hConsoleColor, 7);
	gotoxy(62, 19); cout << "TRO LAI";
	while ((action = get_code()) != KEY_ESC && arr != -1)
	{
		switch (action)
		{
		case ARROW_LEFT:
			if (arr == 1)
				arr = 2;
			else arr = 1;
			if (arr == 1)
			{
				SetConsoleTextAttribute(hConsoleColor, 207);
				gotoxy(45, 19); cout << "SAN SANG";
				SetConsoleTextAttribute(hConsoleColor, 7);
				gotoxy(62, 19); cout << "TRO LAI";
				SetConsoleTextAttribute(hConsoleColor, 7);
			}
			else if (arr == 2)
			{
				SetConsoleTextAttribute(hConsoleColor, 7);
				gotoxy(45, 19); cout << "SAN SANG";
				SetConsoleTextAttribute(hConsoleColor, 207);
				gotoxy(62, 19); cout << "TRO LAI";
				SetConsoleTextAttribute(hConsoleColor, 7);
			}
			break;
		case ARROW_RIGHT:
			if (arr == 1)
				arr = 2;
			else arr = 1;
			if (arr == 1)
			{
				SetConsoleTextAttribute(hConsoleColor, 207);
				gotoxy(45, 19); cout << "SAN SANG";
				SetConsoleTextAttribute(hConsoleColor, 7);
				gotoxy(62, 19); cout << "TRO LAI";
				SetConsoleTextAttribute(hConsoleColor, 7);
			}
			else if (arr == 2)
			{
				SetConsoleTextAttribute(hConsoleColor, 7);
				gotoxy(45, 19); cout << "SAN SANG";
				SetConsoleTextAttribute(hConsoleColor, 207);
				gotoxy(62, 19); cout << "TRO LAI";
				SetConsoleTextAttribute(hConsoleColor, 7);
			}
			break;
		case '\r':
			if (arr == 1)
			{
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 14);
				taoKhung(1, 0, 6, 0, 71, 1, 70, 5);
				SetConsoleTextAttribute(hConsoleColor, 6);
				taoKhung(1, 7, 15, 0, 71, 8, 70, 7);
				SetConsoleTextAttribute(hConsoleColor, 3);
				taoKhung(76, 0, 5, 75, 104, 1, 28, 5);
				SetConsoleTextAttribute(hConsoleColor, 3);
				taoKhung(76, 6, 22, 75, 104, 7, 28, 16);
				int kq = gamePlay();
				if (kq == -1) return -1;
			}
			else if (arr == 2)
			{
				system("cls");
				return -1;
			}
			break;
		default:
			break;
		}
	}

}
int main(void)
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int action;
	int arrow = 1;
	menuColor(arrow);
	while ((action = get_code()) != KEY_ESC || arrow != -1)
	{
		switch (action)
		{
		case ARROW_UP:
			if (arrow == 1)
				arrow = 5;
			else arrow -= 1;
			break;
		case ARROW_DOWN:
			if (arrow == 5)
				arrow = 1;
			else arrow += 1;
			break;
		case '\r':
			if (arrow == 1)
			{
				system("cls");
				int i = gamePlayGuide();
				if (i == -1){
				system("cls");
				break ;
				} 
			}
			else if (arrow == 2)
			{
				fstream f;
				f.open("HuongDan.txt", ios::in);
				f.getline(huongDan, 100000, '=');
				f.close();
				system("cls");
				huongDanH();
				gotoxy(0, 7);
				SetConsoleTextAttribute(hConsoleColor, 6);
				cout << huongDan;
				phimBatKi() ;
				break ;
			}
			else if (arrow == 3)
			{
				thongTinNhom();
				phimBatKi() ;
				break ;
			}
			else if (arrow == 4)
			{
				system("cls");
				int rs = toChucDL();
				if (rs == 1) {
				system("cls");
				break;
				}
			}
			else if (arrow == 5) {
				arrow = -1;
				break;
			}
			get_code();
			break;
		default:
			break;
		}
		if (arrow != -1)
		{
			menuColor(arrow);
		}
		else break;
	}
	system("cls");
	return 0;
}