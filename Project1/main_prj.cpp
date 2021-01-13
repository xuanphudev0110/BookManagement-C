// khai bao thu vien
#include "BanDoc.h"
#include "Date.h"
#include "Sach.h"
#include "GiaoVien.h"
#include "PhieuMuon.h"
#include "SinhVien.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
#define MAX 100	 
#define L_SACH "Sach.txt"

/* Lưu ý khi về chương trình:
- Mã bạn đọc được viết in hoa
- Mã truy cập là admin
*/
int Sach::total = 0;
// ham welcome
void welcome();
// ham loading
void loading();
int PhieuMuon::count = 0; // khai bao biến đếm tổng số phiếu mượn
void main()
{	
	// khai bao
	PhieuMuon::setCount();
	PhieuMuon pNew;
	Sach sNew;
	SinhVien svNew;
	GiaoVien gvNew;
	vector<Sach> sach(MAX);
	vector<GiaoVien> gv(MAX);
	vector<SinhVien> sv(MAX);
	vector<BanDoc> readers(MAX);

	ifstream inFile;
	inputFromFile(inFile,sach);
	inputFromFile(inFile,gv);
	inputFromFile(inFile,sv);
	// goi ham welcome
	//welcome();
	// goi ham loading
	//loading();
	system("cls");
	// menu chuong trinh
MENU:
	cout << "//////////////////CHUC NANG//////////////////\n"
		 << "1. Hien thong tin cua tat ca sach \n\n"
		 << "2. Tim kiem thong tin \n\n"
		 << "3. Quan ly Phieu Muon \n\n"
		 << "4. Quan ly Sach \n\n"
		 << "5. Them Ban Doc\n\n"
		 << "/////////////////////////////////////////////\n";
	int option;
	do {
		cout << "Choose Service: ";
		cin >> option;
	} while (option <1 ||option >5); // chuong trinh chi co 5 chuc nang. Nhap sai nhap lai menu
	
	system("cls");
	string sB;
	 // === Ma Truy Cap ===
	string passKey = "admin";
	string inKey = "\0";
	switch(option)
	{
		case 1:
			cout << "////////////// SACH TRONG THU VIEN ////////////// \n";
			cout << sach; //hien danh sach trong thu vien
			system("pause");
			system("cls");
			goto MENU;
		break;
		case 2:
			cout << "================= TIM KIEM THONG TIN ================ \n";
			cout << "1. Tim kiem sach theo tua de \n";
			cout << "2. Tim kiem ban doc theo ma ban doc \n";
			cout << "Choose Service: ";
			cin >> option;
			switch (option)
			{
			case 1:
				cin.ignore();
				cout << "Nhap tua sach: ";
				getline(std::cin, sB); // xong r đó visual 2017 xài chưa quen :V
				SearchForBookTitle(sach, sB);
				system("pause");
				system("cls");
				goto MENU;
			case 2:
				cin.ignore();
				cout << "Nhap ma ban doc: ";
				getline(std::cin, sB);
				if (sB.substr(0, 4) == "GV17")
				{
					SearchForTeaChers(gv, sB);
				}
				else {
					SearchForStudents(sv, sB);
				}
				system("pause");
				system("cls");
				goto MENU;
			}
		break;
		case 3:
		do
		{
			system("cls");
			cout << "////////////////////////////////////////\n \n";
			cout << setw(26) << "Quan Ly\n\n";
			cout << "////////////////////////////////////////\n \n";
			cout << "Nhap ma truy cap cho admin!!!! \n";
			cout << "Nhap vao ma truy cap: ";
			fflush(stdin);
			getline(cin,inKey);	//nhap vao ma truy cap va kiem tra	
		}while(inKey != passKey);

		system("cls");
		cout << "//////////////////////////++ Quan Ly Phieu Muon ++//////////////////////////\n\n"
		 << "1. Tao phieu muon moi \n\n"
		 << "2. Cap nhat phieu muon \n\n"
		     << "///////////////////////////////////////////////////////////////////////////\n\n";
		cout << "Choose Service: ";
		cin >> option;

		//chuc nang
		switch(option)
		{
			case 1:
				taoPhieuMuon(pNew,sach,sv,gv);
				system("pause");
				system("cls");
				goto MENU;
			break;
			case 2:
				capNhatPhieuMuon(pNew);
				system("pause");
				system("cls");
				goto MENU;
			break;
		}
		break;

		case 4:
			do
			{
				system("cls");
				cout << "////////////////////////////////////////\n \n";
				cout << setw(26) << "Quan Ly\n\n";
				cout << "////////////////////////////////////////\n \n";
				cout << "Nhap ma truy cap cho admin!!!! \n";
				cout << "Nhap vao ma truy cap: ";
				fflush(stdin);
				getline(cin,inKey);	//nhap vao ma truy cap va kiem tra
			}while(inKey != passKey);

			system("cls");
			cout << "//////////////////////////++ Quan Ly Sach ++//////////////////////////\n\n"
				 << "1. Them sach \n\n"
				 << "2. Xoa sach \n\n"
				 << "///////////////////////////////////////////////////////////////////////\n\n";
			cout << "Choose Service: ";
			cin >> option;
			
			//chuc nang
			switch(option)
			{
				case 1:
					themSach(sach,sNew);
					system("pause");
					system("cls");
					goto MENU;
					break;
				case 2:
					xoaSach(sach);
					system("pause");
					system("cls");
					goto MENU;
				break;
			}
			break;
		case 5:
			do
			{
				system("cls");
				cout << "////////////////////////////////////////\n \n";
				cout << setw(26) << "Quan Ly\n\n";
				cout << "////////////////////////////////////////\n \n";
				cout << "Nhap ma truy cap cho admin!!!! \n";
				cout << "Nhap vao ma truy cap: ";
				fflush(stdin);
				getline(cin, inKey);	//nhap vao ma truy cap va kiem tra
			} while (inKey != passKey);

			system("cls");
			cout << "================= Add Ban Doc ================ \n";
			cout << "1. Add Sinh Vien \n";
			cout << "2. Add Giao Vien \n";
			cout << "Choose Service: ";
			cin >> option;
			switch (option)
			{
				case 1:
					themBanDocSV(sv, svNew);
					system("pause");
					system("cls");
					goto MENU;
					break;
				case 2:
					themBanDocGV(gv, gvNew);
					system("pause");
					system("cls");
					goto MENU;
					break;
			}
			
	}
	system("pause");
}
void loading()
{
	system("cls");
	for (int i = 1; i <= 50; i++)
	{
		system("cls");
		cout << "\n\n\n\n\t\t\t\t   Loading " << '\n' << '\t' << '\t';
		for (int j = 1; j <= i; j++)
			cout << "²";
		cout << "\n\n\t " << 2 * i << "%";
		if (i > 1 && i < 20)
			cout << "\n\n\tCreating Temporary files";
		else if (i > 20 && i < 40)
			cout << "\n\n\tAccessing Main Memory";
		else if (i > 40 && i < 48)
			cout << "\n\n\tAccessing Cache\n\n";
		Sleep(150 - i * 3);
	}
	system("pause");
}
// ham welcome
void welcome()
{
	cout << "\t%%      %%      ";
	cout << "\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
	cout << "\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
	cout << "\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
	cout << "\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
	cout << "\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
	cout << "\n\n\t\t\t        $$$$$$$$  $$$$$        ";
	cout << "\n\t\t\t           $$     $   $      ";
	cout << "\n\t\t\t           $$     $$$$$    ";
	cout << "\n\n\n\t\t\t(**********  PROJECT  *********)";
	cout << "\n\n\t\t\tThành Viên Nhóm: \n\n";
	cout << "\t\t\t\t 1. Nguyen Quoc Duy \n\n";
	cout << "\t\t\t\t 2. Pham Xuan Phu \n\n";
	cout << "\t\t\t\t 3. Nguyen Tang Vinh \n\n";
	system("pause");
}