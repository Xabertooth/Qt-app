#include "std_lib_facilities.h"
using namespace std;

void check_input(const vector<string>&, const map<string, string>&);

//���� ����������======================================================
void incert(std::vector<string>& v4, const map<string, string>& m4){ // ���������� �������
	v4.clear();
	string s;
	while (1){
		cin >> s;
		if (s[0] == '>' || (v4.size() == 7)) break;
		v4.push_back(s);
	}
	cout << '\n';
	check_input(v4, m4);
}
//�������� ������������ �����======================================================
void check_input(const vector<string>& v3, const map<string, string>& m3){
	static const regex pat {R"([0-2]Ex[deimnopqs][abcxyzACLR]?\[?i?[abc]?\]?(I|II)[ABC]?T[1-6](X|U)?)"};
	string sv;
	smatch matches;
	
	for (auto s : v3) sv += s; //����� ��������� �� �������
	cout << '\n' << sv << '\n' << endl;
	
	if(!regex_match(sv, matches, pat)){//�������� ������������ �����
		cout << "������������� ����!" << endl;
		for (string str : v3) {
			auto search = m3.find(str);
			if (search == m3.end()) cout << "������������ ������� " << str << endl;
		}
	}
	
}
//������� ����======================================================
int invite(){ //������� ����������� ������� �����
	int choice{0};
	std::cout << '\n' << "_������� ����� ������� ����������!" << '\n' << endl // ��� ����� � - ��� ���������� Bb
		<< "1 - ������������" << endl
		<< "2 - ����-��������������" << endl
		<< "3 - ������������ ���.������� ���" << endl
		<< "4 - ������ � ������ ������������� ������" << endl
		<< "0 - �����" << '\n' << endl;
	std::cin >> choice;
	if (choice < 0 || choice > 3) error("����������� ����� �����!");
	return choice;
}
//���������� �����======================================================
void mapFiller(map<string, string>& mEmp, ifstream& ifs){ //������� ���������� ����� ������� ���������� �������
	bool flag {true}; //���� ��� ����������� �������� "key"
	string sKey, sValue; //������ ��� �������� ����� � ��������
	mEmp.clear(); //������� �����
	for (string s; getline(ifs, s);) { //�������� ������ �� �����, ������ �� � s
		if (flag) { // ���� ����==1, ������ ������ ��� ���� 
			sKey = s; //��������� �� � sKey 
			flag = !flag; //�������� ����� �.�. ����������� ������ ������ � ��������
		}
		else if (s == "---") { 
			flag = !flag;
			sValue += '\n';
			mEmp.insert(make_pair(sKey, sValue)); //���� ������ ����� "---", �� ��������� �������� sKey � sValue � map
			sValue.clear();
		} 
		else {
			(sValue += s)+= '\n';
		}
	}
}
//======================================================
void outingInfo(){

}
//����� �������� ����� � ������������ ������ � �������=========
void printMap(const vector<string>& v2, const map<string, string>& m2) {
	for (string str : v2) {
		auto search = m2.find(str);
		if (search != m2.end()) cout << search->first << ":  " << search->second << std::endl;
	}
}
//======================================================
void Exd(vector<string>& v1, map<string, string>& m1){ //������� ��������� ���������� �� ����
	
	ifstream ifs;
	ifs.open("Ex_file.txt", std::ios::in); 
	if(!ifs.is_open()) error("Fail opened file!");
	mapFiller(m1, ifs); //���������� ����� �� �����
	ifs.close();
	
	cout << '\n' << '\t' <<  "������� ����� ���������� �.�.�.�. ����� ������, ����� ����� ������� ������ '>'." << endl;
	
	incert(v1, m1);
	printMap(v1, m1);
}
//======================================================
void IPRating(){
	
}
//======================================================
void fireAreas(){
	
}	
//======================================================
int main(){
	system("chcp 1251");

	map<string, string> m; //����� ��� �������� ������ ��������� �� �����
	vector<string> v; //������ ��� �������� ��������� ��������� �������� 

	int cho = invite();
	switch (cho){
		case 0:
			cout << '\n' << '\t' <<  "Goodbye!" << std::endl;
			return 0;
		case 1:
			cout << '\n' << '\t' << "Explosion protection" << endl;
			Exd(v,m);
			break;
		case 2:
			cout << '\n' << '\t' << "Ingress Protection Rating" << endl;
			IPRating();
			break;
		case 3:
			cout << '\n' << '\t' << "Fire areas" << endl;
			fireAreas();
			break;
		default:
			break;
	}
	system("pause");
	return 0;
}