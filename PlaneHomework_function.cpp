#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

#define ROWS 10
#define COLS 6

int seat[ROWS][COLS];

// ��l�Ʈy��
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

// ��ܮy��
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

// �d��y��
void findSeat(int num, int firstCount) {
    int found = 0;
    for (int i = 0; i < ROWS && !found; i++) {
        for (int j = 0; j < COLS && !found; j++) {
            if (seat[i][j] == num) {
                char row = 'A' + i;
                int col = j + 1;
                
                if (num <= firstCount) {
                    printf("�y�� %d �Y����, ��m %c%d\n", num, row, col);
                } else {
                    printf("�y�� %d �g�ٿ�, ��m %c%d\n", num, row, col);
                }
                found = 1;
            } 
        }
    }
    if (!found) {
        printf("�d�L�y�� %d\n", num);
    }
}

// �󴫮y��
void changeSeat(int change1, int change2) {
    int pos1_i = -1, pos1_j = -1;
    int pos2_i = -1, pos2_j = -1;
    
    // ����Ӯy���m
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
    
    // �p�G�y�줣�s�b
    if (pos1_i == -1 || pos2_i == -1) {
        printf("���~: ���y�줣�s�b, �L�k�i���\n");
        return;
    }
    
    // �i��y��洫
    int temp = seat[pos1_i][pos1_j];
    seat[pos1_i][pos1_j] = seat[pos2_i][pos2_j];
    seat[pos2_i][pos2_j] = temp;
    
    printf("�w�N�y�� %d �P�y�� %d �洫\n", change1, change2);
    displaySeats();
}

// �Τ�]�m�y��ƶq
void setupSeats(int* fCsettings, int* eCsettings) {
    int total;
    do {
        printf("�п�J�Y�������ȼƶq: ");
        fflush(stdin);
        scanf("%d", fCsettings);
        
        printf("�п�J�g�ٿ����ȼƶq: ");
        fflush(stdin);
        scanf("%d", eCsettings);
        
        total = *fCsettings + *eCsettings;

        // �ˬd�O�_�W�L�̤j�ƶq
        if (*fCsettings > 12) {
            printf("�w���y��ƶq�W�L�̤j���� (12)\n");
        } else if (*eCsettings > 48) {
            printf("�Ůy��ƶq�W�L�̤j���� (48)\n");
        } else if (total > 60) {
            printf("�`�y��ƶq�W�L�̤j���� (60)\n");
        }
    } while (total > 60 || *fCsettings > 12 || *eCsettings > 48);
}

int main(void) { 
    int fCsettings, eCsettings, firstSearch, change1, change2;

    printf("�y��t�m: 12 �w���y��M 48 �Ůy��A�@ 60 �y��\n");
    
    // �]�w�y��ƶq
    setupSeats(&fCsettings, &eCsettings);
    
    // ��l�Ʈy��
    initializeSeats(fCsettings, eCsettings);
    
    printf("\n��l�y��t�m:\n");
    displaySeats();

    // �d��y��
    while (1) {
        printf("\n�п�J�d�߮y��s�� (0�h�X): ");
        fflush(stdin);
        scanf("%d", &firstSearch);
        
        if (firstSearch == 0) {
            break;
        }
        
        findSeat(firstSearch, fCsettings);
    }
    
    // �󴫮y��
    while (1) {
        printf("�п�J�n�󴫪���Ӯy��s�� (0�h�X): ");
        fflush(stdin);
        scanf("%d %d", &change1, &change2);
        
        if (change1 == 0) {
            break;
        }
        
        if (change1 != change2) {
            changeSeat(change1, change2);
        } else {
            printf("���~: ���i�H�N�y��P�ۤv�洫\n");
        }
    }
    
    // ���ݥΤ���U�Ů��䭫�s�}�l
    while (1) {
        printf("���Ů��䭫�s�}�l�Ψ�L���N��h�X...\n");
        if (_getch() != 32) {
            return 0;
        } else {
            system("cls");
            main();
        }
    }
    
    return 0;
}

