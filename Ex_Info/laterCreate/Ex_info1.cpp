#include "TGeneralClass.h"
//======================================================
void IPRating(){
	
}
//======================================================
void fireAreas(){
	
}
//������� ����======================================================
int invite(){ //������� ����������� ������� �����
	int choice{0};
	cout << '\n' << "������� ����� ������� ����������!" << '\n' << endl // ��� ����� � - ��� ���������� Bb
		<< "1 - ������������" << endl
		<< "2 - ����-��������������" << endl
		<< "3 - ������������ ���.������� ���" << endl
		<< "4 - ������ � ������ ������������� ������" << endl
		<< "0 - �����" << '\n' << endl;
	cin >> choice;
	if (choice < 0 || choice > 3) error("����������� ����� �����!");
	return choice;
}	
//======================================================
int main(){
	system("chcp 1251");
	
	static const regex Ex_pntr {R"([0-2]Ex[deimnopqs][abcxyzACLR]?\[?i?[abc]?\]?(I|II)[ABC]?T[1-6](X|U)?)"}; //������ ����� ��� Ex
	static const regex Ip_pntr{ R"(IP[0-6][0-8]:)" }; //������ ����� ��� IP
	TGeneral* genVar;

	while(1){
		int cho = invite();
		switch (cho){
			case 0:
				cout << '\n' << '\t' <<  "Goodbye!" << std::endl;
				Sleep(1300);
				return 0;
			case 1:
				cout << '\n' << '\t' << "Explosion protection" << endl;
				genVar = new TGeneral(Ex_pntr, "Ex_file.txt");
				genVar->printMap();
				delete genVar;
				break;
			case 2:
				cout << '\n' << '\t' << "Ingress Protection Rating (���������� IP)" << '\n'
					<< "����������: ����� ����� ������ ����� ������� ��������� (������ IP 6 8: >)" << endl;
				genVar = new TGeneral(Ip_pntr, "Ip_file.txt");
				genVar->printMap();
				delete genVar;
				break;
			case 3:
				cout << '\n' << '\t' << "Fire areas" << endl;
				fireAreas();
				break;
			default:
				break;
		}
	}
	return 0;
}