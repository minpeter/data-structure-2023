#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int n; // 정점의 최댓값
int rear, front; // 앞쪽과 뒤쪽을 나타내는 변수
int map[30][30]; // 인접 행렬
int queue[30]; // 큐
int visit[30]; // 방문 여부를 나타내는 배열
void BFS(int v) {
	int i;
	visit[v] = 1; // 정점 v를 방문했다고 표시
	printf("%d에서 시작\n", v);
	queue[rear++] = v; // 큐에 v를 삽입하고 뒤쪽을 1 증가시킴
	while (front < rear) { // 뒤쪽이 앞쪽과 같거나 작으면 루프 탈출
		// 큐의 첫번째에 있는 데이터를 제외하고 제외된 값을 가져오며, 앞쪽 1 증가
		v = queue[front++];
		for (i = 1; i <= n; i++) {
			// 정점 v와 정점 i가 만나고, 정점 i를 방문하지 않은 상태일 경우
			if (map[v][i] == 1 && !visit[i]) {
				visit[i] = 1; // 정점 i를 방문했다고 표시
				printf("%d에서 %d로 이동\n", v, i);
				queue[rear++] = i; // 큐에 i를 삽입하고 후단을 1 증가시킴
			}
		}
	}
}
int main() {
	int start; // 시작 정점
	int v1, v2;
	printf("정점의 총 개수와 시작 정점을 입력하세요.: ");
	scanf("%d%d", &n, &start);
	while (1) {
		printf("연결할 두 정점을 입력하세요.(예 3 4): ");
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1) break; // 입력 종료
		map[v1][v2] = map[v2][v1] = 1; // 정점 v1과 정점 v2가 연결되었다고 표시
	}
	BFS(start); // BFS 시작!
	return 0;
}