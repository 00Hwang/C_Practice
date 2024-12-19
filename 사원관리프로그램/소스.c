#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct {
	char ID[20]; // 아이디
	char PW[20]; // 비밀번호
	char name[50]; // 이름
	char belong[50]; // 소속
	int rank; // 직급
	int age; // 나이
	int hours; // 총 근무 시간
}info; // 사원 정보
info now = { {NULL},{NULL},{NULL},{NULL},0,0,0 };

int menu = 0; // 메뉴 입력 받는 변수
void Eliminate(char* str, char ch);
void create_txt(); // 파일이 없을시 생성
void start(); // 프로그램 시작 화면
void sigh_up(); // 회원가입 화면
void login(); // 로그인 화면
void main_screen(); // 로그인 후 메인화면
void info_menu(); // 정보 조회 메뉴
void cheak_info(); // 정보 조회 화면
void other_info_menu(); // 사원정보 조회 메뉴
void add_hours(); // 근무시간 추가 화면
void change_PW(); // 비밀번호 변경
void check_salary(); // 이번 달 급여 조회
void delete_ID(); // 회원탈퇴
void manage_salary(); // 급여관리 화면
void permission_ID(); // 회원가입 승인
void check_other_info(); // 사원정보 확인
void manage_rank(); // 사원직급 관리
void change_info(); // 개인정보 수정


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
			printf("파일 오류!");
			exit(1);
		}
		fprintf(file, "admin\n");
		fprintf(file, "admin\n");
		fprintf(file, "admin\n");
		fclose(file);
		file = fopen("admin의 정보파일.txt", "w");
		fprintf(file, "관리자\n");
		fprintf(file, "9999\n");
		fprintf(file, "관리팀\n");
		fprintf(file, "9999\n");
		fprintf(file, "0\n");
		fclose(file);
		file = fopen("계급별 시급.txt", "w");
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
	printf("┌────────────────────────┐\n");
	printf("│  회사원 관리 프로그램  │\n");
	printf("├────────────────────────┤\n");
	printf("│ 1. 회원가입            │\n");
	printf("│ 2. 로그인              │\n");
	printf("│ 3. 종료                │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		sigh_up(); // 회원가입 화면
		break;
	case 2:
		login(); // 로그인 화면
		break;
	case 3:
		exit(1); // 종료
		break;
	default:
		start(); // 프로그램 시작 화면
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
	printf("┌────────────────────────┐\n");
	printf("│        회원가입        │\n");
	printf("└────────────────────────┘\n");
	printf("ID : "); // 회원가입 정보 기입 구간
	scanf("%s", join.ID);
	printf("PW : ");
	scanf("%s", join.PW);
	printf("이름 : ");
	scanf("%s", join.name);
	printf("나이 : ");
	scanf("%d", &join.age);
	printf("소속 : ");
	scanf("%s", join.belong);
	printf("┌────────────────────────┐\n");
	printf("│ 1. 회원가입취소        │\n");
	printf("│ 2. 재입력              │\n");
	printf("│ 3. 완료                │\n");
	printf("└────────────────────────┘\n");

	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		start(); // 프로그램 시작 화면
		break;
	case 2:
		sigh_up(); // 회원가입 화면
		break;
	case 3:
		for (int i = 0; i < count; i++)
		{
			if (i == 0 || i % 3 == 0)
			{
				if (strstr(data[i], join.ID) != NULL)
				{
					printf("---- 아이디가 중복됩니다. 재입력 바랍니다.---- \n\n");
					Sleep(1000);
					sigh_up();
				}
			}
		}

		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, join.ID);
		strcat(user_file_name, "의 정보파일.txt");

		file = fopen("login.txt", "a");
		if (file == NULL) {
			printf("파일 오류!");
			exit(1);
		}
		fprintf(file, "%s\n", join.ID);
		fprintf(file, "%s\n", join.PW);
		fprintf(file, "%s\n", join.name);
		fclose(file);
		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("파일 오류!");
			exit(1);
		}
		fprintf(file, "%s\n", join.name);
		fprintf(file, "%d\n", join.age);
		fprintf(file, "%s\n", join.belong);
		fprintf(file, "%d\n", join.rank);
		fprintf(file, "%d\n", join.hours);
		fclose(file);

		printf("---- 가입신청이 완료되었습니다.---- \n\n");
		Sleep(1000);
		start(); // 프로그램 시작 화면
		break;
	default:
		start(); // 프로그램 시작 화면
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
	printf("┌────────────────────────┐\n");
	printf("│        로그인          │\n");
	printf("└────────────────────────┘\n");
	printf("ID : ");
	scanf("%s", enter.ID);
	printf("PW : ");
	scanf("%s", enter.PW);
	for (i = 0; i < count; i++) // ID 검사
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
		printf("ID가 틀렸습니다.");
		Sleep(1000);
		start();
	}
	check = 0;
	for (i = 0; i < count; i++) // PW 검사
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
		printf("PW가 틀렸습니다.");
		Sleep(1000);
		start();
	}

	char* user_file_name = malloc(sizeof(char) * 50);
	strcpy(user_file_name, data[j - 1]);
	strcat(user_file_name, "의 정보파일.txt");
	Eliminate(user_file_name, '\n');
	file = fopen(user_file_name, "r"); // 로그인한 ID에 대한 정보 저장
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
		printf("\n\n   승인 받지 않은 회원입니다.");
		Sleep(2000);
		start(); // 시작화면
	}

	system("cls");
	printf("\n\n     로그인에 성공했습니다!");
	Sleep(1000);
	system("cls");
	printf("\n\n     로그인에 성공했습니다!\n            %s", data[j + 1]);
	Sleep(1000);
	system("cls");
	printf("\n\n     로그인에 성공했습니다!\n            %s        님 환영합니다!\n\n", data[j + 1]);
	Sleep(1000);
	main_screen();
}
void main_screen()
{
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│        메인화면        │\n");
	printf("├────────────────────────┤\n");
	printf("│ 1. 근무시간 추가       │\n");
	printf("│ 2. 개인정보 조회       │\n");
	printf("│ 3. 사원정보 조회       │\n");
	printf("│ 4. 급여 관리           │\n");
	printf("│ 5. 로그아웃            │\n");
	printf("│ 6. 종료                │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		add_hours();
		break;
	case 2:
		info_menu(); // 정보 조회 메뉴
		break;
	case 3:
		if (now.rank >= 3) {
			other_info_menu(); // 사원정보 조회 메뉴
		}
		else {
			system("cls");
			printf("\n\n   '부장'직급 이상만 이용 가능합니다.");
			Sleep(2000);
			main_screen(); // 로그인 후 메인화면
		}
		break;
	case 4:
		if (now.rank >= 4) {
			manage_salary(); // 급여관리 화면
		}
		else {
			system("cls");
			printf("\n\n   '사장'직급 이상만 이용 가능합니다.");
			Sleep(2000);
			main_screen(); // 로그인 후 메인화면
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
	printf("┌────────────────────────┐\n");
	printf("│      정보조회메뉴      │\n");
	printf("├────────────────────────┤\n");
	printf("│ 1. 개인정보 조회       │\n");
	printf("│ 2. 이번 달 급여 조회   │\n");
	printf("│ 3. 비밀번호 변경       │\n");
	printf("│ 4. 회원 탈퇴           │\n");
	printf("│ 5. 뒤로가기            │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		cheak_info(); // 정보 조회 화면
		break;
	case 2:
		check_salary(); // 이번 달 급여 조회
		break;
	case 3:
		change_PW();
		break;
	case 4:
		delete_ID();
		break;
	case 5:
		main_screen(); // 로그인 후 메인화면
		break;
	default:
		info_menu(); // 정보 조회 메뉴
		break;
	}
}
void cheak_info()
{
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│      개인정보조회      │\n");
	printf("└────────────────────────┘\n");
	printf("이름 : %s\n", now.name); // 회원가입 정보 기입 구간
	printf("나이 : %d\n", now.age);
	printf("소속 : %s\n", now.belong);
	if (now.rank == 1) {
		printf("직급 : 사원\n");
	}
	else if (now.rank == 2) {
		printf("직급 : 대리\n");
	}
	else if (now.rank == 3) {
		printf("직급 : 부장\n");
	}
	else if (now.rank == 4) {
		printf("직급 : 사장\n");
	}
	printf("근무시간 : %d\n", now.hours);
	printf("┌────────────────────────┐\n");
	printf("│ 1. 개인정보수정        │\n");
	printf("│ 2. 뒤로가기            │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		change_info(); // 개인정보 수정
		break;
	case 2:
		info_menu(); // 정보 조회 메뉴
		break;
	default:
		cheak_info(); // 정보 조회 화면
		break;
	}
}
void other_info_menu()
{
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│    사원정보조회메뉴    │\n");
	printf("├────────────────────────┤\n");
	printf("│ 1. 사원정보 조회       │\n");
	printf("│ 2. 회원가입 승인       │\n");
	printf("│ 3. 사원 직급 관리      │\n");
	printf("│ 4. 뒤로가기            │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		check_other_info(); // 사원정보 확인
		break;
	case 2:
		permission_ID(); // 회원가입 승인
		break;
	case 3:
		manage_rank(); // 사원직급 관리
		break;
	case 4:
		main_screen(); // 로그인 후 메인화면
		break;
	default:
		other_info_menu(); // 사원정보 조회 메뉴
		break;
	}
}
void add_hours() {
	int time;
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│        시간입력        │\n");
	printf("└────────────────────────┘\n");
	printf("근무 시간 입력(단위 : 시) : ");
	scanf("%d", &time);
	printf("┌────────────────────────┐\n");
	printf("│ 1. 시간입력 확인       │\n");
	printf("│ 2. 시간입력 취소       │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
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
		strcat(user_file_name, "의 정보파일.txt");

		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("파일 오류!");
			exit(1);
		}
		fprintf(file, "%s\n", now.name);
		fprintf(file, "%d\n", now.age);
		fprintf(file, "%s\n", now.belong);
		fprintf(file, "%d\n", now.rank);
		fprintf(file, "%d\n", now.hours);
		fclose(file);
		system("cls");
		printf("\n\n   시간이 입력되었습니다!\n    현재 입력된 시간 : %d시간", now.hours);
		Sleep(3000);
		info_menu(); // 정보 조회 메뉴
		break;
	default:
		system("cls");
		printf("\n\n   잘못된 메뉴 입력입니다.");
		Sleep(2000);
		add_hours(); // 근무시간 추가 화면
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
	printf("┌────────────────────────┐\n");
	printf("│      비밀번호변경      │\n");
	printf("└────────────────────────┘\n");
	printf("변경할 패스워드 : ");
	scanf("%s", new_PW);
	printf("┌────────────────────────┐\n");
	printf("│ 1. 비밀번호 변경 확인  │\n");
	printf("│ 2. 비밀번호 변경 취소  │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
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
		printf("\n\n   성공적으로 변경되었습니다.");
		Sleep(2000);
		info_menu(); // 정보 조회 메뉴
		break;
	case 2:
		info_menu(); // 정보 조회 메뉴
		break;
	default:
		system("cls");
		printf("\n\n   잘못된 메뉴 입력입니다.");
		Sleep(2000);
		change_PW(); // 비밀번호 변경
		break;
	}
}
void check_salary() {
	FILE* file;
	char data[100][300];
	int count = 0;
	file = fopen("계급별 시급.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		Eliminate(data[count], '\n');
		count++;
	}
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│       급여 조회        │\n");
	printf("└────────────────────────┘\n");
	printf(" %s님의 이번 달 급여 :  \n", now.name);
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
	printf("┌────────────────────────┐\n");
	printf("│ 1. 근무시간 추가       │\n");
	printf("│ 2. 뒤로가기            │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		add_hours(); // 근무시간 추가 화면
		break;
	case 2:
		info_menu(); // 정보 조회 메뉴
		break;
	default:
		check_salary(); // 이번 달 급여 조회
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
	strcat(user_file_name, "의 정보파일.txt");
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│       회원 탈퇴        │\n");
	printf("├────────────────────────┤\n");
	printf("│         주  의         │\n");
	printf("│ 회원을 탈퇴하게 될 시  │\n");
	printf("│ 복구할 수 없습니다.    │\n");
	printf("│ 1. 회원 탈퇴           │\n");
	printf("│ 2. 취소                │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		nResult = remove(user_file_name);

		if (nResult == 0)
		{
			printf("파일 삭제 성공");
		}
		else if (nResult == -1)
		{
			perror("파일 삭제 실패");
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
		printf("\n\n   성공적으로 삭제되었습니다.");
		Sleep(2000);

		start(); // 정보 조회 메뉴
		break;
	case 2:
		info_menu(); // 정보 조회 메뉴
		break;
	default:
		delete_ID(); // 회원탈퇴
		break;
	}
}
void manage_salary() {
	FILE* file;
	int change_rank = 0;
	char change_salary[10];
	char data[100][300];
	int count = 0;
	file = fopen("계급별 시급.txt", "r");
	while (1)
	{
		fgets(data[count], sizeof(data), file);
		if (feof(file)) break;
		Eliminate(data[count], '\n');
		count++;
	}
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│        시급관리        │\n");
	printf("└────────────────────────┘\n");
	printf(" (1) 사원의 시급 : %s원\n", data[1]);
	printf(" (2) 대리의 시급 : %s원\n", data[2]);
	printf(" (3) 부장의 시급 : %s원\n", data[3]);
	printf(" (4) 사장의 시급 : %s원\n", data[4]);
	printf(" 바꿀 계급 : ");
	scanf("%d", &change_rank);
	printf(" 바꿀 시급 : ");
	scanf("%s", &change_salary);
	printf("┌────────────────────────┐\n");
	printf("│ 1. 시급 변경 확인      │\n");
	printf("│ 2. 시급 변경 취소      │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		file = fopen("계급별 시급.txt", "w");
		for (int i = 0; i < count; i++) {
			if (i != change_rank) {
				fprintf(file, "%s\n", data[i]);
			}
			else if (i = change_rank) {
				fprintf(file, "%s\n", change_salary);
			}
		}
		system("cls");
		printf("\n\n   성공적으로 변경되었습니다!");
		Sleep(2000);
		fclose(file);
		main_screen(); // 로그인 후 메인화면
		break;
	case 2:
		main_screen(); // 로그인 후 메인화면
		break;
	default:
		system("cls");
		printf("\n\n   변경에 실패하였습니다! (잘못된 입력)");
		Sleep(2000);
		manage_salary(); // 급여관리 화면
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
	printf("┌────────────────────────┐\n");
	printf("│      회원가입승인      │\n");
	printf("├────────────────────────┤\n");
	printf("│ 1. ID로 조회           │\n");
	printf("│ 2. 이름으로 조회       │\n");
	printf("│ 3. 뒤로가기            │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		printf(" ID을 입력하세요. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 검사
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
			printf("\n\n   존재하지 않는 ID입니다.");
			Sleep(2000);
			permission_ID(); // 회원가입 승인
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "의 정보파일.txt");
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
			printf("\n\n   이미 승인된 회원입니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
		}
		fclose(file);
		system("cls");
		printf("\n\n   %s소속\n\n   %s님 인식되었습니다.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("┌────────────────────────┐\n");
		printf("│ 1. 회원가입 승인       │\n");
		printf("│ 2. 회원가입 거부       │\n");
		printf("│ 3. 뒤로가기            │\n");
		printf("└────────────────────────┘\n");
		printf(" 입력 : ");
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
			printf("\n\n   성공적으로 승인되었습니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
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
			printf("\n\n   성공적으로 거부되었습니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		case 3:
			permission_ID(); // 회원가입 승인
			break;
		default:
			system("cls");
			printf("\n\n   잘못된 메뉴 입력입니다.");
			permission_ID(); // 회원가입 승인
			break;
		}
		break;
	case 2:
		printf(" 이름을 입력하세요. : ");
		scanf("%s", name);
		for (i = 0; i < count; i++) // ID 검사
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
			printf("\n\n   존재하지 않는 이름입니다.");
			Sleep(2000);
			permission_ID(); // 회원가입 승인
		}
		count = 0;
		char* user_file_name2 = malloc(sizeof(char) * 50);
		strcpy(user_file_name2, login_data[j - 2]);
		strcat(user_file_name2, "의 정보파일.txt");
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
			printf("\n\n   이미 승인된 회원입니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
		}
		system("cls");
		printf("\n\n   %s소속\n\n   %s님 인식되었습니다.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("┌────────────────────────┐\n");
		printf("│ 1. 회원가입 승인       │\n");
		printf("│ 2. 회원가입 거부       │\n");
		printf("│ 3. 뒤로가기            │\n");
		printf("└────────────────────────┘\n");
		printf(" 입력 : ");
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
			printf("\n\n   성공적으로 승인되었습니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
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
			printf("\n\n   성공적으로 거부되었습니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		case 3:
			permission_ID(); // 회원가입 승인
			break;
		default:
			system("cls");
			printf("\n\n   잘못된 메뉴 입력입니다.");
			permission_ID(); // 회원가입 승인
			break;
		}
		break;
	case 3:
		system("cls");
		printf("\n\n   잘못된 메뉴 입력입니다.");
		other_info_menu(); // 사원정보 조회 메뉴
		break;
	default:
		other_info_menu(); // 사원정보 조회 메뉴
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
	printf("┌────────────────────────┐\n");
	printf("│      사원정보조회      │\n");
	printf("├────────────────────────┤\n");
	printf("│ 1. ID로 조회           │\n");
	printf("│ 2. 이름으로 조회       │\n");
	printf("│ 3. 뒤로가기            │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		printf(" ID을 입력하세요. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 검사
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
			printf("\n\n   존재하지 않는 ID입니다.");
			Sleep(2000);
			check_other_info(); // 사원정보 확인
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "의 정보파일.txt");
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
			printf("\n\n   본인보다 높은 직급은 조회할 수 없습니다.");
			Sleep(2000);
			check_other_info();
		}
		system("cls");
		printf("┌────────────────────────┐\n");
		printf("│      사원정보조회      │\n");
		printf("└────────────────────────┘\n");
		printf("ID : %s\n", login_data[j]);
		printf("PW : %s\n", login_data[j + 1]);
		printf("이름 : %s\n", info_data[0]);
		printf("나이 : %s\n", info_data[1]);
		printf("소속 : %s\n", info_data[2]);
		if (atoi(info_data[3]) == 1) {
			printf("직급 : 사원\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("직급 : 대리\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("직급 : 부장\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("직급 : 사장\n");
		}
		printf("근무시간 : %s\n", info_data[4]);
		printf("┌────────────────────────┐\n");
		printf("│ 1. 뒤로가기            │\n");
		printf("└────────────────────────┘\n");
		printf(" 입력 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		default:
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		}
		break;
	case 2:
		printf(" 이름을 입력하세요. : ");
		scanf("%s", name);
		for (i = 0; i < count; i++) // ID 검사
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
			printf("\n\n   존재하지 않는 이름입니다.");
			Sleep(2000);
			check_other_info(); // 사원정보 확인
		}
		count = 0;
		char* user_file_name3 = malloc(sizeof(char) * 50);
		strcpy(user_file_name3, login_data[j - 2]);
		strcat(user_file_name3, "의 정보파일.txt");
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
			printf("\n\n   본인보다 높은 직급은 조회할 수 없습니다.");
			Sleep(2000);
			check_other_info();
		}
		system("cls");
		printf("┌────────────────────────┐\n");
		printf("│      사원정보조회      │\n");
		printf("└────────────────────────┘\n");
		printf("ID : %s\n", login_data[j - 2]);
		printf("PW : %s\n", login_data[j - 1]);
		printf("이름 : %s\n", info_data[0]);
		printf("나이 : %s\n", info_data[1]);
		printf("소속 : %s\n", info_data[2]);
		if (atoi(info_data[3]) == 1) {
			printf("직급 : 사원\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("직급 : 대리\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("직급 : 부장\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("직급 : 사장\n");
		}
		printf("근무시간 : %s\n", info_data[4]);
		printf("┌────────────────────────┐\n");
		printf("│ 1. 뒤로가기            │\n");
		printf("└────────────────────────┘\n");
		printf(" 입력 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		default:
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		}
		break;
	case 3:
		system("cls");
		printf("\n\n   잘못된 메뉴 입력입니다.");
		other_info_menu(); // 사원정보 조회 메뉴
		break;
	default:
		other_info_menu(); // 사원정보 조회 메뉴
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
	printf("┌────────────────────────┐\n");
	printf("│     사원 직급 관리     │\n");
	printf("├────────────────────────┤\n");
	printf("│ 1. ID로 조회           │\n");
	printf("│ 2. 이름으로 조회       │\n");
	printf("│ 3. 뒤로가기            │\n");
	printf("└────────────────────────┘\n");
	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {



	case 1:
		printf(" ID을 입력하세요. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 검사
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
			printf("\n\n   존재하지 않는 ID입니다.");
			Sleep(2000);
			manage_rank(); // 사원직급 관리
		}
		count = 0;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, login_data[j]);
		strcat(user_file_name, "의 정보파일.txt");
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
			printf("\n\n   본인보다 높은 직급은 관리할 수 없습니다.");
			Sleep(2000);
			manage_rank(); // 사원직급 관리
		}
		system("cls");
		printf("\n\n   %s소속\n\n   %s님 인식되었습니다.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("┌────────────────────────┐\n");
		printf("│     사원 직급 관리     │\n");
		printf("├────────────────────────┤\n");
		printf("│ 본인 직급 이상으로는   │\n");
		printf("│ 변경이 불가능합니다.   │\n");
		printf("│ (1) 사원               │\n");
		printf("│ (2) 대리               │\n");
		printf("│ (3) 부장               │\n");
		printf("│ (4) 사장               │\n");
		printf("└────────────────────────┘\n");
		if (atoi(info_data[3]) == 1) {
			printf("현재직급 : 사원\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("현재직급 : 대리\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("현재직급 : 부장\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("현재직급 : 사장\n");
		}
		printf("바꿀직급 : ");
		scanf("%s", info_data[3]);
		if (atoi(info_data[3]) >= now.rank) {
			system("cls");
			printf("\n\n   해당 직급 변경 불가능입니다.");
			Sleep(2000);
			manage_rank(); // 사원직급 관리
		}
		printf("┌────────────────────────┐\n");
		printf("│ 1. 직급 변경           │\n");
		printf("│ 2. 변경 취소           │\n");
		printf("└────────────────────────┘\n");
		printf(" 입력 : ");
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
			printf("\n\n   성공적으로 변경되었습니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		case 2:
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		default:
			system("cls");
			printf("\n\n   잘못된 메뉴 입력입니다.");
			manage_rank(); // 사원직급 관리
			break;
		}
		break;




	case 2:
		printf(" 이름을 입력하세요. : ");
		scanf("%s", ID);
		for (i = 0; i < count; i++) // ID 검사
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
			printf("\n\n   존재하지 않는 ID입니다.");
			Sleep(2000);
			manage_rank(); // 사원직급 관리
		}
		count = 0;
		char* user_file_name4 = malloc(sizeof(char) * 50);
		strcpy(user_file_name4, login_data[j - 2]);
		strcat(user_file_name4, "의 정보파일.txt");
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
			printf("\n\n   본인보다 높은 직급은 관리할 수 없습니다.");
			Sleep(2000);
			manage_rank(); // 사원직급 관리
		}
		system("cls");
		printf("\n\n   %s소속\n\n   %s님 인식되었습니다.", info_data[2], info_data[0]);
		Sleep(2000);
		system("cls");
		printf("┌────────────────────────┐\n");
		printf("│     사원 직급 관리     │\n");
		printf("├────────────────────────┤\n");
		printf("│ 본인 직급 이상으로는   │\n");
		printf("│ 변경이 불가능합니다.   │\n");
		printf("│ (1) 사원               │\n");
		printf("│ (2) 대리               │\n");
		printf("│ (3) 부장               │\n");
		printf("│ (4) 사장               │\n");
		printf("└────────────────────────┘\n");
		if (atoi(info_data[3]) == 1) {
			printf("현재직급 : 사원\n");
		}
		else if (atoi(info_data[3]) == 2) {
			printf("현재직급 : 대리\n");
		}
		else if (atoi(info_data[3]) == 3) {
			printf("현재직급 : 부장\n");
		}
		else if (atoi(info_data[3]) == 4) {
			printf("현재직급 : 사장\n");
		}
		printf("바꿀직급 : ");
		scanf("%s", info_data[3]);
		if (atoi(info_data[3]) >= now.rank) {
			system("cls");
			printf("\n\n   해당 직급 변경 불가능입니다.");
			Sleep(2000);
			manage_rank(); // 사원직급 관리
		}
		printf("┌────────────────────────┐\n");
		printf("│ 1. 직급 변경           │\n");
		printf("│ 2. 변경 취소           │\n");
		printf("└────────────────────────┘\n");
		printf(" 입력 : ");
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
			printf("\n\n   성공적으로 변경되었습니다.");
			Sleep(2000);
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		case 2:
			other_info_menu(); // 사원정보 조회 메뉴
			break;
		default:
			system("cls");
			printf("\n\n   잘못된 메뉴 입력입니다.");
			manage_rank(); // 사원직급 관리
			break;
		}
		break;



	case 3:
		other_info_menu(); // 사원정보 조회 메뉴
		break;



	default:
		system("cls");
		printf("\n\n   잘못된 메뉴 입력입니다.");
		Sleep(2000);
		other_info_menu(); // 사원정보 조회 메뉴
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
	printf("┌────────────────────────┐\n");
	printf("│    개인정보수정        │\n");
	printf("└────────────────────────┘\n");
	printf("이름 : ");
	scanf("%s", join.name);
	printf("나이 : ");
	scanf("%d", &join.age);
	printf("소속 : ");
	scanf("%s", join.belong);
	printf("┌────────────────────────┐\n");
	printf("│ 1. 수정취소            │\n");
	printf("│ 2. 재입력              │\n");
	printf("│ 3. 완료                │\n");
	printf("└────────────────────────┘\n");

	printf(" 입력 : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		cheak_info(); // 정보 조회 화면
		break;
	case 2:
		change_info(); // 개인정보 수정
		break;
	case 3:
		;
		char* user_file_name = malloc(sizeof(char) * 50);
		strcpy(user_file_name, now.ID);
		strcat(user_file_name, "의 정보파일.txt");

		file = fopen(user_file_name, "w");
		if (file == NULL) {
			printf("파일 오류!");
			exit(1);
		}
		fprintf(file, "%s\n", join.name);
		fprintf(file, "%d\n", join.age);
		fprintf(file, "%s\n", join.belong);
		fprintf(file, "%d\n", now.rank);
		fprintf(file, "%d\n", now.hours);
		fclose(file);

		printf("\n--- 정보수정이 완료되었습니다.---- \n");
		Sleep(1000);
		printf("--- 재 로그인 바랍니다.---- \n\n");
		Sleep(1000);
		login(); // 정보 조회 화면
		break;
	default:
		system("cls");
		printf("\n\n   잘못된 메뉴 입력입니다.");
		cheak_info(); // 정보 조회 화면
		break;
	}
}


void Eliminate(char* str, char ch)
{
	for (; *str != '\0'; str++)//종료 문자를 만날 때까지 반복
	{
		if (*str == ch)//ch와 같은 문자일 때
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}