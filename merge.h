#ifndef merge_H
#define merge_H

#include <vector>

//protoripos
template <typename T>
void mergeSort(T arreglo[], int left, int right);

template <typename T>
void merge(T arreglo[], int left, int mid, int right);

template <typename T>
static void llenasub_arr(T arreglo[], T sub_arreglo[], int inicio, int fin);

template <typename T>
static void ciclo_merge(T arreglo[], T sub_arreglo_izq[], T sub_arreglo_der[], int inicio ,int size_l, int size_r);


//diferente punto de entrada
template <typename T>
void mergeSort(std::vector<T>& vec){
     mergeSort(&vec[0], 0, (vec.size()-1) );
}

//funcion mergesort que llama a recursion hasta dividir en unidades el arreglo
template <typename T>
void mergeSort(T arreglo[], int left, int right){
    if (left < right){
        auto mid = left+(right-left)/2;
        mergeSort(arreglo, left, mid);
        mergeSort(arreglo, mid+1, right);
        merge(arreglo, left, mid, right);
    }
}

//funcion merge que une los arrays
template <typename T>
void merge(T arreglo[], int left, int mid, int right){
    
    int size_l = mid-left+1, size_r = right-mid;
    T LEFT[size_l], RIGHT[size_r];
    
    llenasub_arr(arreglo, LEFT , left    , size_l);
    llenasub_arr(arreglo, RIGHT, (mid+1) , size_r);
    ciclo_merge(arreglo, LEFT, RIGHT, left, size_l, size_r);
    
}

template <typename T>
static void llenasub_arr(T arreglo[], T sub_arreglo[], int inicio, int fin){
    for (int i = 0; i < fin; i++)  sub_arreglo[i] = arreglo[inicio + i];
}

template <typename T>
static void ciclo_merge(T arreglo[], T sub_arreglo_izq[], T sub_arreglo_der[], int inicio, int size_l, int size_r){
    
    //pos_l posicion en el sub arreglo LEFT
    //pos_r posicion en el sub arreglo RIGHT
    
    int pos_l = 0, pos_r = 0, pos_arreglo = inicio;
    
    while (pos_l < size_l && pos_r < size_r) { //ciclo de merge
        if (sub_arreglo_izq[pos_l] <= sub_arreglo_der[pos_r]) {
            arreglo[pos_arreglo] = sub_arreglo_izq[pos_l];
            pos_l++;
        } else{
            arreglo[pos_arreglo] = sub_arreglo_der[pos_r];
            pos_r++;
        }
        pos_arreglo++;
    }//fin del ciclo de merge
    
    while(pos_l < size_l) { 
        arreglo[pos_arreglo] = sub_arreglo_izq[pos_l];
        pos_arreglo++;
        pos_l++;
    }
    while(pos_r < size_r) {
        arreglo[pos_arreglo] = sub_arreglo_der[pos_r];
        pos_arreglo++; 
        pos_r++;
        
    }
    
    
}

#endif
