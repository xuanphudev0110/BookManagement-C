#pragma once
#include "Sach.h"
#include "SinhVien.h"
#include "GiaoVien.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;

class PhieuMuon
{
private:
	static int count;// tổng số sách
	int stt;
	Date ngayMuon;
	Date ngayTra;
	string maSach;
	string maBD;
	int tinhTrang;
public:
	PhieuMuon(void);
	~PhieuMuon();
	// setters
	void setTinhTrang(int tinhTrang);
	static void setCount(); //dùng để xác định stt (mã số phiếu)
	static void updateCount();
	static int getCount();
	int getStt();
	// getters
	string getNgayMuon();
	string getNgayTra();
	string getMaNguoiMuon();
	string getMaSach();
	string getMaBD();
	int getTinhTrang();
	// ham cap nhat phieu Muon
	friend void capNhatPhieuMuon(PhieuMuon pm);
	// ham tao phieu muon
	friend void taoPhieuMuon(PhieuMuon &pm, vector<Sach> &sach, vector<SinhVien> sv, vector<GiaoVien> gv); //cau 4 - a
};

