# 数値解析１
- 実行ファイルなどは[このへん](../num-analy1)にあります
- `.c`ファイルのコメントアウトは、ほぼメモ帳なので消すか無視してください
- `report3.c`はまだ手を加えていません
- `input.txt`は青空文庫から拾ってきたよくわからん小説（好きなように変えてください）
## report1<br>
>サンプルから、アルファベット、空⽩、改⾏などを抽出し別ファイルに出力<br>
ただし、必要な文字以外は空⽩に置換<br>

`input.txt`から一文字ずつ読み取り、欲しい文字と照合<br>
必要なら別ファイルに書き込み、要らなければスキップを繰り返す<br>
 文字の判別は文字コードで行う（プログラム内の2ケタの数値は文字コード）
<details><summary>変数定義とか</summary>

- `char filename[]`：参照するファイル名の格納場所。別に無くてもいい<br>
- `FILE　*ip`：ファイル情報(住所とか読み取り位置とか)を格納するとこ<br>
  - `fopen`関数：指定したファイルの情報を渡してくれるやつ。使い終わったら`fclose`関数で閉じないとメモリを食われる。<br>＊引数１=（ファイル名やファイルのパス）引数２=（オプション：rなら読み取り、wは書き込み）<br>
  - `feof`関数：EOF（ファイル終端文字）を読み取ったらtrueを返す関数。<br>＊引数=（FILE型のポインタ）<br>`while((letr=fopen(ip))!=EOF)`と書くと、gitからcloneしたときになぜかEOFを読み取らず無限ループするので注意
- `char letr`：読み取る文字の格納場所。別に無くても(ry
  - `isalpha`関数：アルファベットかどうか
  - `fprintf`関数：標準出力以外に出したいときに使うやつたぶん
 </details>
 

## report2<br>
>半⾓⽂字のみから成るテキストファイルから⽂字を1つずつ読み込み、<br>
ファイルに含まれる⽂字の出現頻度を調べる<br>

調べる文字の個数分、配列で変数定義をする<br>
配列はあとで出現頻度毎にソート(並べ替え)するので、配列だけだとどの文字が何個あったか分からなくなる
→構造体で配列の１つに２つ情報を乗っける<br>
<br>
例えば添字０の中に、構造体で文字コードAという情報とそれが何個あったかという情報の２つ入っているので、添字１０とか５０とかに移動しても、一緒に移動させればどの文字が何個あったかの判別がつく（バブルソートで入れ替えるコードを２回書いているのは一緒に移動させるため）<br>
<br>
**回し方**<br>
一文字読み取る→Aと比較、Bと比較、Cと比較…→同じ文字あった→該当文字のカウントを増やす→次へ<br>
文字が見つかった時点で、後は比較せず次へ行くので少しだけ速い<br>
（文字のカウントが多い順に比較すればもっと速くなるかもしれない）
<details><summary>ASCII対応表</summary>

並び替える前はこんな感じ<br>
一番上で定義した`liter_code`関数はこれに倣って返り値を与える<br>
Z→aで文字コードは90→97へ飛ぶので、`if-else`文で場合分け<br>
最後の記号はおまけ<br>
<table><tr></tr><th>添字([ ]内の数字)</th><th>文字コード</th><th>対応文字</th></tr><tr><td>0</td><td>65</td><td>A</td></tr><tr><td>1</td><td>66</td><td>B</td></tr><tr><td>2</td><td>67</td><td>C</td></tr><tr><td>3</td><td>68</td><td>D</td></tr><tr><td>4</td><td>69</td><td>E</td></tr><tr><td>5</td><td>70</td><td>F</td></tr><tr><td>6</td><td>71</td><td>G</td></tr><tr><td>7</td><td>72</td><td>H</td></tr><tr><td>8</td><td>73</td><td>I</td></tr><tr><td>9</td><td>74</td><td>J</td></tr><tr><td>10</td><td>75</td><td>K</td></tr><tr><td>11</td><td>76</td><td>L</td></tr><tr><td>12</td><td>77</td><td>M</td></tr><tr><td>13</td><td>78</td><td>N</td></tr><tr><td>14</td><td>79</td><td>O</td></tr><tr><td>15</td><td>80</td><td>P</td></tr><tr><td>16</td><td>81</td><td>Q</td></tr><tr><td>17</td><td>82</td><td>R</td></tr><tr><td>18</td><td>83</td><td>S</td></tr><tr><td>19</td><td>84</td><td>T</td></tr><tr><td>20</td><td>85</td><td>U</td></tr><tr><td>21</td><td>86</td><td>V</td></tr><tr><td>22</td><td>87</td><td>W</td></tr><tr><td>23</td><td>88</td><td>X</td></tr><tr><td>24</td><td>89</td><td>Y</td></tr><tr><td>25</td><td>90</td><td>Z</td></tr><tr><td>26</td><td>97</td><td>a</td></tr><tr><td>27</td><td>98</td><td>b</td></tr><tr><td>28</td><td>99</td><td>c</td></tr><tr><td>29</td><td>100</td><td>d</td></tr><tr><td>30</td><td>101</td><td>e</td></tr><tr><td>31</td><td>102</td><td>f</td></tr><tr><td>32</td><td>103</td><td>g</td></tr><tr><td>33</td><td>104</td><td>h</td></tr><tr><td>34</td><td>105</td><td>i</td></tr><tr><td>35</td><td>106</td><td>j</td></tr><tr><td>36</td><td>107</td><td>k</td></tr><tr><td>37</td><td>108</td><td>l</td></tr><tr><td>38</td><td>109</td><td>m</td></tr><tr><td>39</td><td>110</td><td>n</td></tr><tr><td>40</td><td>111</td><td>o</td></tr><tr><td>41</td><td>112</td><td>p</td></tr><tr><td>42</td><td>113</td><td>q</td></tr><tr><td>43</td><td>114</td><td>r</td></tr><tr><td>44</td><td>115</td><td>s</td></tr><tr><td>45</td><td>116</td><td>t</td></tr><tr><td>46</td><td>117</td><td>u</td></tr><tr><td>47</td><td>118</td><td>v</td></tr><tr><td>48</td><td>119</td><td>w</td></tr><tr><td>49</td><td>120</td><td>x</td></tr><tr><td>50</td><td>121</td><td>y</td></tr><tr><td>51</td><td>122</td><td>z</td></tr><tr><td>52</td><td>39</td><td>'</td></tr><tr><td>53</td><td>44</td><td>,</td></tr><tr><td>54</td><td>46</td><td>.</td></tr></table>
 </details>

## report3<br>
任意課題
## report4<br>
まだ　（`rand`とかでやる）
## report5<br>
任意課題
