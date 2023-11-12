// quick sort
void Quick_sort(int q[], int l, int r) {
  if (l >= r) {
    return;
  }
  int i = l - 1;
  int j = r + 1;
  int x = q[l + r >> 1];
  while (i < j) {
    while (q[++i] < x);
    while (q[--j] > x);
    if (i < j) {
      swap(q[i], q[j]);
    }
  }
  quick_sort(q, l, j);
  quick_sort(q, j + 1, r);
}

// find the kth maximum by quick sort
int Quick_sort(int l, int r, int k) {
  if (l >= r) {
    return a[r];
  }
  int i = l - 1;
  int j = r + 1;
  int x = a[l + r >> 1];
  while (i < j) {
    while (a[++i] < x);
    while (a[--j] > x);
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  if (k <= j - l + 1) {
    return quick_sort(l, j, k);
  }
  return quick_sort(j + 1, r, k - j + l - 1);
}

// 归并排序求逆序对
long long Merge_sort(int q[], int l, int r) {
  if (l >= r) {
    return 0;
  }
  int mid = l + r >> 1;
  long long res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) {
      tmp[k++] = q[i++];
    } else {
      res += mid - i + 1;
      tmp[k++] = q[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = q[i++];
  }
  while (j <= r) {
    tmp[k++] = q[j++];
  }
  for (i = l, j = 0; i <= r; i++, j++) {
    q[i] = tmp[j];
  }
  return res;
}
