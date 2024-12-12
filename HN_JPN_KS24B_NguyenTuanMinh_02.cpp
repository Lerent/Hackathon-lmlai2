#include <stdio.h>
#include <math.h>

int main () 
{
	int list[100];
	int size = 0;
	int choice;
	
	do {
		printf("\n-----------------MENU--------------------\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
	    printf("2. In ra gia tri cac phan tu dang quan ly\n");
	    printf("3. So luong cac so hoan hao trong mang\n");
	    printf("4. In ra gia tri nho thu 2 trong mang\n");
	    printf("5. Them mot phan tu vao trong mang\n");
	    printf("6. Xoa mot phan tu trong mang\n");
	    printf("7. Sap xep mang theo thu tu tang dan\n");
	    printf("8. Tim kiem phan tu\n");
	    printf("9. Sap xep mang theo so le so chan\n");
	    printf("10. Kiem tra mang co phai mang tang dan\n");
	    printf("11. Thoat\n");
	    printf("Lua chon cua ban: ");
	    scanf("%d", &choice);
	    
	    switch (choice) {
	    	case 1: {
				printf("Hay nhap so phan tu ");
				scanf("%d", &size);
				for (int i = 0; i < size; i++) {
					printf("Hay nhap gia tri cho %d phan tu ", size );
					scanf("%d", &list[i]); 
				}
				break;
			}
			case 2: {
				if(size == 0) {
					printf("Mang rong\n"); 
				} else {
					printf("Gia tri cua cac phan tu trong mang la ");
					for (int i = 0; i < size; i++) {
                        printf("arr[%d] = %d, ", i, list[i]); 
                    }
                    printf("\n"); 
				}	
				break;
			}
			case 3: {
				int count = 0;
                for (int i = 0; i < size; i++) {
                	int sum = 0;
                    for (int j = 1; j <= list[i] / 2; j++) {
                        if (list[i] % j == 0) {
                            sum += j;
                        }
                    }
                    if (sum == list[i] && list[i] > 1) {
                        count++;
                    }
                }
                printf("So luong cac so hoan hao trong mang: %d\n", count);
                break;
            }
			case 4: {
                int min1, min2;
                if (list[0] < list[1]) {
                    min1 = list[0];
                    min2 = list[1];
                } else {
                    min1 = list[1];
                    min2 = list[0];
                }
                for (int i = 2; i < size; i++) {
                    if (list[i] < min1) {
                        min2 = min1;
                        min1 = list[i];
                    } else if (list[i] < min2) {
                        min2 = list[i];
                    }
                }
                printf("Gia tri nho thu 2 trong mang la: %d\n", min2);   
                break;
            }
			case 5: {
				int newValue;
                    printf("Nhap gia tri phan tu can them ");
                    scanf("%d", &newValue);
                    list[size] = newValue;
                    size++;
                    printf("Phan tu da duoc them vao mang\n");
				break;
			} 
			case 6: {
				 if (size == 0) {
                    printf("Mang rong khong co phan tu de xoa.\n");
                } else {
                	int Delete;
	                printf("Hay nhap gia tri phan tu can xoa ");
	                scanf("%d", &Delete);
	                int found = 0;
	                for (int i = 0; i < size - 1; i++) {
	                    if (list[i] == Delete) {
	                    	found = 1;
	                        for(int j = i; j < size - 1; j++) {
	                        	list[j] = list[j + 1];
							} 
							size--;
							printf("Phan tu %d da duoc xoa\n", Delete);
							break; 
	                    }
	                }
	                if (!found) {
                    	printf("Khong tim thay phan tu %d trong mang.\n", Delete);
                    }
				}
				break;
			}
			case 7: {
				if (size == 0) {
                    printf("Mang rong\n");
                } else {
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (list[i] > list[j]) {
                                int temp = list[i];
                                list[i] = list[j];
                                list[j] = temp;
                            }
                        }
                    }
                    printf("Mang sau khi sap xep ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", list[i]);
                    }
                    printf("\n");
                }
				break;
			}
			case 8: {
				int SearchVal;
    			printf("Hay nhap gia tri can tim ");
    			scanf("%d", &SearchVal);
    			printf("Tim thay phan tu %d o vi tri thu ", SearchVal);
    			for (int i = 0; i < size; i++) {
        			if (list[i] == SearchVal) {
            			printf("%d ", i); 
        			}
    			}
    			printf("\n");
				break;
			}
			case 9: {
				if(size == 0) {
					printf("Mang rong\n"); 
				} else {
					printf("Gia tri cua cac phan tu chan trong mang la ");
					for (int i = 0; i < size; i++) {
						if (list[i] % 2 == 0)
                        	printf("%d ", i, list[i]);
                    } 
                    printf("Gia tri cua cac phan tu le trong mang la ");
                    for (int i = 0; i < size; i++) {
						if (list[i] % 2 != 0)
                        	printf("%d ", i, list[i]);
                    }
                    printf("\n"); 
				}	
				break;
			}
			case 10: {
				int tangDan = 0;
				for (int i = 0; i < size; i++) {
                   if (list[i] < list[i + 1]) {
                   	tangDan = 1; 
				   }
                }
                if(tangDan == 1) {
                	printf("Mang nay co tang dan\n");
				}else {
					printf("Mang nay ko tang dan\n"); 
				}
				printf("\n"); 
				break;
			}
			case 11: {
				printf("Thoat chuong trinh\n"); 
				break;
			}
			default:
                printf("Lua chon khong hop le, hay chon lai\n");
                break;
		}
	} while (choice != 11);
	
	return 0; 
}	
	    
