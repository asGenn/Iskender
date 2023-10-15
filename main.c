#include <stdio.h>
#include <stdlib.h>
const int INDEX = 50;
const int INDEXsc = 5;
int findFirstZero(const int a[]){
    for (int i = 0; i <INDEX ; ++i) {
        if(a[i] == 0){
            return i;
        }
    }
    return 99;
}
void initiliazeArray(int a[]){
    for (int i = 0; i < INDEX; ++i) {
        a[i] = 0;
    }
}
void printPlanlamaPenceresi(const int a[]){
    for (int i = 0; i < INDEX; ++i) {
        printf("-%d %d\n",i,a[i]);
    }
}

/*
void printList(int s_list[5][3],int c_list[5][2]){

    printf("SList***\n");
    for (int i = 0; i < INDEXsc; ++i) {
        printf("%d %d %d\n",s_list[i][0],s_list[i][1],s_list[i][2]);

    }
    printf("CList***\n");
    for (int i = 0; i < INDEXsc; ++i) {

        printf("%d %d \n",c_list[i][0],c_list[i][1]);
    }
}
*/
void fillSList(int s_list[5][3],int period,int time){
    for (int i = 0; i < INDEXsc; ++i) {
        printf("%d******\n",i);
        if(s_list[i][0] == -1){
            s_list[i][0] = i + 11;
            s_list[i][1] = period;
            s_list[i][2] = time;
            break;
        }
    }
}
void fillCList(int c_list[5][2],int time){
    for (int i = 0; i < INDEXsc; ++i) {
        if(c_list[i][0] == -1){
            c_list[i][0] = i+ 1;
            c_list[i][1] = time;
            break;
        }else{
            printf("***Daha yer kalmadı***");
        }
    }
}
int isValid(const int planlamaPenceresi[],int time,int index){
    int count =0;
    //int firstZeroIndex = findFirstZero(planlamaPenceresi);
    for (int i = index; i < index + time +1 ; ++i) {
        printf("i is : %d \n",i);
        if(planlamaPenceresi[i] == 0 && i <50){
            printf("count = %d \n",count);
            if(time ==count ){
                printf("%d**\n", i-time);
                return i-time;
            }
            count++;

        }else{
            count = 0;
        }
    }
    return 99;
}
int isValidForC(const int planlamaPenceresi[],int time,int index){
    int count =0;
    //int firstZeroIndex = findFirstZero(planlamaPenceresi);
    for (int i = index; i < index + time  ; ++i) {
        printf("i is : %d \n",i);
        if(planlamaPenceresi[i] == 0 && i <50){
            printf("count = %d \n",count);

            count++;
            if(time ==count ){
                printf("%d**\n", i-time);
                return i-time+1;
            }

        }else{
            count = 0;
        }
    }
    return 99;
}
void makePlanForC(int c_list[5][2],int planlama_penceresi[50]){
    for (int i = 0; i < INDEXsc; ++i) {
        if(c_list[i][0] != -1){
            for (int b=0; b < INDEX; ++b) {
                if(planlama_penceresi[b] ==0){
                    printf("b is : %d \n",b);
                    int firstValidIndex =  isValidForC(planlama_penceresi,c_list[i][1],b);
                    printf("first valid index is : %d\n", firstValidIndex );
                    if(firstValidIndex != 99){
                        for (int j = firstValidIndex; j < firstValidIndex+ c_list[i][1]; ++j) {
                            planlama_penceresi[j] = c_list[i][0];
                        }
                        break;
                    }

                    else{
                        for (int j = 0; j <  c_list[i][1]; ++j) {
                            planlama_penceresi[j] = c_list[i][0];
                        }
                        break;
                    }
                }
            }
        }
    }
}
void makePlan(int s_list[5][3],int c_list[5][2],int planlama_penceresi[50]){
    initiliazeArray(planlama_penceresi);
    for (int i = 0; i < INDEXsc; ++i) {
        if(s_list[i][0] != -1){
            for (int b=0; b < INDEX; ++b) {
                if(planlama_penceresi[b] ==0){
                    int firstValidIndex =  isValid(planlama_penceresi,s_list[i][2],b);
                    if(firstValidIndex != 99){
                        for (int j = firstValidIndex; j < firstValidIndex+ s_list[i][2]; ++j) {
                            printf("j-%d ",j);
                            planlama_penceresi[j] = s_list[i][0];
                        }

                    }
                    b= b+s_list[i][1]-1;
                }
            }
        }
    }
    makePlanForC(c_list,planlama_penceresi);
}

int main() {

    int planlama_penceresi[50];
    char input= 0;
    char input1,input2;
    int time,period;
    int s_list[5][3] = {{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0}};
    int c_list[5][2] = {{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}};
    initiliazeArray(planlama_penceresi);

    while (1){
        printf("İş eklemek için (e) \nPlanlamak için (p)\nÇıkmak için (c)\n");
        printf("Input:");
        scanf(" %c", &input1);
        switch (input1)
        {
            case 'e':
                printf("eklemek istediğiniz iş türü ? (S/C)\n");
                printf("Input:");
                scanf(" %c", &input2);
                switch (input2) {
                    case 's':
                        printf("Period:");
                        scanf("%d", &period);
                        printf("Time:");
                        scanf("%d", &time);
                        fillSList(s_list, period, time);
                        printList(s_list,c_list);
                        break;
                    case 'c':
                        printf("Time:");
                        scanf("%d", &time);
                        fillCList(c_list,time);
                        printList(s_list,c_list);
                        break;
                    default:
                        printf("yanlış ");
                        break;
                }
                break;

            case 'p':
                makePlan(s_list,c_list,planlama_penceresi);
                //printf("%d\n",isValid(planlama_penceresi,10) );
                printPlanlamaPenceresi(planlama_penceresi);

                //printList(s_list,c_list);
                break;
            case 'c':
                exit(0);
                break;
            default:
                printf("yanlış seçim");
                break;
        }

    }
    initiliazeArray(planlama_penceresi);
    //findFirstIndex(planlama_penceresi);
    return 0;
}
