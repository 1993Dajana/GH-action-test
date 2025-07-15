struct Foo {
    // testcase: field values changed
    int x = 3;
    int y = 2;
    int z = 1;
};

Foo foo;

int main() {
    return foo.x;
}
