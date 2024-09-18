#include<iostream>
using namespace std;
//��������
typedef struct list {
	int data;
	struct list* next;
}node,*pnode;
//��������
void createlist(pnode& head, pnode& p) {
	head = new node;
	head->next = nullptr;
	p = head;
}
//������ݵ���β
void adddata(pnode& X, int& x) {
	pnode d = new node;
	d->data = x;
	d->next = nullptr;
	X->next = d;
	X = d;
}
//��ӡ����
void Print(pnode& head) {
	pnode a = head->next;
	if (a == nullptr) {
		cout << "List is empty" << endl;
	}
	while (a) {
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
}
//ɾ��ָ������
void deletedata(pnode& head, int& x) {
	pnode p = head->next;
	pnode prior = head;
	bool a = false;
	if (p == nullptr) {
		cout << "List is empty" << endl;
	}
	while (p) {
		if (p->data == x) {
			prior->next = p->next;
			delete p;
			p = prior->next;
			a = true;
		}
		else {
			prior = p;
			p = p->next; 
		}
	}
	if (a == false) {
		cout << "This data is not in list" << endl;
	}
}
//�޸�ָ������
void changedata(pnode& head,int &x,int &changedata) {
	pnode p = head->next;
	bool a = false;
	while (p) {
		if (p->data == x) {
			p->data = changedata;
			a = true;
		}
		else p = p->next;
	}
	if (a == false)cout << "no" << endl;
}
//����������
void linklist1(pnode& p, pnode& head2) {
	p->next = head2->next;
	delete head2;
}

void linklist2(pnode& head1, pnode& head2) {
	if (head1->next == nullptr) {
		head1->next = head2->next;
		delete head2;
		return;
	}
	else if (head2->next == nullptr) {
		delete head2;
		return;
	}
	else {
		pnode p = head1->next;
		pnode prior = p;
		while (p != nullptr) {
			prior = p;
			p = p->next;
		}
		p = prior;
		p->next = head2->next;
		delete head2;
	}
}
//��������
void tsil(pnode& head) {
	if (head->next == nullptr)return;
	else if (head->next->next == nullptr)return;
	else {
		pnode prior = head->next;
		pnode p = prior->next;
		prior->next = nullptr;
		while (p) {
			head->next = p;
			p = p->next;
			head->next->next = prior;
			prior = head->next;
		}
	}
}
//������ݵ�ָ�����
void adddata(pnode& head, int& n, int& x) {
	int count = 1;
	pnode prior = head;
	pnode p = prior->next;
	while (p) {
		if (count == n){
			pnode a = new node;
			a->data = x;
			a->next = p;
			prior->next = a;
			return;
		}
		prior = p;
		p = p->next;
		count++;
	}
	if (count < n) {
		cout << "There is no such node in the linked list" << endl;
	}
}
//�����һ����ָ�����
void addlist(pnode& heada, pnode& headb, pnode& p) {

}

int main(void) {
	pnode heada = nullptr;//��ͷ
	pnode pa = nullptr;//��β
	createlist(heada , pa);
	for(int i = 0;i< 2;i++){
		int x;
		cin >> x;
		adddata(pa, x);
	}
	/*Print(heada);
	tsil(heada);
	Print(heada);*/
	/*int x = 2;
	deletedata(heada, x);
	pnode headb = nullptr;
	pnode pb = nullptr;
	createlist(headb, pb);
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		adddata(pb, x);
	}
	linklist1(pa, headb);
	Print(heada);
	Print(headb);*/
	return 0;
}
