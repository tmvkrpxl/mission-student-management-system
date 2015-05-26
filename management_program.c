#include<stdio.h>
#include<stdlib.h>
#define NUMBER_OF_STUDENT 250

struct student{
	int number;
	char name;
	int status;
	//status에서 0은 재학 1은 휴학
	int score;
};

void register_student(struct student*);
void input_score(struct student*);
void student_status(struct student*);
void search_student(struct student*);
void remove_student(struct student*);

int main(void){
	int n;
	struct student* student = (struct student*) malloc(NUMBER_OF_STUDENT * sizeof(struct student));
	printf("학생을 등록하려면 1를 입력하세요\n성적 입력을 하려면 2를 입력하세요\n휴학 / 복학 신청을 하려면 3를 입력하세요\n학생을 검색하려면 4를 입력하세요\n등록된 학생을 제거하려면 5를 입력하세요\n");
	scanf_s("%d", &n);
	if (n == 1){
		//학생의 등록
		register_student(student);
	}
	if (n == 2){
		//학생의 성적 입력
		input_score(student);
	}
	if (n == 3){
		//학생의 휴학 / 복학 신청
		status(student);
	}
	if (n == 4){
		//학생의 검색
		search_student(student);
	}
	if (n == 5){
		//등록된 학생의 제거
		remove_student(student);
	}


	free(student);
}

void register_student(struct student* student){
	printf("학번을 입력하세요\n");
	scanf_s("%d", &(student->number));
	printf("이름을 입력하세요\n");
	scanf_s("%s", &(student->name));
	(student->status) = 0;
	(student->score) = 0;
}

void input_score(struct student* student){
	/*
	A: 91 ~ 100
	B: 81 ~ 90
	C: 71 ~ 80
	D: 61 ~ 70
	F: ~ 60
	단, 휴학 중인 상태의 학생은 성적을 입력할 수 없습니다.*/
	printf("점수를 입력하세요 ( 0 ~ 100 )");
	scanf_s("%d",&(student->score));


}

int status(struct student* student){
	int status_status;
	int n;
	printf("학번을 입력하세요\n");
	scanf_s("%d", &(status_status));
	if (status_status == (student->number)){
		if ((student->status) == 0){
			printf("휴학 신청을 하려면 1을 입력해주세요\n아니면 아무 키나 입력해주세요\n");
			scanf_s("%d", &n);
			if (n == 1){
				(student->number) = 1;
				printf("휴학 신청 되었습니다\n");
			}
			else printf("취소되었습니다\n");
		}
		if ((student->status) == 1){
			printf("복학 신청을 하려면 1을 입력해주세요\n아니면 아무 키나 입력해주세요\n");
			scanf_s("%d", &n);
			if (n == 1){
				(student->number) = 0;
				printf("복학 신청 되었습니다\n");
			}
			else printf("취소되었습니다\n");
		}
	}
	else printf("일치하는 학번이 없습니다\n");
}

void search_student(struct student* student){
	// 학번1 이름2 성적3 재학/휴학4
	int n, m;
	printf("학번으로 검색하시려면 1\n이름으로 검색하시려면 2\n성적으로 검색하시려면 3\n재학/휴학으로 검색하시려면 4를 입력하세요\n");
	scanf_s("%d", &n);
	if (n == 1){
		//학번검색
		printf("학번을 입력하세요\n");
		scanf_s("%d", &m);
		if (m == (student->number)){
			printf("");
		}
	}
	if (n == 2){
		//이름검색
		printf("이름을 입력하세요\n");
		scanf_s("%s", &m);
	}
	if (n == 3){
		//성적검색
		printf("성적을 입력하세요\n");
		scanf_s("%d", &m);
		if (m == (student->score)){
			printf("");
		}

	}
	if (n == 4){
		//재학/휴학검색
		printf("재학 상태이면 0을 입력하세요\n휴학 상태이면 1을 입력하세요\n");
		scanf_s("%d", &m);
	}
	else printf("1~4의 숫자를 입력하세요\n");
}

void remove_student(struct student* student){
	//등록된 학생의 정보는 언제든지 제거가 가능하며 학번을 입력하여 제거할 수 있습니다.
	int status_status;
	int n;
	printf("학번을 입력하세요\n");
	scanf_s("%d", &status_status);
	if (status_status == (student->number)){
		printf("입력된 학번의 학생을 제거하시려면 1번을 입력하세요\n아니면 아무 키나 입력해주세요\n");
		scanf_s("%d", &n);
		if (n == 1){
			student->number = 0;
			student->name = 0;
			student->status = 0;
			student->score = 0;
			printf("제거되었습니다\n");
		}
		else printf("취소되었습니다\n");
	}
	else printf("일치하는 학번이 없습니다\n");
}