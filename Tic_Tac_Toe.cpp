#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
void hodplayer();
void vivodpole();
void igra1x1();
void igrabot();
void igrabotlow();
void proverka();
void wincheck();
void botlowhod();

char pole[3][3];
int igra = 0, win = 0, error = 0, cord1 = 0, cord2 = 0;

char startznak = 'x', winznak = ' ';

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	startznak = 'x';
	igra = 0;
	win = 0;
	error = 0;
	winznak = ' ';

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			pole[i][j] = ' ';
		}
	}

	cout << " Приветствую в игре крестики-нолики!"<<endl;
	cout << " Игра начинается хода крестиков." << endl;
	cout << " Меню: " << endl;
	cout << " 1 - запустить игру 1х1 (с другом)" << endl;
	cout << " 2 - играть с ботом (в разработке)" << endl;
	cout << " 3 - выйти из игры" << endl;
	cout << " Выберите режим игры! ";
	cin >> igra;
	if (igra == 1) {
		igra1x1();
	}
	if (igra == 2) {
		system("CLS");
		igrabot();
	}
	if (igra == 3) {
		return 0;
	}
}

void igra1x1() {
	startznak = 'x';
	for (int i = 0; i < 9; i++) {
		hodplayer();
	}
	cout << endl << "Ничья";
}

void vivodpole() {
	system("CLS");
	cout << endl << " " << "Игровое поле: " << endl;
	cout << "   " << pole[0][0] << '|' << pole[0][1] << '|' << pole[0][2] << endl;
	cout << "   " << pole[1][0] << '|' << pole[1][1] << '|' << pole[1][2] << endl;
	cout << "   " << pole[2][0] << '|' << pole[2][1] << '|' << pole[2][2] << endl;
}
void hodplayer() {
	vivodpole();
	if (error) {
		cout << " Эта клетка уже занята! Выберите другую. ";
		error = 0;
	}
	cout << endl << " Ходят - " << startznak << ". Напишите координаты клетки, куда хотите сходить.";
	cout << endl << " (Формат координат - сначала ряд от 0 до 2, потом столбец от 0 до 2)" << endl;
	cin >> cord1 >> cord2;
	if (pole[cord1][cord2] != ' ') {
		error = 1;
		hodplayer();
	}
	if (pole[cord1][cord2] == ' ') {
		pole[cord1][cord2] = startznak;
		if (startznak == 'x') startznak = 'o';
		else startznak = 'x';
		wincheck();
	}
}
void proverka() {
	if (pole[0][0] == pole[0][1] && pole[0][1] == pole[0][2] && pole[0][0] != ' ') { win = 1; winznak = pole[0][0]; } // горизонталь 1
	if (pole[1][0] == pole[1][1] && pole[1][1] == pole[1][2] && pole[1][0] != ' ') { win = 1; winznak = pole[1][0]; } // горизонталь 2
	if (pole[2][0] == pole[2][1] && pole[2][1] == pole[2][2] && pole[2][0] != ' ') { win = 1; winznak = pole[2][0]; } // горизонталь 3
	if (pole[0][0] == pole[1][0] && pole[1][0] == pole[2][0] && pole[0][0] != ' ') { win = 1; winznak = pole[0][0]; } // вертикаль 1
	if (pole[0][1] == pole[1][1] && pole[1][1] == pole[2][1] && pole[0][1] != ' ') { win = 1; winznak = pole[0][1]; } // вертикаль 2
	if (pole[0][2] == pole[1][2] && pole[1][2] == pole[2][2] && pole[0][2] != ' ') { win = 1; winznak = pole[0][2]; } // вертикаль 3
	if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2] && pole[0][0] != ' ') { win = 1; winznak = pole[0][0]; } // диагональ 1
	if (pole[0][2] == pole[1][1] && pole[1][1] == pole[2][0] && pole[0][2] != ' ') { win = 1; winznak = pole[0][2]; } // диагональ 2
}
void wincheck() {
	proverka();
	if (winznak == ' ') win = 0;
	if (win) {
		system("CLS");
		if (winznak == 'x') cout << endl << " Победил: крестик! ";
		if (winznak == 'o') cout << endl << " Победил: нолик! ";
		cout << endl << endl << " Нажмите Enter для продолжения...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		system("CLS");
		main();
	}
}

void igrabotlow() {
	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			hodplayer();
		}
		else {
			botlowhod();
		}
	}
	cout << endl << "Ничья";
	main();
}
void igrabot() {
	system("CLS");
	cout << " Выберите сложность бота: " << endl;
	cout << " 1 - Глупый бот (ходит случайно) " << endl << " 2 - Умный бот (в разработке) ";
	cin >> igra;
	if (igra == 1) {
		igrabotlow();
	}
	if (igra == 2) {
		cout << " Этот режим игры еще не доступен! ";
		main();
	}
}
void botlowhod() {
	vivodpole();
	int cord1bot, cord2bot;
	cout << endl << " Ходит бот! Ожидайте..." << endl;
	cord1bot = rand() % 3;
	cord2bot = rand() % 3;
	if (pole[cord1bot][cord2bot] != ' ') {
		error = 1;
		botlowhod();
	}
	if (pole[cord1bot][cord2bot] == ' ') {
		pole[cord1bot][cord2bot] = startznak;
		if (startznak == 'x') startznak = 'o';
		else startznak = 'x';
		wincheck();
	}
}