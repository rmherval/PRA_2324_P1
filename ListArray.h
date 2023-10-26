#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public  List<T>{
	private:
          T* arr;
          int max;
          int n;
          static const int MINSIZE = 2;//una vez que pongo un valor a const ya no lo puedo modificar
	public:
	  ListArray(){
	  arr = new T[MINSIZE];//reservar mem dinámica para un array de MINSIZE de elem de tipo entero
		  n = 0;
		  
		  max = MINSIZE;
	  }

	  ~ListArray(){
		  delete[] arr;
	  }
	  T operator[](int pos){
		if(pos<0 || pos>=n)
			throw std::out_of_range("La posición está fuera del rango");
		else
			return arr[pos];
	
	  }

	  
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	  out<<"List => [";
		for(int i=0; i<list.n; i++){
			out<<list.arr[i]<<" ";
		}
		out<<"]";
		return out;
	}


	  void resize(int new_size){
		T* new_arr = new T[new_size];
		for(int i=0; i<n; i++)
			new_arr[i] = arr[i];
		delete[] arr; //elimino lo que estaba apuntando pq ya no lo necesito
		arr = new_arr;//actualizar arr para que apunte donde apunta el nuevo
		max = new_size;
	}

T* get(int i) const{
	if(i<0 || i>=n){
	throw std::out_of_range("índuce fuera de rango");
	
	return &arr[i];
	}
}
	void insert(int pos, T e) override{
	  if(pos<0 || pos>n){//no válida si fuera del intervalo [0,size()]
		       throw std::out_of_range("La posición está fuera del rango");
		}

        	if (n == max) {
            		resize(max * 2); // Duplicar el tamaño si está lleno antes de la inserción
        	}

        	for (int i = n; i > pos; --i) {
            		arr[i] = arr[i - 1];  // Desplazar elementos a la derecha para hacer espacio
        	}

		arr[pos] = e;  // Insertar el nuevo elemento
		++n;  // Incrementar el número de elementos
 	        
	}
       void append(T e) override{
	 insert(n, e);
       }
		
       void prepend(T e) override{
	 insert(0,e);
       }
    
       T remove(int pos) override{
	 if(pos<0 || pos>=n){
		       throw std::out_of_range("La posición está fuera del rango");
		}
	 T aux;
	 aux = arr[pos];//guardo el valor 
        
	 for (int i = pos+1; i <= n; i++) {
            arr[i-1] = arr[i];  // Desplazar elementos a la izquierda para rellenar el hueco borrado
         }
	 
	 n--;
	 return aux;
       }
	 
  T get(int pos) override{
     if(pos<0 || pos>=n){
		       throw std::out_of_range("La posición está fuera del rango");
		}
     return arr[pos];
  }
  int search(T e) override{ 
    for(int i = 0; i<n; i++){
      if(arr[i]==e)
	return i;
    }
    return -1;
  }
    
  bool empty() override{
    return n==0;
  }
  int size() override{
    return n;
  }

};



