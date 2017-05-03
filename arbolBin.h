#ifndef arbbin_H
#define arbbin_H_H

//prubando con data tipo char
#include <iostream>

template<typename T>
struct nodo{
	int key;
	T data;
	
	nodo<T>* padre = nullptr;
	nodo<T>* hijo_der = nullptr;
	nodo<T>* hijo_izq = nullptr;
	
	nodo(int k, char d,nodo<T>* p = nullptr, nodo<T>* hd = nullptr, nodo<T>* hi= nullptr)
	: key(k), data(d) {
		padre = p;
		hijo_der = hd;
		hijo_izq = hi;
	}
	
	
	bool es_hoja(){
		return (hijo_der == nullptr && hijo_izq == nullptr);
	}
	/*
	bool padre_de_uno(){
		bool x = (hijo_der != nullptr && hijo_izq == nullptr);
		bool y = (hijo_der == nullptr && hijo_izq != nullptr);
		return (x || y);
	}
	
	bool padre_de_2(){
		return (hijo_der != nullptr && hijo_izq != nullptr);
	}
	*/
	void print(){
		std::cout<<"nodo # "<<this->key<<" dat: "<< this->data <<std::endl;
	}

};

template<typename T>
class arbol_binario {
	
private:
	nodo<T>* raiz;
	
	//busca en que node se bede insertar un nuevo valor
	inline nodo<T>* find_insertN(int _k){
		auto focus = raiz;
		auto pad = focus;
		while(true){
			pad = focus;
			focus = (_k > focus->key)? focus->hijo_der : focus->hijo_izq;
			if(focus == nullptr) return(pad);
		}
	}
///////////////////////
	inline nodo<T>* Delete(nodo<T>* nod, int _k){
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
				nodo<T>* temp = nod;
				nod = nod->hijo_der;
				delete temp;
			}else if(nod->hijo_der == nullptr){
				nodo<T>* temp = nod;
				nod = nod->hijo_izq;
				delete temp;
			} //dos hijos 
				//cambiando por min right subtree (puede ser max en left subtree)
			else {
				nodo<T>* temp = find_min(nod->hijo_der);
				nod->data = temp->data; 
				nod->key = temp->key;
				nod->hijo_der = Delete(nod->hijo_der, temp->key);
			}
		}
		
		return nod;
	}	
	
public:
	
	arbol_binario(){
		raiz = nullptr;
	}
	
	inline nodo<T>* get_raiz(){return (raiz);}
	
	nodo<T>* binsearch(int _k){
		
		if(raiz == nullptr || _k == raiz->key) return (raiz);
		nodo<T>* focus = raiz;
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
		nodo<T>* nuevo = new nodo<T>(_k, data, nullptr, nullptr, nullptr);
		if(raiz == nullptr){
			raiz = nuevo;
			return;
		}else {
			nodo<T>* padr = find_insertN(_k);
			if(padr == nullptr) return;
			nuevo->padre = padr;
			(_k > padr->key)? padr->hijo_der = nuevo : padr->hijo_izq = nuevo;
		}
	}
	
	
	//borra un elemento del arbol
	void remueve(int _k){
		Delete(raiz, _k);
	}

	//funciones de recorrido
	void rec_inorden(nodo<T>* focus){
		if(focus != nullptr){
			rec_inorden( focus->hijo_izq );
			focus->print();
			rec_inorden( focus->hijo_der );
		}
	}
	
	void rec_preorden(nodo<T>* focus){
		if(focus != nullptr){
			focus->print();
			rec_preorden( focus->hijo_izq );
			rec_preorden( focus->hijo_der );
		}
	}
	
	void rec_posorden(nodo<T>* focus, bool borra = false){
		if(focus != nullptr){
		rec_posorden( focus->hijo_izq );
		rec_posorden( focus->hijo_der );
		
		if(!borra)
			focus->print();
		else
			delete focus;
		}
	}
	
	nodo<T>* find_min(nodo<T>* focus){
		if(focus == nullptr) return (nullptr);
		while(focus->hijo_izq != nullptr)
			focus = focus->hijo_izq;
		//focus->print();
		return (focus);
	}
	
	nodo<T>* find_max(nodo<T>* focus){
		if(focus == nullptr) return (nullptr);
		while(focus->hijo_der != nullptr)
			focus = focus->hijo_der;
		//focus->print();
		return (focus);
	}
	
	
};

#endif
