#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<string>

using namespace std;

struct human {
	string name, fname;
	int age;
	double weight, heigt;
};

struct student {
	string name, fname;
	int age;
	double grades[2];
} s, dinara; // переменные типа студент, их можно объявлять сразу после структуры

struct student1 {
	string fname;
	string group;
	int grades[3];

	bool otli4nik(/*ничего не принимает, т.к. по умолчанию имеет доступ ко всем свойствам структуры*/) {
		for (int i = 0; i < 3; i++)
			if (grades[i] < 90)
				return false;
		return true;
	}

	/*bool dvoi4nik() {

	}*/
};
void otli4niki(student1 *ss, int n) {
	/*bool f;
	for (int i = 0; i < n; i++)
	{
		f = true;
		for (int j = 0; j < 3; j++)
		{
			if (ss[i].grades[j] < 90)
			{
				f = false;
				break;
			}
		}
		if (f) cout << ss[i].fname << " " << ss[i].group << endl;
	}*/
	for(int i=0; i<3; i++)
		if (ss[i].otli4nik() == true)
			cout << ss[i].fname << endl;
}
void dvoi4niki(student1 *ss, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += ss[i].grades[j];
		}
		if (sum/3 < 50) cout << ss[i].fname << " " << ss[i].group << endl;
	}
}

// 2.	Описать структуру билет (название маршрута, время, дата, стоимость).
// А) *Создать экземпляр структуры билет и написать для него функции заполнения и печати.
// Б) **Создать массив билетов и написать  программу, позволяющую:
// -динамически изменять размер массива;
// -выводить список билетов на конкретную дату;
// -выводить список  билетов не дороже определенной суммы;
// -печать всего списка билетов.

struct ticket {
	string route;
	string time;
	string date;
	int price;

	// внутренние функци структуры
	void enter_ticket() {
		cin >> route >> time >> date >> price;
	}
	void print() {
		cout << route << " " << time << " " << date << " " << price << endl;
	}
	void print_by_day(string cmp_date /*compares*/) {
		if (cmp_date == date)
			print();
	}
	bool cmp_by_price(double cmp_price) {
		return (price < cmp_price);
	}
	
};
void fill_ticket(ticket *ss, int n) {
	for (int i = 0; i < n; i++)
	{
			cin >> ss[i].route;
			ss[i].time = rand() % 60 + 20;
			cin >> ss[i].date;
			ss[i].price = rand() % 1000 + 100;
			cout << "ticket #" << i + 1 << " : ";
			cout << " rout: " << ss[i].route << " time: " << ss[i].time << " date: " << ss[i].date << " price: " << ss[i].price << endl;
	}
}

// 4.	**Описать структуру ОЗУ (фирма, частота, объем). Создать массив экземпляров структуры ОЗУ и написать программу, позволяющую:
// -динамически изменять размер массива;
// -выводить список памяти с частотой больше заданной;
// -выводить список памяти с объемом больше заданного;

struct ozu {
	string prod;
	double freq;
	double vol;

	void enter_ozu() {
		cin >> prod >> freq >> vol;
	}
	void print() {
		cout << prod << " " << freq << " " << vol << endl;
	}
	bool cmp_by_freq(double cmp_freq) {
		return (freq < cmp_freq);
	}
	bool cmp_by_vol(double cmp_vol) {
		return (vol < cmp_vol);
	}
};

// 3.	**Описать структуру Data(день, месяц, год).Описать структуру Student(фамилия, группа, дата поступления).
// Проиллюстрировать работу с этим классом.
struct date {
	int day, month, year;
	void enter_date() {
		char c;
		cin >> day >> c >> month >> c >> year; // c - для точек
	}

	bool cmp_date(date d) {
		return (d.day == day && d.month == month && d.year == year);
	}

	void print() {
		cout << day << "." << month << "." << year;
	}
};

struct stud {
	string fname;
	int group;
	date entering_date; // other structure
	void enter_stud() {
		cin >> fname >> group;
		entering_date.enter_date();
	}

	void print() {
		cout << fname << " " << group << " ";
		entering_date.print();
		cout << endl;
	}
};

struct example {
	int a;
	double d;
	char b;
	int z;
	
};


int Aatoi_t(char* s) // когда из массива 1-2-3-4 нужно получить число 1234
{
	int sum = 0;
	for (int i = 0; i < strlen(s) && isdigit(s[i]); i++)
	{
		sum = sum * 10 + s[i] - 48; // по разрядам собираем
	}
	return sum;
	/*while (*s >= '0' && *s <= '9') {
	n *= 10;
	n += *s++;
	n -= '0';
	}
	return n;*/
}
int Aatoi_t1(char* s)
{
	int sum = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]))
			sum = sum * 10 + s[i] - 48;
	}
	return sum;

}
void test1(char* s) //по таблице ASCII перевод в верхний регистр
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] = s[i] - 32; // 97-65=32
		cout << s[i] << endl;
	}
}




int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			student s1; // в данном случае переменная s1 типа student, и занимает память по сумме переменных в структуре стринг 2*28 байт + 4 байта + 8 = 68 байт

			// student s1 = { "", "", 0,{ 0,0 } }; // инициализация полей при объявлении, должны соответствовать типам

			s1.name = "Dinara";
			s1.fname = "Aikenova";
			s1.age = 18;

			s1.grades[0] = 100; // обращение к полям структур через точку
			s1.grades[1] = 98;
		}
		break;
		case 2:
		{
			student ss[20]; // array of structures, memmory = 68*20;
			student s1 = { "", "", 0,{ 0,0 } };

			ss[0].name = "Dinara";
			ss[0].fname = "Aikenova";


			ss[0].grades[0] = 100;
			ss[1].grades[1] = 98;

			s1.grades[0] = 100;
			s1.grades[1] = 98;

			// s1 = ss[0];

			cout << s1.name << " " << s1.fname << " " << s1.age << " " << s1.grades[0] << " " << s1.grades[1] << endl;
			
			// cin>>
		}
		break;
		case 3:
		{
			student1 *ss;
			int n;
			cin >> n;
			ss = new student1[n];

			for (int i = 0; i < n; i++)
			{
				cin >> ss[i].fname >> ss[i].group;
				for (int j = 0; j < 3; j++)
					cin >> ss[i].grades[j];
			}

			otli4niki(ss, n);
			dvoi4niki(ss, n);

			delete[] ss;
		}
		break;
		case 4:
		{
			ticket *ts;
			int n, choice;
			cin >> n;
			ts = new ticket[n];

			string c_date;
			double c_price;
			bool f = true;

			for (int i = 0; i < n; i++)
				ts[i].enter_ticket();

			while (true) {
				cout << "Enter 1-to print by date" << endl;
				cout << "Enter 1-to print by price" << endl;
				cout << "Enter 1-to print all" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cin >> c_date;
					for (int i = 0; i < n; i++)
						ts[i].print_by_day(c_date);
					break;
				case 2:
					cin >> c_price;
					for (int i = 0; i < n; i++)
					if (ts[i].cmp_by_price(c_price)) ts[i].print();
					break;
				case 3:
					for (int i = 0; i < n; i++)
						ts[i].print();
					break;
				}
			}

			// fill_ticket(ts, n);

			

		}
		break;
		case 5:
		{
			cout << sizeof(example) << endl;
		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{
			int n;
			cin >> n;
			stud *ss;
			date d;
			ss = new stud[n];

			for (int i = 0; i < n; i++)
			{
				cout << "Enter" << i + 1 << "th student" << endl;
				ss[i].enter_stud();
			}

			system("cls"); // для очистки экрана
			cout << "Enter date to compare with:" << endl;
			d.enter_date();
			for (int i = 0; i < n; i++)
			{
				if(ss[i].entering_date.cmp_date(d))
					ss[i].print();
			}
		}
		break;
		case 8:
		{
			char str[100] = "hello ";
			char str1[100] = "hi world";
			strncpy_s(str,str1, 3); //копирование определенное количество символов
			strcpy_s(str, str1);//копирование в первый массив второй

			strcpy_s(str, strstr(str1, "w"));

			strcat_s(str, str1); // str= str+str1

			strncat_s(str, str1, 4);

			strncat_s(str, strstr(str1,"w"), 4);

			cout << strcmp(str, str1) << endl;

			cout << strncmp(str, str1,2) << endl;

			cout << str << endl;

			// char str[100] = "This!is example for.my#students"; //разбивка на контекст

			char* context;
			char* p = strtok_s(str, "!.#is ", &context);
			while (p!=NULL)
			{
				cout << p << "    " << endl;
				p = strtok_s(context, "!.#is ", &context);
			}
		}
		break;
		case 9:
		{

			char final_text[100] = "";
			char a[100] = "This is example for my example";
			char b[100] = "example";
			char c[100] = "test";

			char* context;
			char* p = strtok_s(a, " ", &context);
			while (p != NULL)
			{
				if (strcmp(p, b) != 0)
					//strcat_s(final_text, c);
			
					strncat_s(final_text, p, strlen(p));
				strcat_s(final_text, " ");
						
				p = strtok_s(context, " ", &context);
				
			}
			cout << final_text << endl;
		}
		break;
		case 10:
		{
			/*int a;
			char str[30];
			int index = 0;
			cin >> str;
			cout << Aatoi_t(str) << endl;
			cout << Aatoi_t1(str) << endl;
			_itoa_s(a, str, 10);
			cout<<atoi(str)<<endl;


			for (int i = 0; i < strlen(str); i++)
			{
			cout << str[i] << endl;
			}
			while (a)
			{
			str[index++] = char(48 + a % 10);
			a /= 10;
			}
			for (int k = index-1; k >= 0; k--)
			{
			cout << str[k] << endl;
			}
*/
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}