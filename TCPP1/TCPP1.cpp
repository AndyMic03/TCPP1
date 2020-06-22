#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#define N 3
using namespace std;
int main() {
	string names[N], suf, nsuf, maxn, minn, premin, premax, preavg, re, pass[N], file("output.txt");
	int grades[N], mins, maxs, i, maxw(0), op, sum(0), maxg(0), ecnt(0), passg, sump(0), fin, fir,ini;
	int zer(0), ten(0), twe(0), thi(0), fou(0), fif(0), six(0), sev(0), eig(0), nin(0), hun(0);
	float avg,perp, rat;
	init:
	cout << "Input the minimum grade: ";
	cin >> mins;
	cout << "Input the maximum grade: ";
	cin >> maxs;
	int ming(maxs);
	if (mins < 0) {
		cout << "The minimum grade is a negative number";
		if (maxs < 0) {
			cout << " and the maximum grade is a negative number." << endl;
			goto init;
		}
		else {
			cout << "." << endl;
			goto init;
		}
	}
	if (maxs < 0) {
		cout << "The maximum grade is a negative number." << endl;
		goto init;
	}
	if (mins > maxs) {
		cout << "The minimum grade is greater than the maximum grade." << endl;
		goto init;
	}
	if (mins == maxs) {
		cout << "The minimum grade is equal to the maximum grade." << endl;
		goto init;
	}
	input:
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
		if (re == "yes")
			goto input;
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
	cout << "9.Exit the console" << endl;
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
					ofstream output;
					if (file=="output.txt") {
						output.open(file);
						output << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << endl;
						for (i = 0; i < N; i++)
							output << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << grades[i] << endl;
						output.close();
						cout << "The file was saved as 'output.txt'.";
						cout << endl;
						file = "output0.txt";
						goto menu;
					}
					else {	
						cout << "The file already exixts. The file will be saved as '";
						for (i = 0; i < 100; i++) {
							if (file.at(6) = i) {
								file ="output" + to_string(i+1) + ".txt";
								break;
							}
						}
						cout << file << "'." << endl;
						output.open(file);
						file = "output" + to_string(i + 2) + ".txt";
						output << '\t' << setw(maxw) << "Name" << '\t' << "|" << '\t' << "Grade" << endl;
						for (i = 0; i < N; i++)
							output << '\t' << setw(maxw) << names[i] << '\t' << "|" << '\t' << grades[i] << endl;
						output.close();
						cout << endl;
						goto menu;
					}
				}
				else
					if (op == 6) {
						cout << "Are you sure that you would you like to re-enter the data? (yes/no)" << endl;
						cout << ">";
						cin >> re;
						if (re == "yes")
							goto input;
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
								goto init;
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
								if (op == 9)
									return 0;
								else {
									cout << endl;
									cout << "ERROR" << endl;
									goto menu;
								}
}