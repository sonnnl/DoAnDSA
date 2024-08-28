#pragma once
#include"VAT_TU.H"
#include"NHAN_VIEN.h"
//////////////////////////HOA DON VA CHI TIET HOA DON////////////////////////////////////
/////////////////HOA DON ///////////////
string Tao_Ma_HD(DS_NV ds_nv);
void Them_HD_Vao_DS(HOA_DON hd, DS_HD &ds_hd);
void NhapNgay(string &result, int choice, int &ordinal, bool &isSave, bool &isEscape);
int countds_hd(DS_HD ds);
void Nhap_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN *nv, HOA_DON &hd);
NHAN_VIEN* Find_NV(DS_NV ds_nv,NODE_HD *node_hd);
////////////CHI TIET HOA DON ///////////
bool Full_CTHD(DS_CT_HD ds);
int Insert_CT_HD(DS_CT_HD& ds, CHI_TIET_HOA_DON cthd);
void Output_CTHD(TREE_VT t, CHI_TIET_HOA_DON cthd, int& locate);
void OutputCTHD_PerPage(TREE_VT t, DS_CT_HD ds_ct_hd, int index);
int Output_ListCTHD(TREE_VT t, HOA_DON& hd, CHI_TIET_HOA_DON& cthd, int& tttrang, NHAN_VIEN* nv);
int ChooseItems_CTHD(TREE_VT t,DS_CT_HD &ds_ct_hd,int &tttrang, int tongtrang);
void Update_CTHD(HOA_DON hd, DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd, bool isEdited, TREE_VT t, int& pos);

///////////NHAN VIEN LAP HOA DON///////
NHAN_VIEN* Menu_NV_Lap_HD(DS_NV ds);     //tra ve con tro nhan vien
void Menu_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN *nv);
void Menu_CTHD(TREE_VT t, NHAN_VIEN *nv, HOA_DON &hd);


//////////TIM KIEM VAT TU TRONG MUC LAP HOA DON /////////////////////////
void Menu_Tim_Kiem_VT(TREE_VT t);
void NhapTenVT_TimKiem(string &result, int &ordinal, bool &isSave, bool &isEscape);
int Output_SearchVT_List(NODE_VT* t, int& tttrang);
void Bang_Nhap_Ten_VT(TREE_VT t, subListVT& l, bool& kt);
void OutputsubVT_PerPage(TREE_VT t, subListVT list, int index);
/////////////////IN HOA DON KHOANG NGAY////////////
void NhapNgay2(string &result, int choice, int &ordinal, bool &isSave, bool &isEscape);
void OutputHD_PerPage(DS_NV ds_nv, DS_HD ds_hd_temp, int index);
void OutputCTHD_PerPage(TREE_VT t,DS_CT_HD ds_ct_hd, int index);
void Nhap_Khoang_Ngay(NGAY_LAP_HD &NgayTruoc,NGAY_LAP_HD &NgaySau, bool &isEscape);
void Menu_IN_DS_HD(DS_NV ds_nv);         //al
void Ds_HD_Temp(DS_HD &ds_hd_temp, DS_NV ds_nv);
void Ds_VT_Gia(TREE_VT t,DS_VAT_TU_GIA &ds_vt_gia);
void GiaiPhongVTGia(DS_VAT_TU_GIA &ds_vt_gia);
void Menu_IN_10_VT(TREE_VT t, DS_NV ds_nv);
/////////////////IN DOANH THU TUNG THANG////////////////
void NhapNam(string& result, int& ordinal, bool& isSave, bool& isEscape);
void BangNhapNam(TREE_VT t, DS_NV ds_nv, bool& kt);      //al
/////////////////IN HOA DON THEO MA HOA DON////////////
void NhapTenHD_TimKiem(string &result, int &ordinal, bool &isSave, bool &isEscape);
void Bang_Nhap_Ten_HD(TREE_VT t,DS_NV ds_nv, bool &kt);
int Output_SearchHD_List(TREE_VT t,DS_NV ds_nv);
void Menu_Tim_Kiem_HD(TREE_VT t,DS_NV ds_nv);
string int_to_string(int a);
void GiaiPhongDSHD(DS_HD &ds_hd);
///////////////////NGAY THANG NAM//////////////////////
int KiemTraNam(int yy, int mm);
void SoNgayTrongThang(int yy, int mm, int a[13]);
int KiemTraNgay(int dd, int mm, int yy);
int kiem_tra_truoc_hien_tai(int dd, int mm, int yy);
int kiem_tra_khoang_ngay(ngay_lap_hd ngay_truoc,ngay_lap_hd ngay_sau);
int kiem_tra_ngay_hd(ngay_lap_hd ngay_ht, ngay_lap_hd ngay_truoc, ngay_lap_hd ngay_sau );
//////////////////TRA HANG////////////////////////////
void Menu_Tra_Hang(TREE_VT t, DS_NV ds_nv);
void NhapSoLuongTraHang(string& result, int& ordinal, bool& isSave, bool& isEscape);
void TraHang_CTHD(HOA_DON& hd, DS_NV ds_nv, DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd, bool isEdited, TREE_VT& t, int& pos); //al
bool kiemTraTrangThai(DS_NV ds_nv, HOA_DON hd, CHI_TIET_HOA_DON cthd);
void Bang_Nhap_Ten_HD_Return(TREE_VT t, DS_NV& ds_nv, bool& kt);
int Output_SearchHD_List_Return(TREE_VT t, DS_NV ds_nv);

string int_to_string(int a)
{
	stringstream s;
	s << a;
	string str = s.str();
	return str;
}

int GetPosition(NODE_CTHD* currentNode, NODE_CTHD* pHead) {
	int position = 0;

	// Kiểm tra điều kiện đặc biệt
	if (pHead == NULL || currentNode == NULL) {
		return -1; 
	}

	NODE_CTHD* temp = pHead;
	while (temp != currentNode) {
		temp = temp->next;
		position++;
	}
	return position;
}
NODE_CTHD* GetNodeAtPosition(NODE_CTHD* pHead, int pos) {
	if (pHead == NULL || pos < 0) {
		return NULL;
	}

	NODE_CTHD* currentNode = pHead;
	int currentPos = 0;

	// Duyệt qua danh sách đến khi đạt được vị trí pos
	while (currentNode != NULL && currentPos < pos) {
		currentNode = currentNode->next;
		currentPos++;
	}

	// Kiểm tra xem đã đến cuối danh sách chưa hoặc vị trí pos không hợp lệ
	if (currentNode == NULL || currentPos != pos) {
		return NULL;
	}

	return currentNode;
}
void Output_CTHD(TREE_VT t, CHI_TIET_HOA_DON cthd, int& locate) //ham nay de in ra 1 dong cua chi tiet hoa don
{
	Xoa_OutCTHD_1line(locate);
	gotoxy(xDisplayDS[0] + 3, yDisplay_CTHD[1]  + locate);
	cout << cthd.MAVT;
	gotoxy(xDisplayDS[1] + 1, yDisplay_CTHD[1]  + locate);
	NODE_VT *vt_temp = find_VT(t, cthd.MAVT);
	cout << vt_temp->VT.ten;
	gotoxy(xDisplayDS[2] + 4, yDisplay_CTHD[1]  + locate);
	cout << cthd.so_luong;
	gotoxy(xDisplayDS[3] + 3, yDisplay_CTHD[1]  + locate);
	cout << cthd.thue;
	gotoxy(xDisplayDS[4] + 3, yDisplay_CTHD[1]  + locate);
	cout << cthd.don_gia;

}
void Them_HD_Vao_DS(HOA_DON hd, DS_HD &ds_hd)
{
	NODE_HD *p = new NODE_HD;
	
	p->HD = hd;
	p->next = NULL;
	if (ds_hd.pHead == NULL)
	{
		ds_hd.pHead = ds_hd.pTail = p;
	}
	else 
	{
		ds_hd.pTail->next = p;
		ds_hd.pTail = p;
	}
}
void GiaiPhongDSHD(DS_HD &ds_hd)
{
	NODE_HD *p;
	while(ds_hd.pHead!=NULL)
	{	
		p=ds_hd.pHead;
		ds_hd.pHead=ds_hd.pHead->next;
		delete p;
	}
}
void NhapNgay(string& result, int choice, int& ordinal, bool& isSave, bool& isEscape)
{
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;
	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())

		{
			int kb_hit = _getch();
			// chi nhan chu so
			// chi nhap so luong ton toi da 6 chu so.
			if (((kb_hit >= 48 && kb_hit <= 57))
				&& count < ((choice == 2) ? MAX_NAM : MAX_NGAY) && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(60) << setfill(' ') << " ";
				gotoxy(x, y);
				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				// xay ra 3 truong hop 
				if (choice == 0) // nhap ngay
				{
					if (kb_hit == KEY_UP)
					{
						ordinal = 3;
						return;
					}
					else
					{
						ordinal = 1;
						return;
					}
				}
				else if (choice == 1) // nhap thang
				{
					if (kb_hit == KEY_UP)
					{
						ordinal = 0;
						return;
					}
					else
					{
						ordinal = 2;
						return;
					}
				}
				else if (choice == 2) // nhap nam
				{
					if (kb_hit == KEY_UP)
					{
						ordinal = 1;
						return;
					}
					else
					{
						ordinal = 3;
						return;
					}
				}

			}
			else if (kb_hit == ENTER)
			{
				if (choice == 0)
				{
					ordinal = 1;
					return;
				}
				else if (choice == 1)
				{
					ordinal = 2;
					return;
				}
				else if (choice == 2)
				{
					ordinal = 3;
					return;
				}
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				if (choice == 0 || choice == 1)
				{
					cout << " TOI DA " << MAX_NGAY << " CHU SO !!!";
				}
				else
				{
					cout << " TOI DA " << MAX_NAM << " CHU SO !!!";
				}

				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}
int countds_hd(DS_HD ds)

{	
	int count=0;
	for(NODE_HD *k=ds.pHead;k!=NULL;k=k->next)
	{
		count++;
	}
	return count;
}
int countds_ct_hd(DS_CT_HD ds) {
	int count = 0;
	for (NODE_CTHD* k = ds.pHead; k != NULL; k = k->next)
	{
		count++;
	}
	return count;
}

bool Full_CTHD(DS_CT_HD ds) {
	return countds_ct_hd(ds) == MAX_CT_HD;
}
int Insert_CT_HD(DS_CT_HD& ds, CHI_TIET_HOA_DON cthd)  //THEM VAO SAU
{
	if (Full_CTHD(ds)) {
		return 0;
	}
	NODE_CTHD* p = new NODE_CTHD;

	p->CTHD = cthd;
	p->next = NULL;
	if (ds.pHead == NULL)
	{
		ds.pHead = ds.pTail = p;
	}
	else
	{
		ds.pTail->next = p;
		ds.pTail = p;
	}
	return 1;
}

void Update_CTHD(HOA_DON hd, DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd, bool isEdited, TREE_VT t, int& pos)
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapCTHD[0].length();

	// cac bien luu tru tam thoi
	string MAVT = "VT";
	string so_luong = "";
	string thue = "";
	string don_gia = "";

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 59);  //tao hop thong bao
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapCTHD, 10); //tao bang nhap
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideCTHD, 5); //tao bang huong dan
	if (isEdited) //neu la chinh sua
	{
		// chinh sua thue, so luong, don gia
		MAVT = cthd.MAVT;  //lay ma vat tu
		thue = int_to_string(cthd.thue); //lay thue
		so_luong = int_to_string(cthd.so_luong); //lay so luong
		don_gia = int_to_string(cthd.don_gia); //lay don gia
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3); 
		cout << MAVT;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
		cout << thue;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
		cout << so_luong;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
		cout << don_gia;
	}

	while (true) {

		if (isEdited)
		{

			switch (ordinal)
			{
			case 0: // thue
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
				NhapSoLuongTon(thue, NHAP_THUE_EDITED, ordinal, isSave, isEscape); // nhap thue
				break;
			case 1:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapSoLuongTon(so_luong, NHAP_SO_LUONG_EDITED, ordinal, isSave, isEscape); //nhap so luong
				break;
			case 2:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
				NhapSoLuongTon(don_gia, NHAP_DON_GIA_EDITED, ordinal, isSave, isEscape); //nhap don gia
				break;
			}
		}
		else  // not edited
		{
			switch (ordinal)
			{
			case 0: // nhap ma vat tu
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
				Nhap_Ma_VT(MAVT, ordinal, isSave, isEscape);
				break;
			case 1: // thue
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
				NhapSoLuongTon(thue, NHAP_THUE, ordinal, isSave, isEscape);
				break;
			case 2: // nhap so luong
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapSoLuongTon(so_luong, NHAP_SO_LUONG, ordinal, isSave, isEscape);
				break;
			case 3:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
				NhapSoLuongTon(don_gia, NHAP_DON_GIA, ordinal, isSave, isEscape);
				break;
			}

		}


		// khi nhan f10 hoac esc ham nhap se ket thuc, tien hanh kiem tra
		if (isSave) //neu nhan f10
		{
			// cap nhat lai flag
			isSave = false;

			// kiem tra rong
			if (MAVT.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (thue.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (so_luong.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			else if (don_gia.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 3;
				continue;
			}

			// kiem tra xem ma vat tu co ton tai khong
			if (MAVT.length() != 0)
			{
				NODE_VT* vt_temp = find_VT(t, MAVT); 
				if (vt_temp == NULL)   //neu ma vat tu khong ton tai
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "MA VAT TU KHONG TON TAI !!! ";
					normalBGColor();
					ordinal = 0;
					continue;
				}
				else //neu nhap dung thong tin
				{
					if (!isEdited) //de khi them 2 chi tiet hoa don co cung ma vat tu, thi khong cho them, canh bao cho nguoi dung nen chinh sua
					{
						NODE_CTHD* currentNode = ds_ct_hd.pHead;
						int index = 0; // Vị trí của node trong danh sách liên kết đơn
						while (currentNode != NULL) // Duyệt qua danh sách liên kết đơn
						{
							if (currentNode->CTHD.MAVT == vt_temp->VT.MAVT) // neu tim thay ma vat tu trung 
							{
								// Cập nhật vị trí trùng trong danh sách liên kết đơn
								pos = index; 
								// In thông báo
								for (int i = 0; i < 5; i++)
								{
									SetColor(BLUE);
									gotoxy(X_NOTIFY + 17, Y_NOTIFY);
									Sleep(100);
									cout << "CHI TIET NAY DA CO TRONG HOA DON. HAY CHINH SUA";
									Sleep(500);
								}
								XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
								return;
							}
							// Di chuyển đến node tiếp theo trong danh sách liên kết đơn
							currentNode = currentNode->next;
							index++;
						}
					}
				}

			}

			if (hd.loai == 'x' || hd.loai == 'X')
			{
				if (so_luong.length() != 0) //neu da nhap so luong
				{
					NODE_VT* vt_temp = find_VT(t, MAVT); // tim vat tu
					int so_luong_temp = atoi(so_luong.c_str()); //chuyen so luong tu string sang int
					if (so_luong_temp > vt_temp->VT.so_luong_ton) //neu so luong nhap lon hon so luong ton
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(196);
						cout << "SO LUONG TRONG KHO KHONG DU (CON LAI: " << vt_temp->VT.so_luong_ton << ")."; 
						normalBGColor();
						if (isEdited)
						{
							ordinal = 1;   //quay lai nhap so luong
							continue;
						}
						ordinal = 2;  //nhap so luong
						continue;
					}
				}
			}



			cthd.MAVT = MAVT;
			cthd.thue = atoi(thue.c_str());
			cthd.so_luong = atoi(so_luong.c_str());
			cthd.don_gia = atoi(don_gia.c_str());
			if (!isEdited) // them
			{
				int temp = Insert_CT_HD(ds_ct_hd, cthd);
				if (temp == 0) //kiem tra xem them co thanh cong hay k
				{
					// thong bao ra.
					for (int i = 0; i < 5; i++)
					{
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						Sleep(100);
						cout << "BO NHO DA DAY .KHONG THEM CHI TIET MOI VAO DUOC!";
						Sleep(500);
					}
				}
				else
				{
					// In dong thong bao .
					for (int i = 0; i < 5; i++)
					{
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						Sleep(100);
						cout << "           SUCCESSFULLY !!! ";
					}
				}
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return; //ket thuc qua trinh nhap
		}

		if (isEscape)
		{
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return; //thoat
		}
	}
	ShowCur(false);
}
void Nhap_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN* nv, HOA_DON& hd)
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapHD[0].length();

	// cac bien luu tru tam thoi
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	string ngay = "";
	string thang = "";
	string nam = "";
	uint loai = 3;
	string MAHD;

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 48);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapHD, 12);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideHD, 3);

	MAHD = Tao_Ma_HD(ds_nv);  //tao ma hoa don

	gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
	cout << MAHD;


	// bien kiem tra ngay thang nam de in ra ngay thang nam hien tai
	bool kt_ngay = 1;
	bool kt_thang = 1;
	bool kt_nam = 1;

	while (true) {

		switch (ordinal)
		{

		case 0:
			if (kt_ngay == 1) //neu chua nhap ngay thi lay ngay hien tai
			{
				ngay = int_to_string(ltm.tm_mday);
				kt_ngay = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
			NhapNgay(ngay, NHAP_NGAY, ordinal, isSave, isEscape);
			break;
		case 1:
			if (kt_thang == 1) //neu chua nhap thang thi lay thang hien tai
			{
				thang = int_to_string(1 + ltm.tm_mon);
				kt_thang = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
			NhapNgay(thang, NHAP_THANG, ordinal, isSave, isEscape);
			break;
		case 2:
			if (kt_nam == 1) //neu chua nhap nam thi lay nam hien tai
			{
				nam = int_to_string(1900 + ltm.tm_year);
				kt_nam = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
			NhapNgay(nam, NHAP_NAM, ordinal, isSave, isEscape);
			break;
		case 3:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 11);
			Nhap(loai, NHAP_LOAI, ordinal, isSave, isEscape);
			break;
		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ngay.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (thang.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (nam.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			else if (loai == 3)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 3;
				continue;
			}

			if (atoi(nam.c_str()) > 2000) //kiem tra nam 
			{
				if (atoi(thang.c_str()) > 0 && atoi(thang.c_str()) <= 12) // kiem tra thang
				{
					if (KiemTraNgay(atoi(ngay.c_str()), atoi(thang.c_str()), atoi(nam.c_str())) == 1)
					{

						if (kiem_tra_truoc_hien_tai(atoi(ngay.c_str()), atoi(thang.c_str()), atoi(nam.c_str())) != 1)

						{
							gotoxy(X_NOTIFY + 17, Y_NOTIFY);
							SetColor(BLUE);
							cout << "NHAP THOI GIAN TRUOC HOAC BANG HT";
							normalBGColor();

							// quay lai va dien vao truong du lieu do
							ordinal = 0;
							continue;
						}

					}
					else
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						cout << "DINH DANG NGAY SAI !!!                     ";
						normalBGColor();

						// quay lai va dien vao truong du lieu do
						ordinal = 0;
						continue;
					}
				}
				else
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP THANG KHONG PHU HOP !!!               ";
					normalBGColor();

					// quay lai va dien vao truong du lieu do
					ordinal = 1;
					continue;
				}
			}
			else
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "NHAP NAM KHONG PHU HOP !!!                 ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}


			hd.MAHD = MAHD;
			hd.ngay_lap_hd.Ngay = atoi(ngay.c_str());
			hd.ngay_lap_hd.Thang = atoi(thang.c_str());
			hd.ngay_lap_hd.Nam = atoi(nam.c_str());
			hd.loai = (char)loai;

			// In dong thong bao .
			for (int i = 0; i < 5; i++)
			{
				SetColor(BLUE);
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				Sleep(100);
				cout << "    SUCCESSFULLY !!!                 ";
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			system("cls");
			string fullName = nv->ho + " " + nv->ten;
			// hien thi hoa don vua nhap bang ham displayhd
			//DisplayHD(keyDisplayCTHD, 5, xDisplayDS, int_to_string(nv->MANV), fullName, MAHD, ngay, thang, nam, loai);
			// ve list chi tiet vat tu
			//DisplayCTHD(keyDisplayCTHD, 5, xDisplayDS, yDisplay_CTHD);
			// menu chi tiet hoa do
			Menu_CTHD(t, nv, hd); //sau khi nhap hoa don xong thi chuyen sang menu chi tiet hoa don
			return;
		}

		if (isEscape)
		{
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return;
		}
	}
	ShowCur(false);
}
int Output_ListCTHD(TREE_VT t, HOA_DON& hd, CHI_TIET_HOA_DON& cthd, int& tttrang, NHAN_VIEN* nv)
{
	int choose;
	bool check = false;

	// nCTHD la so CTHD hien co
	int nCTHD = countds_ct_hd(hd.ds_ct_hd);
	// thu tu trang
	int tongtrang;
	tongtrang = (nCTHD / NUMBER_LINES_CTHD) + 1;
	OutputCTHD_PerPage(t, hd.ds_ct_hd, tttrang); //xuat ds cthd ung voi trang hien tai

	int kb_hit;
	int currposMainMenu = -1; // vi tri hien tai cua con tro tren menu
	int nKey = 7;
	do
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0) {
				kb_hit = _getch();
			}
			int pos = -1;
			NODE_CTHD* currentNode = nullptr;
			switch (kb_hit)
			{
			case PAGE_UP: // di ve trang truoc
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputCTHD_PerPage(t, hd.ds_ct_hd, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputCTHD_PerPage(t, hd.ds_ct_hd, tttrang);
				break;

			case KEY_F2: // them
			{

				Update_CTHD(hd, hd.ds_ct_hd, cthd, false, t, pos);  //them chi tiet hoa don bang ham update
				if (pos > -1) // nếu pos > -1 thì có nghĩa là đã tồn tại trong danh sách chi tiết hóa đơn, lúc này tiến hành chỉnh sửa cái đã tồn tại
				{
					int temp = -1; // temp cua pos, de khi dung ham update o duoi khong doi gia tri cua pos
					NODE_CTHD* nodeAtPos = GetNodeAtPosition(hd.ds_ct_hd.pHead, pos);
					if (nodeAtPos != NULL) {
						Update_CTHD(hd, hd.ds_ct_hd, nodeAtPos->CTHD, true, t, temp); //ham ket thuc khi ket thuc qua trinh nhap tu cac ham nhap
					}
				}
				return 1;
			}
			case KEY_F3: // sua
			{
				choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang); //chon vi tri can sua trong danh sach chi tiet hoa don
				if (choose == 999) // Kiểm tra nếu người dùng hủy chọn
				{
					return 1;
				}
				if (choose < countds_ct_hd(hd.ds_ct_hd)) 
				{
					int temp = -1; // temp cua pos, de khi dung ham update o duoi khong doi gia tri cua pos
					NODE_CTHD* nodeAtPos = GetNodeAtPosition(hd.ds_ct_hd.pHead, choose); //tim node tai vi tri choose
					if (nodeAtPos != NULL) {
						Update_CTHD(hd, hd.ds_ct_hd, nodeAtPos->CTHD, true, t, temp); //sua chi tiet hoa don tai vi tri choose
					}
					return 1;
				}
				

				return 1;
			}
			case KEY_F5: // tim kiem vat tu
			{
				Menu_Tim_Kiem_VT(t);
				return 1;
			}

			case KEY_F4: // xoa
			{
				choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang); //chon vi tri can xoa trong danh sach chi tiet hoa don

				int n = countds_ct_hd(hd.ds_ct_hd);
				if (choose < n)
				{
					// Tìm node cần xóa
					NODE_CTHD* nodeToDelete = GetNodeAtPosition(hd.ds_ct_hd.pHead, choose);

					if (nodeToDelete != NULL) {
						// Xóa node
						if (nodeToDelete == hd.ds_ct_hd.pHead) {
							// Nếu node cần xóa là node đầu danh sách
							hd.ds_ct_hd.pHead = nodeToDelete->next;
						}
						else {
							// Nếu node cần xóa không phải là node đầu danh sách
							NODE_CTHD* prevNode = hd.ds_ct_hd.pHead;
							while (prevNode->next != nodeToDelete) {
								prevNode = prevNode->next;
							}
							prevNode->next = nodeToDelete->next;
							if (nodeToDelete == hd.ds_ct_hd.pTail) {
								// Nếu node cần xóa là node cuối danh sách
								hd.ds_ct_hd.pTail = prevNode;
							}
						}

						

						delete nodeToDelete; // Giải phóng bộ nhớ của node bị xóa
					}
				}
				return 1; 
			}

			case KEY_F7: // Thanh toán
			{
				hd.tong_tien = 0;
				
				if (countds_ct_hd(hd.ds_ct_hd) == 0) //neu chua co chi tiet hoa don nao .
				{
					for (int i = 0; i < 5; i++)
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						Sleep(100);
						cout << "HOA DON CHUA NHAP VAT TU !!!";
						Sleep(500);
					}
					normalBGColor();
					continue;
				}

				NODE_CTHD* currentNode = hd.ds_ct_hd.pHead;
				while (currentNode != NULL) //duyet qua danh sach chi tiet hoa don de tinh tong tien
				{
					hd.tong_tien += ((currentNode->CTHD.so_luong * currentNode->CTHD.don_gia) * (1 + ((float)currentNode->CTHD.thue / 100)));
					currentNode = currentNode->next;
				}

				gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
				SetColor(REG_DWORD);
				cout << std::fixed << hd.tong_tien;
				system("pause");

				// Thêm hóa đơn vào danh sách của nhân viên
				Them_HD_Vao_DS(hd, nv->ds_hd);

				// Cập nhật số lượng và tồn kho của vật tư
				Cap_Nhat_Vat_Tu(t, hd, hd.ds_ct_hd);

				return 0;
			}

			case ESC:
			{
				return 0; //thoat
			}
			case KEY_LEFT:

				if (currposMainMenu > 0)//kiem tra xem có phải không ở vị trí đầu không 
				{
					currposMainMenu = currposMainMenu - 1; //di chuyển menu sang trái
				}
				else {
					currposMainMenu = nKey - 2; //neu cur = 0 thi di chuyen den cuoi cung
				}
				//currposMainMenu là vị trí hiện tại của con trỏ trên menu ( không bao gồm ô MENU )
				EffectiveMenu_Hoa_Don(currposMainMenu, 2); //highlight dong chon
				break;

			case KEY_RIGHT: //key right

				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1; //neu chua phai la cuoi thi di chuyen sang phai
				}
				else {
					currposMainMenu = 0;// neu la cuoi cung thi quay lai dau
				}
				EffectiveMenu_Hoa_Don(currposMainMenu, 1); //highlight dong chon
				break;

			case ENTER: //tuong tu nhu may phim F

				switch (currposMainMenu)
				{
				case 0: // them
					Update_CTHD(hd, hd.ds_ct_hd, cthd, false, t, pos);
					if (pos > -1)
					{
						int temp = -1; // temp cua pos
						NODE_CTHD* currentNode = GetNodeAtPosition(hd.ds_ct_hd.pHead, pos);
						Update_CTHD(hd, hd.ds_ct_hd, currentNode->CTHD, true, t, temp);
					}
					return 1;

				case 1: // sua
					choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang);
					gotoxy(100, 35);
					cout << hd.ds_ct_hd.pHead->CTHD.don_gia << hd.ds_ct_hd.pHead->CTHD.thue;
					if (choose < countds_ct_hd(hd.ds_ct_hd))
					{
						int temp = -1; // temp cua pos
						NODE_CTHD* currentNode = GetNodeAtPosition(hd.ds_ct_hd.pHead, choose);
						Update_CTHD(hd, hd.ds_ct_hd, currentNode->CTHD, true, t, temp);
						return 1;
					}
					return 1;

				case 2: // xoa
					choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang);

					if (choose < countds_ct_hd(hd.ds_ct_hd))
					{
						NODE_CTHD* nodeToDelete = GetNodeAtPosition(hd.ds_ct_hd.pHead, choose);
						if (nodeToDelete != NULL) {
							if (nodeToDelete == hd.ds_ct_hd.pHead) {
								// Nếu node cần xóa là node đầu danh sách
								hd.ds_ct_hd.pHead = nodeToDelete->next;
							}
							else {
								// Nếu node cần xóa không phải là node đầu danh sách
								NODE_CTHD* prevNode = hd.ds_ct_hd.pHead;
								while (prevNode->next != nodeToDelete) {
									prevNode = prevNode->next;
								}
								prevNode->next = nodeToDelete->next;
							}

							if (nodeToDelete == hd.ds_ct_hd.pTail) {
								// Nếu node cần xóa là node cuối danh sách
								hd.ds_ct_hd.pTail = NULL;
							}

							delete nodeToDelete; // Giải phóng bộ nhớ của node bị xóa
							
						}
					}
					return 1;
				case 3: // tim kiem vat tu
					Menu_Tim_Kiem_VT(t);
					return 1;
				case 4: // thanh toan
					hd.tong_tien = 0;
					if (countds_ct_hd(hd.ds_ct_hd) == 0)
					{
						for (int i = 0; i < 5; i++)
						{
							gotoxy(X_NOTIFY + 17, Y_NOTIFY);
							SetColor(BLUE);
							Sleep(100);
							cout << "HOA DON CHUA NHAP VAT TU !!!";
							Sleep(500);
						}
						normalBGColor();
						continue;
					}

					currentNode = hd.ds_ct_hd.pHead;
					while (currentNode != NULL)
					{
						hd.tong_tien += ((currentNode->CTHD.so_luong * currentNode->CTHD.don_gia) * (1 + ((float)currentNode->CTHD.thue / 100)));
						currentNode = currentNode->next;

					}

					gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
					SetColor(REG_DWORD);
					cout << fixed << hd.tong_tien << "      " << "An phim bat ky de tiep tuc";
					_getch();

					// Thêm hóa đơn vào danh sách của nhân viên
					Them_HD_Vao_DS(hd, nv->ds_hd);

					// Cập nhật số lượng và tồn kho của vật tư
					Cap_Nhat_Vat_Tu(t, hd, hd.ds_ct_hd);

					return 0;
				case 5: //thoat
					return 0;


				}

			}

		}
		ShowCur(false);
		SetColor(BLACK);
		gotoxy(1, 38);
		cout << "Trang " << tttrang << "/" << tongtrang;
	} while (true);


}


NHAN_VIEN* Menu_NV_Lap_HD(DS_NV ds) //chon nhan vien lap hoa don
{
	clrscr();
	gotoxy(15, 1);
	cout << "~~~CHON NHAN VIEN LAP HOA DON~~~ ";
	normalBGColor();
		
	int nDS = ds.n -1;  //+1
	int choose;

	gotoxy(3, yHotkey );
	SetColor(BLACK);
	cout << "ESC-Thoat, Enter-Chon Nhan Vien Lap ,PgUP, PgDn";
	normalBGColor();

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS/NUMBER_LINES) + 1;

label1:
	XoaMotVung(79, yDisplay, 30, 53);
	DisplayVT(keyDisplayNV, 4, xDisplayDS); //ve bang ds nhan vien 
	OutputNV_PerPage(ds, tttrang); //xuat ds nhan vien theo trang
	int kb_hit;
    do
    {
        if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch(kb_hit)
			{
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputNV_PerPage(ds,tttrang);
				break;
			
			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputNV_PerPage(ds,tttrang);
				break;

			case ESC:
				return NULL;

			default:
				choose = ChooseItems_NV(ds, tttrang, tongtrang);
				if (choose >= ds.n || choose < 0)
					goto label1;
				return ds.ds[choose];			

			}
			
			
		}
    }while (true);
}
void Menu_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN *nv)
{
	clrscr();
	normalBGColor();

    
        clrscr();
		gotoxy(26, 1);
		cout << "~~~ LAP HOA DON ~~~ ";
		
	
		gotoxy(3, yHotkey );
		SetColor(BLACK);
		cout << "ESC-Thoat, F10 - Luu";

		normalBGColor();
		
		HOA_DON hd;
		
		int index = 0;
		string fullName = nv->ho + " " + nv->ten;
								
		DisplayHD(keyDisplayCTHD, 5, xDisplayDS,int_to_string(nv->MANV),fullName,"//","//","//","//",3);  //hien thi hoa don khoi tao ben trai
		Nhap_HD(t, ds_nv, nv,hd); //bang nhap thong tin hoa don
}
void Menu_CTHD(TREE_VT t, NHAN_VIEN *nv, HOA_DON &hd)
{
	int tttrang = 1;
	int esc = 1;

    do
    {
		clrscr();
		// hien thi hoa don vua nhap bang ham displayhd
        DisplayHD(keyBangNhapHD, 5, xDisplayDS,int_to_string(nv->MANV), nv->ho + " " + nv->ten ,hd.MAHD, int_to_string(hd.ngay_lap_hd.Ngay), int_to_string(hd.ngay_lap_hd.Thang), int_to_string(hd.ngay_lap_hd.Nam),hd.loai);
		// ve list chi tiet vat tu
		DisplayCTHD(keyDisplayCTHD, 5, xDisplayDS, yDisplay_CTHD);
		gotoxy(135, yHotkey + 3 );
		SetColor(GREEN);
		cout << "F10-LUU";
		Menu_Hoa_Don(keymenu_hoa_don,7);
		//"MENU CT_HD", "THEM CT |F2", "CHINH SUA CT|F3", "XOA CT|F4", "TIM KIEM MA VT|F5", "THANH TOAN|F7", "THOAT|ESC"
		normalBGColor();
		CHI_TIET_HOA_DON cthd;
		int index = 0;
        
		
		esc = Output_ListCTHD(t, hd, cthd, tttrang, nv); //xuat danh sach chi tiet hoa don, ham chi ket thuc khi an esc hoac f7 (thanh toan)

    }while (esc);
}

////////////////// TIM KIEM VAT TU TRONG LUC LAP HOA DON /////////////////////////////////////////////////
void Menu_Tim_Kiem_VT(TREE_VT t)
{
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

    do
    {
        clrscr();
		gotoxy(26, 1);
		cout << "~~~DANH SACH VAT TU SAU KHI TIM KIEM~~~ ";

		gotoxy(3, yHotkey );
		SetColor(BLACK);
		cout << "ESC-Thoat, F10 - Tim Kiem";

		normalBGColor();

		// cho nay thay doi cau truc DSLK TEMPLIST bang Mang cap phat dong hay hon...

		DisplayVT(keyDisplayVT, 5, xDisplayDS);
		esc = Output_SearchVT_List(t, tttrang);
		

    }while (esc);

}

void addSubVT(subListVT& list, string ten, string MAVT) { // Thêm vật tư vào danh sách con
	if (list.n >= MAX_VT) {
		return; // Hoặc xử lý khi danh sách đầy
	}
	SUBVT* vt = new SUBVT;
	vt->ten = ten;
	vt->MAVT = MAVT;

	// Kiểm tra list.n có vượt quá giới hạn MAX_VT - 1 không
	if (list.n < MAX_VT) {
		list.arr[list.n] = vt;
		list.n++;
	}
	else {
		// Xử lý khi danh sách đã đầy
		delete vt; // Giải phóng bộ nhớ nếu không cần thiết
	}
}

void Create_Sub_Search_List(TREE_VT t, subListVT& l, string Key) { // Tạo danh sách con chứa các vật tư tìm được
	if (t == NULL)
		return;
	Create_Sub_Search_List(t->left, l, Key);
	if (t->VT.ten.find(Key) != string::npos) // Tìm thấy
		addSubVT(l, t->VT.ten, t->VT.MAVT);
	Create_Sub_Search_List(t->right, l, Key);
}
void OutputsubVT_PerPage(TREE_VT t, subListVT list, int index) { // Xuất danh sách con vật tư theo trang
	Xoa_OutNV_29lines();  // Xóa màn hình hiển thị trước đó.
	SetColor(BLACK);
	int locate = 0;   // Đặt vị trí ban đầu để in ra vật tư.
	NODE_VT* temp = NULL;
	index--;  // Điều chỉnh chỉ mục trang (index) để bắt đầu từ 0.

	for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (index + 1); i++) {
		if (i >= static_cast<int>(list.n)) {   // Kiểm tra xem đã hết danh sách hay chưa
			break;
		}
		SUBVT* temp2 = list.arr[i];
		temp = find_VT(t, temp2->MAVT);  // Tìm vật tư trong cây
		if (temp != NULL) {
			Output_VT(temp, locate);  // In ra thông tin vật tư
			locate++;  // Tăng vị trí locate
		}
	}
}
void Clear_Sub_List(subListVT& list) {
    for (int i = 0; i < list.n; ++i) {
        delete list.arr[i];
        list.arr[i] = nullptr; // Set the pointer to null after deletion
    }
    list.n = 0;
}
void NhapTenVT_TimKiem(string& result, int& ordinal, bool& isSave, bool& isEscape) // Hàm nhập tên vật tư khi tìm kiếm
{
    // bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa, chu so  va dau cach
			// chi nhap ten vat tu toi da 19 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57) || kb_hit == SPACE)
				&& count < MAX_TEN_VT && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{	
					ordinal = 0;
					return;	
				}
				else
				{
					ordinal = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 0;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU CHU VA SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}

}
int Output_SearchVT_List(NODE_VT* t, int& tttrang) { // Xuất danh sách vật tư tìm kiếm được theo trang
	subListVT l;
	int currposMainMenu = -1;
	bool kt = false; // Thoát khỏi tìm kiếm
	ShowCur(false);
	Bang_Nhap_Ten_VT(t, l, kt);
	// nNV là số NV hiện có trong cây
	int nVT = l.n;

	// Thứ tự trang
	int tongtrang;
	tongtrang = (nVT / NUMBER_LINES) + 1;
	OutputsubVT_PerPage(t, l, tttrang);
	ShowCur(false);
	if (!kt) {
		_getch(); // Dừng màn hình
	}

	Clear_Sub_List(l);
	if (kt) {
		return 0;
	}
	else {
		return 1;
	}
}

void Bang_Nhap_Ten_VT(TREE_VT t, subListVT& l, bool& kt) {
	ShowCur(true);
	normalBGColor();

	int ordinal = 0;
	bool isSave = false; // thực hiện tìm kiếm
	bool isEscape = false;

	// chiều dài bảng nhập 
	int nngang = (int)keyBangNhapTimKiemVT[0].length();

	// biến key để tìm kiếm những vật tư có tên chứa key
	string key = "";
	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapTimKiemVT, 4);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideTimKiemVT, 3);

	while (true) {
		switch (ordinal) {
		case 0:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
			NhapTenVT_TimKiem(key, ordinal, isSave, isEscape); //thoat ham khi f10 hoac esc
			break;
		}

		if (isSave) { //neu nhan f10
			isSave = false;

			// kiểm tra rỗng
			if (key.length() == 0) {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lại và điền vào trường dữ liệu đó
				ordinal = 0;
				continue;
			}

			// thêm thuật toán tìm kiếm cây lấy những vật tư có ký tự là Key
			Create_Sub_Search_List(t, l, key);
			for (int i = 0; i < 5; i++) {
				SetColor(BLUE);
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				Sleep(100);
				cout << "           SUCCESSFULLY !!! ";
			}
			return;
		}

		if (isEscape) { // nếu nhấn ESC
			kt = true;
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
string Tao_Ma_HD(DS_NV ds_nv)
{
	bool kt_hd = false;

	// duyệt qua từng nhân viên, coi đã có nhân viên nào lập hoá đơn chưa, nếu có thì tạo mã hoá đơn mới
	for (int i = 0; i < ds_nv.n; i++)
		{
		if (ds_nv.ds[i]->ds_hd.pHead != NULL) {
			kt_hd = true;
			break;
			}
		}
	   // nếu có, tạo danh sách liên kết đơn tạm để nối tất cả hoá đơn đó lại, duyệt tìm mã hoá đơn max
	if(kt_hd)
	{
		DS_HD ds_hd_temp;
		// lay toan bo hoa don dang co cua moi nhan vien
		for (int i = 0; i < ds_nv.n; i++)
		{
			if (ds_nv.ds[i]->ds_hd.pHead != NULL) {
				NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
				while (p != NULL) {
					Them_HD_Vao_DS(p->HD, ds_hd_temp);
						p = p->next;
					}
			}
		}


		// tim max
		string max_temp = ds_hd_temp.pHead->HD.MAHD.substr(2); // lay tu sau HD tro ve
		// duyet tung thang de so sanh voi max
		for (NODE_HD *n = ds_hd_temp.pHead; n != NULL; n = n->next)
		{
			string cur = n->HD.MAHD.substr(2);
			
			if (atoi(max_temp.c_str()) < atoi(cur.c_str()))
			{
				max_temp = cur;
			}
		}
		max_temp = int_to_string(atoi(max_temp.c_str()) + 1);
		// ket qua
		string result = "HD" + max_temp;
		return result;

	}
	else // nếu không, cho mã hoá đơn của nó là HD0
	{
		string result = "HD0";
		return result;
	}
	
}
//============================IN HOA DON KHOANG NGAY================
void OutputHD_PerPage(DS_NV ds_nv,DS_HD ds_hd_temp, int index)
{
	ShowCur(false);
    Xoa_OutDSHD_29lines();
    SetColor(BLACK);
    locate = 0;
    index--;
	
    NODE_HD *p=ds_hd_temp.pHead;
	for (int i = 1; i <= NUMBER_LINES * index; i++) p = p->next;//duyet den vi tri can xuat, vi du nhu index = 1 thi p se la pHead, i =1 vi se khong thay doi p -> p->next
    for(int i = NUMBER_LINES * index ; p!=NULL && i < NUMBER_LINES *(index + 1) ; i++ ) // duyet vi tri trong trang de in
		{
			Xoa_OutDSHD_1line(locate); // xoa dong de in dong moi
			gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
			cout << p->HD.MAHD;
			gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
			cout << p->HD.ngay_lap_hd.Ngay<<"/"<<p->HD.ngay_lap_hd.Thang<<"/"<<p->HD.ngay_lap_hd.Nam;
			gotoxy(xDisplayDS[2] + 4, yDisplay + 3 + locate);
			(p->HD.loai== 'X' || p->HD.loai == 'x')?cout<<"XUAT":cout<<"NHAP";
			gotoxy(xDisplayDS[3] + 2, yDisplay + 3 + locate);
			NHAN_VIEN* q = Find_NV(ds_nv, p); // tim nhan vien co hoa don nay
			cout<<q->ho<<" "<<q->ten;
			gotoxy(xDisplayDS[3] + 28, 2 + 3 + locate);
			cout<< p->HD.tong_tien;
			locate++;
			p = p->next; // chuyen sang phan tu ke tiep
		}
    
}
NHAN_VIEN* Find_NV(DS_NV ds_nv, NODE_HD* node_hd) // tim nhan vien co hoa don này trong danh sách nhân viên
{	
	string b=node_hd->HD.MAHD.substr(2);
	for(int i=0 ; i<ds_nv.n; i++ )
	{
		if(ds_nv.ds[i]->ds_hd.pHead!=NULL)
				{
					NODE_HD *p=ds_nv.ds[i]->ds_hd.pHead;
					for(p;p!=NULL;p=p->next)
					{	
						string a=p->HD.MAHD.substr(2);
						
						if(atoi(a.c_str())==atoi(b.c_str()))
						{
							return ds_nv.ds[i];
						}
					}
				}
		
	}							
}
void OutputCTHD_PerPage(TREE_VT t,DS_CT_HD ds_ct_hd, int index)
{
	ShowCur(false);
	Xoa_OutCTHD_18lines();
	SetColor(BLACK);
	locate = 0;
	index--;
	int n = countds_ct_hd(ds_ct_hd);
	if (n==0)
		return;
	NODE_CTHD* TMP = ds_ct_hd.pHead;
	for (int i = 1; i <= NUMBER_LINES_CTHD * index; i++) TMP = TMP->next;
	for (int i = NUMBER_LINES_CTHD * index; TMP != NULL && i < NUMBER_LINES_CTHD * (index + 1); i++) {
		if (TMP == NULL) break; // Kiểm tra nếu p là NULL thì thoát vòng lặp
		Output_CTHD(t, TMP->CTHD,locate); // Gọi hàm xuất chi tiết hóa đơn
		locate++; // Tăng vị trí để in chi tiết hóa đơn tiếp theo
		TMP = TMP->next; // Di chuyển con trỏ đến chi tiết hóa đơn tiếp theo
	}
	//ở đây có thể dùng hàm getNode để lấy node ở vị trí index, sau đó xuất chi tiết hóa đơn từ node đó, nhưng cách này sẽ tốn thời gian hơn
	//NODE_CTHD* curNode = GetNodeAtPosition(ds_ct_hd.pHead, i);
	//Output_CTHD(t, curNode->CTHD);
}


//============================nhapngaythangnam=================
int KiemTraNam(int yy, int mm) { // kiem tra nam nhuan
	bool check;
	if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
		check = 0;
	}
	else check = 1;
	return check;
}
void SoNgayTrongThang(int yy, int mm, int a[13]) { // tinh so ngay trong thang
	int i;
	for (i = 1; i <= 12; i++) {
		if (i <= 7)
			if (i % 2 != 0) a[i] = 31;
			else a[i] = 30;
		if (i >= 8)
			if (i % 2 == 0) a[i] = 31;
			else a[i] = 30;
		if (i == 2)
			if (KiemTraNam(yy, mm) == 0) a[i] = 29;
			else a[i] = 28;
	}
}
int KiemTraNgay(int dd, int mm, int yy) { // kiem tra ngay hop le
	bool check;
	int a[13];
	SoNgayTrongThang(yy, mm, a);
	if (dd <= a[mm] && dd > 0)
		check = 1;
	else check = 0;
	return check;
}
int kiem_tra_truoc_hien_tai(int dd, int mm, int yy)
{

time_t now = time(0);
    tm ltm;
	localtime_s(&ltm, &now); // convert now to tm struct for UTC
	int ddht = ltm.tm_mday;  /// lay ngay hien tai
	int mmht = 1 + ltm.tm_mon; // lay thang hien tai
	int yyht = 1900 + ltm.tm_year; // lay nam hien tai

	if (yy < yyht) return 1; //neu nam nho hon nam hien tai
	else if (yy == yyht) // neu nam bang nam hien tai
	{
		if (mm < mmht) return 1; //neu thang nho hon thang hien tai 
		else if (mm == mmht) if (dd <= ddht) return 1; else return -1;
	}
	return -1;

}
int kiem_tra_nam_lon_hon_hien_tai(int yy)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now); // convert now to tm struct for UTC
	int yyht = 1900 + ltm.tm_year; // lay nam hien tai

	if (yy <= yyht) return 1; // neu nam nho hon hoac bang nam hien tai
	return -1; // neu nam lon hon 
}

int kiem_tra_khoang_ngay(ngay_lap_hd ngay_truoc, ngay_lap_hd ngay_sau)//kiem tra ngay truoc co nho hon ngay sau khong
{
	if (ngay_truoc.Nam < ngay_sau.Nam) return 1;
	else if (ngay_truoc.Nam == ngay_sau.Nam)
	{
		if (ngay_truoc.Thang < ngay_sau.Thang) return 1;
		else if (ngay_truoc.Thang == ngay_sau.Thang) if (ngay_truoc.Ngay <= ngay_sau.Ngay) return 1; else return -1;
	}
	return -1;
}
int kiem_tra_ngay_hd(ngay_lap_hd ngay_ht, ngay_lap_hd ngay_truoc, ngay_lap_hd ngay_sau)// kiem tra ngay hop le
{
	if(kiem_tra_khoang_ngay(ngay_truoc,ngay_ht)==1 && kiem_tra_khoang_ngay(ngay_ht,ngay_sau)==1)
	return 1;
	else 
	return -1;
}
int daysBetweenDates(tm a, tm b) {
	// Chuyển đổi cả hai ngày sang dạng time_t
	time_t timeA = mktime(&a);
	time_t timeB = mktime(&b);

	// Tính sự khác biệt giữa hai ngày và chuyển đổi từ giây sang ngày
	double difference = difftime(timeB, timeA) / (60 * 60 * 24);
	return static_cast<int>(difference);
}

int kiem_tra_dieu_kien_tra_hang(ngay_lap_hd ngay_lap) {
	// Lấy ngày hiện tại
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now); // Chuyển đổi now sang tm struct

	// Tạo một đối tượng tm cho ngày lập hóa đơn
	tm ngay_lap_tm = {};
	ngay_lap_tm.tm_mday = ngay_lap.Ngay;
	ngay_lap_tm.tm_mon = ngay_lap.Thang - 1; // Tháng trong tm bắt đầu từ 0
	ngay_lap_tm.tm_year = ngay_lap.Nam - 1900; // Năm trong tm bắt đầu từ 1900

	// Tính sự khác biệt giữa hai ngày
	int diffDays = daysBetweenDates(ngay_lap_tm, ltm);

	// Kiểm tra điều kiện trả hàng
	if (diffDays <= 3) {
		return 1;
	}
	else {
		return 0;
	}
}
//=============================NGAY========================
void NhapNgay2(string &result, int choice, int &ordinal, bool &isSave, bool &isEscape)
{
	 // bien dem so chu da duoc nhap vao cho result
	 int x, y;
	x = wherex();
	y = wherey();
	XoaMotDong(5);
	gotoxy(x,y);
	cout << result;
	int count = (int)result.length();
	
	// bien co hieu
	int nSpace = 0;

	while (true)
	{
		
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu so
			// chi nhap so luong ton toi da 6 chu so.
			
			if (((kb_hit >= 48 && kb_hit <= 57))
				&& count < ((choice == 2 || choice == 5) ? MAX_NAM : MAX_NGAY) && count >= 0) //neu choice bang 2 hoac 5 thi nhap nam, con lai nhap ngay, thang
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(60) << setfill(' ') << " ";
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE) 
				{
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch(); //neu khong getch thi kb_hit se la cai phim minh an luc dau
				// xay ra 3 truong hop 
				if (choice == 0) // nhap ngay
				{
					if (kb_hit == KEY_LEFT)
					{
						ordinal = 2; // nhay ve nam
						return;
					}
					else
					{	
						ordinal = 1; // nhay ve thang
						return;
					}
				}
				else if (choice == 1) // nhap thang
				{
					if (kb_hit == KEY_LEFT) // nhap ngay 
					{
						ordinal = 0;
						return;
					}
					else // nhap nam 
					{
						ordinal = 2;
						return;
					}
				}
				else if (choice == 2) // nhap nam
				{
					if (kb_hit == KEY_LEFT)
					{
						ordinal = 1; // nhap thang 
						return;
					}
					else
					{
						ordinal = 0; // nhap ngay 
						return;
					}
				}
				else if (choice == 3) // nhap ngay o duoi
				{
					if (kb_hit == KEY_LEFT) // nhap nam o duoi 
					{
						ordinal = 5;
						return;
					} 
					else // nhap thang o duoi
					{
						ordinal = 4;
						return;
					}
				}
				else if (choice == 4) // nhap thang o duoi 
				{
					if (kb_hit == KEY_LEFT) // nhap ngay o duoi
					{
						ordinal = 3;
						return;
					}
					else // nhap nam o duoi 
					{
						ordinal = 5;
						return;
					}
				}
				else if (choice == 5) // nhap nam
				{
					if (kb_hit == KEY_LEFT) // nhap thang o duoi 
					{
						ordinal = 4;
						return;
					}
					else
					{
						ordinal = 3; // nhap ngay o duoi
						return;
					}
				}
 				
			}
			else if (kb_hit == ENTER) //neu nhan enter
			{
				if (choice == 0)
				{
					ordinal = 3;
					return;
				}
				else if (choice == 1)
				{
					ordinal = 4;
					return;
				}
				else if (choice == 2)
				{
					ordinal = 5;
					return;
				}
				else if (choice == 3)
				{
					ordinal = 0;
					return;
				}
				else if (choice == 4)
				{
					ordinal = 1;
					return;
				}
				else if (choice == 5)
				{
					ordinal = 2;
					return;
				}
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				if (choice == 0 || choice == 1)
				{
					cout << " TOI DA "<< MAX_NGAY << " CHU SO !!!"; 
				}
				else 
				{
					cout << " TOI DA "<< MAX_NAM << " CHU SO !!!"; 
				}
				           
				normalBGColor();
				gotoxy(x, y);
				
			}
		}

	}
}
///////////////////////////////////////////   IN HD   ////////////////////////////////////////////////


void Nhap_Khoang_Ngay(NGAY_LAP_HD &NgayTruoc,NGAY_LAP_HD &NgaySau, bool &isEscape) 
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapHD[0].length();

	// cac bien luu tru tam thoi
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	string ngaytruoc = "",thangtruoc="",namtruoc="";
	string ngaysau="",thangsau="",namsau="";
	uint loai=3;
	string MAHD;
	// tao box 
	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 48);
	// ve bang nhap
	BangNhap(xDisplayDS[5] + 5, yDisplay, nngang, keyBangNhapHD1, 7);

		// so lan quay lai nhap ngay, thang, nam
		bool kt_ngay = 1;
		bool kt_thang = 1;
		bool kt_nam = 1;
		bool kt_ngay2 = 1;
		bool kt_thang2 = 1;
		bool kt_nam2 = 1;
	
	while (true) {
			
			switch (ordinal)
			{
			
			case 0: // nhap ngay truoc
				if (kt_ngay == 1)
				{	
					ngaytruoc = int_to_string(ltm.tm_mday);
					kt_ngay = 0;
				}
				gotoxy((xDisplayDS[5] + 7 + nngang / 3), yDisplay + 4);
				NhapNgay2(ngaytruoc,NHAP_NGAY, ordinal, isSave, isEscape);
				break;
			case 1: // nhap thang truoc
				if (kt_thang == 1)
				{
					thangtruoc =int_to_string(1 + ltm.tm_mon);
					kt_thang = 0;
				}
				
				gotoxy((xDisplayDS[5] + 7 + nngang / 2+2), yDisplay + 4);
				NhapNgay2(thangtruoc,NHAP_THANG, ordinal, isSave, isEscape);
				break;
			case 2: // nhap nam truoc
				if (kt_nam == 1)
				{
					namtruoc = int_to_string(1900 + ltm.tm_year);
					kt_nam = 0;
				}
				gotoxy((xDisplayDS[5] + 7 + nngang / 2+10), yDisplay + 4);
				NhapNgay2(namtruoc,NHAP_NAM, ordinal, isSave, isEscape);
				break;
			case 3: // nhap ngay sau
				if (kt_ngay2 == 1)
				{	
					ngaysau = int_to_string(ltm.tm_mday);
					kt_ngay2 = 0;
				}
				gotoxy((xDisplayDS[5] + 7 + nngang / 3), yDisplay + 6);
				NhapNgay2(ngaysau,3, ordinal, isSave, isEscape);
				break;
			case 4: // nhap thang sau
				if (kt_thang2 == 1)
				{
					thangsau =int_to_string(1 + ltm.tm_mon);
					kt_thang2 = 0;
				}
				
				gotoxy((xDisplayDS[5] + 7 + nngang / 2+2), yDisplay + 6);
				NhapNgay2(thangsau,4, ordinal, isSave, isEscape);
				break;
			case 5: // nhap nam sau
				if (kt_nam2 == 1)
				{
					namsau = int_to_string(1900 + ltm.tm_year);
					kt_nam2 = 0;
				}
				gotoxy((xDisplayDS[5] + 7 + nngang / 2+10), yDisplay + 6);
				NhapNgay2(namsau,5, ordinal, isSave, isEscape);
				break;	

			}
		
		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ngaytruoc.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (thangtruoc.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (namtruoc.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			if (atoi(namtruoc.c_str()) > 2000) // kiem tra nam truoc co hop le k
			{
				if (atoi(thangtruoc.c_str()) > 0 && atoi(thangtruoc.c_str()) <= 12)  // kiem tra thang truoc co hop le k 
				{
					if (KiemTraNgay(atoi(ngaytruoc.c_str()), atoi(thangtruoc.c_str()), atoi(namtruoc.c_str())) == 1) //kiem tra ngay truoc co hop le k
					{

						if (kiem_tra_truoc_hien_tai(atoi(ngaytruoc.c_str()), atoi(thangtruoc.c_str()), atoi(namtruoc.c_str())) != 1) // kiem tra ngay truoc co nho hon ngay hien tai k
						
							{
								gotoxy(X_NOTIFY + 17, Y_NOTIFY);
								SetColor(BLUE);
								cout << "NHAP THOI GIAN TRUOC HOAC BANG HT";
								normalBGColor();

								// quay lai va dien vao truong du lieu do
								ordinal = 0;
								continue;
							}
							
					}
					else 
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						cout << "DINH DANG NGAY SAI !!!                     ";
						normalBGColor();

							// quay lai va dien vao truong du lieu do
						ordinal = 0;
						continue;
					}
				}
				else 
					{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP THANG KHONG PHU HOP !!!               ";
					normalBGColor();

					// quay lai va dien vao truong du lieu do
					ordinal = 1;
					continue;
					}
			} else 
				{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout<<"NHAP NAM KHONG PHU HOP !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
				}

			if(atoi(namsau.c_str())>2000)
			{
				if (atoi(thangsau.c_str()) > 0 && atoi(thangsau.c_str()) <= 12) 
				{
					if (KiemTraNgay(atoi(ngaysau.c_str()), atoi(thangsau.c_str()), atoi(namsau.c_str())) == 1)
					{

							if (kiem_tra_truoc_hien_tai(atoi(ngaysau.c_str()), atoi(thangsau.c_str()), atoi(namsau.c_str())) != 1)
						
							{
								gotoxy(X_NOTIFY + 17, Y_NOTIFY);
								SetColor(BLUE);
								cout << "NHAP THOI GIAN TRUOC HOAC BANG HIEN TAI !!!";
								normalBGColor();

								// quay lai va dien vao truong du lieu do
								ordinal = 3;
								continue;
							}
							
					}
					else 
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						cout << "DINH DANG NGAY SAI !!!                     ";
						normalBGColor();

							// quay lai va dien vao truong du lieu do
						ordinal = 3;
						continue;
					}
				}
				else 
					{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP THANG KHONG PHU HOP !!!               ";
					normalBGColor();

					// quay lai va dien vao truong du lieu do
					ordinal = 4;
					continue;
					}
			} else 
				{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout<<"NHAP NAM KHONG PHU HOP !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 5;
				continue;
				}
			

			// chuyen doi du lieu
			NgayTruoc.Ngay = atoi(ngaytruoc.c_str());
			NgayTruoc.Thang = atoi(thangtruoc.c_str());
			NgayTruoc.Nam = atoi(namtruoc.c_str());
			NgaySau.Ngay = atoi(ngaysau.c_str());
			NgaySau.Thang = atoi(thangsau.c_str());
			NgaySau.Nam = atoi(namsau.c_str());
			if(kiem_tra_khoang_ngay(NgayTruoc,NgaySau)==-1)
			 {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout<<"HAI MOC THOI GIAN KHONG PHU HOP !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			// In dong thong bao .
			for (int i = 0; i < 5; i++)
			{
					SetColor(BLUE);
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					Sleep(100);
					cout << "           SUCCESSFULLY !!! ";
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			system("cls");
			return;
		}

		if (isEscape)
		{
			clrscr();
			return;
		}
	}
	ShowCur(false);
}
void Menu_IN_DS_HD(DS_NV ds_nv) // in danh sach hoa don theo khoang ngay
{
	NGAY_LAP_HD NgayTruoc,NgaySau;
    clrscr();
	gotoxy(3, yHotkey );
	SetColor(BLACK);
	cout << "ESC-Thoat, F10 - Tim Kiem";
	normalBGColor();
	HOA_DON hd;
	int index = 0;
	bool isEscape = false;
	Nhap_Khoang_Ngay(NgayTruoc, NgaySau, isEscape); // nhap khoang ngay
    if(isEscape)
		return;

	DS_HD ds_hd_temp;
	if (ds_nv.n == 0) // neu danh sach nhan vien rong
	{
		return;
	}
	for (int i = 0; i < ds_nv.n; i++) // duyet qua tat ca nhan vien
    {	
		NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead; // lay danh sach hoa don cua nhan vien
		for (p; p != NULL; p = p->next) // duyet qua tat ca hoa don cua nhan vien
		{
			if (kiem_tra_ngay_hd(p->HD.ngay_lap_hd, NgayTruoc, NgaySau) == 1) // kiem tra hoa don co nam trong khoang ngay can tim k
			{
				Them_HD_Vao_DS(p->HD,ds_hd_temp);
			}
		}
    }
	NODE_HD *p=ds_hd_temp.pHead;
	for (p; p != NULL; p = p->next) // sap xep lai danh sach hoa don theo ngay lap hoa don
		{
			for(NODE_HD *q=p->next;q!=NULL;q=q->next)
			{
				if (kiem_tra_khoang_ngay(p->HD.ngay_lap_hd, q->HD.ngay_lap_hd) == -1) // neu ngay lap hoa don p lon hon ngay lap hoa don q thi doi cho
				{
					HOA_DON temp=p->HD;
					p->HD=q->HD;
					q->HD=temp;

				}
			}
		}

	int nDS=countds_hd(ds_hd_temp);
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS/NUMBER_LINES) + 1;  

	clrscr();
	normalBGColor();
	gotoxy(26, 1);
	cout << "BANG LIET KE DANH SACH HOA DON "<<"TU NGAY : "<<NgayTruoc.Ngay<<"/"<<NgayTruoc.Thang<<"/"<<NgayTruoc.Nam<<" DEN NGAY: "<<NgaySau.Ngay<<"/"<<NgaySau.Thang<<"/"<<NgaySau.Nam;
	gotoxy(3, yHotkey );
	SetColor(BLACK);
	cout << "ESC-Thoat";
	DisplayVT(keyDisplayHD, 5, xDisplay_IN_DS_HD); // in ra ten cot, bang danh sach hoa don
	OutputHD_PerPage(ds_nv, ds_hd_temp, tttrang); // in ra danh sach hoa don theo trang
	do
	{
		if(_kbhit())
		{
			int kbhit=_getch();
			switch(kbhit)
			{
				case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputHD_PerPage(ds_nv,ds_hd_temp,tttrang);
				break;
			
			    case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputHD_PerPage(ds_nv,ds_hd_temp,tttrang);
				break;
				case ESC: 
					GiaiPhongDSHD(ds_hd_temp); // giai phong danh sach hoa don tam 
				return ;
			}
		}
		ShowCur(false);
        gotoxy(3, 36);
        cout<<"Trang "<<tttrang<<" /"<<tongtrang<<"  "<<"PagUP-Trang Truoc, PagDn-Trang Sau";
	}while(1);
	
	system("pause");
}
void Ds_HD_Temp(DS_HD& ds_hd_temp, DS_NV ds_nv) // tao danh sach hoa don tam, chua hoa don cua tat ca nhan vien

{
	for(int i=0;i<ds_nv.n;i++)
	{
		NODE_HD *p=ds_nv.ds[i]->ds_hd.pHead;
		for(p;p!=NULL;p=p->next)
		{
			Them_HD_Vao_DS(p->HD,ds_hd_temp);
		}
	}
}
void Ds_VT_Gia(TREE_VT t, DS_VAT_TU_GIA& ds_vt_gia) // tao danh sach vat tu gia, chua gia cua tat ca vat tu
{
	if(t==NULL) return;
	else
	{
		Ds_VT_Gia(t->left,ds_vt_gia);
		VAT_TU_GIA *p=new VAT_TU_GIA;
		p->MAVT=t->VT.MAVT;
		ds_vt_gia.ds[ds_vt_gia.n++]=p;
		Ds_VT_Gia(t->right,ds_vt_gia);
	}
}
void GiaiPhongVTGia(DS_VAT_TU_GIA &ds_vt_gia)
{
	for(int i=0;i<ds_vt_gia.n;i++)
	{
		delete ds_vt_gia.ds[i];
	}
}
//10 vat tu co doanh thu cao nhat ====================================
void Menu_IN_10_VT(TREE_VT t, DS_NV ds_nv)
{	
	NODE_HD *p;
	DS_HD ds_hd_temp;
	ngay_lap_hd NgayTruoc,NgaySau;
	DS_VAT_TU_GIA ds_vt_gia_loi,ds_vt_gia_nhap,ds_vt_gia_xuat;
	gotoxy(3, yHotkey );
	SetColor(BLACK);
	cout << "ESC-Thoat, F10 - Tim Kiem";
	
	Ds_HD_Temp(ds_hd_temp,ds_nv);
	Ds_VT_Gia(t,ds_vt_gia_loi);
	Ds_VT_Gia(t,ds_vt_gia_nhap);
	Ds_VT_Gia(t,ds_vt_gia_xuat);
	



	bool isEscape = false;
	Nhap_Khoang_Ngay(NgayTruoc,NgaySau, isEscape);

	if(isEscape)
		return;
	
	for (NODE_HD* p = ds_hd_temp.pHead; p != NULL; p = p->next) // duyet qua tat ca hoa don
	{
		if (kiem_tra_ngay_hd(p->HD.ngay_lap_hd, NgayTruoc, NgaySau) == 1) // kiem tra hoa don co nam trong khoang ngay can tim k
		{
			if (p->HD.loai == 'N' || p->HD.loai == 'n') // neu hoa don la hoa don nhap
			{	
				for(int j=0;j<ds_vt_gia_nhap.n;j++) // duyet tat ca cac vat tu 
				
				{	string b=ds_vt_gia_nhap.ds[j]->MAVT.substr(2);
					for(NODE_CTHD* curNode = p->HD.ds_ct_hd.pHead;curNode != NULL;curNode = curNode->next) //dueyet tat ca cac cthd co trong hoa don p 
					{	
						string a=curNode->CTHD.MAVT.substr(2);
						
						if(atoi(a.c_str())==atoi(b.c_str())) //neu vat tu j co trong hoa don p
						{	
						
							ds_vt_gia_nhap.ds[j]->gia += (curNode->CTHD.so_luong * curNode->CTHD.don_gia * (1 + (double)curNode->CTHD.thue / 100)); //cap nhat tong nhap cua vat tu j
							
							
						}


					}
				}
			}
			else // hoa don xuat
			{	
				for(int j=0;j<ds_vt_gia_xuat.n;j++) // duyet tat ca vat tu 
				
				{	string b=ds_vt_gia_xuat.ds[j]->MAVT.substr(2);
						
				for (NODE_CTHD* curNode = p->HD.ds_ct_hd.pHead; curNode != NULL; curNode = curNode->next) //dueyet tat ca cac cthd co trong hoa don p
					{	
						string a=curNode->CTHD.MAVT.substr(2);
						
						if(atoi(a.c_str())==atoi(b.c_str()))
						{	
						
							ds_vt_gia_xuat.ds[j]->gia += (curNode->CTHD.so_luong * curNode->CTHD.don_gia * (1 + (double)curNode->CTHD.thue / 100)); //cap nhat tong xuat cua vat tu j
							
						}
					}
				}
			}

		}
	}
	

	

	for(int i=0;i<ds_vt_gia_loi.n;i++)
	{
	if(ds_vt_gia_nhap.ds[i]->gia<ds_vt_gia_xuat.ds[i]->gia) // tinh loi nhuan cua vat tu i(tong xuat - tong nhap )
	ds_vt_gia_loi.ds[i]->gia=ds_vt_gia_xuat.ds[i]->gia-ds_vt_gia_nhap.ds[i]->gia;
	}


	for (int i = 0; i < ds_vt_gia_loi.n; i++) // sap xep lai danh sach vat tu theo loi nhuan giam dan
	{
		for(int j=i;j<ds_vt_gia_loi.n;j++)
		{
			if(ds_vt_gia_loi.ds[i]->gia<ds_vt_gia_loi.ds[j]->gia)
			{
				VAT_TU_GIA *temp;
				temp=ds_vt_gia_loi.ds[i];
				ds_vt_gia_loi.ds[i]=ds_vt_gia_loi.ds[j];
				ds_vt_gia_loi.ds[j]=temp;
			}
		}
	}
	ShowCur(false);

	locate=0;
	gotoxy(2,1);
	cout<<"TOP 10 VAT TU CO DOANH THU CAO NHAT TRONG KHOANG THOI GIAN "<<"TU NGAY : "<<NgayTruoc.Ngay<<"/"<<NgayTruoc.Thang<<"/"<<NgayTruoc.Nam<<" DEN NGAY: "<<NgaySau.Ngay<<"/"<<NgaySau.Thang<<"/"<<NgaySau.Nam;
	gotoxy(3, yHotkey );
	SetColor(BLACK);
	cout << "ESC-Thoat";
	DisplayVT(keyDisplayTop10, 3, xDisplayTop10);
	for(int i=0;i<ds_vt_gia_loi.n && i<10;i++)
	{
		if (ds_vt_gia_loi.ds[i]->gia == 0) continue;
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
	cout<<ds_vt_gia_loi.ds[i]->MAVT;

	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout<<find_VT(t,ds_vt_gia_loi.ds[i]->MAVT)->VT.ten;

	gotoxy(xDisplayDS[2] + 2, yDisplay + 3 + locate);
	cout<<ds_vt_gia_loi.ds[i]->gia;

	locate++;
	}
	GiaiPhongVTGia(ds_vt_gia_loi);
	GiaiPhongVTGia(ds_vt_gia_nhap);
	GiaiPhongVTGia(ds_vt_gia_xuat);
	gotoxy(100,35);
	cout<<endl;
	ShowCur(false);
	int kb_hit;
	while (_kbhit) {
		kb_hit = _getch();
		if (kb_hit == ESC) {
			clrscr();
			return;
		}
	}
	
}
//-----------------------------------DOANH THU TUNG THANG TRONG NAM-------------------------------------
void Menu_Doanh_Thu_Tung_Thang(TREE_VT t, DS_NV ds_nv) {
	gotoxy(3, yHotkey);
	SetColor(BLACK);
	cout << "ESC-Thoat, F10 - Tim Kiem";
	bool kt = false;
	BangNhapNam(t,ds_nv, kt);
	if (kt) {
		return;
	}
}


void NhapTenHD_TimKiem(string &result, int &ordinal, bool &isSave, bool &isEscape)
{
    // bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	
	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa, chu so  va dau cach
			// chi nhap ten vat tu toi da 19 ky tu.
			if ((kb_hit >= 48 && kb_hit <= 57) && count < MAX_TEN_VT && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				count++;
				cout << (char)kb_hit;
				result += (char)kb_hit;

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{	
					ordinal = 0;
					return;	
				}
				else
				{
					ordinal = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 0;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}

}
void Bang_Nhap_Ten_HD(TREE_VT t,DS_NV ds_nv, bool &kt)
{
	ShowCur(true);
	normalBGColor();

	int ordinal = 0;
	bool isSave = false; // tien hanh tim kiem
	bool isEscape = false;
	bool found = false;

	// chieu dai bang nhap 
	int nngang = (int)keyBangNhapTimKiemHD[0].length();

	// bien key de tim kiem nhung vat tu co ten = key
	string key = "HD";
	string ma_so_hd = "";
	CreateBox(xDisplayDS[5] + 9, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapTimKiemHD, 4);

	while (true)
	{
		switch(ordinal)
		{
		case 0:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
			cout << key;
			gotoxy((xDisplayDS[5] + 9 + nngang / 2), yDisplay + 3);
			NhapTenHD_TimKiem(ma_so_hd, ordinal, isSave, isEscape);
			break;
		}

		if (isSave)
		{
			isSave = false;

			// check rong
			if (ma_so_hd.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "HAY NHAP VAO SO HOA DON !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
		
			// chen thuat toan tim kiem cay lay nhung vat tu ma co ky tu la Key 
			for (int i = 0; i < (ds_nv.n); i++) // duyet qua tat ca nhan vien
			{
				if (ds_nv.ds[i]->ds_hd.pHead != NULL) // neu nhan vien co hoa don
				{
					NODE_HD *p=ds_nv.ds[i]->ds_hd.pHead;
					for (p; p != NULL; p = p->next) // duyet qua tat ca hoa don cua nhan vien
					{	
						string a = p->HD.MAHD.substr(2); // lay ma hoa don

						if (a.compare(ma_so_hd) == 0) // neu ma hoa don trung voi ma hoa don can tim
						{
							int tttrang = 1;
							int tongtrang = (countds_ct_hd(p->HD.ds_ct_hd) -1/ NUMBER_LINES_CTHD) + 1;
							normalBGColor();
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
							system("cls");
							gotoxy(23, 1);
							cout << "~~~HOA DON SAU KHI TIM KIEM~~~ ";
							SetColor(BLACK);
							gotoxy(20, 38);
   							cout<<"PAGE UP-TRANG TRUOC, PAGE DOWN-TRANG SAU";

							string fullName = ds_nv.ds[i]->ho + " " + ds_nv.ds[i]->ten; // ten nhan vien
							DisplayHD(keyDisplayCTHD, 5, xDisplayDS,int_to_string(ds_nv.ds[i]->MANV),fullName ,p->HD.MAHD, int_to_string(p->HD.ngay_lap_hd.Ngay),int_to_string(p->HD.ngay_lap_hd.Thang), int_to_string(p->HD.ngay_lap_hd.Nam),p->HD.loai );
							// lam menu them chi tiet hoa don trong day
							DisplayCTHD(keyDisplayCTHD, 5,xDisplayDS, yDisplay_CTHD);
							// menu chi tiet hoa do
							OutputCTHD_PerPage(t,p->HD.ds_ct_hd,tttrang);
							
							gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
							SetColor(REG_DWORD);
							cout << std::fixed <<p->HD.tong_tien;

							CreateBox(xDisplayDS[5] + 9, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
							for (int i = 0; i < 5; i++)
							{
									SetColor(BLUE);
									gotoxy(X_NOTIFY + 17, Y_NOTIFY);
									Sleep(100);
									cout << "AN ESC DE QUAY LAI !!!";
							}
							normalBGColor();
							int kb_hit;
							bool exit = false;
							do
							{
								if (_kbhit())
								{
									kb_hit = _getch();
									if (kb_hit == 224 || kb_hit == 0)
										kb_hit = _getch();
									switch(kb_hit)
									{
									case PAGE_UP:
										(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
										OutputCTHD_PerPage(t,p->HD.ds_ct_hd, tttrang);
										break;
									
									case PAGE_DOWN:
										(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
										OutputCTHD_PerPage(t,p->HD.ds_ct_hd, tttrang);
										break;
									
									case ESC:
										exit = true;
									}
								}
								ShowCur(false);
								SetColor(BLACK);
								gotoxy(3, 38);
								cout << "Trang " << tttrang << "/" << tongtrang;
							}while(!exit);
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
							return;
						}
					}
				}
			}
			
			if(!found)
			{
				for (int i = 0; i < 5; i++)
				{
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						Sleep(100);
						cout << "MA HOA DON KHONG TON TAI.                ";
						Sleep(500);
				}
				normalBGColor();
				XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
				return;
			}
		}


		if (isEscape)
		{
			kt = true;
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
			return;
		}
	}
	
}
void XoaCTHD(DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd){
	NODE_CTHD* prev = NULL;
	NODE_CTHD* current = ds_ct_hd.pHead;

	while (current != NULL) {
		if (current->CTHD.MAVT == cthd.MAVT) {
			if (prev == NULL) {
				// Nếu node cần xóa là node đầu danh sách
				ds_ct_hd.pHead = current->next;
			}
			else {
				// Nếu node cần xóa không phải là node đầu danh sách
				prev->next = current->next;
			}
			if (current == ds_ct_hd.pTail) {
				// Nếu node cần xóa là node cuối danh sách
				ds_ct_hd.pTail = prev;
			}
			delete current; // Giải phóng bộ nhớ của node bị xóa
			return;
		}
		prev = current;
		current = current->next;
	}
}
bool kiemTraTrangThai(DS_NV ds_nv, HOA_DON hd, CHI_TIET_HOA_DON cthd) {
	for (int i = 0; i < ds_nv.n; i++) { // duyet qua tat ca nhan vien
		NODE_HD* node_hd = ds_nv.ds[i]->ds_hd.pHead; // lay danh sach hoa don cua nhan vien
		// duyet qua tat ca hoa don cua nhan vien
		while (node_hd != NULL) {
			NODE_CTHD* node_cthd = node_hd->HD.ds_ct_hd.pHead; // lay danh sach chi tiet hoa don cua hoa don
			while (node_cthd != NULL) { // duyet qua tat ca chi tiet hoa don cua hoa don
				if (node_cthd->CTHD.MAVT == cthd.MAVT && node_hd->HD.MAHD != hd.MAHD) { // neu tim thay vat tu trong hoa don khac
					return true; //tim thay
				}
				node_cthd = node_cthd->next;
			}
			node_hd = node_hd->next;
		}
	}
	return false; // khong tim thay
}
void TraHang_CTHD(HOA_DON& hd, DS_NV ds_nv,DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd, bool isEdited, TREE_VT& t, int& pos) {
	// Hiển thị con trỏ nhập
	ShowCur(true);
	normalBGColor();

	// Các biến điều khiển quá trình trả hàng
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// Chiều dài bảng nhập
	int nngang = (int)keyBangNhapCTHD[0].length();

	// Biến tạm lưu trữ số lượng trả hàng
	string so_luong_tra = "";

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 59);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapCTHD_TraHang, 2);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideCTHD_TraHang, 2);

	// Gán số lượng trả hàng vào biến tạm lưu trữ
	so_luong_tra = int_to_string(cthd.so_luong);
	// Hiển thị số lượng trả hàng
	gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 2);
	cout << so_luong_tra;

	while (true) {
		// Nếu đang chỉnh sửa
		if (isEdited) {
			// Xử lý nhập số lượng trả hàng
			switch (ordinal) {
			case 0: // Nhập số lượng trả hàng
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 2);
				NhapSoLuongTraHang(so_luong_tra, ordinal, isSave, isEscape);
				break;
			}
		}
		// Kiểm tra lưu
		if (isSave) {
			// Cập nhật biến và kiểm tra trống
			isSave = false;
			if (so_luong_tra.length() == 0) {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "VUI LÒNG NHẬP SỐ LƯỢNG TRẢ !!!";
				normalBGColor();
				ordinal = 0;
				continue;
			}

			// Kiểm tra số lượng trả không vượt quá số lượng ban đầu
			int so_luong_tra_temp = atoi(so_luong_tra.c_str());
			if (so_luong_tra_temp > cthd.so_luong) {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "GIOI HAN:  " << cthd.so_luong << ".";
				normalBGColor();
				ordinal = 0;
				continue;
			}

			// Cập nhật số lượng trả hàng trong chi tiết hóa đơn
			cthd.so_luong -= so_luong_tra_temp;
			// Cập nhật tổng tiền của hóa đơn
			hd.tong_tien -= ((so_luong_tra_temp * cthd.don_gia) * (1 + ((float)cthd.thue / 100)));
			// Cập nhật số lượng vật tư
			NODE_VT* vt_temp = find_VT(t, cthd.MAVT); // Tìm vật tư trong cây
			bool ktTrangThai = kiemTraTrangThai(ds_nv,hd,cthd); // Trạng thái vật tư trong hóa đơn
			if (hd.loai == 'X' || hd.loai == 'x') // xuat
			{		
					vt_temp->VT.so_luong_ton += so_luong_tra_temp;    // tang so luong ton, vi khi xuat bi tra hang so luong trong kho van giu nguyen
			}
			else // nhap
			{
				vt_temp->VT.so_luong_ton -= so_luong_tra_temp;    // giam so luong ton
			}
			if (cthd.so_luong == 0)
			{
				if (!ktTrangThai)
				{
					vt_temp->VT.trong_hoa_don = false;
				}
				//XoaCTHD(ds_ct_hd, cthd);
			}

			// In thông báo thành công
			for (int i = 0; i < 5; i++) {
				SetColor(BLUE);
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				Sleep(100);
				cout << "TRA HANG THANH CONG !!! ";
				Sleep(500);
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
			SetColor(REG_DWORD);
			cout << std::fixed << hd.tong_tien << "                               ";
			_getch;
			return;
		}

		// Kiểm tra ESC
		if (isEscape) {
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return;
		}
	}
	ShowCur(false);
}

void Bang_Nhap_Ten_HD_Return(TREE_VT t, DS_NV& ds_nv, bool& kt) // bang nhap ten hoa don de tra hang
{
	ShowCur(true);
	normalBGColor();

	int ordinal = 0;
	bool isSave = false; // tien hanh tim kiem
	bool isEscape = false;
	bool found = false;

	// chieu dai bang nhap 
	int nngang = (int)keyBangNhapTimKiemHD[0].length();

	// bien key de tim kiem nhung vat tu co ten = key
	string key = "HD";
	string ma_so_hd = "";
	CreateBox(xDisplayDS[5] + 9, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapTraHang, 4);

	while (true)
	{
		switch (ordinal)
		{
		case 0:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
			cout << key;
			gotoxy((xDisplayDS[5] + 9 + nngang / 2), yDisplay + 3);
			NhapTenHD_TimKiem(ma_so_hd, ordinal, isSave, isEscape);
			break;
		}

		if (isSave)
		{
			isSave = false;

			// check rong
			if (ma_so_hd.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "HAY NHAP VAO SO HOA DON !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			//tim kiem hoa don
			for (int i = 0; i < (ds_nv.n); i++)
			{
				if (ds_nv.ds[i]->ds_hd.pHead != NULL)
				{
					NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
					for (p; p != NULL; p = p->next)
					{
						string a = p->HD.MAHD.substr(2);

						if (a.compare(ma_so_hd) == 0)
						{
							if (!kiem_tra_dieu_kien_tra_hang(p->HD.ngay_lap_hd))
							{
								for (int i = 0; i < 5; i++)
								{
									SetColor(BLUE);
									gotoxy(X_NOTIFY + 17, Y_NOTIFY);
									Sleep(100);
									cout << "QUA 3 NGAY KE TU " << p->HD.ngay_lap_hd.Ngay << "/" << p->HD.ngay_lap_hd.Thang <<"/" << p->HD.ngay_lap_hd.Nam <<" KHONG THE TRA HANG";
									Sleep(500);
								}
								normalBGColor();
								XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
								return;
							}
							int tttrang = 1;
							int tongtrang = (countds_ct_hd(p->HD.ds_ct_hd) / NUMBER_LINES_CTHD) + 1;
							normalBGColor();
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
							system("cls");
							gotoxy(23, 1);
							cout << "~~~HOA DON SAU KHI TIM KIEM~~~ ";
							SetColor(BLACK);
							gotoxy(20, 38);
							cout << "PAGE UP-TRANG TRUOC, PAGE DOWN-TRANG SAU";

							string fullName = ds_nv.ds[i]->ho + " " + ds_nv.ds[i]->ten;
							DisplayHD(keyDisplayCTHD, 5, xDisplayDS, int_to_string(ds_nv.ds[i]->MANV), fullName, p->HD.MAHD, int_to_string(p->HD.ngay_lap_hd.Ngay), int_to_string(p->HD.ngay_lap_hd.Thang), int_to_string(p->HD.ngay_lap_hd.Nam), p->HD.loai);
							// lam menu them chi tiet hoa don trong day
							DisplayCTHD(keyDisplayCTHD, 5, xDisplayDS, yDisplay_CTHD);
							// menu chi tiet hoa do
							OutputCTHD_PerPage(t, p->HD.ds_ct_hd, tttrang);

							gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
							SetColor(REG_DWORD);
							cout << std::fixed << p->HD.tong_tien;

							CreateBox(xDisplayDS[5] + 9, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
							for (int i = 0; i < 5; i++)
							{
								SetColor(BLUE);
								gotoxy(X_NOTIFY + 17, Y_NOTIFY);
								Sleep(100);
								cout << "AN ESC DE QUAY LAI !!!";
							}
							CreateBox(xDisplayDS[5] + 9, Y_NOTIFY + 10, "CACH THAO TAC:  ", 62);
							for (int i = 0; i < 5; i++)
							{
								SetColor(BLUE);
								gotoxy(X_NOTIFY + 17, Y_NOTIFY+10);
								Sleep(100);
								cout << "AN PHIM F2 DE TRA HANG";
							}
							normalBGColor();
							int kb_hit;
							bool exit = false;
							do
							{
								if (_kbhit())
								{
									kb_hit = _getch();
									if (kb_hit == 224 || kb_hit == 0)
										kb_hit = _getch();
									switch (kb_hit)
									{
									case PAGE_UP:
										(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
										OutputCTHD_PerPage(t, p->HD.ds_ct_hd, tttrang);
										break;

									case PAGE_DOWN:
										(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
										OutputCTHD_PerPage(t, p->HD.ds_ct_hd, tttrang);
										break;
									case KEY_F2:
									{
										XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 70);
										int choose = ChooseItems_CTHD(t, p->HD.ds_ct_hd, tttrang, tongtrang);
										if (choose < countds_ct_hd(p->HD.ds_ct_hd))
										{
											int temp = -1; // Biến tạm của pos
											NODE_CTHD* nodeAtPos = GetNodeAtPosition(p->HD.ds_ct_hd.pHead, choose);
											if (nodeAtPos != NULL) {
												TraHang_CTHD(p->HD,ds_nv, p->HD.ds_ct_hd, nodeAtPos->CTHD, true, t, temp);
												OutputCTHD_PerPage(t, p->HD.ds_ct_hd, tttrang);
											}
										}
										else {
											exit = true;
										}
										break;
									}
									case ESC:
										exit = true;
									}
								}
								ShowCur(false);
								SetColor(BLACK);
								gotoxy(3, 38);
								cout << "Trang " << tttrang << "/" << tongtrang;
							} while (!exit);
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
							return;
						}
					}
				}
			}

			if (!found)
			{
				for (int i = 0; i < 5; i++)
				{
					SetColor(BLUE);
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					Sleep(100);
					cout << "MA HOA DON KHONG TON TAI.                ";
					Sleep(500);
				}
				normalBGColor();
				XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
				return;
			}
		}


		if (isEscape)
		{
			kt = true;
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
			return;
		}
	}

}
int Output_SearchHD_List(TREE_VT t,DS_NV ds_nv)
{
	int currposMainMenu = -1;
	bool kt = false; // thoat khoi tim kiem
	ShowCur(false);
	Bang_Nhap_Ten_HD(t,ds_nv,kt);
	
    // thu tu trang
	ShowCur(false);
	if (kt)
	{
		normalBGColor();
		clrscr();
		return 0;
	}
	else
		return 1;

}

int Output_SearchHD_List_Return(TREE_VT t, DS_NV ds_nv)
{
	
	int currposMainMenu = -1;
	bool kt = false; // thoat khoi tim kiem
	ShowCur(false);
	Bang_Nhap_Ten_HD_Return(t, ds_nv, kt);

	// thu tu trang
	ShowCur(false);
	if (kt)
	{
		normalBGColor();
		clrscr();
		return 0;
	}
	else
		return 1;
}
void Menu_Tim_Kiem_HD(TREE_VT t,DS_NV ds_nv)
{
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

    do
    {
        clrscr();
		gotoxy(23, 1);
		cout << "~~~HOA DON SAU KHI TIM KIEM~~~ ";
		DisplayHD(keyDisplayCTHD, 5, xDisplayDS,"","","","","","",3);
		gotoxy(3, yHotkey );
		SetColor(BLACK);
		cout << "ESC-Thoat, F10 - Tim Kiem";

		normalBGColor();
		CHI_TIET_HOA_DON cthd;
		int index = 0;

		
		esc = Output_SearchHD_List(t,ds_nv);

    }while (esc);

}


void Menu_Tra_Hang(TREE_VT t, DS_NV ds_nv)
{
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

	do
	{
		clrscr();
		gotoxy(23, 1);
		cout << "~~~HOA DON SAU KHI TIM KIEM~~~ ";
		DisplayHD(keyDisplayCTHD, 5, xDisplayDS, "", "", "", "", "", "", 3);
		gotoxy(3, yHotkey);
		SetColor(BLACK);
		cout << "ESC-Thoat, F10 - Tim Kiem";

		normalBGColor();



		esc = Output_SearchHD_List_Return(t, ds_nv);

	} while (esc);

}
int ChooseItems_CTHD(TREE_VT t, DS_CT_HD& ds_ct_hd, int& tttrang, int tongtrang)// chon 1 vat tu trong danh sach
{

	int kb_hit;
	int pos = 0;
	SetColor(REG_DWORD);
	gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
	cout << "<<";
	gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
	cout << ">>";
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			//if (kb_hit == 224 || kb_hit == 0)
				//kb_hit = _getch();
			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << "  ";

				(pos > 0) ? pos-- : pos = 17; // neu pos = 0 thi pos = 17, pos> 0 thi pos--. Neu o muc 0 thi xuong cuoi danh sach

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << ">>";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << "  ";

				(pos < NUMBER_LINES_CTHD - 1) ? pos++ : pos = 0; // Neu pos < 17 thi pos++, neu pos = 17 thi pos = 0

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << ">>";
				break;
			case PAGE_UP:
				if (tttrang > 1)
				{
					tttrang--;
				}
				else
				{
					tttrang = tongtrang;
				}
				OutputCTHD_PerPage(t, ds_ct_hd, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(5);
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << ">>";
				break;



			case PAGE_DOWN:
				if (tttrang < tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;

				}
				OutputCTHD_PerPage(t, ds_ct_hd, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(REG_DWORD);
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << ">>";
				break;
			case ENTER:

				// tra ve vi tri pos.
				return (tttrang == 1) ? pos : pos + (tttrang - 1) * NUMBER_LINES_CTHD; // tra ve vi tri cua vat tu trong danh sach vat tu
			case ESC:
				return 999;

			}
		}
		ShowCur(false);
		SetColor(WHITE);
		normalBGColor();
	}
}
void NhapSoLuongTraHang(string& result, int& ordinal, bool& isSave, bool& isEscape)
{
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;

	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa, chu so  va dau cach
			// chi nhap ten vat tu toi da 19 ky tu.
			if ((kb_hit >= 48 && kb_hit <= 57) && count < MAX_SLT && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				count++;
				cout << (char)kb_hit;
				result += (char)kb_hit;

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 0;
					return;
				}
				else
				{
					ordinal = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 0;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA 9 KY TU, CHI LAY KY TU SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}

}
//phu
void BangNhapNam(TREE_VT t, DS_NV ds_nv, bool& kt) {
	ShowCur(true);
	normalBGColor();

	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// Chiều dài bảng nhập
	int nngang = (int)keyBangNhapTimKiemHD[0].length();

	// Biến key để tìm kiếm
	string nam = "";
	CreateBox(xDisplayDS[5] + 9, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapTimNam, 4);

	while (true)
	{
		switch (ordinal)
		{
		case 0:
			gotoxy((xDisplayDS[5] + 9 + nngang / 2), yDisplay + 3);
			NhapNam(nam, ordinal, isSave, isEscape);
			break;
		}

		if (isEscape) {
			kt = false;
			return;
		}

		if (isSave) {
			// Xử lý logic khi năm đã được nhập và lưu
			int intYear = atoi(nam.c_str());
			if (kiem_tra_nam_lon_hon_hien_tai(intYear)==-1) {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "NAM KHONG HOP LE !!!";
				normalBGColor();
				ordinal = 0;
				isSave = false;
				continue;
			}

			int giaTriNhapThang[12] = { 0 };  // Mảng lưu giá trị nhập từng tháng
			int giaTriXuatThang[12] = { 0 };  // Mảng lưu giá trị xuất từng tháng

			for (int i = 0; i < ds_nv.n; i++) { // Duyệt qua từng nhân viên
				for (NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead; p != NULL; p = p->next) { // Duyệt qua từng hóa đơn của nhân viên
					if (p->HD.ngay_lap_hd.Nam == intYear) { // Nếu hóa đơn được lập trong năm cần thống kê
						if (p->HD.loai == 'N' || p->HD.loai == 'n') {
							giaTriNhapThang[p->HD.ngay_lap_hd.Thang - 1] += p->HD.tong_tien;
						}
						else if (p->HD.loai == 'X' || p->HD.loai == 'x') {
							giaTriXuatThang[p->HD.ngay_lap_hd.Thang - 1] += p->HD.tong_tien;
						}
					}
				}
			}

			// Tính doanh thu (xuất - nhập) cho từng tháng
			int doanhThuThang[12] = { 0 };
			for (int i = 0; i < 12; i++) {
				doanhThuThang[i] = giaTriXuatThang[i] - giaTriNhapThang[i];
			}

			// Hiển thị doanh thu từng tháng
			ShowCur(false);
			gotoxy(X_NOTIFY + 17, Y_NOTIFY);
			SetColor(BLUE);
			cout << "TIM THAY";
			gotoxy(2, 1);
			cout << "DOANH THU TUNG THANG CUA NAM " << intYear;
			gotoxy(3, yHotkey);
			SetColor(BLACK);
			cout << "ESC-Thoat";
			DisplayVT(keyDisplayDoanhThu, 4, xDisplayTop10);
			for (int i = 1; i <= 12; i++) {
				gotoxy(xDisplayTop10[0] + 3, yDisplay + 3 + i-1);
				SetColor(2);
				cout << i;
				gotoxy(xDisplayTop10[1] + 3, yDisplay + 3 + i-1);
				SetColor(3);
				cout << std::fixed << doanhThuThang[i - 1];
				gotoxy(xDisplayTop10[2] + 3, yDisplay + 3 + i - 1);
				SetColor(4);
				cout << std::fixed << giaTriNhapThang[i - 1];
				gotoxy(xDisplayTop10[3] + 3, yDisplay + 3 + i - 1);
				SetColor(5);
				cout << std::fixed << giaTriXuatThang[i - 1];


			}
			ShowCur(false);
			kt = true;

			// Vòng lặp chờ người dùng nhấn ESC để thoát
			while (true) {
				int kb_hit = _getch();
				if (kb_hit == ESC) {
					clrscr();
					return;
				}
			}
		}
	}
}


void NhapNam(string& result, int& ordinal, bool& isSave, bool& isEscape)
{
	cout << result;
	int count = (int)result.length();
	int x, y;

	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chỉ nhận ký tự số và giới hạn số ký tự là 4 (cho năm)
			if ((kb_hit >= 48 && kb_hit <= 57) && count < 4 && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				count++;
				cout << (char)kb_hit;
				result += (char)kb_hit;

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 0;
					return;
				}
				else
				{
					ordinal = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 0;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA 4 KY TU, CHI LAY KY TU SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}
