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
### [Ergodash](keybords/omkbd/ergodash/rev1/keymaps/tsubu)
~~~shell
 qmk compile -kb omkbd/ergodash/rev1 -km tsubu
~~~
 
