#include "PhieuMuon.h"


PhieuMuon::PhieuMuon(void)
{
	maBD = "\0";
	tinhTrang = 0;
}
PhieuMuon::~PhieuMuon() {}
void PhieuMuon::setCount()
{
	// khai bao ifstream
	ifstream inFile;
	// duong dan den file txt
	inFile.open("csdl/PhieuMuon/count.txt");
	// kiem tra duong dan
	if (!inFile.is_open())
	{
		cout << "Mo file - database/count.txt: khong thanh cong !!! \n";
		return;
	}
	inFile >> PhieuMuon::count;
	inFile.ignore(1, '\n');
	inFile.close();
}
void PhieuMuon::updateCount()
{
	// khai bao ofstream
	ofstream ofstream;
	// duong dan den file txt
	ofstream.open("csdl/PhieuMuon/count.txt");
	// kiem tra duong dan
	if (!ofstream.is_open())
	{
		cout << "Mo file - database/count.txt: khong thanh cong !!! \n";
		return;
	}
	ofstream << PhieuMuon::count;
	ofstream.close();
}
// setters
void PhieuMuon::setTinhTrang(int tinhTrang)
{
	this->tinhTrang = tinhTrang;
}
// getters
int PhieuMuon::getCount()
{
	return PhieuMuon::count;
}
int PhieuMuon::getStt()
{
	return stt;
}
string PhieuMuon::getNgayMuon()
{
	string ngayNhap;

	std::ostringstream oss;
	oss << ngayMuon.getDay();
	oss << "/";
	oss << ngayMuon.getMon();
	oss << "/";
	oss << ngayMuon.getYear();

	ngayNhap = oss.str();
	return ngayNhap;
}
string PhieuMuon::getNgayTra()
{
	string ngayNhap;

	std::ostringstream oss;
	oss << ngayTra.getDay();
	oss << "/";
	oss << ngayTra.getMon();
	oss << "/";
	oss << ngayTra.getYear();

	ngayNhap = oss.str();
	return ngayNhap;
}
string PhieuMuon::getMaNguoiMuon()
{
	return maBD;
}
int PhieuMuon::getTinhTrang()
{
	return tinhTrang;
}
string PhieuMuon::getMaSach()
{
	return maSach;
}
string PhieuMuon::getMaBD()
{
	return maBD;
}
// cap nhat phieu muon
void capNhatPhieuMuon(PhieuMuon pm)
{
NHAP:
	string key;
	int upTinhTrang = 3;
	cout << "Nhap vao so phieu muon: ";
	fflush(stdin);
	getline(cin, key);
	// duong dan den so phieu muon
	ifstream inFile;
	inFile.open("csdl/PhieuMuon/" + key + ".txt");
	// kiem tra duong dan
	if (!inFile.is_open())
	{
		cout << "Khong tim thay phieu muon nay!!!Vui long nhap lai...\n";
		goto NHAP;
	}
	// cap nhat lai tinh trang muon sach
	do
	{
		cout << "Nhap vao tinh trang phieu muon (0 hoac 1): ";
		cin >> upTinhTrang;
	} while (upTinhTrang > 1 && upTinhTrang < 0); // nhap sai nhap lai

	// khai bao bien
	int day, mon, year;
	int day2, mon2, year2;
	// doc file
	while (!inFile.eof())
	{
		inFile >> pm.stt;
		inFile.ignore(1, '\n');

		getline(inFile, pm.maSach, '\n');
		getline(inFile, pm.maBD, '\n');

		inFile >> day;
		inFile.ignore(1, '/');
		inFile >> mon;
		inFile.ignore(1, '/');
		inFile >> year;
		inFile.ignore(1, '\n');
		pm.ngayMuon.setDayMonYear(day, mon, year);

		inFile >> day2;
		inFile.ignore(1, '/');
		inFile >> mon2;
		inFile.ignore(1, '/');
		inFile >> year2;
		inFile.ignore(1, '\n');
		pm.ngayTra.setDayMonYear(day2, mon2, year2);
		inFile >> pm.tinhTrang;

		inFile.ignore(1, '\n');
	}
	pm.tinhTrang = upTinhTrang;
	//cap nhat lai phieu muon vao file
	ofstream outFile;
	outFile.open("csdl/PhieuMuon/" + key + ".txt");

	outFile << pm.stt << "\n"
		<< pm.maSach << "\n"
		<< pm.maBD << "\n"
		<< pm.getNgayMuon() << "\n"
		<< pm.getNgayTra() << "\n"
		<< pm.tinhTrang << "\n";
	outFile.close();
	cout << "Cap nhat thanh cong !!!Quay lai menu chinh...\n";
}
// tao phieu muon
void taoPhieuMuon(PhieuMuon &pm, vector<Sach> &sach, vector<SinhVien> sv, vector<GiaoVien> gv)
{
	do //nhap va kiem tra ma Sach co ton tai hay khong
	{
		cout << "Nhap vao ma sach: ";
		fflush(stdin);
		getline(cin, pm.maSach);
		if (!checkSach(sach, pm.maSach))
		{
			cout << "Khong tim thay ma sach!!!Vui long nhap lai ... \n";
		}
	} while (!checkSach(sach, pm.maSach));

	do //nhap va kiem tra ma ban doc co ton tai hay khong
	{
		cout << "Nhap vao ma ban doc: ";
		fflush(stdin);
		getline(cin, pm.maBD);
		if (!checkSinhVien(sv, pm.maBD) && !checkGiaoVien(gv, pm.maBD))
		{
			cout << "Khong tim thay ma ban doc nay!!!Vui long nhap lai ...\n";
		}
	} while (!checkSinhVien(sv, pm.maBD) && !checkGiaoVien(gv, pm.maBD));
	// khai bao bien
	int day, mon, year;
	cout << "--Ngay Muon Sach: \n";
	cout << "ngay: ";
	cin >> day;

	cout << "thang: ";
	cin >> mon;

	cout << "nam: ";
	cin >> year;
	pm.ngayMuon.setDayMonYear(day, mon, year);

	cout << "--Ngay Tra Sach: \n";
	cout << "ngay: ";
	cin >> day;

	cout << "thang: ";
	cin >> mon;

	cout << "nam: ";
	cin >> year;
	pm.ngayTra.setDayMonYear(day, mon, year);

	pm.setTinhTrang(1);

	PhieuMuon::count++;
	PhieuMuon::updateCount();
	pm.stt = PhieuMuon::count;
	string fileName;

	//chuyen tu kieu du lieu int -> string
	std::ostringstream oss;
	oss << pm.getStt();

	fileName = oss.str();

	//tao file phieu muon
	// khai bao ofstream
	ofstream outFile;
	// duong dan den file txt
	outFile.open("csdl/PhieuMuon/" + fileName + ".txt");
	// ghi file
	outFile << pm.stt << "\n"
		<< pm.maSach << "\n"
		<< pm.maBD << "\n"
		<< pm.getNgayMuon() << "\n"
		<< pm.getNgayTra() << "\n"
		<< pm.tinhTrang << "\n";
	outFile.close();

	//cap nhat vao sach 
	for (int i = 0; i < sach.size(); i++)
	{
		if (sach[i].getMaSach() == pm.maSach)
		{
			sach[i].setMaPhieuMuon(pm.stt);
			break;
		}
	}
	inputToFile_Sach(sach);
	cout << "Them phieu muon thanh cong. Vui long kiem tra lai!!! \n";

}

