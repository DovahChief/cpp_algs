#ifndef avltree_H
#define avltree_H

//prubando con data tipo char
#include <iostream>

struct nodo{
	int key;
	char data;
	
	nodo* padre = nullptr;
	nodo* hijo_der = nullptr;
	nodo* hijo_izq = nullptr;
	
	nodo(int k, char d,nodo* p = nullptr, nodo* hd = nullptr, nodo* hi= nullptr)
	: key(k), data(d) {
		padre = p;
		hijo_der = hd;
		hijo_izq = hi;
	}
	
	bool es_hoja(){
		return (hijo_der == nullptr && hijo_izq == nullptr);
	}
	
	bool padre_de_uno(){
		bool x = (hijo_der != nullptr && hijo_izq == nullptr);
		bool y = (hijo_der == nullptr && hijo_izq != nullptr);
		return (x || y);
	}
	
	bool padre_de_2(){
		return (hijo_der != nullptr && hijo_izq != nullptr);
	}
	
	void print(){
		std::cout<<"nodo # "<<this->key<<" dat: "<< this->data <<std::endl;
	}
	
};

class arbol_binario {
	
private:
	nodo* raiz;
	
	//busca en que node se bede insertar un nuevo valor
	inline nodo* find_insertN(int _k){
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
	
	inline nodo* get_raiz(){return (raiz);}
	
	void inserta(int _k, char data){
		nodo* nuevo = new nodo(_k, data, nullptr, nullptr, nullptr);
		if(raiz == nullptr){
			raiz = nuevo;
			return;
		}else {
			nodo* padr = find_insertN(_k);
			nuevo->padre = padr;
			(_k > padr->key)? padr->hijo_der = nuevo : padr->hijo_izq = nuevo;
		}
	}
	
	inline nodo* binsearch(int _k){
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
	void rec_inorden(nodo* focus){
		if(focus != nullptr){
		rec_inorden( focus->hijo_izq );
		focus->print();
		rec_inorden( focus->hijo_der );
		}
	}
	
	void rec_preorden(nodo* focus){
		if(focus != nullptr){
		focus->print();
		rec_preorden( focus->hijo_izq );
		rec_preorden( focus->hijo_der );
		}
	}
	
	void rec_posorden(nodo* focus, bool borra = false){
		if(focus != nullptr){
		rec_posorden( focus->hijo_izq );
		rec_posorden( focus->hijo_der );
		
		if(!borra)
			focus->print();
		else
			delete focus;
		}
	}
	
	void find_min(nodo* focus){
		if(focus == nullptr) return;
		while(focus->hijo_izq != nullptr)
			focus = focus->hijo_izq;
		std::cout<<"----MINIMO----\t";
		focus->print();
	}
	
	void find_max(nodo* focus){
		if(focus == nullptr) return;
		while(focus->hijo_der != nullptr)
			focus = focus->hijo_der;
		std::cout<<"----MAXIMO----\t";
		focus->print();
	}
	
	
};

#endif
