class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A)*(D-B) + (G-E)*(H-F);
        
        if(C <= E || H <= B || G <= A || D <= F) {
            return area;
        } 
        return area-(min(G, C)-max(A, E))*(min(H, D)-max(B, F));
    }
};