#pragma once

#include "STRUCT.H"




///////////////////////////////// VAT TU ///////////////////////////
void initTree_VT(TREE_VT &t);
bool isEmpty(TREE_VT t);
NODE_VT *getNodeVT(VAT_TU vt);
void insertVTToTree(TREE_VT &t, VAT_TU vt);
int countVT(TREE_VT t);
bool Check_MAVT(TREE_VT t, string MAVT);
NODE_VT *findMin(TREE_VT t);
NODE_VT *find_VT(TREE_VT t, string MAVT);
bool IsDeleted_VT(TREE_VT &t, VAT_TU nv);
void initList_Temp_List(LIST_TEMP_LIST &l);
void Cap_Nhat_Vat_Tu(TREE_VT &t, HOA_DON hd, DS_CT_HD ds_ct_hd);
void NhapTenVT(string &result, int &ordinal, bool &isSave, bool &isEscape, bool isEdited);
void Update_VT(TREE_VT &t, VAT_TU &vt, bool isEdited);
void OutputVT_PerPage(TREE_VT t, LIST_TEMP_LIST l, int index);
int Output_ListVT(TREE_VT &t, LIST_TEMP_LIST &l, VAT_TU &vt, int &tttrang);
void Menu_VT(TREE_VT &t);
void Create_Temp_List(TREE_VT t, LIST_TEMP_LIST &l, int &index);
void ClearAll_Temp_List(LIST_TEMP_LIST &l);
NODE_TEMP_LIST *Middle(NODE_TEMP_LIST *start, NODE_TEMP_LIST *last);
NODE_TEMP_LIST *binarySearch_Temp_List(LIST_TEMP_LIST l, uint index);
int ChooseItems(TREE_VT &t, LIST_TEMP_LIST &l, int tttrang, int tongtrang);
void NhapDonViTinh(string &result, int &ordinal, bool &isSave, bool &isEscape, bool isEdited);
void NhapSoLuongTon(string &result,int choice ,int &ordinal, bool &isSave, bool &isEscape);
void Output_VT(NODE_VT* vt, int& locate);
NODE_TEMP_LIST *getNode_Temp_List(uint index, string MAVT, string ten);
void addTailList_Temp_List(LIST_TEMP_LIST &l, uint index, string MAVT, string ten);
void Sort_Temp_list_Name(LIST_TEMP_LIST &l);
/////////// RANDOM VT  ///////////////
string Tao_Ma_VT(TREE_VT t);
bool Kiem_Tra_Trung_MAVT(TREE_VT t, string key);
int So_Sanh_Ma_VT(string a, string b);
void Nhap_Ma_VT(string &result, int &ordinal, bool &isSave, bool &isEscape);
int Output_ListVT_TEN(TREE_VT &t, LIST_TEMP_LIST &l, VAT_TU &vt, int &tttrang);
void Menu_In_DS_VT(TREE_VT &t);
void GiaiPhongTree(TREE_VT &t);

void format_string(string& a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);

	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{

			a.erase(a.begin() + i + 1);
			i--;
		}

	}
}


void initTree_VT(TREE_VT &t)  // khoi tao cay nhi phan 
{
    t = NULL;
}
bool isEmpty(TREE_VT t)  // kiem tra cay rong
{
    return t == NULL;
}
NODE_VT *getNodeVT(VAT_TU vt)  // tao node vat tu moi
{
    NODE_VT *p = new NODE_VT;
    p->VT = vt;
    p->left = p->right = NULL;
    return p;
}
void insertVTToTree(TREE_VT &t, VAT_TU vt)  // them node vt vao cay ( de quy )
{
    if (t == NULL)
    {
        t = getNodeVT(vt);
    }
    else if (vt.MAVT < t->VT.MAVT)
    {
        insertVTToTree(t->left, vt);
    }
    else if (vt.MAVT > t->VT.MAVT)
    {
        insertVTToTree(t->right,vt);
    }
}
void GiaiPhongTree(TREE_VT &t)   // giai phong cay
{
	if(t==NULL ) return;
	else 
	{
		GiaiPhongTree(t->left);
		GiaiPhongTree(t->right);
		delete t;
	}
}
int countVT(TREE_VT t)         // dem nut tren cay ( de quy )
{
    int c = 1;
    if (t == NULL)
        return 0;
    else 
    {
        c += countVT(t->left);
        c += countVT(t->right);
        return c;
    }
}
bool Check_MAVT(TREE_VT t, string MAVT)  // kiem tra trung ma vat tu ( de quy )
{
    if (t == NULL)    // cay rong tra ve false
        return false;
    else if (So_Sanh_Ma_VT(t->VT.MAVT, MAVT) == 0)   // Neu ma vt bang ma vt cua node hien tai, tra ve true
        return true;
    else if (So_Sanh_Ma_VT(MAVT, t->VT.MAVT) < 0)  // Neu ma vt ma be hon node hien tai, tiep tuc so sanh ma vt do voi cay trai cua node do
    {
        return Check_MAVT(t->left, MAVT);
    }
    else 
        return Check_MAVT(t->right, MAVT);     // Neu ma vt ma lon hon node hien tai, tiep tuc so sanh ma vt do voi cay phai cua node do
}


NODE_VT *findMin(TREE_VT t)   // tim node vat tu co ma nho nhat // de xoa vat tu
{
    while (t->left != NULL)
        t = t->left;
    return t;
}
NODE_VT *find_VT(TREE_VT t, string MAVT)  // tim nodevt co MAVT
{
    while (t != NULL && MAVT != t->VT.MAVT)  // vong lap ket thuc khi tim ra node vt co MAVT hoac bang NULL khi ko ton tai
    {
        if (MAVT < t->VT.MAVT)
            t = t->left;
        else 
            t = t->right;
    }
    return t;
}
bool IsDeleted_VT(TREE_VT &t, VAT_TU vt)   // ham bool de xoa vat tu
{
    if (t == NULL)   // cay rong 
        return false;
    else 
    {
        if (vt.MAVT > t->VT.MAVT)                            // de quy tim not can xoa
            return IsDeleted_VT(t->right, vt);
        else if (vt.MAVT < t->VT.MAVT)
            return IsDeleted_VT(t->left, vt);
        else 
        {
            // case 1: No child
            if (t->left == NULL && t->right == NULL)
            {
                delete t;  //xoa nut
                t = NULL;   // gan nut do bang NULL 
            }
            // case 2: 1 child
            else if (t->right == NULL)
            {
                NODE_VT *temp = t;    // tao node tam luu dia chi cua t can xoa
                t = t->left;    // tien hanh gan t-left cho t
                delete temp;      // xoa temp luu dia chi t cu
            }
            else if (t->left == NULL)
            {
                NODE_VT *temp = t;
                t = t->right;
                delete temp;
            }
            // case 3: 2 child
            else
            {
                NODE_VT *temp = findMin(t->right);   // tim nut the mangg ( trai nhat cua cay con phai )
                t->VT = temp->VT;   // hoan doi ten vat tu voi nut the mang
                return IsDeleted_VT(t->right, temp->VT);  // xoa nut the mang 
            }
            return true;    
        }
    }
}
void initList_Temp_List(LIST_TEMP_LIST &l)  // khoi tao mot dslkd tam
{
    l.pHead = l.pTail = NULL;
}
void Cap_Nhat_Vat_Tu(TREE_VT &t, HOA_DON hd, DS_CT_HD ds_ct_hd)  // cap nhat so luong vat tu
{
	if (hd.loai == 'X' || hd.loai == 'x') // xuat
	{
		for (NODE_CTHD *curNode = ds_ct_hd.pHead; curNode != NULL; curNode = curNode->next)
		{
			NODE_VT *vt_temp = find_VT(t, curNode->CTHD.MAVT);
			vt_temp->VT.so_luong_ton -= curNode->CTHD.so_luong;    // giam so luon ton
			vt_temp->VT.trong_hoa_don = true;          // cap nhat trang thai
		}
	}
	else // nhap
	{
		for (NODE_CTHD* curNode = ds_ct_hd.pHead; curNode != NULL; curNode = curNode->next)
		{
			NODE_VT* vt_temp = find_VT(t, curNode->CTHD.MAVT);   
			vt_temp->VT.so_luong_ton += curNode->CTHD.so_luong;    // tang so luong ton
			vt_temp->VT.trong_hoa_don = true;    // cap nhat trang thai
		}
	}
}
void NhapTenVT(string &result, int &ordinal, bool &isSave, bool &isEscape, bool isEdited)
{
    // bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;  // toa do con tro
	int nSpace = 0;  //kiem soat khoang trang (space)	

	while (true)
	{
		x = wherex();  // luu bien x,y thanh vi tri nhap sau nay
		y = wherey();
		while (_kbhit())  // chờ nhập từ bàn phím
		{
			int kb_hit = _getch();  //lưu ký tự nhập từ bàn phím
			//Chỉ chấp nhận các ký tự chữ cái (A-Z, a-z), chữ số (0-9) và khoảng trắng, với tổng số ký tự không vượt quá MAX_TEN_VT.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57) || kb_hit == SPACE)
				&& count < MAX_TEN_VT && count >= 0)
			{
				// Mục đích của đoạn mã này là để xóa dòng thông báo hiện tại tại vị trí xác định trên console
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				cout << setw(44) << setfill(' ') << " ";
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE) // kiem tra xem ky tu vua nhap co phai la space hay khong
				{
					count++;   // tang bien dem 
					cout << (char)kb_hit;  // in ky tu vua nhap ra man hinh 
					result += (char)kb_hit;   // chuoi ket qua dc nhap nhat 
					nSpace = 0;      //bien dem khoang trang ve lai bang 0, ko cho nhap them khoang trang nua
				}
				else if (kb_hit != SPACE)  // neu ki tu vua nhap k phai la space
				{
					count++; 
					kb_hit = toupper((char)kb_hit);  // bien thanh chu in hoa 
					cout << (char)kb_hit;     // in ra mh
					result += (char)kb_hit; 
					nSpace = 1;   // cho phep nhap khoang trang sau ki tu nay
				}

			}
			else if (kb_hit == 224)  // kiem tra xem co phai phim dieu huong
			{
				kb_hit = _getch();  // lay du lieu nhap tu phim
				if (kb_hit == KEY_UP)   // neu nut mui ten di len 
				{
					if (isEdited) 
					{
						ordinal = 1;
						return;
					}                   
					else
					{
						ordinal = 2;
						return;
					}
					//Cập nhật giá trị của ordinal dựa trên phím điều hướng đã được nhấn và trạng thái của isEdited.
					//Điều hướng chương trình dựa trên các phím điều hướng để thực hiện các hành động thích hợp
				}
				else  // nut trai phai xuong se di xuong
				{
					ordinal = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)  
			{
				ordinal = 1;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)  // kiem tra khi xoa bang backspace
			{
				cout << "\b" << " " << "\b";  // in khoang trang va lui con tro bang \b
				count--;
				result.erase(result.length() - 1, 1); // xoa ky tu cuoi
			}
			else if (kb_hit == 0) // kiem tra cac thao tac khac
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10) // neu la F10 
				{ 
					isSave = true; // tien hanh luu
					return;
				}
			}
			else if (kb_hit == ESC) // kiem tra neu nhan esc
			{
				isEscape = true;  // bien thoat bang true
				return;
			}
			else {  // cac truong hop nhap k thoa man
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << " TOI DA 20 KY TU, CHI LAY KY TU CHU VA SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}

}
void Update_VT(TREE_VT &t, VAT_TU &vt, bool isEdited)  // isEdited la true: chinh sua, neu la false thi nhap vt
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapVT[0].length();   //  key bang nhap 0 : ~~~ CAP NHAT VAT TU ~~~        

	// cac bien luu tru tam thoi
	string ten = "";  
	string don_vi_tinh = "";
	string temp_so_luong_ton = "";
	uint so_luong_ton;
	string MAVT;

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 59);    // tao box thong bao
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapVT, 10);   // tao bang nhap
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideVT, 5);   // tao bang huong dan

	if (isEdited)  // neu la chinh sua thi cap nhat cac bien tam bang cac ten co san 
	{
		ten = vt.ten;   // cap nhat ten 
		don_vi_tinh = vt.don_vi_tinh;   // cap nhat dvt
		so_luong_ton = vt.so_luong_ton;
		MAVT = vt.MAVT;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);     
		cout << MAVT;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
		cout << ten;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
		cout << don_vi_tinh;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
		cout << so_luong_ton;
	}
    if (!isEdited)  // neu them moi 
    {
        gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);    
		MAVT = Tao_Ma_VT(t);   // tao ma vat tu
		cout << MAVT;
    }

	while (true) {
		if(isEdited) // neu chinh sua
		{
			switch (ordinal)   // kiem tra thu tu nhap
			{
			
			case 0:     // neu la 0
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);  
				NhapTenVT(ten, ordinal, isSave, isEscape, isEdited);
				break;
			case 1:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapDonViTinh(don_vi_tinh, ordinal, isSave, isEscape, isEdited);
				break;
			}		
		}
		else // neu ko chinh sua, tuc la them vt
		{
			switch (ordinal)
			{
			
			case 0:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
				NhapTenVT(ten, ordinal, isSave, isEscape, isEdited);
				break;
			case 1:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapDonViTinh(don_vi_tinh, ordinal, isSave, isEscape, isEdited);
				break;
			case 2:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
				NhapSoLuongTon(temp_so_luong_ton, NHAP_SO_LUONG_TON ,ordinal, isSave, isEscape);
				for (int i = 0; i < temp_so_luong_ton.length(); i++)
				so_luong_ton = atoi(temp_so_luong_ton.c_str());
				break;
			}
		}
		
		// check Save
		if (isSave)   // neu trong qua trinh nhap co f10 de luu thi isSave thanh true
		{
			// cap nhat lai flag để nếu không thỏa mãn các điều kiện về nhập liệu còn nhập lại
			isSave = false;

			// check rong;
			if (ten.length() == 0)
			{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0; // cap nhat lai thu tu bang 0 tuc la nhap lai ten
				continue;
			}
			else if (don_vi_tinh.length() == 0)
			{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			if (!isEdited)  // neu la them vao
			{
				vt.trong_hoa_don = false;
				if (temp_so_luong_ton.length() == 0)
				{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
				}
			}
			
			

			vt.MAVT = MAVT;
			format_string(ten);
			vt.ten = ten;
			vt.don_vi_tinh = don_vi_tinh;
			vt.so_luong_ton = so_luong_ton;
//			vt.trong_hoa_don = false;

            if (isEdited)  // neu chinh sua
            {
                NODE_VT *p = find_VT(t, MAVT);  // tim ma vat tu va cap nhat vat tu
                p->VT = vt;
            }
            else  // neu la them vao
            {
                // thuật toán thêm vào danh sách vật tư
			    insertVTToTree(t, vt);
            }

			// In dong thong bao .
			for (int i = 0; i < 5; i++)
			{
					SetColor(BLUE);
					gotoxy(X_NOTIFY + 15, Y_NOTIFY);
					Sleep(100);
					cout << "           SUCCESSFULLY !!! ";
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return; //ket thuc ham 
		}

		if (isEscape)
		{
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return;
		}
	}
	ShowCur(false);
}
void OutputVT_PerPage(TREE_VT t, LIST_TEMP_LIST l, int index)// index chi muc trang
{
	Xoa_OutNV_29lines();  // Xóa màn hình hiển thị trước đó.
    SetColor(BLACK);
    int locate = 0;   //Đặt vị trí ban đầu để in ra vật tư.
    NODE_TEMP_LIST *temp1 = NULL;    
    NODE_VT *temp2 = NULL;
    index--;
    for (int i = NUMBER_LINES * index; i < NUMBER_LINES *(index + 1); i++)  // tu 0 - 28, 28 - ..
    {
        temp1 = binarySearch_Temp_List(l, i);
        if (temp1 == NULL)   //neu danh sach rong return 
            return;
        temp2 = find_VT(t, temp1->tl.MAVT);  //Tìm vật tư trong cây nhị phân dựa trên danh sách tạm thời.
		Output_VT(temp2, locate); // Truyền locate vào hàm Output_VT
		locate++; // Tăng vị trí locate sau mỗi lần in ra thông tin vật tư
    }
} 
int Output_ListVT(TREE_VT &t, LIST_TEMP_LIST &l, VAT_TU &vt, int &tttrang)
{
	NODE_TEMP_LIST *temp1 = NULL;  //tao mot node tam
    NODE_VT *temp2 = NULL;  //tao mot node vt
    int choose;
    bool check;

    // nNV la so NV hien co trong cay
    int nVT = countVT(t);

    // thu tu trang
    int tongtrang;
    tongtrang = (nVT / NUMBER_LINES) + 1; 
    OutputVT_PerPage(t,l,tttrang); // dau tien hien thi trang thu nhat

    int kb_hit;
	int currposMainMenu = -1;  // vị trí hiện tại của phím chọn chức năng F10, ...
	int nKey=5;
	ShowCur(false);
    do
    {
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)   //kiem tra phim dieu huong
                kb_hit = _getch();

				
            switch(kb_hit)
            {
			case PAGE_UP:      //Trong trường hợp của mã PAGE_UP, tro ve trang trc
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;  
				OutputVT_PerPage(t,l,tttrang);                    //Biến tttrang sẽ giảm đi 1 nếu tttrang không phải là trang đầu tiên; 
				break;											// ngược lại, nếu tttrang đang ở trang đầu tiên, nó sẽ được đặt lại thành trang cuối cùng.
			
			case PAGE_DOWN:    // den trang sau
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;    //biến tttrang sẽ tăng lên 1 nếu tttrang không phải là trang cuối cùng
				OutputVT_PerPage(t,l,tttrang);						//ngược lại, nếu tttrang đang ở trang cuối cùng, nó sẽ được đặt lại thành trang đầu tiên.
				break;
            case KEY_F2: // them
                    Update_VT(t, vt, false);                        // them vat tu, bien isEdited la false     
                    ClearAll_Temp_List(l);      // xoa ds tam thoi
                    return 1;                   
            case KEY_F3: // sua
                    choose = ChooseItems(t, l, tttrang, tongtrang); // chọn một vật tư từ trang để chỉnh sửa  
                    temp1 = binarySearch_Temp_List(l, choose);    // tim vat tu trong danh sach tam ở vị trí choose
                    if (temp1 == NULL)
                        return 1;
                    else
                    {
                        temp2 = find_VT(t, temp1->tl.MAVT);
                        Update_VT(t, temp2->VT, true);  // isEdited = True
                        ClearAll_Temp_List(l);
                        return 1;
                    }
            case KEY_F4: // xoa
                    choose = ChooseItems(t, l, tttrang, tongtrang);
                    temp1 = binarySearch_Temp_List(l, choose);
                    if (temp1 == NULL)
                    {
                        return 1;
                    }
                    else 
                    {
                        temp2 = find_VT(t, temp1->tl.MAVT);
						if (temp2->VT.trong_hoa_don)  //nếu vật tư nằm trong hóa đơn nào đó
						{
							CreateBox(X_NOTIFY, Y_NOTIFY, "NOTIFICATIONS:  ", 59);  // tạo box thông báo 
							// In dong thong bao .
							for (int i = 0; i < 5; i++)
							{
							SetColor(BLUE);
							gotoxy(X_NOTIFY + 15, Y_NOTIFY);
							Sleep(100);
							cout << " VAT TU DA CO TRONG HOA DON. KHONG THE XOA";
							Sleep(500);
							}
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
							ClearAll_Temp_List(l);  //xóa danh sách tạm 
							return 1;
						}
                        check = IsDeleted_VT(t, temp2->VT);  //biến check kiểm tra xem đã xóa vật tư thành công chưa
						ClearAll_Temp_List(l);
                        return 1;
                    }
            case ESC:
                    ClearAll_Temp_List(l);
                    return 0;

			case KEY_LEFT:  // chọn các phím nóng bên trái f10, f2 ,....

				
				if (currposMainMenu > 0)
				{
					currposMainMenu = currposMainMenu - 1;  // nếu vị trí >0 thì qua trái 
				}
				else {
					currposMainMenu = nKey - 2;  //nếu bằng 0 thì qua cái thứ 3 (nkey - 2 = 3)
				}

				EffectiveMenu_VatTu(currposMainMenu, 2);   //hiệu ứng cho phím đó
				break;

			case KEY_RIGHT: //key right
				
				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1;
				}
				else {
					currposMainMenu = 0;//di chuyên đến vị trí 0
				}
				EffectiveMenu_VatTu(currposMainMenu, 1);
				break;

			case ENTER: //enter
			
				switch(currposMainMenu)   //dựa vào biến mainmenu
				{
					case 0: 
							Update_VT(t, vt, false);
                 	  		ClearAll_Temp_List(l);
                    		return 1;
					case 1:
							choose = ChooseItems(t, l, tttrang, tongtrang);
                   			temp1 = binarySearch_Temp_List(l, choose);
                 		  	if (temp1 == NULL)
                       		return 1;
                		    else
                  			{
                      		 	temp2 = find_VT(t, temp1->tl.MAVT);
                      			Update_VT(t, temp2->VT, true);
                       			ClearAll_Temp_List(l);
                       			return 1;
                   			 }
					case 2:
					choose = ChooseItems(t, l, tttrang, tongtrang);
                    temp1 = binarySearch_Temp_List(l, choose);
                    if (temp1 == NULL)
                    {
                        return 1;
                    }
                    else 
                    {
                        temp2 = find_VT(t, temp1->tl.MAVT);
						if (temp2->VT.trong_hoa_don)
						{
							CreateBox(X_NOTIFY, Y_NOTIFY, "NOTIFICATIONS:  ", 59);
							// In dong thong bao .
							for (int i = 0; i < 5; i++)
							{
							SetColor(BLUE);
							gotoxy(X_NOTIFY + 15, Y_NOTIFY);
							Sleep(100);
							cout << " VAT TU DA CO TRONG HOA DON. KHONG THE XOA";
							Sleep(500);
							}
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
							ClearAll_Temp_List(l);
							return 1;
						}
                        check = IsDeleted_VT(t, temp2->VT);
						ClearAll_Temp_List(l);
                        return 1;
                    }
					case 3:
					  ClearAll_Temp_List(l);
                    return 0;
				}
			
            }
            
        }
		
        ShowCur(false);
        gotoxy(3, 36);
		SetColor(BLACK);
        cout << "Trang " << tttrang << " / " << tongtrang;
		gotoxy(135, yHotkey + 1 );
		SetColor(GREEN);
		cout << "F10-LUU";
		


    }while (true);
	



		

}
void Menu_VT(TREE_VT &t)
{
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

    do
    {
        clrscr();
		gotoxy(26, 1);
		cout << "~~~CAP NHAT VAT TU~~~ ";
		normalBGColor();
		VAT_TU vt;
		int index = 0;

		
        LIST_TEMP_LIST l;
        initList_Temp_List(l);
        Create_Temp_List(t, l, index);
		DisplayVT(keyDisplayVT, 5, xDisplayDS);
		//keyDisplayVT là một mảng gồm 5 tiêu đề cột: "MA VT", " TEN VT", "DVT ", "SL", "TRONG HD".

		Menu_Vat_Tu(keymenu_vat_tu,5);
		//{ "MENU VAT TU","THEM VAT TU |F2", "CHINH SUA VAT TU|F3", "XOA VAT TU|F4","THOAT|ESC" };
		esc = Output_ListVT(t, l, vt, tttrang);  // esc chỉ false khi ấn phím esc hoặc chọn chức năng thoát

    }while (esc);  // vòng lặp vô tận cho đến khi thoát
		
}
void Create_Temp_List(TREE_VT t, LIST_TEMP_LIST &l, int &index)
{
	//Hàm Create_Temp_List được sử dụng để tạo danh sách tạm thời từ cây nhị phân t. Danh sách tạm thời này chứa các phần tử của cây theo thứ tự tăng dần.
	if (t == NULL) return; // Nếu cây rỗng thì không làm gì cả
    Create_Temp_List(t->left, l, index);  // Duyệt cây con bên trái trước
    addTailList_Temp_List(l, index++, t->VT.MAVT, t->VT.ten);  // Thêm phần tử hiện tại vào danh sách tạm thời, các phần tử thêm vào sẽ có index tăng 
    Create_Temp_List(t->right, l, index);   // Sau đó duyệt cây con bên phải
	//thứ tự của các phần tử trong danh sách tạm thời sẽ giống với thứ tự các phần tử trong cây nhị phân tăng dần theo mã vật tư. ( 1 2 3 4 5 )
}
void ClearAll_Temp_List(LIST_TEMP_LIST &l)
{
    NODE_TEMP_LIST *p;
    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->next;
        delete p;
    }
}
NODE_TEMP_LIST* Middle(NODE_TEMP_LIST* start, NODE_TEMP_LIST* last) {
	if (!start) return NULL; // Nếu start là NULL, trả về NULL
	NODE_TEMP_LIST* slow = start; // Khởi tạo con trỏ slow từ start
	NODE_TEMP_LIST* fast = start->next; // Khởi tạo con trỏ fast từ start->next
	while (fast != last) { // Duyệt danh sách cho đến khi fast đạt last
		fast = fast->next; // Di chuyển fast một bước
		if (fast != last) { // Nếu fast chưa đến last
			slow = slow->next; // Di chuyển slow một bước
			fast = fast->next; // Di chuyển fast thêm một bước
		}
	}
	return slow; // Trả về con trỏ slow, đây chính là điểm giữa của danh sách
}
NODE_TEMP_LIST *binarySearch_Temp_List(LIST_TEMP_LIST l, uint index)
{
	//Hàm binarySearch_Temp_List được sử dụng để tìm kiếm một phần tử trong danh sách LIST_TEMP_LIST theo chỉ mục index bằng phương pháp tìm kiếm nhị phân.
    NODE_TEMP_LIST *start = l.pHead;
    NODE_TEMP_LIST *last = NULL;  // gán last = NULL vi ko the biet chieu dai cua dslkd 
    do
    {
        // Find middle
        NODE_TEMP_LIST *mid = Middle(start, last);
        // if middle is empty
        if (mid == NULL)
            return NULL;
        
        // if value is present at middle
        if (mid->tl.index == index)
            return mid;
        // if value is more than mid
        else if (mid->tl.index < index)
            start = mid->next;
        // if value is less than mid
        else 
            last = mid;
    }while (last == NULL || last != start);
    return NULL; // value not present
}
int ChooseItems(TREE_VT &t, LIST_TEMP_LIST &l, int tttrang, int tongtrang)
{
	//Hàm ChooseItems được sử dụng để cho phép người dùng chọn các mục trong danh sách hiển thị. 
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(REG_DWORD);
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
	cout << "<<";
	gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
	cout << ">>";
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc ( xoa dau << >> o duoi )
				SetColor(REG_DWORD);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << "  ";

				(pos > 0) ? pos-- : pos = 28;  // bien pos giam di 1, neu pos truoc do bang 0, cho ve cuoi trang

				// to dau << >> o vi tri moi 
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case KEY_DOWN:
				// xoa muc truoc ( xoa dau << >> o tren )
				SetColor(REG_DWORD);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << "  ";

				(pos < NUMBER_LINES - 1) ? pos++ : pos = 0;   // neu pos o vi tri cuoi cung cua ds, tro lai dau ds, con ko tang vi tri pos len 1

				// to dau << >> o vi tri moi
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
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
				OutputVT_PerPage(t, l, tttrang);

				// cho pos bang 0
				pos = 0;
				SetColor(LIGHT_GREEN);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case PAGE_DOWN:  // trang sau 
				if (tttrang <  tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;  // neu o trang cuoi thi ve trang 1

				}
				
				OutputVT_PerPage(t, l, tttrang);  // hien thi trang do

				// cho pos bang 0
				pos = 0;
				SetColor(LIGHT_GREEN);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case ENTER:

				// tra ve vi tri pos. tương ứng với vị trí của phần tử trong danh sách tạm thời
				return pos + (tttrang - 1)* NUMBER_LINES; 
			}
		}
		ShowCur(false);
		SetColor(WHITE);
		gotoxy(30, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
		normalBGColor();
	}
}
void NhapDonViTinh(string &result, int &ordinal, bool &isSave, bool &isEscape, bool isEdited)
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
			// chi nhan chu thuong va dau cach
			// chi nhap ten vat tu toi da 10 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
				&& count < MAX_DVT && count >= 0) //count >= 0 de dam bao ko backspace khi ko co ky tu nao 
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit; 
					result += (char)kb_hit;
					nSpace = 0;  // nSpace = 0, không cho phép nhập tiếp dấu cách
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;  //in ra ky tu vua nhap
					result += (char)kb_hit; //them ky tu vua nhap vao result
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					//Nếu người dùng nhấn phím mũi tên lên, chúng ta sẽ trả về vị trí 0 để quay lại trường nhập trước đó.
					ordinal = 0;
					return;
				}
				else
				{
					if (isEdited)
					{
						// trả về vị trí 0 để quay lại trường nhập tên vật tư
						ordinal = 0;
						return;
					}
					else 
					{
						// trả về vị trí 2 để quay lại trường nhập mã số lượng tồn ( thêm mới )
						ordinal = 2;
						return;
					}
					
				}
			}
			else if (kb_hit == ENTER) // chức năng giống phím mũi tên xuống 
			{
				if (isEdited)
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
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b"; //	xoa ky tu cuoi cung
				//b là một ký tự đặc biệt đại diện cho ký tự backspace. Khi in ký tự \b lên màn hình, nó sẽ di chuyển con trỏ về vị trí trước đó trên cùng một dòng.
				count--; // giam bien dem
				result.erase(result.length() - 1, 1); // xoa ky tu cuoi cung trong result
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
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << " TOI DA 10 KY TU,CHI LAY KY TU CHU!!!      ";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}
void NhapSoLuongTon(string &result,int choice ,int &ordinal, bool &isSave, bool &isEscape)
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
			if (((kb_hit >= 48 && kb_hit <= 57)) && count < (choice == 1 ? MAX_THUE : MAX_SLT) && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
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

			}  //choice để phân biệt các trường nhập trong hóa đơn, bởi vì hàm này được sử dụng cho nhiều trường hợp
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					if (choice == 0)
					{
						ordinal = 3;
						return;
					}
					else if (choice == 1)
					{
						ordinal = 0;
						return;
					}
					else if (choice == 2 || choice == 5)
					{
						ordinal = 1;
						return;
					}
					else if (choice == 3) // nhap don gia trong chi tiet hoa don
				    {
						ordinal = 2;
						return;
					}
					else if (choice == 10) // nhập thuế có edit
					{
						ordinal = 2;
						return;
					}
					else if (choice == 11) // nhập số lượng có edit
					{
						ordinal = 0;
						return;
					}
					else if (choice == 12) // nhập đơn giá có edit
					{
						ordinal = 1;
						return;
					}
				}
				else // key down
				{
					if(choice == 0) // ma vat tu
					{
						ordinal = 1;
						return;
					}
					else if (choice == 1 ) // thue
					{
						ordinal = 2;
						return;
					}
					else if (choice == 2) // so luong ton
					{
						ordinal = 0;
						return;
					}
					else if (choice == 5) // so luong trong chi tiet hoa don
					{
						ordinal = 3;
						return;
					}
					else if (choice == 3) // don gia trong chi tiet hoa don
					{
						ordinal = 0;
						return;
					}
					else if (choice == 11) //  số lượng có edit
					{
						ordinal = 2;
						return;
					}
					else if (choice == 10) // thuế edit
					{
                        ordinal = 1;
						return;
					}
					else if (choice == 12) // don gia co edit
					{
						ordinal = 0;
						return;
					}
				}
			}
			else if (kb_hit == ENTER)
			{
				if(choice == 0)
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
						ordinal = 0;
						return;
					}
					else if (choice == 5)
					{
						ordinal = 3;
						return;
					}
					else if (choice == 3)
					{
						ordinal = 0;
						return;
					}
					else if (choice == 11) //  số lượng có edit
					{
						ordinal = 2;
						return;
					}
					else if (choice == 10) // thuế edit
					{
                        ordinal = 1;
						return;
					}
					else if (choice == 12) // don gia co edit
					{
						ordinal = 0;
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
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << " TOI DA 9 CHU SO !!!                        ";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}
/////////// RANDOM VT  ///////////////
string Tao_Ma_VT(TREE_VT t)
{
	string result = "VT0000";
	do
	{
		result[2] = rand() % (57- 49 + 1) + 49;
		for (int i = 3; i < result.length(); i++)
		{
			result[i] = rand() % (57 - 48 + 1) + 48;
		}
	}while(Kiem_Tra_Trung_MAVT(t, result));
	return result;
}
bool Kiem_Tra_Trung_MAVT(TREE_VT t, string key)
{
	if (t == NULL)
		return false;
	if (So_Sanh_Ma_VT(key, t->VT.MAVT) > 0)
		return Kiem_Tra_Trung_MAVT(t->right, key);
	else if (So_Sanh_Ma_VT(key, t->VT.MAVT) < 0)
		return Kiem_Tra_Trung_MAVT(t->left,key);
	else // ton tai
		return true;
}

int So_Sanh_Ma_VT(string a, string b)
{
	// cat chuoi lay ma vat tu
	string  temp_a = a.substr(2);   // cat cac so sau "VT"
	string temp_b = b.substr(2);    // cat cac so sau "VT"
	int so_a = atoi(temp_a.c_str());  //chuyển từ string sang một con trỏ trỏ tới mảng kí tự
	int so_b = atoi(temp_b.c_str());  //chuyển từ string sang một con trỏ trỏ tới mảng kí tự
	if (so_a > so_b)
		return 1;
	else if (so_a < so_b)
		return -1;
	else 
		return 0;
}

void Nhap_Ma_VT(string &result, int &ordinal, bool &isSave, bool &isEscape)
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
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57))
				&& count < MAX_MA_VT && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
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
					ordinal = 3;
					return;
				}
				else
				{
					ordinal = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 1;
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
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA " << MAX_MA_VT << " KY TU, CHI LAY KY TU CHU VA SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}

///////////////////////////////////////////IN DS VT//////////////////////////////////////////////////

int Output_ListVT_TEN(TREE_VT &t, LIST_TEMP_LIST &l, VAT_TU &vt, int &tttrang)
{
	

    // nNV la so NV hien co trong cay
    int nVT = countVT(t);

    // thu tu trang
    int tongtrang;
    tongtrang = (nVT / NUMBER_LINES) + 1;
    OutputVT_PerPage(t,l,tttrang);

    int kb_hit;
	ShowCur(false);
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
				OutputVT_PerPage(t,l,tttrang);
				break;
			
			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputVT_PerPage(t,l,tttrang);
				break;
            case ESC:
                    ClearAll_Temp_List(l);
                    return 0;
			
            }
            
        }
		
        ShowCur(false);
        gotoxy(3, 36);
		SetColor(BLACK);
		cout<<"Trang "<<tttrang<<" /"<<tongtrang<<"  "<<"PagUP-Trang Truoc, PagDn-Trang Sau";
		


    }while (true);

}


void Menu_In_DS_VT(TREE_VT &t)
{

	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

    do
    {
        clrscr();
		gotoxy(25, 1);
		cout << "~~~DANH SACH VAT TU~~~";


		normalBGColor();
		VAT_TU vt;
		int index = 0;

		// cho nay thay doi cau truc DSLK TEMPLIST bang Mang cap phat dong hay hon...
        LIST_TEMP_LIST l;
        initList_Temp_List(l);
        Create_Temp_List(t, l, index);
		Sort_Temp_list_Name(l);
		DisplayVT(keyDisplayVT, 5, xDisplayDS);
		esc = Output_ListVT_TEN(t, l, vt, tttrang);

    }while (esc);
		
}

void Output_VT(NODE_VT* vt, int& locate)
{
	Xoa_OutNV_1line(locate);
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
	cout << vt->VT.MAVT;
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << vt->VT.ten;
	gotoxy(xDisplayDS[2] + 2, yDisplay + 3 + locate);
	cout << vt->VT.don_vi_tinh;
	gotoxy(xDisplayDS[3] + 3, yDisplay + 3 + locate);
	cout << vt->VT.so_luong_ton;
	gotoxy(xDisplayDS[4] + 4, yDisplay + 3 + locate);
	(vt->VT.trong_hoa_don == true) ? cout << "CO" : cout << "KHONG";
}

NODE_TEMP_LIST *getNode_Temp_List(uint index, string MAVT, string ten)
{
    NODE_TEMP_LIST *p = new NODE_TEMP_LIST;
    p->tl.index = index;
    p->tl.MAVT = MAVT;
	p->tl.ten=ten;
    p->next = NULL;
    return p;
}
void addTailList_Temp_List(LIST_TEMP_LIST &l, uint index, string MAVT, string ten)
{
    NODE_TEMP_LIST *p = getNode_Temp_List(index, MAVT,ten);
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else 
    {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void Sort_Temp_list_Name(LIST_TEMP_LIST &l)
{
	if(l.pHead==NULL) return;
	NODE_TEMP_LIST *p1,*p2;
	for(p1=l.pHead;p1!=NULL;p1=p1->next)
	{
		for(p2=p1->next;p2!=NULL;p2=p2->next)
		{
			if(p1->tl.ten>p2->tl.ten)
			{
				TEMP_LIST temp,temp2;
				temp.ten=p1->tl.ten;
				p1->tl.ten=p2->tl.ten;
				p2->tl.ten=temp.ten;
				temp2.MAVT=p1->tl.MAVT;
				p1->tl.MAVT=p2->tl.MAVT;
				p2->tl.MAVT=temp2.MAVT;
			}
		}
	}

}


