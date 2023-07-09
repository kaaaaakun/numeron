#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// <<<<<<< HEAD
// int hasDuplicate(char guess[]) {
// 	// for (int i = 0; guess[i] != '\0' ; i++)
// 	// {
// 	// 	if (guess[i] < '0' || '9' < guess[i] || 10 < i)
// 	// 		return 1;
// 	// }
// 	for (int i = 0; i < 4; i++) {
// =======
int hasDuplicate(int guess[]) {
    for (int i = 0; i < 4; i++) {
// >>>>>>> 53f40b6... OK
        for (int j = i + 1; j < 4; j++) {
            if (guess[i] == guess[j]) {
                return 1; // 重複が見つかった場合、エラーとして1を返す
            }
        }
    }
    return 0; // 重複がない場合は0を返す
}

int main() {
// <<<<<<< HEAD
//     char target[4];  // 目標の4桁の数字
//     char guess[4];   // プレイヤーの予想の4桁の数字
// =======
    int target[4];  // 目標の4桁の数字
    int guess[4];   // プレイヤーの予想の4桁の数字
// >>>>>>> 53f40b6... OK
    int attempts = 0;  // プレイヤーの試行回数
    srand(time(0));

//<<<<<<< HEAD
//    target[0] = rand() % 10 + 48;
//
//    do {
//        target[1] = rand() % 10 + 48;
//    } while (target[1] == target[0]);
//
//    do {
//        target[2] = rand() % 10 + 48;
//    } while (target[2] == target[0] || target[2] == target[1]);
//
//    do {
//        target[3] = rand() % 10 + 48;
//=======
    target[0] = rand() % 10;

    do {
        target[1] = rand() % 10;
    } while (target[1] == target[0]);

    do {
        target[2] = rand() % 10;
    } while (target[2] == target[0] || target[2] == target[1]);

    do {
        target[3] = rand() % 10;
// >>>>>>> 53f40b6... OK
    } while (target[3] == target[0]  || target[3] == target[1]|| target[3] == target[2]);
printf("%d%d%d%d\n",target[0],target[1],target[2],target[3]);
    printf("数当てゲームを開始します！\n");
    printf("0から9までの数字を使って4桁の数を当ててください。\n");

    while (1) {
        int hits = 0;    // ヒットの数
        int breaks = 0;  // ブレークの数

        printf("\n4桁の数字を入力してください（重複は不可）: ");
// <<<<<<< HEAD
//         if (scanf("%1c%1c%1c%1c", &guess[0], &guess[1], &guess[2], &guess[3]) != 4 || hasDuplicate(guess)) {
//             printf("入力が無効です。正しい4桁の数字を正しく入力してください。\n");
// =======
        if (scanf("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]) != 4 || hasDuplicate(guess)) {
            printf("入力が無効です。重複があるか、4桁の数字を正しく入力してください。\n");
// >>>>>>> 53f40b6... OK
            fflush(stdin); // 入力バッファをクリア
            continue; // ループを継続して入力をやり直す
        }
        attempts++;

        // ヒットとブレークの数を計算
        for (int i = 0; i < 4; i++) {
            if (guess[i] == target[i]) {
                hits++;
            } else if (guess[i] == target[(i + 1) % 4]  || guess[i] == target[(i + 2) % 4]|| guess[i] == target[(i + 3) % 4]) {
                breaks++;
            }
        }

        printf("ヒット: %d, ブレーク: %d\n", hits, breaks);

        // 正解した場合
        if (hits == 4) {
            printf("正解です！おめでとうございます！\n");
            printf("試行回数: %d\n", attempts);
            break;
        }
    }
    return 0;
}

