// Design Spreadsheet

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    int *data;
} Spreadsheet;

static void trim_spaces(char *s) {
    if (!s) return;
    char *p = s;
    while (*p && isspace((unsigned char)*p)) p++;
    if (p != s) memmove(s, p, strlen(p) + 1);
    int len = (int)strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) s[--len] = '\0';
}

Spreadsheet* spreadsheetCreate(int rows) {
    Spreadsheet *obj = (Spreadsheet*)malloc(sizeof(Spreadsheet));
    obj->rows = rows;
    obj->cols = 26;
    obj->data = (int*)calloc((size_t)rows * obj->cols, sizeof(int));
    return obj;
}

void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value) {
    int col = toupper((unsigned char)cell[0]) - 'A';
    int row = atoi(cell + 1) - 1;
    obj->data[row * obj->cols + col] = value;
}

void spreadsheetResetCell(Spreadsheet* obj, char* cell) {
    int col = toupper((unsigned char)cell[0]) - 'A';
    int row = atoi(cell + 1) - 1;
    obj->data[row * obj->cols + col] = 0;
}

static int value_of_token(Spreadsheet *obj, char *tok) {
    trim_spaces(tok);
    if (isalpha((unsigned char)tok[0])) {
        int col = toupper((unsigned char)tok[0]) - 'A';
        int row = atoi(tok + 1) - 1;
        return obj->data[row * obj->cols + col];
    }
    return (int)strtol(tok, NULL, 10);
}

int spreadsheetGetValue(Spreadsheet* obj, char* formula) {
    char *body = formula;
    if (body[0] == '=') body++;
    char *plus = strchr(body, '+');
    if (!plus) {
        char tmp[64];
        strncpy(tmp, body, sizeof(tmp)-1);
        tmp[sizeof(tmp)-1] = '\0';
        return value_of_token(obj, tmp);
    }
    int left_len = (int)(plus - body);
    char left[64], right[64];
    memcpy(left, body, left_len);
    left[left_len] = '\0';
    strncpy(right, plus + 1, sizeof(right)-1);
    right[sizeof(right)-1] = '\0';
    int v1 = value_of_token(obj, left);
    int v2 = value_of_token(obj, right);
    return v1 + v2;
}

void spreadsheetFree(Spreadsheet* obj) {
    free(obj->data);
    free(obj);
}

int main() {
    Spreadsheet* spreadsheet = spreadsheetCreate(3);
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=5+7"));
    spreadsheetSetCell(spreadsheet, "A1", 10);
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=A1+6"));
    spreadsheetSetCell(spreadsheet, "B2", 15);
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=A1+B2"));
    spreadsheetResetCell(spreadsheet, "A1");
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=A1+B2"));
    spreadsheetFree(spreadsheet);
    return 0;
}
