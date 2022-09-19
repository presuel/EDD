#include <iostream>
using namespace std;

struct label {
    int nro;
    int prev;
    int peso;
    int marca;
};

typedef struct label label_t;

void dijkstra ( int, int **, int, int, string[] );

void ejemplo();

int main(){
    string respuesta;
    cout << "Desea visualizar un ejemplo? (s) si, (n) no.\n";
    cout << "Respuesta: ";
    cin >> respuesta;
    if( respuesta == "s" ){
        ejemplo();
    }
    // ----------------------------------------------------------
    int numNodos;
    int origen, destino;
    int **A;    // Puntero doble (puntero a un puntero)
    cout << "========================================\n";
    cout << "Ingrese la cantidad de nodos: ";
    cin >> numNodos;
    cin.ignore();
    // Asignando memoria dinámica
    if( ( A= new int *[numNodos])== NULL ) return 1;
    string etiqueta[numNodos];
    for( int i=0; i < numNodos; i++){
        if( ( A[i]= new int [numNodos]) == NULL ) return 1;
    }
    // Inicializando a cero
    for( int i=0; i<numNodos; i++){
        for( int j=0; j<numNodos; j++){
            A[i][j]= 0;
        }
    }
    // Ingresando la matriz de adyacencia
    cout << "========================================\n";
    cout << "Ingrese las etiquetas de los nodos.\n";
    for(int i=0; i<numNodos; i++){
        cout << "Nodo " << i+1 << ": ";
        getline(cin, etiqueta[i]);
    }
    cout << "========================================\n";
    cout << "Captura de datos.\n";
    for( int i=0; i<numNodos; i++){
        cout << etiqueta[i] << ": ";
        for( int j=0; j<numNodos; j++){
            cin >> A[i][j];
        }
    }
    // Determinando ruta
    cout << "========================================\n";
    cout << "Nodos capturados:\n";
    for(int i=0; i<numNodos; i++){
        cout << i+1 << ") Nodo " << etiqueta[i] << ".\n";
    }
    cout << "========================================\n";
    cout << "Ingrese el numero del nodo origen: ";
    cin >> origen;
    cout << "Ingrese el numero del nodo destino: ";
    cin >> destino;
    // Algoritmo de Dijkstra
    dijkstra( numNodos, A, origen-1, destino-1, etiqueta);
    // Liberando memoria asignada 
    for (int i=0; i<numNodos; i++) delete A[i];
    delete [] A;
    return 0;
}

void ejemplo(){
    cout << "========================================\n";
    cout << "Ingrese la cantidad de nodos: 6\n";
    cout << "Ingrese las etiquetas de los nodos:\n";
    cout << "Nodo 1: A\n";
    cout << "Nodo 2: B\n";
    cout << "Nodo 3: C\n";
    cout << "Nodo 4: D\n";
    cout << "Nodo 5: E\n";
    cout << "Nodo 6: F\n";
    cout << "Captura de datos.\n";
    cout << "Nodo A: 0 2 5 99 99 8  <-- 99 significa 'inalcanzable desde ese nodo'\n";
    cout << "Nodo B: 2 0 99 1 99 99\n";
    cout << "Nodo C: 5 99 0 1 2 99\n";
    cout << "Nodo D: 99 1 1 0 99 5\n";
    cout << "Nodo E: 99 99 2 99 0 1\n";
    cout << "Nodo F: 8 99 99 5 1 0\n";
    cout << "========================================\n";
    cout << "Nodos capturados:\n";
    cout << "1)Nodo A.\n";
    cout << "2)Nodo B.\n";
    cout << "3)Nodo C.\n";
    cout << "4)Nodo D.\n";
    cout << "5)Nodo E.\n";
    cout << "6)Nodo F.\n";
    cout << "========================================\n";
    cout << "Ingrese nodo origen: 1\n";
    cout << "Ingrese nodo destino: 6\n";
    cout << "========================================\n";
    cout << "Ruta mas economica de A a F: A - B- D - C - E - F\n";
    cout << "Costo total: 7\n";
    cout << "========================================\n\n";
}

void dijkstra ( int N, int **A, int a, int b, string e[] ){
    label_t *Labels;
    int i, i0, j, peso;
    int *ruta;
    if(( Labels= new label_t[N])==NULL) return;
    if( a<0 || a>N-1 ) return;
    if( b<0 || b>N-1 ) return;
    for(i=0; i<N; i++){
        Labels[i].nro= i;
        if( i!= a ){
            Labels[i].prev= -1;
            Labels[i].peso= -1;
            Labels[i].marca= 0;
        } else {
            Labels[i].prev= -1;
            Labels[i].peso= 0;
            Labels[i].marca= 0;
        }
    }
    //
    while(1){
        peso= -1;
        i0= -1;
        for( i=0; i<N; i++ ){
            if( Labels[i].marca == 0 && Labels[i].peso >= 0 ){
                if( peso == -1){
                    peso= Labels[i].peso;
                    i0= i;
                } else if ( Labels[i].peso <= peso ){
                    peso= Labels[i].peso;
                    i0= i;
                }
            }
        }
        if( i0 == -1){ // Ya no quedan nodos por analizar.
            break;
        }
        for( i=0; i<N; i++ ){
            if( A[i0][i] > 0 ){
                if( Labels[i].peso == -1 || Labels[i0].peso + A[i0][i] < Labels[i].peso ){
                    Labels[i].peso= Labels[i0].peso + A[i0][i];
                    Labels[i].prev= i0;
                }
            }
        }
        Labels[i0].marca = 1;   //  nodo i0 marcado
    }
    // ------------------------------------- Ruta desde origen hasta destino
    int longitud= 2;
    i=b;
    while( ( i= Labels[i].prev ) != a ){
        longitud++;
    }
    if( ( ruta = new int[longitud] ) == NULL ){
        return;
    }
    ruta[longitud-1]= b;
    i= b;
    j= 0;
    for( j= 1; j < longitud; j++ ){
        i= Labels[i].prev;
        ruta[longitud-j-1]= i;
    }
    cout << "========================================\n";    
    cout << "Ruta mas economica de " << e[a] << " a " << e[b] << ": ";
    for(i=0; i<longitud; i++){
        cout << e[ ruta[i] ];
        if(i<longitud-1){
            cout << " - ";
        } 
    }
    cout << "\nCosto total: " << Labels[b].peso << "\n\n";
    cout << "========================================\n";   
    delete ruta;
    delete [] Labels;
}