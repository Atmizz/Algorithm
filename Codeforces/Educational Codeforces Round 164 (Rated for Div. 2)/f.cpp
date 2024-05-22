struct DijsktraAlgorithm {
	struct Node {
		int x;
		i64 dis;
		friend bool operator < (Node a, Node b) {
			return a.dis > b.dis;
		}
	};
	struct Edge {
		int to, net;
		i64 dis;
	}e[N<<1];
	i64 dis[N];
	int cnt, head[N];
	void init() {
		cnt = 0;
		memset(head, 0, sizeof head);
	}
	inline void insert(int u, int v, i64 w) {
		e[++cnt] = {v, head[u], w};
		head[u] = cnt;
	}
	void Dijsktra(int st) {
		memset(dis, 0x3f, sizeof dis);
		std :: priority_queue <Node> q;
		dis[st] = 0; q.push({st, 0});
		while((int) q.size()) {
			auto [u, d] = q.top(); q.pop();
			if(d != dis[u]) {
				continue ;
			}
			for(int i = head[u]; i; i = e[i].net) {
				int v = e[i].to;
				if(dis[v] > dis[u] + e[i].dis) {
					dis[v] = dis[u] + e[i].dis;
					q.push({v, dis[v]});
				}
			}
		}
	}
}Dij;