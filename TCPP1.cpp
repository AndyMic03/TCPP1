#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<thread>
#include<chrono>
#include<conio.h>
#include<math.h>
#include<filesystem>
#include<direct.h>
constexpr auto N = 3;
using namespace std;
void welcome() {
	int i, t(250);
	string bar,version;
	ifstream input;
	ofstream output;
	version = "v0.23";
	for (i = 0; i < 25; i++) {
		bar += "#";
		t -= 10;
		cout << "\n\n\n";
		cout << "\t\t*****************************" << endl;
		cout << "\t\t*  Welcome to TCPP1(" << version << ")! *" << endl;
		cout << "\t\t  " << bar << "  " << endl;
		cout << "\t\t*****************************" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		system("cls");
	}
	cout << "\n\n\n";
	cout << "\t\t*****************************" << endl;
	cout << "\t\t*  Welcome to TCPP1(" << version << ")! *" << endl;
	cout << "\t\t* Press any key to continue *" << endl;
	cout << "\t\t*****************************" << endl;
	cout << endl;
	_getch();
	bar = "";
}
void security(int& att, string cusername, bool& su, bool& admin) {
	string username, password, bar, flnm, file, cdir, ndir, adtst;
	char inpass[100];
	int temp, lock(0), i, loop(1), maxlen(8);
	double per(0);
	char* buffer = {};
	ifstream input;
	ofstream output;
	system("cls");
	su = false;
	input.open("lock.txt");
	if (input.fail()) {
		cout << "\t\t     SYSTEM FILES HAVE BEEN TAMPERED WITH" << endl;
		cout << "\t\t       PLEASE CONTACT AN ADMINISTRATOR" << endl; \
			cout << "\t\t           TERMINATING PROGRAM..." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		while (loop == 1)
			_getch();
	}
	input >> temp;
	input.close();
	if (temp == 1) {
		cout << "\t\t LOCKDOWN WAS IN PROGRESS" << endl;
		cout << "\t\t     REDIRECTING NOW" << endl;
		this_thread::sleep_for(chrono::seconds(2));
		att = 0;
	}
	cout << "\n\n\n";
	cout << "\t\t*****************************" << endl;
	cout << "\t\t*          SECURITY         *" << endl;
	cout << "\t\t*         CHECKPOINT        *" << endl;
	cout << "\t\t*      " << att << " ATTEMPTS LEFT      *" << endl;
	cout << "\t\t*****************************" << endl;
	cout << "\n\n\n";
	if (att == 0) {
		system("cls");
		output.open("lock.txt");
		output << "1";
		output.close();
		for (i = 0; i < 29; i++) {
			cout << "\n\n\n";
			cout << "\t\t*****************************" << endl;
			cout << "\t\t*       LOCKDOWN MODE       *" << endl;
			cout << "\t\t*         ACTIVATED         *" << endl;
			cout << "\t\t*     WAIT FOR 5 MINUTES    *" << endl;
			cout << "\t\t*****************************" << endl;
			cout << "\t\t\t    " << per << "%" << endl;
			cout << "\t\t" << bar << endl;
			this_thread::sleep_for(chrono::milliseconds(10340));
			per += 3.45;
			bar += "#";
			system("cls");
		}
		lock++;
		att += 3;
		output.open("lock.txt");
		output << "0";
		output.close();
		security(att, cusername, su, admin);
	}
	if (lock > 3) {
		cout << "\n\n\n";
		cout << "\t\t*****************************" << endl;
		cout << "\t\t*          TOO MANY         *" << endl;
		cout << "\t\t*     LOCKDOWNS DETECTED    *" << endl;
		cout << "\t\t*           GOODBYE         *" << endl;
		cout << "\t\t*****************************" << endl;
		while (loop == 1)
			_getch();
	}
	cout << "\t\t       Username: ";
	cin >> username;
	flnm = username;
	file = flnm + ".txt";
	input.open(file);
	if (username == "admin") {
		cout << "\t\t       Password: ";
		cin >> password;
		if (password == "pass") {
			cout << "\t\t*************************************************************" << endl;
			cout << "\t\t*                  SUPER-USER MODE ENABLED                  *" << endl;
			cout << "\t\t*************************************************************" << endl;
			su = true;
		}
		return;
	}
	if (input.fail()) {
		cout << "\t\t     Incorrect Username" << endl;
		att--;
		cout << "\t\t   Resetting in 10 seconds.";
		this_thread::sleep_for(chrono::seconds(10));
		input.close();
		security(att, cusername, su, admin);
		return;
	}
	input >> inpass;
	input >> adtst;
	input.close();
	cout << "\t\t       Password: ";
	cin >> password;
	if (adtst == "susr")
		admin = true;
	for (i = 0; (i < 100 && inpass[i] != '\0'); i++)
		inpass[i] = inpass[i] - 2;
	if (inpass == password) {
		system("cls");
		cout << endl;
		cout << "\t\t\t\t******************************" << endl;
		cout << "\t\t\t\t*       ACCESS GRANTED       *" << endl;
		cout << "\t\t\t\t*          WELCOME           *" << endl;
		cout << "\t\t\t\t******************************" << endl;
		cout << endl;
		cusername = username;
		cdir = _getcwd(buffer, maxlen);
		ndir = cdir + "\\" + username;
		_chdir(ndir.c_str());
		return;
	}
	else {
		cout << "\t\t     Incorrect Password" << endl;
		att--;
		cout << "\t\t   Resetting in 10 seconds.";
		this_thread::sleep_for(chrono::seconds(10));
		security(att, cusername, su, admin);
	}
}
void user_input(int& start, int& ch, string mdir) {
	int i, maxlen(8);
	string username, password, flnm, file, pval, cdir, dg, ndir, rdir, admin;
	ofstream output;
	char outpass[100];
	char* buffer = {};
	rdir = _getcwd(buffer, maxlen);
	_chdir(mdir.c_str());
	buffer = {};
	cout << "\n\n\n";
	cout << "*************************************************************" << endl;
	cout << "*                        LOGIN INFO                         *" << endl;
	cout << "*                      INITIALISATION                       *" << endl;
	cout << "*************************************************************" << endl;
	cout << "\t\t       Username: ";
	cin >> username;
	cout << "\t\t       Password: ";
	cin >> outpass;
	cout << "\t\t Is this user an administrator? (yes/no) >";
	cin >> admin;
	for (i = 0; (i < 100 && outpass[i] != '\0'); i++)
		outpass[i] = outpass[i] + 2;
	flnm = username;
	file = flnm + ".txt";
	output.open(file);
	output << outpass << endl;
	if (admin == "yes")
		output << "susr";
	if (admin == "no")
		output << "usr";
	output.close();
	cdir = _getcwd(buffer, maxlen);
	ndir = cdir + "\\" + username;
	_mkdir(ndir.c_str());
	if (ch == 1)
		_chdir(ndir.c_str());
	_chdir(rdir.c_str());
	start = 1;
}
void user_delete(string mdir, string cusername) {
	string username, flnm, cdir, ndir;
	int maxlen(8);
	char* buffer = {};
	cout << "Which user would you like to delete?" << endl;
	cout << ">";
	cin >> username;
	cdir = _getcwd(buffer, maxlen);
	flnm = username + ".txt";
	_chdir(mdir.c_str());
	ndir = cdir + "\\" + username;
	if (cusername == username) {
		cout << "\t\t*************************************************************" << endl;
		cout << "\t\t*                 CANNOT DELETE ACTIVE USER                 *" << endl;
		cout << "\t\t*************************************************************" << endl;
		return;
	}
	ifstream input;
	input.open(username + ".txt");
	if (input.fail()) {
		cout << "\t\t*************************************************************" << endl;
		cout << "\t\t*                    USER DOES NOT EXIST                    *" << endl;
		cout << "\t\t*************************************************************" << endl;
		return;
	}
	input.close();
	remove(ndir.c_str());
	remove(flnm.c_str());
	_chdir(cdir.c_str());
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                        USER DELETED                       *" << endl;
	cout << "\t\t*************************************************************" << endl;
}
void first(int& start, int& ch, string mdir) {
	cout << endl;
	cout << "*************************************************************" << endl;
	cout << "*  Welcome to the 'Teacher Catalogue of Pupils' Program 1!  *" << endl;
	cout << "*  This program will catalogue your student and test data.  *" << endl;
	cout << "* You will now be prompted with a series of menus in order  *" << endl;
	cout << "*to complete the initialisation and create your first class.*" << endl;
	cout << "*                 PRESS ANY KEY TO CONTINUE                 *" << endl;
	cout << "*************************************************************" << endl;
	_getch();
	user_input(start, ch, mdir);
}
void init_input(int& start) {
	int mins, maxs, ming;
	string re;
	ofstream output;
	cout << "\n\n";
	cout << "\t\t********************" << endl;
	cout << "\t\t*  INITIALISATION  *" << endl;
	cout << "\t\t********************" << endl;
	cout << endl;
	cout << "Input the minimum grade: ";
	cin >> mins;
	cout << "Input the maximum grade: ";
	cin >> maxs;
	ming = maxs;
	if (mins < 0) {
		cout << "The minimum grade is a negative number";
		if (maxs < 0) {
			cout << " and the maximum grade is a negative number." << endl;
			init_input(start);
		}
		else {
			cout << "." << endl;
			init_input(start);
		}
	}
	if (maxs < 0) {
		cout << "The maximum grade is a negative number." << endl;
		init_input(start);
	}
	if (mins > maxs) {
		cout << "The minimum grade is greater than the maximum grade." << endl;
		init_input(start);
	}
	if (mins == maxs) {
		cout << "The minimum grade is equal to the maximum grade." << endl;
		init_input(start);
	}
	cout << "Would you like to save the initialization? (yes/no)" << endl;
	cout << ">";
	cin >> re;
	if (re == "yes") {
		output.open("init.txt");
		output << mins << endl;
		output << maxs << endl;
		output.close();
		cout << "The file was saved as 'init.txt'." << endl;
		cout << endl;
		return;
	}
	else
		if (re == "no")
			return;
		else {
			system("cls");
			cout << "ERROR. Quitting...";
			init_input(start);
		}
}
void name_open(string names[N]) {
	string flnm, file;
	ifstream input;
	int i;
	cout << "Which class would you like to open?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	input.open(file);
	for (i = 0; i < N; i++)
		getline(input, names[i]);
	input.close();
	return;
}
void name_input(string names[N]) {
	string suf, re, flnm, file;
	int i;
	ofstream output;
	for (i = 0; i < N; i++) {
		if ((i % 10) == 0)
			suf = "st";
		else
			if ((i % 10) == 1)
				suf = "nd";
			else
				if ((i % 10) == 2)
					suf = "rd";
				else
					suf = "th";
		cout << "Input the " << i + 1 << suf << " name: ";
		cin >> names[i];
	}
	cout << "Would you like to save the student list? (yes/no)" << endl;
	cout << ">";
	cin >> re;
	if (re == "yes") {
		cout << "Which class did you input?" << endl;
		cout << ">";
		cin >> flnm;
		file = flnm + ".txt";
		output.open(file);
		for (i = 0; i < N; i++)
			output << names[i] << endl;
		output.close();
		cout << "The file was saved as '" << file << "'." << endl;
		cout << endl;
		return;
	}
	else
		if (re == "no")
			return;
		else {
			system("cls");
			cout << "ERROR. Quitting...";
			name_input(names);
		}
}
void name_edit(size_t& maxw) {
	int i;
	string flnm, file, word, names[N];
	ifstream input;
	ofstream output;
	cout << "Which class would you like to edit?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	name_open(names);
	cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Edits" << endl;
	for (i = 0; i < N; i++) {
		cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t';
		cin >> names[i];
	}
	cout << endl;
	cout << "How would you like to save that?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	output.open(file);
	for (i = 0; i < N; i++)
		output << names[i] << endl;
	output.close();
	cout << "The file was saved as '" << file << "'.";
	cout << endl;
}
void name_delete() {
	string flnm, file;
	cout << "Which class would you like to delete?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	remove(file.c_str());
}
void grade_input(int& mins, int& maxs, size_t& maxw, string names[N], int grades[N]) {
	int i, ecnt(0);
	string nsuf, re;
	cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << endl;
	for (i = 0; i < N; i++) {
		cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t';
		cin >> grades[i];
	}
	system("cls");
	for (i = 0; i < N; i++) {
		if (grades[i] < mins) {
			cout << "The grade of " << names[i] << " is less than the minimum." << endl;
			ecnt++;
		}
		else
			if (grades[i] > maxs) {
				cout << "The grade of " << names[i] << " is more than the maximum number." << endl;
				ecnt++;
			}
			else
				cout << "The grade of " << names[i] << " is within the grade range." << endl;
	}
	if (ecnt != 0) {
		cout << endl;
		if (ecnt != 1)
			cout << "There are " << ecnt << " errors. Would you like to re-enter the data? (yes/no)" << endl;
		else
			cout << "There is " << ecnt << " error. Would you like to re-enter the data? (yes/no)" << endl;
		cout << ">";
		cin >> re;
		if (re == "yes") {
			ecnt = 0;
			grade_input(mins, maxs, maxw, names, grades);
		}
		else
			if (re == "no")
				return;
			else {
				system("cls");
				cout << "ERROR. Quitting...";
				grade_input(mins, maxs, maxw, names, grades);
			}
		re = "no";
	}
	for (i = 0; i < N; i++) {
		if (names[i].size() > maxw)
			maxw = names[i].size();
	}
	cout << "DATA INPUT COMPLETED!" << endl;
}
void grade_view(string names[N], int grades[N], int& maxw) {
	int i;
	cout << endl;
	cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << endl;
	for (i = 0; i < N; i++)
		cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << grades[i] << endl;
	cout << endl;
}
void grade_stats(string names[N], int grades[N]) {
	int i, sum(0), maxg(0), ming(0);
	double avg;
	string maxn, minn, premin, premax, preavg;
	for (i = 0; i < N; i++)
		sum += grades[i];
	avg = (double)sum / N;
	for (i = 0; i < N; i++) {
		if (grades[i] > maxg) {
			maxg = grades[i];
			maxn = names[i];
		}
	}
	for (i = 0; i < N; i++) {
		if (grades[i] < ming) {
			ming = grades[i];
			minn = names[i];
		}
	}
	if ((ming / 10 == 8) || (ming % 10 == 8))
		premin = "an";
	else
		premin = "a";
	if ((avg / 10 == 8) || ((int)avg % 10 == 8))
		preavg = "an";
	else
		preavg = "a";
	if ((maxg / 10 == 8) || (maxg % 10 == 8))
		premax = "an";
	else
		premax = "a";
	cout << "The lowest score was " << premin << " " << ming << " and was made by " << minn << endl;
	cout << "The average score was " << preavg << " " << avg << endl;
	cout << "The highest score was " << premax << " " << maxg << " and was made by " << maxn << endl;
	cout << endl;
}
void grade_pass(string names[N], int grades[N], int& maxw) {
	int i, passg, sump(0);
	double perp;
	string pass[N];
	cout << "Input the passing grade: ";
	cin >> passg;
	for (i = 0; i < N; i++) {
		if (grades[i] >= passg) {
			pass[i] = "PASSED";
			sump++;
		}
		else
			pass[i] = "FAILED";
	}
	perp = (double)sump / N * 100;
	cout << endl;
	cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Passed/Failed" << endl;
	for (i = 0; i < N; i++)
		cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << pass[i] << endl;
	cout << endl;
	cout << "The percentage of students that passed is " << perp << "%." << endl;
}
void grade_conv() {
	int fir, fin, ini;
	double rat;
	string re;
	cout << "Enter the initial scheme's max grade: ";
	cin >> fir;
	cout << "Enter the final scheme's max grade: ";
	cin >> fin;
	rat = (double)fin / fir;
	re = "yes";
	while (re == "yes") {
		cout << "Input grade: ";
		cin >> ini;
		cout << "Converted grade: " << (double)ini * rat << endl;
		cout << endl;
		cout << "Would you like to repeat the convertion ? (yes / no)" << endl;
		cout << ">";
		cin >> re;
	}
}
void graph_slave(int grades[N], int& a, int& b) {
	int i, count(0);
	for (i = 0; i < N; i++) {
		if (grades[i] >= a && grades[i] < b)
			count++;
	}
	cout << a << "-" << b - 1 << "%:   ";
	for (i = 0; i < N; i++)
		if (count > 0) {
			cout << "#";
			count--;
		}
}
void graph_main(int grades[N], int& mins, int& maxs, int& ecnt) {
	int i, a(0), b(10);
	string re;
	if (mins != 0 || maxs != 100) {
		cout << "\t\tWARNING! Graphing is incompatible with your configuration." << endl;
		cout << "\t\t\tPress any key to return to the menu..." << endl;
		_getch();
		return;
	}
	if (ecnt != 0) {
		cout << "\tCAUTION! Graphing may be inacurate due to errors during the input of data." << endl;
		cout << "\t\t\tDo you want to proceed?(yes/no)" << endl;
		cout << "\t\t\t>";
		cin >> re;
		if (re == "yes")
			re = "no";
		else
			if (re == "no")
				return;
			else {
				system("cls");
				cout << "ERROR. Quitting...";
				return;
			}
		re = "no";
	}
	for (i = 0; i < 11; i++) {
		graph_slave(grades, a, b);
		a += 10;
		b += 10;
	}
}
void test_save(string names[N], size_t& maxw, int grades[N]) {
	int i;
	string flnm, file;
	ofstream output;
	cout << endl;
	cout << "How would you like to save that?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	output.open(file);
	output << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << endl;
	for (i = 0; i < N; i++)
		output << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << grades[i] << endl;
	output.close();
	cout << "The file was saved as '" << file << "'.";
	cout << endl;
}
void test_open(size_t& maxw, string file, string names[N], string grades[N]) {
	int i;
	string flnm, word;
	ifstream input;
	input.open(file);
	for (i = 0; i < N + 1; i++) {
		if (i == 0) {
			input >> word;
			input >> word;
			input >> word;
		}
		else {
			input >> word;
			names[i - 1] = word;
			input >> word;
			input >> word;
			grades[i - 1] = word;
		}
	}
	input.close();
}
void test_view(size_t& maxw) {
	int i;
	string flnm, file, word, names[N], grades[N];
	ifstream input;
	cout << "Which test would you like to view?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	test_open(maxw, file, names, grades);
	cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << endl;
	for (i = 0; i < N; i++)
		cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << grades[i] << endl;
	cout << endl;
}
void test_edit(size_t& maxw) {
	int i, transfer[N]{};
	string flnm, file, word, names[N], grades[N];
	ifstream input;
	cout << "Which test would you like to edit?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	test_open(maxw, file, names, grades);
	cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << '\t' << "|" << '\t' << "Edits" << endl;
	for (i = 0; i < N; i++) {
		cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << grades[i] << '\t' << "|" << '\t';
		cin >> transfer[i];
	}
	test_save(names, maxw, transfer);
	cout << endl;
}
void test_input(size_t& maxw, int& mins, int& maxs) {
	int grades[N];
	string names[N];
	name_open(names);
	grade_input(mins, maxs, maxw, names, grades);
	test_save(names, maxw, grades);
}
void test_delete() {
	string flnm, file;
	cout << "Which test would you like to delete?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	remove(file.c_str());
}
void records_input(string mdir) {
	int i, maxlen(8);
	string rdir, ndir, file, tmp;
	char* buffer = {};
	ifstream input;
	ofstream output;
	struct {
		string id;
		string name;
		string dob;
		string add;
		string fmob;
		string mmob;
		string hmob;
		string past;
		string com;
	}student[N];
	rdir = _getcwd(buffer, maxlen);
	_chdir(mdir.c_str());
	ndir = mdir + "//records";
	_chdir(ndir.c_str());
	for (i = 0; i < N; i++) {
		cout << "Input the ID number of the student: ";
		cin >> student[i].id;
		cout << "Input the full name of the student: ";
		getline(cin, tmp);
		getline(cin, student[i].name);
		cout << "Input the date of birth of the student: ";
		cin >> student[i].dob;
		cout << "Input the father's phone number number of the student: ";
		cin >> student[i].fmob;
		cout << "Input the mother's phone number number of the student: ";
		cin >> student[i].mmob;
		cout << "Input the home's phone number number of the student: ";
		cin >> student[i].hmob;
		cout << "Input any past offences of the student: ";
		getline(cin, tmp);
		getline(cin, student[i].past);
		cout << "Input any comments for the student: ";
		getline(cin, student[i].com);
		file = student[i].id + ".txt";
		output.open(file);
		output << student[i].id << endl;
		output << student[i].name << endl;
		output << student[i].dob << endl;
		output << student[i].fmob << endl;
		output << student[i].mmob << endl;
		output << student[i].hmob << endl;
		output << student[i].past << endl;
		output << student[i].com << endl;
		output.close();
		output.open("rc.txt", ios_base::app);
		output << student[i].id << endl;
		output.close();
	}
	_chdir(rdir.c_str());
	return;
}
void records_view(string mdir) {
	int i, maxlen(8), found(0);
	string rdir, ndir, file, re, tmp, look;
	char* buffer = {};
	ifstream input;
	ofstream output;
	struct {
		string id;
		string name;
		string dob;
		string add;
		string fmob;
		string mmob;
		string hmob;
		string past;
		string com;
	}student[N];
	rdir = _getcwd(buffer, maxlen);
	_chdir(mdir.c_str());
	ndir = mdir + "//records";
	_chdir(ndir.c_str());
	cout << "Input the ID of the student you are looking for:";
	cin >> look;
	input.open("rc.txt");
	for (i = 0; i < N; i++) {
		input >> tmp;
		if (tmp == look)
			found++;
	}
	if (found == 1)
		cout << found << " Resut found." << endl;
	else {
		cout << "No results found." << endl;
		return;
	}
	input.close();
	for (i = 0; i < found; i++) {
		file = look + ".txt";
		input.open(file);
		input >> student[i].id;
		getline(input, tmp);
		getline(input, student[i].name);
		input >> student[i].dob;
		input >> student[i].fmob;
		input >> student[i].mmob;
		input >> student[i].hmob;
		getline(input, tmp);
		getline(input, student[i].past);
		getline(input, student[i].com);
		input.close();
		cout << "ID:            " << student[i].id << endl;
		cout << "Full Name:     " << student[i].name << endl;
		cout << "DOB:           " << student[i].dob << endl;
		cout << "Father Number: " << student[i].fmob << endl;
		cout << "Mother Number: " << student[i].mmob << endl;
		cout << "Home Number:   " << student[i].hmob << endl;
		cout << "Past Offences: " << student[i].past << endl;
		cout << "Comments:      " << student[i].com << endl;
		input.close();
		cout << endl;
		cout << "Would you like to run another search? (yes/no)" << endl;
		cout << ">";
		cin >> re;
		if (re == "yes")
			records_view(mdir);
	}
	_chdir(rdir.c_str());
	return;
}
void records_edit(string mdir) {
	int i, maxlen(8), found(0);
	string rdir, ndir, file, re, tmp, look;
	char* buffer = {};
	ifstream input;
	ofstream output;
	struct {
		string id;
		string name;
		string dob;
		string add;
		string fmob;
		string mmob;
		string hmob;
		string past;
		string com;
	}student[N];
	rdir = _getcwd(buffer, maxlen);
	_chdir(mdir.c_str());
	ndir = mdir + "//records";
	_chdir(ndir.c_str());
	cout << "Input the ID of the student you are looking to edit:";
	cin >> look;
	input.open("rc.txt");
	for (i = 0; i < N; i++) {
		input >> tmp;
		if (tmp == look)
			found++;
	}
	if (found == 1)
		cout << found << " Resut found." << endl;
	else {
		cout << "No results found." << endl;
		return;
	}
	input.close();
	for (i = 0; i < found; i++) {
		file = look + ".txt";
		input.open(file);
		input >> student[i].id;
		getline(input, tmp);
		getline(input, student[i].name);
		input >> student[i].dob;
		input >> student[i].fmob;
		input >> student[i].mmob;
		input >> student[i].hmob;
		getline(input, tmp);
		getline(input, student[i].past);
		getline(input, student[i].com);
		input.close();
		cout << "ID:            " << setw(20) << student[i].id << endl;
		cout << "Full Name:     " << setw(20) << student[i].name << "\t| Change: ";
		getline(cin, tmp);
		getline(cin, student[i].name);
		cout << "DOB:           " << setw(20) << student[i].dob << "\t| Change: ";
		cin >> student[i].dob;
		cout << "Father Number: " << setw(20) << student[i].fmob << "\t| Change: ";
		cin >> student[i].fmob;
		cout << "Mother Number: " << setw(20) << student[i].mmob << "\t| Change: ";
		cin >> student[i].mmob;
		cout << "Home Number:   " << setw(20) << student[i].hmob << "\t| Change: ";
		cin >> student[i].hmob;
		cout << "Past Offences: " << setw(20) << student[i].past << "\t| Change: ";
		getline(cin, tmp);
		getline(cin, student[i].past);
		cout << "Comments:      " << setw(20) << student[i].com << "\t| Change: ";
		getline(cin, student[i].com);
		output.open(file);
		output << student[i].id << endl;
		output << student[i].name << endl;
		output << student[i].dob << endl;
		output << student[i].fmob << endl;
		output << student[i].mmob << endl;
		output << student[i].hmob << endl;
		output << student[i].past << endl;
		output << student[i].com << endl;
		output.close();
	}
		cout << endl;
		cout << "Would you like to run another search? (yes/no)" << endl;
		cout << ">";
		cin >> re;
		if (re == "yes")
			records_view(mdir);
	
	_chdir(rdir.c_str());
	return;
}
void logout(int& rep, int& log, string mdir) {
	int i, t(250);
	string bar;
	bar = "";
	for (i = 0; i < 7; i++) {
		t -= 10;
		cout << "\n\n\n";
		cout << "\t\t*************" << endl;
		cout << "\t\t  " << bar << "  " << endl;
		cout << "\t\t*************" << endl;
		bar += "#";
		this_thread::sleep_for(chrono::milliseconds(250));
		system("cls");
	}
	cout << "\n\n\n";
	cout << "\t\t*************" << endl;
	cout << "\t\t*  Goodbye  *" << endl;
	cout << "\t\t*************" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	rep = 0;
	log = 1;
	_chdir(mdir.c_str());
	return;
}
void goodbye(int& rep, int& log) {
	int i, t(250);
	string bar;
	bar = "";
	for (i = 0; i < 7; i++) {
		t -= 10;
		cout << "\n\n\n";
		cout << "\t\t*************" << endl;
		cout << "\t\t  " << bar << "  " << endl;
		cout << "\t\t*************" << endl;
		bar += "#";
		this_thread::sleep_for(chrono::milliseconds(250));
		system("cls");
	}
	cout << "\n\n\n";
	cout << "\t\t*************" << endl;
	cout << "\t\t*  Goodbye  *" << endl;
	cout << "\t\t*************" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	rep = 0;
	log = 0;
	return;
}
void submenu1(string names[N], size_t& maxw, int& mins, int& maxs) {
	int op;
	system("cls");
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                       SUBMENU TESTS                       *" << endl;
	cout << "\t\t*                         1.NEW TEST                        *" << endl;
	cout << "\t\t*                       2.EDIT A TEST                       *" << endl;
	cout << "\t\t*                       3.VIEW A TEST                       *" << endl;
	cout << "\t\t*                      4.DELETE A TEST                      *" << endl;
	cout << "\t\t*                           5.BACK                          *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin >> op;
	cout << "\n\n\n";
	switch (op) {
	case 1:
		test_input(maxw, mins, maxs);
		break;
	case 2:
		test_edit(maxw);
		break;
	case 3:
		test_view(maxw);
		break;
	case 4:
		test_delete();
		break;
	case 5:
		return;
		break;
	default:
		submenu1(names, maxw, mins, maxs);
		break;
	}
}
void submenu2(string names[N], size_t& maxw) {
	int op;
	system("cls");
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                      SUBMENU STUDENTS                     *" << endl;
	cout << "\t\t*                        1.NEW CLASS                        *" << endl;
	cout << "\t\t*                       2.EDIT A CLASS                      *" << endl;
	cout << "\t\t*                       3.LOAD A CLASS                      *" << endl;
	cout << "\t\t*                      4.DELETE A CLASS                     *" << endl;
	cout << "\t\t*                           5.BACK                          *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin >> op;
	cout << "\n\n\n";
	switch (op) {
	case 1:
		name_input(names);
		break;
	case 2:
		name_edit(maxw);
		break;
	case 3:
		name_open(names);
		break;
	case 4:
		name_delete();
		break;
	case 5:
		return;
		break;
	default:
		submenu2(names, maxw);
		break;
	}
}
void submenu3(string mdir, int& start, string cusername, int& ch) {
	int op;
	system("cls");
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                      SUBMENU SECURITY                     *" << endl;
	cout << "\t\t*                         1.NEW USER                        *" << endl;
	cout << "\t\t*                       2.EDIT A USER                       *" << endl;
	cout << "\t\t*                      3.DELETE A USER                      *" << endl;
	cout << "\t\t*                           4.BACK                          *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin >> op;
	cout << "\n\n\n";
	switch (op) {
	case 1:
		user_input(start, ch, mdir);
		break;
	case 2:
		return; // placeholder
		break;
	case 3:
		user_delete(mdir, cusername);
		break;
	case 4:
		return;
		break;
	default:
		submenu3(mdir, start, cusername, ch);
		break;
	}
}
void submenu4(int& start, int& mins, int& maxs, int& ming, string mdir) {
	int op;
	system("cls");
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                      SUBMENU UTILITIES                    *" << endl;
	cout << "\t\t*                       1.RE-INITIALISE                     *" << endl;
	cout << "\t\t*                      2.GRADE CONVERTER                    *" << endl;
	cout << "\t\t*                            3.???                          *" << endl;
	cout << "\t\t*                           4.BACK                          *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin >> op;
	cout << "\n\n\n";
	switch (op) {
	case 1:
		init_input(start);
		break;
	case 2:
		grade_conv();
		break;
	case 3:
		records_view(mdir);
		break;
	case 4:
		return;
		break;
	default:
		submenu4(start, mins, maxs, ming, mdir);
		break;
	}
}
void submenu5(string mdir){
	int op;
	system("cls");
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                       SUBMENU RECORDS                     *" << endl;
	cout << "\t\t*                      1.CREATE RECORDS                     *" << endl;
	cout << "\t\t*                       2.EDIT RECORDS                      *" << endl;
	cout << "\t\t*                       3.VIEW RECORDS                      *" << endl;
	cout << "\t\t*                      4.DELETE RECORDS                     *" << endl;
	cout << "\t\t*                           5.BACK                          *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin >> op;
	cout << "\n\n\n";
	switch (op) {
	case 1:
		records_input(mdir);
		break;
	case 2:
		records_edit(mdir);
		break;
	case 3:
		records_view(mdir);
		break;
	case 4:
		//records_delete(mdir);
		break;
	case 5:
		return;
		break;
	default:
		submenu5(mdir);
		break;
	}
}
void mainmenu(string names[N], string mdir, int& rep, int& log, int& start, string cusername, int& ch, int& mins, int& maxs, int& ming, size_t& maxw) {
	int op;
	ifstream input;
	input.open("init.txt");
	input >> mins;
	input >> maxs;
	input.close();
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                         MAIN MENU                         *" << endl;
	cout << "\t\t*                          1.TESTS                          *" << endl;
	cout << "\t\t*                         2.STUDENTS                        *" << endl;
	cout << "\t\t*                        3.UTILITIES                        *" << endl;
	cout << "\t\t*                         4.LOG-OUT                         *" << endl;
	cout << "\t\t*                     5.EXIT THE CONSOLE                    *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin>>op;
	cout << "\n\n\n";
	switch (op) {
		case 1:
			submenu1(names, maxw, mins, maxs);
			break;
		case 2:
			submenu2(names, maxw);
			break;
		case 3:
			submenu4(start, mins, maxs, ming, mdir);
			break;
		case 4:
			logout(rep, log, mdir);
			break;
		case 5:
			goodbye(rep, log);
			break;
		default:
			mainmenu(names, mdir, rep, log, start, cusername, ch, mins, maxs, ming, maxw);
			break;
	}
	return;
}
void mainmenu_s(string names[N], string mdir, int& rep, int& log, int& start, string cusername, int& ch, int& mins, int& maxs, int& ming) {
	int op;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                         MAIN MENU                         *" << endl;
	cout << "\t\t*                  1.SECURITY/ADMINISTRATION                *" << endl;
	cout << "\t\t*                         2.RECORDS                         *" << endl;
	cout << "\t\t*                        3.UTILITIES                        *" << endl;
	cout << "\t\t*                         4.LOG-OUT                         *" << endl;
	cout << "\t\t*                     5.EXIT THE CONSOLE                    *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin >> op;
	cout << "\n\n\n";
	switch (op) {
	case 1:
		submenu3(mdir, start, cusername, ch);
		break;
	case 2:
		submenu5(mdir);
		break;
	case 3:
		submenu4(start, mins, maxs, ming, mdir);
		break;
	case 4:
		logout(rep, log, mdir);
		break;
	case 5:
		goodbye(rep, log);
		break;
	default:
		mainmenu_s(names, mdir, rep, log, start, cusername, ch, mins, maxs, ming);
		break;
	}
	return;
}
void mainmenu_su(string names[N], string mdir, int& rep, int& log, int& start, string cusername, int& ch, int& mins, int& maxs, int& ming, size_t& maxw) {
	int op;
	ifstream input;
	input.open("init.txt");
	input >> mins;
	input >> maxs;
	input.close();
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t*                         MAIN MENU                         *" << endl;
	cout << "\t\t*                          1.TESTS                          *" << endl;
	cout << "\t\t*                         2.STUDENTS                        *" << endl;
	cout << "\t\t*                  3.SECURITY/ADMINISTRATION                *" << endl;
	cout << "\t\t*                        4.UTILITIES                        *" << endl;
	cout << "\t\t*                         5.LOG-OUT                         *" << endl;
	cout << "\t\t*                     6.EXIT THE CONSOLE                    *" << endl;
	cout << "\t\t*************************************************************" << endl;
	cout << "\t\t                            >";
	cin >> op;
	cout << "\n\n\n";
	switch (op) {
	case 1:
		submenu1(names, maxw, mins, maxs);
		break;
	case 2:
		submenu2(names, maxw);
		break;
	case 3:
		submenu3(mdir, start, cusername, ch);
		break;
	case 4:
		submenu4(start, mins, maxs, ming, mdir);
		break;
	case 5:
		logout(rep, log, mdir);
		break;
	case 6:
		goodbye(rep, log);
		break;
	default:
		mainmenu_su(names, mdir, rep, log, start, cusername, ch, mins, maxs, ming, maxw);
		break;
	}
	return;
}
int main() {
	begin:
	string names[N], mdir, cusername;
	char* buffer = {};
	int mins(0), maxs(0), ming(0), ecnt(0), start, rep(1), log(0), att(3), maxlen(8), ch(0);
	bool su(false), admin(false);
	size_t maxw(0);
	ifstream input;
	ofstream output;
	mdir = _getcwd(buffer, maxlen);
	welcome();
	input.open("global_parameters.txt");
	input >> start;
	input.close();
	if (start == 0) {
		ch = 1;
		first(start, ch, mdir);
		ch = 0;
	}
	else
		security(att, cusername, su, admin);
	start = 1;
	if ((su == false) and (admin == false))
		while (rep == 1)
			mainmenu(names, mdir, rep, log, start, cusername, ch, mins, maxs, ming, maxw);
	else
		if (admin == true)
			while (rep == 1)
				mainmenu_su(names, mdir, rep, log, start, cusername, ch, mins, maxs, ming, maxw);
		else
			if (su == true)
				while (rep == 1)
					mainmenu_s(names, mdir, rep, log, start, cusername, ch, mins, maxs, ming);
	if (log == 1)
		goto begin;
	else
		return 0;
}