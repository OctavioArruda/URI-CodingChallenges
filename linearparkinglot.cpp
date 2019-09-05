#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    // flag de erro:
    bool erro;
    // pilha de estacionamento:
    stack<int> estacionamento;
    int count, vagas, motoristas, c, s, max; 
 
    while(cin >> motoristas >> vagas){
        if(vagas == 0 && motoristas == 0)
            break;

        int chegada[100000] = {0};
        int saida[100000] = {0};
        estacionamento = stack<int>();

        erro = false;
        
        for(count = 1;count <= motoristas; count++){
            cin >> c >> s;

            if(count == 0 || s > max)
                max = s;

            chegada[c] = c;
            saida[s] = c;
        }

        for(count = 1; count <= max; count++){
            if(saida[count] != 0) {
                if(!estacionamento.empty() && estacionamento.top() == saida[count])
                    estacionamento.pop();
                else {
                    erro = true;
                    break;
                }
            }

            if(chegada[count] != 0){
                if(estacionamento.size() < vagas)
                    estacionamento.push(chegada[count]);
                else {
                    erro = true;
                    break;
                }    
            }
        }

        if(erro)
            cout << "Nao" << endl;
        else
            cout << "Sim" << endl;
    }
 
    return 0;
}