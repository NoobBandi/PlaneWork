#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

#define ROWS 10
#define COLS 6

// �w�q�����ܼ� 
int seat[ROWS][COLS];

void findSeat(int num, int firstCount) {
	int found = 0;
	for (int i = 0; i < ROWS && !found; i++) {
		for (int j = 0; j < COLS && !found; j++) {
			if (seat[i][j] == num) {
				char row = 'A' + i;
				int col = j + 1;
				
				
				if (num <= firstCount) {
                    printf("���� %d�G�Y�����A�y�� %c%d\n", num, row, col);
                } else {
                    printf("���� %d�G�g�ٿ��A�y�� %c%d\n", num, row, col);
                }
				found = 1;
			} 
		}
	}
	if (!found) {
		printf("�䤣��y�� %d\n", num);
	}
}

void changeSeat(int change1, int change2) {
	int pos1_i = -1, pos1_j = -1;
    int pos2_i = -1, pos2_j = -1;
    
    // ����Ӯy�쪺��m
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(seat[i][j] == change1) {
                pos1_i = i;
                pos1_j = j;
            }
            if(seat[i][j] == change2) {
                pos2_i = i;
                pos2_j = j;
            }
        }
    }
    
    // �ˬd�O�_����Ӯy��
    if(pos1_i == -1 || pos2_i == -1) {
        printf("���~�G�䤣����w���y��s���I\n");
        return;
    }
    
    // �洫�y��
    int temp = seat[pos1_i][pos1_j];
    seat[pos1_i][pos1_j] = seat[pos2_i][pos2_j];
    seat[pos2_i][pos2_j] = temp;
    
    printf("�H�洫���� %d �M���� %d ���y��\n", change1, change2);

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
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

int main(void) { 
	int firstSearch, change1, change2, fCsettings, eCsettings, total;
	int count = 1;

	printf("�o�Z���� 12 ���Y�����y��M 48 ��g�ٿ��y��C\n");
	do {
	    printf("�п�J�Y�������ȼƶq�G");
	    fflush(stdin);
	    scanf("%d", &fCsettings);
	    
	    printf("�п�J�g�ٿ����ȼƶq�G");
	    fflush(stdin);
	    scanf("%d", &eCsettings);
	    
	    total = fCsettings + eCsettings;

	    // �p�G�W�L 60 �Ӯy��A��ܿ��~�T��
	    if (fCsettings > 12) {
	    	printf("��J�Y�������ƶq�w�W�L����Z�y�쭭��\n");
		} else if (eCsettings > 48) {
			printf("��J�g�ٿ����ƶq�w�W�L����Z�y�쭭��\n");
		} else if(total > 60) {
	        printf("�`�[�_�Ӥw�g�W�L����Z�y�쭭��\n");
	    }
		
	} while (total > 60 || fCsettings > 12 || eCsettings > 48);
	 
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			seat[i][j] = 0;
		}
	}
	
	for (int i = 0; i < ROWS && count <= total; i++) {
		for(int j = 0; j < COLS && count <= total; j++) {
			seat[i][j] = count;
			count++;
		}
	}
	
	printf("\n�H�����t���y��G\n");
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
	
	while(1) {
		printf("\n�п�J�d�߮y�쪺���Ƚs���G");
        fflush(stdin);
        scanf("%d", &firstSearch);
        
        if(firstSearch == 0) {
            break;
        }
        
        findSeat(firstSearch, fCsettings);
	}
	
	while(1) {
		printf("�п�J�n�洫�y�쪺��쭼�Ƚs���]�ΪŮ���j�^�G");
		fflush(stdin);
        scanf("%d %d", &change1, &change2);
        
        if(change1 == 0) {
            break;
        }
        
        if (change1 != change2) {
        	changeSeat(change1, change2);
    	} else {
        	printf("����P�ۦP�y��i��󴫡I\n");
		}
	}
	
	while(1) {
		printf("���U�ť��䭫�s�w�Ʈy��A�ר�L���N��h�X�{��...\n");
		if(_getch() != 32) {
			return 0;
		} else {
			system("cls");
			main();
		}
	}
	
	return 0;
}
