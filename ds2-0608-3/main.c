#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 30

int n;                  // 정점의 총 개수
int graph[MAX_SIZE][MAX_SIZE];   // 인접 행렬
bool visited[MAX_SIZE];          // 정점의 방문 여부
int discovery[MAX_SIZE];         // 정점의 발견 순서
int low[MAX_SIZE];               // 정점의 최소 발견 순서
int time;                        // 발견 시간

// 브릿지 검출 함수
void findBridges(int u, int parent) {
    visited[u] = true;
    discovery[u] = low[u] = ++time;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                findBridges(v, u);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (low[v] > discovery[u]) {
                    printf("브릿지: %d - %d\n", u, v);
                }
            }
            else if (v != parent) {
                low[u] = (low[u] < discovery[v]) ? low[u] : discovery[v];
            }
        }
    }
}

// 그래프 초기화 및 브릿지 검출 함수 호출
void findBridgesDFS() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        discovery[i] = 0;
        low[i] = 0;
    }
    time = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            findBridges(i, -1);
        }
    }
}

int main() {
    int m; // 간선의 개수
    printf("정점의 총 개수와 간선의 개수를 입력하세요: ");
    scanf("%d %d", &n, &m);

    // 그래프 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("간선을 입력하세요 (예: 1 2): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    // 브릿지 검출
    findBridgesDFS();

    return 0;
}
