#ifndef structBST_H
#define structBST_H

#include <iostream>

template<typename T>
struct nodo_s {
		int m_llave;
		T m_objeto;

		nodo_s<T>* padre	  = nullptr;

		nodo_s<T>* hijo_der = nullptr;
		nodo_s<T>* hijo_izq = nullptr;
		
		nodo_s(int _k, T _obj, nodo_s<T>* p, nodo_s<T>* hd,nodo_s<T>* hi){
			m_llave = _k;
			m_objeto = _obj;
			padre = p;
			hijo_der = hd;
			hijo_izq = hi;
		}
};

template<typename T>
class binaryTree {
private:
	nodo_s<T>* raiz;
public:
	binaryTree(){
		raiz = nullptr;
		
	}
	nodo_s<T>* get_raiz(){ return (raiz); }
	~binaryTree(){ rec_posorden(raiz, true);}
	
	void borra_arbol() {
		rec_posorden(raiz, true);
		raiz = nullptr;
	}
	
	void inserta(int _k, T _data){
		nodo_s<T>  nd(_k, _data, nullptr, nullptr, nullptr);
		nodo_s<T>* n = &nd;
		nodo_s<T>* _padre = nullptr;
		if(raiz == nullptr){
			raiz = n;
			return;
		}
		else{
			nodo_s<T>* focus = raiz;
			while(true){
				_padre = focus;
				if(_k > focus->m_llave){
					focus = focus->hijo_der;
					if(focus == nullptr){
						_padre->hijo_der = n;
						_padre->hijo_der->padre = _padre;
						return;
					}
				}else{
					focus = focus->hijo_izq;
					if(focus == nullptr){
						_padre->hijo_izq = n;
						_padre->hijo_izq->padre = _padre;
						return;
					}
				}
			}
		}
	}
	
	nodo_s<T>* binsearch(int _k){
		auto focus = raiz;
		while (focus->m_llave != _k){
			focus = (_k > focus->m_llave)? focus->hijo_der : focus->hijo_izq;
			if(focus == nullptr || focus->m_llave == _k) return(focus);
		}
	}

	void rec_inorden(nodo_s<T>* focus){
            if(focus != nullptr){
                rec_inorden( focus->hijo_izq );
                std::cout<< focus->m_objeto <<std::endl;
                rec_inorden( focus->hijo_der );
            }
        }
        void rec_preorden(nodo_s<T>* focus){
            if(focus != nullptr){
                std::cout<< focus->get_data() <<std::endl;
                rec_preorden( focus->hijo_izq );
                rec_preorden( focus->hijo_der );
            }
        }
        void rec_posorden(nodo_s<T>* focus, const bool borra = false){
            if(focus != nullptr){
                rec_posorden( focus->hijo_izq );
                rec_posorden( focus->hijo_der );
                if(borra) {
                    delete focus;
                }else{
                    std::cout<< focus->m_objeto <<std::endl;
                }
                
            }
        }
};

#endif
