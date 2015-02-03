int N;
vector<int> points;
long long dp[1<<18][18];

bool doTheyCross(int mask, int a, int b)
{
    if (a > b) {
        std::swap(a,b);
    }
    // The O(N) method:
    bool part1 = false, part2 = false;
    for (int i = 0; i < N; i++) {
        if ( mask & (1 << i) ) {
            part1 = (part1 ||  (a <  i && i <  b) );
            part2 = (part2 || !(a <= i && i <= b) );
        }
    }
    return part1 && part2;
    
    /* The O(1) method: (Not actually necessary) :
    // Create two bitmasks, one for part 1 and one for part 2
    // If there is an intersection between both bit masks and mask,
    // then the result is true:
    int part1 = ( ( ( 1<<(b - a - 1) ) - 1) << (a+1) );
    int part2 = ( (1<<N)-1 ) - part1 - (1<<a) - (1<<b) ;
    // .., a+1,  a+2, ... , b- 1
    return ( (part1&mask) && (part2&mask) );
    */
}

long long rec(int mask, int p)
{
    long long & res = dp[mask][p];
    if (res == -1) {
        if ( mask == (1<<N)-1 ) {
            res = ( doTheyCross(mask, p, points[0] ) );
        } else {
            res = 0;
            for (int q = 0; q < N; q++) {
                // If q was not visited yet and the segment creates
                // an intersection:
                if ( !(mask & (1<<q) ) && doTheyCross(mask, p,q) ) {
                    // We can use q:
                    res += rec( mask | (1<<q), q);
                }
            }
        }
    }
    return res;
}

long long count(int N, vector <int> points)
{
    memset(dp, -1, sizeof(dp));
    int mask = 0;
    for (int i=0; i < points.size(); i++) {
        points[i]--;
        mask |= ( 1 << points[i] );
    }
    this->N = N;
    this->points = points;
    return rec(mask, points[points.size() - 1] );
}