#include <iostream>
#pragma warning(disable : 4996)
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//чтение файла char
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
char* output(FILE* fp) {

	int* j;
	j = new int;
	*j = 0;

	int* k;
	k = new int;
	*k = 0;
	char* name;
	name = new char[20];
	char* pr;
	pr = new char;
	*pr = '0';
	while ((*pr) != '\0') {

		*k = fread(pr, (sizeof(char)), 1, fp);
		if (*k == 0) {
			*pr = '|';
			return(pr);
		};
		name[*j] = *pr;
		*j = *j + 1;
	};
	return(name);
	delete[] name, pr, j;

};
//чтение файла инт
int output_i(FILE* fp) {
	int* j;
	j = new int;
	*j = 0;
	int* k;
	k = new int;
	int* i;
	i = new int;
	int* date;
	char* pr;
	pr = new char;
	*pr = '0';

	date = new int;
	*(date) = 0;
	int* buff;
	buff = new int[5];
	*buff = 0;

	while ((*pr == '0') || (*pr == '1') || (*pr == '2') || (*pr == '3') || (*pr == '4') || (*pr == '5') || (*pr == '6') || (*pr == '7') || (*pr == '8') || (*pr == '9')) {

		fread(pr, (sizeof(char)), 1, fp);


		switch ((*(pr))) {

		case '0': *(buff + (*j)) = 0;

			break;
		case '1':*(buff + (*j)) = 1;
			break;
		case '2':*(buff + (*j)) = 2;
			break;
		case '3':*(buff + (*j)) = 3;
			break;
		case '4':*(buff + (*j)) = 4;
			break;
		case '5':*(buff + (*j)) = 5;
			break;
		case '6':*(buff + (*j)) = 6;
			break;
		case '7':*(buff + (*j)) = 7;
			break;
		case '8':*(buff + (*j)) = 8;
			break;
		case '9':*(buff + (*j)) = 9;
			break;

		};

		*j = *j + 1;

	};

	*j = *j - 1;
	*j = *j - 1;
	*date = 0;
	*k = 0;
	for (*j; *j >= 0; *j = *j - 1) {
		*i = powl(10, *j);
		(*(date)) = (*(date)) + ((*(buff + *k)) * (*i));
		*k = *k + 1;
	};
	return(*date);
	delete[] buff, k, j, i, date, pr;


};
char simv(int i) {
	switch (i)
	{
	case 0:return('0');
	case 1:return('1');
	case 2:return('2');
	case 3:return('3');
	case 4:return('4');
	case 5:return('5');
	case 6:return('6');
	case 7:return('7');
	case 8:return('8');
	case 9:return('9');
	}


};
char* int_char(int i) {
	char* c;
	c = new char[5];
	int* b;
	b = new int;
	if ((i < 10000) && (i >= 1000)) {
		*b = i / 1000;
		i = i % 1000;
		*(c + 0) = simv(*b);
		*b = i / 100;
		i = i % 100;
		*(c + 1) = simv(*b);
		*b = i / 10;
		i = i % 10;
		*(c + 2) = simv(*b);
		*b = i / 1;
		i = i % 1;
		*(c + 3) = simv(*b);
		return(c);
	}
	else {
		if ((i < 1000) && (i >= 100)) {

			*b = i / 100;
			i = i % 100;
			*(c + 0) = simv(*b);
			*b = i / 10;
			i = i % 10;
			*(c + 1) = simv(*b);
			*b = i / 1;
			i = i % 1;
			*(c + 2) = simv(*b);
			return(c);
		}
		else {
			if ((i < 100) && (i >= 10)) {

				*b = i / 10;
				i = i % 10;
				*(c + 0) = simv(*b);
				*b = i / 1;
				i = i % 1;
				*(c + 1) = simv(*b);
				return(c);
			}
			else {
				if ((i < 10) && (i >= 1)) {

					*b = i / 1;
					i = i % 1;
					*(c + 0) = simv(*b);
					return(c);

				}


			};
		};
	};

};
void zapis_int(FILE* nfp, int* k) {
	char* x;
	x = new char[5];

	if ((*k < 10000) && (*k > 1000)) {
		x = int_char(*k);
		for (int z = 0; z < 4; z++)
		{
			fwrite((x + z), (sizeof(char)), 1, nfp);
		}
	}
	else {
		if ((*k < 1000) && (*k > 100))
		{
			x = int_char(*k);
			for (int z = 0; z < 3; z++)
			{
				fwrite((x + z), (sizeof(char)), 1, nfp);
			}
		}
		else {
			if ((*k < 100) && (*k > 10)) {
				x = int_char(*k);
				for (int z = 0; z < 2; z++)
				{
					fwrite((x + z), (sizeof(char)), 1, nfp);
				}

			}
			else {
				if ((*k < 10) && (*k > 1)) {
					x = int_char(*k);
					for (int z = 0; z < 1; z++)
					{
						fwrite((x + z), (sizeof(char)), 1, nfp);
					}
				}
			}
		}
	};


};

class mark {
private:
	int* mark1;
	char* subject;
public:

	
	mark() {
	this->mark1 = new int;
	this->subject = new char[20];
	
	};
	~mark() {
		delete[] mark1, subject;

	};
	int out_mark () {
		return(*mark1);
	}
	void izmenenie1(int o) {
		FILE* fp;
		fp = fopen("ochenky.txt", "r");
		FILE* nfp;
		nfp = fopen("new__file.txt", "w");
		char* buff;
		char* buf;
		char* bu;
		int* k;
		int* ki;
		int* men;
		int* kl;
		kl = new int;
		men = new int;
		k = new int;
		ki = new int;
		*kl = 0;
		*ki = 1;
		buff = new char[20];
		buf = new char[20];
		bu = new char[20];
		*ki=fread(buff, sizeof(char), 1, fp);
		fwrite(buff, sizeof(char), 1, nfp);
		for (int i = 0; i < o; i++) {
			
			while (*buff != '|') {
				*ki=fread(buff, sizeof(char), 1, fp);
				fwrite(buff,sizeof(char),1,nfp);
			}
			*ki = fread(buff, sizeof(char), 1, fp);
			if (i != o - 1) {
				fwrite(buff, sizeof(char), 1, nfp);
			}
		}
		memset(&buf[0], 0, sizeof(buf));
		memset(&bu[0], 0, sizeof(bu));
		
		
		
		*k = -1;
		while ((*buff !='|') && (*ki != 0)) {
			
			memset(&subject[0], 0, sizeof(subject));
			*kl = 0;
			while (*buff != '\0') {
				
					bu[*k] = *buf;
				
				*buf = *buff;
				*k = *k + 1;
				switch ((*(buff))) {
				case '0': *mark1 = 0;
					break;
				case '1':*mark1 = 1;
					break;
				case '2':*mark1 = 2;
					break;
				case '3':*mark1 = 3;
					break;
				case '4':*mark1 = 4;
					break;
				case '5':*mark1 = 5;
					break;
				case '6':*mark1 = 6;
					break;
				case '7':*mark1= 7;
					break;
				case '8':*mark1 = 8;
					break;
				case '9':*mark1 = 9;
					break;
				};
				
				*ki=fread(buff, sizeof(char), 1, fp);
			}
			for (int nt = 0; nt < *k; nt++) {
				subject[nt] = bu[nt];
			}
			subject[*k] = '\0';
			cout << "Хотите изменить оценку" << *mark1 << "по предмету:" << subject << endl;
			cout << "1-Да, изменить оценку" << endl;
			cout << "2-Да, изменить предмет" << endl;
			cout << "3-Да, Удалить запись" << endl;
			cout << "4-Не хочу" << endl << "->";
			cin >> *men;
			switch (*men) {
			case 1:
				*mark1 = 9;
				while ((*mark1 > 5) || (*mark1 < 0)) {
					cin >> *mark1;
				}

				for (int j = 0; j < *k; j++) {
					fwrite(subject + j, sizeof(char), 1, nfp);
				}
				switch (*mark1)
				{
				case 1: *buff = '1'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 2: *buff = '2'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 3: *buff = '3'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 4: *buff = '4'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 5: *buff = '5'; fwrite(buff, sizeof(char), 1, nfp); break;
				};
				*bu = '\0'; fwrite(bu, sizeof(char), 1, nfp);
				break;
			case 2:
				cin >> subject;
				while (*(subject + *kl) != '\0')
				{
					fwrite(subject+*kl, sizeof(char), 1, nfp);
					*kl = *kl + 1;
				};
				switch (*mark1)
				{
				case 1: *buff = '1'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 2: *buff = '2'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 3: *buff = '3'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 4: *buff = '4'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 5: *buff = '5'; fwrite(buff, sizeof(char), 1, nfp); break;
				};
				*bu = '\0'; fwrite(bu, sizeof(char), 1, nfp);
				break;
			case 3:
				break;
			case 4:
				for (int j = 0; j < *k; j++) {
					fwrite(subject+j, sizeof(char), 1, nfp);
				}
				
				switch (*mark1) {
				case 1: *buff = '1'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 2: *buff = '2'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 3: *buff = '3'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 4: *buff = '4'; fwrite(buff, sizeof(char), 1, nfp); break;
				case 5: *buff = '5'; fwrite(buff, sizeof(char), 1, nfp); break;
				}
				*bu = '\0'; fwrite(bu, sizeof(char), 1, nfp);
				break;
			};
		
			
			if (*ki != 0) {
				*ki = fread(buff, sizeof(char), 1, fp);
			}
			
			*buf = *buff;
			
			*k = -1;
			
		}
		
		while (*ki != 0) {
			
			fwrite(buff, sizeof(char), 1, nfp);
			*ki = fread(buff, sizeof(char), 1, fp);
			

		}
		fclose(fp);
		fclose(nfp);
		remove("ochenky.txt");
		rename("new__file.txt", "ochenky.txt");
	};
	char chtenie1(FILE* fp, int* kl, char* buff) {

		char* buf;
		char* bu;
		int* k;
		int* ki;
		k = new int;
		buf = new char[50];
		bu = new char[50];
		memset(&buf[0], 0, sizeof(buf));
		memset(&bu[0], 0, sizeof(bu));
		*k = 0;

		*buf = *buff; cout << '|';
		cout << "оценки по предметам:" << endl;
		while ((*buff != '|') && (*kl != 0)) {

			memset(&bu[0], 0, sizeof(bu));
			memset(&subject[0], 0, sizeof(subject));

			*k = -1;
			while (*buff != '\0') {


				if (*k >= 0) {
					*(bu + *k) = *buf;
				}
				*buf = *buff;

				*k = *k + 1;
				switch (*buff) {
				case '0': *mark1 = 0;
					break;
				case '1':*mark1 = 1;
					break;
				case '2':*mark1 = 2;
					break;
				case '3':*mark1 = 3;
					break;
				case '4':*mark1 = 4;
					break;
				case '5':*mark1 = 5;
					break;
				case '6':*mark1 = 6;
					break;
				case '7':*mark1 = 7;
					break;
				case '8':*mark1 = 8;
					break;
				case '9':*mark1 = 9;
					break;

				};

				*kl = fread(buff, sizeof(char), 1, fp);


			}


			memset(&subject[0], 0, sizeof(subject));

			
			for (int nt = 0; nt < *(k); nt++) {

				*(subject+nt) = bu[nt];

			}
			*(subject + *k) = '\0';
			memset(&bu[0], 0, sizeof(bu));
			cout << '|';
			cout << subject;
			cout << ":";
			cout << *mark1 << endl;
			if (*kl != 0) {
				*kl = fread(buff, sizeof(char), 1, fp);
			}

			*buf = *buff;
			

		}cout << "|-------------------------------------------------------------" << endl << endl << endl;
		return(*buff);
	};
	char chtenie12(FILE* fp, int* kl, char* buff) {

		char* buf;
		char* bu;
		int* k;
		int* ki;
		k = new int;
		buf = new char[20];
		bu = new char[20];
		memset(&buf[0], 0, sizeof(buf));
		memset(&bu[0], 0, sizeof(bu));
		*k = 0;
		*buf = *buff;
		memset(&subject[0], 0, sizeof(subject));
		memset(&bu[0], 0, sizeof(bu));
		while (*buff != '\0') {

			bu[*k] = *buf;

			*buf = *buff;

			*k = *k + 1;
			switch (*buff) {
			case '0': *mark1 = 0;
				break;
			case '1':*mark1 = 1;
				break;
			case '2':*mark1 = 2;
				break;
			case '3':*mark1 = 3;
				break;
			case '4':*mark1 = 4;
				break;
			case '5':*mark1 = 5;
				break;
			case '6':*mark1 = 6;
				break;
			case '7':*mark1 = 7;
				break;
			case '8':*mark1 = 8;
				break;
			case '9':*mark1 = 9;
				break;

			};

			*kl = fread(buff, sizeof(char), 1, fp);

		};
		for (int nt = 0; nt < *(k - 0); nt++) {
			subject[nt - 1] = bu[nt];
		};

		if (*kl != 0) {
			*kl = fread(buff, sizeof(char), 1, fp);
		};
		*buf = *buff;
		if (*kl == 0) {
			return('|');
		};


		return(*buff);
	};
	void vivod() {
		cout << subject << endl;
		cout << *mark1 << endl;
	};
	mark& operator=(const mark& right) {
		if (0) { return(*this); }
		for (int i = 0; i < 20; i++) {
			subject[i] = right.subject[i];
		}
		*mark1 = *(right.mark1);
	};
	void swap(mark* right, mark* left,int pred) {
		if (0) { return; }
		for (int j = 0; j < pred; j++) {
			left[j] = right[j];
		}
		
	};
};

class student:public mark {
private:

	char* name;
	char* firstname;
	char* secondname;
	char* gender;

	int* date;
	int* inter_date;
	char* facultet;
	char* kafedra;
	char* group;
	char* zachetka;
public:
	student() {
		this->name = new char[20];
		this->firstname = new char[20];
		this->secondname = new char[20];
		this->gender = new char[1];
		this->date = new int[3];
		this->inter_date = new int[3];
		this->facultet = new char[20];
		this->kafedra = new char[20];
		this->group = new char[20];
		this->zachetka = new char[20];

	};
	
	
	~student() {
		delete[] name, firstname, secondname,gender, date, inter_date, facultet, kafedra, group, zachetka;
	};
	student& operator=( student& right) {
		if (0) {
			return(*this);
		}
		name = right.name;
		firstname = right.firstname;
		secondname = right.secondname;
		gender = right.gender;
		date[0] = right.date[0];
		date[1] = right.date[1];
		date[2] = right.date[2];
		inter_date[0] = right.inter_date[0];
		inter_date[1] = right.inter_date[1];
		inter_date[2] = right.inter_date[2];
		facultet = right.facultet;
		kafedra = right.facultet;
		group = right.group;
		zachetka = right.zachetka;
		
	}
	void vivod() {
		
		cout << "                            Карточка студента                 " << endl;
		cout << "|-------------------------------------------------------------" << endl;
		cout << "|ФИО:" << name << " ";
		cout << firstname;
		cout << " " << secondname;
		cout << " " << "(" << gender << ")" << endl;
		cout << "|-------------------------------------------------------------" << endl;
		cout << "|Дата рождения:" << date[0] << "." << date[1] << "." << date[2] << endl;
		cout << "|-------------------------------------------------------------" << endl;
		cout << "|Дата поступления:" << inter_date[0] << "." << inter_date[1] << "." << inter_date[2] << endl;
		cout << "|-------------------------------------------------------------" << endl;
		cout << "|Факультет:" << facultet << endl;
		cout << "|-------------------------------------------------------------" << endl;
		cout << "|Кафедра:" << kafedra << endl;
		cout << "|-------------------------------------------------------------" << endl;
		cout << "|Группа::" << group << endl;
		cout << "|-------------------------------------------------------------" << endl;
		cout << "|Зачетка:" << zachetka << endl;
		cout << "|-------------------------------------------------------------" << endl;

		
	}
	
	char* vvod_char() {
		char* str;
		str = new char[20];
		cin >> str;
		return(str);
		delete[]name;
	};
	char* vvod_gender(){
	char* g;
	g = new char[1];

	while ((*g !='М') && (*g !='Ж')) {
		 cin>>*g;
	}
	
	return (g);

	};
	
	void vvod_date() {
		for (int j = 0; j < 3; j++) { *(date + j) = 0; };
		for (int j = 0; j < 3; j++) { *(inter_date + j) = 0; };
		cout << "Введите год рождения учащегося" << endl << "->";
		while ((*date < 1800) || (*date > 2005)) {
			cin >> *(date + 0);
		};
		cout << "Введите месяц рождения учащегося" << endl << "->";
		while ((*(date + 1) < 1) || (*(date + 1) > 12)) {
			cin >> *(date + 1);
		};
		cout << "Введите день рождения учащегося" << endl << "->";
		while ((*(date + 2) < 1) || (*(date + 2) > 31)) {
			cin >> *(date + 2);
		}
		cout << "Введите год поступления учащегося" << endl << "->";
		while ((*(inter_date + 0) < 1800) || (*(inter_date + 0) > 2020) || ((*(inter_date + 0) - *date) < 15)) {
			cin >> *(inter_date + 0);
		};
		cout << "Введите месяц поступления учащегося" << endl << "->";
		while ((*(inter_date + 1) < 1) || (*(inter_date + 1) > 12)) {
			cin >> *(inter_date + 1);
		};
		cout << "Введите день поступления учащегося" << endl << "->";
		while ((*(inter_date + 2) < 1) || (*(inter_date + 2) > 31)) {
			cin >> *(inter_date + 2);
		}

	}
	void vvod() {
		cout << "Введите имя учащегося" << endl << "->";
		name= vvod_char();
		cout << "Введите фамилию учащегося" << endl << "->";
		firstname = vvod_char();
		cout << "Введите отчество учащегося" << endl << "->";
		secondname = vvod_char();
		cout << "[М/Ж]" << endl << "->";
		memset(gender, 0, sizeof(&gender));
		*gender = *vvod_gender();
		vvod_date();
		cout << "Введите факультет учащегося" << endl << "->";
		facultet = vvod_char();
		cout << "Введите кафедру учащегося" << endl << "->";
		kafedra = vvod_char();
		cout << "Введите группу учащегося" << endl << "->";
		group = vvod_char();
		cout << "Введите номер зачетки учащегося" << endl << "->";
		zachetka = vvod_char();
	}
	void zapis1(){
		ofstream fate("Student.txt", 0x08);
		fate << name;
		fate << '\0';
		fate << firstname;
		fate << '\0';
		fate << secondname;
		fate << '\0';
		fate << gender;
		fate << '\0';
		fate << * (date + 0);
		fate << '\0';
		fate << * (date + 1);
		fate << '\0';
		fate << * (date + 2);
		fate << '\0';
		fate << *(inter_date + 0);
		fate << '\0';
		fate << * (inter_date + 1);
		fate << '\0';
		fate << * (inter_date + 2);
		fate << '\0';
		fate << facultet;
		fate << '\0';
		fate << kafedra;
		fate << '\0';
		fate << group;
		fate << '\0';
		fate << zachetka;
		fate << '\0';
		fate.close();
		delete[] date;
	
	}
	
	void izmenenie(int o) {
		cout << "1-изменение имени" << "\t" << "2-изменение фамилии" << endl << "3-изменение отчества" << "\t" << "4-изменение даты рождения или поступления" << endl << "5-изменение факультета" << "\t" << "6-изменение кафедры" << endl << "7-изменение группы" << "\t" << "8-изменение зачетки" << endl<< "9-изменение предметов" << endl<<"->";
		int* m;
		m = new int;
		*m = 11;
		while ((*m > 10) || (*m < 0)) {
			cin >> *m;
		}
		switch (*m) {
		case 1:
			cout << "Введите имя" << endl<<"->";
			cin >> name;
			break;
		case 2:
			cout << "Введите фамилию" << endl << "->";
			cin >> firstname;
			break;
		case 3:
			cout << "Введите отчество" << endl << "->";
			cin >> secondname;
			break;
		case 4:
			int* s;
			s = new int[6];
			vvod_date();
			
			inter_date[0] = s[3];
			inter_date[1] = s[4];
			inter_date[2] = s[5];
			break;
		case 5:
			cout << "Введите факультет" << endl << "->";
			cin >> facultet;
			break;
		case 6:
			cout << "Введите кафедра" << endl << "->";
			cin >> kafedra;
			break;
		case 7:
			cout << "Введите группу" << endl << "->";
			cin >> group;
			break;
		case 8:
			cout << "Введите номер зачетки" << endl << "->";
			cin >> zachetka;
			break;
		case 9:mark::izmenenie1(o);
		
			break;
		}
		delete[] m;
		

	}
	bool sravn_date(int date_1) {
		if (*inter_date == date_1) { return(1); }
		else { return(0); };
	}
	bool sravn_gendr(char g) {
		if (*gender == g) { return(1); }
		else { return(0); };
	}
	char *chtenie(char*r,FILE* fp) {
		name=r;
	
		r = output(fp);
	
		firstname = r;
		r = output(fp);
		
		secondname = r;	
		r = output(fp);
		
		gender = r;
	
		date[0] = output_i(fp);
		date[1] = output_i(fp);
		date[2] = output_i(fp);
		inter_date[0] = output_i(fp);
		inter_date[1] = output_i(fp);
		inter_date[2] = output_i(fp);
		r = output(fp);

		facultet = r;
		r = output(fp);
		
		kafedra = r;
		r = output(fp);
		
		group = r;
		r = output(fp);
	
		zachetka = r;
		r = output(fp);
	
		return(r);
	}
	void zapis() {
		ofstream fate("new_file.txt", 0x08);
		fate << name;
		fate << '\0';
		fate << firstname;
		fate << '\0';
		fate << secondname;
		fate << '\0';
		fate << gender;
		fate << '\0';
		fate << *(date + 0);
		fate << '\0';
		fate << *(date + 1);
		fate << '\0';
		fate << *(date + 2);
		fate << '\0';
		fate << *(inter_date + 0);
		fate << '\0';
		fate << *(inter_date + 1);
		fate << '\0';
		fate << *(inter_date + 2);
		fate << '\0';
		fate << facultet;
		fate << '\0';
		fate << kafedra;
		fate << '\0';
		fate << group;
		fate << '\0';
		fate << zachetka;
		fate << '\0';
		fate.close();
		

	}
 
	char* outname() {
		return(name);
	}
	void ochenky() {
		ofstream F("ochenky.txt", 0x08);
		int s, j, oy=-12;
		char sem[50];
		int jo=-20;
		switch (inter_date[0]) 
		{
		case 2020:cout << "у данного студента еще не было сессии :(" << endl;
			F << "0";
			F << "0";
			F << '\0';
			F << '|';
			return;
			break;
		case 2019:
			cout << "------------------ Семестры, предметы, оценки ---------------------" << endl;
			cout << "Вы можете ввести максимум 1 cессию  и 10 предметов:" << endl;

			cout << "	[" << 1 << "] семестр." << endl;
			cout << "Ведите кол-во предметов" << endl << "->";
			jo = -20;
			while ((jo<1) ||(jo>10)) 
			{
				cin >> jo;
			}
			
			for (j = 1; j <= jo; j++) 
			{
				cout << "введите предмет" << endl << "->";
				cin >> sem;
				F << sem;
				cout << "введите оценку" << endl << "->";
				oy = -12;
				while ((oy < 1) || (oy > 5)) 
				{
					cin >> oy;
				}
				F << oy;
				F << '\0';
			}
			F << '|';
			return;
			break;
		case 2018:

			for (s = 1; s <= 3; s++) {

				cout << "------------------ Семестры, предметы, оценки ---------------------" << endl;
				cout << "Вы можете ввести максимум 3 сессий и по 10 предметов для каждой из них:" << endl;
				cout << "	[" << s << "] семестр." << endl;
				cout << "Ведите кол-во предметов" << endl << "->";
				jo = -20;
				while ((jo < 1) || (jo > 10)) {
					cin >> jo;
				}
				for (j = 1; j <= jo; j++) {
					cout << "введите предмет" << endl << "->";
					cin >> sem;
					F << sem;
					cout << "введите оценку" << endl << "->";
					oy = -12;
					while ((oy < 1) || (oy > 5)) {
						cin >> oy;
					}
					F << oy;
					F << '\0';
				}
			}
			F << '|';
			return;
			break;
		case 2017:

			for (s = 1; s <= 5; s++) {

				cout << "------------------ Семестры, предметы, оценки ---------------------" << endl;
				cout << "Вы можете ввести максимум 5 сессий и по 10 предметов для каждой из них:" << endl;
				cout << "	[" << s << "] семестр." << endl;
				cout << "Ведите кол-во предметов" << endl << "->";
				jo = -20;
				while ((jo < 1) || (jo > 10)) {
					cin >> jo;
				}
				for (j = 1; j <= jo; j++) {
					cout << "введите предмет" << endl << "->";
					cin >> sem;
					F << sem;
					cout << "введите оценку" << endl << "->";
					oy = -12;
					while ((oy < 1) || (oy > 5)) {
						cin >> oy;
					}
					F << oy;
					F << '\0';
				}
			}
			F << '|';
			return;
			break;
		case 2016:

			for (s = 1; s <= 7; s++) {

				cout << "------------------ Семестры, предметы, оценки ---------------------" << endl;
				cout << "Вы можете ввести максимум 7 сессий и по 10 предметов для каждой из них:" << endl;
				cout << "	[" << s << "] семестр." << endl;
				cout << "Ведите кол-во предметов" << endl << "->";
				jo = -20;
				while ((jo < 1) || (jo > 10)) {
					cin >> jo;
				}
				for (j = 1; j <= jo; j++) {
					cout << "введите предме" << endl << "->";
					cin >> sem;
					F << sem;
					cout << "введите оценку" << endl << "->";
					oy = -12;
					while ((oy < 1) || (oy > 5)) {
						cin >> oy;
					}
					F << oy;
					F << '\0';
				}
			}
			F << '|';
			return;
			break;

		case 2015:

			for (s = 1; s <= 9; s++) {

				cout << "------------------ Семестры, предметы, оценки ---------------------" << endl;
				cout << "Вы можете ввести максимум 9 сессий и по 10 предметов для каждой из них:" << endl;
				cout << "	[" << s << "] семестр." << endl;
				cout << "Ведите кол-во предметов" << endl << "->";
				jo = -20;
				while ((jo < 1) || (jo > 10)) {
					cin >> jo;
				}
				for (j = 1; j <= jo; j++) {
					cout << "введите предмет" << endl << "->";
					cin >> sem;
					F << sem;
					cout << "введите оценку" << endl << "->";
					oy = -12;
					while ((oy < 1) || (oy > 5)) {
						cin >> oy;
					}
					F << oy;
					F << '\0';
				}
			}
			F << '|';
			return;
			break;
		default:
			for (s = 1; s <= 10; s++) {

				cout << "------------------ Семестры, предметы, оценки ---------------------" << endl;
				cout << "Вы можете ввести максимум 10 сессий и по 10 предметов для каждой из них:" << endl;
				cout << "	[" << s << "] семестр." << endl;
				cout << "Ведите кол-во предметов" << endl << "->";
				jo = -20;
				while ((jo < 1) && (jo > 10)) {
					cin >> jo;
				}

				for (j = 1; j <= jo; j++) {
					cout << "введите предмет" << endl << "->";
					cin >> sem;
					F << sem;
					cout << "введите оценку" << endl << "->";
					oy = -12;
					while ((oy < 1) || (oy > 5)) {
						cin >> oy;
					}
					F << oy;
					F << '\0';
				}
			}
			F << '|';
			return;
			break;
		}
		F.close();
	}

	friend bool sravn1(char* name_1, char* name_2, char* name_3, student& stud);
	friend void quickSort_char( int low,int high, student *stud);
	friend void quickSort_float(int low, int high, student* stud,float* sred);
	friend void quickSort_float1(int low, int high, student* stud, float* sred);
};

student p;
student t;
int i;
int k;
char name2;
char name_1;
student ti;
mark* ty;
mark** ty1;
int predme;
void quickSort_char(int low, int high, student* stud)
{
	if (low < high)
	{
		p = stud[high];
		i = (low - 1);
		for (int j = low; j <= high - 1; j++)
		{
			k = 0;
		kostil:
			name2 = p.firstname[k];
			name_1 = stud[j].firstname[k];


			if ((name_1) == (name2)) {
				k++;

				goto kostil;
			}
			else {
				if ((name_1) < (name2))
				{
					i++;
					t = stud[i];
					stud[i] = stud[j];
					stud[j] = t;
				}
			}
		}
		ti = stud[i + 1];
		stud[i + 1] = stud[high];
		stud[high] = ti;
		quickSort_char(low, i, stud);
		quickSort_char(i + 2, high, stud);
	};

	return;


};
float maine;
float klf;
float tre;

void quickSort_float(int low, int high, student* stud, float* sred)
{


	if (low < high)
	{
		maine = sred[high];
		i = (low - 1);

		for (int j = low; j <= high - 1; j++)
		{

			if ((sred[j]) > (maine))
			{
				i++;

				tre = sred[i];
				t = stud[i];


				sred[i] = sred[j];
				stud[i] = stud[j];


				sred[j] = tre;
				stud[j] = t;
			}

		}

		tre = sred[i + 1];
		ti = stud[i + 1];




		sred[i + 1] = sred[high];
		stud[i + 1] = stud[high];


		sred[high] = tre;
		stud[high] = ti;

		quickSort_float(low, i, stud, sred);

		quickSort_float(i + 2, high, stud, sred);

	}

	return;


};


void quickSort_float1(int low, int high, student* stud, float* sred)
{
	cout << low << high;

	if (low < high)
	{
		maine = sred[high];
		i = (low - 1);

		for (int j = low; j <= high - 1; j++)
		{

			if ((sred[j]) < (maine))
			{
				i++;

				tre = sred[i];
				t = stud[i];

				sred[i] = sred[j];
				stud[i] = stud[j];

				sred[j] = tre;
				stud[j] = t;
			}

		}
		tre = sred[i + 1];
		ti = stud[i + 1];


		sred[i + 1] = sred[high];
		stud[i + 1] = stud[high];

		sred[high] = tre;
		stud[high] = ti;

		quickSort_float1(low, i, stud, sred);

		quickSort_float1(i + 2, high, stud, sred);

	}

	return;


};
bool sravn1(char* name_1, char* name_2, char* name_3, student& stud) {
	bool boooo = 1;

	for (int q1 = 0; q1 < 20; q1++) {

		if ((*(stud.name + q1) == name_1[q1]) && (*(stud.firstname + q1) == name_2[q1]) && (*(stud.secondname + q1) == name_3[q1])) {

		}
		else {
			boooo = 0;
		};
	}
	return(boooo);
};
	char menu ='o';
	student stud;
	mark marke;
	int main()
	{
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		
		while (1) {
			cout << "1-добавление нового студента" << endl << "2-вывод студентов" <<endl<< "3-изменение данных о студенте" << endl << "4-Вариант 22" << endl << "5-Вариант 39" <<endl<<"6-выход из программы" << endl;
			while (!((menu == '2') || (menu == '1') || (menu == '3') || (menu == '4') || (menu == '5') || (menu == '6') )) {
				cin >> menu;
			};
			if (menu == '6') { return(0); }
			if (menu == '1') {
				student();
				stud.vvod();
				stud.ochenky();
				stud.zapis1();
				
			};

			
			if (menu == '2') {
				FILE* fp;
				fp = fopen("Student.txt", "r");
				FILE* afp;
				afp = fopen("ochenky.txt", "r");
				char* r;
				r = new char;
				char* re;
				re = new char;
				int* ki;
				ki = new int;
				*ki = 1;
				 *ki = fread(re, sizeof(char), 1, afp);
				
				r = output(fp);
				while (*r != '|') {
					cout << "                            Карточка студента                 " << endl;
					cout << "|-------------------------------------------------------------" << endl;
					cout << "|ФИО:" << r << " ";
					cout << output(fp);
					cout << " " << output(fp);
					cout << " " << "(" << output(fp) << ")" << endl;
					cout << "|-------------------------------------------------------------" << endl;
					cout << "|Дата рождения:" << output_i(fp)<<"." << output_i(fp)<<"." << output_i(fp) << endl;	
					cout << "|-------------------------------------------------------------" << endl;
					cout << "|Дата поступления:"  << output_i(fp)<<"." << output_i(fp)<<"."<< output_i(fp) << endl;
					cout << "|-------------------------------------------------------------" << endl;
					cout << "|Факультет:" << output(fp) << endl;
					cout << "|-------------------------------------------------------------" << endl;
					cout << "|Кафедра:" << output(fp) << endl;
					cout << "|-------------------------------------------------------------" << endl;
					cout << "|Группа::" << output(fp) << endl;
					cout << "|-------------------------------------------------------------" << endl;
					cout << "|Зачетка:" << output(fp) << endl;
					cout << "|-------------------------------------------------------------" << endl;
				
					*re=marke.chtenie1(afp, ki,re);
					*ki = fread(re, sizeof(char), 1, afp);
					r = output(fp);
				};
				fclose(fp);
				fclose(afp);
				delete r,re,ki;
			};
			if (menu == '3') {
				student;
				FILE* fp;
				fp = fopen("Student.txt", "r");
				char* r;
				r = new char;
				int* buff;
				buff = new int[3];
				r = output(fp);
				
				bool* i;
				i = new bool;
				*i = 0;
				
				int* o;
				o= new int;
				*o = 0;
				char *name_1;
				name_1 = new char[20];
				char* name_2;
				name_2 = new char[20];
				char* name_3;
				name_3 = new char[20];
				
				if (1) {
					cout << "Введите имя студента->";
					cin >> name_1;
					cout << "Введите фамилию студента->";
					cin >> name_2;
					cout << "Введите отчесто студента->";
					cin >> name_3;
					
					
					while (*r != '|') {
						
						r = stud.chtenie(r, fp);
						
						*o=*o+1;
			                
						if ( sravn1(name_1,name_2,name_3, stud) ) {
							
							*i = 1;
							fclose(fp);
							fp = fopen("student.txt", "r ");
							FILE* nfp;
							nfp = fopen("new_file.txt", "w ");
							int* l;
							l = new int;
							*l = 0;
							int* k;
							k = new int;
							*o = *o - 1;
							char* x;
							x = new char[5];
							int jo = 0;
							r = output(fp);
							stud.vivod();
							cout << endl << endl;
							
							
							if (*(r + 2) == 'э') {
								r = stud.outname();
							}
							for (jo; jo < *o; jo++) {
								
								r = stud.chtenie(r, fp);
								stud.zapis();

							}
							cout << endl << endl << endl;
							fclose(nfp);
							if (*r != '|') {
								r = stud.chtenie(r, fp);
							}
							stud.izmenenie(*o);
							stud.zapis();
							
							
							while (*r != '|') {
								r = stud.chtenie(r, fp);
								stud.zapis();
								
								
							}
							
							fclose(fp);
							remove("student.txt");
							rename("new_file.txt", "student.txt");
							delete[] l, k, x;
							break;
						}
						
					};
					fclose(fp);
					if (*i == 0) { cout << "студента с таким ФИО не нашлося в нашей базе данных :(" << endl; break; }
					
					delete[] r, name_1, name_2, name_3,buff,i,o;
				
					
				
					
				};
			}
			
			if (menu == '4') {
				mark* markee;
				student* da;
				student* net;
				da = new student[50];
				net = new student[50];
				markee = new mark[50];
				int* pred;
				pred = new int[50];
				int* predy;
				predy = new int[50];
				int* predn;
				predn = new int[50];
				int* h;
				int* ik;
				int* i;
				int* ii;
				int* zx;
				zx = new int[50];
				i = new int;
				ik = new int;
				ii = new int;
				h = new int;
				*i = 0;
				*ii = 0;
				char* r;
				r = new char[20];
				char* ra;
				ra = new char[20];
				int* kl;
				int* zxr;
				zxr = new int;
				*zxr = 0;
				kl = new int;
				FILE* fp;
				FILE* nfp;
				fp = fopen("student.txt", "r");
				nfp = fopen("ochenky.txt", "r");
				r = output(fp);
				*kl = fread(ra, sizeof(char), 1, nfp);
				cout << "Введите год, студентов поступивших в который, вы желаете узреть" << endl << "->";
				cin >> *h;
				while (*r != '|')
				{
					r = stud.chtenie(r, fp);
					*ik = 0;
					while ((*ra != '|'))
					{
						*ra = markee[*ik].chtenie12(nfp, kl, ra);
						*ik = *ik + 1;
					}
					if (stud.sravn_date(*h))
					{
						da[*i] = stud;
						*i = *i + 1;
					}
					else
					{
						net[*ii] = stud;
						*ii = *ii + 1;
					};
					*kl = 1;
					*kl = fread(ra, sizeof(char), 1, nfp);
				}
				quickSort_char(0, (*i) - 1, da);
				for (int u = 0; u < *i; u++)
				{
					da[u].vivod();
					cout << endl << endl;
				}
				cout << "Иные года" << endl << endl << endl;
				quickSort_char(0, (*ii) - 1, net);
				for (int u = 0; u < *ii; u++)
				{
					net[u].vivod();
					cout << endl << endl;
				}
				fclose(fp);
				fclose(nfp);
				delete[] h, i, ii, r, da, net, zxr, ik, markee, ra, kl, fp, nfp;
			};
			if (menu == '5') 
			{
				mark* markee;
				student* da;
				student* net;
				markee = new mark[50];
				da = new student[50];
				net = new student[50];
				int* zxr;
				zxr = new int;
				*zxr = 0;
				char* h;
				int* ik;
				int* i;
				int* ii;
				i = new int;
				ik = new int;
				ii = new int;
				h = new char;
				*i = 0;
				*ii = 0;
				char* r;
				r = new char[20];
				char* ra;
				ra = new char[20];
				float* ro;
				ro = new float;
				*ro = 0;
				int* kl;
				kl = new int;
				FILE* fp;
				FILE* nfp;
				float *mko;
				mko = new float[50];
				float* mkoy;
				mkoy = new float[50];
				float* mkon;
				mkon = new float[50];
				fp = fopen("student.txt", "r");
				nfp = fopen("ochenky.txt", "r");
				r = output(fp);
				
				*kl = fread(ra, sizeof(char), 1, nfp);
				cout << "Введите пол, студентов которых, вы желаете узреть" << endl << "->";
				cin >> *h;
				while (*r != '|') 
				{
					r = stud.chtenie(r, fp);
					*ik = 0;
					*ro = 0;
					*zxr = *zxr + 1;
					
					while ((*ra != '|')) {
						*ra = markee[*ik].chtenie12(nfp, kl, ra);

						*ro = markee[*ik].out_mark() + *ro;

						*ik = *ik + 1;
					};
					
					*(mko + *(zxr)-1) = ((*ro)/ (*ik));
					
					
					if (stud.sravn_gendr(*h)) {
						da[*i] = stud;
						
						*(mkoy + *i) = *(mko + *(zxr)-1);
						*i = *i + 1;
					}
					else {
						net[*ii] = stud;
						*(mkon + *ii) = *(mko + *(zxr)-1);
						*ii = *ii + 1;
					};
					
					*kl = fread(ra, sizeof(char), 1, nfp);
				};
				cout << *i << "/" << *ii;
				char g = '0';
				cout << "1-топ неуспевающих" << endl << "2-топ успевающих";
					while ((g != '1') && (g != '2')) {
						cin >> g;
				}
					if (g == '2') 
					{
						quickSort_float(0, (*i) - 1, da, mkoy);
					}
					else 
					{
						quickSort_float1(0, (*i) - 1, da, mkoy);
					}
				for (int u = 0; u < *i; u++) 
				{
					da[u].vivod();
					cout << mkoy[u]<<endl;
					cout << endl << endl;

				};
				cout << "Иной пол"<<endl;
				g = '0';
				cout << "1-топ неуспевающих" << endl << "2-топ успевающих";
				while ((g != '1') && (g != '2')) {
					cin >> g;
				}
				if (g == '2')
				{
					quickSort_float(0, (*ii) - 1, net, mkon);
				}
				else
				{
					quickSort_float1(0, (*ii) - 1, net, mkon);
				}
				for (int u = 0; u < *ii; u++)
				{
					net[u].vivod();
					cout << mkon[u]<<endl;
					cout << endl << endl;
				};
				fclose(fp);
				fclose(nfp);
				delete[] h, i, ii, r,da,net,zxr,mko,mkoy,mkon,ik,marke,ra,ro,kl,fp,nfp;
			};
			menu = 'k';
		};
		
	
		return 0;

	};
	
	