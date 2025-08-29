#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/

// ---- Prototipos ----
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    printf("Ingresa el numero de arreglos: ");
    scanf("%d", &n);  // Leer el número de arreglos

    int total = n * n;
    int *arr = (int *)malloc(total * sizeof(int));

    // Leer n arreglos de tamaño n
    printf("Ingresa los valores de los arreglos: \n");
    for (int i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

// ---- Implementa aquí tu función mergeSort ----
void mergeSort(int arr[], int left, int right) {
    if (left >= right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid +1, right);
    merge(arr, left, mid, right);
}

// ---- Implementa aquí tu función merge ----
void merge(int arr[], int left, int mid, int right) {
    int nleft = mid -left+1;
    int nright = right -mid;
    int *arrleft = (int *)malloc(nleft * sizeof(int));
    int *arrright = (int *)malloc(nright * sizeof(int));
    for (int i = 0; i < nleft; i++) {
        arrleft[i] = arr[left+i];
    }
    for (int j = 0; j < nright; j++) {
        arrright[j] = arr[j+mid+1];
    }
    int i = 0, j = 0, k = left;
    while (i < nleft && j < nright) {
        if (arrleft[i] < arrright[j]){
            arr[k] = arrleft[i];
            i++;
        }else{
            arr[k] = arrright[j];
            j++;
        }
        k++;
    }
    while (i < nleft) {
        arr[k] = arrleft[i];
        i++;
        k++;
    }
    while (j < nright) {
        arr[k] = arrright[j];
        j++;
        k++;
    }
    return;
}
