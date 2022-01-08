#include "std_lib_facilities.h"
using namespace std;

void check_input(const vector<string>&, const map<string, string>&);

//Ввод маркировки======================================================
void incert(std::vector<string>& v4, const map<string, string>& m4){ // заполнение вектора
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
//Проверка корректности ввода======================================================
void check_input(const vector<string>& v3, const map<string, string>& m3){
	static const regex pat {R"([0-2]Ex[deimnopqs][abcxyzACLR]?\[?i?[abc]?\]?(I|II)[ABC]?T[1-6](X|U)?)"};
	string sv;
	smatch matches;
	
	for (auto s : v3) sv += s; //вывод элементов из вектора
	cout << '\n' << sv << '\n' << endl;
	
	if(!regex_match(sv, matches, pat)){//проверка корректности ввода
		cout << "некорректноый ввод!" << endl;
		for (string str : v3) {
			auto search = m3.find(str);
			if (search == m3.end()) cout << "Некорректный элемент " << str << endl;
		}
	}
	
}
//Главное меню======================================================
int invite(){ //функция приглашение выбрать пункт
	int choice{0};
	std::cout << '\n' << "_Введите пункт искомой информации!" << '\n' << endl // тут буква В - это английская Bb
		<< "1 - взрывозащита" << endl
		<< "2 - пыле-влагостойкость" << endl
		<< "3 - классификаци пож.опасных зон" << endl
		<< "4 - классы и группы взрывоопасных смесей" << endl
		<< "0 - выход" << '\n' << endl;
	std::cin >> choice;
	if (choice < 0 || choice > 3) error("отсутствует такой пункт!");
	return choice;
}
//Заполнение карты======================================================
void mapFiller(map<string, string>& mEmp, ifstream& ifs){ //функция заполнения карты данными выбранного раздела
	bool flag {true}; //флаг для определения свойства "key"
	string sKey, sValue; //память для хранения ключа и значения
	mEmp.clear(); //очистка карты
	for (string s; getline(ifs, s);) { //получаем строку из файла, кладём её в s
		if (flag) { // если флаг==1, значит строка это ключ 
			sKey = s; //сохраняем её в sKey 
			flag = !flag; //инверсия флага т.к. последующие строки войдут в значение
		}
		else if (s == "---") { 
			flag = !flag;
			sValue += '\n';
			mEmp.insert(make_pair(sKey, sValue)); //если строка равна "---", то заносятся значения sKey и sValue в map
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
//Вывод значений карты в соответствии ключам в векторе=========
void printMap(const vector<string>& v2, const map<string, string>& m2) {
	for (string str : v2) {
		auto search = m2.find(str);
		if (search != m2.end()) cout << search->first << ":  " << search->second << std::endl;
	}
}
//======================================================
void Exd(vector<string>& v1, map<string, string>& m1){ //Функция обработки информации по ВЗЭО
	
	ifstream ifs;
	ifs.open("Ex_file.txt", std::ios::in); 
	if(!ifs.is_open()) error("Fail opened file!");
	mapFiller(m1, ifs); //заполнение карты из файла
	ifs.close();
	
	cout << '\n' << '\t' <<  "введите знаки маркировки в.з.э.о. через пробел, после ввода введите символ '>'." << endl;
	
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

	map<string, string> m; //карта для хранения данных считанных из файла
	vector<string> v; //вектор для хранения введённых элементов значений 

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