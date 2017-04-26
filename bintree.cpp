#include "bintree.h"

bintree::bintree(){
    raiz = nullptr;    
};

nodo* bintree::crea_hoja(int _v, std::string _s){
    nodo* nuevo = new nodo;
    nuevo->m_llave = _v;
    nuevo->m_info = _s;
    return (nuevo);
}

//agrega un nodo en la posicion correspondiente
void bintree::agrega_nodo(int _k, std::string _nombre){
    nodo* nuevo = crea_hoja(_k, _nombre);
    if(raiz == nullptr) raiz = nuevo;
    else{
        nodo* focus = raiz;
        nodo* padre;
        
        while(true){ //ciclo recorre el arbol
            padre = focus;
            if(_k < focus->m_llave){ //si debe seguir a la izquierda
                focus = focus->hijo_izq;
                if(focus == nullptr){
                    padre->hijo_izq = nuevo;
                    return;
                }//fin del if que determina fin del arbol
            }//fin del if de recorrido a la izquierda
            else { //si a partir del nodo actual debemos movernos a la derecha
                focus = focus->hijo_der;
                if(focus == nullptr){ //cuando se llega a fin de arbol
                    padre->hijo_der = nuevo;
                    return;
                } 
            }
        }//fin del ciclo de recorrido de arbol
        
    }
    
}
//busqueda de elemento 
nodo* bintree::bin_search(int _k){
    nodo* focus = raiz;
    while(focus->m_llave != _k){
        focus = (_k > focus->m_llave)? focus->hijo_der : focus->hijo_izq;
        if(focus == nullptr || focus->m_llave == _k) return (focus);
    }
}

nodo* bintree::reemplaza(nodo* _cambiado){
    nodo* padre_sustit = _cambiado;
    nodo* reemp = _cambiado;
    nodo* focus = _cambiado->hijo_der;
    
    while(focus != nullptr){
        padre_sustit = reemp;
        reemp = focus;
        focus = focus->hijo_der;
    }
    
    if(reemp != _cambiado->hijo_der){
        padre_sustit->hijo_izq = reemp->hijo_der;
        reemp->hijo_der = _cambiado->hijo_der;
    }
    return reemp;    
}


//elimina un nodo /******REQUIERE DEBUG**********/
void bintree::elimina(int _k){
    nodo* padre = raiz;
    nodo* focus = raiz;
    bool hijo_i = 0;
    
    while(focus->m_llave != _k){
        padre = focus;
        if(_k < focus->m_llave){
            hijo_i = true;
            focus = focus->hijo_izq;
        } else {
            hijo_i = false;
            focus = focus->hijo_der;
        }
        if(focus == nullptr) return;
    }//fin del while
    
    //no tiene hijos
        if(!focus->tiene_hijos()){ 
            if(focus == raiz) raiz = nullptr;
            else if(hijo_i)   padre->hijo_izq = nullptr;
            else              padre->hijo_der = nullptr;
        } //no tiene hijo derecho 
        else if(focus->hijo_der == nullptr){ 
            if(focus ==  raiz)   raiz = focus->hijo_izq;
            else if(hijo_i)      padre->hijo_izq = focus->hijo_izq;
            else                 padre->hijo_der = focus->hijo_izq;
        } //no tiene hijo izquierdo 
        else if(focus->hijo_izq == nullptr){ 
            if(focus ==  raiz)   raiz = focus->hijo_der;
            else if(hijo_i)      padre->hijo_izq = focus->hijo_der;
            else                 padre->hijo_der = focus->hijo_der;
        } else {
            nodo* rm = reemplaza(focus);
            if(focus == raiz)    raiz = rm;
            else if(hijo_i)      padre->hijo_izq = rm;
            else                 padre->hijo_der = rm;
            rm->hijo_izq = focus->hijo_izq;
        }
    
    
}



//funciones de recorrido para el arbol
void bintree::rec_inorden(nodo* focus){
    if(focus != nullptr){
        rec_inorden( focus->hijo_izq );
        std::cout<< focus->m_info <<std::endl;
        rec_inorden( focus->hijo_der );
    }
}
void bintree::rec_preorden(nodo* focus){
    if(focus != nullptr){
        std::cout<< focus->m_info <<std::endl;
        rec_preorden( focus->hijo_izq );
        rec_preorden( focus->hijo_der );
    }
}
void bintree::rec_posorden(nodo* focus){
    if(focus != nullptr){
        rec_posorden( focus->hijo_izq );
        rec_posorden( focus->hijo_der );
        std::cout<< focus->m_info <<std::endl;
    }
}
