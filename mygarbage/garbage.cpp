#include<iostream>
#define MaxSource 3//可扩展多资源
#define MaxP 10
using namespace std;

struct Resource{//资源剩余量
	int AvailableSource[MaxSource];
};

struct Process {//进程状态
	string name;
	int Max[MaxSource];
	int Allocation[MaxSource];
	int Need[MaxSource];

}processes[MaxP];

bool check(Resource& s,int i) {//检查剩余资源够不够第i个进程用
	for (int j = 0; j < MaxSource; j++) {
		if (s.AvailableSource[j] < processes[i].Need[j]) {
			return false;
		}
	}
	return true;
}



int main() {
	cout << "E02114353曹志伟" << endl;
	cout << "请输入进程个数" << endl;
	int n; cin >> n;
	Resource s;


	//格式化输入案例（便于输入）
	cout << "输入进程资源情况（例如下）" << endl;
	cout << "\t最大需求量\t已分配量" << endl;
	cout << "进程名   ";
	char c = 'A';
	for (int j = 0; j < MaxSource; j++) {
		cout  <<" " << (char)(c + j);
	}
	cout << "\t\t";
	for (int j = 0; j < MaxSource; j++) {
		cout << " " << (char)(c + j);
	}
	cout << endl;



	//输入
	for (int i = 0; i < n; i++) {
		cin >> processes[i].name;
		
		for (int j = 0; j < MaxSource; j++) {//输入第i个进程对第j个资源的需求量
			cin >> processes[i].Max[j];
		}
		for (int j = 0; j < MaxSource; j++) {//输入第i个进程对第j个资源的占有量
			cin >> processes[i].Allocation[j];
		}
		for (int j = 0; j < MaxSource; j++) {//算出仍然需要的资源
			processes[i].Need[j] = processes[i].Max[j] - processes[i].Allocation[j];
		}
		
	}
	cout << "输入剩余的计算机资源" << endl;
	for (int j = 0; j < MaxSource; j++) {//输入剩余的计算机资源
		cout << (char)(c + j) << ':';
		cin >> s.AvailableSource[j];
	}
		

	//银行家算法如下
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
				processes[i].Need[0] = 1 << 30;//删除该进程
				break;
			}
		}
		if (!flag)break;

	}


	//输出
	if (!flag)cout << "未找到安全序列" << endl;
	else {
		cout << "下面是一个安全进程序列:" << endl;
		for (int i = 0; i < n; i++) {
			cout << finish[i]<<"\t";
		}
	}

	return 0;
}