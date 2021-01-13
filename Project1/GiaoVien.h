#pragma once
// khai bao thu vien
#include "BanDoc.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;

class GiaoVien: protected BanDoc
{
private:
	string diaChi;
	string sdt;
	Date ngay;
public:
	GiaoVien(void);
	~GiaoVien();
	// getters
	string getNgayDki();
	// kiem tra giao vien co hay khong
	friend bool checkGiaoVien(vector<GiaoVien> gv,string key);
	// doc file GiaoVien.txt
	friend void inputFromFile(ifstream &inFile,vector<GiaoVien> &gv);
	// ghi file
	friend ostream& operator << (ostream &os,vector<GiaoVien> &gv);
	// ham tim kiem ma ban doc la giao vien
	friend void SearchForTeaChers(vector<GiaoVien> &bandoc, string ma);
	// ham them ban doc la giao vien
	friend void themBanDocGV(vector<GiaoVien> &listGV, GiaoVien gv);
};


