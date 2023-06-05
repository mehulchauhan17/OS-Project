#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
struct process 
{
char activ[50];
int waitingTime, arrivalTime, burstTime, turnaroundTime, priority, id; 
};
char hours[24];
char act_name[24][50]; 
struct process a[24], b;
int n;
int extractHour(char *string) 
{
int i, time_int; 
char time_temp[3]; 
for (i = 0; i < 3; i++) 
{
if (string[i] == ':') 
{
break; 
}
time_temp[i] = string[i]; 
}
time_int = atoi(time_temp); 
return time_int;
}
int main() 
{
int temp[10], t, count = 0, highest_p, wake_time; 
char break_time[10], lun_time[10], din_time[10];int sleep_hours = 0;
char string[256], name[25], sleep[10];
float total_waitingTime = 0, total_turnaroundTime = 0, Avg_waitingTime, 
Avg_turnaroundTime;
printf("What is your name?\n"); 
scanf("%s", name);
printf("Greetings, %s! :)\n", name);
printf("When do you plan to sleep tonight?\n"); 
scanf("%s", sleep);
printf("How many hours, %s?\n", name); 
scanf("%d", &sleep_hours);
int sleep_time = extractHour(sleep); 
if (sleep_time + sleep_hours > 24) 
{
wake_time = sleep_time + sleep_hours - 24;
printf("So you'll wake up at %d:00, great!\n", wake_time); 
}
else 
{
wake_time = sleep_time + sleep_hours;
printf("So you'll wake up at %d:00 tomorrow, great!\n", wake_time); 
}
for (int i = 0; i < 24; ++i) 
{
strcpy(act_name[i],"Free"); 
}
char c;
printf("Do you have breakfast? y-yes n-no\n"); 
scanf(" %c", &c);
if (c == 'y') 
{
printf("Enter breakfast and grooming time\n"); 
scanf("%s", break_time);
}
int b_time= extractHour(break_time);printf("Enter lunch time\n"); 
scanf("%s", lun_time);
int l_time= extractHour(lun_time); 
printf("Enter dinner time\n");
scanf("%s", din_time);
int d_time= extractHour(din_time); 
printf("Enter the number of the activities:\n");
scanf("%d", &n);
printf("\nEnter the arrival time, duration and importance of the activities:\n"); 
for (int i = 0; i < n; i++)
{
printf("\nInput details of activity %d:\n", i + 1); 
printf("Enter activity name:\n");
scanf("%s", a[i].activ); 
printf("Enter Arrival-Time:- "); 
scanf("%s", string);
a[i].arrivalTime = extractHour(string);
printf("Number of hours needed for the activity:- "); 
scanf("%d", &a[i].burstTime);
printf("Number of priority for the activity:- "); 
scanf("%d", &a[i].priority);
temp[i] = a[i].burstTime; 
a[i].id = i;
}
a[9].priority = -1;
for (t = wake_time; t < 24; t++) 
{
if (t == b_time) 
{
hours[t] = 'B';
strcpy(act_name[t],"Breakfast"); 
continue;
}if (t == l_time) 
{
hours[t] = 'L';
strcpy(act_name[t],"Lunch"); 
continue;
}
if (t == d_time) 
{
hours[t] = 'D';
strcpy(act_name[t],"Dinner"); 
continue;
}
highest_p = 9;
for (int i = 0; i < n; i++) 
{
if (a[highest_p].priority < a[i].priority && a[i].arrivalTime <= t && a[i].burstTime 
> 0)
{
highest_p = i;
strcpy(act_name[t],a[i].activ); 
hours[t] = a[highest_p].id + '0';
} 
}
a[highest_p].burstTime = a[highest_p].burstTime - 1; 
if (a[highest_p].burstTime == 0)
{
count++;
a[highest_p].waitingTime = t + 1 - a[highest_p].arrivalTime - temp[highest_p]; 
a[highest_p].turnaroundTime = t + 1 - a[highest_p].arrivalTime;
total_waitingTime = total_waitingTime + a[highest_p].waitingTime;
total_turnaroundTime = total_turnaroundTime + a[highest_p].turnaroundTime; 
}
}
for (int i = 0; i < sleep_hours; i++) 
{hours[sleep_time] = 'S';
strcpy(act_name[sleep_time],"Sleep"); 
sleep_time++;
if (sleep_time > 23) 
sleep_time = 0;
}
Avg_waitingTime = total_waitingTime / n;
Avg_turnaroundTime = total_turnaroundTime / n;
printf("\n\nActivity-ID\tBreak-Time\tTotal-Submission-Time\n"); 
for (int i = 0; i < n; i++)
{
printf("%d\t\t%d\t\t%d\n", i , a[i].waitingTime, 
a[i].turnaroundTime);
}
printf("\n");
printf("\nAverage break time of the activities is %f\n", Avg_waitingTime);
printf("Average turnaround time of the activities is %f\n\n",Avg_turnaroundTime);
printf("Your schedule for the day is as follows:\n\n");
for (int i = 0; i < 24; i++) 
{
if(strcmp(act_name[i],act_name[i+1])==0) 
{
int j=i;
while(strcmp(act_name[i],act_name[i+1])==0) 
{
i++; 
}
printf("Hours: %d to %d\t\tActivity ID: %c\tActivity: %s\n", j, i+1, hours[i], 
act_name[i] );
}
else
{
if(i<10) 
{printf("Hour: %d to %d\t\tActivity ID: %c\tActivity: %s\n", i,i+1, hours[i], 
act_name[i]);
} 
else
printf("Hour: %d to %d\t\tActivity ID: %c\tActivity: %s\n", i,i+1, hours[i], 
act_name[i]);
} 
}
if(count!=n) 
{
printf("\nDon't worry as you didn't finish in time, you can do the remaining 
activities tomorrow, %s! :)\n",name);
} 
return 0; 
return 0;
}
