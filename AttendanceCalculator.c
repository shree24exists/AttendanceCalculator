#include<stdio.h>
int main() //Total Number of lectures taken as 20 (excludes Labs)
//YOU NEED TO CREATE "attendance_data" TEXT FILE MANUALLY!!
 {
    int rno;
    char att;
    int roll[65] = {0};

FILE *file = fopen("attendance_data.txt", "r");
    if (file != NULL) {
        for (int i = 0; i < 65; i++) {
            fscanf(file, "%d", &roll[i]);
        }
        fclose(file);
    }

    printf("Enter your Roll Number: ");
    scanf("%d", &rno);

    printf("The number of lectures attended for roll number %d is %d",rno, roll[rno]);
    int x = (roll[rno]*100)/20;
    printf("\nTheir attendance is %d percent",x);

    for (int i = 1; i <= 4; i++) {
        printf("\nTaking attendance for Lecture %d", i);
        printf("\nIs the entered roll number present? (Y/N): ");
        scanf(" %c", &att);

    if(att == 'Y' || att == 'y') {
        roll[rno] += 1;
        int x = (roll[rno]*100)/20;
        printf("Attendance Marked. Updated No. of lectures attended are %d, and %d percent is their attendance", roll[rno],x);
    } else if (att == 'N' || att == 'n') {
            printf("Absentee Marked. No changes were made to number of lectures attended.\n");
    }

 }
   file = fopen("attendance_data.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < 65; i++) {
            fprintf(file, "%d\n", roll[i]);
        }
        fclose(file);
    } else {
        printf("Error: Could not save attendance data.\n");
    }
 return 0;
 }