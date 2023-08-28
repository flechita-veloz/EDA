#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define pb push_back
#define endl "\n"
using namespace std;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pii> vpi;
typedef vector<double> vd;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

vector<vd> generarPuntosAleatorios(int dimension, int numPuntos){
    vector<vd> puntos(numPuntos, vd(dimension));
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0,1.0);
    for(int i= 0; i< numPuntos; i++){
        for(int j= 0; j< dimension; j++){
            puntos[i][j]= distribution(generator);
        }
    }
    return puntos;
}

double calcularDistancia(vd &punto1, vd &punto2){
    double dist= 0.0;
    for(int i= 0; i< punto1.size(); i++){
        dist+= pow(punto1[i]-punto2[i],2);
    }
    return sqrt(dist);
}

void solve(){
    vi dimensiones= {10,50,100,500,1000};
    int numPuntos= 100;
    for(int dim:dimensiones){
        vector<vd> puntos= generarPuntosAleatorios(dim,numPuntos);
        vd distancias;
        for(int i= 0; i< numPuntos; i++){
            for(int j= i+1; j< numPuntos; j++){
                double distancia= calcularDistancia(puntos[i],puntos[j]);
                distancias.pb(distancia);
            }
        }
        string _s= to_string(dim);
        string nombreArchivo= "distancias";
        nombreArchivo+= _s+".txt";
        ofstream archivoSalida(nombreArchivo);
        if (!archivoSalida.is_open()) {
            cout << "Error al abrir el archivo." << endl;
            return;
        }
        for (double distancia : distancias) {
            archivoSalida << fixed<< setprecision(1)<<distancia << endl; 
        }
        archivoSalida.close();
        cout<<nombreArchivo<<" listo"<<endl;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; t= 1; //cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
 