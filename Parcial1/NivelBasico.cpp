#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    cout << "Bubble Sort:" << endl;
    printArray(arr, n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                cout << "Intercambio en posiciones " << j << " y " << j+1 << ": ";
                printArray(arr, n);
            }
        }
        cout << "Ciclo " << i+1 << " completado: ";
        printArray(arr, n);
    }
}

void selectionSort(int arr[], int n) {
    cout << "Selection Sort:" << endl;
    printArray(arr, n);
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            cout << "Intercambio en posiciones " << i << " y " << minIndex << ": ";
            printArray(arr, n);
        }
        cout << "Ciclo " << i+1 << " completado: ";
        printArray(arr, n);
    }
}

void insertionSort(int arr[], int n) {
    cout << "Insertion Sort:" << endl;
    printArray(arr, n);
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
            cout << "Desplazamiento en posicion " << j+1 << ": ";
            printArray(arr, n);
        }
        arr[j + 1] = clave;
        cout << "Insercion en posicion " << j+1 << ": ";
        printArray(arr, n);
        cout << "Ciclo " << i << " completado: ";
        printArray(arr, n);
    }
}
int main() {
    char continuar;
    do {
        cout << "-----------Bienvenido al programa de ordenamiento-----------\n" << endl;
        cout << "Ingrese la cantidad de elementos: ";
        int n;
        cin >> n;
        vector<int> original(n);
        cout << "Ingrese los elementos: ";
        for(int i = 0; i < n; i++) {
            cin >> original[i];
        }
        cout << "Seleccione el tipo de ordenamiento:" << endl;
        cout << "1. Burbuja" << endl;
        cout << "2. Seleccion" << endl;
        cout << "3. Insercion" << endl;
        int opcion;
        cin >> opcion;
        switch (opcion) {
            case 1: {
                vector<int> arr = original;
                bubbleSort(arr.data(), n);
                cout << "Elementos ordenados con burbuja: ";
                for(int x : arr) cout << x << " ";
                cout << endl;
                break;
            }
            case 2: {
                vector<int> arr = original;
                selectionSort(arr.data(), n);
                cout << "Elementos ordenados con seleccion: ";
                for(int x : arr) cout << x << " ";
                cout << endl;
                break;
            }
            case 3: {
                vector<int> arr = original;
                insertionSort(arr.data(), n);
                cout << "Elementos ordenados con insercion: ";
                for(int x : arr) cout << x << " ";
                cout << endl;
                break;
            }
            default:
                cout << "Opción no valida" << endl;
        }
        cout << "¿Deseas continuar organizando archivos? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
    return 0;
}