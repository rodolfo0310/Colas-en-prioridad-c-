#include <iostream>
using namespace std;



//Esta estructura es para que podamos manejar las colas ordinarias, sin prioridad.
struct Nodo{
  char dato;
  int prioridad;
  Nodo *siguiente;

};

//Esta estructura es para que se puedan manejar las colas con prioridad.
struct Nodo *crearNuevoNodo(char Dato, int Prioridad){
  struct Nodo*nuevoNodo = new(struct Nodo);
  nuevoNodo -> dato= Dato;
  nuevoNodo ->prioridad = Prioridad;
  return nuevoNodo;
};
//Prototipos de las funciones.
void insertarCola(Nodo *& Inicio, Nodo *& Fin, int numero, int prioridad);
bool colaVaciaONo(Nodo *);
void ordenarPrioridad(Nodo *&Inicio, Nodo *&Fin);
void EliminarColaenrioridad(Nodo *&Incion, Nodo*&Fin, Nodo *&,int &);
void  muestraColaCompleta(Nodo *&Inicio);
void Menu();


int main() {

  Menu();

}

//Definición de las funciones.
void insertarCola(Nodo *& Inicio, Nodo *& Fin, char Dato, int Prioridad){
     struct Nodo *auxiliar = crearNuevoNodo(Dato, Prioridad);
     auxiliar->siguiente = NULL;
     Nodo *nuevo_nodo = new Nodo();
     nuevo_nodo -> dato = Dato;
     nuevo_nodo -> siguiente = NULL;

      if(colaVaciaONo(Inicio)){
          Inicio = auxiliar;
          }

   else{
     Fin -> siguiente = auxiliar;
   }

   Fin = auxiliar;
   ordenarPrioridad(Inicio, Fin);

}



bool colaVaciaONo(Nodo *frente){
     //Vamos a determinar si la cola está vacía o no.
     return(frente == NULL)? true: false;
     //Vamos a hacer el condicional más acortado.
}

//Esta función es utilizada par que cada vez que se haga una inserción o una eliminación, la cola
//se pueda ordenar en base a la prioridad que el usuario le haya dado.
void ordenarPrioridad(Nodo *& Inicio, Nodo *& Fin)
{
     struct Nodo *aux1, *aux2;
     int prioridad_aux;
     char dato_aux;
     
     aux1 = Inicio;
     
     while( aux1->siguiente != NULL)
     {
            aux2 = aux1->siguiente;
            
            while( aux2 != NULL)
            {
                   if( aux1->prioridad > aux2->prioridad )
                   {
                       prioridad_aux = aux1->prioridad;
                       dato_aux = aux1->dato;
                       
                       aux1->prioridad = aux2->prioridad;
                       aux1->dato   = aux2->dato;
                       
                       aux2->prioridad = prioridad_aux;
                       aux2->dato   = dato_aux;
                   }
                   
                   aux2 = aux2->siguiente;
            }
            
            aux1 = aux1->siguiente;
     }
}

void  muestraColaCompleta(Nodo *&Inicio){
  struct Nodo*auxiliar;
  auxiliar = Inicio;

   cout << " Caracter con Prioridad " << endl;
     cout << " ------------------- " << endl;
      while( auxiliar != NULL )
     {
            cout<<"    "<< auxiliar->dato << "     |   " << auxiliar->prioridad << endl;
            auxiliar = auxiliar->siguiente;
     }   
}

void Menu(){
   Nodo *frente = NULL;
   Nodo *fin = NULL;
   char dato;
   int Prioridad;
   int opcion;

   do{
      cout << "--------------------------------" << endl;
      cout << "----Menú-Colas--Con-Prioridad---"<< endl;
      cout << "--------------------------------" << endl;
      cout << "Opción 1: Insertar un elemento en la cola con prioridad" << endl;
      cout << "Opción 2: Mostrar los elementos de la cola con prioridad" << endl;
      cout << "Opción 3: Eliminar cola en prioridad" << endl;
      cout << "Opción 4: Salir" << endl;
      cout << "Elija su opción dentro de los parametros: ";
      cin  >> opcion;
      

      switch(opcion){

        case 1:
              cout << "Ingrese un carácter para la cola con prioridad: ";
              cin >> dato;
              cout << "Ingrese un número para darle mayor o menor prioridad a la cola: ";
              cin >> Prioridad;

              insertarCola(frente, fin,dato, Prioridad);

              cout << "Elementos insertados con éxito" << endl;
        break;
        case 2:
              if(frente != NULL)
                muestraColaCompleta(frente);
              else
                 cout << "Cola Con Prioridad Vacía!!" << endl;
         break;
        case 3:
              cout << "Dijite el caracter de prioridad que desea eliminar ";
              cin >> dato;
              cout << "Cola eliminada con exito: ";
              cin >> Prioridad;

            
        break;

        case 4: break;
        default:
                cout << "La opción que escogió no está dentro del Menú" << endl;
                system("pause");
                exit(0);
        break;

      }
       cout<<"Presione enter para continuar...";
               //La ejecución del programa se detiene hasta que no se presione la tecla enter.
        //Esto es lo hago porque el servidor está alojado en un so Linux y este no admite el system("pause");
       cin.ignore().get();
       system("clear");

   }while(opcion != 3);
   
}

//Funcion para eliminar cola
void EliminarColaenprioridad(Nodo *&Inicio, Nodo *&Fin, int &n){

  n = Inicio->dato;
  Nodo *aux = Inicio;

  if(Inicio == Fin){
     Inicio = NULL;
     Fin = NULL;
  }
  else{
    Inicio = Inicio->siguiente;
  }
  delete Inicio;
}
