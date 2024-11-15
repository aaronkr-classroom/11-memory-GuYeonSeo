#include <stdio.h>

#define ROWS 3 //행의 개수
#define COLS 5 //열의 개수

//2차원 배열을 출력하는 함수
void printArr(char arr[ROWS][COLS]) {
	printf("배열의 상태 : \n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n"); //다음 행으로 가기
	}
	printf("\n"); //끝
}

int main(void) {
	//ROWSXCOLS 크기의 2차원 배열 선언
	char data[ROWS][COLS] = { 0 }; //모든 요소를 0으로 초기화
	char (*p)[COLS]; //COLS 개의 char을 가지는 배열을 가리키는

	p = data; // 포인터 p가 data 배열을 가리키도록 설정

	//포인터를 사용하여 배열의 요소에 값 할당
	(*p)[1] = 3; //첫번째 행의 두번째 요소에 3할당
	(*(p + 1))[2] = 4; //두번째 행의 세번째 요소에 4할당
	(*(p + 2))[4] = 5; //세번째 행의 다섯번째 요소에 5할당

	printf("초기 배열의 상태 : \n");
	printArr(data);

	//2차원 배열을 수정하기
	p = data; //포인터 p를 다시 첫번째 행으로 초기화
	p++; //포인터 p를 두번째 행으로 이동
	(*p)[0] = 7; //두번째 행의 첫번째 요소에 7할당
	(*p)[4] = 8;
	(*(p - 1))[3] = 9; //첫번째 행을 수정하기

	printf("두 번째 수정 후 배열의 상태 : \n");
	printArr(data);

	//포인터 산술 연산을 사용함
	char* ptr = &data[0][0]; //배열의 첫번째 요소를 가리키는 포인터
	*(ptr + 6) = 10; //두번째 행의 두번째 요소에 10할당
	*(ptr + 10) = 11; //세번째 행의 첫번째 요소에 11할당
	*(ptr + 14) = 28; //마지막 요소에 28할당
	//*(ptr + 15) = 100; //오류
	//ptr의 길이가 ROWSxCOLS까지 이니까
	//ptr의 인덱스가 ROWSxCOLS-1까지 갈 수 있다(ptr[14])

	printf("포인터 산술 연산 후 배열의 상태 : \n");
	printArr(data);

	// 첫번째와 세번째 행을 바꾸기
	char temp[COLS]; //임시 저장 배열
	for (int i = 0; i < 5; i++) {
		temp[i] = data[0][i]; //첫번째 행의 요소를 temp에 복사
		data[0][i] = data[2][i]; //세번째 행의 요소를 첫번째 행에 복사
		data[2][i] = temp[i];  //temp의 요소를 세번째 행에 복사
	}

	printf("첫번째 행과 세번째 행 교환 후 배열의 상태 : \n");
	printArr(data);

	return 0;
}