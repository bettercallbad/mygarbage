#include<iostream>
#define MaxSource 3//����չ����Դ
#define MaxP 10
using namespace std;

struct Resource{//��Դʣ����
	int AvailableSource[MaxSource];
};

struct Process {//����״̬
	string name;
	int Max[MaxSource];
	int Allocation[MaxSource];
	int Need[MaxSource];

}processes[MaxP];

bool check(Resource& s,int i) {//���ʣ����Դ��������i��������
	for (int j = 0; j < MaxSource; j++) {
		if (s.AvailableSource[j] < processes[i].Need[j]) {
			return false;
		}
	}
	return true;
}



int main() {
	cout << "E02114353��־ΰ" << endl;
	cout << "��������̸���" << endl;
	int n; cin >> n;
	Resource s;


	//��ʽ�����밸�����������룩
	cout << "���������Դ����������£�" << endl;
	cout << "\t���������\t�ѷ�����" << endl;
	cout << "������   ";
	char c = 'A';
	for (int j = 0; j < MaxSource; j++) {
		cout  <<" " << (char)(c + j);
	}
	cout << "\t\t";
	for (int j = 0; j < MaxSource; j++) {
		cout << " " << (char)(c + j);
	}
	cout << endl;



	//����
	for (int i = 0; i < n; i++) {
		cin >> processes[i].name;
		
		for (int j = 0; j < MaxSource; j++) {//�����i�����̶Ե�j����Դ��������
			cin >> processes[i].Max[j];
		}
		for (int j = 0; j < MaxSource; j++) {//�����i�����̶Ե�j����Դ��ռ����
			cin >> processes[i].Allocation[j];
		}
		for (int j = 0; j < MaxSource; j++) {//�����Ȼ��Ҫ����Դ
			processes[i].Need[j] = processes[i].Max[j] - processes[i].Allocation[j];
		}
		
	}
	cout << "����ʣ��ļ������Դ" << endl;
	for (int j = 0; j < MaxSource; j++) {//����ʣ��ļ������Դ
		cout << (char)(c + j) << ':';
		cin >> s.AvailableSource[j];
	}
		

	//���м��㷨����
	bool flag = false;
	string finish[MaxP];
	int ok = 0;
	while (ok < n) {
		for (int i = 0; i < n; i++) {
			if (check(s,i)) {
				finish[ok++] = processes[i].name;
				flag = true;
				for (int j = 0; j < MaxSource; j++) {
					s.AvailableSource[j] += processes[i].Allocation[j];
				}
				processes[i].Need[0] = 1 << 30;//ɾ���ý���
				break;
			}
		}
		if (!flag)break;

	}


	//���
	if (!flag)cout << "δ�ҵ���ȫ����" << endl;
	else {
		cout << "������һ����ȫ��������:" << endl;
		for (int i = 0; i < n; i++) {
			cout << finish[i]<<"\t";
		}
	}

	return 0;
}