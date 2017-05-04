#ifndef avltree_H
#define avltree_H

//prubando con data tipo char
#include <iostream>

enum recorrido{ INORDEN, PREORDEN, POSORDEN};

template<typename T>
struct nodo_a {
	int key;
	int heigth;
	T data;
	
	   nodo_a<T>* padre = nullptr;
	   nodo_a<T>* hijo_der = nullptr;
	   nodo_a<T>* hijo_izq = nullptr;
	
	nodo_a(int k,int _h, char d,nodo_a<T>* p = nullptr, nodo_a<T>* hd = nullptr, nodo_a<T>* hi= nullptr)
	: key(k),heigth(_h), data(d) {
		padre = p;
		hijo_der = hd;
		hijo_izq = hi;
	}
	
	
	bool es_hoja(){
		return (hijo_der == nullptr && hijo_izq == nullptr);
	}
	
	void print(){
		std::cout<<"nodo # "<<this->key<<" dat: "<< this->data 
		<<" altura: "<<this->heigth<<std::endl;
	}

};

template<typename T>
class alvTree {
	
private:
	   nodo_a<T>* raiz;
	
	//busca en que node se bede insertar un nuevo valor
	inline nodo_a<T>* find_insertN(int _k){
		auto focus = raiz;
		auto pad = focus;
		while(true){
			pad = focus;
			focus = (_k > focus->key)? focus->hijo_der : focus->hijo_izq;
			if(focus == nullptr) return(pad);
		}
	}

	inline nodo_a<T>* Delete(nodo_a<T>* nod, int _k){
		if(nod == nullptr) return (nullptr);
		
		else if(_k < nod->key) nod->hijo_izq = Delete(nod->hijo_izq, _k);
		else if(_k > nod->key) nod->hijo_der = Delete(nod->hijo_der, _k);
		else{
			//es hoja del arbol
			if(nod->es_hoja()){
				delete nod;
				nod = nullptr;
			}
			//caso de un hijo
			else if(nod->hijo_izq == nullptr){
				            nodo_a<T>* temp = nod;
				nod = nod->hijo_der;
				delete temp;
			}else if(nod->hijo_der == nullptr){
				            nodo_a<T>* temp = nod;
				nod = nod->hijo_izq;
				delete temp;
			} //dos hijos 
				//cambiando por min right subtree (puede ser max en left subtree)
			else {
				nodo_a<T>* temp = find_min(nod->hijo_der);
				nod->data = temp->data; 
				nod->key = temp->key;
				nod->hijo_der = Delete(nod->hijo_der, temp->key);
			}
		}
		
		return nod;
	}
	
	void actualiza_height(nodo_a<T>* focus){
		int h = 0;
		while(focus != nullptr){
			focus->heigth = h; h++;
			focus = focus->padre;
		}
	}

public:
	
	alvTree(){
		raiz = nullptr;
	}
	~alvTree(){
		recorre(raiz,POSORDEN, true);
	}
	
	inline nodo_a<T>* get_raiz(){return (raiz);}
	
	   nodo_a<T>* binsearch(int _k){
		
		if(raiz == nullptr || _k == raiz->key) return (raiz);
		      nodo_a<T>* focus = raiz;
		while(_k != focus->key){
			focus = (_k > focus->key)? focus->hijo_der : focus->hijo_izq;
			if(focus == nullptr ||focus->key == _k ) return (focus);
		}
	}
	
	void inserta(int _k, T data){
		if(binsearch(_k) != nullptr){
			std::cout<<"Ya existe un elemento con la llave que elegiste"<<std::endl;
			return;
		}
		nodo_a<T>* nuevo = new nodo_a<T>(_k, 0, data, nullptr, nullptr, nullptr);
		if(raiz == nullptr){
			raiz = nuevo;
			return;
		}else {
			nodo_a<T>* padr = find_insertN(_k);
			if(padr == nullptr) return;
			nuevo->padre = padr;
			actualiza_height(nuevo);
			(_k > padr->key)? padr->hijo_der = nuevo : padr->hijo_izq = nuevo;
		}
		
		balancea(raiz);
	}
	
	
	//borra un elemento del arbol
	void remueve(int _k){
		Delete(raiz, _k);
	}

	//funciones de recorrido

	void recorre(nodo_a<T>* focus, recorrido tr = INORDEN, bool borra = false){
		if(focus != nullptr){
			if(tr == PREORDEN) focus->print();
			recorre( focus->hijo_izq, tr, borra);
			if(tr == INORDEN) focus->print();
			recorre( focus->hijo_der, tr, borra);
			if(tr == POSORDEN && !borra) focus->print();
			if(borra) delete focus;
		}
	}
	
	   nodo_a<T>* find_min(nodo_a<T>* focus){
		if(focus == nullptr) return (nullptr);
		while(focus->hijo_izq != nullptr)
			focus = focus->hijo_izq;
		//focus->print();
		return (focus);
	}
	
	   nodo_a<T>* find_max(nodo_a<T>* focus){
		if(focus == nullptr) return (nullptr);
		while(focus->hijo_der != nullptr)
			focus = focus->hijo_der;
		//focus->print();
		return (focus);
	}
	
	
};

#endif
