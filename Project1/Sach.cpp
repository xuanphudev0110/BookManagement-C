#include "Sach.h"


Sach::Sach(void)
{
	maSach = "\0";
	tuaDe =  "\0";
	tacGia = "\0";
	nxb = "\0";
	namPH = 0;
	soTrang = 0;
	maPhieuMuon = -1;
}
Sach::~Sach(){}
// getters
string Sach::getTuaDe()
{
	return this->tuaDe;
}
string Sach::getMaSach()
{
	return maSach;
}  
string Sach::getNgayNhapKho()
{
	string ngayNhap;

	std::ostringstream oss;
	oss << ngayNhapKho.getDay();
	oss << "/";
	oss << ngayNhapKho.getMon();
	oss << "/";
	oss << ngayNhapKho.getYear();

	ngayNhap = oss.str();
	return ngayNhap;
}
//setters
void Sach::setMaPhieuMuon(int maPhieuMuon)
{
	this->maPhieuMuon = maPhieuMuon;
}
// doc file
void inputFromFile(ifstream &inFile,vector<Sach> &sach)
{
	// khai bao bien
    int i = 0;
	int day = 0;
	int mon = 0;
	int year = 0;
	// duong dan den file txt
	inFile.open("csdl/Sach.txt");
	// neu duong dan sai dung chuong trinh
	if(!inFile.is_open())
	{
		cout << "Mo file khong thanh cong !!! \n";
		return;
	}
	// doc tren 1 dong file
	while(!inFile.eof())
	{
		getline(inFile,sach[i].maSach,'#');
		getline(inFile,sach[i].tuaDe,'#');
		getline(inFile,sach[i].tacGia,'#');
		getline(inFile,sach[i].nxb,'#');

		inFile >> sach[i].gia;
		inFile.ignore(1,'#');
		inFile >> sach[i].namPH;
		inFile.ignore(1,'#');
		inFile >> sach[i].soTrang;
		inFile.ignore(1,'#');

		inFile >> day;
		inFile.ignore(1,'/');
		inFile >> mon;
		inFile.ignore(1,'/');
		inFile >> year;
		inFile.ignore(1,'#');
		sach[i].ngayNhapKho.setDayMonYear(day,mon,year);
		inFile >> sach[i].maPhieuMuon;
		inFile.ignore(1,'\n');
		i++;
	}
	sach.resize(i-1);
	inFile.close();

}
// doc tung dong file
void inputToFile_Sach(vector<Sach> &sach)
{
	// duong dan den file txt
	ofstream outFile("csdl/Sach.txt");
	// neu duong dan sai dung chuong trinh
	if(!outFile.is_open())
	{
		cout << "Mo file - csdl/Sach.txt: khong thanh cong !!! \n";
		return;
	}
	// doc tung dong file
	for(int i = 0;i < sach.size();i++)
	{
	 outFile << sach[i].maSach << "#"
			<< sach[i].tuaDe << "#"
			<< sach[i].tacGia << "#"
			<< sach[i].nxb << "#"
			<< sach[i].gia << "#"
			<< sach[i].namPH << "#"
			<< sach[i].soTrang << "#"
			<< sach[i].getNgayNhapKho() << "#"
			<< sach[i].maPhieuMuon << "\n";
	}
	outFile.close();
}
// ghi file
ostream& operator << (ostream &os,vector<Sach> &sach)
{
	cout << "==============Danh sach cac Sach trong thu vien==============\n\n";
	for(int i = 0;i < sach.size();i++)
	{
		os << "Ma sach: " << sach[i].maSach
		   << setw(20) << "Tua sach: " << sach[i].tuaDe << "\n"
		   << "Ten tg: " << sach[i].tacGia << "\n"
		   << "NXB: "  << sach[i].nxb << "\n"
		   << "Gia: "  << sach[i].gia << "\n"
		   << "Nam PH: " << sach[i].namPH << "\n"
		   << "Ngay nhap kho: " << sach[i].getNgayNhapKho() << "\n"
		   << "So trang: " << sach[i].soTrang << "\n";
		os << "-------------------------------------\n";
	}
	return os;
}
// ham xóa sach
void xoaSach(vector<Sach> &sach)
{
NHAP:
	string key;
	do
	{
		cout << "Nhap vao ma sach can xoa: ";
		fflush(stdin);
		getline(cin,key);
		if(checkSach_vector(sach,key) == -1)
		{
		   cout << "Khong tim thay sach nay !!! \n";
		}
	}while(checkSach_vector(sach,key) == -1);// kiem tra ma sach có hay không nếu không có thì nhập lại

	int pos = checkSach_vector(sach,key); 

	//kiem tra hien tai sach co dang duoc muon khong
	if(sach[pos].maPhieuMuon != 0)// neu sach dang muon thi khong the xoa
	{
		cout << "Sach nay hien dang duoc muon khong the xoa !!! Vui long nhap lai \n";
		goto NHAP;
	}
	swap(sach[pos],sach[sach.size()-1]);
	sach.pop_back();

	//cap nhat vao file
	ofstream outFile;
	// duong dan den file txt
	outFile.open("csdl/Sach.txt");
	//// neu duong dan sai dung chuong trinh
	if(!outFile.is_open())
	{
		cout << "Khong mo duoc file csdl/Sach.txt";
		return;
	}
	// ghi file
	for(int i = 0;i < sach.size();i++)
	{
		outFile << sach[i].maSach << "#"
				<< sach[i].tuaDe << "#"
				<< sach[i].tacGia << "#"
				<< sach[i].nxb << "#"
				<< sach[i].gia << "#"
				<< sach[i].namPH << "#"
				<< sach[i].soTrang << "#"
				<< sach[i].getNgayNhapKho() << "#"
				<< sach[i].maPhieuMuon << "\n";
	}
	outFile.close();
	cout << "Xoa sach thanh cong!! \n";
}
// ham thêm sách
void themSach(vector<Sach> &listSach,Sach sach)
{	
	do
	{
		cin.ignore();
		cout << "Nhap vao ma sach: ";
		fflush(stdin);
		getline(cin,sach.maSach);
		if(checkSach(listSach,sach.maSach))
		{
		   cout << "Ma sach nay da ton tai vui long nhap lai !!! \n";
		}
	}while(checkSach(listSach,sach.maSach)); // kiem tra ma sach co hay khong. nếu có yêu cầu nhập lại
	cout << "Nhap vao ten sach: ";
	fflush(stdin);
	getline(cin,sach.tuaDe);
	cout << "Nhap vao tac gia: ";
	fflush(stdin);
	getline(cin,sach.tacGia);
	cout << "Nhap vao nxb: ";
	fflush(stdin);
	getline(cin,sach.nxb);
	cout << "Nhap vao gia: ";
	cin >> sach.gia;
    cout << "Nhap vao nam phat hanh: ";
	cin >> sach.namPH;
	cout << "Nhap vao so trang: ";
	cin >> sach.soTrang;
	// khai bao bien
	int day,mon,year;
	cout << "--Ngay Nhap kho: \n";
	cout << "ngay: ";
	cin >> day;

	cout << "thang: ";
	cin >> mon;

	cout << "nam: ";
	cin >> year;
	sach.ngayNhapKho.setDayMonYear(day,mon,year);
	sach.setMaPhieuMuon(0);

	ofstream outFile;
	// duong dan den file txt
	outFile.open("csdl/Sach.txt",ios::app);
	//// neu duong dan sai dung chuong trinh
	if(!outFile.is_open())
	{
	    cout << "Khong mo duoc file csdl/Sach.txt!!! \n";
	}
		// ghi file
	outFile<< sach.maSach<< "#"
		   << sach.tuaDe << "#"
		   << sach.tacGia << "#"
		   << sach.nxb << "#"
		   << sach.gia << "#"
		   << sach.namPH << "#"
		   << sach.soTrang << "#"
		   << sach.getNgayNhapKho() << "#"
		   << sach.maPhieuMuon << "\n";
	outFile.close();
	// duyet qua list sach
	listSach.push_back(sach);
	cout << "Them vao thanh cong !!!Vui long kiem tra file csdl/Sach.txt \n";
}
// ham tim kiem sach
void SearchForBookTitle(vector<Sach> &BOOK, string Title)
{
	
	for (int i = 0; i < BOOK.size(); i++)
	{
		//cout << BOOK[i].getTuaDe() << endl;
		//cout << BOOK[i].getTuaDe().length() << endl;
		if (BOOK[i].getTuaDe() == Title)
		{
			cout << "Thong tin sach ban muon tim: \n";
			cout << "Ma sach: "<<BOOK[i].getMaSach() << endl;
			cout << "Tua de: "<<BOOK[i].getTuaDe() << endl;
			cout << "Tac gia: "<<BOOK[i].tacGia << endl;
			cout << "Nha xuat ban: " << BOOK[i].nxb << endl;
			cout << "Gia: " << BOOK[i].gia << endl;
			cout << "Nam phat hanh: " << BOOK[i].namPH << endl;
			cout << "So trang: " << BOOK[i].soTrang<<endl;
			return;
		}
	}
	cout << "Khong tim thay tua sach ban yeu cau!!!\n";
}
// ham check sach
bool checkSach(vector<Sach> sach,string key)
{
	for(int i = 0;i < sach.size();i++)
	{
		if(sach[i].getMaSach() == key)
		{
				return true;
		}
	}
	return false;
}
int checkSach_vector(vector<Sach> sach,string key)
{
	for(int i = 0;i < sach.size();i++)
	{
		if(sach[i].getMaSach() == key)
		{
				return i;
		}
	}
	return -1;
}