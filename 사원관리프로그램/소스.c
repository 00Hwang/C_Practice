#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct {
	char ID[20]; // 嬴檜蛤
	char PW[20]; // 綠塵廓��
	char name[50]; // 檜葷
	char belong[50]; // 模樓
	int rank; // 霜晝
	int age; // 釭檜
	int hours; // 識 斬鼠 衛除
}info; // 餌錳 薑爾
info now = { {NULL},{NULL},{NULL},{NULL},0,0,0 };

int menu = 0; // 詭景 殮溘 嫡朝 滲熱
void Eliminate(char* str, char ch);
void create_txt(); // だ橾檜 橈擊衛 儅撩
void start(); // Щ煎斜極 衛濛 �飛�
void sigh_up(); // �蛾灠㊣� �飛�
void login(); // 煎斜檣 �飛�
void main_screen(); // 煎斜檣 �� 詭檣�飛�
void info_menu(); // 薑爾 褻�� 詭景
void cheak_info(); // 薑爾 褻�� �飛�
void other_info_menu(); // 餌錳薑爾 褻�� 詭景
void add_hours(); // 斬鼠衛除 蹺陛 �飛�
void change_PW(); // 綠塵廓�� 滲唳
void check_salary(); // 檜廓 殖 晝罹 褻��
void delete_ID(); // �蛾躠酷�
void manage_salary(); // 晝罹婦葬 �飛�
void permission_ID(); // �蛾灠㊣� 蝓檣
void check_other_info(); // 餌錳薑爾 �挫�
void manage_rank(); // 餌錳霜晝 婦葬
void change_info(); // 偃檣薑爾 熱薑


int main()
{
	create_txt();
	start();

	return 0;
}

void create_txt() {

	FILE* file;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		file = fopen("login.txt", "w");
		if (file == NULL) {
			printf("だ橾 螃盟!");
			exit(1);
		}
		fprintf(file, "admin\n");
		fprintf(file, "admin\n");
		fprintf(file, "admin\n");
		fclose(file);
		file = fopen("admin曖 薑爾だ橾.txt", "w");
		fprintf(file, "婦葬濠\n");
		fprintf(file, "9999\n");
		fprintf(file, "婦葬ぜ\n");
		fprintf(file, "9999\n");
		fprintf(file, "0\n");
		fclose(file);
		file = fopen("啗晝滌 衛晝.txt", "w");
		fprintf(file, "0\n");
		fprintf(file, "10000\n");
		fprintf(file, "12000\n");
		fprintf(file, "14000\n");
		fprintf(file, "16000\n");
		fclose(file);
	}
	else {
	}

}
void start()
{
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛  �蜓蝧� 婦葬 Щ煎斜極  弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛 1. �蛾灠㊣�            弛\n");
	printf("弛 2. 煎斜檣              弛\n");
	printf("弛 3. 謙猿                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		sigh_up(); // �蛾灠㊣� �飛�
		break;
	case 2:
		login(); // 煎斜檣 �飛�
		break;
	case 3:
		exit(1); // 謙猿
		break;
	default:
		start(); // Щ煎斜極 衛濛 �飛�
		break;
	}
}
void sigh_up()
{
	info join = { {NULL},{NULL},{NULL},{NULL},0,0,0 };
	FILE* file = NULL;
	int join_confirm = 0;
	int count = 0;
	char data[100][300];

	file = fopen("login.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		count++;
	}
	fclose(file);

	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛        �蛾灠㊣�        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("ID : "); // �蛾灠㊣� 薑爾 晦殮 掘除
	scanf("%s", join.ID);
	printf("PW : ");
	scanf("%s", join.PW);
	printf("檜葷 : ");
	scanf("%s", join.name);
	printf("釭檜 : ");
	scanf("%d", &join.age);
	printf("模樓 : ");
	scanf("%s", join.belong);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 1. �蛾灠㊣埼趧�        弛\n");
	printf("弛 2. 營殮溘              弛\n");
	printf("弛 3. 諫猿                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		start(); // Щ煎斜極 衛濛 �飛�
		break;
	case 2:
		sigh_up(); // �蛾灠㊣� �飛�
		break;
	case 3:
		for (int i = 0; i < count; i++)
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(data[i], join.ID) != NULL)
				{
					printf("---- 嬴檜蛤陛 醞犒腌棲棻. 營殮溘 夥奧棲棻.---- \n\n");
					Sleep(1000);
					sigh_up();
				}
			}
		}

		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, join.ID);
		strcat(user_file_name, "曖 薑爾だ橾.txt");

		file = fopen("login.txt", "a");
		if (file == NULL) {
			printf("だ橾 螃盟!");
			exit(1);
		}
		fprintf(file, "%s\n", join.ID);
		fprintf(file, "%s\n", join.PW);
		fprintf(file, "%s\n", join.name);
		fclose(file);
		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("だ橾 螃盟!");
			exit(1);
		}
		fprintf(file, "%s\n", join.name);
		fprintf(file, "%d\n", join.age);
		fprintf(file, "%s\n", join.belong);
		fprintf(file, "%d\n", join.rank);
		fprintf(file, "%d\n", join.hours);
		fclose(file);

		printf("---- 陛殮褐羶檜 諫猿腎歷蝗棲棻.---- \n\n");
		Sleep(1000);
		start(); // Щ煎斜極 衛濛 �飛�
		break;
	default:
		start(); // Щ煎斜極 衛濛 �飛�
		break;
	}
}
void login()
{
	info enter = { {NULL},{NULL},{NULL},{NULL},0,0,0 };
	FILE* file;
	char data[100][300];
	char login_data[100][300];
	int count = 0;
	int check = 0;
	int i, j;
	file = fopen("login.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		count++;
	}
	fclose(file);

	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛        煎斜檣          弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("ID : ");
	scanf("%s", enter.ID);
	printf("PW : ");
	scanf("%s", enter.PW);
	for (i = 0; i < count; i++) // ID 匐餌
	{
		if (i == 0 || i % 3 == 0)
		{
			if (strstr(data[i], enter.ID) != NULL)
			{
				check = 1;
			}
		}
	}
	if (check == 0)
	{
		printf("ID陛 ぎ溜蝗棲棻.");
		Sleep(1000);
		start();
	}
	check = 0;
	for (i = 0; i < count; i++) // PW 匐餌
	{
		if (i == 1 || i % 3 == 1)
		{
			if (strstr(data[i], enter.PW) != NULL)
			{
				check = 1;
				j = i;
			}
		}
	}
	if (check == 0)
	{
		printf("PW陛 ぎ溜蝗棲棻.");
		Sleep(1000);
		start();
	}

	char* user_file_name = malloc(sizeof(char) * 50);
	strcpy(user_file_name, data[j - 1]);
	strcat(user_file_name, "曖 薑爾だ橾.txt");
	Eliminate(user_file_name, '\n');
	file = fopen(user_file_name, "r"); // 煎斜檣и ID縑 渠и 薑爾 盪濰
	count = 0;
	while (1)
	{
		fgets(login_data[count], sizeof(data), file);
		if (feof(file)) break;
		Eliminate(login_data[count], '\n');
		count++;
	}
	strcpy(now.ID, enter.ID);
	strcpy(now.PW, enter.PW);
	strcpy(now.name, login_data[0]);
	now.age = atoi(login_data[1]);
	strcpy(now.belong, login_data[2]);
	now.rank = atoi(login_data[3]);
	now.hours = atoi(login_data[4]);
	fclose(file);

	if (now.rank == 0) {
		system("cls");
		printf("\n\n   蝓檣 嫡雖 彊擎 �蛾衋埭炴�.");
		Sleep(2000);
		start(); // 衛濛�飛�
	}

	system("cls");
	printf("\n\n     煎斜檣縑 撩奢ц蝗棲棻!");
	Sleep(1000);
	system("cls");
	printf("\n\n     煎斜檣縑 撩奢ц蝗棲棻!\n            %s", data[j + 1]);
	Sleep(1000);
	system("cls");
	printf("\n\n     煎斜檣縑 撩奢ц蝗棲棻!\n            %s        椒 �紊腎桭炴�!\n\n", data[j + 1]);
	Sleep(1000);
	main_screen();
}
void main_screen()
{
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛        詭檣�飛�        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛 1. 斬鼠衛除 蹺陛       弛\n");
	printf("弛 2. 偃檣薑爾 褻��       弛\n");
	printf("弛 3. 餌錳薑爾 褻��       弛\n");
	printf("弛 4. 晝罹 婦葬           弛\n");
	printf("弛 5. 煎斜嬴醒            弛\n");
	printf("弛 6. 謙猿                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		add_hours();
		break;
	case 2:
		info_menu(); // 薑爾 褻�� 詭景
		break;
	case 3:
		if (now.rank >= 3) {
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
		}
		else {
			system("cls");
			printf("\n\n   '睡濰'霜晝 檜鼻虜 檜辨 陛棟м棲棻.");
			Sleep(2000);
			main_screen(); // 煎斜檣 �� 詭檣�飛�
		}
		break;
	case 4:
		if (now.rank >= 4) {
			manage_salary(); // 晝罹婦葬 �飛�
		}
		else {
			system("cls");
			printf("\n\n   '餌濰'霜晝 檜鼻虜 檜辨 陛棟м棲棻.");
			Sleep(2000);
			main_screen(); // 煎斜檣 �� 詭檣�飛�
		}
		break;
	case 5:
		start();
		break;
	case 6:
		exit(1);
		break;
	default:
		main_screen();
		break;
	}
}
void info_menu()
{
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛      薑爾褻�虜瑒�      弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛 1. 偃檣薑爾 褻��       弛\n");
	printf("弛 2. 檜廓 殖 晝罹 褻��   弛\n");
	printf("弛 3. 綠塵廓�� 滲唳       弛\n");
	printf("弛 4. �蛾� 驍黴           弛\n");
	printf("弛 5. 菴煎陛晦            弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		cheak_info(); // 薑爾 褻�� �飛�
		break;
	case 2:
		check_salary(); // 檜廓 殖 晝罹 褻��
		break;
	case 3:
		change_PW();
		break;
	case 4:
		delete_ID();
		break;
	case 5:
		main_screen(); // 煎斜檣 �� 詭檣�飛�
		break;
	default:
		info_menu(); // 薑爾 褻�� 詭景
		break;
	}
}
void cheak_info()
{
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛      偃檣薑爾褻��      弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("檜葷 : %s\n", now.name); // �蛾灠㊣� 薑爾 晦殮 掘除
	printf("釭檜 : %d\n", now.age);
	printf("模樓 : %s\n", now.belong);
	if (now.rank == 1) {
		printf("霜晝 : 餌錳\n");
	}
	else if (now.rank == 2) {
		printf("霜晝 : 渠葬\n");
	}
	else if (now.rank == 3) {
		printf("霜晝 : 睡濰\n");
	}
	else if (now.rank == 4) {
		printf("霜晝 : 餌濰\n");
	}
	printf("斬鼠衛除 : %d\n", now.hours);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 1. 偃檣薑爾熱薑        弛\n");
	printf("弛 2. 菴煎陛晦            弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		change_info(); // 偃檣薑爾 熱薑
		break;
	case 2:
		info_menu(); // 薑爾 褻�� 詭景
		break;
	default:
		cheak_info(); // 薑爾 褻�� �飛�
		break;
	}
}
void other_info_menu()
{
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛    餌錳薑爾褻�虜瑒�    弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛 1. 餌錳薑爾 褻��       弛\n");
	printf("弛 2. �蛾灠㊣� 蝓檣       弛\n");
	printf("弛 3. 餌錳 霜晝 婦葬      弛\n");
	printf("弛 4. 菴煎陛晦            弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		check_other_info(); // 餌錳薑爾 �挫�
		break;
	case 2:
		permission_ID(); // �蛾灠㊣� 蝓檣
		break;
	case 3:
		manage_rank(); // 餌錳霜晝 婦葬
		break;
	case 4:
		main_screen(); // 煎斜檣 �� 詭檣�飛�
		break;
	default:
		other_info_menu(); // 餌錳薑爾 褻�� 詭景
		break;
	}
}
void add_hours() {
	int time;
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛        衛除殮溘        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("斬鼠 衛除 殮溘(欽嬪 : 衛) : ");
	scanf("%d", &time);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 1. 衛除殮溘 �挫�       弛\n");
	printf("弛 2. 衛除殮溘 鏃模       弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 2:
		info_menu();
		break;
	case 1:
		now.hours += time;
		FILE *file;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, now.ID);
		strcat(user_file_name, "曖 薑爾だ橾.txt");

		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("だ橾 螃盟!");
			exit(1);
		}
		fprintf(file, "%s\n", now.name);
		fprintf(file, "%d\n", now.age);
		fprintf(file, "%s\n", now.belong);
		fprintf(file, "%d\n", now.rank);
		fprintf(file, "%d\n", now.hours);
		fclose(file);
		system("cls");
		printf("\n\n   衛除檜 殮溘腎歷蝗棲棻!\n    ⑷營 殮溘脹 衛除 : %d衛除", now.hours);
		Sleep(3000);
		info_menu(); // 薑爾 褻�� 詭景
		break;
	default:
		system("cls");
		printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
		Sleep(2000);
		add_hours(); // 斬鼠衛除 蹺陛 �飛�
		break;
	}
}
void change_PW() {
	char new_PW[100];
	int count = 0;
	char data[100][300];
	int i, j;
	FILE* file;
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛      綠塵廓�ㄩ秣�      弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("滲唳й ぬ蝶錶萄 : ");
	scanf("%s", new_PW);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 1. 綠塵廓�� 滲唳 �挫�  弛\n");
	printf("弛 2. 綠塵廓�� 滲唳 鏃模  弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		file = fopen("login.txt", "r");
		while (1)
		{
			fgets(data[count], sizeof(data), file);
			if (feof(file)) break;
			count++;
		}
		fclose(file);
		for (i = 0; i < count; i++)
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(data[i], now.ID) != NULL)
				{
					j = i;
				}
			}
		}
		file = fopen("login.txt", "w");
		for (i = 0; i < count; i++)
		{
			if (i == j + 1)
				fprintf(file, "%s\n", new_PW);
			else {
				fprintf(file, "%s", data[i]);
			}
		}
		fclose(file);
		system("cls");
		printf("\n\n   撩奢瞳戲煎 滲唳腎歷蝗棲棻.");
		Sleep(2000);
		info_menu(); // 薑爾 褻�� 詭景
		break;
	case 2:
		info_menu(); // 薑爾 褻�� 詭景
		break;
	default:
		system("cls");
		printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
		Sleep(2000);
		change_PW(); // 綠塵廓�� 滲唳
		break;
	}
}
void check_salary() {
	FILE* file;
	char data[100][300];
	int count = 0;
	file = fopen("啗晝滌 衛晝.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		Eliminate(data[count], '\n');
		count++;
	}
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛       晝罹 褻��        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" %s椒曖 檜廓 殖 晝罹 :  \n", now.name);
	switch (now.rank) {
	case 1:
		printf(" %d\   \n", now.hours * atoi(data[1]));
		break;
	case 2:
		printf(" %d\   \n", now.hours * atoi(data[2]));
		break;
	case 3:
		printf(" %d\   \n", now.hours * atoi(data[3]));
		break;
	case 4:
		printf(" %d\   \n", now.hours * atoi(data[4]));
		break;
	}
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 1. 斬鼠衛除 蹺陛       弛\n");
	printf("弛 2. 菴煎陛晦            弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		add_hours(); // 斬鼠衛除 蹺陛 �飛�
		break;
	case 2:
		info_menu(); // 薑爾 褻�� 詭景
		break;
	default:
		check_salary(); // 檜廓 殖 晝罹 褻��
		break;
	}
}
void delete_ID() {
	FILE* file;
	char data[100][300];
	int count = 0;
	int i, j, nResult;
	char* user_file_name = malloc(sizeof(char) * 50);
	strcpy(user_file_name, now.name);
	strcat(user_file_name, "曖 薑爾だ橾.txt");
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛       �蛾� 驍黴        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛         輿  曖         弛\n");
	printf("弛 �蛾衋� 驍黴ж啪 腆 衛  弛\n");
	printf("弛 犒掘й 熱 橈蝗棲棻.    弛\n");
	printf("弛 1. �蛾� 驍黴           弛\n");
	printf("弛 2. 鏃模                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		nResult = remove(user_file_name);

		if (nResult == 0)
		{
			printf("だ橾 餉薯 撩奢");
		}
		else if (nResult == -1)
		{
			perror("だ橾 餉薯 褒ぬ");
		}
		file = fopen("login.txt", "r");
		while (1)
		{
			fgets(data[count], sizeof(data), file);
			if (feof(file)) break;
			count++;
		}
		fclose(file);
		for (i = 0; i < count; i++)
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(data[i], now.ID) != NULL)
				{
					j = i;
				}
			}
		}
		file = fopen("login.txt", "w");
		for (i = 0; i < count; i++)
		{
			if (i != j && i != j + 1 && i != j + 2) {
				fprintf(file, "%s", data[i]);
			}
		}
		fclose(file);
		system("cls");
		printf("\n\n   撩奢瞳戲煎 餉薯腎歷蝗棲棻.");
		Sleep(2000);

		start(); // 薑爾 褻�� 詭景
		break;
	case 2:
		info_menu(); // 薑爾 褻�� 詭景
		break;
	default:
		delete_ID(); // �蛾躠酷�
		break;
	}
}
void manage_salary() {
	FILE* file;
	int change_rank = 0;
	char change_salary[10];
	char data[100][300];
	int count = 0;
	file = fopen("啗晝滌 衛晝.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		Eliminate(data[count], '\n');
		count++;
	}
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛        衛晝婦葬        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" (1) 餌錳曖 衛晝 : %s錳\n", data[1]);
	printf(" (2) 渠葬曖 衛晝 : %s錳\n", data[2]);
	printf(" (3) 睡濰曖 衛晝 : %s錳\n", data[3]);
	printf(" (4) 餌濰曖 衛晝 : %s錳\n", data[4]);
	printf(" 夥羚 啗晝 : ");
	scanf("%d", &change_rank);
	printf(" 夥羚 衛晝 : ");
	scanf("%s", &change_salary);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 1. 衛晝 滲唳 �挫�      弛\n");
	printf("弛 2. 衛晝 滲唳 鏃模      弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		file = fopen("啗晝滌 衛晝.txt", "w");
		for (int i = 0; i < count; i++) {
			if (i != change_rank) {
				fprintf(file, "%s\n", data[i]);
			}
			else if (i = change_rank) {
				fprintf(file, "%s\n", change_salary);
			}
		}
		system("cls");
		printf("\n\n   撩奢瞳戲煎 滲唳腎歷蝗棲棻!");
		Sleep(2000);
		fclose(file);
		main_screen(); // 煎斜檣 �� 詭檣�飛�
		break;
	case 2:
		main_screen(); // 煎斜檣 �� 詭檣�飛�
		break;
	default:
		system("cls");
		printf("\n\n   滲唳縑 褒ぬж艘蝗棲棻! (澀跤脹 殮溘)");
		Sleep(2000);
		manage_salary(); // 晝罹婦葬 �飛�
		break;
	}

}
void permission_ID() {
	FILE* file;
	char login_data[100][300];
	char info_data[100][300];
	char ID[100] = { NULL };
	char name[100] = { NULL };
	int count = 0;
	int check = 0;
	int i, j = 0;
	file = fopen("login.txt", "r");
	while (1)
	{
		fgets(login_data[count], sizeof(login_data), file);
		if (feof(file)) break;
		Eliminate(login_data[count], '\n');
		count++;
	}
	fclose(file);
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛      �蛾灠㊣埣臍�      弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛 1. ID煎 褻��           弛\n");
	printf("弛 2. 檜葷戲煎 褻��       弛\n");
	printf("弛 3. 菴煎陛晦            弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		printf(" ID擊 殮溘ж撮蹂. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 匐餌
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(login_data[i], ID) != NULL)
				{
					check = 1;
					j = i;
				}
			}
		}
		if (check == 0)
		{
			system("cls");
			printf("\n\n   襄營ж雖 彊朝 ID殮棲棻.");
			Sleep(2000);
			permission_ID(); // �蛾灠㊣� 蝓檣
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "曖 薑爾だ橾.txt");
		file = fopen(user_file_name, "r");
		while (1)
		{
			fgets(info_data[count], sizeof(info_data), file);
			if (feof(file)) break;
			Eliminate(info_data[count], '\n');
			count++;
		}
		if (atoi(info_data[3]) >= 1) {
			system("cls");
			printf("\n\n   檜嘐 蝓檣脹 �蛾衋埭炴�.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
		}
		fclose(file);
		system("cls");
		printf("\n\n   %s模樓\n\n   %s椒 檣衝腎歷蝗棲棻.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛 1. �蛾灠㊣� 蝓檣       弛\n");
		printf("弛 2. �蛾灠㊣� 剪睡       弛\n");
		printf("弛 3. 菴煎陛晦            弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf(" 殮溘 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			file = fopen(user_file_name, "w");
			fprintf(file, "%s\n", info_data[0]);
			fprintf(file, "%s\n", info_data[1]);
			fprintf(file, "%s\n", info_data[2]);
			fprintf(file, "1\n");
			fprintf(file, "%s\n", info_data[4]);
			fclose(file);
			system("cls");
			printf("\n\n   撩奢瞳戲煎 蝓檣腎歷蝗棲棻.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		case 2:
			file = fopen("login.txt", "w");
			for (i = 0; i < count; i++)
			{
				if (i != j - 2 && i != j - 1 && i != j) {
					fprintf(file, "%s\n", login_data[i]);
				}
			}
			fclose(file);
			system("cls");
			printf("\n\n   撩奢瞳戲煎 剪睡腎歷蝗棲棻.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		case 3:
			permission_ID(); // �蛾灠㊣� 蝓檣
			break;
		default:
			system("cls");
			printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
			permission_ID(); // �蛾灠㊣� 蝓檣
			break;
		}
		break;
	case 2:
		printf(" 檜葷擊 殮溘ж撮蹂. : ");
		scanf("%s", name);
		for (i = 0; i < count; i++) // ID 匐餌
		{
			if (i == 2 || i % 3 == 2)
			{
				if (strstr(login_data[i], name) != NULL)
				{
					check = 1;
					j = i;
				}
			}
		}
		if (check == 0)
		{
			system("cls");
			printf("\n\n   襄營ж雖 彊朝 檜葷殮棲棻.");
			Sleep(2000);
			permission_ID(); // �蛾灠㊣� 蝓檣
		}
		count = 0;
		char* user_file_name2 = malloc(sizeof(char) * 50);
		strcpy(user_file_name2, login_data[j - 2]);
		strcat(user_file_name2, "曖 薑爾だ橾.txt");
		file = fopen(user_file_name2, "r");
		while (1)
		{
			fgets(info_data[count], sizeof(info_data), file);
			if (feof(file)) break;
			Eliminate(info_data[count], '\n');
			count++;
		}
		fclose(file);
		if (atoi(info_data[3]) >= 1) {
			system("cls");
			printf("\n\n   檜嘐 蝓檣脹 �蛾衋埭炴�.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
		}
		system("cls");
		printf("\n\n   %s模樓\n\n   %s椒 檣衝腎歷蝗棲棻.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛 1. �蛾灠㊣� 蝓檣       弛\n");
		printf("弛 2. �蛾灠㊣� 剪睡       弛\n");
		printf("弛 3. 菴煎陛晦            弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf(" 殮溘 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			file = fopen(user_file_name2, "w");
			fprintf(file, "%s\n", info_data[0]);
			fprintf(file, "%s\n", info_data[1]);
			fprintf(file, "%s\n", info_data[2]);
			fprintf(file, "1\n");
			fprintf(file, "%s\n", info_data[4]);
			fclose(file);
			system("cls");
			printf("\n\n   撩奢瞳戲煎 蝓檣腎歷蝗棲棻.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		case 2:
			file = fopen("login.txt", "w");
			for (i = 0; i < count; i++)
			{
				if (i != j - 2 && i != j - 1 && i != j) {
					fprintf(file, "%s\n", login_data[i]);
				}
			}
			fclose(file);
			system("cls");
			printf("\n\n   撩奢瞳戲煎 剪睡腎歷蝗棲棻.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		case 3:
			permission_ID(); // �蛾灠㊣� 蝓檣
			break;
		default:
			system("cls");
			printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
			permission_ID(); // �蛾灠㊣� 蝓檣
			break;
		}
		break;
	case 3:
		system("cls");
		printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
		other_info_menu(); // 餌錳薑爾 褻�� 詭景
		break;
	default:
		other_info_menu(); // 餌錳薑爾 褻�� 詭景
		break;
	}
}
void check_other_info() {
	FILE* file;
	char login_data[100][300];
	char info_data[100][300];
	char ID[100] = { NULL };
	char name[100] = { NULL };
	int count = 0;
	int check = 0;
	int i, j = 0;
	file = fopen("login.txt", "r");
	while (1)
	{
		fgets(login_data[count], sizeof(login_data), file);
		if (feof(file)) break;
		Eliminate(login_data[count], '\n');
		count++;
	}
	fclose(file);
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛      餌錳薑爾褻��      弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛 1. ID煎 褻��           弛\n");
	printf("弛 2. 檜葷戲煎 褻��       弛\n");
	printf("弛 3. 菴煎陛晦            弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		printf(" ID擊 殮溘ж撮蹂. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 匐餌
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(login_data[i], ID) != NULL)
				{
					check = 1;
					j = i;
				}
			}
		}
		if (check == 0)
		{
			system("cls");
			printf("\n\n   襄營ж雖 彊朝 ID殮棲棻.");
			Sleep(2000);
			check_other_info(); // 餌錳薑爾 �挫�
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "曖 薑爾だ橾.txt");
		file = fopen(user_file_name, "r");
		while (1)
		{
			fgets(info_data[count], sizeof(info_data), file);
			if (feof(file)) break;
			Eliminate(info_data[count], '\n');
			count++;
		}
		fclose(file);
		if (atoi(info_data[3]) > now.rank) {
			system("cls");
			printf("\n\n   獄檣爾棻 堪擎 霜晝擎 褻�裔� 熱 橈蝗棲棻.");
			Sleep(2000);
			check_other_info();
		}
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛      餌錳薑爾褻��      弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("ID : %s\n", login_data[j]);
		printf("PW : %s\n", login_data[j + 1]);
		printf("檜葷 : %s\n", info_data[0]);
		printf("釭檜 : %s\n", info_data[1]);
		printf("模樓 : %s\n", info_data[2]);
		if (atoi(info_data[3]) == 1) {
			printf("霜晝 : 餌錳\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("霜晝 : 渠葬\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("霜晝 : 睡濰\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("霜晝 : 餌濰\n");
		}
		printf("斬鼠衛除 : %s\n", info_data[4]);
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛 1. 菴煎陛晦            弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf(" 殮溘 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		default:
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		}
		break;
	case 2:
		printf(" 檜葷擊 殮溘ж撮蹂. : ");
		scanf("%s", name);
		for (i = 0; i < count; i++) // ID 匐餌
		{
			if (i == 2 || i % 3 == 2)
			{
				if (strstr(login_data[i], name) != NULL)
				{
					check = 1;
					j = i;
				}
			}
		}
		if (check == 0)
		{
			system("cls");
			printf("\n\n   襄營ж雖 彊朝 檜葷殮棲棻.");
			Sleep(2000);
			check_other_info(); // 餌錳薑爾 �挫�
		}
		count = 0;
		char* user_file_name3 = malloc(sizeof(char) * 50);
		strcpy(user_file_name3, login_data[j - 2]);
		strcat(user_file_name3, "曖 薑爾だ橾.txt");
		file = fopen(user_file_name3, "r");
		while (1)
		{
			fgets(info_data[count], sizeof(info_data), file);
			if (feof(file)) break;
			Eliminate(info_data[count], '\n');
			count++;
		}
		fclose(file);
		if (atoi(info_data[3]) > now.rank) {
			system("cls");
			printf("\n\n   獄檣爾棻 堪擎 霜晝擎 褻�裔� 熱 橈蝗棲棻.");
			Sleep(2000);
			check_other_info();
		}
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛      餌錳薑爾褻��      弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("ID : %s\n", login_data[j - 2]);
		printf("PW : %s\n", login_data[j - 1]);
		printf("檜葷 : %s\n", info_data[0]);
		printf("釭檜 : %s\n", info_data[1]);
		printf("模樓 : %s\n", info_data[2]);
		if (atoi(info_data[3]) == 1) {
			printf("霜晝 : 餌錳\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("霜晝 : 渠葬\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("霜晝 : 睡濰\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("霜晝 : 餌濰\n");
		}
		printf("斬鼠衛除 : %s\n", info_data[4]);
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛 1. 菴煎陛晦            弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf(" 殮溘 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		default:
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		}
		break;
	case 3:
		system("cls");
		printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
		other_info_menu(); // 餌錳薑爾 褻�� 詭景
		break;
	default:
		other_info_menu(); // 餌錳薑爾 褻�� 詭景
		break;
	}
}
void manage_rank() {
	FILE* file;
	char login_data[100][300];
	char info_data[100][300];
	char ID[100] = { NULL };
	char name[100] = { NULL };
	int count = 0;
	int check = 0;
	int i, j = 0;
	file = fopen("login.txt", "r");
	while (1)
	{
		fgets(login_data[count], sizeof(login_data), file);
		if (feof(file)) break;
		Eliminate(login_data[count], '\n');
		count++;
	}




	fclose(file);
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛     餌錳 霜晝 婦葬     弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛 1. ID煎 褻��           弛\n");
	printf("弛 2. 檜葷戲煎 褻��       弛\n");
	printf("弛 3. 菴煎陛晦            弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {



	case 1:
		printf(" ID擊 殮溘ж撮蹂. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 匐餌
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(login_data[i], ID) != NULL)
				{
					check = 1;
					j = i;
				}
			}
		}
		if (check == 0)
		{
			system("cls");
			printf("\n\n   襄營ж雖 彊朝 ID殮棲棻.");
			Sleep(2000);
			manage_rank(); // 餌錳霜晝 婦葬
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "曖 薑爾だ橾.txt");
		file = fopen(user_file_name, "r");
		while (1)
		{
			fgets(info_data[count], sizeof(info_data), file);
			if (feof(file)) break;
			Eliminate(info_data[count], '\n');
			count++;
		}
		fclose(file);
		if (atoi(info_data[3]) > now.rank) {
			system("cls");
			printf("\n\n   獄檣爾棻 堪擎 霜晝擎 婦葬й 熱 橈蝗棲棻.");
			Sleep(2000);
			manage_rank(); // 餌錳霜晝 婦葬
		}
		system("cls");
		printf("\n\n   %s模樓\n\n   %s椒 檣衝腎歷蝗棲棻.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛     餌錳 霜晝 婦葬     弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
		printf("弛 獄檣 霜晝 檜鼻戲煎朝   弛\n");
		printf("弛 滲唳檜 碳陛棟м棲棻.   弛\n");
		printf("弛 (1) 餌錳               弛\n");
		printf("弛 (2) 渠葬               弛\n");
		printf("弛 (3) 睡濰               弛\n");
		printf("弛 (4) 餌濰               弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		if (atoi(info_data[3]) == 1) {
			printf("⑷營霜晝 : 餌錳\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("⑷營霜晝 : 渠葬\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("⑷營霜晝 : 睡濰\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("⑷營霜晝 : 餌濰\n");
		}
		printf("夥羚霜晝 : ");
		scanf("%s", info_data[3]);
		if (atoi(info_data[3]) >= now.rank) {
			system("cls");
			printf("\n\n   п渡 霜晝 滲唳 碳陛棟殮棲棻.");
			Sleep(2000);
			manage_rank(); // 餌錳霜晝 婦葬
		}
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛 1. 霜晝 滲唳           弛\n");
		printf("弛 2. 滲唳 鏃模           弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf(" 殮溘 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			file = fopen(user_file_name, "w");
			fprintf(file, "%s\n", info_data[0]);
			fprintf(file, "%s\n", info_data[1]);
			fprintf(file, "%s\n", info_data[2]);
			fprintf(file, "%d\n", atoi(info_data[3]));
			fprintf(file, "%s\n", info_data[4]);
			fclose(file);
			system("cls");
			printf("\n\n   撩奢瞳戲煎 滲唳腎歷蝗棲棻.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		case 2:
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		default:
			system("cls");
			printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
			manage_rank(); // 餌錳霜晝 婦葬
			break;
		}
		break;




	case 2:
		printf(" 檜葷擊 殮溘ж撮蹂. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 匐餌
		{
			if (i == 2 || i % 3 == 2)
			{
				if (strstr(login_data[i], name) != NULL)
				{
					check = 1;
					j = i;
				}
			}
		}
		if (check == 0)
		{
			system("cls");
			printf("\n\n   襄營ж雖 彊朝 ID殮棲棻.");
			Sleep(2000);
			manage_rank(); // 餌錳霜晝 婦葬
		}
		count = 0;
		char* user_file_name4 = malloc(sizeof(char) * 50);
		strcpy(user_file_name4, login_data[j - 2]);
		strcat(user_file_name4, "曖 薑爾だ橾.txt");
		file = fopen(user_file_name4, "r");
		while (1)
		{
			fgets(info_data[count], sizeof(info_data), file);
			if (feof(file)) break;
			Eliminate(info_data[count], '\n');
			count++;
		}
		fclose(file);
		if (atoi(info_data[3]) > now.rank) {
			system("cls");
			printf("\n\n   獄檣爾棻 堪擎 霜晝擎 婦葬й 熱 橈蝗棲棻.");
			Sleep(2000);
			manage_rank(); // 餌錳霜晝 婦葬
		}
		system("cls");
		printf("\n\n   %s模樓\n\n   %s椒 檣衝腎歷蝗棲棻.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛     餌錳 霜晝 婦葬     弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
		printf("弛 獄檣 霜晝 檜鼻戲煎朝   弛\n");
		printf("弛 滲唳檜 碳陛棟м棲棻.   弛\n");
		printf("弛 (1) 餌錳               弛\n");
		printf("弛 (2) 渠葬               弛\n");
		printf("弛 (3) 睡濰               弛\n");
		printf("弛 (4) 餌濰               弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		if (atoi(info_data[3]) == 1) {
			printf("⑷營霜晝 : 餌錳\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("⑷營霜晝 : 渠葬\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("⑷營霜晝 : 睡濰\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("⑷營霜晝 : 餌濰\n");
		}
		printf("夥羚霜晝 : ");
		scanf("%s", info_data[3]);
		if (atoi(info_data[3]) >= now.rank) {
			system("cls");
			printf("\n\n   п渡 霜晝 滲唳 碳陛棟殮棲棻.");
			Sleep(2000);
			manage_rank(); // 餌錳霜晝 婦葬
		}
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛 1. 霜晝 滲唳           弛\n");
		printf("弛 2. 滲唳 鏃模           弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf(" 殮溘 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			file = fopen(user_file_name4, "w");
			fprintf(file, "%s\n", info_data[0]);
			fprintf(file, "%s\n", info_data[1]);
			fprintf(file, "%s\n", info_data[2]);
			fprintf(file, "%d\n", atoi(info_data[3]));
			fprintf(file, "%s\n", info_data[4]);
			fclose(file);
			system("cls");
			printf("\n\n   撩奢瞳戲煎 滲唳腎歷蝗棲棻.");
			Sleep(2000);
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		case 2:
			other_info_menu(); // 餌錳薑爾 褻�� 詭景
			break;
		default:
			system("cls");
			printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
			manage_rank(); // 餌錳霜晝 婦葬
			break;
		}
		break;



	case 3:
		other_info_menu(); // 餌錳薑爾 褻�� 詭景
		break;



	default:
		system("cls");
		printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
		Sleep(2000);
		other_info_menu(); // 餌錳薑爾 褻�� 詭景
		break;
	}
}
void change_info() {

	info join = { {NULL},{NULL},{NULL},{NULL},0,0,0 };
	FILE* file = NULL;
	int join_confirm = 0;
	int count = 0;
	char data[100][300];

	file = fopen("login.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		count++;
	}
	fclose(file);

	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛    偃檣薑爾熱薑        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("檜葷 : ");
	scanf("%s", join.name);
	printf("釭檜 : ");
	scanf("%d", &join.age);
	printf("模樓 : ");
	scanf("%s", join.belong);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 1. 熱薑鏃模            弛\n");
	printf("弛 2. 營殮溘              弛\n");
	printf("弛 3. 諫猿                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	printf(" 殮溘 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		cheak_info(); // 薑爾 褻�� �飛�
		break;
	case 2:
		change_info(); // 偃檣薑爾 熱薑
		break;
	case 3:
		;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, now.ID);
		strcat(user_file_name, "曖 薑爾だ橾.txt");

		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("だ橾 螃盟!");
			exit(1);
		}
		fprintf(file, "%s\n", join.name);
		fprintf(file, "%d\n", join.age);
		fprintf(file, "%s\n", join.belong);
		fprintf(file, "%d\n", now.rank);
		fprintf(file, "%d\n", now.hours);
		fclose(file);

		printf("\n--- 薑爾熱薑檜 諫猿腎歷蝗棲棻.---- \n");
		Sleep(1000);
		printf("--- 營 煎斜檣 夥奧棲棻.---- \n\n");
		Sleep(1000);
		login(); // 薑爾 褻�� �飛�
		break;
	default:
		system("cls");
		printf("\n\n   澀跤脹 詭景 殮溘殮棲棻.");
		cheak_info(); // 薑爾 褻�� �飛�
		break;
	}
}


void Eliminate(char* str, char ch)
{
	for (; *str != '\0'; str++)//謙猿 僥濠蒂 虜陳 陽梱雖 奩犒
	{
		if (*str == ch)//ch諦 偽擎 僥濠橾 陽
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}