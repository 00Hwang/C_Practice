#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct {
	char ID[20]; // ���̵�
	char PW[20]; // ��й�ȣ
	char name[50]; // �̸�
	char belong[50]; // �Ҽ�
	int rank; // ����
	int age; // ����
	int hours; // �� �ٹ� �ð�
}info; // ��� ����
info now = { {NULL},{NULL},{NULL},{NULL},0,0,0 };

int menu = 0; // �޴� �Է� �޴� ����
void Eliminate(char* str, char ch);
void create_txt(); // ������ ������ ����
void start(); // ���α׷� ���� ȭ��
void sigh_up(); // ȸ������ ȭ��
void login(); // �α��� ȭ��
void main_screen(); // �α��� �� ����ȭ��
void info_menu(); // ���� ��ȸ �޴�
void cheak_info(); // ���� ��ȸ ȭ��
void other_info_menu(); // ������� ��ȸ �޴�
void add_hours(); // �ٹ��ð� �߰� ȭ��
void change_PW(); // ��й�ȣ ����
void check_salary(); // �̹� �� �޿� ��ȸ
void delete_ID(); // ȸ��Ż��
void manage_salary(); // �޿����� ȭ��
void permission_ID(); // ȸ������ ����
void check_other_info(); // ������� Ȯ��
void manage_rank(); // ������� ����
void change_info(); // �������� ����


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
			printf("���� ����!");
			exit(1);
		}
		fprintf(file, "admin\n");
		fprintf(file, "admin\n");
		fprintf(file, "admin\n");
		fclose(file);
		file = fopen("admin�� ��������.txt", "w");
		fprintf(file, "������\n");
		fprintf(file, "9999\n");
		fprintf(file, "������\n");
		fprintf(file, "9999\n");
		fprintf(file, "0\n");
		fclose(file);
		file = fopen("��޺� �ñ�.txt", "w");
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
	printf("����������������������������������������������������\n");
	printf("��  ȸ��� ���� ���α׷�  ��\n");
	printf("����������������������������������������������������\n");
	printf("�� 1. ȸ������            ��\n");
	printf("�� 2. �α���              ��\n");
	printf("�� 3. ����                ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		sigh_up(); // ȸ������ ȭ��
		break;
	case 2:
		login(); // �α��� ȭ��
		break;
	case 3:
		exit(1); // ����
		break;
	default:
		start(); // ���α׷� ���� ȭ��
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
	printf("����������������������������������������������������\n");
	printf("��        ȸ������        ��\n");
	printf("����������������������������������������������������\n");
	printf("ID : "); // ȸ������ ���� ���� ����
	scanf("%s", join.ID);
	printf("PW : ");
	scanf("%s", join.PW);
	printf("�̸� : ");
	scanf("%s", join.name);
	printf("���� : ");
	scanf("%d", &join.age);
	printf("�Ҽ� : ");
	scanf("%s", join.belong);
	printf("����������������������������������������������������\n");
	printf("�� 1. ȸ���������        ��\n");
	printf("�� 2. ���Է�              ��\n");
	printf("�� 3. �Ϸ�                ��\n");
	printf("����������������������������������������������������\n");

	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		start(); // ���α׷� ���� ȭ��
		break;
	case 2:
		sigh_up(); // ȸ������ ȭ��
		break;
	case 3:
		for (int i = 0; i < count; i++)
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(data[i], join.ID) != NULL)
				{
					printf("---- ���̵� �ߺ��˴ϴ�. ���Է� �ٶ��ϴ�.---- \n\n");
					Sleep(1000);
					sigh_up();
				}
			}
		}

		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, join.ID);
		strcat(user_file_name, "�� ��������.txt");

		file = fopen("login.txt", "a");
		if (file == NULL) {
			printf("���� ����!");
			exit(1);
		}
		fprintf(file, "%s\n", join.ID);
		fprintf(file, "%s\n", join.PW);
		fprintf(file, "%s\n", join.name);
		fclose(file);
		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("���� ����!");
			exit(1);
		}
		fprintf(file, "%s\n", join.name);
		fprintf(file, "%d\n", join.age);
		fprintf(file, "%s\n", join.belong);
		fprintf(file, "%d\n", join.rank);
		fprintf(file, "%d\n", join.hours);
		fclose(file);

		printf("---- ���Խ�û�� �Ϸ�Ǿ����ϴ�.---- \n\n");
		Sleep(1000);
		start(); // ���α׷� ���� ȭ��
		break;
	default:
		start(); // ���α׷� ���� ȭ��
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
	printf("����������������������������������������������������\n");
	printf("��        �α���          ��\n");
	printf("����������������������������������������������������\n");
	printf("ID : ");
	scanf("%s", enter.ID);
	printf("PW : ");
	scanf("%s", enter.PW);
	for (i = 0; i < count; i++) // ID �˻�
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
		printf("ID�� Ʋ�Ƚ��ϴ�.");
		Sleep(1000);
		start();
	}
	check = 0;
	for (i = 0; i < count; i++) // PW �˻�
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
		printf("PW�� Ʋ�Ƚ��ϴ�.");
		Sleep(1000);
		start();
	}

	char* user_file_name = malloc(sizeof(char) * 50);
	strcpy(user_file_name, data[j - 1]);
	strcat(user_file_name, "�� ��������.txt");
	Eliminate(user_file_name, '\n');
	file = fopen(user_file_name, "r"); // �α����� ID�� ���� ���� ����
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
		printf("\n\n   ���� ���� ���� ȸ���Դϴ�.");
		Sleep(2000);
		start(); // ����ȭ��
	}

	system("cls");
	printf("\n\n     �α��ο� �����߽��ϴ�!");
	Sleep(1000);
	system("cls");
	printf("\n\n     �α��ο� �����߽��ϴ�!\n            %s", data[j + 1]);
	Sleep(1000);
	system("cls");
	printf("\n\n     �α��ο� �����߽��ϴ�!\n            %s        �� ȯ���մϴ�!\n\n", data[j + 1]);
	Sleep(1000);
	main_screen();
}
void main_screen()
{
	system("cls");
	printf("����������������������������������������������������\n");
	printf("��        ����ȭ��        ��\n");
	printf("����������������������������������������������������\n");
	printf("�� 1. �ٹ��ð� �߰�       ��\n");
	printf("�� 2. �������� ��ȸ       ��\n");
	printf("�� 3. ������� ��ȸ       ��\n");
	printf("�� 4. �޿� ����           ��\n");
	printf("�� 5. �α׾ƿ�            ��\n");
	printf("�� 6. ����                ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		add_hours();
		break;
	case 2:
		info_menu(); // ���� ��ȸ �޴�
		break;
	case 3:
		if (now.rank >= 3) {
			other_info_menu(); // ������� ��ȸ �޴�
		}
		else {
			system("cls");
			printf("\n\n   '����'���� �̻� �̿� �����մϴ�.");
			Sleep(2000);
			main_screen(); // �α��� �� ����ȭ��
		}
		break;
	case 4:
		if (now.rank >= 4) {
			manage_salary(); // �޿����� ȭ��
		}
		else {
			system("cls");
			printf("\n\n   '����'���� �̻� �̿� �����մϴ�.");
			Sleep(2000);
			main_screen(); // �α��� �� ����ȭ��
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
	printf("����������������������������������������������������\n");
	printf("��      ������ȸ�޴�      ��\n");
	printf("����������������������������������������������������\n");
	printf("�� 1. �������� ��ȸ       ��\n");
	printf("�� 2. �̹� �� �޿� ��ȸ   ��\n");
	printf("�� 3. ��й�ȣ ����       ��\n");
	printf("�� 4. ȸ�� Ż��           ��\n");
	printf("�� 5. �ڷΰ���            ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		cheak_info(); // ���� ��ȸ ȭ��
		break;
	case 2:
		check_salary(); // �̹� �� �޿� ��ȸ
		break;
	case 3:
		change_PW();
		break;
	case 4:
		delete_ID();
		break;
	case 5:
		main_screen(); // �α��� �� ����ȭ��
		break;
	default:
		info_menu(); // ���� ��ȸ �޴�
		break;
	}
}
void cheak_info()
{
	system("cls");
	printf("����������������������������������������������������\n");
	printf("��      ����������ȸ      ��\n");
	printf("����������������������������������������������������\n");
	printf("�̸� : %s\n", now.name); // ȸ������ ���� ���� ����
	printf("���� : %d\n", now.age);
	printf("�Ҽ� : %s\n", now.belong);
	if (now.rank == 1) {
		printf("���� : ���\n");
	}
	else if (now.rank == 2) {
		printf("���� : �븮\n");
	}
	else if (now.rank == 3) {
		printf("���� : ����\n");
	}
	else if (now.rank == 4) {
		printf("���� : ����\n");
	}
	printf("�ٹ��ð� : %d\n", now.hours);
	printf("����������������������������������������������������\n");
	printf("�� 1. ������������        ��\n");
	printf("�� 2. �ڷΰ���            ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		change_info(); // �������� ����
		break;
	case 2:
		info_menu(); // ���� ��ȸ �޴�
		break;
	default:
		cheak_info(); // ���� ��ȸ ȭ��
		break;
	}
}
void other_info_menu()
{
	system("cls");
	printf("����������������������������������������������������\n");
	printf("��    ���������ȸ�޴�    ��\n");
	printf("����������������������������������������������������\n");
	printf("�� 1. ������� ��ȸ       ��\n");
	printf("�� 2. ȸ������ ����       ��\n");
	printf("�� 3. ��� ���� ����      ��\n");
	printf("�� 4. �ڷΰ���            ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		check_other_info(); // ������� Ȯ��
		break;
	case 2:
		permission_ID(); // ȸ������ ����
		break;
	case 3:
		manage_rank(); // ������� ����
		break;
	case 4:
		main_screen(); // �α��� �� ����ȭ��
		break;
	default:
		other_info_menu(); // ������� ��ȸ �޴�
		break;
	}
}
void add_hours() {
	int time;
	system("cls");
	printf("����������������������������������������������������\n");
	printf("��        �ð��Է�        ��\n");
	printf("����������������������������������������������������\n");
	printf("�ٹ� �ð� �Է�(���� : ��) : ");
	scanf("%d", &time);
	printf("����������������������������������������������������\n");
	printf("�� 1. �ð��Է� Ȯ��       ��\n");
	printf("�� 2. �ð��Է� ���       ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
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
		strcat(user_file_name, "�� ��������.txt");

		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("���� ����!");
			exit(1);
		}
		fprintf(file, "%s\n", now.name);
		fprintf(file, "%d\n", now.age);
		fprintf(file, "%s\n", now.belong);
		fprintf(file, "%d\n", now.rank);
		fprintf(file, "%d\n", now.hours);
		fclose(file);
		system("cls");
		printf("\n\n   �ð��� �ԷµǾ����ϴ�!\n    ���� �Էµ� �ð� : %d�ð�", now.hours);
		Sleep(3000);
		info_menu(); // ���� ��ȸ �޴�
		break;
	default:
		system("cls");
		printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
		Sleep(2000);
		add_hours(); // �ٹ��ð� �߰� ȭ��
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
	printf("����������������������������������������������������\n");
	printf("��      ��й�ȣ����      ��\n");
	printf("����������������������������������������������������\n");
	printf("������ �н����� : ");
	scanf("%s", new_PW);
	printf("����������������������������������������������������\n");
	printf("�� 1. ��й�ȣ ���� Ȯ��  ��\n");
	printf("�� 2. ��й�ȣ ���� ���  ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
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
		printf("\n\n   ���������� ����Ǿ����ϴ�.");
		Sleep(2000);
		info_menu(); // ���� ��ȸ �޴�
		break;
	case 2:
		info_menu(); // ���� ��ȸ �޴�
		break;
	default:
		system("cls");
		printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
		Sleep(2000);
		change_PW(); // ��й�ȣ ����
		break;
	}
}
void check_salary() {
	FILE* file;
	char data[100][300];
	int count = 0;
	file = fopen("��޺� �ñ�.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		Eliminate(data[count], '\n');
		count++;
	}
	system("cls");
	printf("����������������������������������������������������\n");
	printf("��       �޿� ��ȸ        ��\n");
	printf("����������������������������������������������������\n");
	printf(" %s���� �̹� �� �޿� :  \n", now.name);
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
	printf("����������������������������������������������������\n");
	printf("�� 1. �ٹ��ð� �߰�       ��\n");
	printf("�� 2. �ڷΰ���            ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		add_hours(); // �ٹ��ð� �߰� ȭ��
		break;
	case 2:
		info_menu(); // ���� ��ȸ �޴�
		break;
	default:
		check_salary(); // �̹� �� �޿� ��ȸ
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
	strcat(user_file_name, "�� ��������.txt");
	system("cls");
	printf("����������������������������������������������������\n");
	printf("��       ȸ�� Ż��        ��\n");
	printf("����������������������������������������������������\n");
	printf("��         ��  ��         ��\n");
	printf("�� ȸ���� Ż���ϰ� �� ��  ��\n");
	printf("�� ������ �� �����ϴ�.    ��\n");
	printf("�� 1. ȸ�� Ż��           ��\n");
	printf("�� 2. ���                ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		nResult = remove(user_file_name);

		if (nResult == 0)
		{
			printf("���� ���� ����");
		}
		else if (nResult == -1)
		{
			perror("���� ���� ����");
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
		printf("\n\n   ���������� �����Ǿ����ϴ�.");
		Sleep(2000);

		start(); // ���� ��ȸ �޴�
		break;
	case 2:
		info_menu(); // ���� ��ȸ �޴�
		break;
	default:
		delete_ID(); // ȸ��Ż��
		break;
	}
}
void manage_salary() {
	FILE* file;
	int change_rank = 0;
	char change_salary[10];
	char data[100][300];
	int count = 0;
	file = fopen("��޺� �ñ�.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		Eliminate(data[count], '\n');
		count++;
	}
	system("cls");
	printf("����������������������������������������������������\n");
	printf("��        �ñް���        ��\n");
	printf("����������������������������������������������������\n");
	printf(" (1) ����� �ñ� : %s��\n", data[1]);
	printf(" (2) �븮�� �ñ� : %s��\n", data[2]);
	printf(" (3) ������ �ñ� : %s��\n", data[3]);
	printf(" (4) ������ �ñ� : %s��\n", data[4]);
	printf(" �ٲ� ��� : ");
	scanf("%d", &change_rank);
	printf(" �ٲ� �ñ� : ");
	scanf("%s", &change_salary);
	printf("����������������������������������������������������\n");
	printf("�� 1. �ñ� ���� Ȯ��      ��\n");
	printf("�� 2. �ñ� ���� ���      ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		file = fopen("��޺� �ñ�.txt", "w");
		for (int i = 0; i < count; i++) {
			if (i != change_rank) {
				fprintf(file, "%s\n", data[i]);
			}
			else if (i = change_rank) {
				fprintf(file, "%s\n", change_salary);
			}
		}
		system("cls");
		printf("\n\n   ���������� ����Ǿ����ϴ�!");
		Sleep(2000);
		fclose(file);
		main_screen(); // �α��� �� ����ȭ��
		break;
	case 2:
		main_screen(); // �α��� �� ����ȭ��
		break;
	default:
		system("cls");
		printf("\n\n   ���濡 �����Ͽ����ϴ�! (�߸��� �Է�)");
		Sleep(2000);
		manage_salary(); // �޿����� ȭ��
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
	printf("����������������������������������������������������\n");
	printf("��      ȸ�����Խ���      ��\n");
	printf("����������������������������������������������������\n");
	printf("�� 1. ID�� ��ȸ           ��\n");
	printf("�� 2. �̸����� ��ȸ       ��\n");
	printf("�� 3. �ڷΰ���            ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		printf(" ID�� �Է��ϼ���. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID �˻�
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
			printf("\n\n   �������� �ʴ� ID�Դϴ�.");
			Sleep(2000);
			permission_ID(); // ȸ������ ����
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "�� ��������.txt");
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
			printf("\n\n   �̹� ���ε� ȸ���Դϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
		}
		fclose(file);
		system("cls");
		printf("\n\n   %s�Ҽ�\n\n   %s�� �νĵǾ����ϴ�.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("����������������������������������������������������\n");
		printf("�� 1. ȸ������ ����       ��\n");
		printf("�� 2. ȸ������ �ź�       ��\n");
		printf("�� 3. �ڷΰ���            ��\n");
		printf("����������������������������������������������������\n");
		printf(" �Է� : ");
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
			printf("\n\n   ���������� ���εǾ����ϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
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
			printf("\n\n   ���������� �źεǾ����ϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		case 3:
			permission_ID(); // ȸ������ ����
			break;
		default:
			system("cls");
			printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
			permission_ID(); // ȸ������ ����
			break;
		}
		break;
	case 2:
		printf(" �̸��� �Է��ϼ���. : ");
		scanf("%s", name);
		for (i = 0; i < count; i++) // ID �˻�
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
			printf("\n\n   �������� �ʴ� �̸��Դϴ�.");
			Sleep(2000);
			permission_ID(); // ȸ������ ����
		}
		count = 0;
		char* user_file_name2 = malloc(sizeof(char) * 50);
		strcpy(user_file_name2, login_data[j - 2]);
		strcat(user_file_name2, "�� ��������.txt");
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
			printf("\n\n   �̹� ���ε� ȸ���Դϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
		}
		system("cls");
		printf("\n\n   %s�Ҽ�\n\n   %s�� �νĵǾ����ϴ�.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("����������������������������������������������������\n");
		printf("�� 1. ȸ������ ����       ��\n");
		printf("�� 2. ȸ������ �ź�       ��\n");
		printf("�� 3. �ڷΰ���            ��\n");
		printf("����������������������������������������������������\n");
		printf(" �Է� : ");
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
			printf("\n\n   ���������� ���εǾ����ϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
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
			printf("\n\n   ���������� �źεǾ����ϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		case 3:
			permission_ID(); // ȸ������ ����
			break;
		default:
			system("cls");
			printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
			permission_ID(); // ȸ������ ����
			break;
		}
		break;
	case 3:
		system("cls");
		printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
		other_info_menu(); // ������� ��ȸ �޴�
		break;
	default:
		other_info_menu(); // ������� ��ȸ �޴�
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
	printf("����������������������������������������������������\n");
	printf("��      ���������ȸ      ��\n");
	printf("����������������������������������������������������\n");
	printf("�� 1. ID�� ��ȸ           ��\n");
	printf("�� 2. �̸����� ��ȸ       ��\n");
	printf("�� 3. �ڷΰ���            ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		printf(" ID�� �Է��ϼ���. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID �˻�
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
			printf("\n\n   �������� �ʴ� ID�Դϴ�.");
			Sleep(2000);
			check_other_info(); // ������� Ȯ��
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "�� ��������.txt");
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
			printf("\n\n   ���κ��� ���� ������ ��ȸ�� �� �����ϴ�.");
			Sleep(2000);
			check_other_info();
		}
		system("cls");
		printf("����������������������������������������������������\n");
		printf("��      ���������ȸ      ��\n");
		printf("����������������������������������������������������\n");
		printf("ID : %s\n", login_data[j]);
		printf("PW : %s\n", login_data[j + 1]);
		printf("�̸� : %s\n", info_data[0]);
		printf("���� : %s\n", info_data[1]);
		printf("�Ҽ� : %s\n", info_data[2]);
		if (atoi(info_data[3]) == 1) {
			printf("���� : ���\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("���� : �븮\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("���� : ����\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("���� : ����\n");
		}
		printf("�ٹ��ð� : %s\n", info_data[4]);
		printf("����������������������������������������������������\n");
		printf("�� 1. �ڷΰ���            ��\n");
		printf("����������������������������������������������������\n");
		printf(" �Է� : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		default:
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		}
		break;
	case 2:
		printf(" �̸��� �Է��ϼ���. : ");
		scanf("%s", name);
		for (i = 0; i < count; i++) // ID �˻�
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
			printf("\n\n   �������� �ʴ� �̸��Դϴ�.");
			Sleep(2000);
			check_other_info(); // ������� Ȯ��
		}
		count = 0;
		char* user_file_name3 = malloc(sizeof(char) * 50);
		strcpy(user_file_name3, login_data[j - 2]);
		strcat(user_file_name3, "�� ��������.txt");
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
			printf("\n\n   ���κ��� ���� ������ ��ȸ�� �� �����ϴ�.");
			Sleep(2000);
			check_other_info();
		}
		system("cls");
		printf("����������������������������������������������������\n");
		printf("��      ���������ȸ      ��\n");
		printf("����������������������������������������������������\n");
		printf("ID : %s\n", login_data[j - 2]);
		printf("PW : %s\n", login_data[j - 1]);
		printf("�̸� : %s\n", info_data[0]);
		printf("���� : %s\n", info_data[1]);
		printf("�Ҽ� : %s\n", info_data[2]);
		if (atoi(info_data[3]) == 1) {
			printf("���� : ���\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("���� : �븮\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("���� : ����\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("���� : ����\n");
		}
		printf("�ٹ��ð� : %s\n", info_data[4]);
		printf("����������������������������������������������������\n");
		printf("�� 1. �ڷΰ���            ��\n");
		printf("����������������������������������������������������\n");
		printf(" �Է� : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		default:
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		}
		break;
	case 3:
		system("cls");
		printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
		other_info_menu(); // ������� ��ȸ �޴�
		break;
	default:
		other_info_menu(); // ������� ��ȸ �޴�
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
	printf("����������������������������������������������������\n");
	printf("��     ��� ���� ����     ��\n");
	printf("����������������������������������������������������\n");
	printf("�� 1. ID�� ��ȸ           ��\n");
	printf("�� 2. �̸����� ��ȸ       ��\n");
	printf("�� 3. �ڷΰ���            ��\n");
	printf("����������������������������������������������������\n");
	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {



	case 1:
		printf(" ID�� �Է��ϼ���. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID �˻�
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
			printf("\n\n   �������� �ʴ� ID�Դϴ�.");
			Sleep(2000);
			manage_rank(); // ������� ����
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "�� ��������.txt");
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
			printf("\n\n   ���κ��� ���� ������ ������ �� �����ϴ�.");
			Sleep(2000);
			manage_rank(); // ������� ����
		}
		system("cls");
		printf("\n\n   %s�Ҽ�\n\n   %s�� �νĵǾ����ϴ�.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("����������������������������������������������������\n");
		printf("��     ��� ���� ����     ��\n");
		printf("����������������������������������������������������\n");
		printf("�� ���� ���� �̻����δ�   ��\n");
		printf("�� ������ �Ұ����մϴ�.   ��\n");
		printf("�� (1) ���               ��\n");
		printf("�� (2) �븮               ��\n");
		printf("�� (3) ����               ��\n");
		printf("�� (4) ����               ��\n");
		printf("����������������������������������������������������\n");
		if (atoi(info_data[3]) == 1) {
			printf("�������� : ���\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("�������� : �븮\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("�������� : ����\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("�������� : ����\n");
		}
		printf("�ٲ����� : ");
		scanf("%s", info_data[3]);
		if (atoi(info_data[3]) >= now.rank) {
			system("cls");
			printf("\n\n   �ش� ���� ���� �Ұ����Դϴ�.");
			Sleep(2000);
			manage_rank(); // ������� ����
		}
		printf("����������������������������������������������������\n");
		printf("�� 1. ���� ����           ��\n");
		printf("�� 2. ���� ���           ��\n");
		printf("����������������������������������������������������\n");
		printf(" �Է� : ");
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
			printf("\n\n   ���������� ����Ǿ����ϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		case 2:
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		default:
			system("cls");
			printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
			manage_rank(); // ������� ����
			break;
		}
		break;




	case 2:
		printf(" �̸��� �Է��ϼ���. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID �˻�
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
			printf("\n\n   �������� �ʴ� ID�Դϴ�.");
			Sleep(2000);
			manage_rank(); // ������� ����
		}
		count = 0;
		char* user_file_name4 = malloc(sizeof(char) * 50);
		strcpy(user_file_name4, login_data[j - 2]);
		strcat(user_file_name4, "�� ��������.txt");
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
			printf("\n\n   ���κ��� ���� ������ ������ �� �����ϴ�.");
			Sleep(2000);
			manage_rank(); // ������� ����
		}
		system("cls");
		printf("\n\n   %s�Ҽ�\n\n   %s�� �νĵǾ����ϴ�.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("����������������������������������������������������\n");
		printf("��     ��� ���� ����     ��\n");
		printf("����������������������������������������������������\n");
		printf("�� ���� ���� �̻����δ�   ��\n");
		printf("�� ������ �Ұ����մϴ�.   ��\n");
		printf("�� (1) ���               ��\n");
		printf("�� (2) �븮               ��\n");
		printf("�� (3) ����               ��\n");
		printf("�� (4) ����               ��\n");
		printf("����������������������������������������������������\n");
		if (atoi(info_data[3]) == 1) {
			printf("�������� : ���\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("�������� : �븮\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("�������� : ����\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("�������� : ����\n");
		}
		printf("�ٲ����� : ");
		scanf("%s", info_data[3]);
		if (atoi(info_data[3]) >= now.rank) {
			system("cls");
			printf("\n\n   �ش� ���� ���� �Ұ����Դϴ�.");
			Sleep(2000);
			manage_rank(); // ������� ����
		}
		printf("����������������������������������������������������\n");
		printf("�� 1. ���� ����           ��\n");
		printf("�� 2. ���� ���           ��\n");
		printf("����������������������������������������������������\n");
		printf(" �Է� : ");
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
			printf("\n\n   ���������� ����Ǿ����ϴ�.");
			Sleep(2000);
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		case 2:
			other_info_menu(); // ������� ��ȸ �޴�
			break;
		default:
			system("cls");
			printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
			manage_rank(); // ������� ����
			break;
		}
		break;



	case 3:
		other_info_menu(); // ������� ��ȸ �޴�
		break;



	default:
		system("cls");
		printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
		Sleep(2000);
		other_info_menu(); // ������� ��ȸ �޴�
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
	printf("����������������������������������������������������\n");
	printf("��    ������������        ��\n");
	printf("����������������������������������������������������\n");
	printf("�̸� : ");
	scanf("%s", join.name);
	printf("���� : ");
	scanf("%d", &join.age);
	printf("�Ҽ� : ");
	scanf("%s", join.belong);
	printf("����������������������������������������������������\n");
	printf("�� 1. �������            ��\n");
	printf("�� 2. ���Է�              ��\n");
	printf("�� 3. �Ϸ�                ��\n");
	printf("����������������������������������������������������\n");

	printf(" �Է� : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		cheak_info(); // ���� ��ȸ ȭ��
		break;
	case 2:
		change_info(); // �������� ����
		break;
	case 3:
		;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, now.ID);
		strcat(user_file_name, "�� ��������.txt");

		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("���� ����!");
			exit(1);
		}
		fprintf(file, "%s\n", join.name);
		fprintf(file, "%d\n", join.age);
		fprintf(file, "%s\n", join.belong);
		fprintf(file, "%d\n", now.rank);
		fprintf(file, "%d\n", now.hours);
		fclose(file);

		printf("\n--- ���������� �Ϸ�Ǿ����ϴ�.---- \n");
		Sleep(1000);
		printf("--- �� �α��� �ٶ��ϴ�.---- \n\n");
		Sleep(1000);
		login(); // ���� ��ȸ ȭ��
		break;
	default:
		system("cls");
		printf("\n\n   �߸��� �޴� �Է��Դϴ�.");
		cheak_info(); // ���� ��ȸ ȭ��
		break;
	}
}


void Eliminate(char* str, char ch)
{
	for (; *str != '\0'; str++)//���� ���ڸ� ���� ������ �ݺ�
	{
		if (*str == ch)//ch�� ���� ������ ��
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}