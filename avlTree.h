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
	
	bool tiene_hijos(){
		return (!(hijo_der == nullptr && hijo_izq == nullptr));
	}
	
	bool padre_de_uno(){
		bool x = (hijo_der != nullptr && hijo_izq == nullptr);
		bool y = (hijo_der == nullptr && hijo_izq != nullptr);
		return (x || y);
	}
	
	bool padre_de_2(){
		return (hijo_der != nullptr && hijo_izq != nullptr);
	}
	
};

class arbol_binario {
	
private:
	nodo_a* raiz;
	
	//busca en que node se bede insertar un nuevo valor
	inline nodo_a* find_insertN(int _k){
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
	
	inline nodo_a* get_raiz(){return (raiz);}
	
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
	
	inline nodo_a* binsearch(int _k){
		if(_k == raiz->key) return (raiz);
		auto focus = raiz;
		while(_k != focus->key){
			focus = (_k > focus->key)? focus->hijo_der : focus->hijo_izq;
			if(focus->key == _k || focus == nullptr) return (focus);
		}
	}
	//borra un elemento del arbol
	void remueve(int _k){
		auto nod = binsearch(_k);
		
	}
	
	
  
	
	//funciones de recorrido
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
	
	void rec_posorden(nodo_a* focus, bool borra = false){
		if(focus != nullptr){
		rec_posorden( focus->hijo_izq );
		rec_posorden( focus->hijo_der );
		
		if(!borra)
			std::cout<<"nodo # "<<focus->key<<" dat: "<< focus->data <<std::endl;
		else
			delete focus;
		}
	}
	
	
};

#endif
