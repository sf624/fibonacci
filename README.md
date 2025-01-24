# フィボナッチ数計算プログラム

フィボナッチ数を行列積を用いて計算します。O(log n)程度の計算量であり、整数オーバーフローを避けるためboostの多倍長整数を用いています。

実行環境は以下の通りです。

```bash
$ cat /etc/lsb-release
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=24.04
DISTRIB_CODENAME=noble
DISTRIB_DESCRIPTION="Ubuntu 24.04 LTS"
```

## 必要ライブラリ

boostとEigenが必要です。

```bash
$ sudo apt-get update
$ sudo apt-get install -y g++ libboost-all-dev libeigen3-dev
```

## ビルド・実行

```bash
$ g++ main.cpp -o fib -I/usr/include/eigen3 -O3
$ ./fib 10
55
```

fib(10) = 55 が計算されます。n = 1,000,000であれば1秒程度で計算できます。

```bash
$ time ./fib 1000000
...9033684684301719893411568996526838242546875

real    0m0.371s
user    0m0.321s
sys     0m0.000s
```
