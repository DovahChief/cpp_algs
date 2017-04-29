#include <string>

#include "binsearc.h"
#include "merge.h"
#include "arbolBin.h"


int main() {
	
	arbol_binario arbol;
	arbol.inserta(4,'c');
	arbol.inserta(2,'d');
	arbol.inserta(6,'s');
	arbol.inserta(1,'u');
	arbol.inserta(3,'t');
	arbol.inserta(5,'C');
	arbol.inserta(7,'S');
	arbol.inserta(7,'X');
	
	std::cout<<"\n\n Buscando valor  7 : "<< (arbol.binsearch(7)) <<std::endl;
	std::cout<<" contenido de 7 : "<< (arbol.binsearch(7)) <<std::endl;
	//arbol.inserta(7,'X');
	//arbol.remueve(1);
	arbol.remueve(2);
	
	arbol.find_min(arbol.get_raiz());
	
	std::cout<<"\n\n----RECORRIDO IN-ORDEN-----"<<std::endl;
	arbol.rec_inorden(arbol.get_raiz());
	
/*
	std::cout<<"\n\n----RECORRIDO POS-ORDEN-----"<<std::endl;
	arbol.rec_posorden(arbol.get_raiz());
	std::cout<<"\n\n----RECORRIDO PRE-ORDEN-----"<<std::endl;
	arbol.rec_preorden(arbol.get_raiz());
	
	std::cout<<"\n\n Buscando valor  3 : "<< (arbol.binsearch(3))->data <<std::endl;
	
    
	 nodo_a x  {1, 'a'};
	//x.data = 'y';
	nodo_a y  {2, 'b', &x};
	nodo_a* p = new nodo_a(3,'z');
	std::cout<<std::endl<<std::endl<<"-------ordenando---------"<<std::endl<<std::endl<<std::endl;
	
	p->padre = &x;
	p->hijo_der = &x;
	p->hijo_izq = &y;
	
	
	std::cout<<"iniciando p"<<std::endl;
	std::cout<<"direccion de p "<<p<<std::endl;
	std::cout<<"valor de la llave de p "<<p->key<<std::endl;
	std::cout<<"contenido de  p "<<p->data<<std::endl;
	std::cout<<"padre de p "<<p->padre<<std::endl;
	std::cout<<"hijo derecho de  p "<<p->hijo_der<<std::endl;
	std::cout<<"hijo izquierdo de p "<< p->hijo_izq<<std::endl;
	
	if(x.padre == nullptr) std::cout<<"x no tiene padre"<<std::endl;
	
	std::cout<<std::endl<<std::endl<<"-------ordenando---------"<<std::endl<<std::endl<<std::endl;
	
	
	std::cout<<"iniciando x"<<std::endl;
	std::cout<<"direccion de x "<<&(x)<<std::endl;
	std::cout<<"valor de la llave de x "<<x.key<<std::endl;
	std::cout<<"contenido de  x "<<x.data<<std::endl;
	std::cout<<"padre de x "<<x.padre<<std::endl;
	std::cout<<"hijo derecho de  x "<<x.hijo_der<<std::endl;
	std::cout<<"hijo izquierdo de x "<< x.hijo_izq<<std::endl;
	
	if(x.padre == nullptr) std::cout<<"x no tiene padre"<<std::endl;
	
	std::cout<<std::endl<<std::endl<<"-------ordenando---------"<<std::endl<<std::endl<<std::endl;
	
	std::cout<<"iniciando y"<<std::endl;
	std::cout<<"direccion de y "<<&(y)<<std::endl;
	std::cout<<"valor de la llave de y "<<y.key<<std::endl;
	std::cout<<"contenido de  y "<<y.data<<std::endl;
	std::cout<<"padre de y "<<y.padre<<std::endl;
	std::cout<<"hijo derecho de  y "<<y.hijo_der<<std::endl;
	std::cout<<"hijo izquierdo de y "<< y.hijo_izq<<std::endl;
	
	if(y.padre == nullptr) std::cout<<"y no tiene padre"<<std::endl;
	
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
    
	
	bintree<std::string> arbol;
	arbol.inserta(2, "nodo : 1");
	arbol.inserta(1, "nodo : 2");
	arbol.inserta(3, "nodo : 3");
	arbol.rec_inorden(arbol.get_raiz());
	
*/
    return 0;
}
