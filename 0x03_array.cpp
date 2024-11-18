// 0x03강 - 배열
// 배열은 메모리 상에 원소를 연속하게 배치한 자료구조
// 
// 배열의 성질
// 1. O(1)에 k번째 원소를 확인/변경 가능
// 2. 추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음
// 3. Cache hit rate가 높음
// 4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림
//
// 계산 비용
// 임의의 위치에 있는 원소를 확인, 변경은 O(1)
// 마지막 위치에 원소를 추가, 제거는 O(1)
// 임의의 위치에 원소를 추가는 O(N) -> 중간에 원소를 하나 넣으면, 그 뒤의 원소들을 모두 뒤로 밀어야 하므로
// 
// 배열 초기화 방법
// int a[21];
// int b[21][21];
// 
// 1. memset    -> 실수 가능성 높아서 조심
// memset(a, 0, sizeof a);
// memset(b, 0, sizeof b);
// 
// 2. for
// for (int i = 0; i < 21; i++)
//     a[i] = 0;
// for (int i = 0; i < 21; i++)
//     for (int j = 0; j < 21; j++)
//         b[i][j] = 0;
//
// 3. fill  -> 가장 추천
// fill(a, a+21, 0);
// for (int i = 0; i < 21; i++)
//     fill(b[i], b[i]+21, 0);


#include <iostream>
#include <vector>

// insert from BaaarkingDog
void insert(int idx, int num, int arr[], int& len){
    for (int i = len; i > idx; i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = num;
    len++;
}

// My insert
// 좀 더 간단하게 코드 구성 가능
void my_insert(int idx, int num, int arr[], int& len){
    if (idx == len) {
        arr[idx] = num; len++;
    }
    else if (idx < len) {
        for (int i = len; i > idx; i--){
            arr[i] = arr[i-1];
        }
        arr[idx] = num; len++;
    }
    else {
        std::cout << "out of range!" << '\n';
    }
}

// erase from BaaarkingDog
void erase(int idx, int arr[], int& len){
  len--;
  for(int i = idx; i < len; i++)
    arr[i] = arr[i+1];
}

// My erase
// len--; 부분이 뒤에 나오면 상황에 따라 오류 발생할 수 있음
// 개선 필요
void my_erase(int idx, int arr[], int& len){
    for (int i = idx; i < len; i++){
        arr[i] = arr[i+1];
    }
    len--;    
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) std::cout << arr[i] << ' ';
  std::cout << "\n\n";
}

void insert_test(){
  std::cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  std::cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}