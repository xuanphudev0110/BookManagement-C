#include "SinhVien.h"


SinhVien::SinhVien(void)
{

}
SinhVien::~SinhVien(){}
// setters
void SinhVien::setKhoaHoc(string khoaHoc)
{
	this->khoaHoc = khoaHoc;
}
// getters
string SinhVien::getMaBD()
{
	return maBD;
}
string SinhVien::getTen()
{
	return hoTen;
}
string SinhVien::getKhoaHoc()
{
	return this->khoaHoc;
}
string SinhVien::getKhoa() {
	return khoa;
}
// ham check Sinh vien
bool checkSinhVien(vector<SinhVien> sv,string key)
{
   for(int i =0;i < sv.size();i++)
	{
		if(sv[i].getMaBD() == key)
		{
			return true;
		}
	}
    return false;
}
// doc file
void inputFromFile(ifstream &inFile,vector<SinhVien> &sv)
{
	// khai bao bien
	int i = 0;
	string maBD,hoTen,khoa,ngayDangKy,khoaHoc;
	// duong dan den file txt
	inFile.open("csdl/SinhVien.txt");
	// mo file khong thanh cong
	if(!inFile.is_open())
	{
		cout << "Mo File GiaoVien.txt khong thanh cong !!! \n";
		return;
	}
	// doc file den '#'
	while(!inFile.eof())
	{
		getline(inFile,maBD,'#');
		sv[i].setMaBD(maBD);
		getline(inFile,hoTen,'#');
		sv[i].setHoTen(hoTen);
		getline(inFile,khoa,'#');
		sv[i].setKhoa(khoa);
		getline(inFile,ngayDangKy,'#');
		sv[i].setNgayDangKy(ngayDangKy);
		getline(inFile,khoaHoc,'\n');
		sv[i].setKhoaHoc(khoaHoc);
		i++;
	}
	sv.resize(i-1);
	inFile.close();
}
// ghi file
ostream& operator << (ostream &os,vector<SinhVien> &sv)
{
	for(int i =0;i < sv.size();i++)
	{
		os << "Ma sv: " << sv[i].maBD << endl;
		os << "ho ten: "<< sv[i].hoTen << endl; 
		os << "khoa: "<< sv[i].khoa << endl; 
		os << "ho ten: "<< sv[i].ngayDangKy << endl; 
		os << "khoa hoc: "<< sv[i].khoaHoc << endl;
		os << "===========================\n";
	}
	return os;
}
//im kiem ma ban doc theo sinh vien
void SearchForStudents(vector<SinhVien> &bandoc, string ma)
{
	for (int i = 0; i < bandoc.size(); i++)
	{
		if (bandoc[i].getMaBD() == ma)
		{
			cout << "Thong tin ma ban doc ban muon tim: \n";
			cout << "Ten ban doc: " << bandoc[i].hoTen << endl;
			cout << "Khoa: " << bandoc[i].khoa << endl;
			cout << "Khoa hoc: " << bandoc[i].khoaHoc << endl;
			cout << "Ngay dang ki tham gia: " << bandoc[i].ngayDangKy << endl;
			return;
		}
	}
	cout << "Khong tim thay ma ban doc ban yeu cau!!!\n";
}
string SinhVien::getNgayDki()
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
// them ban doc theo sinh vien
void themBanDocSV(vector<SinhVien> &listSV, SinhVien sv)
{
	cout << "bat buoc nhap chuoi 17211 neu nhap sai nhap lai!!! \n";
	do
	{
		do
		{
			cin.ignore();
			cout << "Nhap vao ma ban doc: ";
			fflush(stdin);
			getline(cin, sv.maBD);
		} while (sv.maBD.substr(0, 5) != "17211");
		if (checkSinhVien(listSV, sv.maBD))
		{
			cout << "Ma ban doc nay da ton tai vui long nhap lai !!! \n";
		}
	} while (checkSinhVien(listSV, sv.maBD));// kiem tra ma ban doc co hay khong
	cout << "Nhap vao ten ban doc: ";
	fflush(stdin);
	getline(cin, sv.hoTen);
	cout << "Nhap ten khoa: ";
	fflush(stdin);
	getline(cin, sv.khoa);
	cout << "Nhap ten khoa hoc: ";
	fflush(stdin);
	getline(cin, sv.khoaHoc);
	int day, mon, year;
	cout << "--Ngay dang ki tham gia: \n";
	cout << "ngay: ";
	cin >> day;

	cout << "thang: ";
	cin >> mon;

	cout << "nam: ";
	cin >> year;
	sv.ngay.setDayMonYear(day, mon, year);
	ofstream outFile;
	// duong dan den file txt
	outFile.open("csdl/UserData.txt", ios::app);
	// mo file khong thanh cong
	if (!outFile.is_open())
	{
		cout << "Khong mo duoc file csdl/UserData.txt!!! \n";
	}
	// ghi file
	outFile << sv.maBD << "#"
		<< sv.hoTen << "#"
		<< sv.khoa << "#"
		<< sv.khoaHoc << "#"
		<< sv.getNgayDki() << "\n";
		outFile.close();

	listSV.push_back(sv);
	cout << "Them vao thanh cong !!!Vui long kiem tra file csdl/UserData.txt \n";
}