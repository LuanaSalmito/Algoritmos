#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    int n, kk;
    while (cin >> n >> kk){
        int notas[n];
        for (int i=0 ; i<n ; ++i)
            cin >> notas[i];
        vector<double> medias;
        for (int i=0 ; i<n ; ++i)
            for (int j=i+1 ; j<n ; ++j)
                for (int k=j+1 ; k<n ; ++k){
                    double media = (notas[i]+notas[j]+notas[k])/3.0;
                    medias.push_back(media);
                }
        sort(medias.begin(), medias.end());
        cout << fixed << setprecision(1) << medias[medias.size()-kk] << endl;
    }
    return 0;
}