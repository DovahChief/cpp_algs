#ifndef bintree_H
#define bintree_H

#include <string>
#include <iostream>
#include <vector>

template <typename T>
class nodo{
private:
        int m_llave;
        T m_objeto;
        
        nodo<T>* hijo_der;
        nodo<T>* hijo_izq;
        nodo<T>* padre;
public:
        //convertir info a template que reciba cualquier objeto
        nodo(int _llave,  T _objeto/*, nodo* p*/): m_llave(_llave), m_objeto(_objeto) {
            hijo_der = {nullptr};
            hijo_izq = {nullptr};
            padre    =  {nullptr};
        };
        
        nodo<T>* get_padre(){return (padre);}
        nodo<T>* get_hijoIZQ(){return (hijo_izq);}
        nodo<T>* get_hijoDER(){return (hijo_der);}
        
        int get_key(){ return (m_llave);}
        
        void set_hijoDER(nodo<T>* nuevo){ hijo_der = nuevo;}
        void set_hijoIZQ(nodo<T>* nuevo){ hijo_izq = nuevo;}
        void set_padre(nodo<T>* nuevo){ padre    = nuevo;}
        
        T get_data(){return (m_objeto);}
        
        bool es_raiz() {
            return (padre == nullptr);
        }
        bool tiene_hijos() {
            return (hijo_der != nullptr && hijo_izq != nullptr);
        }
        bool es_vacio(){
            return (m_objeto == NULL);
        }
};

template <typename T>
class bintree {

private:
        nodo<T>* raiz;
       
        nodo<T>* reemplaza(nodo<T>* _cambiado){
			nodo<T>* padre_sustit = _cambiado;
			nodo<T>* reemp = _cambiado;
			nodo<T>* focus = _cambiado->get_hijoDER();
			
			while(focus != nullptr){
				padre_sustit = reemp;
				reemp = focus;
				focus = focus->get_hijoDER();
			}
			
			if(reemp != _cambiado->get_hijoDER()){
				padre_sustit->set_hijoIZQ(reemp->get_hijoDER());
				reemp->set_hijoDER(_cambiado->get_hijoDER());
			}
			return reemp; 
		}     //se usa en elimina nodo
        
        
public:
		//constructor
        bintree() {raiz = nullptr;}
        nodo<T>* get_raiz(){ return (raiz); }
        //destructor
        ~bintree(){
            rec_posorden(raiz, true);
        }
        
        //recorrido post orden que elimina datos
        void borra_arbol() {
            rec_posorden(raiz, true);
            raiz = nullptr;
        }
        
        //agrega un nodo en la posicion correspondiente
        void agrega_nodo(int _k, T data){
            nodo<T>* nuevo = new nodo<T>(_k, data);
            nodo<T>* padre = nullptr;
            //caso de arbol vacio
            if(raiz == nullptr) {
                raiz = nuevo;
                return;
            } // arbol con elementos recorremos con llave
            else {
                nodo<T>* focus = raiz;
                while(true){
                    padre = focus;
                    if( _k > focus->get_key() ){
                        focus = focus->get_hijoDER();
                        if(focus == nullptr){
                            padre->set_hijoDER(nuevo);
							padre->get_hijoDER()->set_padre(nuevo);
                            return;
                        }                             
                    }else{
                        focus = focus->get_hijoIZQ();
                        if(focus == nullptr){
                            padre->set_hijoIZQ(nuevo);
							padre->get_hijoIZQ()->set_padre(nuevo);
                            return;
                        }
                    }
                }
            }            
        }

        
        //busqueda de elemento
        nodo<T>* bin_search(int _k){
            nodo<T>* focus = raiz;
			while(focus->get_key() != _k){
				focus = (_k > focus->get_key())? focus->get_hijoDER() : focus->get_hijoIZQ();
				if(focus == nullptr || focus->get_key() == _k) return (focus);
			}
        }
        
        void elimina(int _k){

			nodo<T>* focus = raiz;
            nodo<T>* padre = nullptr;

			
			while(focus->get_key() != _k){
                padre = focus;
				if(_k < focus->get_key())
					focus = focus->get_hijoIZQ();
				 else 
					focus = focus->get_hijoDER();
				if(focus == nullptr) return;
			}//fin del while
			
			//no tiene hijos
				if(!focus->tiene_hijos()){ 
					if(focus == raiz) 
						raiz = nullptr;
					else if(padre->get_hijoIZQ() == focus)
						padre->set_hijoIZQ(nullptr);
					else
						padre->set_hijoDER(nullptr);
				} //no tiene hijo derecho 
				
				else if(focus->get_hijoDER() == nullptr){ 
					if(focus ==  raiz)
						raiz = focus->get_hijoIZQ();
					else if(padre->get_hijoIZQ() == focus)
						padre->set_hijoIZQ(focus->get_hijoIZQ());
					else
						padre->set_hijoDER(focus->get_hijoIZQ());
				} //no tiene hijo izquierdo
				
				else if(focus->get_hijoIZQ() == nullptr){ 
					if(focus ==  raiz)
						raiz = focus->get_hijoDER();
					else if(padre->get_hijoIZQ() == focus)
						padre->set_hijoIZQ(focus->get_hijoDER());
					else
						padre->set_hijoDER(focus->get_hijoDER());
				} else {
					auto rm = reemplaza(focus);
					if(focus == raiz)
						raiz = rm;
					else if(padre->get_hijoIZQ() == focus)
						padre->set_hijoIZQ(rm);
					else                 
						padre->set_hijoDER(rm);
					rm->set_hijoIZQ(focus->get_hijoIZQ());
				}
        }
        
        
        //funciones de recorrido
        void rec_inorden(nodo<T>* focus){
            if(focus != nullptr){
                rec_inorden( focus->get_hijoIZQ() );
                std::cout<< focus->get_data() <<std::endl;
                rec_inorden( focus->get_hijoDER() );
            }
        }
        void rec_preorden(nodo<T>* focus){
            if(focus != nullptr){
                std::cout<< focus->get_data() <<std::endl;
                rec_preorden( focus->get_hijoIZQ() );
                rec_preorden( focus->get_hijoDER() );
            }
        }
        void rec_posorden(nodo<T>* focus, const bool borra = false){
            if(focus != nullptr){
                rec_posorden( focus->get_hijoIZQ() );
                rec_posorden( focus->get_hijoDER() );
                if(borra) {
                    delete focus;
                }else{
                    std::cout<< focus->get_data() <<std::endl;
                }
                
            }
        }
        
        
        
};

#endif
