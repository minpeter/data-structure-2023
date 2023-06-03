#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
//�׷��� �ʱ�ȭ
void init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}
//���� ���� ���� 
void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "�׷���: ������ ���� �ʰ�");
        return;
    }
    g->n++;
}
//���� ���� ����
void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "�׷���: ���� ��ȣ ����");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
//���� ��� ��� �Լ�
void print_adj_mat(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}
void main() {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 6; i++) {
        insert_vertex(g, i);
    }
insert_edge(g, 0, 1);
insert_edge(g, 0, 2);
insert_edge(g, 0, 3);

insert_edge(g, 1, 0);
insert_edge(g, 1, 3);
insert_edge(g, 1, 4);
insert_edge(g, 1, 5);

insert_edge(g, 2, 0);
insert_edge(g, 2, 4);
insert_edge(g, 2, 5);

insert_edge(g, 3, 0);
insert_edge(g, 3, 1);
insert_edge(g, 3, 4);
insert_edge(g, 3, 5);


insert_edge(g, 4, 1);
insert_edge(g, 4, 2);
insert_edge(g, 4, 3);

insert_edge(g, 5, 1);
insert_edge(g, 5, 2);
insert_edge(g, 5, 3);

    print_adj_mat(g);
    free(g);
}
