#pragma once

#include"HOA_DON.H"
// ////////////////////////////////////////  GHI FILE ///////////////////////////////////////////////////////
void Duyet_Cay_Ghi(TREE_VT t,fstream &file_vt)    // ham ghi lieu cua mot nut vao mot tep
{
	if(t==NULL) return;     // neu cay t rong thi se tra ve luon
	else 
	{	 
		Duyet_Cay_Ghi(t->left,file_vt);     // ghi du lieu theo thu tu L - N - R
		file_vt<<t->VT.MAVT<<'\n';
		file_vt<<t->VT.ten<<'\n';
		file_vt<<t->VT.don_vi_tinh<<'\n';
		file_vt<<t->VT.so_luong_ton<<'\n';
		file_vt<<t->VT.trong_hoa_don<<'\n';
		Duyet_Cay_Ghi(t->right,file_vt);
	}
}
void Ghi_File_VT(TREE_VT t)   // ghi du lieu tu cay ra file
{
	fstream file_vt;   //khoi tao mot doi tuong file_vt 
	file_vt.open(".\\file\\danhsachvattu.txt", ios::out); // mo file va su dung mode ios::out de chi ra rang tep se dc mo de ghi 
	if(!file_vt) cout<<"KHONG MO DUOC FILE GHI !!!";   //kiem tra xem tep co mo duoc k
	else 
	{
		file_vt<<countVT(t)<<endl;  // ghi so luong vat tu bang cach dung ham countVT
		Duyet_Cay_Ghi(t,file_vt); 
	}
	file_vt.close();
}
void Doc_File_VT(TREE_VT &t)
{
	fstream file_vt;
	VAT_TU p;  // Khoi tao mot cau truc vat tu p
	int countvt;   //bien luu so luong vt
	file_vt.open(".\\file\\danhsachvattu.txt",ios::in); // mo tep tin de doc, su dung mode ios::in
	if(!file_vt) return;
	if(file_vt.is_open())
	{
		file_vt>>countvt;      // doc so luong vat tu tu file
		file_vt.ignore();      // bo qua dau xuong dong \n
		for(int i=0;i<countvt;i++)  // vong lap de doc tat ca cac vat tu co trong file
		{
		getline(file_vt,p.MAVT);
		getline(file_vt,p.ten);
		getline(file_vt,p.don_vi_tinh);
		file_vt>>p.so_luong_ton;
		file_vt.ignore();
		file_vt>>p.trong_hoa_don;  //trang thai
		file_vt.ignore();
		insertVTToTree(t,p);  // sau khi vat tu p dc ghi du lieu tu file, tien hanh them vao cay
		}
	}
}

void Ghi_File_NV(DS_NV ds)   
{
	fstream file_nv;
	file_nv.open(".\\file\\danhsachnhanvien.txt", ios::out);
	file_nv<<ds.n<<'\n';    // so luong nhan vien
	for(int i=0;i<ds.n;i++)   //duyet tung nhan vien 
	{
		file_nv<<ds.ds[i]->MANV<<'\n';
		file_nv<<ds.ds[i]->ho<<'\n';
		file_nv<<ds.ds[i]->ten<<'\n';
		file_nv<<ds.ds[i]->gioitinh;	
		if(countds_hd(ds.ds[i]->ds_hd)!=0) file_nv<<'\n';  // neu nhan vien ko co hoa don in ra -1
		else file_nv<<'\n'<<-1<<'\n';
		if(ds.ds[i]->ds_hd.pHead!=NULL)  //kiem tra xem danh sach lien ket don hoa don co rong k, neu rong thi ko lam gi ca 
		{
			file_nv<<countds_hd(ds.ds[i]->ds_hd)<<'\n';     //ghi so luong hoa don cua nv ra file
			for(NODE_HD* p = ds.ds[i]->ds_hd.pHead;p!=NULL;p=p->next) //duyet dslkd hoa don
			{	
				file_nv<<p->HD.MAHD<<'\n';
				file_nv<<p->HD.ngay_lap_hd.Ngay<<'\n';
				file_nv<<p->HD.ngay_lap_hd.Thang<<'\n';
				file_nv<<p->HD.ngay_lap_hd.Nam<<'\n';
				file_nv<<p->HD.loai<<'\n';
				file_nv<<p->HD.tong_tien << '\n';
				file_nv<<countds_ct_hd(p->HD.ds_ct_hd)<<'\n'; //tiep tuc ghi so luong chi tiet trong hoa don
				for(NODE_CTHD *curNode = p->HD.ds_ct_hd.pHead;curNode != NULL;curNode = curNode = curNode->next) //duyet dslkd chi tiet hoa don
				{
					file_nv<<curNode->CTHD.MAVT<<'\n';
					file_nv<<curNode->CTHD.so_luong<<'\n';
					file_nv<<curNode->CTHD.don_gia<<'\n';
					file_nv<<curNode->CTHD.thue<<'\n';
				}
			}
		}
	}
}
void Doc_File_NV(DS_NV& ds, bool* use)
{
	fstream file_nv;
	int countds_nv = 0, countds_hd = 0, countds_ct_hd = 0;  //tao 3 bien dem ds nhanvien, ds hoa don, ds ct hoa don
	file_nv.open(".\\file\\danhsachnhanvien.txt", ios::in);
	if (file_nv.is_open())
	{
		file_nv >> countds_nv;   // doc so luong nhan vien
		file_nv.ignore();
		for (int i = 0; i < countds_nv; i++)   // doc tung nhan vien
		{
			NHAN_VIEN* nv = new NHAN_VIEN;   // tao mot con tro nhan vien tam
			file_nv >> nv->MANV;
			use[nv->MANV] = true; // ma nay da duoc dung
			file_nv.ignore();
			getline(file_nv, nv->ho);
			getline(file_nv, nv->ten);
			file_nv >> nv->gioitinh;
			file_nv.ignore();

			file_nv >> countds_hd;    // doc so luong hoa don
			file_nv.ignore();
			DS_HD dshd;
			if (countds_hd != -1)   //kiem tra xem hoa don co ton tai hay k
				for (int j = 0; j < countds_hd; j++)
				{
					HOA_DON p;
					getline(file_nv, p.MAHD);
					file_nv >> p.ngay_lap_hd.Ngay;
					file_nv.ignore();
					file_nv >> p.ngay_lap_hd.Thang;
					file_nv.ignore();
					file_nv >> p.ngay_lap_hd.Nam;
					file_nv.ignore();
					file_nv >> p.loai;

					file_nv >> p.tong_tien;
					file_nv.ignore();
					file_nv >> countds_ct_hd;
					file_nv.ignore();
					for (int l = 0; l < countds_ct_hd; l++)    // duyet tung chi tiet hoa don
					{
						CHI_TIET_HOA_DON k;
						getline(file_nv, k.MAVT);
						file_nv >> k.so_luong;
						file_nv.ignore();
						file_nv >> k.don_gia;
						file_nv.ignore();
						file_nv >> k.thue;
						file_nv.ignore();
						Insert_CT_HD(p.ds_ct_hd, k);    // them cthd k vao hd p
					}
					Them_HD_Vao_DS(p, dshd); // them hd p vao dshd
				}
			nv->ds_hd = dshd;
			ds.ds[i] = nv; // them nhan vien
			ds.n++;
		}
	}
	Sap_Xep_NV_Name(ds); //quicksort sap xep tang dan theo ten + ho sau khi doc xong
	file_nv.close();
}