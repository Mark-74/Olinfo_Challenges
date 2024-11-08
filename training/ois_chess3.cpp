// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {
    int test, queenPosX, queenPosY;
    fin >> test;
    for(int suca = 0; suca < test; suca++){
        char board[8][8];
        for (int i = 0; i < 8; i++) {
            for (int z = 0; z<8; z++) {
                fin >> board[i][z];
                if(board[i][z] == 'q') {
                    queenPosX = i;
                    queenPosY = z;
                }
            }
        }
        if(queenPosX +1 < 8 && queenPosY - 1 >= 0){
            if(board[queenPosX+1][queenPosY-1] == 'P'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX +1 < 8 && queenPosY +1 < 8){
            if(board[queenPosX+1][queenPosY+1] == 'P'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX-2 >= 0 && queenPosY -1 >= 0 ){
            if(board[queenPosX-2][queenPosY-1] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX-2 >= 0 && queenPosY +1 < 8 ){
            if(board[queenPosX-2][queenPosY+1] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX-1 >= 0 && queenPosY +2 < 8 ){
            if(board[queenPosX-1][queenPosY+2] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX+1 < 8 && queenPosY +2 < 8 ){
            if(board[queenPosX+1][queenPosY+2] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX+2 < 8 && queenPosY +1 < 8 ){
            if(board[queenPosX+2][queenPosY+1] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX+2 < 8 && queenPosY -1 >= 0 ){
            if(board[queenPosX+2][queenPosY-1] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX+1 < 8 && queenPosY -2 >= 0 ){
            if(board[queenPosX+1][queenPosY-2] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }
        if(queenPosX-1 >= 0 && queenPosY -2 >= 0 ){
            if(board[queenPosX-1][queenPosY-2] == 'N'){
                fout<<"YES"<<endl;
                continue;
            }
        }

        bool torre = false;
        //riga dx
        for(int i = queenPosY +1; i < 8; i++){
            if(board[queenPosX][i] != '.'){
                if(board[queenPosX][i] == 'R' || board[queenPosX][i] == 'Q'){
                    fout<<"YES"<<endl;
                    torre = true;
                    break;
                } else break; //se c'è qualcos'altro blocca il resto della fila
            }
        }
         if(torre){
             continue;
        }
        //riga sx
        for(int i = queenPosY -1; i >= 0; i--){
            if(board[queenPosX][i] != '.'){
                if(board[queenPosX][i] == 'R' || board[queenPosX][i] == 'Q'){
                    fout<<"YES"<<endl;
                    torre = true;
                    break;
                } else break; //se c'è qualcos'altro blocca il resto della fila
            }
        }
         if(torre){
             continue;
        }
        //colonna su
        for(int i = queenPosX -1; i >= 0; i--){
            if(board[i][queenPosY] != '.'){
                if(board[i][queenPosY] == 'R' || board[i][queenPosY] == 'Q'){
                    fout<<"YES"<<endl;
                    torre = true;
                    break;
                } else break; //se c'è qualcos'altro blocca il resto della fila
            }
        }
         if(torre){
             continue;
        }
        //colonna giù
        for(int i = queenPosX +1; i < 8; i++){
            if(board[i][queenPosY] != '.'){
                if(board[i][queenPosY] == 'R' || board[i][queenPosY] == 'Q'){
                    fout<<"YES"<<endl;
                    torre = true;
                    break;
                } else break; //se c'è qualcos'altro blocca il resto della fila
            }
        }
        if(torre){
             continue;
        }

        bool alfiere = false;
        //basso dx
        for(int i = 1; i < 8; i ++){
            if(queenPosX +i >= 8 || queenPosY+i >= 8 ){
                break;
            } else if(board[queenPosX+i][queenPosY+i] != '.'){
                if(board[queenPosX+i][queenPosY+i] == 'Q' || board[queenPosX+i][queenPosY+i] == 'B'){
                    fout<<"YES"<<endl;
                    alfiere = true;
                    break;
                } else break;
            }
        }
        if(alfiere){
            continue;
        }
        //alto dx
        for(int i = 1; i < 8; i ++){
            if(queenPosX -i < 0 || queenPosY+i >= 8 ){
                break;
            } else if(board[queenPosX-i][queenPosY+i] != '.'){
                if(board[queenPosX-i][queenPosY+i] == 'Q' || board[queenPosX-i][queenPosY+i] == 'B'){
                    fout<<"YES"<<endl;
                    alfiere = true;
                    break;
                } else break;
            }
        }
        if(alfiere){
            continue;
        }
        //basso sx
        for(int i = 1; i < 8; i ++){
            if(queenPosX +i >= 8 || queenPosY-i < 0 ){
                break;
            } else if(board[queenPosX+i][queenPosY-i] != '.'){
                if(board[queenPosX+i][queenPosY-i] == 'Q' || board[queenPosX+i][queenPosY-i] == 'B'){
                    fout<<"YES"<<endl;
                    alfiere = true;
                    break;
                } else break;
            }
        }
        if(alfiere){
            continue;
        }
        //alto sx
        for(int i = 1; i < 8; i ++){
            if(queenPosX -i < 0 || queenPosY -i < 0 ){
                break;
            } else if(board[queenPosX-i][queenPosY-i] != '.'){
                if(board[queenPosX-i][queenPosY-i] == 'Q' || board[queenPosX-i][queenPosY-i] == 'B'){
                    fout<<"YES"<<endl;
                    alfiere = true;
                    break;
                } else break;
            }
        }
        if(alfiere){
            continue;
        }
        
        
        //se siamo arrivati qui la regina è salva
        fout<<"NO"<<endl;
    }
   
    return 0;
}