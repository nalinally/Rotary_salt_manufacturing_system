# 回転式製塩システム　引継ぎ資料

# 始めに

卒研を１年間してみて、次の２つを強く感じました。

1. 時間は常にないと思ったほうがいい。
    
    本当に、気づいたら年が明けてました。爆速で進捗で出してやろうっていうよりは、**毎日ちょっとでもいいから取り組み続ける**（≠ 進捗を出す）のを意識すると、いつの間にか進捗は出てると思います。
    
2. 卒研は、自分で考え始めてからが楽しい。
    
    これは本当にそう。だから本当は、**研究テーマも自分で考えたほうが絶対いい**です。引継ぎはあんまりお勧めししない。テーマ以外にも、例えば研究の進め方とかを先生に聞いたり調べてみるのは全然いいけど、自分でも考えてやった方が、うまくいくことが多いです。
    

# 研究背景

海水から塩を作るときには、次のような工程をふみます。

![製塩工程](images/製塩工程.png)

海水から塩を取り出すためには、海水の水分をどうにかして蒸発させる必要があります。外国だと広い土地がありがちなので海水を天日干しにできたりしますが、多湿で広い土地もない日本では、海水を釜で煮詰めて塩を取り出すやり方が主流です。

その時に問題になるのは、エネルギーです。お日様の力を使うわけじゃなくて、燃料を使って火をたくわけですから、より少ないエネルギーで海水から塩を取り出したい。そこで、どうにか海水の濃度を上げて（採かん）から、海水を煮詰める（煎ごう）という手法が考えられました。

この手法にはエネルギー効率の面だけではなくて、煮詰める方法によって、狙った形や大きさの塩を作ることができるので、高品質な塩を作りやすいというメリットもあります。

ここからは採かん（わかりにくいので、以下海水濃縮）に絞って話を進めます。

現在日本で主流な海水濃縮手法は、イオン交換膜法というもので、化学的なフィルタを通すことで「水分を蒸発させる」のではなく「塩だけを取り出す」ということで海水を濃くすることができるんだそう。

参考
[日本の塩づくりの歴史 | 塩のつくり方 | 塩百科 | 公益財団法人塩事業センター](https://www.shiojigyo.com/siohyakka/made/history.html)

ただ、沖縄県うるま市の浜比嘉島にある高江洲製塩所というところでは、一昔前の**流下式塩田**という手法を使って海水濃縮を行っています。

この手法は、海水から「水分を蒸発させる」ので、イオン交換膜法ではフィルタによって取り除かれてしまうような海水中のミネラルを、そのまま塩に残すことができるのだそうです。

流下式塩田の概要として、

1. 海水を枝条架（しじょうか：竹を組んで作ったやつ）に上から流す
2. 海水が枝条架を滴り落ちる間に、海風によって海水の水分が蒸発する
3. 下まで落ちてきた海水を、流下盤（ゆるくて幅が広い下り坂）に流す
4. 流下盤で薄く広がった海水は、太陽の照射を受けて、水分が蒸発する
5. 流下盤を流れ切った海水をもう一度上にくみ上げて、枝条架に上から流す
6. 海水の塩分濃度が15％になるまで、１～５を繰り返す

![流下式塩田3](images/流下式塩田3.png)


という手順によって、海水濃縮を行います。なんで15％かというと、それ以上濃度を上げると塩が結晶化し始めてしまうかららしいです。

しかし、この流下式塩田には、**気候の影響を強く受ける**という問題があります。上の説明からわかるように、流下式塩田は自然の力を使って海水濃縮を行うので、雨が降った時には稼働できなかったり、雨が降っていなくても湿度が高かったり風がない日だと効率が大きく落ちたりしてしまいます。

この問題が解決すれば、**塩の安定生産**が可能となり、ネットなどでの受注生産をすることができるようになります。

参考
[「されど塩」が生まれるまで - 伯方塩業株式会社](https://www.hakatanoshio.co.jp/salt/saredoshio/)

# 研究概要

本研究では、新しい方法での海水濃縮を提案します。

まず、水面の上を一定の温度、湿度、速さの風が流れていると仮定すると、水の蒸発する速度は

$$
v=\frac{Sh\times{D}\times(c_1-c_2)}{l}
$$

$v$ : 蒸発速度 [kg/m^2s]　　$D$ : 水蒸気の拡散係数 [m^2/sec]　　$Sh$ : シャーウッド数

$c_1$ : 水面付近の飽和蒸気量 [kg/m^3]　　$c_2$ : 空気の蒸気量 [kg/m^3]　　$l$ : 水面の代表長さ [m]

で表されます。シャーウッド数は、風速の1/2乗に比例する定数です。

この式から、水の蒸発速度を上げるためには、

1. 海水温を上げる　→　水面の飽和蒸気量($c_1$)を上げる
2. 空気の除湿・循環を行う　→　水面の蒸気量($c_2$)を下げる
3. 風速($u$)を上げる　→　シャーウッド数を増加させる
4. 空気と水が触れる面積を大きくする(最終的な蒸発速度は、面積 $S$ を用いて $v\times{S}$ と表される)

この４つが重要になります。

参考
[水の蒸発速度  |  工学計算.com](https://kougakukeisan.com/2021/09/25/水の蒸発速度/)

これら４つのパラメータを効果的に上げるために、本研究では、回転する中空の円筒（ロータ）を用いた新しい海水濃縮手法を提案します。

![製塩システム](images/製塩システム.png)


この手法では、中空の円筒（以下ロータ）を用いて海水濃縮を行います。まず、ロータの表面に海水を薄く張ります。このロータを回転させることで、ロータの表面と空気との間に相対速度が生じ、風が吹いているのと同じ状態になります。この風を使って、海水の水分を蒸発させます。

雨の日や湿度が高い日は装置を密閉して、除湿器によって部屋の湿度を下げ、晴れの日には装置を開閉して、流下式塩田と同じように日光と自然の風を利用して海水濃縮を行います。

![システム運用](images/システム運用.png)


この手法によって、気候によらない、安定した海水濃縮が可能となり、これにより安定した塩の生産ができるようになります。

![原理図](images/原理図.png)


# 最終的なゴール

最終的なゴールは、大体この図のような感じです。

![製塩システム](images/製塩システム.png)


最終的にやりたいことは、

①　湿度、温度、気圧、水温、照度をセンサによって常時モニタリングし、

②　その値からヒータ、除湿器、電磁バルブ、ロータを最適に制御することで、

③　従来の流下式塩田の一番効率がいい時ぐらいの効率を常に保ち続ける（ただし、電力消費は最低限で！）

です。

# やったこと

### 筐体の作成

筐体の設計を行い、加工して作りました。solidworksというソフトを使って設計を行いましたが、9月くらいに一度OSを消し飛ばしたので、設計ファイルは残っていません。ごめんなさい。solidworksは、機械科の人か工場の先生に聞けば自分のPCにインストールすることができると思います。

![筐体](images/筐体.png)

１号機。底の深い箱を使ったので、空気の循環がうまくいかず、全然水分が蒸発しませんでした。センサは画像の場所ではなく、装置の隣に設置しました。

![2号機筐体.jpg](images/2号機筐体.jpg)

２号機。ロータの回転機構をそのまま、底の浅い箱に付け替えています。これによって、扇風機を使えばうまく空気を循環できるので、水分が蒸発するようになりました。また、１号機では4枚の透明な円盤によって円筒の構造を形作っていましたが、これを両端の2枚にすることによって、ロータの形状を変えやすくしました。

### センサモジュールの開発
Xiao esp32s3というモジュールを使って、センサの値を読み、Ambientというサービスを使ってクラウドにデータを蓄積・可視化するシステムを開発しました。

[IoTデーター可視化サービス Ambient](https://ambidata.io/)

使用したセンサとマイコンは以下です。

マイコン：

[Xiao ESP32S3](https://www.switch-science.com/products/8968)

センサ：

[BME280](https://akizukidenshi.com/catalog/g/g109421/)

[DS18B20](https://www.amazon.co.jp/%E6%B8%A9%E5%BA%A6%E3%82%BB%E3%83%B3%E3%82%B5%E3%83%BC-%E3%82%B5%E3%83%BC%E3%83%A2%E3%82%B9%E3%82%BF%E3%83%83%E3%83%88-%E3%83%88%E3%83%A9%E3%83%B3%E3%82%B9%E3%83%87%E3%83%A5%E3%83%BC%E3%82%B5%E3%83%A2%E3%82%B8%E3%83%A5%E3%83%BC%E3%83%AB-DS18B20-%E3%83%97%E3%83%AD%E3%83%BC%E3%83%96%E4%BB%98%E3%81%8D/dp/B07B2VVQ4K/ref=sr_1_14?crid=S0A72MTEM87Z&keywords=ds18b20&qid=1707878258&s=industrial&sprefix=DS%2Cindustrial%2C525&sr=1-14-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&psc=1)

BME280は、J1、J2、J3をはんだで繋げて使用しました。

実装したコードは以下です。

[ambient_water_temp](codes\ambient_water_temp)

接続図は以下です。（手書きですみません...）

![センサモジュール_接続図](images/センサモジュール_接続図.jpg)

参考
[Arduino+DS18B20で温度測定してみた #Arduino - Qiita](https://qiita.com/hnw/items/315fad0d4b60ada10d00)

### 制御モジュールの開発
MQTT通信という通信方法を使って、遠隔でXiao ESP32S3に指示を出し、モーターを制御するシステムを開発しました。

使用した回路とマイコンは以下です。

マイコン：

[Xiao ESP32S3](https://www.switch-science.com/products/8968)

回路：

[モータードライバ TB6643KQ](https://akizukidenshi.com/catalog/g/g109421/)

実装したコードは以下です。

[xiao_mqtt_motor](codes/xiao_mqtt_motor/)

接続図は以下です。（また手書きですみません...）

![制御モジュール_接続図](images/制御モジュール_接続図.jpg)

参考

[ESP32でMQTT通信（XIAO ESP32S3、Node-RED、HIDキーボード） - 趣味的ロボット研究所](https://404background.com/program/esp32-mqtt/)

[TB6643KQ データシート](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://www.marutsu.co.jp/contents/shop/marutsu/datasheet/TB6643KQ_datasheet_ja_20110621.pdf)

# 現状

最終的なゴールはこんな感じですが、

![最終的なゴール](images/最終的なゴール.png)


現状はこんな感じです。

![現状](images/現状.png)


# 動かし方

# やること
