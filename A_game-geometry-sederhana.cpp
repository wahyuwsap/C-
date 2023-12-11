#include <string.h>
#include <windows.h>
#include <ncurses/ncurses.h>
//#include "music.h"


using namespace std;

//kecepatan kotak, jika semakin kecil nilainya maka semakin cepat
int time;

void warna();
void menu_utama_play();
void menu_utama_exit();
void mode();
void play();
void exit();
void cara_bermain();
void credits1();

int main(){

//	playMusic(); // Panggil fungsi dari musik.cpp
  //  return 0;
	
	char ch;
	int select;
	char spike;
	
	
	initscr();

	warna();//memanggil fungsi warna
	
	curs_set(0);//menghilangkan cursor
	
	noecho();
	
	start_color();
	
	menu_utama_play();select=1;
	
	while(true){
		for(int i=0;;){
		noecho();
		ch = getch();
			if(ch==72){//tampilan selection play // 72 adalah kode ascii untuk up arrow
				clear();
		        menu_utama_play();select=1;
			}
			else if(ch == 80){//tampilan selection exit // 80 adalah kode ascii untuk down arrow
				clear();
		        menu_utama_exit();select=2;
		        
			}else if(ch == 77){//tampilan cara bermain // 77 adalah kode ascii untuk right arrow
				clear();
		        cara_bermain();select=3;
			}
			else if(ch == 75){//tampilan cara bermain // 75 adalah kode ascii untuk left arrow
				clear();
		        menu_utama_play();select=4;
			}
			else if(ch == 105){//tampilan credits // 105 adalah kode ascii untuk huruf i
				clear();
		        credits1();select=5;
			}
			
			if(ch == '\n'){
				
				if(select == 1){//select play
					mode();
				}
				if(select == 2){// exit
					exit(0);
				}
				if(select == 3){// exit
					cara_bermain();
				}
				if(select == 4){// exit
					mode();
				}
				if(select == 5){// exit
					credits1();
				}
			}
		}	
	}

	getch();
	refresh();
	endwin();
	
}

void warna(){
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_WHITE);
	init_pair(2,COLOR_WHITE,COLOR_BLUE);
}
void credits1(){
	mvprintw (11,30, "pembuat game :");refresh();
	mvprintw (12,30, "Wahyu Sri Aryo Pangestu");refresh();
	mvprintw (13,30, "Zidan Ahmad At-thoriq");refresh();
	mvprintw (14,30, "Kemas M Alfath Iskandar");refresh();
	mvprintw (15,30, "Indah Febriana Della");refresh();
	attron(COLOR_PAIR(2));
	mvprintw (17,36, "Klik kiri untuk kembali ke menu utama <-");refresh();
	attroff(COLOR_PAIR(1));
	
	
}

void cara_bermain(){
	mvprintw (8,46, "Intruksi cara bermain");refresh();
	attron(COLOR_PAIR(1));
	mvprintw (11,30, "menghindar dari spike dan panah, jika tertabrak, akan kalah");refresh();
	attroff(COLOR_PAIR(1));
	mvprintw (13,32, "panah atas (^) untuk memindahkan pemain ke jalur atas  ");refresh();
	mvprintw (14,31, "panah bawah (v) untuk memindahkan pemain ke jalur bawah  ");refresh();
	attron(COLOR_PAIR(2));
	mvprintw (17,36, "Klik kiri untuk kembali ke menu utama <-");refresh();
	attroff(COLOR_PAIR(1));
	
}

  

void menu_utama_play(){ 
	mvprintw (0,0,"        :::   :::    ::::::::::  ::::    :::  :::    :::      :::    ::::::::::::::    :::        :::   :::        ::: ");refresh();
	mvprintw (1,0,"      :+:+: :+:+:   :+:        :+:+:   :+:  :+:    :+:       :+:    :+:    :+:      :+: :+:     :+:+: :+:+:     :+: :+:");refresh();
	mvprintw (2,0,"    +:+ +:+:+ +:+  +:+        :+:+:+  +:+  +:+    +:+       +:+    +:+    +:+     +:+   +:+   +:+ +:+:+ +:+   +:+   +:+");refresh();
	mvprintw (3,0,"   +#+  +:+  +#+  +#++:++#   +#+ +:+ +#+  +#+    +:+       +#+    +:+    +#+    +#++:++#++:  +#+  +:+  +#+  +#++:++#++:");refresh();
	mvprintw (4,0,"  +#+       +#+  +#+        +#+  +#+#+#  +#+    +#+       +#+    +#+    +#+    +#+     +#+  +#+       +#+  +#+     +#+ ");refresh();
	mvprintw (5,0," #+#       #+#  #+#        #+#   #+#+#  #+#    #+#       #+#    #+#    #+#    #+#     #+#  #+#       #+#  #+#     #+#  ");refresh();
	mvprintw (6,0,"###       ###  ########## ###    ####   ########         ########     ###    ###     ###  ###       ###  ###     ###    ");refresh();

	mvprintw (9,42, "(Tekan enter untuk memilih!)");refresh();
	attron(COLOR_PAIR(1));
	mvprintw (12,53, "PLAY :)");refresh();
	attroff(COLOR_PAIR(1));
	mvprintw (14,53, "EXIT");refresh();
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	mvprintw (17,35, "Intruksi Cara Bermain : klik panah kanan ->");refresh();
	attroff(COLOR_PAIR(1));
	mvprintw (18,48, "credits (klik i)");refresh();
	
}

void menu_utama_exit(){
	mvprintw (0,0,"        :::   :::    ::::::::::  ::::    :::  :::    :::      :::    ::::::::::::::    :::        :::   :::        ::: ");refresh();
	mvprintw (1,0,"      :+:+: :+:+:   :+:        :+:+:   :+:  :+:    :+:       :+:    :+:    :+:      :+: :+:     :+:+: :+:+:     :+: :+:");refresh();
	mvprintw (2,0,"    +:+ +:+:+ +:+  +:+        :+:+:+  +:+  +:+    +:+       +:+    +:+    +:+     +:+   +:+   +:+ +:+:+ +:+   +:+   +:+");refresh();
	mvprintw (3,0,"   +#+  +:+  +#+  +#++:++#   +#+ +:+ +#+  +#+    +:+       +#+    +:+    +#+    +#++:++#++:  +#+  +:+  +#+  +#++:++#++:");refresh();
	mvprintw (4,0,"  +#+       +#+  +#+        +#+  +#+#+#  +#+    +#+       +#+    +#+    +#+    +#+     +#+  +#+       +#+  +#+     +#+ ");refresh();
	mvprintw (5,0," #+#       #+#  #+#        #+#   #+#+#  #+#    #+#       #+#    #+#    #+#    #+#     #+#  #+#       #+#  #+#     #+#  ");refresh();
	mvprintw (6,0,"###       ###  ########## ###    ####   ########         ########     ###    ###     ###  ###       ###  ###     ###    ");refresh();

	mvprintw (9,42, "(Tekan enter untuk memilih!)");refresh();
	mvprintw (12,53, "PLAY");refresh();
	attron(COLOR_PAIR(1));
	mvprintw (14,53, "EXIT :(");refresh();attroff(COLOR_PAIR(1));refresh();
	attron(COLOR_PAIR(2));
	mvprintw (17,35, "Intruksi Cara Bermain : klik panah kanan ->");refresh();attroff(COLOR_PAIR(2));
	mvprintw (18,48, "credits (klik i)");refresh();
}

void mode(){
	clear();
	char md;
	mvprintw (9,43, "Masukan tingkat kesulitan game!");refresh();
	mvprintw (11,50, "1. Mudah Banget");refresh();
	mvprintw (12,50, "2. Masih Mudah");refresh();
	mvprintw (13,50, "3. Normal");refresh();
	mvprintw (14,50, "4. Sulit");refresh();
	mvprintw (15,50, "5. Mustahil");refresh();
	mvprintw (18,47, "Pilihan anda : ");
	
	echo();
	
	md = getch();//input tingkat kesulitan
	
	if(md == '1'){
		time=80;play();
	}
	else if(md == '2'){
		time=50;play();
	}
	else if(md == '3'){
		time=30;play();
		
	}else if(md == '4'){
		time=12;play();
	}
	else if(md == '5'){
		time=7;play();
	}
}
 void laser(){
 	for (int i = 0; i <= 20; i++){
 		
	 }
 }

void play(){
	
	nodelay(stdscr, TRUE);
	
	//inisiasi warna
	init_pair(1,COLOR_CYAN,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_WHITE);
	init_pair(3,COLOR_YELLOW,COLOR_YELLOW);
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);
	
	//sumbu y = 7 dan 9
	//sumbu x = 60 sampai dengan 116
	
	// titik kordinat rintangan y,x (spike)
	
	int a=5;
	int a1=6;
	int a2=7;
	
	int b=100;
	int b1=101;
	int b2=102;
	
	int c=9;
	int c1=10;
	int c2=11;
	
	int d=115;
	int d1=116;
	int d2=117;
	
	int e=5;
	int e1=6;
	int e2=7;
	
	int f=130;
	int f1=131;
	int f2=132;
	
	int g=9;
	int g1=10;
	int g2=11;
	
	int h=145;
	int h1=146;
	int h2=147;
	
	int j=5;
	int j1=6;
	int j2=7;
	
	int k=160;
	int k1=161;
	int k2=162;
		
	int l=9;
	int l1=10;
	int l2=11;
	
	int m=175;
	int m1=176;
	int m2=177;
	
	int n=5;
	int n1=6;
	int n2=7;
	
	int n3=10;
	
	int o=191;
	int o1=192;
	int o2=193;
	
	
	int skors = 0;
	
	int y= 7; //y=a
	int x= 2; //x=b
	 
	
	//kotak kuning
	int tombol; 
	
	char kotak[100] = "<><>";
	char kotak1[100] = "<><>";
    char spike[100] = "|";
    char spike2[100] = "| |";  
    char spike3[100] = "|   |";
	char laser[100]= "<-----|"; 
	char lasergagal[100]= "<=====|" ;
	
    char beda3[100] = "\\    /";
    char beda2[100] = "  \\  /";  
    char beda[100] = "    \\/";
	
  
	//looping utama
	while(true){
	for(int i = 0;i<200;i++){
		skors++;//syarat score agar nilainya bertambah terus
		mvprintw(20,11, "Score = ");
		mvprintw(20,20,"%d", skors);
		
		noecho();
		tombol=getch();//menangkap input tombol
		clear();
		
	
    
		//membuat garis lurus
		attron(COLOR_PAIR(2));
		mvprintw(8,0,"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		
		// menyimpan kordinat spike
		mvprintw(a,b2-i,spike);
		mvprintw(a1,b1-i,spike2);
		mvprintw(a2,b-i,spike3);
		
		mvprintw(c,d-i,spike3);
		mvprintw(c1,d1-i,spike2);
		mvprintw(c2,d2-i,spike);
		
		mvprintw(e,f2-i,spike);
		mvprintw(e1,f1-i,spike2);
		mvprintw(e2,f-i,spike3);
		
		mvprintw(g,h-i,spike3);
		mvprintw(g1,h1-i,spike2);
		mvprintw(g2,h2-i,spike);
		
		
		mvprintw(j,k2-i,spike);
		mvprintw(j1,k1-i,spike2);
		mvprintw(j2,k-i,spike3);
	
		mvprintw(l,m-i,spike3);
		mvprintw(l1,m1-i,spike2);
		mvprintw(l2,m2-i,spike);
		
		mvprintw(n,o2-i,spike);
		mvprintw(n1,o1-i,spike2);
		mvprintw(n2,o-i,spike3);
		attroff(COLOR_PAIR(1));
		
		mvprintw(l,o2+300-(i*3), beda3);  //jadi kek ngebut aja gtu seh
		mvprintw(l1,o1+300-(i*3),beda2);
		mvprintw(l2,o+300-(i*3),beda);
		
		
		attron(COLOR_PAIR(4));

		// membuat laser(panah)
		mvprintw(l+1, o-((i-7)*2),laser); // laser tipuan
		attroff(COLOR_PAIR(4));
		mvprintw(l1, o-((i+20)*3),laser); // laser bagian atas
		mvprintw(n1, o-(i*3),laser); // laser bagian bawah
		
		
		
		Sleep(time);
//		for (int j=0;j<o2;j++){
//			mvprintw(n1,o1-j,laser)
//		}
		//kondisi ketika kotak kuning naik turun
		if(tombol==72||tombol==119){
			y=7;
		}
		else if(tombol==80||tombol==115){
			y=10;
		}
		attroff(COLOR_PAIR(1));refresh();
		
		//membuat kotak kuning naik dan turun
		attron(COLOR_PAIR(3));
		mvprintw(y,x, kotak);
		mvprintw(y-1,x, kotak1);
		attroff(COLOR_PAIR(3));
		//(y==a2 && x== b-i) || (y==a2-1 && x== b-i+2)
		//kondisi manual jika kotak kuning menabrak spike
		
		if(y==a2 && x== b-i-2){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y ==a2 && x== b-i+3){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y-1==c && x==d-i-2){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y-1==c && x==d-i+3){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==e2 && x==f-i-2){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==e2 && x==f-i+3){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y-1==g && x==h-i-2){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y-1==g && x==h-i+3){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==j2 && x==k-i-2){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==j2 && x==k-i+3){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y-1==l && x==m-i-2){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y-1==l && x==m-i+3){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==n2 && x==o-i-2){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==n2 && x==o-i+3){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==n2 && x==o-(i*3)){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		
		else if(y==l1 && x==o-((i+20)*3)){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		
		refresh();
		}
	}
}


