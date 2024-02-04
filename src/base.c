
int main(int argc, char* argv[]) {
  int arr[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
  }
  if (arr[9] > 7) {
    arr[9] = 20;
  }
  return 0;
}