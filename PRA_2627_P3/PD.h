#ifndef PD_H
#define PD_H

#include <vector>
#include <limits>    
#include <algorithm>

const int inf_val = std::numeric_limits<int>::max();


void monedas(const std::vector<int>& m, int d, std::vector<int>& s) {
    int n = m.size();
    
    
    std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, inf_val));
    
    T[0][0] = 0;
    
    
    for (int j = 1; j <= d; ++j) {
        if (j >= m[0] && T[0][j - m[0]] != inf_val) {
            T[0][j] = 1 + T[0][j - m[0]];
        }
    }
    
    
    for (int i = 1; i < n; ++i) {
        T[i][0] = 0;
        for (int j = 1; j <= d; ++j) {
            if (j < m[i] || T[i][j - m[i]] == inf_val) {
                T[i][j] = T[i - 1][j];
            } else if (T[i - 1][j] != inf_val) {
                T[i][j] = std::min(T[i - 1][j], 1 + T[i][j - m[i]]);
            } else {
                T[i][j] = 1 + T[i][j - m[i]];
            }
        }
    }
    
    
    s.assign(n, 0); 
    int i = n - 1;
    int j = d;
    
    
    while (j > 0) {
        if (i == 0 || T[i][j] != T[i - 1][j]) {
            s[i] = s[i] + 1;
            j = j - m[i];
        } else {
            i = i - 1;
        }
    }
}

// 2. PROBLEMA DE LA MOCHILA
int mochila(const std::vector<int>& p, const std::vector<int>& b, int m, std::vector<int>& s) {
    int n = p.size();
    
 
    std::vector<std::vector<int>> g(n, std::vector<int>(m + 1, 0));
    
  
    for (int C = 0; C <= m; ++C) {
        if (p[0] <= C) {
            g[0][C] = b[0];
        }
    }
    
    
    for (int i = 1; i < n; ++i) {
        for (int C = 0; C <= m; ++C) {
            if (p[i] > C) {
                
                g[i][C] = g[i - 1][C];
            } else {
                
                g[i][C] = std::max(g[i - 1][C], g[i - 1][C - p[i]] + b[i]);
            }
        }
    }
    
    
    s.assign(n, 0);
    int C = m;
    
   
    for (int i = n - 1; i > 0; --i) {
        
        if (g[i][C] != g[i - 1][C]) {
            s[i] = 1;          
            C = C - p[i];    
        }
    }
    
    
    if (C >= p[0] && g[0][C] == b[0]) {
        s[0] = 1;
    }
    
    
    return g[n - 1][m];
}


#endif
