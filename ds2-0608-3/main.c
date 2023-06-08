#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 30

int n;                  // ������ �� ����
int graph[MAX_SIZE][MAX_SIZE];   // ���� ���
bool visited[MAX_SIZE];          // ������ �湮 ����
int discovery[MAX_SIZE];         // ������ �߰� ����
int low[MAX_SIZE];               // ������ �ּ� �߰� ����
int time;                        // �߰� �ð�

// �긴�� ���� �Լ�
void findBridges(int u, int parent) {
    visited[u] = true;
    discovery[u] = low[u] = ++time;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                findBridges(v, u);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (low[v] > discovery[u]) {
                    printf("�긴��: %d - %d\n", u, v);
                }
            }
            else if (v != parent) {
                low[u] = (low[u] < discovery[v]) ? low[u] : discovery[v];
            }
        }
    }
}

// �׷��� �ʱ�ȭ �� �긴�� ���� �Լ� ȣ��
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
    int m; // ������ ����
    printf("������ �� ������ ������ ������ �Է��ϼ���: ");
    scanf("%d %d", &n, &m);

    // �׷��� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // ���� ���� �Է�
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("������ �Է��ϼ��� (��: 1 2): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    // �긴�� ����
    findBridgesDFS();

    return 0;
}
