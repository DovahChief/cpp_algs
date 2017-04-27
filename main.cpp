#include <iostream>
#include "binsearc.h"
#include "merge.h"
#include "bintree.h"
#include <vector>
#include <string>

int main() {
    std::vector<int> v {9,8,7,3,6,4,1,11};
    
	
    std::cout<<"-------ordenando---------"<<std::endl;
    
    mergeSort(v);
    for(const auto& x : v){
        std::cout<<x<<std::endl;
    }
    
    int val = 12; 
    auto x = binsearch(v, val);

    
    std::cout<<"-------buscando---------"<<std::endl;
    std::cout<<((x == true)?"se encontro el ":"no se encontro el ")<<val<<std::endl;
    
	
	/*bintree<std::string> arbol;
            
    for (const auto& x : v){
        arbol.agrega_nodo(x, "nodo : "+ std::to_string(x));
    }
    
    arbol.elimina(11); //revisar funcion 
    
    std::cout<<"recorriendo arbol "<<std::endl;
    arbol.rec_inorden(arbol.get_raiz());
    */
	bintree<std::string> arbol;
	arbol.agrega_nodo(2, "nodo : 1");
	arbol.agrega_nodo(1, "nodo : 2");
//	arbol.agrega_nodo(3, "nodo : 3");
	
//	arbol.rec_inorden(arbol.get_raiz());
	
    return 0;
}
