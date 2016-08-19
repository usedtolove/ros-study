# Linux cpp HelloWorld

## Steps
### 1. edit hello.cpp
```
#include <iostream>
using namespace std;

int main(){
    cout << "HelloWorld" << endl;
    return 0;
}
```

### 2. compile
`g++ hello.cpp -o hello`

### 3. run
`./hello`

## remark
* gcc is for C, and will **NOT** give access to c++ library.
