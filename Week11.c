#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void SelectionSort(int arr[], int n)
{
    int i, k, p, temp;
    for (i = 0; i < n - 1; i++) {
        p = i;
        for (k = i + 1; k < n; k++) {
            if (arr[k] < arr[p]) p = k; // Ascending sort(�������� ����)
        }
        temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
    }
}

int main()
{
    int  lotto[7]= { 0 };   // ������ 5������ 0���� ä�� --> 6�� ��� 0���� �ʱ�ȭ �ȴ�.
    int i = 0, n = 0;
    srand((unsigned)time(NULL));  // �Ź� �ٸ� ���� �����ϵ��� �����Լ� �ʱ�ȭ

    while (1)   // �ߺ����� �����ϱ� ������  for ������  6�� �ݺ��ϸ� �ȵ�
    {
        //  rand() % 45 : 0���� 44���� �� ������ �����Ѵ�.
        //  rand() % 45  + 1 : 1���� 45������ ������ �����Ѵ�.

        int r = rand() % 70 + 1;  // 1~70 ������ ���� �� ����, �ߺ� ����

        for (i = 0; i < n; i++)         // �̹� ������ ���� ��ŭ�� �ߺ��� ������ �˻��Ѵ�.
            if (lotto[i] == r) break;     // �̹� ������ ��ȣ����(�ߺ���) �˻��Ѵ�.

        if (n == i) lotto[n++] = r;            // �ߺ����� �ƴҶ����� n��ġ�� ������ ���� ����Ų��.
        if (n >= 6) break;        // ���� �� 6���� �����Ǿ����� ���� �ݺ��� �����.
    }

    // ũ������� �����Ѵ�.
    SelectionSort(lotto, 7);

    // ������ ��ȣ ����Ѵ�.
    for (i = 0; i < 7; i++)
        printf("%d\n", lotto[i]);

    return 0;
}





