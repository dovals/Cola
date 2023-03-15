#include <iostream>
#define TAM 50
#define total 2

class Alumno{
private:
    std::string Nombre;
    std::string Nombre_Carrera;
    std::string Materias_Aprob;
    std::string Promedio;
public:
    Alumno(){};


    friend std::ostream & operator<<(std::ostream &O, Alumno &x){
            O<<"\n Nombre: "<<x.Nombre<<" Nombre Carrera: " <<x.Nombre_Carrera<<" Numero de Materias Aprobadas: "<<x.Materias_Aprob<<" Promedio: "<<x.Promedio<<std::endl;
            return O;
    }
    friend std::istream & operator>>(std::istream &O, Alumno &x){
            std::cout<<"\n Nombre: ";
            O>>x.Nombre;
            std::cout<<"\n Nombre de la Carrera: ";
            O>>x.Nombre_Carrera;
            std::cout<<"\n Total de Materias Aprobadas: ";
            O>>x.Materias_Aprob;
            std::cout<<"\n Promedio Final: ";
            O>>x.Promedio;
            return O;
    }
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;

public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
};

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            Alumno x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main()
{
    Cola<Alumno> MiCola;
    Alumno x;
    int op;
    while(true)
    {
        std::cout<<" 1.-Agregar informacion de alumno \n 2.-generar constancia"<<std::endl;
        std::cin>>op;
        switch(op)
        {
            case 1:
                std::cout<<"\n Ingresa los datos del alumno No.- "<<std::endl;
                std::cin>>x;
                MiCola.Queue(x);
            break;

            case 2:
                if(MiCola.vacia())
                {
                    std::cout<<"\n no hay solicitudes pendientes"<<std::endl;
                }
                else
                {
                    x=MiCola.Front();
                    std::cout<<x<<std::endl;
                    MiCola.Dequeue();
                }
            break;
        }
    }
    return 0;
}
