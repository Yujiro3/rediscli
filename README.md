C++のRedisクライアントサンプル
======================
libevent2を利用したRedisクライアント

利用方法
------

### libevent2モジュールのインストール ###
    
    $ wget http://jaist.dl.sourceforge.net/project/levent/libevent/libevent-2.0/libevent-2.0.21-stable.tar.gz
    $ tar xzvf libevent-2.0.21-stable.tar.gz
    $ cd libevent-2.0.21-stable
    $ ./configure
    $ make
    $ sudo make install

### コンパイル ###
    
    $ g++ -L/usr/local/lib  -I/usr/local/include -levent -o rediscli main.cpp mem_rediscli.cpp
        
### コマンド ###

```cpp
/* キー操作 */
rcli.query("SET key 4");
cout << "SET:" << rcli.result << endl;

rcli.query("GET key");
cout << "GET:" << rcli.result << endl;

/* リスト操作 */
rcli.query("SADD mymems 1001");
cout << "SADD:" << rcli.result << endl;

rcli.query("SMEMBERS mymems");
list_t::iterator row = rcli.member.begin();

cout << "SMEMBERS:" << endl;
while (row != rcli.member.end()) {
    cout << row->c_str() << endl;
    ++row;
}    

/* 接続を閉じる */
rcli.query("QUIT");
cout << "QUIT:" << rcli.result << endl;
```

### テスト実行 ###
    
    $ ./rediscli
    SET:OK
    GET:4
    
    SADD:
    SMEMBERS:
    1001
    QUIT:OK

ライセンス
----------
Copyright &copy; 2013 Yujiro Takahashi  
Licensed under the [MIT License][MIT].  
Distributed under the [MIT License][MIT].  

[MIT]: http://www.opensource.org/licenses/mit-license.php
