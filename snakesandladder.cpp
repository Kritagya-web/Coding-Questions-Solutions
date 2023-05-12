// Implemented by Kritagya Kumra
int minDiceThrowToLastCell(int **board, int n);
{
    int n = board.size();
    // reconstruct board to 1D array
    vector<int> g(n * n + 1);
    for (int i = n - 1, k = 1, d = 1; i >= 0; i--, d ^= 1)
    {
        if (d % 2 == 0)
        {
            // if the direction is even,
            // we iterate columns from the right to the left
            // e.g. 12 <- 11 <- 10 <- 9 <- 8 <- 7
            for (int j = n - 1; j >= 0; j--)
            {
                g[k++] = board[i][j];
            }
        }
        else
        {
            // if the direction is odd,
            // we iterate columns from the left to the right
            // e.g. 1 -> 2 -> 3 -> 4 -> 5 -> 6
            for (int j = 0; j < n; j++)
            {
                g[k++] = board[i][j];
            }
        }
    }
    // dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1}); // {dist, pos}
    unordered_map<int, int> vis;
    while (!q.empty())
    {
        auto [dist, cur_pos] = q.top();
        q.pop();
        // skip if the current position is visited and the dist is greater than that
        if (vis.count(cur_pos) && dist >= vis[cur_pos])
            continue;
        // if the current position reaches the square, return dist
        if (cur_pos == n * n)
            return dist;
        // we need `dist` to reach `cur_pos`
        vis[cur_pos] = dist;
        // we can have at most 6 destinations, try each step
        for (int i = 1; i <= 6; i++)
        {
            // since we reconstruct the input as a 1D array,
            // we can calculate next_pos by adding `i` to `cur_pos`
            int next_pos = cur_pos + i;
            // skip if it is out of bound
            // e.g. in 34, you can only go to 35 and 36, not any cells after 36 (see example 1)
            if (next_pos > n * n)
                continue;
            // if the next position is -1, then we can go there
            if (g[next_pos] == -1)
            {
                q.push({dist + 1, next_pos});
            }
            else
            {
                // otherwise, there is a ladder / snake which leads to `g[next_pos]`
                q.push({dist + 1, g[next_pos]});
            }
        }
    }
    // not possible to reach the square
    return -1;
}
// Implemented by Kritagya Kumra