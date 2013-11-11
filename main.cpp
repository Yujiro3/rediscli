/**
 * main.cpp
 *
 * C++ versions 4.4.5
 *
 *      mem_redis : https://github.com/Yujiro3/rediscli
 *      Copyright (c) 2011-2013 sheeps.me All Rights Reserved.
 *
 * @package         mem_redis
 * @copyright       Copyright (c) 2011-2013 sheeps.me
 * @author          Yujiro Takahashi <yujiro3@gmail.com>
 * @filesource
 */

#include <iostream>
#include <string>

#include <event2/util.h>
#include <event2/event.h>

#include "mem_rediscli.h"

using namespace std;
using namespace mem;

/**
 * メイン関数
 *
 * @access public
 * @param int  argc
 * @param char **argv
 * @return int
 */
int main(int argc, char **argv) {
    struct event_base *base = event_base_new();
    rediscli rcli(base, "127.0.0.1", 6379);

    /* Redisサーバへ接続 */
    if (rcli.connection()) {
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

        event_base_dispatch(base);
    }

    event_base_free(base);

    return 0;
}