// Punti: 100.0
int quadri(int N, long long M, int V[]) {
    int i_sx = 0, i_dx = N;
    while(i_dx - i_sx > 1){
        long long cuum = 0;
        int start_idx = 0;
        int mid = (i_sx + i_dx+1) / 2;
        //fill sliding window up to mid
        for(int i = 0; i < mid; i++)
            cuum += V[i];
        for(int i = mid; i < N; i++){
            if(cuum <= M){
                cuum += V[i];
                cuum -= V[start_idx++];
            } else
            {
                break;
            }
        }
        
        if(cuum > M)
            i_dx = mid;
        else
            i_sx = mid;
    }
    long long cuum = 0;
    int start_idx = 0;
    //fill sliding window up to i_dx
    for(int i = 0; i < i_dx; i++)
        cuum += V[i];
    for(int i = i_dx; i < N; i++){
        if(cuum <= M){
            cuum += V[i];
            cuum -= V[start_idx++];
        } else
        {
            return i_sx;
        }
    }
    if(cuum > M)
        return i_sx;
    else
        return i_dx;
}