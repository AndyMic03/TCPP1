﻿#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<thread>
#include<chrono>
#include <conio.h>
#include<math.h>
#define N 3
using namespace std;
int main() {
	string names[N], suf, nsuf, maxn, minn, premin, premax, preavg, re, pass[N], file, bar, flnm;
	int grades[N], mins, maxs, ming, i, maxw(0), op, sum(0), maxg(0), ecnt(0), passg, sump(0), fin, fir, ini, t(250), start(0);
	int zer(0), ten(0), twe(0), thi(0), fou(0), fif(0), six(0), sev(0), eig(0), nin(0), hun(0); //Chart Variables
	double avg,perp, rat, per(0);
	ifstream input;
	ofstream output;
	string username, password; //Lock Strings
	char inpass[100], outpass[100];
	int temp,att(3), lock(0); //Lock Variables
	welcome:
	for (i = 0; i < 25; i++) {
		bar += "#";
		t -= 10;
		cout << "\n\n\n";
		cout << "\t\t*****************************" << endl;
		cout << "\t\t*  Welcome to TCPP1(v0.20)! *" << endl;
		cout << "\t\t  " << bar << "  " << endl;
		cout << "\t\t*****************************" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		system("cls");
	}
	cout << "\n\n\n";
	cout << "\t\t*****************************" << endl;
	cout << "\t\t*  Welcome to TCPP1(v0.20)! *" << endl;
	cout << "\t\t* Press any key to continue *" << endl;
	cout << "\t\t*****************************" << endl;
	cout << endl;
	_getch();
	bar = "";
	input.open("init.txt");
	input >> mins;
	input >> maxs;
	input >> start;
	input.close();
	if (start == 0)
		goto first;
	else
		goto pass;
	pass:
	system("cls");
	input.open("lock.txt");
	if (input.fail()) {
		cout << "\t\t     SYSTEM FILES HAVE BEEN TAMPERED WITH" << endl;
		cout << "\t\t       PLEASE CONTACT AN ADMINISTRATOR" << endl;\
		cout << "\t\t           TERMINATING PROGRAM..." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		return 104;
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
		goto pass;
	}
	cout << "\t\t       Username: ";
	cin >> username;
	flnm = username;
	file = flnm + ".txt";
	input.open(file);
	if (input.fail()) {
		cout << "\t\t     Incorrect Username" << endl;
		att--;
		cout << "\t\t   Resetting in 10 seconds.";
		this_thread::sleep_for(chrono::seconds(10));
		input.close();
		goto pass;
	}
	input >> inpass;
	input.close();
	cout << "\t\t       Password: ";
	cin >> password;
	for (i = 0; (i < 100 && inpass[i] != '\0'); i++)
		inpass[i] = inpass[i] - 2;
	if (inpass == password) {
		cout << "\t\t******************************" << endl;
		cout << "\t\t*       ACCESS GRANTED       *" << endl;
		cout << "\t\t*          WELCOME           *" << endl;
		cout << "\t\t*****************************" << endl;
		goto iprompt;
	}
	else {
		cout << "\t\t     Incorrect Password" << endl;
		att--;
		cout << "\t\t   Resetting in 10 seconds.";
		this_thread::sleep_for(chrono::seconds(10));
		goto pass;
	}
	first:
	cout << endl;
	cout << "*************************************************************" << endl;
	cout << "*  Welcome to the 'Teacher Catalogue of Pupils' Program 1!  *" << endl;
	cout << "*  This program will catalogue your student and test data.  *" << endl;
	cout << "* You will now be prompted with a series of menus in order  *" << endl;
	cout << "*to complete the initialisation and create your first class.*" << endl;
	cout << "*                 PRESS ANY KEY TO CONTINUE                 *" << endl;
	cout << "*************************************************************" << endl;
	_getch();
	cout << "\n\n\n";
	cout << "*************************************************************" << endl;
	cout << "*                        LOGIN INFO                         *" << endl;
	cout << "*                      INITIALISATION                       *" << endl;
	cout << "*************************************************************" << endl;
	cout << "\t\t       Username: ";
	cin >> username;
	cout << "\t\t       Password: ";
	cin >> outpass;
	for (i = 0; (i < 100 && outpass[i] != '\0'); i++)
		outpass[i] = outpass[i] + 2;
	flnm = username;
	file = flnm + ".txt";
	output.open(file);
	output << outpass;
	output.close();
	start = 1;
	system("cls");
	goto iprompt;
	iprompt:
	cout << "\t             Would you like to:" << endl;
	cout << "\t       1.Input new initialization data" << endl;
	cout << "\t     2.Open existing initialization data" << endl;
	cout << "\t     >";
	cin >> op;
	cout << endl;
	if (op == 1)
		goto iinput;
	else
		if (op == 2)
			goto iopen;
		else {
			system("cls");
			cout << "ERROR. Quitting...";
			goto welcome;
		}
	iopen:
	input.open("init.txt");
	input >> mins;
	input >> maxs;
	input.close();
	ming = maxs;
	goto nprompt;
iinput:
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
			goto iinput;
		}
		else {
			cout << "." << endl;
			goto iinput;
		}
	}
	if (maxs < 0) {
		cout << "The maximum grade is a negative number." << endl;
		goto iinput;
	}
	if (mins > maxs) {
		cout << "The minimum grade is greater than the maximum grade." << endl;
		goto iinput;
	}
	if (mins == maxs) {
		cout << "The minimum grade is equal to the maximum grade." << endl;
		goto iinput;
	}
	cout << "Would you like to save the initialization? (yes/no)" << endl;
	cout << ">";
	cin >> re;
	if (re == "yes") {
		output.open("init.txt");
		output << mins << endl;
		output << maxs << endl;
		output << start << endl;
		output.close();
		cout << "The file was saved as 'init.txt'."<<endl;
		cout << endl;
		goto nprompt;
	}
	else
		if (re == "no")
			goto nprompt;
		else {
			system("cls");
			cout << "ERROR. Quitting...";
			goto iinput;
		}
	nprompt:
	cout << "\t\t     Would you like to:" << endl;
	cout << "\t\t  1.Input new student data" << endl;
	cout << "\t\t2.Open existing student data" << endl;
	cout << "\t\t>";
	cin >> op;
	cout << endl;
	if (op == 1)
		goto ninput;
	else
		if (op == 2)
			goto nopen;
		else {
			system("cls");
			cout << "ERROR. Quitting...";
			goto welcome;
		}
	nopen:
	cout << "Which class would you like to open?" << endl;
	cout << ">";
	cin >> flnm;
	file = flnm + ".txt";
	input.open(file);
	for (i = 0; i < N; i++)
		getline(input, names[i]);
	input.close();
	goto ginput;
	ninput:
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
		cout << "The file was saved as '"<<file<<"'."<<endl;
		cout << endl;
		goto ginput;
	}
	else
		if (re == "no")
			goto ginput;
		else {
			system("cls");
			cout << "ERROR. Quitting...";
			goto ninput;
		}
	ginput:
	for (i = 0; i < N; i++) {
		if (names[i].back() == 's')
			nsuf = names[i] + "'";
		else
			nsuf = names[i] + "'s";
		cout << "Input " << nsuf << " grade: ";
		cin >> grades[i];
	}
	system("cls");
	for (i = 0; i < N; i++) {
		if (grades[i] < mins) {
			cout << "The grade of " << names[i] << " is less than the minimum."<<endl;
			ecnt++;
		}
		else
			if (grades[i] > maxs) {
				cout << "The grade of " << names[i] << " is more than the maximum number."<<endl;
				ecnt++;
			}
			else
				cout << "The grade of " << names[i] << " is within the grade range."<<endl;
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
			goto ginput;
		}
		else
			if (re == "no")
				goto menu;
			else {
				system("cls");
				cout << "ERROR. Quitting...";
				goto menu;
			}
		re = "no";
	}
	for (i = 0; i < N; i++) {
		if (names[i].size() > maxw)
			maxw = names[i].size();
	}
	cout << "DATA INPUT COMPLETED!" << endl;
	menu:
	cout << endl;
	cout << "Please select an option:" << endl;
	cout << "1.Display the name and grade list" << endl;
	cout << "2.Display the min, avg and max values" << endl;
	cout << "3.Display passing and failing students" << endl;
	cout << "4.Display the grade destribution graph" << endl;
	cout << "5.Save the values to a text file" << endl;
	cout << "6.Re-Input the test results" << endl;
	cout << "7.Re-Initialize the min/max grades" << endl;
	cout << "8.Marking Scheme Converter" << endl;
	cout << "9.Sign Out" << endl;
	cout << ">";
	cin >> op;
	system("cls");
	if (op == 1) {
		cout << endl;
		cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << endl;
		for (i = 0; i < N; i++)
			cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << grades[i] << endl;
		cout << endl;
		goto menu;
	}
	else
		cout << endl;
	if (op == 2) {
		for (i = 0; i < N; i++)
			sum += grades[i];
		avg = (float)sum / N;
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
		goto menu;
	}
	else
		if (op == 3) {
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
			perp = (float)sump/N*100;
			cout << endl;
			cout << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Passed/Failed" << endl;
			for (i = 0; i < N; i++)
				cout << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << pass[i] << endl;
			cout << endl;
			cout << "The percentage of students that passed is " << perp << "%." << endl;
			goto menu;
		}
		else
			if (op == 4) {
				if (mins != 0 || maxs != 100) {
					cout << "\t\tWARNING! Graphing is incompatible with your configuration." << endl;
					cout << "\t\t\tPress any key to return to the menu..."<<endl;
					_getch();
					goto menu;
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
							goto menu;
						else {
							system("cls");
							cout << "ERROR. Quitting...";
							goto menu;
						}
					re = "no";
				}
				for (i = 0; i < N; i++) {
					if (grades[i] >= 0 && grades[i] < 10)
						zer++;
					else
						if (grades[i] >= 10 && grades[i] < 20)
							ten++;
						else
							if (grades[i] >= 20 && grades[i] < 30)
								twe++;
							else
								if (grades[i] >= 30 && grades[i] < 40)
									thi++;
								else
									if (grades[i] >= 40 && grades[i] < 50)
										fou++;
									else
										if (grades[i] >= 50 && grades[i] < 60)
											fif++;
										else
											if (grades[i] >= 60 && grades[i] < 70)
												six++;
											else
												if (grades[i] >= 70 && grades[i] < 80)
													sev++;
												else
													if (grades[i] >= 80 && grades[i] < 90)
														eig++;
													else
														if (grades[i] >= 90 && grades[i] < 100)
															nin++;
														else
															if (grades[i] == 100)
																hun++;
				}
				cout << "0-9%:   ";
				for (i = 0; i < N; i++)
					if (zer > 0) {
						cout << "#";
						zer--;
					}
				cout << endl;
				cout << "10-19%: ";
				for (i = 0; i < N; i++)
					if (ten > 0) {
						cout << "#";
						ten--;
					}
				cout << endl;
				cout << "20-29%: ";
				for (i = 0; i < N; i++)
					if (twe > 0) {
						cout << "#";
						twe--;
					}
				cout << endl;
				cout << "30-39%: ";
				for (i = 0; i < N; i++)
					if (thi > 0) {
						cout << "#";
						thi--;
					}
				cout << endl;
				cout << "40-49%: ";
				for (i = 0; i < N; i++)
					if (fou > 0) {
						cout << "#";
						fou--;
					}
				cout << endl;
				cout << "50-59%: ";
				for (i = 0; i < N; i++)
					if (fif > 0) {
						cout << "#";
						fif--;
					}
				cout << endl;
				cout << "60-69%: ";
				for (i = 0; i < N; i++)
					if (six > 0) {
						cout << "#";
						six--;
					}
				cout << endl;
				cout << "70-79%: ";
				for (i = 0; i < N; i++)
					if (sev > 0) {
						cout << "#";
						sev--;
					}
				cout << endl;
				cout << "80-89%: ";
				for (i = 0; i < N; i++)
					if (eig > 0) {
						cout << "#";
						eig--;
					}
				cout << endl;
				cout << "90-99%: ";
				for (i = 0; i < N; i++)
					if (nin > 0) {
						cout << "#";
						nin--;
					}
				cout << endl;
				cout << "100%:   ";
				for (i = 0; i < N; i++)
					if (hun > 0) {
						cout << "#";
						hun--;
					}
				cout << endl;
				goto menu;
			}
			else
				if (op == 5) {
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
					cout << "The file was saved as '"<<file<<"'.";
					cout << endl;
					goto menu;
				}
				else
					if (op == 6) {
						cout << "Are you sure that you would you like to re-enter the data? (yes/no)" << endl;
						cout << ">";
						cin >> re;
						if (re == "yes")
							goto ginput;
						else
							if (re == "no")
								goto menu;
							else {
								system("cls");
								cout << "ERROR. Quitting...";
								goto menu;
							}
						re = "no";
					}
					else
						if (op == 7) {
							cout << "WARNING! Re-initializtion will wipe the existing data. Do you concent? (yes/no)" << endl;
							cout << ">";
							cin >> re;
							if (re == "yes")
								goto iprompt;
							else
								if (re == "no")
									goto menu;
								else {
									system("cls");
									cout << "ERROR. Quitting...";
									goto menu;
								}
							re = "no";
						}
						else
							if (op == 8) {
								cout << "Enter the initial scheme's max grade: ";
								cin >> fir;
								cout << "Enter the final scheme's max grade: ";
								cin >> fin;
								rat = (float)fin / fir;
								re = "yes";
								while (re == "yes") {
									cout << "Input grade: ";
									cin >> ini;
									cout << "Converted grade: " << (float)ini * rat << endl;
									cout << endl;
									cout<< "Would you like to repeat the convertion ? (yes / no)" << endl;
									cout << ">";
									cin >> re;
								}
								goto menu;
							}
							else
								if (op == 9) {
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
									system("cls");
									goto welcome;
								}
								else {
									cout << endl;
									cout << "ERROR" << endl;
									goto menu;
								}
}