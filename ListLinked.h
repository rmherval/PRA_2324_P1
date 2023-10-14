#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
      Node<T>* first;
      int n;

    public:

      ListLinked(){
	first = nullptr;
	n = 0;
      }
      ~ListLinked(){
	while(first!=nullptr){
	Node<T>* aux = first->next;
	delete first;
	first = aux;
	}
      }
      T operator[](int pos){
	if(pos<0 || pos>=n)
			throw std::out_of_range("La posición está fuera del rango");
	else{
	  Node<T>* aux = first;
	  for(int i = 0; i <pos; i++){
	    aux=aux->next;
	  }
	  return aux->data;
	}
      }
      friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
	out<<"List => [";
	Node<T>* aux = list.first;
	while(aux!=nullptr){
	    out<<aux->data<<" ";
	    aux= aux->next;
	 
	}
	out<<"]";
	return out;
      }


       void resize(int new_size){}



	void insert(int pos, T e) override{
	  if(pos<0 || pos>n){//no válida si fuera del intervalo [0,size()]
		       throw std::out_of_range("La posición está fuera del rango");
		}
	   Node<T>* new_node = new Node(e);
	  if(pos==0){//primera posición
	    new_node->next = first;
            first = new_node;
	  }
	  else{
	    int i=0;
	    Node<T>* aux = first;
	    while(aux!=nullptr && i<pos-1){
	      aux=aux->next;
	      i++;
	    }
	    if(aux!=nullptr){//estamos en pos-1
	      //aux->next=new Node<T>(e, aux->next);
	      new_node->next=aux->next;
	      aux->next=new_node;
	      
	    }
	    n++;
 	        
	}
       void append(T e) override{
	 insert(n, e);
       }
		
       void prepend(T e) override{
	 insert(0,e);
       }
    
       T remove(int pos) override{
	 if (pos < 0 || pos >= n) {
            throw std::out_of_range("La posición está fuera del rango");
        }

        Node<T>* aux = first;
        T dato;

        if (pos == 0) {
            first = aux->next;
            dato = aux->data;
            delete aux;
        } else {
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }
            Node<T>* borrar = aux->next;
            aux->next = borrar->next;
            dato = borrar->data;
            delete borrar;
        }

        n--;
        return removed_data;
    }
	 
  T get(int pos) override{
     if(pos<0 || pos>=n){
       throw std::out_of_range("La posición está fuera del rango");
     }
     if(pos==0)
       return first->data;
     else{
       Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
                aux = aux->next;
	}
	return aux->data
     
	  }
  }
  int search(T e) override{
    Node<T>* aux = first;
        for (int i = 0; i < n; i++) {
            if (aux->data == e) {
                return i;
            }
            aux = aux->next;
        }
        return -1; // Si no se encuentra
    }
    
  bool empty() override{
    return n==0;
  }
  int size() override{
    return n;
  }

	};
