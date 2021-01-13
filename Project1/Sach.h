#pragma once
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;
#define MAX 100
class Sach
{
private:
	static int total; //tong so sach co trong thu vien
	string maSach;
	string tuaDe;
	string tacGia;
	string nxb;
	double gia;
	int namPH;
	int soTrang;
	Date ngayNhapKho;
	int maPhieuMuon;
public:
	Sach(void);
	~Sach();
	/// getters
	string getTuaDe();
	string getMaSach();
	string getNgayNhapKho();
	// setters
	void setMaPhieuMuon(int maPhieuMuon);
	// doc file
	friend void inputFromFile(ifstream &inFile,vector<Sach> &sach);
	// doc tung dong file
	friend void inputToFile_Sach(vector<Sach> &sach);
	// xoa sach
	friend void xoaSach(vector<Sach> &sach);
	// them sach
	friend void themSach(vector<Sach> &listSach,Sach sach);
	// ghi file
	friend ostream& operator << (ostream &os,vector<Sach> &sach);
	// kiem tra sach co hay khong
	friend bool checkSach(vector<Sach> sach,string key);
	// kiem tra sach
	friend int checkSach_vector(vector<Sach> sach,string key);
	// tim kiem sach theo tua de
	friend void SearchForBookTitle(vector<Sach> &BOOK, string Title);
};

