// Furthest Point From Origin

int furthestDistanceFromOrigin(char* moves) {
    int countL = 0 , countR = 0 , count_ = 0;
    for(int i = 0 ; moves[i] ; i++){
        countL += (moves[i] == 'L');
        countR += (moves[i] == 'R');
        count_ += (moves[i] == '_');
    }
    int result = (countL > countR) ?
     countL - countR : 
     countR - countL;
    return result + count_;
}