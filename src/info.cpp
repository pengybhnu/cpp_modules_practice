struct Info{
    int px;
    double py;
};

void print(int x){
  Info inf= {.px=x,.py=369.3};
}
int main(int argc, char *argv[]){
    const int n = 20;
    unsigned long h = n +1;

}
// clang-17 -Xclang -ast-dump -fsyntax-only info.c
// clang-17 -o0 -c src/info.c -S -emit-llvm
// /usr/lib/llvm-17/bin/opt info.ll -S -O3

// clang -fmodules -fsyntax-only -Xclang -ast-dump src/info.c

// LD_DEBUG="symbols:bindings" ./build/bin/infot