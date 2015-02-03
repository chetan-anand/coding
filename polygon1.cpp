/*************** Program Begin **********************/
long long dp[1 << 18][18];
class PolygonTraversal {
public:
    int N, start, end;
    inline int addPoint(int mask, int p)
    {
        return ( mask | (1 << p) );
    }
    bool isIntersect(int mask, int p1, int p2)
    {
        bool f1 = false, f2 = false;
        if (p1 > p2) {
            swap(p1, p2);
        }
        for (int i = 0; i < N; i++) {
            if ( mask & (1 << i) ) {
                if (i > p1 && i < p2) {
                    f1 = true;
                } else if (i < p1 || i > p2) {
                    f2 = true;
                }
            }
        }
        return f1 && f2;
    }
    long long rec(int mask, int p)
    {
        long long & res = dp[mask][p];
        if (res != -1) {
            return res;
        }
        if (mask == end) {  // base case
            if (isIntersect(mask, p, start) ) {
                res = 1;
                return 1;
            } else {
                res = 0;
                return 0;
            }
        }
        res = 0;
        for (int i = 0; i < N; i++) {
            if ( !( mask & (1 << i) ) ) { // 若点未访问
                if (isIntersect(mask, p, i)) {
                    // 若符合，加入该点
                    res += rec( addPoint(mask, i), i );
                }
            }
        }
        return res;
    }
    long long count(int N, vector <int> points) {
        long long res = 0;
        this->N = N;
        end = (1 << N) - 1;
        start = points[0] - 1;
        int mask = 0;
        for (int i = 0; i < points.size(); i++) {
            --points[i];
            mask = addPoint(mask, points[i]);
        }
        memset(dp, -1, sizeof(dp));
        res = rec(mask, points[ points.size() - 1 ]);
 
        return res;
    }
 
};