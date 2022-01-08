#include "std_lib_facilities.h"
using namespace std;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class TGeneral{
	public:
		ifstream ifs;
		TGeneral(const regex& pat, string file); //0 ������������
		void printMap(); // 1
	private:
		void incert(); // 2 ���� ����������
		void check_input(); // 3 �������� ������������ �����
		void mapFiller(); //4 ���������� �����
		string file; // ��� �����
		map<string, string> m; // ����� ��� �������� ������ �� �����
		vector<string> v; //������ ��� �������� �������� �����. ������
		regex pat;
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//0 �����������======================================================
TGeneral::TGeneral(const regex& r, string s)
	:file{s}, pat{r}
{
	ifs.open(file, std::ios::in); 
	if(!ifs.is_open()) error("Fail opened file!");
	TGeneral::mapFiller(); //
	ifs.close();
}

//1 ����� �������� ����� � ������������ ������ � �������=============
void TGeneral::printMap() {
	TGeneral::incert();
	for (string str : v) {
		auto search = m.find(str);
		if (search != m.end()) cout << search->first << ":  " << search->second << std::endl;
	}
}

//2 ���� ����������==================================================
void TGeneral::incert(){ // ���������� �������
	cout << '\n' << '\t'
		<<  "������� ����� ���������� ����� ������, ����� ����� ������� ������ '>'" << endl;
	v.clear();
	string s;
	while (1){
		cin >> s;
		if (s[0] == '>' || (v.size() == 7)) break;
		v.push_back(s);
	}
	cout << '\n';
	TGeneral::check_input();
}

//3 �������� ������������ �����=====================================
void TGeneral::check_input(){
	string sv;
	smatch matches;
	
	for (auto s : v) sv += s; //����� ��������� �� �������
	cout << '\n' << sv << '\n' << endl;
	
	if(!regex_match(sv, matches, pat)){//�������� ������������ �����
		cout << "������������� ����!" << endl;
		for (string str : v) {
			auto search = m.find(str);
			if (search == m.end()) cout << "������������ ������� " << str << endl;
		}
	}
}

//4 ���������� �����================================================
void TGeneral::mapFiller(){
	bool flag {true}; //���� ��� ����������� �������� "key"
	string sKey, sValue; //������ ��� �������� ����� � ��������
	m.clear(); //������� �����
	for (string s; getline(ifs, s);) { //�������� ������ �� �����, ����� � � s
		if (flag) { //���� ����==1, ������ ������ ��� ���� 
			sKey = s; //��������� � � sKey  
			flag = !flag; //�������� ����� �.�. ����������� ������ ������ � ��������
		}
		else if (s == "---") { 
			flag = !flag;
			sValue += '\n';
			m.insert(make_pair(sKey, sValue)); //���� ������ ����� "---", �� ��������� �������� sKey � sValue � map
			sValue.clear();
		} 
		else {
			(sValue += s)+= '\n';
		}
	}
}