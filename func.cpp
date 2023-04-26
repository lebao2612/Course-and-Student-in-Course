#include"header.h"

void khoiTaoSVList(SVList& svlist) {
	svlist.Head = NULL;
	svlist.Tail = NULL;
}

void khoiTaoClassList(ClassList& classlist) {
	classlist.Head = NULL;
	classlist.Tail = NULL;
}

void khoiTaoCourseList(CourseList& courselist) {
	courselist.Head = NULL;
	courselist.Tail = NULL;
}

//Doc sinh vien tu file
SinhVien* DocSV(string a) {
	fstream f;
	f.open(a);
	SinhVien* p = new SinhVien;
	getline(f, p->No, ',');
	getline(f, p->MSSV, ',');
	getline(f, p->Ten, ',');
	getline(f, p->Ho, ',');
	getline(f, p->Gioitinh, ',');
	getline(f, p->Ngaysinh, ',');
	getline(f, p->ID, '\n');
	p->pnext = NULL;
	return p;
}

// add sinh vien vao danh sach
void addSV(SVList& DS, SinhVien* sv) {
	if (sv == NULL)
		return;
	if (DS.Head == NULL) {
		DS.Head = sv;
		DS.Tail = sv;
	}
	else {
		DS.Tail->pnext = sv;
		DS.Tail = sv;
	}
}

//add lop hoc vao danh sach lop hoc
void addClass(ClassList& classlist, Class* iclass) {
	if (iclass == NULL)
		return;
	if (classlist.Head == NULL) {
		classlist.Head = iclass;
		classlist.Tail = iclass;
	}
	else {
		classlist.Tail->pnext = iclass;
		classlist.Tail = iclass;
	}
}

//add khoa hoc vao danh sach khoa hoc
void addCourse(CourseList& courselist, Course* course) {
	if (course == NULL)
		return;
	if (courselist.Head == NULL) {
		courselist.Head = course;
		courselist.Tail = course;
	}
	else {
		courselist.Tail->pnext = course;
		courselist.Tail = course;
	}
}

//xoa sinh vien
void xoaSV(SVList& DS, SinhVien* sv) {
	if (DS.Head == NULL)
		return;
	else if (DS.Head == sv) {
		DS.Head = DS.Head->pnext;
		delete sv;
	}
	else if (DS.Head == sv && DS.Tail == sv) {
		DS.Head = DS.Tail = NULL;
		delete sv;
	}
	else {
		SinhVien* p = DS.Head;
		while (p->pnext != sv) {
			p = p->pnext;
		}
		p->pnext = sv->pnext;
		delete sv;
	}
}

//xoa khoa hoc
void xoaCourse(CourseList& courselist, Course* course) {
	if (courselist.Head == NULL)
		return;
	else if (courselist.Head == course) {
		courselist.Head = courselist.Head->pnext;
		delete course;
	}
	else if (courselist.Head == course && courselist.Tail == course) {
		courselist.Head = courselist.Tail = NULL;
		delete course;
	}
	else {
		Course* p = courselist.Head;
		while (p->pnext != course) {
			p = p->pnext;
		}
		p->pnext = course->pnext;
		delete course;
	}
}

Class* CreateClass(string a) {
	Class* newClass = new Class;
	newClass->maLop = a;
	newClass->pnext = NULL;
	return newClass;
}


//CHECK CLASSLIST 
bool checkClassList(ClassList classlist) {
	if (classlist.Head == NULL) {
		return true;
	}
	return false;
}


//SAVE CLASSLIST
void saveClassList(ClassList& classlist) {
	fstream f;
	f.open("ClassList.csv");
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		string a;
		f >> a;
		Class* newClass = CreateClass(a);
		if (checkClassList(classlist)){
			classlist.Head = newClass;
			classlist.Tail = newClass;
		}
		else {
			classlist.Tail->pnext = newClass;
			classlist.Tail = newClass;
		}
	}
}

void xuatDanhSachCacLop(ClassList classlist) {
	Class* p = classlist.Head;
	while (p != NULL) {
		cout << p->maLop << endl;
		p = p->pnext;
	}
	string a;
	cout << "Nhap lop muon xem: ";
	cin >> a;
	xuatThongTinSVCuaLop(a);
}

bool checkSVList(SVList svlist) {
	if (svlist.Head == NULL)
		return true;
	return false;
}


/*void saveSVList(SVList& svlist, string a) {
	fstream f;
	f.open(a);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	string maLop, No, MSSV, Ten, Ho, Gioitinh, Ngaysinh, ID;
	while (!f.eof()) {
		SinhVien* p = DocSV(a);
		if (checkSVList)
			svlist.Head = svlist.Tail = p;
		else {
			svlist.Tail->pnext = p;
			svlist.Tail = p;
		}
	}
	f.close();
}

*/


void xuatThongTinSVCuaLop(string a) {
	string b = "Classes\\" + a + ".csv";
	fstream f;
	f.open(b, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	string No, Maso, Ten, Ho, GioiTinh, Ngaysinh, ID;
	while (!f.eof()) {
		getline(f, No, ',');
		if (No == "")
			break;
		getline(f, Maso, ',');
		getline(f, Ten, ',');
		getline(f, Ho, ',');
		getline(f, GioiTinh, ',');
		getline(f, Ngaysinh, ',');
		getline(f, ID, '\n');
		string hoten = Ho + " " + Ten;
		cout << No << "\t" << Maso << "\t" << hoten << "\t" << GioiTinh << "\t" << Ngaysinh << "\t" << ID << endl;
	}
}

bool checkCourseList(CourseList courselist) {
	if (courselist.Head == NULL)
		return true;
	return false;
}

void saveCourseList(CourseList &courselist) {
	fstream f;
	f.open("CoursesList.csv");
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		string a, b, c;
		Course* p = new Course;
		getline(f, p->maMH, ',');
		if (p->maMH == "\n")
			break;
		getline(f, p->tenMH, ',');
		getline(f, p->tenLop, ',');
		getline(f, a, ',');
		p->soLuongMax = stoi(a);
		getline(f, b, ',');
		p->soLuongCur = stoi(b);
		getline(f, c, ',');
		p->namHoc = stoi(c);
		getline(f, p->gioHoc, '\n');
		p->pnext = NULL;
		if (checkCourseList(courselist)) {
			courselist.Head = p;
			courselist.Tail = p;
		}
		else {
			courselist.Tail->pnext = p;
			courselist.Tail = p;
		}
	}
}

void xuatDanhSachMonHoc(CourseList courselist) {
	Course* p = courselist.Head;
	cout << "Ma MH" << "\t" << "Ten Mon Hoc" << "\t" << "Ten Lop" << "\t" << "So luong" << "\t" << "Da dang ky" << "\t" << "Nam hoc" << "\t" << "Gio hoc" << endl;
	while (p != NULL) {
		cout << p->maMH << "\t" << p->tenMH << "\t" << p->tenLop << "\t" << p->soLuongMax << "\t" << p->soLuongCur << "\t" << p->namHoc << "\t" << p->gioHoc << endl;
		p = p->pnext;
	}
}

void xuatHocSinhMonHoc(string a) {
	string b = "Courses\\" + a + ".csv";
	fstream f;
	f.open(b, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	string No, Maso, Ten, Ho, GioiTinh, Ngaysinh, ID;
	while (!f.eof()) {
		getline(f, No, ',');
		if (No == "")
			break;
		getline(f, Maso, ',');
		getline(f, Ten, ',');
		getline(f, Ho, ',');
		getline(f, GioiTinh, ',');
		getline(f, Ngaysinh, ',');
		getline(f, ID, '\n');
		string hoten = Ho + " " + Ten;
		cout << No << "\t" << Maso << "\t" << hoten << "\t" << GioiTinh << "\t" << Ngaysinh << "\t" << ID << endl;
	}
}