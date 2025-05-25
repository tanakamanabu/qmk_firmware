# カスタマイズについて
## ビルド
 - MSYS2のMingw64にQMKをインストールします
~~~shell
pacman -S git mingw-w64-x86_64-toolchain mingw-w64-x86_64-python3-pip
python3 -m pip install qmk
qmk setup tanakamanabu/qmk_firmware
~~~
## 書き込み
 - ファームの書き込みには [QMKToolBox](https://qmk.fm/toolbox)を使います
 - Auto FlushをオンにしてProMicroをダブルクリックで運が良ければ書き込めます
## 詳細
### [Ergodash](keyboards/omkbd/ergodash/rev1/keymaps/tsubu)
~~~shell
 qmk compile -kb omkbd/ergodash/rev1 -km tsubu
~~~
 
### [Iris](keyboards/keebio/iris/keymaps/tsubu)
 - 過去の遺産なので動かないと思うけど記念に残しておく
