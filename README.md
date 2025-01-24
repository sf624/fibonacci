# フィボナッチ数計算プログラム

フィボナッチ数を行列積を用いて計算します。O(log n)程度の計算量であり、整数オーバーフローを避けるためboost/GMPの多倍長整数演算を用いています。

実行環境は以下の通りです。

```bash
$ cat /etc/lsb-release
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=24.04
DISTRIB_CODENAME=noble
DISTRIB_DESCRIPTION="Ubuntu 24.04 LTS"
```

## 必要ライブラリ

多倍長整数演算にboostとGMP、行列演算にEigenが必要です。

```bash
$ sudo apt-get update
$ sudo apt-get install -y g++ libboost-all-dev libeigen3-dev libgmp-dev
```

## ビルド・実行

```bash
$ g++ main.cpp -o fib -I/usr/include/eigen3 -lgmp -O3
$ ./fib 10
55
```

fib(10) = 55 が計算されます。n = 100,000,000（約2000万桁）であれば、筆者環境で5秒程度で計算できました。

```bash
$ lscpu | grep "Model name"
Model name:                           AMD Ryzen 7 5800X 8-Core Processor
$ time ./fib 100000000 > fib.txt

real    0m5.208s
user    0m4.576s
sys     0m0.147s
$ wc --chars fib.txt
20898765 fib.txt
```
