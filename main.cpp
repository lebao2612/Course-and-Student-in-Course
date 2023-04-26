#include"header.h"
//hello
int main() {
	SVList DS;
	fstream f;
	//xuatThongTinLop(f,DS);
	ClassList classlist;
	CourseList courselist;
	khoiTaoClassList(classlist);
	khoiTaoCourseList(courselist);
	saveClassList(classlist);
	saveCourseList(courselist);
	Course* p = courselist.Head;
	xuatDanhSachMonHoc(courselist);
	xuatHocSinhMonHoc("ADD00031");
	//xuatDanhSachCacLop(classlist);
	//xuatThongTinSVCuaLop("TNT1");
}