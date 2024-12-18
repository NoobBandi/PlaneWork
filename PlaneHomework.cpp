#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

#define ROWS 10
#define COLS 6

// 定義全域變數 
int seat[ROWS][COLS];

void findSeat(int num, int firstCount) {
	int found = 0;
	for (int i = 0; i < ROWS && !found; i++) {
		for (int j = 0; j < COLS && !found; j++) {
			if (seat[i][j] == num) {
				char row = 'A' + i;
				int col = j + 1;
				
				
				if (num <= firstCount) {
                    printf("乘客 %d：頭等艙，座位 %c%d\n", num, row, col);
                } else {
                    printf("乘客 %d：經濟艙，座位 %c%d\n", num, row, col);
                }
				found = 1;
			} 
		}
	}
	if (!found) {
		printf("找不到座位 %d\n", num);
	}
}

void changeSeat(int change1, int change2) {
	int pos1_i = -1, pos1_j = -1;
    int pos2_i = -1, pos2_j = -1;
    
    // 找到兩個座位的位置
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
    
    // 檢查是否找到兩個座位
    if(pos1_i == -1 || pos2_i == -1) {
        printf("錯誤：找不到指定的座位編號！\n");
        return;
    }
    
    // 交換座位
    int temp = seat[pos1_i][pos1_j];
    seat[pos1_i][pos1_j] = seat[pos2_i][pos2_j];
    seat[pos2_i][pos2_j] = temp;
    
    printf("以交換乘客 %d 和乘客 %d 的座位\n", change1, change2);

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

	printf("這班機有 12 位頭等艙座位和 48 位經濟艙座位。\n");
	do {
	    printf("請輸入頭等艙乘客數量：");
	    fflush(stdin);
	    scanf("%d", &fCsettings);
	    
	    printf("請輸入經濟艙乘客數量：");
	    fflush(stdin);
	    scanf("%d", &eCsettings);
	    
	    total = fCsettings + eCsettings;

	    // 如果超過 60 個座位，顯示錯誤訊息
	    if (fCsettings > 12) {
	    	printf("輸入頭等艙的數量已超過本航班座位限制\n");
		} else if (eCsettings > 48) {
			printf("輸入經濟艙的數量已超過本航班座位限制\n");
		} else if(total > 60) {
	        printf("總加起來已經超過本航班座位限制\n");
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
	
	printf("\n隨機分配的座位：\n");
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
		printf("\n請輸入查詢座位的乘客編號：");
        fflush(stdin);
        scanf("%d", &firstSearch);
        
        if(firstSearch == 0) {
            break;
        }
        
        findSeat(firstSearch, fCsettings);
	}
	
	while(1) {
		printf("請輸入要交換座位的兩位乘客編號（用空格分隔）：");
		fflush(stdin);
        scanf("%d %d", &change1, &change2);
        
        if(change1 == 0) {
            break;
        }
        
        if (change1 != change2) {
        	changeSeat(change1, change2);
    	} else {
        	printf("不能與相同座位進行更換！\n");
		}
	}
	
	while(1) {
		printf("按下空白鍵重新安排座位，案其他任意鍵退出程式...\n");
		if(_getch() != 32) {
			return 0;
		} else {
			system("cls");
			main();
		}
	}
	
	return 0;
}
