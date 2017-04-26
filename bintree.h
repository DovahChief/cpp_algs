#ifndef bintree_H
#define bintree_H

#include <string>
#include <iostream>

struct nodo{
        int m_llave;
        std::string m_info;
        
        nodo * hijo_der = {nullptr};
        nodo * hijo_izq = {nullptr};
        
        bool tiene_hijos() {
            return (hijo_der != nullptr && hijo_izq != nullptr);
        };
};

class bintree {
    private:
        nodo* raiz;
        nodo* crea_hoja(int _v, std::string _s); //se usa en agregar nodo
        nodo* reemplaza(nodo* _cambiado);         //se usa en elimina nodo
    public:
        bintree();
        
        void agrega_nodo(int _k, std::string _nombre);
        nodo* bin_search(int _k);
        void elimina(int _k);
        void rec_inorden(nodo* focus); 
        void rec_preorden(nodo* focus);
        void rec_posorden(nodo* focus);
        
        nodo* get_raiz(){return raiz;};
        
};


#endif
