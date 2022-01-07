/*
Bài tập
- Xây dựng lớp Node
- Xây dựng lớp DblList
- Xây dựng lớp DblItr //Lớp bộ lặp
- Xây dựng lớp ứng dụng sử dụng lớp Danh sách liên kết kép để
lưu trữ 1 danh sách sinh viên. Mỗi sinh viên gồm các thông tin
sau: MaSv, Hoten, Ngay, Thang, Nam sinh, gioi tinh, que quan.
Yêu cầu lớp có các các chức năng sau:
- Thêm một sinh viên vào cuối DS
- Thêm một sinh viên vào đầu DS
- Xóa bỏ sinh viên thứ i khỏi DS
- Thay thế sinh viên thứ i bằng một sinh viên mới
Xây dựng chương trình để chạy lớp ứng dụng
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class SinhVien{
    private:
        string hoten, masv, quequan, gioitinh;
        int ngay, thang, nam;
    public:  
        friend istream& operator>>(istream& is, SinhVien &a);
        friend ostream& operator<<(ostream& os, SinhVien a);
        string get_masv(){
            return masv;
        }
};

istream& operator>>(istream& is, SinhVien &a){
    cout << "Nhap ho ten: "; fflush(stdin); getline(is, a.hoten);
    cout << "Nhap ma sinh vien: "; fflush(stdin); getline(is, a.masv);
    cout << "Nhap quen quan: "; fflush(stdin); getline(is, a.quequan);
    cout << "Nhap gioi tinh: "; fflush(stdin); getline(is, a.gioitinh);
    cout << "Nhap ngay thang nam sinh:\n"; is >> a.ngay >> a.thang >> a.nam;
    return is;
}

ostream& operator<<(ostream& os, SinhVien a){
    os << setw(20) << a.hoten << setw(7) << a.masv << setw(15) << a.quequan << setw(10) << a.gioitinh << setw(10) << a.ngay << "/" << a.thang << "/" << a.nam << endl;
    return os;
}

template <class T>
class Node{
    private:
        T elem;
        Node *next;
        Node *pre;
    public:
        Node(){next = NULL; pre = NULL;}
        T get_elem(){
            return elem;
        }
        Node *get_pre(){
            return pre;
        }
        Node *get_next(){
            return next;
        }
        void set_elem(T e){
            elem = e;
        }
        void set_next(Node *p){
            next = p;
        }
        void set_pre(Node *p){
            pre = p;
        }
};

template <class T>
class List{
    private:
        Node<T> *header;
        Node<T> *trailer;
        int count;
    public:
        List(){header = NULL; trailer = NULL; count = 0;}
        int size(){
            return count;
        }
        int isEmpty(){
            return count == 0;
        }
        Node<T> *first(){return header;}
        Node<T> *last(){return trailer;}
        void replace(Node<T>*p, T e);
        Node<T> * insertAfter(Node<T> *p, T e);
        Node<T> * insertBefore(Node<T> *p, T e);
        Node<T> * insertFirst(T e);
        Node<T> * insertLast(T e);
        void remove(Node<T> *p);
        Node<T> *getNode(int i);
};

template <class T>
void List<T>::replace(Node<T> *p, T e){
    p->set_elem(e);
}

template <class T>
Node<T>* List<T>::insertAfter(Node<T> *p, T e){
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
        q->set_pre(p);
        p->set_next(q);
    }
    count++;
    return q;
}

template <class T>
Node<T> * List<T>::insertBefore(Node<T> *p, T e){
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
        p->getPre()->setNext(q);
		q->setPre(p->getPre());
		q->setNext(p);
		p->setPre(q);
    }
    count++;
    return q;
}

template <class T>
Node<T> * List<T>::insertFirst(T e){
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
Node<T> * List<T>::insertLast(T e){
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
        trailer->set_next(q);
        q->set_pre(trailer);
        trailer = q;
    }
    count++;
    return q;
}

template <class T>
		void List<T>::remove(Node<T> *p)
		{
			if(p==header)
			{
				header = header->get_next();
				if(header!=NULL)
					header->set_pre(NULL);
			}
			else
			if(p==trailer)
			{
				trailer = trailer->get_pre();
				if(trailer!=NULL)
				   trailer->set_next(NULL);
			}
			else
			{
					p->get_next()->set_pre(p->get_pre());
					p->get_pre()->set_next(p->get_next());
			 }
			 delete p;
			 count--;  
		}


template <class T>
Node<T>* List<T>::getNode(int i){
    if(i < 0 || isEmpty())
        return NULL;
    Node<T> *p;
    int dem = 0;
    p = header;
    while(dem < i && p != NULL)
    {
        dem++;
        p = p->get_next();
    }
    return p;

}

template <class T>
class ListItr{     //list iterator
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
		//----------------------------------------
		T next()
		{
			T o;
			o = cur->get_elem();
			cur = cur->get_next();
			return o;
		}
};//End of class ListItr


class ListApp  //Lop ung dung lop List va lop ListItr
{
	private:
		List<SinhVien> list;
	public:
		int menu();
		void run();
	  //	void GetElement();
		void InsertFirst();
		void InsertLast();
		void RemoveElement();
		void ListElement();
};
int ListApp::menu()
{
	cout<<"1.Them mot phan tu vao dau danh sach";
	cout<<"\n2.Them mot phan tu vao cuoi danh sach";
	cout<<"\n3.Xoa bo mot phan tu";
	cout<<"\n4.In danh sach cac phan tu co trong danh";
	cout<<"\n5.Ket thuc chuong trinh";
	cout<<"\nChon chuc nang tu 1..5:";
	int n;
	cin>>n;
	return n;
}
void ListApp::run()
{
  int ch;
  do{
	  ch = menu();
	  switch(ch)
	  {
		 case 1:
			  InsertFirst();
			  break;
		 case 2:
			  InsertLast();
			  break;
		 case 3:
			  RemoveElement();
			  break;
		 case 4:
			  ListElement();
			  break;
	 }
	 system("pause");
  }while(ch!=5);
}
void ListApp::InsertFirst()
{
	 SinhVien x;	
	 cout<<"Nhap thong tin sinh vien:";
	 cin>>x;
	 list.insertFirst(x);
	 cout<<"Them phan tu vao dau danh sach thanh cong!";	
}
void ListApp::InsertLast()
{
	 SinhVien x;	
	 cout<<"Nhap thong tin sinh vien:";
	 cin>>x;
	 list.insertLast(x);
	 cout<<"Them phan tu vao cuoi danh sach thanh cong!";	
}
void ListApp::RemoveElement()
{
	 string x;
	 cout<<"Nhap ma sinh vien can xoa:";
	 fflush(stdin); getline(cin, x);
	 Node<SinhVien>* p;
	 p=list.first();
	 while(p!=NULL && p->get_elem().get_masv()!=x)
		p = p->get_next();
	 if(p==NULL)
		cout<<"Khong tim thay sinh vien co ma "<<x;
	 else
	 {
		 list.remove(p);
		 cout<<"Da xoa sinh vien co ma "<<x;
	 }	
}
 void ListApp::ListElement()
 {
	ListItr<SinhVien> Itr(&list);
	cout<<"Danh sach sinh vien:\n";
	while(Itr.hasNext())
	   cout<<Itr.next()<<"\n";	
 }


int main(){
    ListApp a;
    a.run();
    system("pause");
    return 0;
}