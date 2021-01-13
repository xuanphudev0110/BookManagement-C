#include "GiaoVien.h"


GiaoVien::GiaoVien(void)
{
}
GiaoVien::~GiaoVien()
{
}
// kiem tra giao vien co hay khong
bool checkGiaoVien(vector<GiaoVien> gv,string key)
{
   for(int i =0;i < gv.size();i++)
	{
		if(gv[i].getMaBD() == key)
		{
			return true;
		}
	}
    return false;
}
// doc file GiaoVien.txt
void inputFromFile(ifstream &inFile,vector<GiaoVien> &gv)
{
	// khai bao bien
	int i = 0;
	string maBD,hoTen,khoa,ngayDangKy;
	// duong dan den file txt
	inFile.open("csdl/GiaoVien.txt");
	// neu duong dan sai dung chuong trinh
	if(!inFile.is_open())
	{
		cout << "Mo File GiaoVien.txt khong thanh cong !!! \n";
		return;
	}
	// ðoc tung dong file txt
	while(!inFile.eof())
	{
		getline(inFile,maBD,'#');
		gv[i].setMaBD(maBD);
		getline(inFile,hoTen,'#');
		gv[i].setHoTen(hoTen);
		getline(inFile,khoa,'#');
		gv[i].setKhoa(khoa);
		getline(inFile,ngayDangKy,'#');
		gv[i].setNgayDangKy(ngayDangKy);

		getline(inFile,gv[i].diaChi,'#');
		getline(inFile,gv[i].sdt,'\n');
		i++;
	}
	gv.resize(i-1);
	inFile.close();
}
// ghi file
ostream& operator << (ostream &os,vector<GiaoVien> &gv)
{
	for(int i =0;i < gv.size();i++)
	{
		os << "Ma gv: " << gv[i].maBD << endl;
		os << "ho ten: "<< gv[i].hoTen << endl; 
		os << "khoa: "<< gv[i].khoa << endl; 
		os << "ho ten: "<< gv[i].ngayDangKy << endl; 
		os << "dia chi: "<< gv[i].diaChi << endl;
		os << "===========================\n";
	}
	return os;
}
// ham tim kiem ma ban doc la giao vien
void SearchForTeaChers(vector<GiaoVien> &bandoc, string ma)
{
		for (int i = 0; i < bandoc.size(); i++)
		{
			if (bandoc[i].getMaBD() == ma)
			{
				cout << "Thong tin ma ban doc ban muon tim: \n";
				cout << "Ten ban doc: " << bandoc[i].hoTen << endl;
				cout << "Khoa: " << bandoc[i].khoa << endl;
				cout << "Dia chi: " << bandoc[i].diaChi << endl;
				cout << "Ngay dang ki tham gia: " << bandoc[i].ngayDangKy << endl;
				cout << "So dien thoai: " << bandoc[i].sdt << endl;
				return;
			}
		}
		cout << "Khong tim thay ma ban doc ban yeu cau!!!\n";
}
// getter cua ngay dang ki
string GiaoVien::getNgayDki()
{
	string ngayNhap;

	std::ostringstream oss;
	oss << ngay.getDay();
	oss << "/";
	oss << ngay.getMon();
	oss << "/";
	oss << ngay.getYear();

	ngayNhap = oss.str();
	return ngayNhap;
}
// ham them ban doc la giao vien
void themBanDocGV(vector<GiaoVien> &listGV, GiaoVien gv)
{
	cout << "bat buoc nhap chuoi GV17TT neu nhap sai nhap lai!!! \n";
	do
	{
		do
		{
			cin.ignore();
			cout << "Nhap vao ma ban doc: ";
			fflush(stdin);
			getline(cin, gv.maBD);
		} while (gv.maBD.substr(0,6) != "GV17TT"); // neu nhap khac GV17TT yeu cau nhap lai
		// kiem tra ma giao vien co ton tai hay khong
		if (checkGiaoVien(listGV, gv.maBD))
		{
			cout << "Ma ban doc nay da ton tai vui long nhap lai !!! \n";
		}
	} while (checkGiaoVien(listGV, gv.maBD)); // neu ma giao vien ton tai yeu cau nhap lai
	cout << "Nhap vao ten ban doc: ";
	fflush(stdin);
	getline(cin, gv.hoTen);
	cout << "Nhap ten khoa: ";
	fflush(stdin);
	getline(cin, gv.khoa);
	cout << "Nhap ten dia chi: ";
	fflush(stdin);
	getline(cin, gv.diaChi);
	cout << "Nhap so dien thoai: ";
	fflush(stdin);
	getline(cin, gv.sdt);
	// khai bao bien
	int day, mon, year;
	cout << "--Ngay dang ki tham gia: \n";
	cout << "ngay: ";
	cin >> day;

	cout << "thang: ";
	cin >> mon;

	cout << "nam: ";
	cin >> year;
	gv.ngay.setDayMonYear(day, mon, year);
	// khai bao bien ofstream
	ofstream outFile;
	// duong dan den file txt
	outFile.open("csdl/UserData.txt", ios::app);
	// neu duong dan sai dung chuong trinh
	if (!outFile.is_open())
	{
		cout << "Khong mo duoc file csdl/UserData.txt!!! \n";
		return ;
	}
	// ghi file xuong file txt
	outFile << gv.maBD << "#"
		<< gv.hoTen << "#"
		<< gv.khoa << "#"
		<< gv.getNgayDki() << "#"
		<< gv.diaChi<<"#"
		<< gv.sdt <<"\n";
	outFile.close();

	listGV.push_back(gv);
	cout << "Them vao thanh cong !!!Vui long kiem tra file csdl/UserData.txt \n";
}