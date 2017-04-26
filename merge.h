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
void merge(T v[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m; //n1 y n2 numero de elementos en cada arreglo
	T L[n1], R[n2]; //declara dos arreglos temporales l y r
    for (int i = 0; i < n1; i++)  L[i] = v[l + i];//llena el arreglo de la der
    for (int j = 0; j < n2; j++)  R[j] = v[m+1+j];//llena el arreglo de la izq

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { v[k] = L[i];    i++;} //
        else              { v[k] = R[j];    j++;}
        k++;
    }
    //ciclos que copian los elementos restantes de L o R al arreglo
    while(i < n1) { v[k] = L[i];  i++;    k++; }  //ciclo de L
    while(j < n2) { v[k] = R[j];  j++;    k++; }  //coclo de R
}

#endif
