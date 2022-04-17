#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;


bool existe(vector<int> fila, int x) {
    for(int i = 0; i < (int) fila.size(); i++){
        if(x == fila[i])
            return true;
    }
    return false;
}

int contar(vector<int> fila, int x) {
    int count {};
    for(int i = 0; i < (int) fila.size(); i++) {
        if(x == fila[i])
            count++;
    }
    return count;
}

int procurar(vector<int> fila, int x){
    for(int i = 0; i < (int) fila.size(); i++) {
        if(x == fila[i])
        return i;
    }
    return -1;
}

int procurar_apartir(vector<int> fila, int x, int inicio) {
    for(int i = inicio; i < (int)fila.size(); i++) {
        if(x == fila[i]){
            return i;
        }
    }
    return -1;
}

int procurar_menor(vector<int> fila) {
    int menor = { 9999999 };
    for(int i = 0; i < (int)fila.size(); i++) {
        if(menor > fila[i]){
            menor = fila[i];
        }
    }
    return menor;
}

int procurar_pos_menor(vector<int> fila) {
    int menor = { 9999999 };
    int pos = {};
    for(int i = 0; i < (int)fila.size(); i++) {
        if(menor > fila[i]){
            menor = fila[i];
            pos = i;
        }
    }
    return pos;
    
}

int procurar_pos_menor_apartir(vector<int> fila, int inicio) {
    int menor = { 9999999 };
    int pos = {};
    for(int i = inicio; i < (int)fila.size(); i++) {
        if(menor > fila[i]){
            menor = fila[i];
            pos = i;
        }
    }
    return pos;
}

int procurar_melhor_pos_se(vector<int> fila) {
    int pos = {0};
    int menor = {99999999};
    for(int i = 0; i < (int)fila.size(); i++) {
        if(menor > fila[i] && fila[i] > 0 ){
            menor = fila[i];
            pos = i;
        }
        

    }
    if(pos == 0)
        return -1;
     return pos;
}

float calcular_stress_medio(vector<int> fila) {
    float stress_medio {};
    for(int i = 0; i < (int)fila.size(); i++) {
        stress_medio += abs(fila[i]);
    }
    return stress_medio / (float) fila.size();
}

string mais_homens_ou_mulheres(vector<int> fila) {
    int count_neg = {0};
    int count_posi = {0};
    for(int i = 0;  i < (int)fila.size(); i++) {
        if(fila[i] > 0)
            count_posi++;
    }
    for(int i = 0;  i < (int)fila.size(); i++) {
        if(fila[i] < 0)
            count_neg++;
    }

    if(count_neg > count_posi)
        return "mulheres";
    if(count_neg < count_posi)
        return "homens";
    if(count_neg == count_posi)
        return "empate";
}

string metade_mais_estressada(vector<int> fila) {
   int primeira = {0};
   int segunda = {0};
   for(int i = 0;  i < (int)fila.size()/2; i++) {
        primeira += abs(fila[i]);
    }
    for(int i = (int)fila.size()/2;  i < (int)fila.size(); i++) {
        segunda += abs(fila[i]);
    }

    if(primeira > segunda)
        return "primeira";
    if(primeira < segunda)
        return "segunda";
    if(primeira == segunda)
        return "empate";
}

vector<int> clonar(const vector<int>& v) {
    vector<int> clone;
    for(int i = 0; i < (int)v.size(); i++) {
        clone.push_back(v[i]);
    }
    return clone;
    
}

vector<int> pegar_homens(const vector<int>& v) {
    vector<int> pega_homem;
    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i] > 0)
        pega_homem.push_back(v[i]);
    }
    return pega_homem;
}

vector<int> pegar_calmos(const vector<int>& v) {
    vector<int> pega_calmo;
    for(int i = 0; i < (int)v.size(); i++) {
        if(abs(v[i]) < 10)
            pega_calmo.push_back(v[i]);
    }
    return pega_calmo;
}

vector<int> pegar_mulheres_calmas(const vector<int>& v) {
    vector<int> mulher_calma;
    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i] < 0 && v[i] > -10)
            mulher_calma.push_back(v[i]);
    }
    return mulher_calma;
}

vector<int> inverter_com_copia(const vector<int>& v) {
    vector<int> copia_invertida;
    for(int i = (int)v.size(); i > 0; i--) {
        copia_invertida.push_back(v[i]);
    }
    return copia_invertida;
}

void inverter_inplace(vector<int>& v) {
    std::reverse(v.begin(), v.end());
}

int sortear(const vector<int>& v) {
    int random = rand() % v.size();
    int elem = v[random];
    return elem;
}

void embaralhar(vector<int>& v) {
    random_shuffle(v.begin(), v.end());
}

void ordenar(vector<int>& v) {
    sort(v.begin(), v.end());
}

vector<int> exclusivos(const vector<int>& v) {
    vector<int> so_exclusivos;
    int eh_igual = 0;
    for(int i = 1; i <= (int)v.size(); i++) {
        if(v[i] == v[i -1]){
            eh_igual ++;
        }
        if(eh_igual == 0)
         so_exclusivos.push_back(v[i]);
    }
    return so_exclusivos;

}

vector<int> diferentes(const vector<int>& v) {
    vector<int> so_diferentes;
    int eh_igual = 0;
    for(int i = 1; i <= (int)v.size(); i++) {
        if(v[i] == v[i -1]){
            eh_igual ++;
        }
        if(eh_igual == 0)
         so_diferentes.push_back(v[i]);
    }
    return so_diferentes;

}

vector<int> sozinhos(const vector<int>& v) {
    vector<int> so_sozinhos;
    int eh_igual = 0;
    for(int i = 1; i <= (int)v.size(); i++) {
        if(v[i] == abs(v[i -1])){
            eh_igual ++;
        }
        if(eh_igual == 0)
         so_sozinhos.push_back(v[i]);
    }
    return so_sozinhos;

}

vector<int> mais_ocorrencias(vector<int>& v) {
    vector<int> mais_ocorrencias;
    int maior = {0};
    int maior_pos = {0};
    for(int i = 0; i < (int)v.size(); i++) {
        int count = {0};
        for(int j = 0; j < (int)v.size(); j++) {
            if(v[i] == abs(v[j]))
                count++;
        }
        if(count > maior) {
            maior = count;
            maior_pos = i;
        }
    }
    mais_ocorrencias.push_back(v[maior_pos]);
    return mais_ocorrencias;
    
}

vector<int> mais_recorrentes(vector<int>& v) {
   
}

int main() {
    cout << existe({-1, -50, -99}, -1) << "\n";
    cout << contar({-1, -50, -1, -99}, -1) << "\n";
    cout << procurar({-1, -50, -1 -99}, -50) << "\n"; // 1
    cout << procurar({-1, -50, -1, -99}, 10); // -1
    cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0) << "\n"; // 2
    cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3) << "\n"; // 4
    cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << "\n"; // 4
    cout << procurar_menor({5, 3, -1, -50, -1, -99}) << "\n"; // -99
    cout << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << "\n"; // 5
    cout << procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3) << "\n"; // 3
    cout << calcular_stress_medio({5, 3, -1, -50, -1, 10}) << "\n";
    cout << procurar_melhor_pos_se({5, 3, -1, -50, -1, -99}) << "\n"; // 1
    cout << procurar_melhor_pos_se({-1, -50, -1, -99}) << "\n"; // -1
    cout << mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}) << "\n"; // "mulheres"
    cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99}) << "\n"; // "empate"
    cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99}) << "\n"; // "homens"
    cout << metade_mais_estressada({5, 3, -1, -50, -1, -99}) << "\n"; // "segunda"
    cout << metade_mais_estressada({50, 98, 2, -50, -1, -99}) << "\n"; // "empate"
    cout << metade_mais_estressada({-51, 99, 1, -50, -1, -99}); // "primeira"

    
    return 0;
    

}
