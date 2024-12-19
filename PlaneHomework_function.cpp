#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

#define ROWS 10
#define COLS 6

int seat[ROWS][COLS];

// ﹍て畒
void initializeSeats(int fCsettings, int eCsettings) {
    int count = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (count <= fCsettings + eCsettings) {
                seat[i][j] = count;
                count++;
            } else {
                seat[i][j] = 0;
            }
        }
    }
}

// 陪ボ畒
void displaySeats() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(seat[i][j] == 0) {
                printf("0  ");  
            } else if(seat[i][j] < 10) {
                printf("%d  ", seat[i][j]);  
            } else {
                printf("%d ", seat[i][j]);  
            }
        }
        printf("\n");
    }
}

// 琩т畒
void findSeat(int num, int firstCount) {
    int found = 0;
    for (int i = 0; i < ROWS && !found; i++) {
        for (int j = 0; j < COLS && !found; j++) {
            if (seat[i][j] == num) {
                char row = 'A' + i;
                int col = j + 1;
                
                if (num <= firstCount) {
                    printf("畒 %d 繷单康, 竚 %c%d\n", num, row, col);
                } else {
                    printf("畒 %d 竒蕾康, 竚 %c%d\n", num, row, col);
                }
                found = 1;
            } 
        }
    }
    if (!found) {
        printf("琩礚畒 %d\n", num);
    }
}

// 传畒
void changeSeat(int change1, int change2) {
    int pos1_i = -1, pos1_j = -1;
    int pos2_i = -1, pos2_j = -1;
    
    // тㄢ畒竚
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seat[i][j] == change1) {
                pos1_i = i;
                pos1_j = j;
            }
            if (seat[i][j] == change2) {
                pos2_i = i;
                pos2_j = j;
            }
        }
    }
    
    // 狦畒ぃ
    if (pos1_i == -1 || pos2_i == -1) {
        printf("岿粇: Τ畒ぃ, 礚猭秈︽传\n");
        return;
    }
    
    // 秈︽畒ユ传
    int temp = seat[pos1_i][pos1_j];
    seat[pos1_i][pos1_j] = seat[pos2_i][pos2_j];
    seat[pos2_i][pos2_j] = temp;
    
    printf("盢畒 %d 籔畒 %d ユ传\n", change1, change2);
    displaySeats();
}

// ノめ砞竚畒计秖
void setupSeats(int* fCsettings, int* eCsettings) {
    int total;
    do {
        printf("叫块繷单康计秖: ");
        fflush(stdin);
        scanf("%d", fCsettings);
        
        printf("叫块竒蕾康计秖: ");
        fflush(stdin);
        scanf("%d", eCsettings);
        
        total = *fCsettings + *eCsettings;

        // 浪琩琌禬筁程计秖
        if (*fCsettings > 12) {
            printf("箇畒计秖禬筁程 (12)\n");
        } else if (*eCsettings > 48) {
            printf("畒计秖禬筁程 (48)\n");
        } else if (total > 60) {
            printf("羆畒计秖禬筁程 (60)\n");
        }
    } while (total > 60 || *fCsettings > 12 || *eCsettings > 48);
}

int main(void) { 
    int fCsettings, eCsettings, firstSearch, change1, change2;

    printf("畒皌竚: 12 箇畒㎝ 48 畒 60 畒\n");
    
    // 砞﹚畒计秖
    setupSeats(&fCsettings, &eCsettings);
    
    // ﹍て畒
    initializeSeats(fCsettings, eCsettings);
    
    printf("\n﹍畒皌竚:\n");
    displaySeats();

    // 琩т畒
    while (1) {
        printf("\n叫块琩高畒絪腹 (0癶): ");
        fflush(stdin);
        scanf("%d", &firstSearch);
        
        if (firstSearch == 0) {
            break;
        }
        
        findSeat(firstSearch, fCsettings);
    }
    
    // 传畒
    while (1) {
        printf("叫块璶传ㄢ畒絪腹 (0癶): ");
        fflush(stdin);
        scanf("%d %d", &change1, &change2);
        
        if (change1 == 0) {
            break;
        }
        
        if (change1 != change2) {
            changeSeat(change1, change2);
        } else {
            printf("岿粇: ぃ盢畒籔ユ传\n");
        }
    }
    
    // 单ノめ龄穝秨﹍
    while (1) {
        printf("龄穝秨﹍┪ㄤヴ種龄癶...\n");
        if (_getch() != 32) {
            return 0;
        } else {
            system("cls");
            main();
        }
    }
    
    return 0;
}

