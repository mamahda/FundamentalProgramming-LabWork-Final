#include <stdio.h>
#include <stdlib.h>

// simpan nilai dan posisi elemen di struct (emang iya perlu struct untuk soal ini apakah aku berpikir terlalu jauh?)
struct Element {
    int value;
    int i;
    int j;
};

// fungsi buat ngesort
int compare(const void* a, const void* b) {
    return ((struct Element*)a)->value - ((struct Element*)b)->value;
}

int main() {
    int x, y, target;
    scanf("%d %d", &x, &y);

    int array[x][y];
    struct Element sorted[x * y];
    int k = 0;
    
    // emang seribet ini ya(?) tapi ya sudahlah
    // pemikiran orang berbeda beda
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &array[i][j]);
            sorted[k].value = array[i][j];
            sorted[k].i = i;
            sorted[k].j = j;
            k++;
        }
    }
    
    scanf("%d", &target);
    
    //karena binary search maka harus di sort dulu
    qsort(sorted, x * y, sizeof(struct Element), compare); // pakai qsort aja bawaan c tapi kalau mau pake bubble sort boleh boleh aja
    // for (int i = 0; i < x * y; i++) {
    //     printf("%d ", sorted[i].value);
    // }
    // waktunya lakon metu
    int left = 0, right = x * y - 1;
    int found = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // printf("%d %d %d\n", left, mid, right);
        // printf("%d %d %d\n", sorted[left].value, sorted[mid].value, sorted[right].value);
        if (sorted[mid].value == target) {
            printf("Element %d found at position: (%d, %d).\n", 
                   target, sorted[mid].i + 1, sorted[mid].j + 1);
            found = 1;
            break;
        }
        else if (sorted[mid].value < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    if (!found) printf("Element %d not found.\n", target);
    
    return 0;
}