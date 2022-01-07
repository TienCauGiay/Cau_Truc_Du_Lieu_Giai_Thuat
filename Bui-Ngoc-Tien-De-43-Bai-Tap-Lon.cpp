/*
Ứng dụng lớp List để quản lý các đối tượng là các Khách hàng. Mỗi Khách hàng cần
quản lý các thông tin sau: Mã KH là 1 số nguyên, Họ tên, SĐT.
Viết chương trình cho phép thực hiện các chức năng sau:
Nhập thêm các khách hàng, sau khi hoàn thành nhập thông tin của một khách hàng, chương
trình đưa ra câu hỏi có nhập nữa không (y/n)? Nếu người dùng nhập: Y thì tiếp tục nhập,
nhập N thì kết thúc.
· Sử dụng thuật toán tìm kiếm nhị phân, tìm 1 khách hàng trong danh sách có mã nhập vào
từ bàn phím. Nếu tìm thấy thì hiện ra 1 menu gồm các chức năng:
1. Xóa đi một khách hàng
2. Sửa đổi thông tin họ tên, SĐT của khách hàng·
Hiển thị toàn bộ danh sách khách hàng hiện có.
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class KhachHang{
    private:
        int maKH;
        string hoten, sdt;
    public:
        friend istream& operator>>(istream& is, KhachHang& a);
        friend ostream& operator<<(ostream& os, KhachHang a);
        int get_maKH();
        string& get_hoten();
        string& get_sdt();
};

istream& operator>>(istream& is, KhachHang& a){
    cout << "Nhap ma khach hang: "; is >> a.maKH;
    cout << "Nhap ho ten khach hang: "; fflush(stdin); getline(is, a.hoten);
    cout << "Nhap so dien thoai khach hang: "; fflush(stdin); getline(is, a.sdt);
    return is;
}

ostream& operator<<(ostream& os, KhachHang a){
    os << setw(20) << a.hoten << setw(7) << a.maKH << setw(15) << a.sdt << endl;
    return os;
}

int KhachHang::get_maKH(){
    return maKH;
}

string& KhachHang::get_hoten(){
    return hoten;
}

string& KhachHang::get_sdt(){
    return sdt;
}

class Node{
    private:
        KhachHang elem;
        Node *next;
    public:
        Node();
        Node *getnext();
        void setnext(Node *);
        KhachHang& getelem();
        void setelem(KhachHang);
};

Node::Node(){
    next = NULL;
}

Node* Node::getnext(){
    return next;
} 

void Node::setnext(Node *p){
    next = p;
}

KhachHang& Node::getelem(){
    return elem;
}

void Node::setelem(KhachHang e){
    elem = e;
}

template <class T>
T binarySearch(T arr[], T left, T right, T x) {
    T middle;
    while(left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == x)
            return middle;
        if (x > arr[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

class List{
    private:
        Node *header;
        Node *trailer;
        int count;
    public:
        List();
        int size();
        int isempty();
        Node *first();
        Node *last();
        Node *insertlast(KhachHang e);
        void remove(List &l, Node *p);
        Node *getNode(int i);
};

List::List(){
    header = NULL; trailer = NULL; count = 0;
}

int List::size(){
    return count;
}

int List::isempty(){
    return count == 0;
}

Node* List::first(){
    return header;
}

Node* List::last(){
    return trailer;
}

Node* List::insertlast(KhachHang e){
    Node *q;
    q = new Node;
    q->setelem(e);
    if(isempty())
    {
        header = q;
        trailer = q;
    }
    else
    {
        trailer->setnext(q);
        trailer = q;
    }
    count++;
    return q;
}

void List::remove(List &l, Node* p){
	Node *q;
	if(p==l.first()){
		if(l.size()==1){
			l.header  = NULL;
			l.trailer = NULL;
		}
		else
			l.header = l.header->getnext();		
	}
    else if(p==l.last()){
        if(l.size()==1){
            l.trailer = NULL;
            l.header  =NULL;
        }
        else{
            q = l.header;
            while(q->getnext() != p)
                q = q->getnext();
            if(q != NULL)
                q->setnext(p->getnext());
        }
    }
	else{
		q	= l.header;
		while(q->getnext()!= p)			
			q = q->getnext();
		if(q!=NULL){				
			q->setnext(p->getnext());	
		}
	}
	count--;	
}

Node* List::getNode(int i){
    if(i < 0 || isempty())
        return NULL;
    Node *p;
    int dem = 0;
    p = header;
    while(dem < i && p != NULL)
    {
        dem++;
        p = p->getnext();
    }
    return p;
}

class ListItr{
    private:
        List *a;
        Node * cur;
    public:
        ListItr(List * a1){
            a = a1;
            cur = a->first();
        }
        void reset(){
            cur = a->first();
        }
        int hasnext(){
            return cur != NULL;
        }
        KhachHang next(){
            KhachHang o;
            o = cur->getelem();
            cur = cur->getnext();
            return o;
        }
};

class Listapp{
    private:
        List *a;
    public:
        Listapp();
        void NhapDS();
        void XuatDS();
        void SapXep(List &l);
        void TimKiem(); 
        void run();
};

Listapp::Listapp(){
    a = new List;
}

void Listapp::NhapDS(){
    KhachHang x;
    cout << "Nhap thong tin khach hang: " << endl;
    cin >> x;
    a->insertlast(x);
}

void Listapp::XuatDS(){
    ListItr itr(a);
    cout << "Danh sach khach hang hien tai: " << endl << endl;
    cout << setw(20) << "Ho ten" << setw(7) << "Ma KH" << setw(12) << "SDT" << endl << endl;
    while(itr.hasnext())
    {
        cout << itr.next() << endl;
    }
}

void Listapp::SapXep(List &l){
    Node *i, *j;
    for(i = l.first(); i != NULL; i = i->getnext())
    {
        for(j = i->getnext(); j != NULL; j = j->getnext())
        {
            if(i->getelem().get_maKH() > j->getelem().get_maKH())
            {
                KhachHang tg = i->getelem();
                i->getelem() = j->getelem();
                j->getelem() = tg;
            }
        }
    }
}

void Listapp::TimKiem(){
    SapXep(*a);
    int n = a->size();
    int *x; x = new int[n];
    Node *p; p = a->first();
    int i = -1;
    while(p != NULL)
    {
        x[++i] = p->getelem().get_maKH();
        p = p->getnext();
    }
    int matim; cout << endl << "Nhap ma khach hang can tim: "; cin >> matim;
    int kt = binarySearch(x, 0, n-1, matim);
    if(kt != -1)
    {
        cout << "Tim thay khach hang co ma " << matim << endl;
        while(true){
            Node *kh; kh = a->first();
            string tenthay, sdtthay;
            cout << "1. Xoa di 1 khach hang" << endl;
            cout << "2. Sua thong tin khach hang" << endl;
            cout << "0. Thoat" << endl;
            int lcc; cout << "Nhap lua chon: "; cin >> lcc; 
            if(lcc < 0 || lcc >2)
            {
                cout << "nhap lua chon hop le" << endl;
            }
            else if(lcc == 1)
            {
                while(kh != NULL)
                {
                    if(kh->getelem().get_maKH() == matim)
                    {
                        a->remove(*a, kh);
                        break;
                    }
                    kh = kh->getnext();
                }
            }
            else if(lcc == 2)
            {
                cout << "Nhap ten can thay: "; fflush(stdin); getline(cin, tenthay);
                cout << "Nhap so dien thoay can thay: "; fflush(stdin); getline(cin, sdtthay);
                while(kh != NULL){
                    if(kh->getelem().get_maKH() == matim)
                    {
                        kh->getelem().get_hoten() = tenthay;
                        kh->getelem().get_sdt() = sdtthay;
                    }
                    kh = kh->getnext();
                }
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        cout << "Khong tim thay khach hang co ma " << matim << endl;
    }
};

void Listapp::run(){
    string c;
    KhachHang e;
    while(true){
        cout << " ================= Run ================= " << endl;
        cout << " 1. Nhap them cac khach hang" << endl;
        cout << " 2. Danh sach khach hang hien tai" << endl;
        cout << " 3. Tim kiem khach hang theo ma khach hang" << endl;
        cout << " 0. Ket thuc" << endl;
        cout << " ================= Run ================= " << endl;
        int lc; cout << "Nhap lua chon: "; cin >> lc;
        if(lc < 0 || lc > 3)
        {
            cout << "Nhap lua chon khong hop le" << endl;
            system("pause");
        }
        else if(lc == 1)
        {
            do{
                NhapDS();
                cout << "Ban co muon nhap tiep khong (y/n): "; fflush(stdin); getline(cin, c);
            }while(c != "n");
        }
        else if(lc ==2)
        {
            XuatDS();
            system("pause");
        }
        else if(lc == 3)
        {
            TimKiem();
            system("pause");
        }
        else
        {
            break;
        }
    }
}

int main(){
    Listapp a;
    a.run();
    system("pause");
    return 0;
}