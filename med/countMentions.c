// Count Mentions Per User

#include <stdbool.h>
#include <stdlib.h>

int str_to_num(char str[]){
    int num = 0;
    for(int i = 0; i < strlen(str); i++){
        num *= 10;
        num += (int) (str[i] - '0');
    }
    return num;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
    int time_arr[eventsSize];
    for(int i = 0; i < eventsSize; i++){
        time_arr[i] = str_to_num(events[i][1]);
    }
    int order[eventsSize];
    for(int i = 0; i < eventsSize; i++) order[i] = i;
    for(int i = eventsSize - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(time_arr[order[j+1]] < time_arr[order[j]] || (time_arr[order[j+1]] == time_arr[order[j]] && events[order[j+1]][0][0] == 'O')){
                int t = order[j];
                order[j] = order[j+1];
                order[j+1] = t;
            }
        }
    }

    int online[numberOfUsers];
    int *mention = (int *) malloc(sizeof(int) * numberOfUsers);
    memset(online, 0, sizeof(online));
    memset(mention, 0, sizeof(int) * numberOfUsers);
    *returnSize = numberOfUsers;

    for(int n = 0; n < eventsSize; n++){
        int i = order[n];

        if(events[i][0][0] == 'M'){
            if(events[i][2][0] == 'A'){
                for(int j = 0; j < numberOfUsers; j++) mention[j] += 1;
            }
            else if(events[i][2][0] == 'H'){
                int time = str_to_num(events[i][1]);
                for(int j = 0; j < numberOfUsers; j++){
                    if(online[j] == 0) mention[j] += 1;
                    else if(online[j] <= time){
                        online[j] = 0;
                        mention[j] += 1;
                    }
                }
            }
            else{
                char t_id[10];
                char *prev = &(events[i][2][0]), *space = strchr(events[i][2], ' ');
                while(true){
                    memset(t_id, '\0', sizeof(t_id));
                    if(space == NULL){
                        strcpy(t_id, prev + 2);
                        mention[str_to_num(t_id)] += 1;
                        break;
                    }
                    else{
                        strncpy(t_id, prev + 2, (int) (space - prev - 2));
                        mention[str_to_num(t_id)] += 1;
                        prev = space + 1;
                        space = strchr(prev, ' ');
                    }
                }
            }
        }
        else if(events[i][0][0] == 'O'){
            online[str_to_num(events[i][2])] = str_to_num(events[i][1]) + 60;
        }

    }

    return mention;
}