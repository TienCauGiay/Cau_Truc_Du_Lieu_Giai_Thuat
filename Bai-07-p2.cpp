#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class SinhVien{
    private:
        string hoten, quequan, gioitinh;
        int ngay, thang, nam, masv;
    public:
        friend istream& operator>>(istream& is, SinhVien& a);
        friend ostream& operator<<(ostream& os, SinhVien a);
        int& get_masv(){
            return masv;
        }
};

istream& operator>>(istream& is, SinhVien& a){
    cout << "Nhap ho ten: "; fflush(stdin); getline(is, a.hoten);
    cout << "Nhap ma sinh vien: ";cin >> a.masv;
    cout << "Nhap que quan: "; fflush(stdin); getline(is, a.quequan);
    cout << "Nhap gioi tinh: "; fflush(stdin);getline(is, a.gioitinh);
    cout << "Nhap ngay thang nam sinh:\n"; is >> a.ngay >> a.thang >> a.nam;
    return is;
}

ostream& operator<<(ostream& os, SinhVien a){
    cout << setw(20) << a.hoten << setw(7) << a.masv << setw(15) << a.quequan << setw(10) << a.gioitinh << setw(10) << a.ngay << "/" << a.thang << "/" << a.nam << endl;
    return os;
}

template <class T>
class Node{
    private:
        T elem;
        Node * next;
        Node * pre;
    public:
        Node(){next = NULL; pre = NULL;}
        T& get_elem(){return elem;}
        Node * get_next(){return next;}
        Node * get_pre(){return pre;}
        void set_elem(T e){elem = e;}
        void set_next(Node * p){next = p;}
        void set_pre(Node * p){pre = p;}
};

template <class T>
class List{
    private:
        Node<T> * header;
        Node<T> * trailer;
        int count;
    public:
        List(){header = NULL; trailer = NULL; count = 0;}
        int size(){return count;}
        int isEmpty(){return count == 0;}
        Node<T> *first(){return header;}
        Node<T> *last(){return trailer;}
        void replace(Node<T> *p, T e);
        Node<T>* insertafter(Node<T> *p, T e);
        Node<T>* insertbefore(Node<T> *p, T e);
        Node<T>* insertfirst(T e);
        Node<T>* insertlast(T e);
        void remove(Node<T> *p);
        Node<T> *getNode(int i);
};

template <class T>
void List<T>::replace(Node<T> *p, T e){
    p->set_elem(e);
}

template <class T>
Node<T>* List<T>::insertbefore(Node<T> *p, T e){
    Node<T> *q;
    q = new Node<T>;
    q->set_elem(e);
    if(p == header)
    {
        header->set_pre(q);
        q->set_next(header);
        header = q;
    }
    else 
    {
        p->get_pre()->set_next(q);
        q->set_pre(p->get_pre());
        q->set_next(p);
        p->set_pre(q);
    }
    count++;
    return q;
}

template <class T>
Node<T>* List<T>::insertafter(Node<T> *p, T e){
    Node<T> *q;
    q = new Node<T>;
    q->set_elem(e);
    if(p == trailer)
    {
        p->set_next(q);
        q->set_pre(p);
        trailer = q;
    }
    else
    {
        q->set_next(p->get_next());
        p->get_next()->set_pre(q);
        p->set_next(q);
        q->set_pre(p);
    }
    count++;
    return q;
}

template <class T>
Node<T>* List<T>::insertfirst(T e){
    Node<T> *q;
    q = new Node<T>;
    q->set_elem(e);
    if(isEmpty())
    {
        header = q;
        trailer = q;
    }
    else
    {
        q->set_next(header);
        header->set_pre(q);
        header = q;
    }
    count++;
    return q;
}

template <class T>
Node<T>* List<T>::insertlast(T e){
    Node<T> *q;
    q = new Node<T>;
    q->set_elem(e);
    if(isEmpty())
    {
        header = q;
        trailer = q;
    }
    else
    {
        q->set_pre(trailer);
        trailer->set_next(q);
        trailer = q;
    }
    count++;
    return q;
}

template <class T>
void List<T>::remove(Node<T> *p){
    if(p == header)
    {
        header = header->get_next();
        if(header != NULL)
            header->set_pre(NULL);
    }
    else if( p == trailer)
    {
        trailer = trailer ->get_pre();
        if(trailer != NULL)
            trailer->set_next(NULL);
    }
    count--;
}

template <class T>
Node<T>* List<T>::getNode(int i){
    if(i < 0 || isEmpty())
        return NULL;
    int dem = 0;
    Node<T> *p;
    p = header;
    while(p != NULL && dem < i)
    {
        dem++;
        p = p->get_next();
    }
    return p;
}

template <class T>
class ListItr{    
	private :
		 List<T>* theList;
		 Node<T>* cur;	
	public:
		ListItr(List<T> *L)
		{
			theList = L;		
			cur = theList->first();
		}
		void reset(){
             cur = theList->first();
        }
		int hasNext(){
			return cur!=NULL;				
		}
		T next()
		{
			T o;
			o = cur->get_elem();
			cur = cur->get_next();
			return o;
		}
};

class Listapp{
    private:
        List<SinhVien> a;
    public:
        void run(Listapp a);
        void Insertfirst();
        void Insertlast();
        void Remove();
        void Replace();
        void XuatDs();
        void SApxep();
};

void Listapp::Replace(){
    int mathaythe; SinhVien x;
    cout << "Nhap ma sinh vien can thay the thong tin: "; cin >> mathaythe;
    cout << "Nhap thong tin sinh vien can thay the: "; cin >> x;
    Node<SinhVien> *p;
    p = a.first();
    while(p != NULL && p->get_elem().get_masv() != mathaythe)
    {
        p = p->get_next();
        if(p == NULL)
        {
            cout << "khong tim thay sinh vien co ma " << mathaythe << endl;
        }
        else
        {
            a.replace(p, x);
            cout << "Thay the thanh cong" << endl;
            break;
        }
    }
}

void Listapp::Insertfirst(){
    SinhVien x;
    cout << "Nhap thong tinh sinh vien can them dau: " << endl;
    cin >> x;
    a.insertfirst(x);
    cout << "Them thanh cong" << endl;
}

void Listapp::Insertlast(){
    SinhVien x;
    cout << "Nhap thong tin sinh vien can them cuoi: " << endl;
    cin >> x;
    a.insertlast(x);
    cout << "Them thanh cong" << endl;
}

void Listapp::Remove(){
    int maxoa;
    cout << "Nhap vi tri sinh vien can xoa: ";cin >> maxoa;
    Node<SinhVien> *p;
    p = a.first();
    while(p != NULL && p->get_elem().get_masv() != maxoa)
    {
        p = p->get_next();
        if(p == NULL)
        {
            cout << "khong tim thay sinh vien co ma " << maxoa << endl;
        }
        else
        {
            a.remove(p);
            cout << "Xoa Thanh Cong" << endl;
            break;
        }
    }
}

void Listapp::XuatDs(){
    ListItr<SinhVien> Itr(&a);
    cout << "Danh sach sinh vien: " << endl;
    while(Itr.hasNext())
    {
        cout << Itr.next();
    }
    cout << "size = " << a.size() << endl;
}

void Listapp::SApxep(){
    ListItr<SinhVien> Itr(&a);
}

void Listapp::run(Listapp a){
    Node<SinhVien> *l;
    while(true){
        system("cls");
        cout << " =============== Menu =============== " << endl;
        cout << "1. Them 1 sinh vien vao dau sanh sach" << endl;
        cout << "2. Them 1 sinh vien vao cuoi danh sach" << endl;
        cout << "3. Xoa sinh vien co ma nhap tu ban phim" << endl;
        cout << "4. In ra danh sach sinh vien hien tai" << endl;
        cout << "5. Thay the sinh vien co ma nhap tu ban phim" << endl;
        cout << "6. Sap xep danh sach theo ma sv" << endl;
        cout << "0. Ket thuc" << endl;
        cout << " =============== Menu =============== " << endl;
        int lc; cout << "Nhap lua chon: "; cin >> lc;
        if(lc < 0 || lc > 6)
        {
            cout << "Nhap sai" << endl;
        }
        else if(lc == 1)
        {
            a.Insertfirst();
        }
        else if(lc == 2)
        {
            a.Insertlast();
        }
        else if(lc == 3)
        {
            a.Remove();
            system("pause");
        }
        else if(lc == 4)
        {
            a.XuatDs();
            system("pause");
        }
        else if(lc == 5)
        {
            a.Replace();
            system("pausee");
        }
        else if(lc == 6)
        {
            break;
        }
        else
        {
            break;
        }
    }
}

int main(){
    Listapp a;
    a.run(a);
    system("pause");
    return 0;
}