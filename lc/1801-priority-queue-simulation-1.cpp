constexpr int MOD = 1e9 + 7;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy;
        priority_queue sell{greater<>{}, vector<pair<int, int>>{}};

        return accumulate(orders.begin(), orders.end(), 0, [&](int a, auto& v) {
            auto func = [&](auto& q1, auto& q2, auto&& op) {
                while (v[1] && !q1.empty() && op(q1.top().first, v[0])) {
                    auto [price, cnt] = q1.top();
                    q1.pop();
                    auto tmp = min(cnt, v[1]);
                    v[1] -= tmp;
                    cnt -= tmp;
                    a = (a + MOD - tmp) % MOD;
                    if (cnt) q1.emplace(price, cnt);
                }
                if (v[1]) q2.emplace(v[0], v[1]);
                return (a + v[1]) % MOD;
            };
            return v[2] ? func(buy, sell, greater_equal<>{})
                        : func(sell, buy, less_equal<>{});
        });
    }
};

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        using pii = pair<int, int>;
        priority_queue<pii> buy; // 大顶堆
        priority_queue<pii, vector<pii>, greater<pii>> sell;
        int res = 0, mod = 1e9 + 7; // 用res储存当前积压的订单
        for (auto& v : orders)
            if (v[2] == 0) { // 对于一个购买数据
                while (v[1] && !sell.empty() && sell.top().first <= v[0]) {
                    // 找到要价最低的卖家
                    auto [price, amoumt] = sell.top();
                    sell.pop();
                    if (amoumt <= v[1])
                        // 如果卖的数量少，从买的里面以及res中减去
                        res = (res - amoumt + mod) % mod, v[1] -= amoumt;
                    else // 如果买的数量少，从卖的里面以及res中减去
                        sell.push({price, amoumt - v[1]}),
                            res = (res - v[1] + mod) % mod, v[1] = 0;
                }
                if (v[1]) // 如果还有剩的，加入堆以及res中
                    buy.push({v[0], v[1]}), res = (res + v[1]) % mod;
            } else { // 对于一个卖出数据
                while (v[1] && !buy.empty() && buy.top().first >= v[0]) {
                    // 找到出价最高的买家
                    auto [price, amoumt] = buy.top();
                    buy.pop();
                    if (amoumt <= v[1]) // 执行数量更少的交易
                        res = (res - amoumt + mod) % mod, v[1] -= amoumt;
                    else
                        buy.push({price, amoumt - v[1]}),
                            res = (res - v[1] + mod) % mod, v[1] = 0;
                }
                if(v[1])//如果还有剩的，加入堆以及res中
                    sell.push({v[0],v[1]}), res=(res+v[1])%mod;
            }
        return res;
    }
};