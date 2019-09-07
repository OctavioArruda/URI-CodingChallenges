#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int v[10005];

    // Leitura input
    cin >> n >> m;

    // Colocando o tempo que cada caixa demora para processar um itme
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int total = 0;

    // Quem fica livre primeiro fica no início da fila
    priority_queue< pair<int, int> > fila;

    for (int i = 1; i <= n; i++){

        // Coloca -i pois caso tenham dois caixas livres, o
        // de menor id deve atender
        fila.push (make_pair( 0, -i));
    }

    while(m--) {
        // Qtd itens do cliente
        int n_itens;
        cin >> n_itens;

        // Será atendido pelo caixa no início da fila
        int id = -fila.top().second;
        int livre = -fila.top().first;
        // Está atendendo e sai da fila
        fila.pop();

        // Poderá atender novamente (ficará livre)
        // Depois do tempo de atendimento dele * qt itens e -id pois
        // Caso tenha mais de um livre, o com menor id vai ter prioridade
        fila.push( make_pair(-(livre + v[id] * n_itens), -id));
        total = max(total, livre + v[id] * n_itens);
    }

    printf("%d\n", total);
}
