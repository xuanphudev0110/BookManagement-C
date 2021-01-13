#include "BanDoc.h"

BanDoc::BanDoc(void)
{
}
BanDoc::~BanDoc()
{
}
// getters
string BanDoc::getMaBD()
{
	return this->maBD;
}
// setters
void BanDoc::setMaBD(string maBD)
{
	this->maBD = maBD;
}
void BanDoc::setHoTen(string hoTen)
{
	this->hoTen = hoTen;
}
void BanDoc::setKhoa(string khoa)
{
	this->khoa = khoa;
}
void BanDoc::setNgayDangKy(string ngayDangKy)
{
	this->ngayDangKy = ngayDangKy;
}
