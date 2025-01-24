# フィボナッチ数計算プログラム

フィボナッチ数を[Fast doubling](https://www.nayuki.io/page/fast-fibonacci-algorithms#:~:text=Fast%20doubling%20(faster))を用いて計算します。O(log n)程度の計算量であり、整数オーバーフローを避けるためboost/GMPの多倍長整数演算を用いています。

実行環境は以下の通りです。

```bash
$ cat /etc/lsb-release
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=24.04
DISTRIB_CODENAME=noble
DISTRIB_DESCRIPTION="Ubuntu 24.04 LTS"
```

## 必要ライブラリ

多倍長整数演算に[Boost.Multiprecision](https://www.boost.org/doc/libs/release/libs/multiprecision/)と[GMP](https://gmplib.org/)が必要です。

```bash
$ sudo apt-get update
$ sudo apt-get install -y g++ libboost-all-dev libgmp-dev
```

GMPは高速化のために使用しています。ソースコードを下記のように書き換えて`mpz_int`の代わりに`cpp_int`を使うことでGMPへの依存性を失くせますが、代わりに速度が犠牲となります。

```cpp
#include <boost/multiprecision/cpp_int.hpp>

using mp_int = boost::multiprecision::cpp_int;
```


## ビルド・実行

```bash
$ g++ main.cpp -o fib -lgmp -O3 -std=c++17
$ ./fib 10
55
```

fib(10) = 55 が計算されます。n = 100,000,000（約2000万桁）であれば、筆者環境で3秒程度で計算できました。

```bash
$ lscpu | grep "Model name"
Model name:                           AMD Ryzen 7 5800X 8-Core Processor
$ time ./fib 100000000 > fib.txt

real    0m3.088s
user    0m2.990s
sys     0m0.031s
$ wc --chars fib.txt
20898765 fib.txt
```
