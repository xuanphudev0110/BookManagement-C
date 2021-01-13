#pragma once
// khai bao thu vien
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class BanDoc
{
protected:
	string maBD; //mã BD
	string hoTen;
	string khoa;
	string ngayDangKy;
public:
	BanDoc(void);
	~BanDoc();
	// getters
	string getMaBD();
	// setters
	void setMaBD(string maBD);
	void setHoTen(string hoTen);
	void setKhoa(string khoa);
	void setNgayDangKy(string ngayDangKy);
};

