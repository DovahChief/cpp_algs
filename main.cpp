#include <iostream>
#include "binsearc.h"
#include "merge.h"
#include "bintree.h"
#include <vector>


int main() {
    std::vector<int> v {9,8,7,3,6,4,1,11};
    bintree arbol;
            
    for (auto&& x : v){
        arbol.agrega_nodo(x, "nodo : "+ std::to_string(x));
    }
    arbol.elimina(1); //revisar funcion 
    
    std::cout<<"recorriendo arbol "<<std::endl;
    arbol.rec_inorden(arbol.get_raiz());
    
    std::cout<<"-------ordenando---------"<<std::endl;
    
    mergeSort(v);
    for(auto&& x : v){
        std::cout<<x<<std::endl;
    }
    
    int val = 12; 
    auto x = binsearch(v, val);
   
    std::cout<<""<<std::endl;
    int a[] {0,1,2,3,4,5,6};
    int s[] {0,0,0};
    llenasub_arr(a, s, 0 , 2);
    
    std::cout<<"-------buscando---------"<<std::endl;
    std::cout<<((x == true)?"se encontro el ":"no se encontro el ")<<val<<std::endl;
    
    return 0;
}
