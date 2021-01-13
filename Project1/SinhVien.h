#include "BanDoc.h"
#include"Date.h"
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;

class SinhVien:protected BanDoc
{
private:
	string khoaHoc;
	Date ngay;
public:
	SinhVien(void);
	~SinhVien();
	// setters
	void setKhoaHoc(string khoaHoc);
	// getters
	string getNgayDki();
	string getMaBD();
	string getTen();
	string getKhoaHoc();
	string getKhoa();
	friend bool checkSinhVien(vector<SinhVien> sv,string key); //kiem tra xem co sinh vien nay ton tai hay khong
	friend void inputFromFile(ifstream &inFile,vector<SinhVien> &sv); // doc file
	friend ostream& operator << (ostream &os,vector<SinhVien> &sv); // ghi file
	friend void SearchForStudents(vector<SinhVien> &bandoc, string ma); // tim kiem ma ban doc theo sinh vien
	friend void themBanDocSV(vector<SinhVien> &listSV, SinhVien sv);// them ban doc theo sinh vien
	
};


