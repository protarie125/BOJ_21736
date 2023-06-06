#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto Inf = int{ 987'654'321 };

int n, m;
vector<string> field;
pii start;

const auto dx = vi{ -1,1,0,0 };
const auto dy = vi{ 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;
	field = vector<string>(n);
	for (auto i = 0; i < n; ++i) {
		cin >> field[i];
		for (auto j = 0; j < m; ++j) {
			if ('I' == field[i][j]) {
				start = { i, j };
			}
		}
	}

	auto dist = vvi(n, vi(m, Inf));
	dist[start.first][start.second] = 0;

	using Node = pair<int, pii>;
	auto q = priority_queue<Node, vector<Node>, greater<Node>>{};
	q.push({ 0, start });

	auto ans = int{ 0 };
	while (!q.empty()) {
		const auto [dw, pos] = q.top();
		q.pop();

		const auto& [y, x] = pos;

		if ('P' == field[y][x]) {
			++ans;
		}

		for (auto d = 0; d < 4; ++d) {
			const auto nx = x + dx[d];
			const auto ny = y + dy[d];

			if (nx < 0 || m <= nx ||
				ny < 0 || n <= ny) {
				continue;
			}

			if ('X' == field[ny][nx]) {
				continue;
			}

			const auto ndist = dist[y][x] + 1;
			if (ndist < dist[ny][nx]) {
				dist[ny][nx] = ndist;
				q.push({ ndist, {ny, nx} });
			}
		}
	}

	if (0 == ans) {
		cout << "TT";
	}
	else {
		cout << ans;
	}

	return 0;
}