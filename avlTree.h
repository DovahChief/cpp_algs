#ifndef avltree_H
#define avltree_H

//prubando con data tipo char
#include <iostream>

struct nodo_a{
	int key;
	char data;
	
	nodo_a* padre = nullptr;
	nodo_a* hijo_der = nullptr;
	nodo_a* hijo_izq = nullptr;
	
	nodo_a(int k, char d,nodo_a* p = nullptr, nodo_a* hd = nullptr,nodo_a* hi= nullptr)
	: key(k), data(d) {
		padre = p;
		hijo_der = hd;
		hijo_izq = hi;
	}
};

class arbol_binario {
	
private:
	nodo_a* raiz;
	
	//busca en que node se bede insertar un nuevo valor
	nodo_a* find_insertN(int _k){
		auto focus = raiz;
		auto pad = focus;
		while(true){
			pad = focus;
			focus = (_k > focus->key)? focus->hijo_der : focus->hijo_izq;
			if(focus == nullptr) return(pad);
		}
	}
	
public:
	
	arbol_binario(){
		raiz = nullptr;
	}
	
	nodo_a* get_raiz(){return (raiz);}
	
	void inserta(int _k, char data){
		nodo_a* nuevo = new nodo_a(_k, data, nullptr, nullptr, nullptr);
		if(raiz == nullptr){
			raiz = nuevo;
			return;
		}else {
			nodo_a* padr = find_insertN(_k);
			nuevo->padre = padr;
			(_k > padr->key)? padr->hijo_der = nuevo : padr->hijo_izq = nuevo;
		}
	}
	
	void remueve(){
		
	}
	
	void rec_inorden(nodo_a* focus){
		if(focus != nullptr){
		rec_inorden( focus->hijo_izq );
		std::cout<<"nodo # "<<focus->key<<" dat: "<< focus->data <<std::endl;
		rec_inorden( focus->hijo_der );
		}
	}
	
	void rec_preorden(nodo_a* focus){
		if(focus != nullptr){
		std::cout<<"nodo # "<<focus->key<<" dat: "<< focus->data <<std::endl;
		rec_preorden( focus->hijo_izq );
		rec_preorden( focus->hijo_der );
		}
	}
	
	void rec_posorden(nodo_a* focus){
		if(focus != nullptr){
		rec_posorden( focus->hijo_izq );
		rec_posorden( focus->hijo_der );
		std::cout<<"nodo # "<<focus->key<<" dat: "<< focus->data <<std::endl;
		}
	}
	
	
};

#endif
