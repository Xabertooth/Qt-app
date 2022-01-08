#include "TGeneralClass.h"
//======================================================
void IPRating(){
	
}
//======================================================
void fireAreas(){
	
}
//главное меню======================================================
int invite(){ //‘ункци€ приглашени€ выбрать пункт
	int choice{0};
	cout << '\n' << "¬ведите пункт искомой информации!" << '\n' << endl // тут буква В - это английская Bb
		<< "1 - взрывозащита" << endl
		<< "2 - пыле-влагостойкость" << endl
		<< "3 - классификаци пож.опасных зон" << endl
		<< "4 - классы и группы взрывоопасных смесей" << endl
		<< "0 - выход" << '\n' << endl;
	cin >> choice;
	if (choice < 0 || choice > 3) error("отсутствует такой пункт!");
	return choice;
}	
//======================================================
int main(){
	system("chcp 1251");
	
	static const regex Ex_pntr {R"([0-2]Ex[deimnopqs][abcxyzACLR]?\[?i?[abc]?\]?(I|II)[ABC]?T[1-6](X|U)?)"}; //Ўаблон ввода дл€ Ex
	static const regex Ip_pntr{ R"(IP[0-6][0-8]:)" }; //Ўаблон ввода дл€ IP
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
				cout << '\n' << '\t' << "Ingress Protection Rating (сокращенно IP)" << '\n'
					<< "ѕримечание: после ввода второй цифры введите двоеточие (пример IP 6 8: >)" << endl;
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