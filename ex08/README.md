### 演習第８回の問題＆小テスト問題のためのディレクトリ

lec08.cc: 講義中に問われる小テストのプログラム
prog08.cc: 演習問題で以下の仕様を満たすプログラム

#### 問題
以下の仕様を満たすC++プログラムを作成し、正しく動くことを確認せよ。
その後ソースコードと自分で作成したテストパターンを提出せよ。

### 仕様
* C++の標準ライブラリに含まれるsearch, copy, partition と同じ機能をもつ関数my_search, my_copy, my_partitionをテンプレートを使って定義せよ．
* サンプルプログラムには，main関数の中に my_search, my_copy, my_partitionをテストするためのソースは記述されているが，
各関数の中身は定義されていない．正しくプログラムが動作するように各関数を書き加えよ．

以下は関数の概略である．
* template < class ForwardIterator1, class ForwardIterator2 > 
ForwardIterator1 my_search( ForwardIterator1 b, ForwardIterator1 e, ForwardIterator2 b2, Forwarditerator2 e2 );
	* 反復子 b から e で指定されたシーケンスの中から，反復子 b2 から e2 で指定されたシーケンスを探す． ただし，e と e2 は探索範囲にに含まれない．
	* シーケンスが見つかった場合は，その位置の反復子を返す．見つからなかった場合は，e を返す．

* template < class InputIterator, class OutputIterator > 
OutputIterator my_copy( InputIterator b, InputIterator e, OutputIterator d );
	* 反復子 b から e で指定されたシーケンスを，反復子 d が指定する位置にコピーする．
	* 戻り値は最後に追加した要素を指す反復子 （dにコピーされたeの直前の要素を指す反復子）．

* template < class BidirectionalIterator, class Predicate > 
BidirectionalIterator my_partition( BidirectionalIterator b, BidirectionalIterator e, Predicate p );
	* 反復子 b から e で指定されたシーケンスに対して，叙述関数 p がtrueになる要素を前方にまとめる．
	* ただし、partitionされた要素の順は出力のサンプルと違っても構わない(2015/12/01　追記).
	* 戻り値は，p が false を返す最初の要素を指す反復子．
*関数の仕様については教科書P320以降を参照すること．

#### 入力のイメージ
元になるソースファイルSkelton8.ccを参照のこと．

#### 出力のイメージ
詳細はresult8.txtを参照

[://] is found at [://www.u-aizu.ac.jp/~naruse]
[://] is NOT found in [/ProgC++2008/index.html]
http://www.u-aizu.ac.jp/~naruse/ProgC++2008/index.html
http://www.u-aizu.ac.jp/another/ProgC++2008/index.html
Following letters are [/ProgC++2008/index.html]
0 1 2 3 4 5 6 7 8 9 
0 8 2 6 4 5 3 7 1 9 
5
0 0 0 0 0 0 0 0 0 0 
0
1 1 1 1 1 1 1 1 1 1 
1

#### テストの方法
* (1)Skelton8.ccに書き加え，result8.txtと同じになるかを検証する
* 出力結果をエディタで目視し，仕様を満たしているか確認する
* 仕様を満たすまで開発を続ける

#### 提出物（計２ファイル）
* ソースコード（１ファイル）
* 上の(1)のテストパターンに対する出力を表すファイル（１ファイル）
