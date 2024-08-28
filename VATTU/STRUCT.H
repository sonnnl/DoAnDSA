#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include "mylib.h"
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include "Macro.h"

using namespace std;
#define MAX_CT_HD 20
#define MAX_NV 500
#define MAX_VT_GIA 100
#define MAX_VT 100

typedef unsigned int uint;
//===============================VAT TU======================
struct VatTu
{
	string MAVT;
	string ten;
	string don_vi_tinh;
	uint so_luong_ton;
	bool trong_hoa_don;
};
typedef struct VatTu VAT_TU;

struct NodeVT
{
	VAT_TU VT;
	NodeVT *left;
	NodeVT *right;
};
typedef NodeVT NODE_VT;
typedef NODE_VT *TREE_VT;

//===============================HOA DON======================
struct ngay_lap_hd
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct ngay_lap_hd NGAY_LAP_HD;
struct chi_tiet_hd
{
	string MAVT;
	int so_luong;
	int thue;
	int don_gia;
};
typedef struct chi_tiet_hd CHI_TIET_HOA_DON;
struct node_cthd
{
	CHI_TIET_HOA_DON CTHD;
	struct node_cthd *next;
};
typedef struct node_cthd NODE_CTHD;
struct ds_ct_hd
{
	NODE_CTHD *pHead = NULL;
	NODE_CTHD *pTail = NULL;     // them ptail de them vao cuoi de hon
};
typedef struct ds_ct_hd DS_CT_HD;
struct hoa_don
{
	string MAHD;
	NGAY_LAP_HD ngay_lap_hd;
	char loai;
	DS_CT_HD ds_ct_hd;
	uint tong_tien;
};
typedef struct hoa_don HOA_DON;

struct node_hd
{
	HOA_DON HD;
	struct node_hd *next;
};
typedef struct node_hd NODE_HD;

struct ds_hd
{
	NODE_HD *pHead = NULL;
	NODE_HD *pTail = NULL;     // them ptail de them vao cuoi de hon
};
typedef ds_hd DS_HD;

//===============================NHAN VIEN======================
struct NhanVien
{

	uint MANV;
	string ho;
	string ten;
	uint gioitinh;
	DS_HD ds_hd;
};
typedef struct NhanVien NHAN_VIEN;

struct ds_nv
{
	NHAN_VIEN *ds[MAX_NV];
	int n = 0;
};
typedef struct ds_nv DS_NV;
bool MaIsUse[MAX_NV + 1]; //ma nhan vien da duoc su dung chua
int MaRand[MAX_NV + 1]; //mang chua ma nhan vien duoc tao ra ngau nhien
//===============================OTHER======================

struct subVT //cau truc tam thoi luu ten, ma vt
{
	string ten;
	string MAVT;
};
typedef struct subVT SUBVT;

struct subListVT //cau truc tam thoi luu danh sach vat tu de dung trong tim kiem vat tu
{
	SUBVT* arr[MAX_VT];
	int n=0;
};
typedef struct subListVT SUBLISTVT;
//===========================================================
struct temp_list //cau truc tam thoi luu index, ten, ma vt
{
	uint index;
	string ten;
	string MAVT;
};
typedef struct temp_list TEMP_LIST;

struct node_temp_list
{
	TEMP_LIST tl;
	struct node_temp_list *next;
};
typedef node_temp_list NODE_TEMP_LIST;

struct list_temp_list
{
	NODE_TEMP_LIST *pHead;
	NODE_TEMP_LIST *pTail;
};
typedef struct list_temp_list LIST_TEMP_LIST;
//Danh sách tạm thời lưu trữ các phần tử vật tư trong quá trình thao tác với dữ liệu.
//  Nó giúp dễ dàng truy xuất và hiển thị thông tin mà không cần thay đổi trực tiếp cấu trúc cây gốc (TREE_VT).
//===========================================================DSVT_GIA======================
struct vat_tu_gia 

{
	string MAVT;
	uint gia = 0;
};
typedef struct vat_tu_gia VAT_TU_GIA;
struct ds_vat_tu_gia
{
	VAT_TU_GIA *ds[500];
	uint n = 0;
};
typedef struct ds_vat_tu_gia DS_VAT_TU_GIA;

// #endif
