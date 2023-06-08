#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int n; // ������ �ִ�
int rear, front; // ���ʰ� ������ ��Ÿ���� ����
int map[30][30]; // ���� ���
int queue[30]; // ť
int visit[30]; // �湮 ���θ� ��Ÿ���� �迭
void BFS(int v) {
	int i;
	visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
	printf("%d���� ����\n", v);
	queue[rear++] = v; // ť�� v�� �����ϰ� ������ 1 ������Ŵ
	while (front < rear) { // ������ ���ʰ� ���ų� ������ ���� Ż��
		// ť�� ù��°�� �ִ� �����͸� �����ϰ� ���ܵ� ���� ��������, ���� 1 ����
		v = queue[front++];
		for (i = 1; i <= n; i++) {
			// ���� v�� ���� i�� ������, ���� i�� �湮���� ���� ������ ���
			if (map[v][i] == 1 && !visit[i]) {
				visit[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��
				printf("%d���� %d�� �̵�\n", v, i);
				queue[rear++] = i; // ť�� i�� �����ϰ� �Ĵ��� 1 ������Ŵ
			}
		}
	}
}
int main() {
	int start; // ���� ����
	int v1, v2;
	printf("������ �� ������ ���� ������ �Է��ϼ���.: ");
	scanf("%d%d", &n, &start);
	while (1) {
		printf("������ �� ������ �Է��ϼ���.(�� 3 4): ");
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1) break; // �Է� ����
		map[v1][v2] = map[v2][v1] = 1; // ���� v1�� ���� v2�� ����Ǿ��ٰ� ǥ��
	}
	BFS(start); // BFS ����!
	return 0;
}