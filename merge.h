#ifndef merge_H
#define merge_H

#include <vector>

//protoripos
template <typename T>
void mergeSort(T v[], int l, int r);
template <typename T>
void merge(T v[], int l, int m, int r);


//diferente punto de entrada
template <typename T>
void mergeSort(std::vector<T>& vec){
     mergeSort(&vec[0], 0, (vec.size()-1) );
}

//funcion mergesort que llama a recursion hasta dividir en unidades el arreglo
template <typename T>
void mergeSort(T v[], int l, int r){
    if (l < r){
        auto m = l+(r-l)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

//funcion merge que une los arrays
template <typename T>
void merge(T arreglo[], int left, int mid, int right){
    int size_l = mid-left+1, size_r = right-mid;
	
    T LEFT[size_l], RIGHT[size_r];
    
    for (int i = 0; i < size_l; i++)  LEFT[i]  = arreglo[left +i];
    for (int i = 0; i < size_r; i++)  RIGHT[i] = arreglo[mid+1+i];

    int pos_l = 0, pos_r = 0, pos_arreglo = left;
    while (pos_l < size_l && pos_r < size_r) { //ciclo de merge
        if (LEFT[pos_l] <= RIGHT[pos_r]) {
            arreglo[pos_arreglo] = LEFT[pos_l];
            pos_l++;
        } else{
            arreglo[pos_arreglo] = RIGHT[pos_r];
            pos_r++;
        }
        pos_arreglo++;
    }//fin del ciclo de merge
    
    //si arriba no se pusieron todos los elementos de el arreglo LEFT
    while(pos_l < size_l) { 
        arreglo[pos_arreglo] = LEFT[pos_l];
        pos_arreglo++;
        pos_l++;
    }
    while(pos_r < size_r) {
        arreglo[pos_arreglo] = RIGHT[pos_r];
        pos_arreglo++; 
        pos_r++;
        
    }  //ciclo de R
}

#endif
