// Count Covered Buildings

int countCoveredBuildings(int n, int** buildings,
    int buildingsSize, int* buildingsColSize
) {
    int result=0, i, x, y, minX[n+1], maxX[n+1], minY[n+1], maxY[n+1];
    memset(minX, 0, (n+1)*sizeof(int));
    memset(maxX, 0, (n+1)*sizeof(int));
    memset(minY, 0, (n+1)*sizeof(int));
    memset(maxY, 0, (n+1)*sizeof(int));
    for(i=0; i<buildingsSize; i++) {
        x=buildings[i][0]; y=buildings[i][1];
        if(minX[y]==0||minX[y]>x){ minX[y]=x; }
        if(maxX[y]==0||maxX[y]<x){ maxX[y]=x; }
        if(minY[x]==0||minY[x]>y){ minY[x]=y; }
        if(maxY[x]==0||maxY[x]<y){ maxY[x]=y; }
    }
    for(i=0; i<buildingsSize; i++) {
        x=buildings[i][0]; y=buildings[i][1];
        if(minX[y]>=x||maxX[y]<=x){ continue; }
        if(minY[x]>=y||maxY[x]<=y){ continue; }
        result++;
    }

    return result;    
}